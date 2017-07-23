#ifndef SLICEWINDOW_H
#define SLICEWINDOW_H

#include <QDialog>

namespace Ui {
class SliceWindow;
}

class SliceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SliceWindow(QWidget *parent = 0);
    ~SliceWindow();

private:
    Ui::SliceWindow *ui;
};

#endif // SLICEWINDOW_H
