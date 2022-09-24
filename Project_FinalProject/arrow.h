#ifndef ARROW_H
#define ARROW_H
#include "thrown_obj.h"

class Arrow:public Thrown_obj
{
public:
    Arrow(const QPoint & obj_location,const QPoint & heart);
    void draw(QPainter &p);
    void process(Live_player & player);
private:
    int idx;
};
#endif // ARROW_H
