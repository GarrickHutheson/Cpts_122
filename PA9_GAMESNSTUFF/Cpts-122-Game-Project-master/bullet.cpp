#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>


#include <QDebug>
Bullet::Bullet()
{
        //drew the rect
        setRect(0,0, 3, 18);
        //connect
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(20);
}

void Bullet::move()
{
    setPos(x(), y()-15);
    if(pos().y() + rect().height() < 0){
       scene()->removeItem(this);
       delete this;
       //qDebug() << "BULLET GONE!";
    }
}
