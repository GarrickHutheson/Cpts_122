#include "enemy.h"


#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

#include <QDebug>

Enemy::Enemy()
{
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 5);

    //set color
    setBrush(Qt::red);


    //draw the rect
    setRect(0,0, 50, 50);
    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(20);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y()+3);
    if(pos().y() + rect().height() < 0){
       scene()->removeItem(this);
       delete this;
    }
}
