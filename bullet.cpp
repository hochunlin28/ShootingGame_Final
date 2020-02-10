#include "bullet.h"



bullet::bullet(int xr, int yr):xr(xr),yr(yr)
{
    isDelete = 0;

}

void bullet::fly(){
    setPos(x()+xr, y() +yr);
    if(y() < 0 || x()< 0 || x() > 700 || y() > 500) {

        this->scene()->removeItem(this);
        isDelete = 1;
    }
}



bool bullet::getIsDelete(){
    return isDelete;
}
