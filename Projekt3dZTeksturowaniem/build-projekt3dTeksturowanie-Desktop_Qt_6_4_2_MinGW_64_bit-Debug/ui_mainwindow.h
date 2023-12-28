/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <projekt3dteksturowanie.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    projekt3dteksturowanie *widget;
    QGroupBox *groupBox;
    QSlider *xTrans;
    QSlider *yTrans;
    QSlider *zTrans;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QSlider *xScal;
    QSlider *yScal;
    QSlider *zScal;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox_3;
    QSlider *xRota;
    QSlider *yRota;
    QSlider *zRota;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_4;
    QSlider *xShear;
    QSlider *yShear;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *reset;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new projekt3dteksturowanie(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 500, 500));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(530, 10, 261, 121));
        xTrans = new QSlider(groupBox);
        xTrans->setObjectName("xTrans");
        xTrans->setGeometry(QRect(90, 30, 160, 18));
        xTrans->setOrientation(Qt::Horizontal);
        yTrans = new QSlider(groupBox);
        yTrans->setObjectName("yTrans");
        yTrans->setGeometry(QRect(90, 60, 160, 18));
        yTrans->setOrientation(Qt::Horizontal);
        zTrans = new QSlider(groupBox);
        zTrans->setObjectName("zTrans");
        zTrans->setGeometry(QRect(90, 90, 160, 18));
        zTrans->setOrientation(Qt::Horizontal);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 63, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 63, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 63, 20));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(530, 140, 261, 121));
        xScal = new QSlider(groupBox_2);
        xScal->setObjectName("xScal");
        xScal->setGeometry(QRect(90, 30, 160, 18));
        xScal->setOrientation(Qt::Horizontal);
        yScal = new QSlider(groupBox_2);
        yScal->setObjectName("yScal");
        yScal->setGeometry(QRect(90, 60, 160, 18));
        yScal->setOrientation(Qt::Horizontal);
        zScal = new QSlider(groupBox_2);
        zScal->setObjectName("zScal");
        zScal->setGeometry(QRect(90, 90, 160, 18));
        zScal->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 30, 63, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 60, 63, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 90, 63, 20));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(530, 270, 261, 121));
        xRota = new QSlider(groupBox_3);
        xRota->setObjectName("xRota");
        xRota->setGeometry(QRect(90, 30, 160, 18));
        xRota->setOrientation(Qt::Horizontal);
        yRota = new QSlider(groupBox_3);
        yRota->setObjectName("yRota");
        yRota->setGeometry(QRect(90, 60, 160, 18));
        yRota->setOrientation(Qt::Horizontal);
        zRota = new QSlider(groupBox_3);
        zRota->setObjectName("zRota");
        zRota->setGeometry(QRect(90, 90, 160, 18));
        zRota->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 30, 63, 20));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 60, 63, 20));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 90, 63, 20));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(530, 400, 261, 81));
        xShear = new QSlider(groupBox_4);
        xShear->setObjectName("xShear");
        xShear->setGeometry(QRect(90, 30, 160, 18));
        xShear->setOrientation(Qt::Horizontal);
        yShear = new QSlider(groupBox_4);
        yShear->setObjectName("yShear");
        yShear->setGeometry(QRect(90, 60, 160, 18));
        yShear->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 30, 63, 20));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 60, 63, 20));
        reset = new QPushButton(centralwidget);
        reset->setObjectName("reset");
        reset->setGeometry(QRect(530, 490, 261, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Translation", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Shearing", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
