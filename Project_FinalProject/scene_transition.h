#ifndef SCENE_TRANSITION_H
#define SCENE_TRANSITION_H

#include <QObject>
#include <QImage>
#include <QPainter>
#include "constant.h"

class Scene_transition:public QObject
{
    Q_OBJECT
signals:
    void change(void);
    void end(void);
private:
    enum class TransType{door,black,nothing};
    TransType transType;
    bool forward;
    const static int speed=20;
    const static int img_num=8;
    int pos;
    int img_pos;
    int sleep;
//pos只记录ldoor左上角位置，rdoor自己计算
    bool isTransing;
    QImage ldoor;
    QImage rdoor;
    QImage blackImg[img_num];
//前进还是后退
public:
    Scene_transition();
    void draw(QPainter &p);
    void beginTrans(Background nextCondition);
};

#endif // SCENE_TRANSITION_H
