#ifndef WINDOW3D_H
#define WINDOW3D_H

#include <QDialog>

namespace Ui {
class Window3D;
}

class Window3D : public QDialog
{
    Q_OBJECT

public:
    explicit Window3D(QWidget *parent = 0);
    ~Window3D();

private slots:
    void on_pushButtonAxis_clicked();

    void on_pushButtonAxisEdit_clicked();

    void on_pushButtonAxisSave_clicked();

    void on_pushButtonAxisCancel_clicked();

private:
    Ui::Window3D *ui;
    bool editFlag;
};

#endif // WINDOW3D_H
