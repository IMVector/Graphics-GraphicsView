#ifndef MYVIEW01_H
#define MYVIEW01_H
#include <QGraphicsView>

class MyView01 : public QGraphicsView
{
public:
    MyView01();
    ~MyView01();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MYVIEW01_H
