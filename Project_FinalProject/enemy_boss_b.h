#ifndef ENEMY_BOSS_B_H
#define ENEMY_BOSS_B_H

#include "constant.h"
#include "live_player.h"
#include <QPoint>

class Enemy_boss_b : public Live_player
{
    Q_OBJECT
signals:
    void death(void);
    void Orangeball(const QPoint &,const int);

//public slots:
  //  void _changepoint(QPoint &);
public:
    Enemy_boss_b(const QPoint & beginposition);
    void react(Command cmd);
    void draw(QPainter &p);
    bool hurtedBy(Thrown_obj &obj);
    bool attackornot(void);
    bool moveornot(void);
    void process( Live_player & obj);
    Type getType()const {return Type::boss;}
    //void setObj_location(const QPoint &obj_location);
    ~Enemy_boss_b(){}
private:
    enum Condition{
                   l_stand,r_stand,
                   appear1,appear2,appear3,appear4,appear5,
                   disappear1,disappear2,disappear3,disappear4,disappear5,
                   b_lattack1,b_lattack2,b_lattack3,b_lattack4,b_lattack5,b_lattack6,b_lattack7,b_lattack8,b_lattack9,b_lattack10,b_lattack11,b_lattack12,b_lattack13,b_lattack14,
                   b_rattack1,b_rattack2,b_rattack3,b_rattack4,b_rattack5,b_rattack6,b_rattack7,b_rattack8,b_rattack9,b_rattack10,b_rattack11,b_rattack12,b_rattack13,b_rattack14,
                   death1,death2,death3,death4,death5,death6,death7,death8,death9,death10
                  };
    Condition _condition;
    QPoint startpoint;
    int point_destination;
    int _sleep_boss_b;
    int timing;//计时投放技能
};

#endif // Enemy_BOSS_B_H
