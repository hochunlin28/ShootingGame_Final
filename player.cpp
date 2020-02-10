#include "player.h"
#include "QDebug"

player::player(int x):whichPlayer(x)
{
    switch (whichPlayer) {
    case 0:
        health = 20;
        playerSkill = 5;
        break;
    case 1:
        health = 40;
        playerSkill = 5;
        break;
    }
    timer = new QTimer;
    timer->start(1000);
    enemyDamage = 2;
    isDead = 0;
    skillTime = 10;

}

void player::spawnPlayer(QGraphicsScene *s){
    switch (whichPlayer) {
    case 0:
        setPixmap(QPixmap(":/resource/p1Img.png").scaled(100,100));
        setPos(350, 350);
        s->addItem(static_cast<QGraphicsPixmapItem*>(this));
        break;
    case 1:
        setPixmap(QPixmap(":/resource/p2Img.png").scaled(100,100));
        setPos(350, 350);
        s->addItem(static_cast<QGraphicsPixmapItem*>(this));
        break;
    }
}

void player::hurtHealth(){
    health = health - enemyDamage;
    if(health <= 0){
        isDead = 1;
    }
}

int player::getHealth(){
    return health;
}

void player::setEnemyDamage(int x){
    enemyDamage = x;
}

void player::Skill(){
    switch (whichPlayer) {
    case 0:
        if(playerSkill > 0 && skillTime == 10){
            setPixmap(QPixmap(":/resource/p1Img_skill.png").scaled(100,100));
            enemyDamage = 0;
            playerSkill = playerSkill-1;
            this->connect(timer,SIGNAL(timeout()),this,SLOT(addSkillTime()));
        }
        else{
            qDebug() << "you dont have skill" ;
        }

        break;
    case 1:
        if(playerSkill > 0 && skillTime == 10){
            setPixmap(QPixmap(":/resource/p2Img_skill.png").scaled(100,100));
            enemyDamage = 1;
            playerSkill = playerSkill-1;
            this->connect(timer,SIGNAL(timeout()),this,SLOT(addSkillTime()));
        }
        else{
            qDebug() << "you dont have skill" ;
        }
        break;
    }

}

void player::addSkillTime(){
    skillTime = skillTime-1;


    if(skillTime <= 0){
        this->disconnect(timer,SIGNAL(timeout()),this,SLOT(addSkillTime()));
        enemyDamage = 2;
        skillTime = 10;
        switch (whichPlayer) {
        case 0:
            setPixmap(QPixmap(":/resource/p1Img.png").scaled(100,100));
            break;
        case 1:
            setPixmap(QPixmap(":/resource/p2Img.png").scaled(100,100));
            break;
        }

    }
}

int player::getPlayerSkill(){
    return playerSkill;
}

void player::setPlayerSkill(){
    playerSkill = playerSkill -1;
}
