#ifndef SLICEWINDOW_H
#define SLICEWINDOW_H

#include <QDialog>
#include <QPoint>
namespace Ui {
class SliceWindow;
}

class SliceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SliceWindow(QWidget *parent = 0);
    ~SliceWindow();
    void ChangeCursorPosition(QPoint pos);

private slots:
    void on_horizontalSliderSlice_valueChanged(int value);
    void on_lineEditSlice_textChanged(const QString &arg1);

private:
    Ui::SliceWindow *ui;
};

#endif // SLICEWINDOW_H
