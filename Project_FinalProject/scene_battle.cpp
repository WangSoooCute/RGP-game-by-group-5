#include "scene_battle.h"

static const char *back_dirset[]=
{
    ":/others/image/others/back1.png",
    ":/others/image/others/back2.png",
    ":/others/image/others/back3.png"
};
static const char *pause_dirset[]=
{
    ":/others/image/others/pause1.png",
    ":/others/image/others/pause2.png",
    ":/others/image/others/pause3.png"
};

static const char *bag_dirset[]=
{
    ":/others/image/others/bagnormal.png",
    ":/others/image/others/bagfloat.png",
    ":/others/image/others/bagpress.png"
};

Scene_battle::Scene_battle() :pauseTime(false),
    map1(":/background/image/map/1.png"),
    map2(":/background/image/map/2.png"),
    map3(":/background/image/map/3.png"),
    pause(QRect(QPoint(1100,0),QSize(31,27)),pause_dirset),
    back(QRect(QPoint(1150,0),QSize(31,27)),back_dirset),
    bag(QRect(QPoint(0,955),QSize(90,45)),bag_dirset)
{
    connect(&pause,SIGNAL(clicked()),this,SLOT(setPause()),Qt::UniqueConnection);
    connect(&back,SIGNAL(clicked()),this,SLOT(transfer()),Qt::UniqueConnection);
        //信号与信号连接 类似于接力赛 showBag接收到clicked信号后随即发送
    connect(&bag,SIGNAL(clicked()),this,SIGNAL(enableBag()),Qt::UniqueConnection);
}


void Scene_battle::draw(QPainter &p)
{
    switch (global_condition) {
    case Background::map1:
        p.drawImage(0,0,map1);
        break;
    case Background::map2:
        p.drawImage(0,0,map2);
        break;
    case Background::map3:
        p.drawImage(0,0,map3);
        break;
    default:
        break;
    }
    pause.draw(p);
    back.draw(p);
    bag.draw(p);
}

void Scene_battle::mouseMove(const QPoint &pos)
{
    if(pause.contains(pos))
    {
        pause.setFloat();
        return;
    }
    else if(back.contains(pos))
    {
        back.setFloat();
        return;
    }
    else if(bag.contains(pos))
    {
        bag.setFloat();
        return;
    }
    pause.setNormal();
    back.setNormal();
    bag.setNormal();
}

void Scene_battle::reset()
{
    pause.setNormal();
    back.setNormal();
    bag.setNormal();
    pauseTime=false;
}

bool Scene_battle::mousePress(const QPoint &pos)
{
    if(pause.contains(pos))
    {
        pause.setPressed();
        pauseTime=!pauseTime;
        return true;
    }
    else if(back.contains(pos))
    {
        back.setPressed();
        return true;
    }
    else if(bag.contains(pos))
    {
        bag.setPressed();
        return true;
    }
    else return false;
}
