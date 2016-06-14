#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include "bullet.h"
#include <QGraphicsView>
#include <QProgressBar>
struct scene_size{
    int h=800;
    int w=600;
};

#include <sstream>


int main(int argc, char *argv[])
{
    scene_size _sceneSize;
    QApplication a(argc, argv);
    std::cout << "START!"<<  std::to_string (88)<<std::endl;

    QGraphicsScene *scene = new QGraphicsScene();

    MyRect *player = new MyRect();
    QProgressBar *prog = new QProgressBar();


    player->setRect(0,0,100,100);

    scene->addItem(player);
    scene->setBackgroundBrush(Qt::blue);


    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();



    std::cout << scene->height();

    player->acceptTouchEvents();
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy  (Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(_sceneSize.h,_sceneSize.w);
    scene->setSceneRect(0,0,_sceneSize.h,_sceneSize.w);
    player->setPos(view->width()/2,view->height()-player->rect().height());
    //view->setFocus();

    Bullet *bullet = new Bullet();
    bullet->setPos(view->width()/2,view->height()-player->rect().height());

    scene->addItem(bullet);

    return a.exec();
}
