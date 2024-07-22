#ifndef GERENCIAVISUAL_H
#define GERENCIAVISUAL_H

#include <QWidget>

class GerenciaVisual : public QWidget
{
    Q_OBJECT
public:
    explicit GerenciaVisual(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
};

#endif // GERENCIAVISUAL_H
