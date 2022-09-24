#include "scene_startup.h"
#include <QDebug>
//应该每一个button都要有一个对应的dirset
//注意图片放入的顺序
//在默认构造函数完成每一个button和背景图片的初始化
//以及你需要建立的信号与槽之间的连接
static const char *dirset[]=
{
    ":/others/image/others/start1.png",
    ":/others/image/others/start2.png",
    ":/others/image/others/start3.png"
};

/*static const char *gamedirset[]=
{
    ":/others/image/others/newGame1.png",
    ":/others/image/others/newGame2.png"
    ":/others/image/others/newGame1.png"
};*/

Scene_startup::Scene_startup():/*newGame(QRect(QPoint(500,770),QSize(199,96)),gamedirset),*/
    start(QRect(QPoint(500,670),QSize(199,96)),dirset),
    _background(QImage(":/background/image/map/start.png")),
    logo(QImage(":/others/image/others/logo.png"))
{
    connect(&start,SIGNAL(clicked()),this,SLOT(transfer()),Qt::UniqueConnection);
    //connect(&newGame,SIGNAL(clicked()),this,SLOT(newtransfer()),Qt::UniqueConnection);
}

void Scene_startup::reset()
{
    start.setNormal();
    //newGame.setNormal();
}

void Scene_startup::mouseMove(const QPoint &pos)
{
    if(start.contains(pos))
        start.setFloat();
    else start.setNormal();
    //if(newGame.contains(pos))
    //    newGame.setFloat();
    //else newGame.setNormal();
}

bool Scene_startup::mousePress(const QPoint &pos)
{
    if(start.contains(pos))
    {
        start.setPressed();
        return true;
    }
    /*else if(newGame.contains(pos))
    {
        newGame.setPressed();
        return true;
    }*/
    else return false;

}

void Scene_startup::draw(QPainter &p)
{
    p.drawImage(0,0,_background);
    p.drawImage(114,-40,logo);
    start.draw(p);
    //newGame.draw(p);
}
