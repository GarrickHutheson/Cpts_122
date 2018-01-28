#ifndef SPAWNER_H
#define SPAWNER_H
#include <QObject>


class Spawner:public QObject
{
public:
    Spawner();
public slots:
    void spawn();
};

#endif // SPAWNER_H
