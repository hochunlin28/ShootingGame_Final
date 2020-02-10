#ifndef PEOPLE_H
#define PEOPLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "bullet.h"

class people: public QObject, public QGraphicsPixmapItem
{
public:
    people();
    virtual void hurtHealth() = 0;
    virtual int getHealth() = 0;
};

#endif // PEOPLE_H
