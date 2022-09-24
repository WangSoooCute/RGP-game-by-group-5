#include "guard_archer.h"
#include <QPoint>

static const char *dir_set[]=
    {":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_1.png",
     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_1.png",

     ":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_1.png",
     ":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_2.png",
     ":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_3.png",
     ":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_4.png",
     ":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_5.png",
     ":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_6.png",
     ":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_7.png",
     ":/guard/archer/image/guard_archer/archer_lattack_/archer_lattack_8.png",

     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_1.png",
     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_2.png",
     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_3.png",
     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_4.png",
     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_5.png",
     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_6.png",
     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_7.png",
     ":/guard/archer/image/guard_archer/archer_rattack_/archer_rattack_8.png",

     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_1.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_1.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_2.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_2.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_3.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_3.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_4.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_4.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_5.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_5.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_6.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_6.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_7.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_7.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_8.png",
     ":/guard/archer/image/guard_archer/archer_dying_/archer_dying_8.png",

     ":/guard/archer/image/guard_archer/archer_lwalk_/archer_lwalk_1.png",
     ":/guard/archer/image/guard_archer/archer_lwalk_/archer_lwalk_2.png",
     ":/guard/archer/image/guard_archer/archer_lwalk_/archer_lwalk_3.png",
     ":/guard/archer/image/guard_archer/archer_lwalk_/archer_lwalk_4.png",
     ":/guard/archer/image/guard_archer/archer_lwalk_/archer_lwalk_5.png",
     ":/guard/archer/image/guard_archer/archer_lwalk_/archer_lwalk_6.png",

     ":/guard/archer/image/guard_archer/archer_rwalk_/archer_rwalk_1.png",
     ":/guard/archer/image/guard_archer/archer_rwalk_/archer_rwalk_2.png",
     ":/guard/archer/image/guard_archer/archer_rwalk_/archer_rwalk_3.png",
     ":/guard/archer/image/guard_archer/archer_rwalk_/archer_rwalk_4.png",
     ":/guard/archer/image/guard_archer/archer_rwalk_/archer_rwalk_5.png",
     ":/guard/archer/image/guard_archer/archer_rwalk_/archer_rwalk_6.png"
     };
static const QPoint rlocation=QPoint(45,68);//-(32,30)=(16,56)
static const QPoint rheart=QPoint(48,43);
static const QPoint l_rArrow=QPoint(-16,-56);//(16,16)
static const QPoint r_rArrow=QPoint(16,-56);
static const int hurtable_range=30;
static const int attack_range=150;
static const int MAXHP=400;
static const int img_num=46;
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
Guard_archer::Guard_archer(int xpos, int ypos):
    Live_player(QPoint(xpos,ypos),rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,QPoint(xpos,ypos)),
    _condition(rstand1){}

Guard_archer::Guard_archer(const QPoint & obj_location):
    Live_player(obj_location,rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,obj_location),//des赋值的问题:player.front()->setDestination
    _condition(rstand1){}

void Guard_archer::process(Live_player &obj)//只能判断一个敌人？！
{
    if(!(obj.getType()==Type::boss||obj.getType()==Type::enemy))
        return ;
    if(!inAttack_range(obj))
        return ;
    if(_condition>=lattack_1&&_condition<=rattack_8)
        return ;
    if(getDx()!=0||getDy()!=0)
        return ;
    //if(_condition>=lwalk_1&&_condition<=rwalk_6)
        //return ;
    _rival_heart=obj.getHeart();//!!!!!!!!!!!!!!!!!!!!!!!!!!
    if(_condition==lstand1||_condition==rstand1/*||_condition>=lwalk_1*/)/////////////bug改好之处
    {
        if(obj.getObj_locationX()<getObj_locationX())
            _condition=lattack_1;
        else
            _condition=rattack_1;
    }
}

void Guard_archer::lattack()
{
    if(_condition==lattack_6)
        emit arrow(getObj_location()+l_rArrow,_rival_heart);
    if(_condition>=lattack_1&&_condition<lattack_8)
        _condition=Condition(1+_condition);
    else if(_condition==lattack_8)
        _condition=lstand1;
}

void Guard_archer::rattack()
{
    if(_condition==rattack_6)
        emit arrow(getObj_location()+r_rArrow,_rival_heart);
    if(_condition>=rattack_1&&_condition<rattack_8)
        _condition=Condition(1+_condition);
    else if(_condition==rattack_8)
        _condition=rstand1;
}

void Guard_archer::dying()
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

void Guard_archer::lwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=lstand1;
    else if(_condition>=lwalk_1&&_condition<=lwalk_5)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=lwalk_6)
    {
        _condition=lwalk_1;
    }
}

void Guard_archer::rwalk()
{
    if(getDx()==0&&getDy()==0)
        _condition=rstand1;
    else if(_condition>=rwalk_1&&_condition<=rwalk_5)
    {
        _condition=Condition(1+_condition);
    }
    else //if(_condition=rwalk_6)
    {
        _condition=rwalk_1;
    }
}

void Guard_archer::draw(QPainter &p)
{
    drawImage(p,_condition);
    if(getHP()==0)
    {
        dying();
        return ;
    }
    if(_condition>=lattack_1&&_condition<=lattack_8)
        lattack();
    else if(_condition>=rattack_1&&_condition<=rattack_8)
        rattack();
    if(getDx()!=0||getDy()!=0)
    {
        if(getDestinationX()<getObj_locationX())
        {
            if(_condition>=lwalk_1&&_condition<=lwalk_6)
            {
                lwalk();
            }
            else
                _condition=lwalk_1;
        }
        else
        {
            if(_condition>=rwalk_1&&_condition<=rwalk_6)
            {
                rwalk();
            }
            else
                _condition=rwalk_1;
        }
        move();
    }
    else
    {
        if(_condition>=rwalk_1&&_condition<=rwalk_6)
        {
            _condition=rstand1;
            emit arrive();
        }
        else if(_condition>=lwalk_1&&_condition<=lwalk_6)
        {
            _condition=lstand1;
            emit arrive();
        }
        //lattack();//continue lattack
        //rattack();//continue rattack
    }
}
