#ifndef GREENSTONE_H
#define GREENSTONE_H
#include "thrown_obj.h"
#include <cmath>

class greenstone : public Thrown_obj
{
public:
    greenstone(const QPoint & obj_location,const QPoint & heart );
    void draw(QPainter &p);
    void process(Live_player &player);
};

#endif // GREENSTONE_H
