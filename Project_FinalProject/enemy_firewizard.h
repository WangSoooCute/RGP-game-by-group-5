#ifndef ENEMY_FIREWIZARD_H
#define ENEMY_FIREWIZARD_H
#include "constant.h"
#include "live_player.h"
#include "fireball.h"
#include <QPoint>
#include <iostream>
class Enemy_firewizard:public Live_player
{
    Q_OBJECT
signals:
    void fireball(const QPoint &,const QPoint &);
    void death(void);
    void lose(void);
//_________________________________
public:
    Enemy_firewizard(int route);

    void lattack();
    void rattack();
    void dying();
    void lwalk();
    void rwalk();

    bool isAttack(){return (_condition>=lattack_1&&_condition<=rattack_8);}

    void draw(QPainter &p);
    void process(Live_player &obj);//去掉了const
    Type getType()const {return Type::enemy;}
    ~Enemy_firewizard(){}
private:
    enum Condition{
        lstand1,rstand1,
        lattack_1,lattack_2,lattack_3,lattack_4,lattack_5,lattack_6,lattack_7,lattack_8,
        rattack_1,rattack_2,rattack_3,rattack_4,rattack_5,rattack_6,rattack_7,rattack_8,
        dying_1,dying_2,dying_3,dying_4,dying_5,dying_6,dying_7,dying_8,
        dying_9,dying_10,dying_11,dying_12,dying_13,dying_14,dying_15,dying_16,
        lwalk_1,lwalk_2,lwalk_3,lwalk_4,lwalk_5,lwalk_6,lwalk_7,lwalk_8,
        rwalk_1,rwalk_2,rwalk_3,rwalk_4,rwalk_5,rwalk_6,rwalk_7,rwalk_8};
    Condition _condition;
    int _route;
    QPoint _current_obj;//
    int point_destination;
    int idx;
};

#endif // Enemy_firewizard_H
