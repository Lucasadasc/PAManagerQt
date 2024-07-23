#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
private:
    QString ipInformado;
    QString maquinaSelecionada;

    int timerId;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void timerEvent(QTimerEvent *event); // É chamado cada vez que um timer criado na classe é realizado
public slots:
    void getData();
    void tcpConnect();
    void tcpDesconnect();
    void atualizarListaIPs();
    void atualizarMaquinaSelecionada();
    void timerRequisicao();
    void pararTimerRequisicao();
signals:
    void dadosRecebidos(qint64 tempo, int valor); // Sinal que será emitido quando os dados forem recebidos
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
