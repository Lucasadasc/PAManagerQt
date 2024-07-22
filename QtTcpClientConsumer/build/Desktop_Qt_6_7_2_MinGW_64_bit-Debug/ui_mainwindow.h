/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "gerenciavisual.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelQuantProdutores;
    QListWidget *ipsList;
    QPushButton *btnAtualizarLista;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcdNumber;
    QLabel *label_4;
    QSlider *sliderIntervalo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnResgatarDados;
    QPushButton *btnPararBusca;
    GerenciaVisual *widget;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLineEdit *ipInput;
    QPushButton *btnRealizarConexao;
    QPushButton *btnDesconectar;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *labelStatusConexao;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(531, 429);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("this.rgb(255, 85, 127)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 70, 191, 301));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 171, 281));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        labelQuantProdutores = new QLabel(layoutWidget);
        labelQuantProdutores->setObjectName("labelQuantProdutores");
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift")});
        labelQuantProdutores->setFont(font);

        verticalLayout->addWidget(labelQuantProdutores);

        ipsList = new QListWidget(layoutWidget);
        ipsList->setObjectName("ipsList");
        ipsList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));

        verticalLayout->addWidget(ipsList);

        btnAtualizarLista = new QPushButton(layoutWidget);
        btnAtualizarLista->setObjectName("btnAtualizarLista");
        btnAtualizarLista->setEnabled(false);
        btnAtualizarLista->setMinimumSize(QSize(20, 40));
        btnAtualizarLista->setFont(font);
        btnAtualizarLista->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout->addWidget(btnAtualizarLista);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName("lcdNumber");

        gridLayout_2->addWidget(lcdNumber, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 2);

        sliderIntervalo = new QSlider(layoutWidget);
        sliderIntervalo->setObjectName("sliderIntervalo");
        sliderIntervalo->setEnabled(false);
        sliderIntervalo->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderIntervalo, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 80);
        gridLayout_2->setRowStretch(1, 20);
        gridLayout_2->setColumnStretch(0, 80);
        gridLayout_2->setColumnStretch(1, 20);

        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnResgatarDados = new QPushButton(layoutWidget);
        btnResgatarDados->setObjectName("btnResgatarDados");
        btnResgatarDados->setEnabled(false);
        btnResgatarDados->setMinimumSize(QSize(20, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift")});
        font1.setBold(false);
        btnResgatarDados->setFont(font1);
        btnResgatarDados->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_2->addWidget(btnResgatarDados);

        btnPararBusca = new QPushButton(layoutWidget);
        btnPararBusca->setObjectName("btnPararBusca");
        btnPararBusca->setEnabled(false);
        btnPararBusca->setMinimumSize(QSize(20, 40));
        btnPararBusca->setFont(font);
        btnPararBusca->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_2->addWidget(btnPararBusca);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget = new GerenciaVisual(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(210, 70, 311, 301));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 20, 511, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ipInput = new QLineEdit(layoutWidget1);
        ipInput->setObjectName("ipInput");
        ipInput->setMinimumSize(QSize(20, 35));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift")});
        font2.setPointSize(10);
        ipInput->setFont(font2);
        ipInput->setInputMask(QString::fromUtf8(""));
        ipInput->setText(QString::fromUtf8(""));
        ipInput->setDragEnabled(false);
        ipInput->setClearButtonEnabled(true);

        horizontalLayout->addWidget(ipInput);

        btnRealizarConexao = new QPushButton(layoutWidget1);
        btnRealizarConexao->setObjectName("btnRealizarConexao");
        btnRealizarConexao->setEnabled(true);
        btnRealizarConexao->setMinimumSize(QSize(20, 40));
        btnRealizarConexao->setFont(font);
        btnRealizarConexao->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnRealizarConexao->setAutoFillBackground(true);
        btnRealizarConexao->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btnRealizarConexao);

        btnDesconectar = new QPushButton(layoutWidget1);
        btnDesconectar->setObjectName("btnDesconectar");
        btnDesconectar->setEnabled(false);
        btnDesconectar->setMinimumSize(QSize(20, 40));
        btnDesconectar->setFont(font);
        btnDesconectar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btnDesconectar);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 6, 511, 16));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        labelStatusConexao = new QLabel(layoutWidget2);
        labelStatusConexao->setObjectName("labelStatusConexao");
        QPalette palette;
        QBrush brush(QColor(255, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        labelStatusConexao->setPalette(palette);
        labelStatusConexao->setFont(font);
        labelStatusConexao->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        labelStatusConexao->setAcceptDrops(false);
        labelStatusConexao->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(labelStatusConexao);

        horizontalLayout_3->setStretch(0, 90);
        horizontalLayout_3->setStretch(1, 10);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 531, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(sliderIntervalo, &QSlider::valueChanged, lcdNumber, qOverload<int>(&QLCDNumber::display));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelQuantProdutores->setText(QCoreApplication::translate("MainWindow", "Lista de produtores (0)", nullptr));
        btnAtualizarLista->setText(QCoreApplication::translate("MainWindow", "Atualizar", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Intervalo (timer)", nullptr));
        btnResgatarDados->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        btnPararBusca->setText(QCoreApplication::translate("MainWindow", "Parar", nullptr));
        ipInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex.: 127.0.0.1", nullptr));
        btnRealizarConexao->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        btnDesconectar->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Informe o IP do servidor:", nullptr));
        labelStatusConexao->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#00007f;\">Ol\303\241, voc\303\252 est\303\241 desconectado!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
