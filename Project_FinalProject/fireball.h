#ifndef FIREBALL_H
#define FIREBALL_H
#include "thrown_obj.h"
#include<cmath>


class Fireball:public Thrown_obj
{
public:
    Fireball(const QPoint & obj_location,const QPoint & heart);
    void draw(QPainter &p);
    void process(Live_player & player);
};

#endif // FIREBALL_H
