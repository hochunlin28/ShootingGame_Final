#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QGraphicsScene>
#include <QTimer>
#include<QPushButton>


class homepage : public QGraphicsScene
{
    Q_OBJECT

public:
    QPushButton* start,* choosePlayer;//start button

    /* function */
    homepage();
};


#endif // HOMEPAGE_H
