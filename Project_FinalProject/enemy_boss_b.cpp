#include "enemy_boss_b.h"
#include <cstdlib>
#include <ctime>
#include <QPoint>
#include <iostream>
using namespace std;


static const char*dir_set[]=
    {
     ":/enermy_boss_b/image/enermy_boss_b/l_stand.png",
     ":/enermy_boss_b/image/enermy_boss_b/r_stand.png",

     ":/enermy_boss_b/image/enermy_boss_b/appear (1).png",
     ":/enermy_boss_b/image/enermy_boss_b/appear (2).png",
     ":/enermy_boss_b/image/enermy_boss_b/appear (3).png",
     ":/enermy_boss_b/image/enermy_boss_b/appear (4).png",
     ":/enermy_boss_b/image/enermy_boss_b/appear (5).png",

     ":/enermy_boss_b/image/enermy_boss_b/disappear (1).png",
     ":/enermy_boss_b/image/enermy_boss_b/disappear (2).png",
     ":/enermy_boss_b/image/enermy_boss_b/disappear (3).png",
     ":/enermy_boss_b/image/enermy_boss_b/disappear (4).png",
     ":/enermy_boss_b/image/enermy_boss_b/disappear (5).png",


     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (1).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (2).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (3).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (4).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (5).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (6).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (7).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (8).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (9).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (10).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (11).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (12).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (13).png",
     ":/enermy_boss_b/image/enermy_boss_b/bl_attack (14).png",

     ":/enermy_boss_b/image/enermy_boss_b/br_attack (1).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (2).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (3).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (4).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (5).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (6).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (7).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (8).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (9).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (10).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (11).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (12).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (13).png",
     ":/enermy_boss_b/image/enermy_boss_b/br_attack (14).png",

     ":/enermy_boss_b/image/enermy_boss_b/r_death (1).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (2).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (3).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (4).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (5).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (6).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (7).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (8).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (9).png",
     ":/enermy_boss_b/image/enermy_boss_b/r_death (10).png"
    };
static const QPoint rlocation=QPoint(40,87);
static const QPoint rheart=QPoint(38,62);
//图片大小为94*94
static const QPoint l_orangeball=QPoint(11,-17);//
static const QPoint r_orangeball=QPoint(8,-17);

static const int hurtable_range=25;
static const int attack_range=200;//？瞎写的，再调
static const int MAXHP=800;
static const int img_num=50;
static const int speed=4;

Enemy_boss_b::Enemy_boss_b(const QPoint &beginposition):
    Live_player(QPoint(750,400),rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,destination[0][0]),
    _condition(appear1),startpoint(beginposition),point_destination(0),_sleep_boss_b(0),timing(0){}


void Enemy_boss_b::process( Live_player & obj)
{
    if(global_condition==Background::map1)//第一关
    {
        if(_condition==l_stand) return;
        react(Command::Appear);

//        return;
    }
    else//第三关
    {
    if(obj.getType()==Type::princess)
    {
        if(obj.getObj_locationX()<this->getObj_locationX())
        {
            if(attackornot())
                react(Command::Lattack);
            else
                react(Command::Lstand);
        }
        else
        {
            if(attackornot())
                react(Command::Rattack);
            else
                react(Command::Rstand);
        }
    }
    if(getHP()==0)
        react(Command::Death);
    if(moveornot()==true)
        react(Command::Disappear);
    if(_condition==disappear5)
        react(Command::Appear);
    }
    if(_condition==appear5)
        react(Command::Lstand);
}

void Enemy_boss_b::react(Command cmd)
{
    if(_sleep_boss_b%2) return;
    switch(cmd){
        case Command::Appear:
            if(_condition<=appear5&&_condition>appear1) break;
            if(global_condition==Background::map3)
            {
            srand((unsigned)time(NULL));
            setObj_location(QPoint(rand()%800+200,rand()%600+200));
            }
            else
                setObj_location(QPoint(996,492));
            _condition=Condition::appear1;
            break;
        case Command::Disappear:
            if(_condition>=disappear1&&_condition<=disappear5) break;
            _condition=Condition::disappear1;
            break;
        case Command::Lattack:
            if(_condition==b_lattack14||_condition==b_rattack14||_condition==l_stand||_condition==r_stand)
                _condition=b_lattack1;
            break;
        case Command::Rattack:
            if(_condition==b_lattack14||_condition==b_rattack14||_condition==l_stand||_condition==r_stand)
                _condition=b_rattack1;
            break;
        case Command::Rstand:
            if(_condition==appear5||_condition==b_lattack14||_condition==b_rattack14||_condition==l_stand)
                _condition=r_stand;
            break;
        case Command::Lstand:
            if(_condition==appear5||_condition==b_lattack14||_condition==b_rattack14||_condition==r_stand)
                _condition=l_stand;
            break;
        case Command::Death:
            if(_condition<death1)
                _condition=death1;
            else if(_condition==death10)
                deleteIt();
            //还没有
            break;
        default:
            break;
    }
}


void Enemy_boss_b::draw(QPainter &p)
{
    timing++;
    drawImage(p,_condition);
    if(timing%3) return;
    if(_condition==b_lattack9)
    {
        emit Orangeball(getObj_location()+l_orangeball,0);
        emit Orangeball(getObj_location()+l_orangeball,1);
        emit Orangeball(getObj_location()+l_orangeball,2);
        emit Orangeball(getObj_location()+l_orangeball,3);
    }
    if(_condition==b_rattack9)
    {
        emit Orangeball(getObj_location()+r_orangeball,0);
        emit Orangeball(getObj_location()+r_orangeball,1);
        emit Orangeball(getObj_location()+r_orangeball,2);
        emit Orangeball(getObj_location()+r_orangeball,3);
    }
    if((_condition>=appear1&&_condition<appear5)||(_condition>=disappear1&&_condition<disappear5)||(_condition>=b_lattack1&&_condition<b_lattack14)||(_condition>=b_rattack1&&_condition<b_rattack14)||(_condition>=death1&&_condition<death10))
       _condition=Condition(_condition+1);
    //注意弄清楚_condition满足什么状态发送信号比较合适
}

/*
void Enemy_boss_b::setObj_location(const QPoint &obj_location)
{
    this->react(Command::Disappear);
    if(_condition==disappear5)
    {
        Live_player::setObj_location(obj_location);
        react(Command::Appear);
    }
}
*/

bool Enemy_boss_b::attackornot()
{
    if(timing%200)
        return false;
    else
        return true;
}

bool Enemy_boss_b::moveornot()
{
    if(timing==800)
    {
        timing=0;
        return true;
    }
    else
        return false;
}
