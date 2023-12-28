
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Przesuwanie
    connect(ui->xTrans, SIGNAL(valueChanged(int)), ui->widget, SLOT(przesuwanieDX(int)));
    connect(ui->yTrans, SIGNAL(valueChanged(int)), ui->widget, SLOT(przesuwanieDY(int)));
    connect(ui->zTrans, SIGNAL(valueChanged(int)), ui->widget, SLOT(przesuwanieDZ(int)));
    ui->xTrans->setRange(-250, 250);
    ui->yTrans->setRange(-250, 250);
    ui->zTrans->setRange(-250, 250);

    //Skalowanie
    connect(ui->xScal, SIGNAL(valueChanged(int)), ui->widget, SLOT(skalowanieSX(int)));
    connect(ui->yScal, SIGNAL(valueChanged(int)), ui->widget, SLOT(skalowanieSY(int)));
    connect(ui->zScal, SIGNAL(valueChanged(int)), ui->widget, SLOT(skalowanieSZ(int)));
    ui->xScal->setRange(0, 200);
    ui->yScal->setRange(0, 200);
    ui->zScal->setRange(0, 200);
    ui->xScal->setValue(100);
    ui->yScal->setValue(100);
    ui->zScal->setValue(100);

    //Obracanie
    connect(ui->xRota, SIGNAL(valueChanged(int)), ui->widget, SLOT(obracanieX(int)));
    connect(ui->yRota, SIGNAL(valueChanged(int)), ui->widget, SLOT(obracanieY(int)));
    connect(ui->zRota, SIGNAL(valueChanged(int)), ui->widget, SLOT(obracanieZ(int)));
    ui->xRota->setRange(0, 360);
    ui->yRota->setRange(0, 360);
    ui->zRota->setRange(0, 360);

    //Pochylanie
    connect(ui->xShear, SIGNAL(valueChanged(int)), ui->widget, SLOT(pochylanieSHX(int)));
    connect(ui->yShear, SIGNAL(valueChanged(int)), ui->widget, SLOT(pochylanieSHY(int)));
    ui->xShear->setRange(-100, 100);
    ui->yShear->setRange(-100, 100);

    //Reset
    connect(ui->reset,SIGNAL(clicked()),this,SLOT(reset()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    ui->xTrans->setValue(0);
    ui->yTrans->setValue(0);
    ui->zTrans->setValue(0);
    ui->xScal->setValue(100);
    ui->yScal->setValue(100);
    ui->zScal->setValue(100);
    ui->xRota->setValue(0);
    ui->yRota->setValue(0);
    ui->zRota->setValue(0);
    ui->xShear->setValue(0);
    ui->yShear->setValue(0);
    update();
}


