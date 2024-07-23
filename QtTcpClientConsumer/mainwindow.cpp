#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QListWidget>
#include "gerenciavisual.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    // Ação do botão de realizar conexão
    connect(ui->btnRealizarConexao,
        SIGNAL(clicked(bool)),
        this,
        SLOT(tcpConnect()));

    // Ação do botão de realizar desconexão
    connect(ui->btnDesconectar,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpDesconnect()));

    // Ação do botão de atualizar lista
    connect(ui->btnAtualizarLista,
            SIGNAL(clicked(bool)),
            this,
            SLOT(atualizarListaIPs()));

    // Ação do ListWidget a cada interação
    connect(ui->ipsList,
            SIGNAL(clicked(QModelIndex)),
            this,
            SLOT(atualizarMaquinaSelecionada()));

    // Ação do botão de resgatar dados
    connect(ui->btnResgatarDados,
        SIGNAL(clicked(bool)),
        this,
        SLOT(getData())
    );

    // Conectando o sinal ao slot
    connect(this,
            &MainWindow::dadosRecebidos,
            ui -> widget,
            &GerenciaVisual::adicionarDados);

    //Conexão slider de timer
    connect(ui->sliderIntervalo,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(timerRequisicao()));

    // Para timer de resgate de dados da requisição
    connect(ui->btnPararBusca,
            SIGNAL(clicked(bool)),
            this,
            SLOT(pararTimerRequisicao()));
}

void MainWindow::tcpConnect(){
    ipInformado = ui->ipInput->text();
    quint16 porta = 1234; // Porta do servido

    qDebug() << ipInformado;
    ui -> labelStatusConexao -> setText("Conectando...");
    ui-> labelStatusConexao-> setStyleSheet("QLabel { color : orange; }");
    QCoreApplication::processEvents(); // Forçando atualização

    socket->connectToHost(ipInformado,porta);
        if(socket->waitForConnected(3000)){
            qDebug() << "Connected";

            // Setando status das labels
            ui -> labelStatusConexao -> setText("Servidor conectado!");
            ui-> labelStatusConexao-> setStyleSheet("QLabel { color : green; }");

            // Setando estado dos botões
            ui->btnDesconectar->setEnabled(true);
            ui->btnRealizarConexao->setEnabled(false);
        }
        else{
            qDebug() << "Disconnected";

            ui -> labelStatusConexao -> setText("Conexão não estabelecida!");
            ui-> labelStatusConexao-> setStyleSheet("QLabel { color : red; }");
        }

        atualizarListaIPs();
    }

void MainWindow::tcpDesconnect(){
    socket->disconnectFromHost();

    if (socket->state() == QAbstractSocket::UnconnectedState || socket->waitForDisconnected(3000)){
        qDebug() << "Disconnected";

        // Setando estado dos botões
        ui->btnDesconectar->setEnabled(false);
        ui->btnAtualizarLista->setEnabled(false);
        ui->btnResgatarDados->setEnabled(false);
        ui->btnPararBusca->setEnabled(false);
        ui->btnRealizarConexao->setEnabled(true);

        // Setando as labels
        ui -> labelStatusConexao -> setText("Desconectado!");
        ui-> labelStatusConexao-> setStyleSheet("QLabel { color : red; }");

        // Setando lista de IPs
        ui-> ipsList ->clear();
    }
}


void MainWindow::atualizarListaIPs(){
    QString conexaoChar = "list " + ipInformado;

    if (socket->state() == QAbstractSocket::ConnectedState) {

        socket->write(conexaoChar.toStdString().c_str());
        socket->waitForBytesWritten();
        socket->waitForReadyRead();

        qDebug() << socket->bytesAvailable();

        while (socket->bytesAvailable()) {
            QByteArray data = socket->readAll();
            QStringList machineList = QString(data).split("\n");

            QString mensagemLabel = QString("Lista de produtores (%1)").arg(machineList.size()-1);
            ui -> labelQuantProdutores ->setText(mensagemLabel);

            // Limpando QListWidget
            ui -> ipsList -> clear();

            QCoreApplication::processEvents();

            foreach (const QString &machine, machineList) {
                if (!machine.trimmed().isEmpty()) {
                    ui->ipsList->addItem(machine);
                }
            }
        }

        // Deixando botão atualizar disponivel
        ui -> btnAtualizarLista -> setEnabled(true);
    }
}

void MainWindow::atualizarMaquinaSelecionada(){
    ui -> btnResgatarDados -> setEnabled(true);
    ui -> sliderIntervalo -> setEnabled(true);
}

void MainWindow::timerRequisicao(){
    // Temporizador interno da classe - inicia um timer que é repetido a cada 100ms
    int valueLCD = ui->lcdNumber->value() * 5000;
    timerId = startTimer(valueLCD);

    ui->btnPararBusca->setEnabled(true);
}

void MainWindow::pararTimerRequisicao(){
    killTimer(timerId);

    ui -> btnPararBusca ->setEnabled(false);
}

// A cada laõ do timer event, chamar getData()
void MainWindow::timerEvent(QTimerEvent *event){
    getData();
}

void MainWindow::getData(){
    QString str;
    QStringList list;
    qint64 thetime;

    // Recebendo valor selecionado do QListWidget
    QListWidgetItem *selectedItem = ui->ipsList->currentItem();
    maquinaSelecionada = selectedItem->text().replace("\r","");

    qDebug() << "to get data...";

    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";

            QString textoConexao = "get " + maquinaSelecionada + " 1\r\n";
            qDebug() << textoConexao;

            socket->write(textoConexao.toStdString().c_str());
            socket->waitForBytesWritten();
            socket->waitForReadyRead();

            qDebug() << socket->bytesAvailable();

            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");
                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    str = list.at(1);
                    qDebug() << thetime << ": " << str;

                    int valor = str.toInt();

                    // Emitindo o sinal com os dados recebidos
                    emit dadosRecebidos(thetime, valor);
                }
            }
        }
    }
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}


