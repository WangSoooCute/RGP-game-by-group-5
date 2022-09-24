#include "arrow.h"

static const char *dirset[]=
    {":/others/image/others/arrow/0_arrow_up.png",
     ":/others/image/others/arrow/1_arrow_right_up.png",
     ":/others/image/others/arrow/2_arrow_right.png",
     ":/others/image/others/arrow/3_arrow_right_down.png",
     ":/others/image/others/arrow/4_arrow_down.png",
     ":/others/image/others/arrow/5_arrow_left_down.png",
     ":/others/image/others/arrow/6_arrow_left.png",
     ":/others/image/others/arrow/7_arrow_left_up.png"};
static const QPoint rlocation=QPoint(20,7);//?????
static const int img_num=8;
static const int speed=40;
static const int stepmax=10;//

Arrow::Arrow(const QPoint & obj_location, const QPoint &heart):
    Thrown_obj(obj_location,rlocation,heart,img_num,dirset,speed,stepmax)
{
    if(abs(obj_location.x()-heart.x())<=0.3*abs(obj_location.y()-heart.y()) && obj_location.y()>heart.y())
        idx=0;
        else if(obj_location.x()<heart.x() && abs(obj_location.y()-heart.y())<=0.3*abs(obj_location.x()-heart.x()))
        idx=2;
        else if(abs(obj_location.x()-heart.x())<=0.3*abs(obj_location.y()-heart.y()) && obj_location.y()<heart.y())
        idx=4;
        else if(obj_location.x()>heart.x() && abs(obj_location.y()-heart.y())<=0.3*abs(obj_location.x()-heart.x()))
        idx=6;

        else if(obj_location.x()<heart.x()&&obj_location.y()>heart.y())
        idx=1;
        else if(obj_location.x()<heart.x()&&obj_location.y()>heart.y())
        idx=3;
        else if(obj_location.x()>heart.x()&&obj_location.y()<heart.y())
        idx=5;
        else// if(obj_location.x()>heart.x()&&obj_location.y()>heart.y())
        idx=7;
}


void Arrow::draw(QPainter &p)
{
    drawImage(p,idx);
    if(getStepmax()==0)
    deleteIt();
    move();
}

void Arrow::process(Live_player &player)
{
    if(!(player.getType()==Type::boss||player.getType()==Type::enemy))
        return ;
    if(player.inHurtableRange(*this))
    {
        //类型是敌人且我的iceball已经进入了敌人的可受伤范围
        //回忆槽函数reduceHP亦可当作普通函数调用
        player.reduceHP(10);
        deleteIt();
    }
}
