#include "stable_obj.h"


Stable_obj::Stable_obj(const QPoint &obj_location, Pic picType):
    Abstract_obj(obj_location,1,&(info[picType].dir),info[picType].rlocation),
    _picType(picType),_range(info[picType].range){}


void Stable_obj::process(Live_player &player)
{
    if(_range<=ObjDistanceWith(player))  return;
    emit message(_picType);
    if(_picType!=magic_area)
        deleteIt();
}
void Stable_obj::draw(QPainter &p)
{
    Abstract_obj::drawImage(p,0);
}
