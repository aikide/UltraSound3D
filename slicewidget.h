#ifndef SLICEWIDGET_H
#define SLICEWIDGET_H

#include <QWidget>

class SliceWidget : public QWidget
{
  Q_OBJECT

private:
  QImage *slice;
  
  bool isInited;

public:
  explicit SliceWidget(QWidget *parent = 0);
  
  void SetupSlice(unsigned char *data, int w, int h);    
  
protected:
  void paintEvent(QPaintEvent *event);
  
signals:
  
public slots:
  
};

#endif // SLICEWIDGET_H
