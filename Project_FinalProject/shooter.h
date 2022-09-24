#ifndef SHOOTER_H
#define SHOOTER_H
#include "constant.h"
#include "live_player.h"


class Shooter : public Live_player
{
    Q_OBJECT
signals:
    void mymissile(const QPoint &);
    void arrive(void);
    void bullet(const QPoint &,const QPoint &);
//_________________________________
public:
    Shooter(int xpos, int ypos);
    Shooter(const QPoint & obj_location);

    void lattack();
    void rattack();
    void dying();

    bool timeornot();
    void draw(QPainter &p);
    void process(Live_player &obj);
    Type getType()const {return Type::guard;}
    ~Shooter(){}
private:
    enum Condition{
        lstand1,rstand1,
        lattack_1,lattack_2,lattack_3,lattack_4,lattack_5,lattack_6,lattack_7,lattack_8,lattack_9,lattack_10,lattack_11,
        rattack_1,rattack_2,rattack_3,rattack_4,rattack_5,rattack_6,rattack_7,rattack_8,rattack_9,rattack_10,rattack_11,
        dying_1,dying_2,dying_3,dying_4,dying_5,dying_6
        };
    Condition _condition;
    bool missileornot;
    int timing;
    QPoint rival_heart;
private slots:
    void deleteMe(void) {deleteIt();}
    void setMyDes(const QPoint& des){setDestination(des);}
};

#endif // SHOOTER_H
