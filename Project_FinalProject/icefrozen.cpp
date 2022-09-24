#include "icefrozen.h"
static const char *dirset[]=
{
    ":/others/image/others/icefrozen/icefrozen_1.png",
    ":/others/image/others/icefrozen/icefrozen_2.png",
    ":/others/image/others/icefrozen/icefrozen_3.png",
    ":/others/image/others/icefrozen/icefrozen_4.png",
    ":/others/image/others/icefrozen/icefrozen_5.png",
    ":/others/image/others/icefrozen/icefrozen_6.png",
    ":/others/image/others/icefrozen/icefrozen_7.png",
    ":/others/image/others/icefrozen/icefrozen_8.png",
    ":/others/image/others/icefrozen/icefrozen_9.png",
    ":/others/image/others/icefrozen/icefrozen_10.png",

    ":/others/image/others/icefrozen/icefrozen_11.png",
    ":/others/image/others/icefrozen/icefrozen_12.png",
    ":/others/image/others/icefrozen/icefrozen_13.png",
    ":/others/image/others/icefrozen/icefrozen_14.png",
    ":/others/image/others/icefrozen/icefrozen_15.png",
    ":/others/image/others/icefrozen/icefrozen_16.png",
    ":/others/image/others/icefrozen/icefrozen_17.png",
    ":/others/image/others/icefrozen/icefrozen_18.png",
    ":/others/image/others/icefrozen/icefrozen_19.png",
    ":/others/image/others/icefrozen/icefrozen_20.png",

    ":/others/image/others/icefrozen/icefrozen_21.png",
    ":/others/image/others/icefrozen/icefrozen_22.png",
    ":/others/image/others/icefrozen/icefrozen_23.png",
    ":/others/image/others/icefrozen/icefrozen_24.png",
    ":/others/image/others/icefrozen/icefrozen_25.png",
    ":/others/image/others/icefrozen/icefrozen_26.png"
};
static const QPoint rlocation=QPoint(50,97);
static const int img_num=26;
static const int range=40;
static const int frozentime=200;

Icefrozen::Icefrozen(const QPoint &pos):
    Thrown_obj(pos,rlocation,pos,img_num,dirset,0,0),_range(range),idx(0),sleep_idx(0){}


void Icefrozen::draw(QPainter &p)
{
    drawImage(p,idx);
    if(idx==25)
    {
        deleteIt();
        return ;
    }
    if(idx==9)
    {
        if(sleep_idx<frozentime)
        {
            sleep_idx++;
            return;
        }
        else if(sleep_idx==frozentime)
        {
            sleep_idx=0;
        }
    }
    if(idx!=25&&(!getPause()))
    idx++;
}

void Icefrozen::process(Live_player &player)
{
    if(!(player.getType()==Type::enemy||player.getType()==Type::boss))return ;
    if(player.HeartDistanceWith(*this)>_range)return;
    if(idx==8)
    {
        player.setFrozen(true);
    }
    else if(idx==10)
    {
        player.setFrozen(false);
    }
}
