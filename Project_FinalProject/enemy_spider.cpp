#include "enemy_spider.h"

#include <QDebug>
static const char *dir_set[]=
    {":/enemy_spider/image/enemy_spider/lwalk_10.png",
     ":/enemy_spider/image/enemy_spider/lwalk_10.png",

     ":/enemy_spider/image/enemy_spider/dying_1.png",
     ":/enemy_spider/image/enemy_spider/dying_1.png",
     ":/enemy_spider/image/enemy_spider/dying_2.png",
     ":/enemy_spider/image/enemy_spider/dying_2.png",
     ":/enemy_spider/image/enemy_spider/dying_3.png",
     ":/enemy_spider/image/enemy_spider/dying_3.png",
     ":/enemy_spider/image/enemy_spider/dying_4.png",
     ":/enemy_spider/image/enemy_spider/dying_4.png",
     ":/enemy_spider/image/enemy_spider/dying_5.png",
     ":/enemy_spider/image/enemy_spider/dying_5.png",
     ":/enemy_spider/image/enemy_spider/dying_6.png",
     ":/enemy_spider/image/enemy_spider/dying_6.png",
     ":/enemy_spider/image/enemy_spider/dying_7.png",
     ":/enemy_spider/image/enemy_spider/dying_7.png",
     ":/enemy_spider/image/enemy_spider/dying_8.png",
     ":/enemy_spider/image/enemy_spider/dying_8.png",
     ":/enemy_spider/image/enemy_spider/dying_9.png",
     ":/enemy_spider/image/enemy_spider/dying_9.png",
     ":/enemy_spider/image/enemy_spider/dying_10.png",
     ":/enemy_spider/image/enemy_spider/dying_10.png",
     ":/enemy_spider/image/enemy_spider/dying_11.png",
     ":/enemy_spider/image/enemy_spider/dying_11.png",
     ":/enemy_spider/image/enemy_spider/dying_12.png",
     ":/enemy_spider/image/enemy_spider/dying_12.png",
     ":/enemy_spider/image/enemy_spider/dying_13.png",
     ":/enemy_spider/image/enemy_spider/dying_13.png",
     ":/enemy_spider/image/enemy_spider/dying_14.png",
     ":/enemy_spider/image/enemy_spider/dying_14.png",

     ":/enemy_spider/image/enemy_spider/lwalk_1.png",
     ":/enemy_spider/image/enemy_spider/lwalk_2.png",
     ":/enemy_spider/image/enemy_spider/lwalk_3.png",
     ":/enemy_spider/image/enemy_spider/lwalk_4.png",
     ":/enemy_spider/image/enemy_spider/lwalk_5.png",
     ":/enemy_spider/image/enemy_spider/lwalk_6.png",
     ":/enemy_spider/image/enemy_spider/lwalk_7.png",
     ":/enemy_spider/image/enemy_spider/lwalk_8.png",
     ":/enemy_spider/image/enemy_spider/lwalk_9.png",
     ":/enemy_spider/image/enemy_spider/lwalk_10.png",
     ":/enemy_spider/image/enemy_spider/lwalk_11.png",
     ":/enemy_spider/image/enemy_spider/lwalk_12.png",
     ":/enemy_spider/image/enemy_spider/lwalk_13.png",
     ":/enemy_spider/image/enemy_spider/lwalk_14.png",
     ":/enemy_spider/image/enemy_spider/lwalk_15.png",
     ":/enemy_spider/image/enemy_spider/lwalk_16.png",
     ":/enemy_spider/image/enemy_spider/lwalk_17.png",
     ":/enemy_spider/image/enemy_spider/lwalk_18.png",
     ":/enemy_spider/image/enemy_spider/lwalk_19.png",
     ":/enemy_spider/image/enemy_spider/lwalk_20.png",

     ":/enemy_spider/image/enemy_spider/rwalk_1.png",
     ":/enemy_spider/image/enemy_spider/rwalk_2.png",
     ":/enemy_spider/image/enemy_spider/rwalk_3.png",
     ":/enemy_spider/image/enemy_spider/rwalk_4.png",
     ":/enemy_spider/image/enemy_spider/rwalk_5.png",
     ":/enemy_spider/image/enemy_spider/rwalk_6.png",
     ":/enemy_spider/image/enemy_spider/rwalk_7.png",
     ":/enemy_spider/image/enemy_spider/rwalk_8.png",
     ":/enemy_spider/image/enemy_spider/rwalk_9.png",
     ":/enemy_spider/image/enemy_spider/rwalk_10.png",
     ":/enemy_spider/image/enemy_spider/rwalk_11.png",
     ":/enemy_spider/image/enemy_spider/rwalk_12.png",
     ":/enemy_spider/image/enemy_spider/rwalk_13.png",
     ":/enemy_spider/image/enemy_spider/rwalk_14.png",
     ":/enemy_spider/image/enemy_spider/rwalk_15.png",
     ":/enemy_spider/image/enemy_spider/rwalk_16.png",
     ":/enemy_spider/image/enemy_spider/rwalk_17.png",
     ":/enemy_spider/image/enemy_spider/rwalk_18.png",
     ":/enemy_spider/image/enemy_spider/rwalk_19.png",
     ":/enemy_spider/image/enemy_spider/rwalk_20.png",

     ":/enemy_spider/image/enemy_spider/lfight_1.png",
     ":/enemy_spider/image/enemy_spider/lfight_2.png",
     ":/enemy_spider/image/enemy_spider/lfight_3.png",
     ":/enemy_spider/image/enemy_spider/lfight_4.png",
     ":/enemy_spider/image/enemy_spider/lfight_5.png",
     ":/enemy_spider/image/enemy_spider/lfight_6.png",
     ":/enemy_spider/image/enemy_spider/lfight_7.png",
     ":/enemy_spider/image/enemy_spider/lfight_8.png",
     ":/enemy_spider/image/enemy_spider/lfight_9.png",
     ":/enemy_spider/image/enemy_spider/lfight_10.png",
     ":/enemy_spider/image/enemy_spider/lfight_11.png",
     ":/enemy_spider/image/enemy_spider/lfight_12.png",
     ":/enemy_spider/image/enemy_spider/lfight_13.png",
     ":/enemy_spider/image/enemy_spider/lfight_14.png",
     ":/enemy_spider/image/enemy_spider/lfight_15.png",
     ":/enemy_spider/image/enemy_spider/lfight_16.png",

     ":/enemy_spider/image/enemy_spider/rfight_1.png",
     ":/enemy_spider/image/enemy_spider/rfight_2.png",
     ":/enemy_spider/image/enemy_spider/rfight_3.png",
     ":/enemy_spider/image/enemy_spider/rfight_4.png",
     ":/enemy_spider/image/enemy_spider/rfight_5.png",
     ":/enemy_spider/image/enemy_spider/rfight_6.png",
     ":/enemy_spider/image/enemy_spider/rfight_7.png",
     ":/enemy_spider/image/enemy_spider/rfight_8.png",
     ":/enemy_spider/image/enemy_spider/rfight_9.png",
     ":/enemy_spider/image/enemy_spider/rfight_10.png",
     ":/enemy_spider/image/enemy_spider/rfight_11.png",
     ":/enemy_spider/image/enemy_spider/rfight_12.png",
     ":/enemy_spider/image/enemy_spider/rfight_13.png",
     ":/enemy_spider/image/enemy_spider/rfight_14.png",
     ":/enemy_spider/image/enemy_spider/rfight_15.png",
     ":/enemy_spider/image/enemy_spider/rfight_16.png"};
static const QPoint rlocation=QPoint(95,112);
static const QPoint rheart=QPoint(90,64);
static const int hurtable_range=50;
static const int attack_range=0;
static const int MAXHP=400;
static const int img_num=102;
static const int speed=5;//
//注意：每增加一次图片，对应在头文件Condition对应位置要写上状态
//并且更新img_num
//照片顺序最好符合逻辑

//以上定义了这么多的符号常量
//仅仅为了下面构造函数使用符号常量不适用裸露的数字，方便修改
//代码中尽量不出现裸露的数字是一个很好的习惯
//这样修改初始值的时候好修改，不用到下面繁杂的代码里面修改
//照片顺序最好先左后右，同一个运动状态的照片放一起
//照片名称最好和condition对应状态一致
Enemy_spider::Enemy_spider(int route):
    Live_player(startposition[route],rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,destination[route][0]),_condition(lstand1),
                point_destination(0),_route(route){}

bool Enemy_spider::inFight_range(const Live_player &obj) const{
    return abs(obj.getObj_locationX()-getObj_locationX())<=70
            &&abs(obj.getObj_locationY()-getObj_locationY())<=50;
}

void Enemy_spider::process(Live_player & obj)//只能判断一个敌人？！
{
    if(!(obj.getType()==Type::princess||obj.getType()==Type::guard))
        return ;
    if(getHP()==0)//猪兵死不了的原因原来在这里！！！（那为什么别的enemy不加这个就能正常死亡呢？）
        return ;
    if(!inFight_range(obj)) return;
    if(_condition==lfight_7||_condition==rfight_7)
    {
        obj.reduceHP(25);//const 不能动！！！近身攻击注定要比远程射击强大
    }
    if(isFight()) return;
    if(obj.getObj_locationX()<getObj_locationX())
        _condition=lfight_1;
    else
        _condition=rfight_1;
}

void Enemy_spider::lfight()
{
    if(_condition>=lfight_1&&_condition<lfight_16)
        _condition=Condition(1+_condition);
    else if(_condition==lfight_16)
        _condition=lstand1;
}

void Enemy_spider::rfight()
{
    if(_condition>=rfight_1&&_condition<rfight_16)
        _condition=Condition(1+_condition);
    else if(_condition==rfight_16)
        _condition=rstand1;
}


void Enemy_spider::dying()
{
    if(_condition==dying_28)
    {
        deleteIt();
    }
    else if(_condition<dying_1||_condition>dying_28)
    {
        _condition=dying_1;
    }
    else
    {
        _condition=Condition(1+_condition);
    }
}

void Enemy_spider::lwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=lstand1;
    else if(_condition>=lwalk_1&&_condition<lwalk_20)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=lwalk_20)
    {
        _condition=lwalk_1;
    }
}

void Enemy_spider::rwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=rstand1;
    else if(_condition>=rwalk_1&&_condition<=rwalk_20)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=rwalk_20)
    {
        _condition=rwalk_1;
    }
}

void Enemy_spider::draw(QPainter &p)
{
    drawImage(p,_condition);
    _sleep=(_sleep+1)%16;
    _sleep_idx=_sleep%5;
    if(getHP()==0)
    {
        dying();
        return ;
    }

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
            if(_condition>=lwalk_1&&_condition<=lwalk_20)
            {
                //if(_sleep_idx) return;
                lwalk();
            }
            else
                _condition=lwalk_1;
        }
        else
        {
            if(_condition>=rwalk_1&&_condition<=rwalk_20)
            {
                //if(_sleep_idx) return;
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
