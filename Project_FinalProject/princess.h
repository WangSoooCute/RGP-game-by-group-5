#ifndef PRINCESS_H
#define PRINCESS_H
#include "constant.h"
#include "live_player.h"
#include <QPoint>


class Princess : public Live_player
{
    Q_OBJECT
signals:
    void iceball(const QPoint &);
    void princessDeath(void);
public:
    Princess(const QPoint & obj_location=home_magic_area);
    void turnFace(const QPoint &pos);
    void react(Command cmd);
    void draw(QPainter &p);
    void flashMove(const QPoint &des);
    void reset(void);
    void addHP(int amount){setHP(getHP()+amount);}
    bool isLeft(void)const;
    bool isStanding(void)const {return _condition<l_longattack1;}
    bool isRight(void)const {return !isLeft();}
    void process(Live_player &obj){}
    void setObj_location(const QPoint &obj_location);
    int getMP() const {return MP;}
    Type getType()const {return Type::princess;}
private:
    enum Condition{lstand1,rstand1,l_longattack1,l_longattack2,
        l_longattack3,l_longattack4,r_longattack1,r_longattack2,
        r_longattack3,r_longattack4,lmove1,rmove1,
        death1,death2,death3,death4,death5,death6,
        disappear1,disappear2,disappear3,disappear4,disappear5,
        appear1,appear2,appear3,appear4,appear5};
    Condition _condition;
    QPoint nextDes;
    QImage profile;
    const double k_HP;
    const double k_MP;
    int MP;
    bool deathSignal;
private slots:
    void setMP(int newMP){MP=newMP;}
};

#endif // PRINCESS_H
