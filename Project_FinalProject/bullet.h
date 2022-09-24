#ifndef BULLET_H
#define BULLET_H
#include "thrown_obj.h"

class Bullet:public Thrown_obj
{
public:
    Bullet(const QPoint & obj_location,const QPoint & heart);
    void draw(QPainter &p);
    void process(Live_player & player);
};
#endif // BULLET_H
