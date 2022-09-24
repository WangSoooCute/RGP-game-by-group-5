#ifndef FIREBALL3_H
#define FIREBALL3_H
#include "thrown_obj.h"
#include<cmath>


class Fireball3:public Thrown_obj
{
public:
    Fireball3(const QPoint & obj_location,const QPoint & heart);
    void draw(QPainter &p);
    void process(Live_player & player);
};
#endif // FIREBALL3_H
