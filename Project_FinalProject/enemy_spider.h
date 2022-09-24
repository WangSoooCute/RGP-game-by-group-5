#ifndef ENEMY_SPIDER_H
#define ENEMY_SPIDER_H
#include "constant.h"
#include "Live_player.h"
#include <QPoint>
#include <iostream>

class Enemy_spider:public Live_player
{
    Q_OBJECT
signals:
    void death(void);
    void lose(void);
public:
    Enemy_spider(int route);

    void dying();
    void lwalk();
    void rwalk();
    void lfight();
    void rfight();

    bool isFight(){return (_condition>=lfight_1&&_condition<=rfight_16);}
    bool inFight_range(const Live_player &obj) const;//这里的const要留下来！！！

    void draw(QPainter &p);
    void process(Live_player &obj);//去掉了const
    Type getType()const {return Type::enemy;}
    ~Enemy_spider(){}
private:
    enum Condition{
        lstand1,rstand1,
        dying_1,dying_2,dying_3,dying_4,dying_5,dying_6,dying_7,dying_8,
        dying_9,dying_10,dying_11,dying_12,dying_13,dying_14,dying_15,dying_16,
        dying_17,dying_18,dying_19,dying_20,dying_21,dying_22,dying_23,dying_24,
        dying_25,dying_26,dying_27,dying_28,
        lwalk_1,lwalk_2,lwalk_3,lwalk_4,lwalk_5,lwalk_6,lwalk_7,lwalk_8,
        lwalk_9,lwalk_10,lwalk_11,lwalk_12,lwalk_13,lwalk_14,lwalk_15,lwalk_16,
        lwalk_17,lwalk_18,lwalk_19,lwalk_20,
        rwalk_1,rwalk_2,rwalk_3,rwalk_4,rwalk_5,rwalk_6,rwalk_7,rwalk_8,
        rwalk_9,rwalk_10,rwalk_11,rwalk_12,rwalk_13,rwalk_14,rwalk_15,rwalk_16,
        rwalk_17,rwalk_18,rwalk_19,rwalk_20,
        lfight_1,lfight_2,lfight_3,lfight_4,lfight_5,lfight_6,lfight_7,lfight_8,
        lfight_9,lfight_10,lfight_11,lfight_12,lfight_13,lfight_14,lfight_15,lfight_16,
        rfight_1,rfight_2,rfight_3,rfight_4,rfight_5,rfight_6,rfight_7,rfight_8,
        rfight_9,rfight_10,rfight_11,rfight_12,rfight_13,rfight_14,rfight_15,rfight_16};
    Condition _condition;
    int _sleep;
    int _sleep_idx;
    int _route;
    int point_destination;
};

#endif // ENEMY_SPIDER_H
