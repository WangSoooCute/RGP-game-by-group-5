#include "greenstone.h"

static const char *dirset[]=
    {":/others/image/others/greenstone.png"
    };
static const QPoint rlocation=QPoint(15,15);
static const int img_num=1;
static const int speed=15;
static const int stepmax=30;

greenstone::greenstone(const QPoint & obj_location, const QPoint &heart):
    Thrown_obj(obj_location,rlocation,heart,img_num,dirset,speed,stepmax){}




void greenstone::process(Live_player &player)
{
    if((player.getType()==Type::princess||player.getType()==Type::guard)&&player.inHurtableRange(*this))
    {
        //类型是敌人且我的greenstone已经进入了敌人的可受伤范围
        //回忆槽函数reduceHP亦可当作普通函数调用
        player.reduceHP(20);
        deleteIt();
    }
}

void greenstone::draw(QPainter &p)
{
    drawImage(p,0);
    move();
    if(getStepmax()==0) deleteIt();
}

