#include "window3d.h"
#include "ui_window3d.h"

Window3D::Window3D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window3D)
{
    ui->setupUi(this);
}

Window3D::~Window3D()
{
    delete ui;
}
