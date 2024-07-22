#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui
{
    class MainWindow;
}

/**
 * @class MainWindow
 * 
 * @brief A classe MainWindow é responsável por representar a janela principal da aplicação.
 * 
 * Esta classe herda da classe QMainWindow e contém funcionalidades relacionadas ao envio de dados,
 * conexão e desconexão com um servidor TCP, e atualização do estado dos botões.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool envioContinuo; // Variável para controlar o loop de envio contínuo

public:
    /**
     * @brief Construtor da classe MainWindow.
     * 
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief Destrutor da classe MainWindow.
     */
    ~MainWindow();

public slots:
    /**
     * @brief Slot para iniciar o envio de dados.
     */
    void iniciarEnvioDados();

    /**
     * @brief Slot para parar o envio de dados.
     */
    void pararEnvioDados();

    /**
     * @brief Slot para conectar ao servidor TCP.
     */
    void conectarServidorTCP();

    /**
     * @brief Slot para desconectar do servidor TCP.
     */
    void desconectarServidorTCP();

    /**
     * @brief Função para atualizar o estado dos botões.
     */
    void atualizarEstadoBotoes();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
