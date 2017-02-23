#include "myview.h"
#include <QGraphicsScene>
#include <QGraphicsItem>

MyView::MyView()
{
    resize(400,400);
    setBackgroundBrush(Qt::yellow); //设置场景的背景
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,200,200);   //设置场景边框
    QGraphicsRectItem *item = new QGraphicsRectItem(0,0,20,20);
    item->setBrush(Qt::blue);
    scene->addItem(item);
    setScene(scene);

    //设置场景在视图中的对齐方式，左上角
    setAlignment(Qt::AlignLeft | Qt::AlignTop);

    /**
     * QGraphicsView拖动模式，提供了三种：
     * 1.NoDrag：忽略鼠标事件，不可以拖动
     * 2.ScrollHandDrag：光标变为手型，可以拖动场景进行移动
     * 3.RubberBandDrag：使用橡皮筋效果，进行区域选择，可选中一个区域内所有图形项
     */
    setDragMode(QGraphicsView::ScrollHandDrag);
    scene->setSceneRect(0,0,800,800);

    /**
     * 缓存背景。
     * 原理：把整个视图窗口绘制到一个pixmap上，适合较小的视图窗口，如果试图窗口很大，且有滚动条，就不适合缓存背景
     */
    setCacheMode(QGraphicsView::CacheBackground);
}

MyView::~MyView()
{

}

void MyView::wheelEvent(QWheelEvent *event) //滚轮事件
{
    if(event->delta()>0)    //鼠标远离使用者，delta()返回正值
        scale(0.5,0.5); //视图缩放
    else scale(2,2);
}

void MyView::mousePressEvent(QMouseEvent *event)
{
    //Q_UNUSED(event);
    rotate(90); //顺时针旋转90度
    QGraphicsView::mousePressEvent(event);  //调用父类事件
}

