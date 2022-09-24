#include "enemy_greenmonster.h"

static const char *dir_set[]=
    {":/enemy_greenmonster/image/enemy_greenmonster/l_walk (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (8).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (8).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (9).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (9).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (10).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (10).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (11).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (11).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (12).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_walk (12).png",


     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (8).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (8).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (8).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (9).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (9).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/l_attack (9).png",



     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (8).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (8).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (8).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (9).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (9).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/r_attack (9).png",


     ":/enemy_greenmonster/image/enemy_greenmonster/death (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (1).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (2).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (3).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (4).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (5).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (6).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (7).png",
     ":/enemy_greenmonster/image/enemy_greenmonster/death (7).png"
    };
static const QPoint rlocation=QPoint(86,106);
static const QPoint rheart=QPoint(86,73);
//图片大小为168*136
static const QPoint l_greenstone=QPoint(-12,-52);
static const QPoint r_greenstone=QPoint(20,-55);
static const int hurtable_range=50;
static const int attack_range=300;//？瞎写的，再调
static const int MAXHP=300;//同瞎写
static const int img_num=99;
static const int speed=4;



Enemy_greenmonster::Enemy_greenmonster(int route):
    Live_player(startposition[route],rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,destination[route][0]),
    _condition(l_walk1_1),point_destination(0),_sleep_monster(0),_route(route),_current_obj(QPoint(0,0)){}


void Enemy_greenmonster::process( Live_player & obj)
{
    if(obj.getType()==Type::enemy||obj.getType()==Type::boss) return;
    if(getHP()==0)
        react(Command::Death);
    if(inAttack_range(obj))
    {
        _current_obj=obj.getHeart();
        if(inMyLeft(obj))
            react(Command::Lattack);
        else react(Command::Rattack);
    }
    else
        react(Command::Lwalk);
}

void Enemy_greenmonster::react(Command cmd)
{
    if(_sleep_monster%2) return;
    switch(cmd){
        case Command::Lwalk:
            if(getHP()==0)break;
            if(_condition==r_attack9_3||_condition==l_attack9_3||_condition==l_walk12_2)
                _condition=l_walk1_1;
            break;
        case Command::Lattack:
            if(getHP()==0)break;
            //if(!isStanding()) return;
            //冰女进入攻击范围后小兵先停下再进攻
            //移动中无法进攻
            if(_condition<l_attack1_1)
                _condition=l_attack1_1;
            else if(_condition==l_attack9_3||_condition==r_attack9_3)
                _condition=l_attack1_1;
            break;
        case Command::Rattack:
            if(getHP()==0)break;
            if(_condition<l_attack1_1)
                _condition=r_attack1_1;
            else if(_condition==l_attack9_3||_condition==r_attack9_3)
                _condition=r_attack1_1;
            break;
        case Command::Death:
            if(_condition<death1_1)
                _condition=death1_1;
            else if(_condition==death7_3)
            {
                emit death();
                deleteIt();
            }
        default:
            break;
    }
}


void Enemy_greenmonster::draw(QPainter &p)
{
    drawImage(p,_condition);
    _sleep_monster=(_sleep_monster+1)%4;
    if(_sleep_monster%2) return;
    if((_condition>=death1_1&&_condition<death7_3)||(_condition>=l_attack1_1&&_condition<l_attack9_3)||(_condition>=r_attack1_1&&_condition<r_attack9_3)||(_condition<l_walk12_2))
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
        if(_sleep_monster%8) return;
        move();
    }

    if(_condition==l_attack5_2)
        emit greenstone(getObj_location()+l_greenstone,_current_obj);
    else if(_condition==r_attack5_2)
        emit greenstone(getObj_location()+r_greenstone,_current_obj);
    //注意弄清楚_condition满足什么状态发送信号比较合适
}


bool Enemy_greenmonster::isWalking(void)const
{
    if(_condition>=l_walk1_1&&_condition<=l_walk12_2)
        return true;
    else
        return false;
}
