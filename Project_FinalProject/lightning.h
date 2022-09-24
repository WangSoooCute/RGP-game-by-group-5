#ifndef LIGHTNING_H
#define LIGHTNING_H
#include "thrown_obj.h"
#include "constant.h"

class Lightning : public Thrown_obj
{
public:
    Lightning(const QPoint &pos);
    void draw(QPainter &p);
    void process(Live_player & player);


private:
    int idx;
    int _range;
};
#endif // LIGHTNING_H
