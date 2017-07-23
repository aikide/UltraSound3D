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

private:
    Ui::Window3D *ui;
};

#endif // WINDOW3D_H
