#include "orangeball.h"

static const char *dirset[]=
{
    ":/others/image/others/orangeball.png"
};
static const QPoint rlocation=QPoint(48,48);
//94*94
static const int speed=30;
static const int stepmax=1000;
static const int img_num=1;

orangeball::orangeball(const QPoint & obj_location , const int direction):
    Thrown_obj(obj_location,rlocation,QPoint(0,0),img_num,dirset,speed,stepmax),
    _direction(Direction(up+direction)){}

void orangeball::draw(QPainter &p)
{
    drawImage(p,0);
    switch (_direction) {
    case Direction::up:
        moveUp();
        break;
    case Direction::down:
        moveDown();
        break;
    case Direction::left:
        moveLeft();
        break;
    case Direction::right:
        moveRight();
        break;
    default:
        break;
    }
    if(getStepmax()==0)
        deleteIt();
}

void orangeball::process(Live_player &player)
{
    if(!(player.getType()==Type::princess||player.getType()==Type::guard))
        return ;
    if(player.inHurtableRange(*this))
    {
        player.reduceHP(30);
        deleteIt();
    }
}
