#include "mainwindow.h"
#include <QApplication>
#include <QMenuBar>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  
  //w.show();
  w.showMaximized();
  
  return a.exec();
}
