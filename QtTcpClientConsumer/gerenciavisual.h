#ifndef GERENCIAVISUAL_H
#define GERENCIAVISUAL_H

#include <QWidget>
#include <vector>

class GerenciaVisual : public QWidget
{
    Q_OBJECT
private:
    // Declarando array que guardará os dados recebidos
    QVector<qint64> temposRecebidos;
    QVector<int> valoresRecebidos;
    qint64 maiorTempo;
    qint64 menorTempo;
    int maiorValor;

    int timerId;

public:
    explicit GerenciaVisual(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
public slots:
    void adicionarDados(qint64 tempo, int valor); // Slot que recebe os dados
};

#endif // GERENCIAVISUAL_H
