#include "myview01.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QPixmap>
#include <QPainter>

MyView01::MyView01()
{
    resize(300,300);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,200,200);

    QGraphicsRectItem *item1 = new QGraphicsRectItem(0,0,20,20);
    item1->setBrush(Qt::red);
    item1->setPos(10,0);
    //scene->addItem(item1);

    QGraphicsRectItem *item2 = new QGraphicsRectItem(0,0,20,20);
    item2->setBrush(Qt::green);
    item2->setPos(30,0);
    //scene->addItem(item2);

    //新建图形项组,图形项组也是一个图形项
    QGraphicsItemGroup *group = new QGraphicsItemGroup;
    group->addToGroup(item1);
    group->addToGroup(item2);
    scene->addItem(group);

    setScene(scene);

    qDebug() << "itemAt(10,0):" << itemAt(10,0) ;
    qDebug() << "itemAt(30,0):" << itemAt(30,0) ;
    qDebug() << "#######################################" ;
}

MyView01::~MyView01()
{

}

void MyView01::keyPressEvent(QKeyEvent *event)
{
    qDebug() << items() ;
    //items().at(0)->setPos(100,0);
    //items().at(1)->setPos(0,100);
    items().at(2)->setPos(100,100);
    QGraphicsView::keyPressEvent(event);
}

//打印（保存）
void MyView01::mousePressEvent(QMouseEvent *event)
{
    rotate(90); //视图顺时针旋转90度
    QPixmap pixmap(300,300);    //必须指定大小
    QPainter painter(&pixmap);
    render(&painter,QRectF(0,0,300,300),QRect(0,0,300,300));
    pixmap.save("../GraphicsTest02/save.png");
    qDebug() << "dayin ......" <<endl;
    QGraphicsView::mousePressEvent(event);
}

