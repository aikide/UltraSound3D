#include "slicewindow.h"
#include "ui_slicewindow.h"

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
