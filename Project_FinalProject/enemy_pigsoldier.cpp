#include "enemy_pigsoldier.h"

static const char *dir_set[]=
    {":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_1.png",

     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_8.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_9.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_10.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_11.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lattack_/pigsoldier_lattack_12.png",

     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_8.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_9.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_10.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_11.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rattack_/pigsoldier_rattack_12.png",

     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_8.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_8.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_9.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_9.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_10.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_10.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_11.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_11.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_12.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_12.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_13.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_13.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_14.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_14.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_15.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_dying_/pigsoldier_dying_15.png",

     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_8.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lwalk_/pigsoldier_lwalk_8.png",

     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_8.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rwalk_/pigsoldier_rwalk_8.png",

     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lfight_/pigsoldier_lfight_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lfight_/pigsoldier_lfight_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lfight_/pigsoldier_lfight_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lfight_/pigsoldier_lfight_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lfight_/pigsoldier_lfight_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lfight_/pigsoldier_lfight_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lfight_/pigsoldier_lfight_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_lfight_/pigsoldier_lfight_8.png",

     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rfight_/pigsoldier_rfight_1.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rfight_/pigsoldier_rfight_2.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rfight_/pigsoldier_rfight_3.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rfight_/pigsoldier_rfight_4.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rfight_/pigsoldier_rfight_5.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rfight_/pigsoldier_rfight_6.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rfight_/pigsoldier_rfight_7.png",
     ":/enemy_pigsoldier/image/enemy_pigsoldier/pigsoldier_rfight_/pigsoldier_rfight_8.png"};
static const QPoint rlocation=QPoint(197,234);//-(94,21)=(34,79)
static const QPoint rheart=QPoint(188,174);
static const QPoint l_rfireball3=QPoint(35,-184);//
static const QPoint r_rfireball3=QPoint(-64,-184);
static const int hurtable_range=50;
static const int attack_range=250;
static const int MAXHP=400;
static const int img_num=104;//88-15=73
static const int speed=2;//
//注意：每增加一次图片，对应在头文件Condition对应位置要写上状态
//并且更新img_num
//照片顺序最好符合逻辑

//以上定义了这么多的符号常量
//仅仅为了下面构造函数使用符号常量不适用裸露的数字，方便修改
//代码中尽量不出现裸露的数字是一个很好的习惯
//这样修改初始值的时候好修改，不用到下面繁杂的代码里面修改
//照片顺序最好先左后右，同一个运动状态的照片放一起
//照片名称最好和condition对应状态一致
Enemy_pigsoldier::Enemy_pigsoldier(int route):
    Live_player(startposition[route],rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,destination[route][0]),
    _condition(lstand1),point_destination(0),_sleep(0),_route(route){}

bool Enemy_pigsoldier::inFight_range(const Live_player &obj) const{
    return  abs(obj.getObj_locationX()-getObj_locationX())<=60
            &&abs(obj.getObj_locationY()-getObj_locationY())<=30;
}

void Enemy_pigsoldier::process(Live_player & obj)//只能判断一个敌人？！
{
    if(!(obj.getType()==Type::princess||obj.getType()==Type::guard))
        return ;
    if(getHP()==0)//猪兵死不了的原因原来在这里！！！（那为什么别的enemy不加这个就能正常死亡呢？）
        return ;
    if(isAttack())
        return ;
    if(_condition==lfight_6||_condition==rfight_6)
    {
        if(inFight_range(obj))
        obj.reduceHP(50);
    }
    if(isFight()) return;
    if(inFight_range(obj))
    {
        _current_obj=obj.getHeart();
        if(obj.getObj_locationX()<getObj_locationX())
            _condition=lfight_1;
        else
            _condition=rfight_1;
    }
    else if(inAttack_range(obj))
    {
        _current_obj=obj.getHeart();
        if(!isAttack())
        {
            if(obj.getObj_locationX()<getObj_locationX())
                _condition=lattack_1;
            else
                _condition=rattack_1;
        }
    }
}

void Enemy_pigsoldier::lfight()
{
    if(_condition>=lfight_1&&_condition<lfight_8)
        _condition=Condition(1+_condition);
    else if(_condition==lfight_8)
        _condition=lstand1;
}

void Enemy_pigsoldier::rfight()
{
    if(_condition>=rfight_1&&_condition<rfight_8)
        _condition=Condition(1+_condition);
    else if(_condition==rfight_8)
        _condition=rstand1;
}

void Enemy_pigsoldier::lattack()
{
    if(_condition==lattack_6)
        emit fireball3(getObj_location()+l_rfireball3,_current_obj);
    if(_condition>=lattack_1&&_condition<lattack_12)
        _condition=Condition(1+_condition);
    else if(_condition==lattack_12)
        _condition=lstand1;
}

void Enemy_pigsoldier::rattack()
{
    if(_condition==rattack_6)
        emit fireball3(getObj_location()+r_rfireball3,_current_obj);
    if(_condition>=rattack_1&&_condition<rattack_12)
        _condition=Condition(1+_condition);
    else if(_condition==rattack_12)
        _condition=rstand1;
}


void Enemy_pigsoldier::dying()
{
    if(_condition==dying_30)
    {
        deleteIt();
    }
    else if(_condition<dying_1||_condition>dying_30)
    {
        _condition=dying_1;
    }
    else
    {
        _condition=Condition(1+_condition);
    }
}

void Enemy_pigsoldier::lwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=lstand1;
    else if(_condition>=lwalk_1&&_condition<=lwalk_15)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=lwalk_16)
    {
        _condition=lwalk_1;
    }
}

void Enemy_pigsoldier::rwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=rstand1;
    else if(_condition>=rwalk_1&&_condition<=rwalk_15)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=rwalk_16)
    {
        _condition=rwalk_1;
    }
}

void Enemy_pigsoldier::draw(QPainter &p)
{
    drawImage(p,_condition);
    _sleep=(_sleep+1)%40;
    _sleep_idx=_sleep%7;
    if(getHP()==0)
    {
        dying();
        return ;
    }
    if(isAttack())
    {
        lattack();
        rattack();
    }
    //走动过程中停下来进攻！此处与archer不同
    else if(isFight())
    {
        if(_sleep_idx) return;
        lfight();
        rfight();
    }

    else if(getDx()!=0||getDy()!=0)
    {
        if(getDestinationX()<getObj_locationX())
        {
            if(_condition>=lwalk_1&&_condition<=lwalk_16)
            {
                if(_sleep_idx) return;
                lwalk();
            }
            else
                _condition=lwalk_1;
        }
        else
        {
            if(_condition>=rwalk_1&&_condition<=rwalk_16)
            {
                if(_sleep_idx) return;
                rwalk();
            }
            else
                _condition=rwalk_1;
        }
        if(_sleep_idx) return;
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
