#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 700, 500)),
    timer(new QTimer),
    whichPlayerChoose(1)
{
    score=0;
    ui->setupUi(this);
    setHomePage();





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setHomePage(){
    homePage = new homepage;
    connect(homePage->start,SIGNAL(clicked()),this,SLOT(setMainPage()));
    connect(homePage->choosePlayer,SIGNAL(clicked()),this,SLOT(setPlayerPage()));

    currentScene=0;


    ui->textEdit->hide();
    ui->textEdit_2->hide();
    ui->showscore->hide();
    ui->skillcount->hide();
    ui->enemyhealth->hide();
    ui->playerhealth->hide();
    ui->graphicsView->show();


    ui->graphicsView->setScene(homePage);
    homePage->setSceneRect(0,0,ui->graphicsView->width(), ui->graphicsView->height());
    homePage->setBackgroundBrush(QPixmap(":/resource/homePageImg.png").scaled(ui->graphicsView->width(), ui->graphicsView->height()));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void MainWindow::setMainPage(){
    disconnect(homePage->start,SIGNAL(clicked()),this,SLOT(setMainPage()));
    character = new player(whichPlayerChoose);  //polynorphism
    currentScene=1;

    ui->graphicsView->hide();

    ui->textEdit->show();
    ui->textEdit_2->show();
    ui->showscore->show();
    ui->showscore->display(score);
    ui->skillcount->show();
    ui->skillcount->display(character->getPlayerSkill());
    ui->enemyhealth->show();
    ui->playerhealth->show();


    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,ui->graphicsView->width(), ui->graphicsView->height());
    scene->setBackgroundBrush(QPixmap(":/resource/mainPageImg.png").scaled(ui->graphicsView->width(), ui->graphicsView->height()));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    character->spawnPlayer(scene);

    timer->start(10);
    ui->graphicsView->show();

    ui->playerhealth->setRange(0,character->getHealth());
    ui->enemyhealth->hide();
    character->connect(timer, SIGNAL(timeout()), this, SLOT(playerIsAttacked()));


    monster = new enemy;
    monster->spawnEnemy(scene);
    ui->enemyhealth->show();
    ui->enemyhealth->setRange(0,monster->getHealth());
    monster->connect(monster->timer, SIGNAL(timeout()), this, SLOT(enemyAttack()));
    monster->connect(timer, SIGNAL(timeout()), this, SLOT(enemyIsAttacked()));


}

void MainWindow::setPlayerPage(){
    currentScene=3;
    //background



    //playerpage
    playerPage = new playerpage();


    disconnect(homePage->start,SIGNAL(clicked()),this,SLOT(setMainPage()));
    disconnect(homePage->choosePlayer,SIGNAL(clicked()),this,SLOT(setPlayerPage()));
    connect(playerPage->back,SIGNAL(clicked()),this,SLOT(setHomePage()));
    connect(playerPage->chooseP1,SIGNAL(clicked()),this,SLOT(setPlayerP1()));
    connect(playerPage->chooseP2,SIGNAL(clicked()),this,SLOT(setPlayerP2()));
    ui->graphicsView->setScene(playerPage);
    playerPage->setSceneRect(0,0,ui->graphicsView->width(), ui->graphicsView->height());
    playerPage->setBackgroundBrush(QPixmap(":/resource/playerPageImg.png").scaled(ui->graphicsView->width(), ui->graphicsView->height()));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}



void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(currentScene == 1){
        switch(e->key()) {
        case Qt::Key_Up:
        case Qt::Key_W:
            character->setPos(character->x(), character->y() - 10);
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            character->setPos(character->x(), character->y() + 10);
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            character->setPos(character->x() - 10, character->y());
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            character->setPos(character->x() + 10, character->y());
            break;
        case Qt::Key_R:
            character->Skill();
            ui->skillcount->display(character->getPlayerSkill());
            break;
    }

    }
    else{
        e->ignore();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(currentScene == 1){
        switch (whichPlayerChoose) {
        case 0:
            b = new bullet(0,-3);
            playerBullet.append(b);
            b->setPixmap(QPixmap(":/resource/p1Bullet.png").scaled(50, 50));
            b->setPos(character->x() + character->pixmap().width() / 2 - b->pixmap().width() / 2, character->y() - b->pixmap().height());
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b));

            b = new bullet(3,-3);
            playerBullet.append(b);
            b->setPixmap(QPixmap(":/resource/p1Bullet.png").scaled(50, 50));
            b->setPos(character->x() + character->pixmap().width() / 2 - b->pixmap().width() / 2, character->y() - b->pixmap().height());
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b));

            b = new bullet(-3,-3);
            playerBullet.append(b);
            b->setPixmap(QPixmap(":/resource/p1Bullet.png").scaled(50, 50));
            b->setPos(character->x() + character->pixmap().width() / 2 - b->pixmap().width() / 2, character->y() - b->pixmap().height());
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
            break;
        case 1:
            b = new bullet(0,-6);
            playerBullet.append(b);
            b->setPixmap(QPixmap(":/resource/p2Bullet.png").scaled(30, 30));
            b->setPos(character->x() + character->pixmap().width() / 2 - b->pixmap().width() / 2, character->y() - b->pixmap().height());
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
            break;
        }

    }
    else{
        e->ignore();
    }

}

void MainWindow::enemyAttack(){
        monster->setBulletAttack(1);
        if(monster->getBulletAttack() >= 20){
            monster->setBulletAttack(0);
            monster->b = new bullet(0,2);
            enemyBullet.append(monster->b);

            monster->b->setPixmap(QPixmap(":/resource/enemyBullet.png").scaled(50, 50));
            monster->b->setPos(monster->x() + monster->pixmap().width() / 2 - monster->b->pixmap().width() / 2, monster->y()+monster->pixmap().height());


            scene->addItem(static_cast<QGraphicsPixmapItem*>(monster->b));
        }
}
void MainWindow::playerIsAttacked(){
    ui->playerhealth->setGeometry(character->x(),character->y()+character->pixmap().height(),100,20);

    for(int i=0 ; i<playerBullet.size() ; ++i){
        if(playerBullet.at(i)->getIsDelete() == 1){
            delete playerBullet.at(i);
            playerBullet.removeAt(i);
        }
        else
            playerBullet.at(i)->fly();
    }
    for(int i=0 ; i<enemyBullet.size() ; ++i){
        if(enemyBullet.at(i)->getIsDelete() == 1){
            delete enemyBullet.at(i);
            enemyBullet.removeAt(i);
        }
        else if(static_cast<QGraphicsPixmapItem*>(enemyBullet.at(i))->collidesWithItem(static_cast<QGraphicsPixmapItem*>(character))){
            people *per = character; //polynorphism
            per->hurtHealth();

            showPlayerHealth();
            delete enemyBullet.at(i);
            enemyBullet.removeAt(i);
        }
        else{
            enemyBullet.at(i)->fly();

        }
    }

    if(character->getHealth() <= 0){
        character->disconnect(timer, SIGNAL(timeout()), this, SLOT(playerIsAttacked()));
        monster->disconnect(monster->timer, SIGNAL(timeout()), this, SLOT(enemyAttack()));
        monster->disconnect(timer, SIGNAL(timeout()), this, SLOT(enemyIsAttacked()));

        delete monster;
        delete character;
        QMessageBox::information(NULL,tr("Game Over"),QString("Your Score: %1").arg(score));
        score = 0;
        setHomePage();


    }
}


void MainWindow::showPlayerHealth(){
    ui->playerhealth->setValue(character->getHealth());

}

void MainWindow::enemyIsAttacked(){
    ui->enemyhealth->setGeometry(monster->x(),monster->y()+monster->pixmap().height(),100,20);
    for(int i=0 ; i<playerBullet.size() ; ++i){
        if(playerBullet.at(i)->getIsDelete() == 1){
            delete playerBullet.at(i);
            playerBullet.removeAt(i);
        }
        else if(static_cast<QGraphicsPixmapItem*>(playerBullet.at(i))->collidesWithItem(static_cast<QGraphicsPixmapItem*>(monster))){
            people *p2 = monster; //polynorphism
            p2->hurtHealth();
            showEnemyHealth();
            delete playerBullet.at(i);
            playerBullet.removeAt(i);
        }


    }

    if(monster->checkIsDead()){
        monster->scene()->removeItem(monster);
        monster->disconnect(monster->timer, SIGNAL(timeout()), this, SLOT(enemyAttack()));
        monster->disconnect(timer, SIGNAL(timeout()), this, SLOT(enemyIsAttacked()));
        ui->enemyhealth->hide();
        score = score+1;
        ui->showscore->display(score);
        delete monster;

        monster = new enemy;
        monster->spawnEnemy(scene);
        ui->enemyhealth->setRange(0,monster->getHealth());

        monster->connect(monster->timer, SIGNAL(timeout()), this, SLOT(enemyAttack()));
        monster->connect(timer, SIGNAL(timeout()), this, SLOT(enemyIsAttacked()));

    }
}

void MainWindow::showEnemyHealth(){
    ui->enemyhealth->setValue(monster->getHealth());
    ui->enemyhealth->show();

}

void MainWindow::setPlayerP1(){
    QMessageBox::information(NULL,tr("Player"),tr("Choose MagicShiba Successfully"));
    whichPlayerChoose = 0;
}

void MainWindow::setPlayerP2(){
    QMessageBox::information(NULL,tr("Player"),tr("Choose RockerShiba Successfully"));
    whichPlayerChoose = 1;
}
