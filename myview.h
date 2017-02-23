#ifndef MYVIEW_H
#define MYVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QtGui>

class MyView : public QGraphicsView
{
public:
    MyView();
    ~MyView();

protected:
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MYVIEW_H
