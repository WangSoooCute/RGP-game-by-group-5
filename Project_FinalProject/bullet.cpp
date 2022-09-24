#include "Bullet.h"

static const char *dirset[]=
    {":/others/image/others/bullet.png",
    };
static const QPoint rlocation=QPoint(12,3);//?????
static const int img_num=1;
static const int speed=30;
static const int stepmax=10;//

Bullet::Bullet(const QPoint & obj_location, const QPoint &heart):
    Thrown_obj(obj_location,rlocation,heart,img_num,dirset,speed,stepmax){}


void Bullet::draw(QPainter &p)
{
    drawImage(p,0);
    if(getStepmax()==0)
    deleteIt();
    move();
}

void Bullet::process(Live_player &player)
{
    if(!(player.getType()==Type::enemy||player.getType()==Type::boss))
        return ;
    if(player.inHurtableRange(*this))
    {
        //类型是敌人且我的iceball已经进入了敌人的可受伤范围
        //回忆槽函数reduceHP亦可当作普通函数调用
        player.reduceHP(10);
        deleteIt();
    }
}
