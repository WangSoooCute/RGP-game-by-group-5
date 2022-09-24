#ifndef STABLE_OBJ_H
#define STABLE_OBJ_H

#include "live_player.h"
#include "abstract_obj.h"
#include "constant.h"

class Stable_obj:public Abstract_obj
{
    Q_OBJECT
signals:
    void message(Pic);
public slots:
    void deleteMe(void){deleteIt();}
private:
    Pic _picType;
    int _range;
public:
    Stable_obj(const QPoint &obj_location, Pic picType);
    void draw(QPainter &p);
    Pic getPictype()const {return _picType;}
    void process(Live_player &player);
};

#endif // STABLE_OBJ_H
