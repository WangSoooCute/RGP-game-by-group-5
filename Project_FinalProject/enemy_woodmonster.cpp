#include "enemy_woodmonster.h"
#include <QPoint>
/*
#include <QPainter>
#include<QImage>

static const char *pic_shockwave[]=
    {":/others/image/others/shockwave/shockwave_1.png",
     ":/others/image/others/shockwave/shockwave_2.png",
     ":/others/image/others/shockwave/shockwave_3.png",
     ":/others/image/others/shockwave/shockwave_4.png",
     ":/others/image/others/shockwave/shockwave_5.png",
     ":/others/image/others/shockwave/shockwave_6.png",
     ":/others/image/others/shockwave/shockwave_7.png",
     ":/others/image/others/shockwave/shockwave_8.png",
     ":/others/image/others/shockwave/shockwave_9.png",
     ":/others/image/others/shockwave/shockwave_10.png",
     ":/others/image/others/shockwave/shockwave_11.png",
     ":/others/image/others/shockwave/shockwave_12.png"
     //":/others/image/others/shockwave/shockwave_13.png",
     //":/others/image/others/shockwave/shockwave_14.png",
     };
int Enemy_woodmonster::shockwave_i=0;
*/

static const char *dir_set[]=
{
    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_1.png",

    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_6.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_7.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_8.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_9.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_10.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_11.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lattack_12.png",

    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_6.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_7.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_8.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_9.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_10.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_11.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rattack_12.png",


    ":/enemy_woodmonster/image/enemy_woodmonster/dying_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_6.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_6.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/dying_6.png",

    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_6.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_7.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lwalk_8.png",

    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_6.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_7.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rwalk_8.png",

    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_6.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_7.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_8.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_9.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_10.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/lfight_11.png",

    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_1.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_2.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_3.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_4.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_5.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_6.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_7.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_8.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_9.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_10.png",
    ":/enemy_woodmonster/image/enemy_woodmonster/rfight_11.png",
};

static const QPoint rlocation=QPoint(70,120);//(20,4)-(70,120)=(-50,-116)
static const QPoint rheart=QPoint(70,80);
//static const QPoint l_rshockwave=QPoint(-34,-79);//
//static const QPoint r_rshockwave=QPoint(34,-79);
//static const QPoint foot_to_shockwave=QPoint(-50,-116);//////////
static const int hurtable_range=50;
static const int attack_range=70;
static const int fight_range=20;//
static const int MAXHP=400;
static const int img_num=82;
static const int speed=5;//

Enemy_woodmonster::Enemy_woodmonster(int route):
    Live_player(startposition[route],rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,destination[route][0]),
    _fight_range(fight_range),_condition(lstand1),point_destination(0),_sleep(0),_route(route){}

bool Enemy_woodmonster::inFight_range(const Live_player &obj) const{
    return _fight_range>=ObjDistanceWith(obj)
            &&abs(obj.getObj_locationX()-getObj_locationX())<=60
            &&abs(obj.getObj_locationY()-getObj_locationY())<=30;
}

void Enemy_woodmonster::process(Live_player & obj)//只能判断一个敌人？！
{
    if(!(obj.getType()==Type::princess||obj.getType()==Type::guard))
        return ;
    if(getHP()==0)//猪兵死不了的原因原来在这里！！！（那为什么别的enemy不加这个就能正常死亡呢？）
        return ;
    if(isAttack())//||isFight())
        return ;
    if(isFight())
    {
        if(inFight_range(obj))
        obj.reduceHP(6);
        return;
    }
    if(inFight_range(obj))
    {
        if(obj.getObj_locationX()<getObj_locationX())
            _condition=lfight_1;
        else
            _condition=rfight_1;
    }
    else if(inAttack_range(obj))
    {
        connect(this,SIGNAL(shockwave(int)),&obj,SLOT(reduceHP(int)),Qt::UniqueConnection);
        if(obj.getObj_locationX()<getObj_locationX())
            _condition=lattack_1;
        else
            _condition=rattack_1;
    }
    else
    {
        disconnect(this,SIGNAL(shockwave(int)),&obj,SLOT(reduceHP(int)));
    }
}

void Enemy_woodmonster::lfight()
{
    if(_condition>=lfight_1&&_condition<lfight_11)
        _condition=Condition(1+_condition);
    else if(_condition==lfight_11)
        _condition=lstand1;
}

void Enemy_woodmonster::rfight()
{
    if(_condition>=rfight_1&&_condition<rfight_11)
        _condition=Condition(1+_condition);
    else if(_condition==rfight_11)
        _condition=rstand1;
}

void Enemy_woodmonster::lattack()
{
    if(_condition==lattack_6)
        emit shockwave(10);
    if(_condition>=lattack_1&&_condition<lattack_12)
        _condition=Condition(1+_condition);
    else if(_condition==lattack_12)
        _condition=lstand1;
}

void Enemy_woodmonster::rattack()
{
    if(_condition==rattack_6)
        emit shockwave(10);
    if(_condition>=rattack_1&&_condition<rattack_12)
        _condition=Condition(1+_condition);
    else if(_condition==rattack_12)
        _condition=rstand1;
}


void Enemy_woodmonster::dying()
{
    if(_condition==dying_18)
    {
        deleteIt();
    }
    else if(_condition<dying_1||_condition>dying_18)
    {
        _condition=dying_1;
    }
    else
    {
        _condition=Condition(1+_condition);
    }
}

void Enemy_woodmonster::lwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=lstand1;
    else if(_condition>=lwalk_1&&_condition<lwalk_8)
    {
        _condition=Condition(1+_condition);
    }
    else
    {
        _condition=lwalk_1;
    }
}

void Enemy_woodmonster::rwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=rstand1;
    else if(_condition>=rwalk_1&&_condition<rwalk_8)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=rwalk_8)
    {
        _condition=rwalk_1;
    }
}

void Enemy_woodmonster::draw(QPainter &p)
{
    if(getHP()==0)
    {
        drawImage(p,_condition);
        dying();
        return ;
    }
    if(isAttack())
    {
        drawImage(p,_condition);
        lattack();//continue lattack
        rattack();//continue rattack
        return ;
    }
    drawImage(p,_condition);
    _sleep=(_sleep+1)%16;
    _sleep_idx=_sleep%5;
    if(isFight())
    {
        if(_sleep_idx) return;
        lfight();
        rfight();
    }

    else if(getDx()!=0||getDy()!=0)
    {
        if(getDestinationX()<getObj_locationX())
        {
            if(_condition>=lwalk_1&&_condition<=lwalk_8)
            {
                if(_sleep_idx) return;
                lwalk();
            }
            else
                _condition=lwalk_1;
        }
        else
        {
            if(_condition>=rwalk_1&&_condition<=rwalk_8)
            {
                if(_sleep_idx) return;
                rwalk();
            }
            else
                _condition=rwalk_1;
        }
        move();
    }
    else if(point_destination<=2)
    {
        point_destination++;
        setDestination(destination[_route][point_destination]);
    }
    else
        emit lose();
}
