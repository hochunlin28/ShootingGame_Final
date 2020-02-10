#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "people.h"

class player : public people{
    Q_OBJECT
public:
    player(int x);
    virtual void hurtHealth();
    int getHealth();
    void setEnemyDamage(int x);
    void setPlayerSkill();
    int getPlayerSkill();
    void Skill();
    void spawnPlayer(QGraphicsScene *s);
public slots:
    void addSkillTime();

private:
    int whichPlayer;
    int health;
    bool isDead;
    int playerSkill;
    int enemyDamage;
    int cooldown,skillTime;
    QTimer *timer;

};

#endif // PLAYER_H
