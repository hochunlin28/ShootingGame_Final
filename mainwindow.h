#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTime>
#include <QList>
#include <QMessageBox>

#include "homepage.h"
#include "playerpage.h"
#include "bullet.h"
#include "player.h"
#include "enemy.h"
#include "people.h"

#include "QDebug"
#include "vector"
#include "iostream"
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    void setMainPage();
    void setHomePage();
    void setPlayerPage();
    void setPlayerP1();
    void setPlayerP2();

    void playerIsAttacked();
    void enemyAttack();
    void showPlayerHealth();
    void enemyIsAttacked();
    void showEnemyHealth();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    homepage *homePage;
    playerpage *playerPage;
    QTimer *timer;
    QTime *current_time;
    player *character;
    enemy *monster;
    QList<bullet *> enemyBullet,playerBullet;

    bullet *b;
    int score;
    int currentScene;//0 for homepage,1 for mainpage
    int whichPlayerChoose;// player chhose whick character,0 for p1,1 for p2


};

#endif // MAINWINDOW_H
