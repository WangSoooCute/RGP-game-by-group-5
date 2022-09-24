#include "lightning.h"
static const char *dirset[]=
{
    ":/others/image/others/lightning/lightning_1.png",
    ":/others/image/others/lightning/lightning_2.png",
    ":/others/image/others/lightning/lightning_3.png",
    ":/others/image/others/lightning/lightning_4.png",
    ":/others/image/others/lightning/lightning_5.png",
    ":/others/image/others/lightning/lightning_6.png",
    ":/others/image/others/lightning/lightning_7.png",
    ":/others/image/others/lightning/lightning_8.png",
    ":/others/image/others/lightning/lightning_9.png",
    ":/others/image/others/lightning/lightning_10.png"
};
static const QPoint rlocation=QPoint(70,1057);
static const int img_num=10;
static const int range=40;

Lightning::Lightning(const QPoint &pos):
    Thrown_obj(pos,rlocation,pos,img_num,dirset,0,0),idx(0),_range(range){}

void Lightning::draw(QPainter &p)
{
    drawImage(p,idx);
    if(idx==9)
    {
        deleteIt();
        return ;
    }
    else if(!getPause())
        idx++;
}
void Lightning::process(Live_player &player)
{
    if(player.getType()==Type::princess||player.getType()==Type::guard)
        return ;
    if(player.ObjDistanceWith(*this)<=_range && idx==6)
        player.reduceHP(200);
}
