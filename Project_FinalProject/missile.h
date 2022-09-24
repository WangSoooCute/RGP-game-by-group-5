#ifndef MISSILE_H
#define MISSILE_H

#include "princess.h"
#include "thrown_obj.h"

class Missile : public Thrown_obj
{
public:
    Missile(const QPoint & obj_location);
    void draw(QPainter &p);
    void process(Live_player &player);
    void react(Command cmd);
    int getstatus(){return status;}
private:
    enum Condition{u_fly1,u_fly2,l_fly1,l_fly2,r_fly1,r_fly2,
                   death1,death2,death3,death4,death5,death6,death7,death8,death9};
    Condition _condition;
    int status;//导弹先向上，再向左右。用1表示向上，2表示左右移动。

};

#endif // MISSILE_H
