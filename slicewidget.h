#ifndef SLICEWIDGET_H
#define SLICEWIDGET_H

#include <QWidget>

class SliceWidget : public QWidget
{
  Q_OBJECT

private:
  QImage *slice;
  
  bool isInited;
  bool isMainWindowParent;

public:
  explicit SliceWidget(QWidget *parent = 0);
  
  void SetupSlice(unsigned char *data, int w, int h);    

  void SetParentMainWindow();

  void NewSliceWindow();

  void mouseMove(QMouseEvent *event);
  
protected:
  void paintEvent(QPaintEvent *event);
  bool eventFilter(QObject *obj, QEvent *ev);
  
signals:
  
public slots:

  
};

#endif // SLICEWIDGET_H
