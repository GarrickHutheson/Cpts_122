#include "myrect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"


#include <qdebug.h>
void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(x() > 0){
        setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(x() < scene()->width() - this->rect().width()){
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setBrush(Qt::black);
        bullet->setPos(x()+this->rect().width()/2, y()-25);
        scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
