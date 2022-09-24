#include "thrown_obj.h"
#include <cmath>


Thrown_obj::Thrown_obj(const QPoint & obj_location, const QPoint & rlocation, const QPoint & destination, const int img_num, const char **dir_set,
                       const int speed, const int stepmax):
    Abstract_obj(obj_location,img_num,dir_set,rlocation),_speed(speed),_stepmax(stepmax),last_index(0),_pause(false)
{
    setDestination(destination);
}


void Thrown_obj::setDestination(const QPoint &destination)
{
    if(_pause) return;
    if(destination==getObj_location()) return;
    int x1=destination.x()-getObj_locationX();
    int y1=destination.y()-getObj_locationY();
    double distance=sqrt(x1*x1+y1*y1);
    _dx=x1*_speed/distance;
    _dy=y1*_speed/distance;
}


void Thrown_obj::move()
{
    if(_pause) return;
    QPoint newlocation=getObj_location()+QPoint(_dx,_dy);
    setObj_location(newlocation);
    if(_stepmax>0)
        _stepmax--;
    else _stepmax=0;
}


void Thrown_obj::moveUp()
{
    if(_pause) return;
    QPoint newlocation=getObj_location()+QPoint(0,-_speed);
    setObj_location(newlocation);
    if(_stepmax>0)
        _stepmax--;
    else _stepmax=0;
}

void Thrown_obj::moveDown()
{
    if(_pause) return;
    QPoint newlocation=getObj_location()+QPoint(0,+_speed);
    setObj_location(newlocation);
    if(_stepmax>0)
        _stepmax--;
    else _stepmax=0;
}

void Thrown_obj::moveLeft()
{
    if(_pause) return;
    QPoint newlocation=getObj_location()+QPoint(-_speed,0);
    setObj_location(newlocation);
    if(_stepmax>0)
        _stepmax--;
    else _stepmax=0;
}

void Thrown_obj::moveRight()
{
    if(_pause) return;
    QPoint newlocation=getObj_location()+QPoint(_speed,0);
    setObj_location(newlocation);
    if(_stepmax>0)
        _stepmax--;
    else _stepmax=0;
}



void Thrown_obj::drawImage(QPainter &p, int index)
{
    if(_pause)
        Abstract_obj::drawImage(p,last_index);
    else{
        Abstract_obj::drawImage(p,index);
        last_index=index;
    }
}
