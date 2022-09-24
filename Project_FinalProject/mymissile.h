#ifndef MYMISSILE_H
#define MYMISSILE_H

#include "thrown_obj.h"

class mymissile : public Thrown_obj
{
public:
    mymissile(const QPoint & obj_location);
    void draw(QPainter &p);
    void process(Live_player &player);
    void react(Command cmd);
private:
    enum Condition{l_fly1,l_fly2,r_fly1,r_fly2,
                   death1,death2,death3,death4,death5,death6,death7,death8,death9};
    Condition _condition;

};

#endif // MYMISSILE_H
