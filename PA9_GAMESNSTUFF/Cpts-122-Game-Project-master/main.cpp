#include <QApplication>
#include "myrect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    MyRect * player = new MyRect();
    player->setRect(0, 0, 80, 80);
    player->setBrush((Qt::yellow));

    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView * view = new QGraphicsView();

    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setScene(scene);

    player->setPos((view->width()/2),(view->height() - player->rect().height() - 10 ));

    view->show();

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
