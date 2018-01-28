#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    bool

};

#endif // PLAYER_H
