#include "Enemy_cavalry_wolf.h"//改数字！！！

static const char *dir_set[]=
    {
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_1.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_2.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_3.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_4.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_5.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_6.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_7.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_8.png",


    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_rrun_/cavalry_wolf_rrun_1.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_rrun_/cavalry_wolf_rrun_2.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_rrun_/cavalry_wolf_rrun_3.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_rrun_/cavalry_wolf_rrun_4.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_rrun_/cavalry_wolf_rrun_5.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_rrun_/cavalry_wolf_rrun_6.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_rrun_/cavalry_wolf_rrun_7.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_rrun_/cavalry_wolf_rrun_8.png",

    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_lrun_1.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_lrun_/cavalry_wolf_rrun_1.png",

    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_1.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_1.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_2.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_2.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_3.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_3.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_4.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_4.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_5.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_5.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_6.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_6.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_7.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_7.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_8.png",
    ":/enemy_cavalry_wolf/image/enemy_cavalry_wolf/cavalry_wolf_dying_/cavalry_wolf_dying_8.png",
     };

//static const int xpos=1200;
//static const int ypos=500;
static const QPoint rlocation=QPoint(25,52);//
static const QPoint rheart=QPoint(25,26);//
static const int hurtable_range=30;
static const int attack_range=0;
static const int MAXHP=100;
static const int img_num=34;
static const int speed=5;




Enemy_cavalry_wolf::Enemy_cavalry_wolf(int route):
    Live_player(startposition[route],rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,destination[route][0]),
    _condition(lrun1),point_destination(0),_route(route){}


void Enemy_cavalry_wolf::lrun()
{
    if(_condition>=lrun1&&_condition<=lrun7)
    {
        _condition=Condition(1+_condition);
        move();
    }
    else
    {
        _condition=lrun1;
        move();
    }
}


void Enemy_cavalry_wolf::rrun()
{
    if(_condition>=rrun1&&_condition<=rrun7)
    {
        _condition=Condition(1+_condition);
        move();
    }
    else
    {
        _condition=rrun1;
        move();
    }
}


void Enemy_cavalry_wolf::dying()
{
    if(_condition==dying16)
    {
        deleteIt();
        emit death();
    }
    else if(_condition<dying1)
        _condition=dying1;
    else
    {
        _condition=Condition(1+_condition);
    }
}


void Enemy_cavalry_wolf::draw(QPainter &p)
{
    drawImage(p,_condition);

    if(getHP()==0)
    {
        dying();
        return ;
    }
    if(getDx()==0&&getDy()==0)
    {
        //到达目的地
        if(point_destination<=2)
        {
            point_destination++;
            setDestination(destination[_route][point_destination]);
        }
        else
            emit lose();
    }
    if(getDestinationX()<getObj_locationX())
        lrun();
    else if(getDestinationX()>getObj_locationX())
        rrun();
    else
        _condition=lstand;

}
