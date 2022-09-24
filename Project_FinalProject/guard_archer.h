#ifndef GUARD_ARCHER_H
#define GUARD_ARCHER_H
#include "constant.h"
#include "live_player.h"
#include "arrow.h"
#include <QPoint>

class Guard_archer:public Live_player
{
    Q_OBJECT
signals:
    void arrow(const QPoint &,const QPoint &);
    void arrive(void);
//_________________________________
public:
    Guard_archer(int xpos, int ypos);
    Guard_archer(const QPoint & obj_location);

    void lattack();
    void rattack();
    void dying();
    void lwalk();
    void rwalk();

    void draw(QPainter &p);
    void process(Live_player &obj);
    Type getType()const {return Type::guard;}
    /*
    QPoint get_rival_heart()const{return _rival_heart;}//!!!!!!!!!!!!!!!!!!!!!!
    QPoint set_rival_heart(QPoint rival_heart){_rival_heart=rival_heart;}
    */
    ~Guard_archer(){}
private:
    enum Condition{
        lstand1,rstand1,
        lattack_1,lattack_2,lattack_3,lattack_4,lattack_5,lattack_6,lattack_7,lattack_8,
        rattack_1,rattack_2,rattack_3,rattack_4,rattack_5,rattack_6,rattack_7,rattack_8,
        dying_1,dying_2,dying_3,dying_4,dying_5,dying_6,dying_7,dying_8,
        dying_9,dying_10,dying_11,dying_12,dying_13,dying_14,dying_15,dying_16,
        lwalk_1,lwalk_2,lwalk_3,lwalk_4,lwalk_5,lwalk_6,
        rwalk_1,rwalk_2,rwalk_3,rwalk_4,rwalk_5,rwalk_6};
    Condition _condition;
    QPoint _rival_heart;
private slots:
    void deleteMe(void) {deleteIt();}
    void setMyDes(const QPoint& des){setDestination(des);}
};

#endif // GUARD_ARCHER_H
