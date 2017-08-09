#include "slicewindow.h"
#include "ui_slicewindow.h"
#include <QDebug>
#include <QMouseEvent>

SliceWindow::SliceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SliceWindow)
{
    ui->setupUi(this);
}

SliceWindow::~SliceWindow()
{
    delete ui;
}

void SliceWindow::on_horizontalSliderSlice_valueChanged(int value)
{
    ui->lineEditSlice->setText(QString::number(value));
}

void SliceWindow::on_lineEditSlice_textChanged(const QString &arg1)
{
    int value = arg1.toInt();
    if (value < ui->horizontalSliderSlice->maximum() && value > ui->horizontalSliderSlice->minimum())
    {
        ui->horizontalSliderSlice->setValue(value);
    }
    else if (value >= ui->horizontalSliderSlice->maximum())
    {
        ui->horizontalSliderSlice->setValue(ui->horizontalSliderSlice->maximum());
    }
    else if (value <= ui->horizontalSliderSlice->minimum())
    {
        ui->horizontalSliderSlice->setValue(ui->horizontalSliderSlice->minimum());
    }
}

void SliceWindow::ChangeCursorPosition(QPoint pos)
{
    //qDebug() << event->pos();
    ui->lineEditX->setText(QString::number(pos.x()));
    ui->lineEditY->setText(QString::number(pos.y()));
}
