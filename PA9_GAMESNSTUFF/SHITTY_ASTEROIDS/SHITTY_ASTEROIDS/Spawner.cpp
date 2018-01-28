#include "Spawner.h"

Spawner::Spawner():QObject()
{

}

void Spawner::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
