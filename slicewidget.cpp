#include <QPaintEvent>
#include <QPainter>

#include "slicewidget.h"

SliceWidget::SliceWidget(QWidget *parent) : QWidget(parent)
{ 
  this->isInited = false;
}

void SliceWidget::paintEvent(QPaintEvent *event) 
{
  if (!isInited)
    return;
  
  QRect srcRect(QPoint(), slice->size());
  QSize dstSize = srcRect.size().scaled(event->rect().size(), Qt::KeepAspectRatio);
  QRect dstRect(QPoint((width() - dstSize.width()) / 2, (height() - dstSize.height()) / 2), dstSize);                                
  
  QPainter painter(this);

  painter.drawImage(dstRect, *slice, srcRect);
}


void SliceWidget::SetupSlice(unsigned char *data, int w, int h)
{
  slice = new QImage(data, w, h, QImage::Format_RGBA8888);  
  isInited = true;
}
