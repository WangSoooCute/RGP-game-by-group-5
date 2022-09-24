#ifndef ENEMY_FIRECOW_H
#define ENEMY_FIRECOW_H
#include "constant.h"
#include "live_player.h"
#include "fireball2.h"
#include <QPoint>
#include <iostream>
class Enemy_firecow:public Live_player
{
    Q_OBJECT
signals:
    void fireball2(const QPoint &,const QPoint &);
    void death(void);
    void lose(void);
//_________________________________
public:
    Enemy_firecow(int route);

    void lattack();
    void rattack();
    void dying();
    void lwalk();
    void rwalk();

    bool isAttack(){return (_condition>=lattack_1&&_condition<=rattack_8);}

    void draw(QPainter &p);
    void process(Live_player &obj);//去掉了const
    Type getType()const {return Type::enemy;}
    ~Enemy_firecow(){}
private:
    enum Condition{
        lstand1,rstand1,
        lattack_1,lattack_2,lattack_3,lattack_4,lattack_5,lattack_6,lattack_7,lattack_8,
        rattack_1,rattack_2,rattack_3,rattack_4,rattack_5,rattack_6,rattack_7,rattack_8,
        dying_1,dying_2,dying_3,dying_4,dying_5,dying_6,dying_7,dying_8,
        dying_9,dying_10,dying_11,dying_12,dying_13,dying_14,dying_15,dying_16,
        lwalk_1,lwalk_2,lwalk_3,lwalk_4,lwalk_5,lwalk_6,lwalk_7,lwalk_8,
        lwalk_9,lwalk_10,lwalk_11,lwalk_12,lwalk_13,lwalk_14,lwalk_15,lwalk_16,
        rwalk_1,rwalk_2,rwalk_3,rwalk_4,rwalk_5,rwalk_6,rwalk_7,rwalk_8,
        rwalk_9,rwalk_10,rwalk_11,rwalk_12,rwalk_13,rwalk_14,rwalk_15,rwalk_16};
    Condition _condition;
    int _route;//只是为了统一格式而写的，没有什么实际意义
    QPoint _current_obj;//
    int point_destination;
    int idx;
};

#endif // Enemy_firecow_H
