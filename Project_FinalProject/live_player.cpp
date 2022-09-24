#include "live_player.h"
#include <cmath>

void Live_player::setdpoint()
{
    _dx=_destination.x()-getObj_locationX();
    _dy=_destination.y()-getObj_locationY();
}


Live_player::Live_player(const QPoint &obj_location, const QPoint &rlocation, const QPoint &rheart, const int img_num, const char **dir_set,
       const int hurtable_range, const int attack_range, const int MAXHP, int speed, const QPoint &des):
    Abstract_obj(obj_location,img_num,dir_set,rlocation),
    _HP(MAXHP),_MAXHP(MAXHP),_hurtable_range(hurtable_range),_attack_range(attack_range),_speed(speed),last_index(0),
    _pause(false),_frozen(false),_HPBar_length(_MAXHP*_HPBar_elastic),_heart(obj_location-rlocation+rheart),_obj_rheart(rheart-rlocation),_destination(des)
{
    setdpoint();
}


void Live_player::setDestination(const QPoint &des)
{
    if(_pause||_frozen) return;
    _destination=des;
    setdpoint();
}

bool Live_player::inHurtableRange(const Thrown_obj &obj) const
{
    int dx=obj.getObj_locationX()-_heart.x();
    int dy=obj.getObj_locationY()-_heart.y();
    return _hurtable_range*_hurtable_range>(dx*dx+dy*dy);
}

void Live_player::setObj_location(const QPoint &obj_location)
{
    if(_pause||_frozen) return;
    if(!inRegion(obj_location))
    {
        setDestination(getObj_location());
        return;
    }
    Abstract_obj::setObj_location(obj_location);
    _heart=_obj_rheart+getObj_location();
    setdpoint();
}

int Live_player::HeartDistanceWith(const Abstract_obj & obj)const
{
    int dx=this->_heart.x()-obj.getObj_locationX();
    int dy=this->_heart.y()-obj.getObj_locationY();
    return sqrt(dx*dx+dy*dy);
}

bool Live_player::inAttack_range(const Live_player &obj) const
{
    return _attack_range>=ObjDistanceWith(obj);
}


void Live_player::move(void)
{
    if(_pause||_frozen) return;
    int distance=(int)(sqrt(_dx*_dx+_dy*_dy)+0.01);
    if(distance<=_speed)
    {
        Live_player::setObj_location(_destination);
        return;
    }
    int xfoot,yfoot;
    if(_dx==0) xfoot=0;
    else {
        xfoot=(_speed*_dx)/distance;
    }
    if(_dy==0) yfoot=0;
    else {
        yfoot=(_speed*_dy)/distance;
    }
    Live_player::setObj_location(getObj_location()+QPoint(xfoot,yfoot));
}




bool Live_player::inMyLeft(const Live_player & obj)const
{
    return obj.getObj_locationX()<getObj_locationX();
}


void Live_player::drawImage(QPainter &p,int index)
{
    if(_pause||_frozen) Abstract_obj::drawImage(p,last_index);
    else {
        Abstract_obj::drawImage(p,index);
        last_index=index;
    }
    if(_HP<=0)  return;
    p.setBrush(Qt::red);
    QPoint HPBar_TopLeft=getImg_location()+QPoint(getImgX()/2,0)-QPoint(_HPBar_length*0.5,_HPBar_height);
    p.drawRect(HPBar_TopLeft.x(),HPBar_TopLeft.y(),_HP*_HPBar_elastic,_HPBar_height);
    p.setBrush(Qt::NoBrush);
}


void Live_player::reduceHP(int amount)
{
    if(_pause) return;
    _HP-=amount;
    if(_HP<0) _HP=0;
}
