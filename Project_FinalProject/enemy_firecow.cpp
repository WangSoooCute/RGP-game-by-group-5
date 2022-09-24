#include "enemy_firecow.h"

static const char *dir_set[]=
    {
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_1.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_1.png",

    ":/enemy_firecow/image/enemy_firecow/firecow_lattack_/firecow_lattack_1.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lattack_/firecow_lattack_2.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lattack_/firecow_lattack_3.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lattack_/firecow_lattack_4.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lattack_/firecow_lattack_5.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lattack_/firecow_lattack_6.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lattack_/firecow_lattack_7.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lattack_/firecow_lattack_8.png",

    ":/enemy_firecow/image/enemy_firecow/firecow_rattack_/firecow_rattack_1.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rattack_/firecow_rattack_2.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rattack_/firecow_rattack_3.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rattack_/firecow_rattack_4.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rattack_/firecow_rattack_5.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rattack_/firecow_rattack_6.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rattack_/firecow_rattack_7.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rattack_/firecow_rattack_8.png",





     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_1.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_1.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_1.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_2.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_2.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_2.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_3.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_3.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_3.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_4.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_4.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_4.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_5.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_5.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_5.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_6.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_6.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_6.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_7.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_7.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_7.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_8.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_8.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_dying_/firecow_dying_8.png",

     ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_1.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_1.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_2.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_2.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_3.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_3.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_4.png",
     ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_4.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_5.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_5.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_6.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_6.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_7.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_7.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_8.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_lwalk_/firecow_lwalk_8.png",

     ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_1.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_1.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_2.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_2.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_3.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_3.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_4.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_4.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_5.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_5.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_6.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_6.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_7.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_7.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_8.png",
    ":/enemy_firecow/image/enemy_firecow/firecow_rwalk_/firecow_rwalk_8.png"

};
static const QPoint rlocation=QPoint(25,50);//-(22,21)=(3,29)
static const QPoint rheart=QPoint(25,25);
static const QPoint l_rfireball2=QPoint(-3,-29);//
static const QPoint r_rfireball2=QPoint(3,-29);
static const int hurtable_range=50;
static const int attack_range=250;
static const int MAXHP=300;
static const int img_num=66;
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
Enemy_firecow::Enemy_firecow(int route):
    Live_player(startposition[route],rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,destination[route][0]),
    _condition(lstand1),point_destination(0),_route(route),idx(0){}


void Enemy_firecow::process(Live_player & obj)//只能判断一个敌人？！//去掉了const
{
    if(!(obj.getType()==Type::princess||obj.getType()==Type::guard))
        return ;
    if(!inAttack_range(obj))
        return ;
    if(isAttack())
        return ;
    //if(_condition>=lwalk_1&&_condition<=rwalk_6)
        //return ;
    _current_obj=obj.getHeart();//!!!!!!!!!!!!!!!!!!!!!!!!!!
    if(_condition==lstand1||_condition==rstand1||_condition>=lwalk_1)/////////////bug改好之处
    {
        if(obj.getObj_locationX()<getObj_locationX())
            _condition=lattack_1;
        else
            _condition=rattack_1;
    }
}

void Enemy_firecow::lattack()
{
    if(_condition==lattack_6)
        emit fireball2(getObj_location()+l_rfireball2,_current_obj);
    if(_condition>=lattack_1&&_condition<lattack_8)
        _condition=Condition(1+_condition);
    else if(_condition==lattack_8)
        _condition=lstand1;
}

void Enemy_firecow::rattack()
{
    if(_condition==rattack_6)
        emit fireball2(getObj_location()+r_rfireball2,_current_obj);
    if(_condition>=rattack_1&&_condition<rattack_8)
        _condition=Condition(1+_condition);
    else if(_condition==rattack_8)
        _condition=rstand1;
}

void Enemy_firecow::dying()
{
    if(_condition==dying_16)
    {
        deleteIt();
    }
    else if(_condition<dying_1||_condition>dying_16)
        _condition=dying_1;
    else
    {
        _condition=Condition(1+_condition);
    }
}

void Enemy_firecow::lwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=lstand1;
    else if(_condition>=lwalk_1&&_condition<lwalk_16)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=lwalk_16)
    {
        _condition=lwalk_1;
    }
}

void Enemy_firecow::rwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=rstand1;
    else if(_condition>=rwalk_1&&_condition<=rwalk_16)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=rwalk_16)
    {
        _condition=rwalk_1;
    }
}

void Enemy_firecow::draw(QPainter &p)
{
    idx=(idx+1)%3;
    drawImage(p,_condition);
    if(idx) return;
    if(getHP()==0)
    {
        dying();
        return ;
    }
    if(isAttack())
    {
        lattack();//continue lattack
        rattack();//continue rattack
    }
    //走动过程中停下来进攻！此处与archer不同

    else if(getDx()!=0||getDy()!=0)
    {
        if(getDestinationX()<getObj_locationX())
        {
            if(_condition>=lwalk_1&&_condition<=lwalk_16)
            {
                lwalk();
            }
            else
                _condition=lwalk_1;
        }
        else
        {
            if(_condition>=rwalk_1&&_condition<=rwalk_16)
            {
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
