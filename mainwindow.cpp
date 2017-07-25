#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window3d.h"
#include "slicewindow.h"


MainWindow::MainWindow(QWidget *parent) : 
  QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_action3D_Window_triggered()
{
    Window3D w;
    w.showMaximized();
    w.exec();
}

void MainWindow::on_actionCoronal_Window_triggered()
{
    SliceWindow w;
    w.setWindowTitle("Фронтальная плоскость");
    w.showMaximized();
    w.exec();
}

void MainWindow::on_actionSagittal_Window_triggered()
{

    SliceWindow w;
    w.setWindowTitle("Сагиттальная плоскость");
    w.showMaximized();
    w.exec();
}

void MainWindow::on_actionAxial_Window_triggered()
{

    SliceWindow w;
    w.setWindowTitle("Горизонтальная плоскость");
    w.showMaximized();
    w.exec();
}

void MainWindow::on_horizontalSliderSagittal_valueChanged(int value)
{
    ui->lineEditSagittal->setText(QString::number(value));
}

void MainWindow::on_horizontalSliderCoronal_valueChanged(int value)
{
    ui->lineEditCoronal->setText(QString::number(value));
}

void MainWindow::on_horizontalSliderAxial_valueChanged(int value)

{
    ui->lineEditAxial->setText(QString::number(value));
}

void MainWindow::on_lineEditSagittal_textChanged(const QString &arg1)
{
    int value = arg1.toInt();
    if (value < ui->horizontalSliderSagittal->maximum() && value > ui->horizontalSliderSagittal->minimum())
    {
        ui->horizontalSliderSagittal->setValue(value);
    }
    else if (value >= ui->horizontalSliderSagittal->maximum())
    {
        ui->horizontalSliderSagittal->setValue(ui->horizontalSliderSagittal->maximum());
    }
    else if (value <= ui->horizontalSliderSagittal->minimum())
    {
        ui->horizontalSliderSagittal->setValue(ui->horizontalSliderSagittal->minimum());
    }
}

void MainWindow::on_lineEditCoronal_textChanged(const QString &arg1)
{
    int value = arg1.toInt();
    if (value < ui->horizontalSliderCoronal->maximum() && value > ui->horizontalSliderCoronal->minimum())
    {
        ui->horizontalSliderCoronal->setValue(value);
    }
    else if (value >= ui->horizontalSliderCoronal->maximum())
    {
        ui->horizontalSliderCoronal->setValue(ui->horizontalSliderCoronal->maximum());
    }
    else if (value <= ui->horizontalSliderCoronal->minimum())
    {
        ui->horizontalSliderCoronal->setValue(ui->horizontalSliderCoronal->minimum());
    }
}

void MainWindow::on_lineEditAxial_textChanged(const QString &arg1)
{
    int value = arg1.toInt();
    if (value < ui->horizontalSliderAxial->maximum() && value > ui->horizontalSliderAxial->minimum())
    {
        ui->horizontalSliderAxial->setValue(value);
    }
    else if (value >= ui->horizontalSliderAxial->maximum())
    {
        ui->horizontalSliderAxial->setValue(ui->horizontalSliderAxial->maximum());
    }
    else if (value <= ui->horizontalSliderAxial->minimum())
    {
        ui->horizontalSliderAxial->setValue(ui->horizontalSliderAxial->minimum());
    }
}
