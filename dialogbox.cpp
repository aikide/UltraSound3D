#include "dialogbox.h"
#include "ui_dialogbox.h"

DialogBox::DialogBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBox)
{
    ui->setupUi(this);
}

DialogBox::~DialogBox()
{
    delete ui;
}

void DialogBox::on_pushButtonOK_clicked()
{
    accept();
}

void DialogBox::on_pushButtonCancel_clicked()
{
    reject();
}
