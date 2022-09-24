#ifndef THROWN_OBJ_H
#define THROWN_OBJ_H

#include "abstract_obj.h"
#include "live_player.h"

//注意：必须要保证传入的obj_location和heart坐标不同
class Live_player;
class Thrown_obj : public Abstract_obj
{
private:
    int _dx;
    int _dy;
    int _speed;
    int _stepmax;// number of steps allowed
    int last_index;
    bool _pause;
public:
    Thrown_obj(const QPoint & obj_location, const QPoint & rlocation, const QPoint & destination,
               const int img_num, const char **dir_set, const int speed, const int stepmax);
    int getStepmax(void)const {return _stepmax;}
    int getSpeed(void)const {return _speed;}
    bool getPause(void) const {return _pause;}
    virtual void process(Live_player & player)=0;
    virtual void draw(QPainter &p)=0;
    virtual ~Thrown_obj(){}
public slots:
    void setPause(bool pause) {_pause=pause;}
protected:
    void move(void);
    void moveUp(void);
    void moveDown(void);
    void moveLeft(void);
    void moveRight(void);
    void setDestination(const QPoint &destination);
    void setSpeed(int speed){_speed=speed;}
    void setStepmax(int stepmax){_stepmax=stepmax;}
    virtual void drawImage(QPainter &p, int index);
    void deleteIt(){if(_pause) return; else Abstract_obj::deleteIt();}
};


/*class pThrown_obj
{
private:
    Thrown_obj * _p;
public:
    pThrown_obj(Thrown_obj * p):_p(p){}
    pThrown_obj(const pThrown_obj & obj):_p(new Thrown_obj(*obj.use())){}
    const pThrown_obj & operator =(const pThrown_obj & obj)
    {
        _p=new Thrown_obj(*obj.use());
        return *this;
    }
    Thrown_obj * use(void)const {return _p;}
    ~pThrown_obj(){delete _p;}
}*/

#endif // THROWN_OBJ_H
