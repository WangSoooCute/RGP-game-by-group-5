#ifndef FIREBALL2_H
#define FIREBALL2_H
#include "thrown_obj.h"
#include<cmath>


class Fireball2:public Thrown_obj
{
public:
    Fireball2(const QPoint & obj_location,const QPoint & heart);
    void draw(QPainter &p);
    void process(Live_player & player);
};
#endif // FIREBALL2_H
