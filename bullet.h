#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet(int xr, int yr);
    bool getIsDelete();
    void fly();






private:
    bool isDelete;
    int xr,yr;

};

#endif // BULLET_H
