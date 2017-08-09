#include <QPaintEvent>
#include <QPainter>
#include "slicewindow.h"

#include "slicewidget.h"

SliceWidget::SliceWidget(QWidget *parent) : QWidget(parent)
{ 
    this->isInited = false;
    this->setMouseTracking(true);
    this->isMainWindowParent = false;
    this->installEventFilter(this);
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

void SliceWidget::SetParentMainWindow()
{
    isMainWindowParent = true;
}


void SliceWidget::SetupSlice(unsigned char *data, int w, int h)
{
  slice = new QImage(data, w, h, QImage::Format_RGBA8888);  
  isInited = true;
}

void SliceWidget::mouseMove(QMouseEvent *event)
{
    SliceWindow* parent = qobject_cast<SliceWindow*>(this->parent());
    parent->ChangeCursorPosition(event->pos());
}

void SliceWidget::NewSliceWindow()
{
    SliceWindow w;

    if (this->objectName() == "widgetAxial")
    {
        w.setWindowTitle("Горизонтальная плоскость");
    }
    else if (this->objectName() == "widgetCoronal")
    {
        w.setWindowTitle("Фронтальная плоскость");
    }
    else if (this->objectName() == "widgetSagittal")
    {
        w.setWindowTitle("Сагиттальная плоскость");
    }
    w.showMaximized();
    w.exec();
}

bool SliceWidget::eventFilter(QObject *obj, QEvent *ev)
{
    if (!isMainWindowParent && ev->type() == QEvent::MouseMove)
    {
        QMouseEvent* e = static_cast<QMouseEvent*>(ev);
        mouseMove(e);
        return true;
    }
    else if (isMainWindowParent && ev->type() == QEvent::MouseButtonDblClick)
    {
        NewSliceWindow();
        return true;
    }
    return false;
}
