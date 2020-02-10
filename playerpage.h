#ifndef PLAYERPAGE_H
#define PLAYERPAGE_H

#include <QGraphicsScene>
#include <QTimer>
#include<QPushButton>
#include <QLabel>


class playerpage : public QGraphicsScene
{
    Q_OBJECT

public:

    QPushButton *back,*chooseP1,*chooseP2;
    QGraphicsPixmapItem *p1;
    QLabel *p1ImageLabel;
    QLabel *p1ImageLabel_ab;
    QLabel *p2ImageLabel;
    QLabel *p2ImageLabel_ab;

    playerpage();
};



#endif // PLAYERPAGE_H
