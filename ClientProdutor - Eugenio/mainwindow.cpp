#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <cstdlib>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(ui->pushButtonConectar,
            &QPushButton::clicked,
            this,
            &MainWindow::conectarServidorTCP);

    connect(ui->pushButtonDesconectar,
            &QPushButton::clicked,
            this,
            &MainWindow::desconectarServidorTCP);

    connect(socket,
            &QTcpSocket::stateChanged,
            this,
            &MainWindow::atualizarEstadoBotoes);

    // Conecta o botão de início ao slot para enviar dados
    connect(ui->pushButtonIniciar,
            &QPushButton::clicked,
            this,
            &MainWindow::iniciarEnvioDados);

    // Conecta o botão de parada ao slot para parar o envio de dados
    connect(ui->pushButtonParar,
            &QPushButton::clicked,
            this,
            &MainWindow::pararEnvioDados);

    envioContinuo = false;

    // Inicializa o gerador de números aleatórios
    srand(time(0));

    // Atualiza o estado inicial dos botões
    atualizarEstadoBotoes();
}

/**
 * @brief Atualiza o estado dos botões na janela principal.
 *
 * Esta função verifica o estado do socket e habilita ou desabilita os botões
 * de acordo com o estado atual. Se o socket estiver conectado, os botões
 * Desconectar, Parar e Iniciar serão habilitados, enquanto o botão Conectar
 * será desabilitado. Caso contrário, os botões Desconectar e Parar serão
 * desabilitados, enquanto os botões Conectar e Iniciar serão habilitados.
 */
void MainWindow::atualizarEstadoBotoes()
{
    if (socket->state() == QAbstractSocket::ConnectedState)
    {
        ui->pushButtonDesconectar->setEnabled(true);
        ui->pushButtonParar->setEnabled(true);
        ui->pushButtonConectar->setEnabled(false);
        ui->pushButtonIniciar->setEnabled(true);
    }
    else
    {
        ui->pushButtonDesconectar->setEnabled(false);
        ui->pushButtonParar->setEnabled(false);
        ui->pushButtonConectar->setEnabled(true);
        ui->pushButtonIniciar->setEnabled(true);
    }
}

/**
 * @brief Conecta ao servidor TCP.
 *
 * Esta função é responsável por estabelecer uma conexão com um servidor TCP.
 * Ela obtém o endereço IP e a porta do servidor a partir da interface gráfica,
 * e tenta estabelecer a conexão utilizando o socket.
 * 
 * @note Esta função atualiza a interface gráfica exibindo mensagens de status
 * e alterando a cor do rótulo de conexão.
 */
void MainWindow::conectarServidorTCP()
{
    QString enderecoIP = ui->lineEditInputServerIP->text();
    quint16 porta = 1234; // Porta do servidor

    // Verifica se a porta foi especificada e é válida
    bool portaValida;
    quint16 portaInput = ui->lineEditInputServerIP->text().toUShort(&portaValida);
    if (portaValida && portaInput != 0)
    {
        porta = portaInput;
    }

    QString mensagem;

    mensagem = "Tentando conectar ao servidor TCP ...";
    ui->textBrowserDataLog->append(mensagem);
    ui->labelConectado->setText("Tentando conectar ao servidor TCP ...");
    ui->labelConectado->setStyleSheet("QLabel { color : orange; }");
    QCoreApplication::processEvents(); // Força a atualização imediata da interface

    mensagem = "Endereço IP: " + enderecoIP + ", Porta: " + QString::number(porta);
    ui->textBrowserDataLog->append(mensagem);

    socket->connectToHost(enderecoIP, porta);

    if (socket->waitForConnected(3000))
    {
        mensagem = "Conexão bem-sucedida ao servidor em " + enderecoIP + ":" + QString::number(porta);
        ui->textBrowserDataLog->append(mensagem);
        ui->labelConectado->setText("Conectado");
        ui->labelConectado->setStyleSheet("QLabel { color : green; }"); // Cor verde para "conectado"

        mensagem = "Estado do socket após conexão: " + QString::number(socket->state());
        ui->textBrowserDataLog->append(mensagem);
    }
    else
    {
        mensagem = "Falha na conexão ao servidor em " + enderecoIP + ":" + QString::number(porta);
        ui->textBrowserDataLog->append(mensagem);

        mensagem = "Erro: " + socket->errorString();
        ui->textBrowserDataLog->append(mensagem);

        ui->labelConectado->setText("Desconectado");
        ui->labelConectado->setStyleSheet("QLabel { color : red; }"); // Cor vermelha para "desconectado"
    }
    atualizarEstadoBotoes();
}

/**
 * @brief Desconecta o cliente do servidor TCP.
 *
 * Esta função desconecta o cliente do servidor TCP. Ela exibe mensagens de status na interface do usuário
 * e atualiza o estado dos botões. Se a desconexão for bem-sucedida, exibe uma mensagem de sucesso e define
 * a cor do rótulo "Conectado" como vermelho. Caso contrário, exibe uma mensagem de falha e define o rótulo
 * "Conectado" como "Falha ao desconectar".
 */
void MainWindow::desconectarServidorTCP()
{
    QString mensagem;

    mensagem = "Tentando desconectar do servidor TCP ...";
    ui->textBrowserDataLog->append(mensagem);
    ui->labelConectado->setText(mensagem);
    QCoreApplication::processEvents(); // Força a atualização imediata da interface

    socket->disconnectFromHost();

    if (socket->state() == QAbstractSocket::UnconnectedState || socket->waitForDisconnected(3000))
    {
        mensagem = "Desconexão bem-sucedida.";
        ui->textBrowserDataLog->append(mensagem);
        ui->labelConectado->setText("Desconectado");
        ui->labelConectado->setStyleSheet("QLabel { color : red; }"); // Cor vermelha para "desconectado"
    }
    else
    {
        mensagem = "Falha ao desconectar. Estado do socket: " + QString::number(socket->state()) +
                   ", Erro: " + socket->errorString();
        ui->textBrowserDataLog->append(mensagem);
        ui->labelConectado->setText("Falha ao desconectar");
    }
    atualizarEstadoBotoes();
}

/**
 * @brief Inicia o envio contínuo de dados.
 *
 * Esta função é responsável por iniciar o envio contínuo de dados através de um socket.
 * Ela obtém os valores mínimo e máximo a partir de dois LCD Numbers da interface gráfica,
 * verifica se o valor mínimo é menor que o valor máximo e, em seguida, cria um timer para
 * controlar o envio de dados em intervalos especificados pelo slider da interface gráfica.
 * A cada intervalo, um valor aleatório é gerado dentro do intervalo especificado e uma mensagem
 * contendo o timestamp e o valor aleatório é enviada através do socket. O envio é registrado
 * no log da interface gráfica.
 *
 * @note Esta função assume que o socket está conectado.
 */
void MainWindow::iniciarEnvioDados()
{
    int valorMinimo = static_cast<int>(ui->lcdNumberMinimo->value());
    int valorMaximo = static_cast<int>(ui->lcdNumberMaximo->value());

    qDebug() << "valorMinimo:" << valorMinimo << "valorMaximo:" << valorMaximo;

    // Verifica se o valor mínimo é maior ou igual ao valor máximo
    if (valorMinimo >= valorMaximo)
    {
        ui->textBrowserDataLog->append("Erro: valorMinimo deve ser menor que valorMaximo.");
        return;
    }

    // Verifica se o socket está conectado
    if (socket->state() == QAbstractSocket::ConnectedState)
    {
        envioContinuo = true;

        // Cria um timer para controlar o envio de dados
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [this, valorMinimo, valorMaximo, timer]()
                {
            // Gera um valor aleatório e cria a mensagem
            float valorAleatorio = valorMinimo + rand() % (valorMaximo - valorMinimo + 1);
            qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();
            QString mensagem = "set " + QString::number(timestamp) + " " + QString::number(valorAleatorio) + "\r\n";

            // Adiciona a mensagem ao log
            QString logMsg = QString("[%1] Enviando: %2")
                                 .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
                                 .arg(mensagem);
            ui->textBrowserDataLog->append(logMsg);

            // Escreve a mensagem no socket
            qint64 bytesEscritos = socket->write(mensagem.toStdString().c_str());

            // Verifica se a escrita foi bem-sucedida
            if (bytesEscritos == -1) {
                QString erroMsg = QString("[%1] Erro de escrita: %2")
                                      .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
                                      .arg(socket->errorString());
                ui->textBrowserDataLog->append(erroMsg);
            } else {
                QString bytesMsg = QString("[%1] %2 bytes escritos")
                                       .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
                                       .arg(bytesEscritos);
                ui->textBrowserDataLog->append(bytesMsg);

                // Verifica se os bytes foram escritos dentro do timeout
                if (socket->waitForBytesWritten(3000)) {
                    QString successMsg = QString("[%1] Dados escritos com sucesso")
                                             .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
                    ui->textBrowserDataLog->append(successMsg);
                } else {
                    QString timeoutMsg = QString("[%1] Timeout de escrita")
                                             .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
                    ui->textBrowserDataLog->append(timeoutMsg);
                }
            }

            // Para o timer se envioContinuo for definido como falso
            if (!envioContinuo) {
                timer->stop();
                timer->deleteLater();
            } });

        // Inicia o timer com o intervalo especificado no slider
        timer->start(ui->horizontalSliderTempo->value() * 1000);
    }
}

/**
 * @brief Interrompe o envio contínuo de dados.
 *
 * Esta função verifica se o envio contínuo de dados está ativado e, caso esteja,
 * o desativa. Em seguida, exibe uma mensagem no log de dados indicando que o
 * envio de dados foi interrompido.
 * Se o envio contínuo de dados já estiver desativado, exibe uma mensagem no log
 * de dados indicando que o envio de dados já está parado.
 */
void MainWindow::pararEnvioDados()
{
    if (envioContinuo)
    {
        envioContinuo = false;
        ui->textBrowserDataLog->append("<span style='color: red;'>Envio de dados interrompido.</span>");
        qDebug() << "Envio de dados interrompido.";
    }
    else
    {
        ui->textBrowserDataLog->append("<span style='color: orange;'>O envio de dados já está parado.</span>");
        qDebug() << "O envio de dados já está parado.";
    }
}

/**
 * @brief Destrutor da classe MainWindow.
 * 
 * Este método é responsável por liberar a memória alocada para o objeto MainWindow.
 * Ele deleta o socket e a interface de usuário (ui).
 */
MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}
