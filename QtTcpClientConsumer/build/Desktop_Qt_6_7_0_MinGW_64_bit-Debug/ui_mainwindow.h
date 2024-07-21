/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QListWidget *listWidget;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcdNumber;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget1;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(531, 427);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 70, 191, 301));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 171, 281));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift")});
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setEnabled(true);
        pushButton_3->setMinimumSize(QSize(20, 40));
        pushButton_3->setFont(font);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName("lcdNumber");

        gridLayout_2->addWidget(lcdNumber, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 2);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 80);
        gridLayout_2->setRowStretch(1, 20);
        gridLayout_2->setColumnStretch(0, 80);
        gridLayout_2->setColumnStretch(1, 20);

        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setEnabled(true);
        pushButton_4->setMinimumSize(QSize(20, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift")});
        font1.setBold(false);
        pushButton_4->setFont(font1);
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setEnabled(true);
        pushButton_5->setMinimumSize(QSize(20, 40));
        pushButton_5->setFont(font);
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(200, 70, 321, 301));
        widget2 = new QWidget(centralWidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(10, 20, 511, 42));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(20, 35));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift")});
        font2.setPointSize(10);
        lineEdit->setFont(font2);
        lineEdit->setInputMask(QString::fromUtf8(""));
        lineEdit->setText(QString::fromUtf8(""));
        lineEdit->setDragEnabled(false);
        lineEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(widget2);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);
        pushButton->setMinimumSize(QSize(20, 40));
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(false);
        pushButton_2->setMinimumSize(QSize(20, 40));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_2);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(10, 6, 511, 16));
        horizontalLayout_3 = new QHBoxLayout(widget3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget3);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        label_3 = new QLabel(widget3);
        label_3->setObjectName("label_3");
        QPalette palette;
        QBrush brush(QColor(255, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        label_3->setPalette(palette);
        label_3->setFont(font);
        label_3->setCursor(QCursor(Qt::ArrowCursor));
        label_3->setAcceptDrops(false);
        label_3->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(label_3);

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
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Lista de produtores (0)", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Atualizar", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Intervalo (timer)", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Parar", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex.: 127.0.0.1", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Informe o IP do servidor:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#aa0000;\">Desconectado</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
