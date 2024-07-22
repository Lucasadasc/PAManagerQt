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

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
public slots:
    void getData();
    void tcpConnect();
    void tcpDesconnect();
    void atualizarListaIPs();
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
