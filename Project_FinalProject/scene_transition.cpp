#include "scene_transition.h"


static const char*dirset[]={
    ":/background/image/map/black1.png",
    ":/background/image/map/black2.png",
    ":/background/image/map/black3.png",
    ":/background/image/map/black4.png",
    ":/background/image/map/black5.png",
    ":/background/image/map/black6.png",
    ":/background/image/map/black7.png",
    ":/background/image/map/black8.png"
};


Scene_transition::Scene_transition():transType(TransType::nothing),
    pos(-700),img_pos(0),forward(true),isTransing(false),sleep(0),
    ldoor(QImage(":/background/image/map/ldoor.png")),
    rdoor(QImage(":/background/image/map/rdoor.png"))
{
    for(int i=0;i<img_num;i++)
    {
        blackImg[i].load(dirset[i]);
    }
}


void Scene_transition::beginTrans(Background nextCondition)
{
    if(global_condition==Background::home||nextCondition==Background::home||nextCondition==Background::startup)
        transType=TransType::door;
    else transType=TransType::black;
    isTransing=true;
}

void Scene_transition::draw(QPainter &p)
{
    if(!isTransing) return;
    if(transType==TransType::door)
    {
        p.drawImage(QPoint(pos,0),ldoor);
        p.drawImage(QPoint(500-pos,0),rdoor);
        if(pos==-95)
        {
            sleep=(sleep+1)%20;
            if(sleep) return;
            emit change();
            forward=false;
        }
        if(forward)
        {
            if(-100-pos>speed) pos+=speed;
            else pos=-95;
        }
        else if(pos==-700)
        {
            forward=true;
            emit end();
            isTransing=false;
            transType=TransType::nothing;
        }
        else
        {
            if(pos+700>speed) pos-=speed;
            else pos=-700;
        }
    }

    else if(transType==TransType::black)
    {
        p.drawImage(0,0,blackImg[img_pos]);
        sleep=(sleep+1)%3;
        if(sleep) return;
        if(img_pos==(img_num-1))
        {
            emit change();
            forward=false;
        }
        if(forward)
        {
            img_pos++;
        }
        else if(img_pos==0)
        {
            forward=true;
            emit end();
            isTransing=false;
            transType=TransType::nothing;
            sleep=0;
        }
        else
        {
            img_pos--;
        }
    }

}




