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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowserDataLog;
    QLabel *labelConectado;
    QWidget *widget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QLineEdit *lineEditInputServerIP;
    QPushButton *pushButtonConectar;
    QPushButton *pushButtonDesconectar;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcdNumberMinimo;
    QLabel *label_2;
    QSlider *horizontalSliderMinimo;
    QGridLayout *gridLayout_3;
    QLCDNumber *lcdNumberMaximo;
    QLabel *label_3;
    QSlider *horizontalSliderMaximo;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSlider *horizontalSliderTempo;
    QPushButton *pushButtonIniciar;
    QPushButton *pushButtonParar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textBrowserDataLog = new QTextBrowser(centralwidget);
        textBrowserDataLog->setObjectName("textBrowserDataLog");
        textBrowserDataLog->setGeometry(QRect(400, 20, 371, 491));
        labelConectado = new QLabel(centralwidget);
        labelConectado->setObjectName("labelConectado");
        labelConectado->setGeometry(QRect(20, 520, 361, 31));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(21, 21, 361, 491));
        gridLayout_6 = new QGridLayout(widget);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lineEditInputServerIP = new QLineEdit(widget);
        lineEditInputServerIP->setObjectName("lineEditInputServerIP");
        lineEditInputServerIP->setReadOnly(false);

        gridLayout->addWidget(lineEditInputServerIP, 0, 0, 1, 2);

        pushButtonConectar = new QPushButton(widget);
        pushButtonConectar->setObjectName("pushButtonConectar");

        gridLayout->addWidget(pushButtonConectar, 1, 0, 1, 1);

        pushButtonDesconectar = new QPushButton(widget);
        pushButtonDesconectar->setObjectName("pushButtonDesconectar");

        gridLayout->addWidget(pushButtonDesconectar, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        lcdNumberMinimo = new QLCDNumber(widget);
        lcdNumberMinimo->setObjectName("lcdNumberMinimo");

        gridLayout_2->addWidget(lcdNumberMinimo, 2, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        horizontalSliderMinimo = new QSlider(widget);
        horizontalSliderMinimo->setObjectName("horizontalSliderMinimo");
        horizontalSliderMinimo->setOrientation(Qt::Horizontal);
        horizontalSliderMinimo->setInvertedControls(true);

        gridLayout_2->addWidget(horizontalSliderMinimo, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 1, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        lcdNumberMaximo = new QLCDNumber(widget);
        lcdNumberMaximo->setObjectName("lcdNumberMaximo");

        gridLayout_3->addWidget(lcdNumberMaximo, 2, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 0, 1, 1, 1);

        horizontalSliderMaximo = new QSlider(widget);
        horizontalSliderMaximo->setObjectName("horizontalSliderMaximo");
        horizontalSliderMaximo->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSliderMaximo, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 2, 0, 1, 2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName("lcdNumber");

        gridLayout_4->addWidget(lcdNumber, 2, 0, 1, 1);

        horizontalSliderTempo = new QSlider(widget);
        horizontalSliderTempo->setObjectName("horizontalSliderTempo");
        horizontalSliderTempo->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSliderTempo, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 3, 0, 1, 2);

        pushButtonIniciar = new QPushButton(widget);
        pushButtonIniciar->setObjectName("pushButtonIniciar");

        gridLayout_6->addWidget(pushButtonIniciar, 4, 0, 1, 1);

        pushButtonParar = new QPushButton(widget);
        pushButtonParar->setObjectName("pushButtonParar");

        gridLayout_6->addWidget(pushButtonParar, 4, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderMinimo, &QSlider::sliderMoved, lcdNumberMinimo, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSliderMaximo, &QSlider::sliderMoved, lcdNumberMaximo, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSliderTempo, &QSlider::sliderMoved, lcdNumber, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSliderMinimo, &QSlider::valueChanged, lcdNumberMinimo, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSliderMaximo, &QSlider::valueChanged, lcdNumberMaximo, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSliderTempo, &QSlider::valueChanged, lcdNumber, qOverload<int>(&QLCDNumber::display));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelConectado->setText(QCoreApplication::translate("MainWindow", "***********", nullptr));
        lineEditInputServerIP->setInputMask(QString());
        lineEditInputServerIP->setText(QString());
        lineEditInputServerIP->setPlaceholderText(QCoreApplication::translate("MainWindow", "Insira o IP do Servidor", nullptr));
        pushButtonConectar->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        pushButtonDesconectar->setText(QCoreApplication::translate("MainWindow", "Desconectar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Valor M\303\255nimo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Valor M\303\241ximo", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Tempo de Envio", nullptr));
        pushButtonIniciar->setText(QCoreApplication::translate("MainWindow", "Iniciar Envio", nullptr));
        pushButtonParar->setText(QCoreApplication::translate("MainWindow", "Parar Envio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
