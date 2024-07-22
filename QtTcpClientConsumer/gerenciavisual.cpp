#include "gerenciavisual.h"
#include <QPainter> //Pintor
#include <QBrush> //Escova de preenchimento
#include <QPen> // Caneta
#include <cmath>
#include <QMouseEvent>

GerenciaVisual::GerenciaVisual(QWidget *parent)
    : QWidget{parent}
{}

void GerenciaVisual::paintEvent(QPaintEvent *event){
    QPainter painter(this); //Informando ao QPainter que ele deve pintar neste próprio objeto
    QBrush brush;
    QPen pen;

    int x1, y1, x2, y2;

    brush.setColor(QColor(241, 245, 184));
    brush.setStyle(Qt::SolidPattern); // Preenchimento sólido

    pen.setColor(QColor(206, 214, 92)); // Caneta vermelha
    pen.setWidth(2); // Largura do traço

    // Setando as propriedadaes com base nas criadas acima
    painter.setBrush(brush);
    painter.setPen(pen);

    // Desenha um retângulo que ocupa 100% do tamanho do elemento
    painter.drawRect(0,0,width(), height()); // No Qt, os valores de (0,0) estão no canto superior esquerdo da tela

    // Desenhando linha central
    // painter.drawLine(0, height()/2, width(), height()/2);

    pen.setWidth(1); // Largura do traço
    painter.setPen(pen);

    // Desenhando várias linhas e deixando um plano quadriculado
    for(int i = 0; i < width(); i+=10){
        painter.drawLine(i, 0, i, height());
        painter.drawLine(0, i, width(), i);
    }

    // Mudando cor do lápis
    pen.setColor(QColor(0, 0, 255, 180)); // Mudando cor do lápis (o 4º elemento é a transparência)
    painter.setPen(pen);

    painter.drawLine(0, height()/2, width(), height()/2);
}
