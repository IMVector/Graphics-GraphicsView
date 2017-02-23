#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myview.h"
#include "myview01.h"   //图形项查找与图形项组

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    QGraphicsScene *scene = new QGraphicsScene;
//    scene->addText("Hello GraphicsScene");
//    QGraphicsView *view = new QGraphicsView;
//    view->setScene(scene);
//    view->show();

//    QGraphicsScene scene;
//    scene.addText("Hello GraphisScene!");
//    QGraphicsView view(&scene);
//    view.show();

    //MyView *view = new MyView;
    //view->show();

    /**
     * 场景层分为三个层面：
     * 1.图形项层：ItemLayer
     * 2.前景层：ForegroundLayer
     * 3.背景层：BackgroundLayer
     * 场景层绘制从背景层开始，然后图形项层，最后是前景层
     */

//    scene.setForegroundBrush(Qt::red);
//    scene.setBackgroundBrush(Qt::green);

    MyView01 *view = new MyView01;
    view->show();

    return a.exec();
}
