#include "enemy.h"
#include "bullet.h"


enemy::enemy():timer(new QTimer)
{
    status = 0;
    health = 20;
    isDead = 0;
    bulletAttack = 0;
    timer->start(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void enemy::spawnEnemy(QGraphicsScene *scene){
    s = scene;
    setPixmap(QPixmap(":/resource/enemyImg.png").scaled(100,100));
    setPos(qrand()%500,0);
    s->addItem(static_cast<QGraphicsPixmapItem*>(this));
}

void enemy::move(){

    if(x() > 450){status = 1;}
    if(x() < 0){status = 0;}
    if(status == 0) {
        setPos(x()+3, y());
    }
    if(status == 1) {
        setPos(x()-3, y());
    }
}

int enemy::getBulletAttack(){
    return bulletAttack;
}

void enemy::setBulletAttack(int x){
    if(x==0){
        bulletAttack = x;
    }
    else{
        bulletAttack=bulletAttack+1;
    }

}

void enemy::hurtHealth(){
    health = health - 1;
    if(health == 0){
        isDead = 1;
    }
}

int enemy::getHealth(){
    return health;
}

int enemy::checkIsDead(){
    return isDead;
}

enemy::~enemy(){
}
