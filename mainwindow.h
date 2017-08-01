#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dataloader.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void SetupData(const char *fileName);
  
private slots:
    void on_action3D_Window_triggered();

    void on_actionCoronal_Window_triggered();

    void on_actionSagittal_Window_triggered();

    void on_actionAxial_Window_triggered();

    void on_horizontalSliderSagittal_valueChanged(int value);

    void on_horizontalSliderCoronal_valueChanged(int value);

    void on_horizontalSliderAxial_valueChanged(int value);

    void on_lineEditSagittal_textChanged(const QString &arg1);

    void on_lineEditCoronal_textChanged(const QString &arg1);

    void on_lineEditAxial_textChanged(const QString &arg1);

    void on_actionSelect_data_file_triggered();
    
private:
  Ui::MainWindow *ui;
  
  DataLoader *dataLoader;
};

#endif // MAINWINDOW_H
