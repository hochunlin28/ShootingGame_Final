#ifndef ENEMY_H
#define ENEMY_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QThread>
#include "bullet.h"
#include "player.h"
#include "people.h"



class enemy : public people{
    Q_OBJECT
public:
    enemy();
    ~enemy();
    void spawnEnemy(QGraphicsScene *scene);
    int getBulletAttack();
    void setBulletAttack(int x);
    bullet *b;
    QTimer *timer;
    int getHealth();
    int checkIsDead();
    virtual void hurtHealth();

public slots:
    void move();



private:
    int status;

    QGraphicsScene *s;

    int bulletAttack;
    int health;

    bool isDead;
};



#endif // PLAYER_H
