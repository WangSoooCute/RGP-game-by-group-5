#ifndef ICEFROZEN_H
#define ICEFROZEN_H
#include "thrown_obj.h"
#include "constant.h"

class Icefrozen : public Thrown_obj
{
public:
    Icefrozen(const QPoint &pos);
    void draw(QPainter &p);
    void process(Live_player & player);


private:
    int _range;
    int idx;
    int sleep_idx;
};

#endif // Icefrozen_H
