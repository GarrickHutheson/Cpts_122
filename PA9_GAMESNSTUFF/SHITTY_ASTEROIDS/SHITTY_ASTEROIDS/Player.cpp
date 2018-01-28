#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event){
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == (Qt::Key_Right)){
        if (pos().x() + 100 < scene()->width())
         setPos(x()+10,y());
    }

    else if (event->key() == (Qt::Key_Up)){
        if (pos().y() > 0)
         setPos(x(),y()-10);
    }
    else if (event->key() == (Qt::Key_Down)){
        if (pos().y() + rect().height() < scene()->height())
            setPos(x(),y()+10);
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }


}

/*void Player::mousePressEvent(QMouseEvent *event)
{
    if(event->MouseButtonPress)
}*/


