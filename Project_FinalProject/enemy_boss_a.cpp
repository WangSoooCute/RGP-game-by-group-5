#include "enemy_boss_a.h"
#include <QPoint>
#include <iostream>
using namespace std;

static const char*dir_set[]=
    {":/enermy_boss_a/image/enermy_boss_a/al_walk (1).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (2).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (3).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (4).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (5).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (6).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (7).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (8).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (9).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (10).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (11).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_walk (12).png",

     ":/enermy_boss_a/image/enermy_boss_a/al_attack (1).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (2).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (3).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (4).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (5).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (6).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (7).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (8).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (9).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (10).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (11).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (12).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (13).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (14).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (15).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (16).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (17).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (18).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (19).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (20).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (21).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (22).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (23).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (24).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (25).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (26).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (27).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (28).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (29).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (30).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (31).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (32).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (33).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_attack (34).png",


     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (1).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (2).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (3).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (4).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (5).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (6).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (7).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (8).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (9).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (10).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (11).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (12).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (13).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (14).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (15).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (16).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (17).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (18).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (19).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (20).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (21).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (22).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (23).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (24).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (25).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (26).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (27).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (28).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (29).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (30).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (31).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (32).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (33).png",
     ":/enermy_boss_a/image/enermy_boss_a/ar_attack (34).png",

     ":/enermy_boss_a/image/enermy_boss_a/al_death (1).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (2).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (3).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (4).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (5).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (6).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (7).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (8).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (9).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (10).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (11).png",
     ":/enermy_boss_a/image/enermy_boss_a/al_death (12).png",
    };
static const QPoint rlocation=QPoint(116,188);
static const QPoint rheart=QPoint(114,128);
//图片大小为224*216
static const QPoint l_missile=QPoint(16,-120);
static const QPoint r_missile=QPoint(-21,-120);
static const int hurtable_range=60;
static const int attack_range=200;//？瞎写的，再调
static const int MAXHP=1000;
static const int img_num=92;
static const int speed=5;

Enemy_boss_a::Enemy_boss_a(int route):
    Live_player(startposition[route],rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,destination[route][0]),
    _condition(a_lwalk1),point_destination(0),_sleep_boss_a(0),_route(route),bossbamount(0){}

void Enemy_boss_a::process(Live_player & obj)
{
    if(getHP()==0)
        react(Command::Death);
    if(obj.getType()==Type::princess&&inAttack_range(obj))
    {
        if(inMyLeft(obj))
            react(Command::Lattack);
        else react(Command::Rattack);
    }
    else
        react(Command::Lwalk);
}

void Enemy_boss_a::react(Command cmd)
{
    if(_sleep_boss_a%5) return;
    switch(cmd){
        case Command::Lwalk:
            if(getHP()==0)break;
            if(_condition==a_rattack34||_condition==a_lattack34||_condition==a_lwalk12)
                _condition=a_lwalk1;
            break;
        case Command::Lattack:
            if(getHP()==0)break;
            if(_condition<a_lattack1)
                _condition=a_lattack1;
            else if(_condition==a_rattack34||_condition==a_lattack34)
                    _condition=a_lattack1;
            break;
        case Command::Rattack:
            if(getHP()==0)break;
            if(_condition<a_lattack1)
                _condition=a_rattack1;
            else if(_condition==a_rattack34)
                _condition=a_rattack1;
            else if(_condition==a_lattack34)
                    _condition=a_rattack1;
            break;
        case Command::Death:
            if(_condition<a_death1)
            {
                _condition=a_death1;
            }
            else if(_condition==a_death12)
            {
                if(bossbamount==0)
                {
                    emit boss_b(getObj_location());
                    bossbamount++;
                }
                deleteIt();
            }
        default:
            break;
    }
}

void Enemy_boss_a::draw(QPainter &p)
{
    drawImage(p,_condition);
    _sleep_boss_a=(_sleep_boss_a+1)%10;
    if(_sleep_boss_a%5) return;
    if((_condition>=a_rattack1&&_condition<a_rattack34)||(_condition>=a_lattack1&&_condition<a_lattack34)||(_condition>=a_death1&&_condition<a_death12)||_condition<a_lwalk12)
         _condition=Condition(1+_condition);
    if(isWalking())
    {
        int dx=getDx();
        int dy=getDy();
        if(dx==0&&dy==0)
        {
            if(point_destination==3)
            {
                emit lose();
                deleteIt();
            }
            //到达目的地
            if(point_destination<=2)
            {
                point_destination++;
                setDestination(destination[_route][point_destination]);
            }
        }
        move();
    }
    if(_condition==a_lattack13)
        emit missile(getObj_location()+l_missile);
    else if(_condition==a_rattack13)
        emit missile(getObj_location()+r_missile);

    //注意弄清楚_condition满足什么状态发送信号比较合适
}

bool Enemy_boss_a::isWalking(void)const
{
    if(_condition>=a_lwalk1&&_condition<=a_lwalk12)
        return true;
    else
        return false;
}
