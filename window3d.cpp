#include "window3d.h"
#include "ui_window3d.h"
#include "dialogbox.h"

Window3D::Window3D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window3D)
{
    ui->setupUi(this);
    editFlag = false;

    ui->frameA->setVisible(false);
    ui->frameB->setVisible(false);
    ui->frameC->setVisible(false);
    ui->frameD->setVisible(false);
    ui->frameE->setVisible(false);
    ui->frameF->setVisible(false);
    isABPairSet = false;
    isCDPairSet = false;
    isEFPairSet = false;

    ui->groupBoxPoints->setVisible(false);
    ui->pushButtonAxisEdit->setVisible(false);
    ui->pushButtonAxisEdit->setEnabled(false);
}

Window3D::~Window3D()
{
    delete ui;
}

void Window3D::on_pushButtonAxis_clicked()
{
    ui->pushButtonAxis->setEnabled(false);
    //ui->pushButtonAxisEdit->setEnabled(false);
    ui->pushButtonAxisSave->setEnabled(true);
    ui->pushButtonAxisCancel->setEnabled(true);
    ui->pushButtonPair->setEnabled(true);
    ui->pushButtonFixPair->setEnabled(true);
    ui->pushButtonUnFix->setEnabled(true);
    editFlag = true;
    ui->groupBoxPoints->setVisible(true);
    ui->frameA->setVisible(true);
    ui->frameB->setVisible(true);
    isABPairSet = true;

}

void Window3D::on_pushButtonAxisEdit_clicked()
{
    ui->pushButtonAxisSave->setEnabled(true);
    ui->pushButtonAxisCancel->setEnabled(true);
    ui->pushButtonAxis->setEnabled(false);
    //ui->pushButtonAxisEdit->setEnabled(false);

}

void Window3D::on_pushButtonAxisSave_clicked()
{
    ui->pushButtonAxis->setEnabled(true);
    //ui->pushButtonAxisEdit->setEnabled(true);
    ui->pushButtonAxisSave->setEnabled(false);
    ui->pushButtonAxisCancel->setEnabled(false);
    ui->pushButtonPair->setEnabled(false);
    ui->pushButtonFixPair->setEnabled(false);
    ui->pushButtonUnFix->setEnabled(false);
}

void Window3D::on_pushButtonAxisCancel_clicked()
{
    ui->pushButtonAxis->setEnabled(true);
    ui->pushButtonAxisSave->setEnabled(false);
    ui->pushButtonAxisCancel->setEnabled(false);
    ui->pushButtonPair->setEnabled(false);
    ui->pushButtonFixPair->setEnabled(false);
    ui->pushButtonUnFix->setEnabled(false);
    if (editFlag == true)
    {
        //ui->pushButtonAxisEdit->setEnabled(true);
    }
}



void Window3D::on_pushButtonPair_clicked()
{  
    if (!isABPairSet)
    {
        ui->frameA->setVisible(true);
        ui->frameB->setVisible(true);
        isABPairSet = true;
    }
    else if (isABPairSet && !isCDPairSet)
    {
        ui->frameC->setVisible(true);
        ui->frameD->setVisible(true);
        isCDPairSet = true;
    }
    else if (isABPairSet && isCDPairSet && !isEFPairSet)
    {
        ui->frameE->setVisible(true);
        ui->frameF->setVisible(true);
        isEFPairSet = true;
    }

}

void Window3D::on_toolButtonDeleteA_clicked()
{
    DialogBox d;

    if (d.exec() == QDialog::Accepted)
    {
        ui->frameA->setVisible(false);
        ui->frameB->setVisible(false);
        isABPairSet = false;
    }

}

void Window3D::on_toolButtonDeleteB_clicked()
{
    DialogBox d;

    if (d.exec() == QDialog::Accepted)
    {
        ui->frameA->setVisible(false);
        ui->frameB->setVisible(false);
        isABPairSet = false;
    }
}

void Window3D::on_toolButtonDeleteC_clicked()
{
    DialogBox d;

    if (d.exec() == QDialog::Accepted)
    {
        ui->frameC->setVisible(false);
        ui->frameD->setVisible(false);
        isCDPairSet = false;
    }
}

void Window3D::on_toolButtonDeleteD_clicked()
{
    DialogBox d;

    if (d.exec() == QDialog::Accepted)
    {
        ui->frameC->setVisible(false);
        ui->frameD->setVisible(false);
        isCDPairSet = false;
    }
}

void Window3D::on_toolButtonDeleteE_clicked()
{
    DialogBox d;

    if (d.exec() == QDialog::Accepted)
    {
        ui->frameE->setVisible(false);
        ui->frameF->setVisible(false);
        isEFPairSet = false;
    }
}

void Window3D::on_toolButtonDeleteF_clicked()
{
    DialogBox d;

    if (d.exec() == QDialog::Accepted)
    {
        ui->frameE->setVisible(false);
        ui->frameF->setVisible(false);
        isEFPairSet = false;
    }
}
