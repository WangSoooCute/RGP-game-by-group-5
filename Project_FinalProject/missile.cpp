#include "missile.h"

static const char *dirset[]=
    {":/others/image/others/missile/u_fly1.png",
     ":/others/image/others/missile/u_fly2.png",
     ":/others/image/others/missile/l_fly1.png",
     ":/others/image/others/missile/l_fly2.png",
     ":/others/image/others/missile/r_fly1.png",
     ":/others/image/others/missile/r_fly2.png",
     ":/others/image/others/missile/BOOM (1).png",
     ":/others/image/others/missile/BOOM (2).png",
     ":/others/image/others/missile/BOOM (3).png",
     ":/others/image/others/missile/BOOM (4).png",
     ":/others/image/others/missile/BOOM (5).png",
     ":/others/image/others/missile/BOOM (6).png",
     ":/others/image/others/missile/BOOM (7).png",
     ":/others/image/others/missile/BOOM (8).png",
     ":/others/image/others/missile/BOOM (9).png"
    };
static const QPoint rlocation=QPoint(18,42);
//36*84
static const int img_num=15;
static const int speed=15;
static const int stepmax=50;

Missile::Missile(const QPoint & obj_location):
    Thrown_obj(obj_location,rlocation,QPoint(0,0),img_num,dirset,speed,stepmax),
    _condition(u_fly1),status(1){}

void Missile::draw(QPainter &p)
{
    drawImage(p,_condition);
    if(_condition==death9)
        deleteIt();
    if(status==1)
    {
        moveUp();
        react(Command::Umove);
        if(getStepmax()<=45)status=2;
    }
    else
    {
        if(_condition<death1)
            move();
        else
            return;
    }
}

void Missile::react(Command cmd)
{
    switch(cmd){
        case Command::Lmove:
            if(_condition==l_fly1)_condition=l_fly2;
            else _condition=l_fly1;
        break;
        case Command::Rmove:
            if(_condition==r_fly1)_condition=r_fly2;
            else _condition=r_fly1;
        break;
        case Command::Umove:
            if(_condition==u_fly1)_condition=u_fly2;
            else _condition=u_fly1;
        break;
        case Command::Death:
            if(_condition>=death1&&_condition<death9)
                _condition=Condition(1+_condition);
            else if(_condition<death1)
                _condition=death1;
        break;
        default:
        break;
    }
    return;
}

void Missile::process(Live_player &player)
{
    if(!(player.getType()==Type::princess)) return;
    if(getStepmax()<=0)
    {
        react(Command::Death);
        return;
    }
    if(status==2&&player.getType()==Type::princess)
    {
        if(player.getType()==Type::princess&&player.inHurtableRange(*this))
        {
            player.reduceHP(5);
            react(Command::Death);
            return;
        }
        else
        {
            setDestination(player.getHeart());
            if(player.getObj_locationX()<this->getObj_locationX())
            {
                react(Command::Lmove);
                return;
            }
            else
                react(Command::Rmove);
                return;
        }
    }
}
