#include "playerpage.h"

playerpage::playerpage()
{
    //back
    back = new QPushButton();
    back->setText((QString("back")));
    back->setFont(QFont("purisa",16));
    back->setGeometry(0,0,100,40);
    addWidget(back);

    /*//set p1Img
    QPixmap p1Img(":/resource/p1Img.png");
    p1ImageLabel = new QLabel;
    p1ImageLabel->setFixedSize(150,150);
    QPixmap fitp1Img =  p1Img.scaled(p1ImageLabel->width(),p1ImageLabel->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    p1ImageLabel->setPixmap(fitp1Img);
    p1ImageLabel->setGeometry(70,70,100,100);
    addWidget(p1ImageLabel);

    //set p1 ability picture
    QPixmap p1Img_ab(":/resource/p1Img.png");
    p1ImageLabel_ab = new QLabel;
    p1ImageLabel_ab->setFixedSize(150,150);
    QPixmap fitp1Img_ab =  p1Img_ab.scaled(p1ImageLabel_ab->width(),p1ImageLabel_ab->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    p1ImageLabel_ab->setPixmap(fitp1Img_ab);
    p1ImageLabel_ab->setGeometry(70,230,100,100);
    addWidget(p1ImageLabel_ab);*/

    //setchoosep1button

    chooseP1 = new QPushButton;
    chooseP1->setText((QString("Choose")));
    chooseP1->setFont(QFont("purisa",16));
    chooseP1->setGeometry(150,430,100,40);
    addWidget(chooseP1);



    /*//set p2Img
    QPixmap p2Img(":/resource/p2Img.png");
    p2ImageLabel = new QLabel;
    p2ImageLabel->setFixedSize(150,150);
    QPixmap fitp2Img =  p2Img.scaled(p1ImageLabel->width(),p1ImageLabel->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    p2ImageLabel->setPixmap(fitp2Img);
    p2ImageLabel->setGeometry(250,70,100,100);
    addWidget(p2ImageLabel);

    //set p2 ability picture
    QPixmap p2Img_ab(":/resource/p2Img.png");
    p2ImageLabel_ab = new QLabel;
    p2ImageLabel_ab->setFixedSize(150,150);
    QPixmap fitp2Img_ab =  p2Img_ab.scaled(p1ImageLabel_ab->width(),p1ImageLabel_ab->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    p2ImageLabel_ab->setPixmap(fitp2Img_ab);
    p2ImageLabel_ab->setGeometry(250,230,100,100);
    addWidget(p2ImageLabel_ab);*/

    //setchoosep2button

    chooseP2 = new QPushButton;
    chooseP2->setText((QString("Choose")));
    chooseP2->setFont(QFont("purisa",16));
    chooseP2->setGeometry(460,430,100,40);
    addWidget(chooseP2);
}
