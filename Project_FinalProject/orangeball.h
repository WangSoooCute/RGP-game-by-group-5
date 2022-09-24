#ifndef ORANGEBALL_H
#define ORANGEBALL_H
#include "thrown_obj.h"


class orangeball : public Thrown_obj
{
public:
    orangeball(const QPoint &obj_location, const int direction);
    void process(Live_player & player);
    void draw(QPainter &p);
private:
    enum Direction{up,down,left,right};
    Direction _direction;
};

#endif // ORANGEBALL_H
