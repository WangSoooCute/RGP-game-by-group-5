#include "mymissile.h"

static const char *dirset[]=
    {":/others/image/others/missile/l_fly1.png",
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
static const int img_num=13;
static const int speed=10;
static const int stepmax=30;

mymissile::mymissile(const QPoint & obj_location):
    Thrown_obj(obj_location,rlocation,QPoint(0,0),img_num,dirset,speed,stepmax),
    _condition(l_fly1){}

void mymissile::draw(QPainter &p)
{
    drawImage(p,_condition);
    if(_condition==death9)
        deleteIt();
    if(_condition<death1)
            move();
}

void mymissile::react(Command cmd)
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

void mymissile::process(Live_player &player)
{
    if(getStepmax()<=0)
    {
        react(Command::Death);
        return;
    }
    if(player.getType()==Type::boss)
    {
        if(player.inHurtableRange(*this))
        {
            player.reduceHP(3);
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
