#ifndef ENEMY_BOSS_A_H
#define ENEMY_BOSS_A_H

#include "constant.h"
#include "live_player.h"
#include <QPoint>

class Enemy_boss_a : public Live_player
{
    Q_OBJECT
signals:
    void missile(const QPoint &);
    void boss_b(const QPoint &);
    void death(void);
    void lose(void);
public:
    Enemy_boss_a(int route);
    void react(Command cmd);
    void draw(QPainter &p);
    bool isWalking(void)const;
    void process(Live_player &obj);
    Type getType()const {return Type::boss;}
    ~Enemy_boss_a(){}
private:
    enum Condition{a_lwalk1,a_lwalk2,a_lwalk3,a_lwalk4,a_lwalk5,a_lwalk6,a_lwalk7,a_lwalk8,a_lwalk9,a_lwalk10,a_lwalk11,a_lwalk12,
                   a_lattack1,a_lattack2,a_lattack3,a_lattack4,a_lattack5,a_lattack6,a_lattack7,a_lattack8,a_lattack9,a_lattack10,a_lattack11,a_lattack12,a_lattack13,a_lattack14,a_lattack15,a_lattack16,a_lattack17,a_lattack18,a_lattack19,a_lattack20,a_lattack21,a_lattack22,a_lattack23,a_lattack24,a_lattack25,a_lattack26,a_lattack27,a_lattack28,a_lattack29,a_lattack30,a_lattack31,a_lattack32,a_lattack33,a_lattack34,
                   a_rattack1,a_rattack2,a_rattack3,a_rattack4,a_rattack5,a_rattack6,a_rattack7,a_rattack8,a_rattack9,a_rattack10,a_rattack11,a_rattack12,a_rattack13,a_rattack14,a_rattack15,a_rattack16,a_rattack17,a_rattack18,a_rattack19,a_rattack20,a_rattack21,a_rattack22,a_rattack23,a_rattack24,a_rattack25,a_rattack26,a_rattack27,a_rattack28,a_rattack29,a_rattack30,a_rattack31,a_rattack32,a_rattack33,a_rattack34,
                   a_death1,a_death2,a_death3,a_death4,a_death5,a_death6,a_death7,a_death8,a_death9,a_death10,a_death11,a_death12};
    Condition _condition;
    int point_destination;
    int _sleep_boss_a;
    int bossbamount;
    int _route;
};

#endif // Enemy_BOSS_A_H
