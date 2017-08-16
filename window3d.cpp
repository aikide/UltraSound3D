#include "window3d.h"
#include "ui_window3d.h"

Window3D::Window3D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window3D)
{
    ui->setupUi(this);
    editFlag = false;
}

Window3D::~Window3D()
{
    delete ui;
}

void Window3D::on_pushButtonAxis_clicked()
{
    ui->pushButtonAxis->setEnabled(false);
    ui->pushButtonAxisEdit->setEnabled(false);
    ui->pushButtonAxisSave->setEnabled(true);
    ui->pushButtonAxisCancel->setEnabled(true);
    editFlag = true;
    //ui->pushButtonAxisCancel->setVisible(false);
}

void Window3D::on_pushButtonAxisEdit_clicked()
{
    ui->pushButtonAxisSave->setEnabled(true);
    ui->pushButtonAxisCancel->setEnabled(true);
    ui->pushButtonAxis->setEnabled(false);
    ui->pushButtonAxisEdit->setEnabled(false);

}

void Window3D::on_pushButtonAxisSave_clicked()
{
    ui->pushButtonAxis->setEnabled(true);
    ui->pushButtonAxisEdit->setEnabled(true);
    ui->pushButtonAxisSave->setEnabled(false);
    ui->pushButtonAxisCancel->setEnabled(false);
}

void Window3D::on_pushButtonAxisCancel_clicked()
{
    ui->pushButtonAxis->setEnabled(true);
    ui->pushButtonAxisSave->setEnabled(false);
    ui->pushButtonAxisCancel->setEnabled(false);
    if (editFlag == true)
    {
        ui->pushButtonAxisEdit->setEnabled(true);
    }
}


