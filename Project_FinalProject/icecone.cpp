#include "icecone.h"
static const char *dirset[]=
{
    ":/others/image/others/icecone/icecone_1.png",
    ":/others/image/others/icecone/icecone_2.png",
    ":/others/image/others/icecone/icecone_3.png",
    ":/others/image/others/icecone/icecone_4.png",
    ":/others/image/others/icecone/icecone_5.png",
    ":/others/image/others/icecone/icecone_6.png",
    ":/others/image/others/icecone/icecone_7.png",
    ":/others/image/others/icecone/icecone_8.png",
    ":/others/image/others/icecone/icecone_9.png",
    ":/others/image/others/icecone/icecone_10.png",

    ":/others/image/others/icecone/icecone_11.png",
    ":/others/image/others/icecone/icecone_12.png",
    ":/others/image/others/icecone/icecone_13.png",
    ":/others/image/others/icecone/icecone_14.png",
    ":/others/image/others/icecone/icecone_15.png",
    ":/others/image/others/icecone/icecone_16.png",
    ":/others/image/others/icecone/icecone_17.png",
    ":/others/image/others/icecone/icecone_18.png",
    ":/others/image/others/icecone/icecone_19.png",
    ":/others/image/others/icecone/icecone_20.png",

    ":/others/image/others/icecone/icecone_21.png",
    ":/others/image/others/icecone/icecone_22.png",
    ":/others/image/others/icecone/icecone_23.png",
    ":/others/image/others/icecone/icecone_24.png",
    ":/others/image/others/icecone/icecone_25.png",
    ":/others/image/others/icecone/icecone_26.png",
    ":/others/image/others/icecone/icecone_27.png",
    ":/others/image/others/icecone/icecone_28.png",
    ":/others/image/others/icecone/icecone_29.png",
    ":/others/image/others/icecone/icecone_30.png",

    ":/others/image/others/icecone/icecone_31.png",
    ":/others/image/others/icecone/icecone_32.png"
};
static const QPoint rlocation=QPoint(94,134);
static const int img_num=32;
static const int range=25;
static const int frozentime=50;

Icecone::Icecone(const QPoint &pos):
    Thrown_obj(pos,rlocation,pos,img_num,dirset,0,0),_range(range),idx(0),sleep_idx(0){}

void Icecone::draw(QPainter &p)
{
    drawImage(p,idx);
    if(idx==31)
    {
        deleteIt();
        return ;
    }
    if(idx==14)
    {
        if(sleep_idx<frozentime)
        {
            sleep_idx++;
            return;
        }
    }
    if(timeControl&&idx<31&&(!getPause()))
    idx++;
    timeControl=!timeControl;
}

void Icecone::process(Live_player &player)
{
    if(player.getType()==Type::princess||player.getType()==Type::guard)
        return ;
    if(player.HeartDistanceWith(*this)>_range)
        return;
    if(idx==3)
        player.reduceHP(50);//只加了这一句话
}
