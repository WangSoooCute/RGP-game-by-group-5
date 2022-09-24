#include "shooter.h"
#include "live_player.h"
using namespace std;

static const char *dir_set[]=
    {":/guard/shooter/image/shooter/l_stand.png",
     ":/guard/shooter/image/shooter/r_stand.png",

     ":/guard/shooter/image/shooter/l_attack (1).png",
     ":/guard/shooter/image/shooter/l_attack (2).png",
     ":/guard/shooter/image/shooter/l_attack (3).png",
     ":/guard/shooter/image/shooter/l_attack (4).png",
     ":/guard/shooter/image/shooter/l_attack (5).png",
     ":/guard/shooter/image/shooter/l_attack (6).png",
     ":/guard/shooter/image/shooter/l_attack (7).png",
     ":/guard/shooter/image/shooter/l_attack (8).png",
     ":/guard/shooter/image/shooter/l_attack (9).png",
     ":/guard/shooter/image/shooter/l_attack (10).png",
     ":/guard/shooter/image/shooter/l_attack (11).png",

     ":/guard/shooter/image/shooter/r_attack (1).png",
     ":/guard/shooter/image/shooter/r_attack (2).png",
     ":/guard/shooter/image/shooter/r_attack (3).png",
     ":/guard/shooter/image/shooter/r_attack (4).png",
     ":/guard/shooter/image/shooter/r_attack (5).png",
     ":/guard/shooter/image/shooter/r_attack (6).png",
     ":/guard/shooter/image/shooter/r_attack (7).png",
     ":/guard/shooter/image/shooter/r_attack (8).png",
     ":/guard/shooter/image/shooter/r_attack (9).png",
     ":/guard/shooter/image/shooter/r_attack (10).png",
     ":/guard/shooter/image/shooter/r_attack (11).png",


     ":/guard/shooter/image/shooter/death (1).png",
     ":/guard/shooter/image/shooter/death (2).png",
     ":/guard/shooter/image/shooter/death (3).png",
     ":/guard/shooter/image/shooter/death (4).png",
     ":/guard/shooter/image/shooter/death (5).png",
     ":/guard/shooter/image/shooter/death (6).png",


     };
static const QPoint rlocation=QPoint(72,63);//-(32,30)=(16,56)
static const QPoint rheart=QPoint(72,44);
static const QPoint l_myattack=QPoint(-11,-38);//(30,76)
static const QPoint r_myattack=QPoint(14,-30);//(109,76)
static const int hurtable_range=30;
static const int attack_range=200;
static const int MAXHP=400;
static const int img_num=30;
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
Shooter::Shooter(int xpos, int ypos):
    Live_player(QPoint(xpos,ypos),rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,QPoint(xpos,ypos)),
    _condition(rstand1),timing(0),missileornot(false){}

Shooter::Shooter(const QPoint & obj_location):
    Live_player(obj_location,rlocation,rheart,img_num,dir_set,hurtable_range,
                attack_range,MAXHP,speed,obj_location),//des赋值的问题:player.front()->setDestination
    _condition(rstand1),timing(0),missileornot(false),rival_heart(QPoint(0,0)){}


bool Shooter::timeornot()
{
    if(timing%100==0)
    {
        timing=0;
        return true;
    }
    else
        return false;
}

void Shooter::process(Live_player &obj)
{
    if(_condition>=lattack_1&&_condition<=rattack_11)
        return;
    if(obj.getType()==Type::boss&&timeornot()==true)
    {
        missileornot=true;
        if(obj.getObj_locationX()<getObj_locationX())
            _condition=lattack_1;
        else
            _condition=rattack_1;
        return;
    }
    if(obj.getType()==Type::enemy)
    {
        if(inAttack_range(obj))
        {
            rival_heart=obj.getHeart();//!!!!!!!!!!!!!!!!!!!!!!!!!!
            missileornot=false;
            if(_condition==lstand1||_condition==rstand1)
            {
                    if(obj.getObj_locationX()<getObj_locationX())
                        _condition=lattack_1;
                    else
                        _condition=rattack_1;
            }
        }
    }
}

void Shooter::lattack()
{
    if(_condition==lattack_6)
    {
        if(missileornot==true)
            emit mymissile(getObj_location()+l_myattack);
        else
            emit bullet(getObj_location()+l_myattack,rival_heart);
    }
    if(_condition>=lattack_1&&_condition<lattack_8)
        _condition=Condition(1+_condition);
    else if(_condition==lattack_8)
        _condition=lstand1;
}

void Shooter::rattack()
{
    if(_condition==rattack_5)
    {
        if(missileornot==true)
            emit mymissile(getObj_location()+r_myattack);
        else
            emit bullet(getObj_location()+r_myattack,rival_heart);
    }
    if(_condition>=rattack_1&&_condition<rattack_8)
        _condition=Condition(1+_condition);
    else if(_condition==rattack_8)
        _condition=rstand1;
}

void Shooter::dying()
{
    if(_condition==dying_6)
    {
        deleteIt();
    }
    else if(_condition<dying_1)
        _condition=dying_1;
    else
    {
        _condition=Condition(1+_condition);
    }
}


void Shooter::draw(QPainter &p)
{
    drawImage(p,_condition);
    timing++;
    if(getHP()==0)
    {
        dying();
        return ;
    }
    if(_condition>=lattack_1&&_condition<=lattack_8)
        lattack();
    else if(_condition>=rattack_1&&_condition<=rattack_8)
        rattack();
}

