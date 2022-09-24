#include "fireball3.h"

static const char *dirset[]=
    {":/others/image/others/pigsoldier_fireball3.png"};
static const QPoint rlocation=QPoint(10,20);
static const int img_num=1;
static const int speed=15;
static const int stepmax=15;

Fireball3::Fireball3(const QPoint & obj_location, const QPoint &heart):
    Thrown_obj(obj_location,rlocation,heart,img_num,dirset,speed,stepmax){}


void Fireball3::draw(QPainter &p)
{
    drawImage(p,0);
    if(getStepmax()==0)
    deleteIt();
    move();
}

void Fireball3::process(Live_player &player)
{
    if(!(player.getType()==Type::princess||player.getType()==Type::guard))
        return ;
    if(player.inHurtableRange(*this))
    {
        //回忆槽函数reduceHP亦可当作普通函数调用
        player.reduceHP(10);
        deleteIt();
    }
}
