#include "homepage.h"

homepage::homepage()
{
    start = new QPushButton();
    start->setText((QString("start")));
    start->setFont(QFont("purisa",16));

    choosePlayer = new QPushButton;
    choosePlayer->setText((QString("choosePlayer")));
    choosePlayer->setFont(QFont("purisa",16));
    start->setGeometry(100,200,300,50);
    choosePlayer->setGeometry(250,300,300,50);
    addWidget(start);
    addWidget(choosePlayer);

}
