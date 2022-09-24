#ifndef ENEMY_WOODMONSTER_H
#define ENEMY_WOODMONSTER_H
#include "constant.h"
#include "live_player.h"
#include <QPoint>

class Enemy_woodmonster:public Live_player
{
    Q_OBJECT
signals:
    void shockwave(int amount);
    void death(void);
    void lose(void);
//_________________________________
public:
    Enemy_woodmonster(int route);

    void lfight();
    void rfight();
    void lattack();
    void rattack();
    void dying();
    void lwalk();
    void rwalk();

    bool isAttack(){return (_condition>=lattack_1&&_condition<=rattack_12);}
    bool isFight(){return (_condition>=lfight_1&&_condition<=rfight_11);}
    bool inFight_range(const Live_player &obj) const;//这里的const要留下来！！！


    void draw(QPainter &p);
    void process(Live_player &obj);//去掉了const
    Type getType()const {return Type::enemy;}
    ~Enemy_woodmonster(){}
private:
    enum Condition{
        lstand1,rstand1,
        lattack_1,lattack_2,lattack_3,lattack_4,lattack_5,lattack_6,lattack_7,lattack_8,
        lattack_9,lattack_10,lattack_11,lattack_12,
        rattack_1,rattack_2,rattack_3,rattack_4,rattack_5,rattack_6,rattack_7,rattack_8,
        rattack_9,rattack_10,rattack_11,rattack_12,
        dying_1,dying_2,dying_3,dying_4,dying_5,dying_6,dying_7,dying_8,dying_9,dying_10,
        dying_11,dying_12,dying_13,dying_14,dying_15,dying_16,dying_17,dying_18,
        lwalk_1,lwalk_2,lwalk_3,lwalk_4,lwalk_5,lwalk_6,lwalk_7,lwalk_8,
        rwalk_1,rwalk_2,rwalk_3,rwalk_4,rwalk_5,rwalk_6,rwalk_7,rwalk_8,
        lfight_1,lfight_2,lfight_3,lfight_4,lfight_5,lfight_6,lfight_7,lfight_8,
        lfight_9,lfight_10,lfight_11,
        rfight_1,rfight_2,rfight_3,rfight_4,rfight_5,rfight_6,rfight_7,rfight_8,
        rfight_9,rfight_10,rfight_11};
    Condition _condition;
    int _sleep;
    int _sleep_idx;
    int _route;
    int point_destination;
    int _fight_range;
};

#endif // ENEMY_WOODMONSTER_H
