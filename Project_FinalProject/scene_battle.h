#ifndef SCENE_BATTLE_H
#define SCENE_BATTLE_H

#include <QObject>
#include <QPoint>
#include <QPainter>
#include <QImage>
#include "button.h"
#include "constant.h"

class Scene_battle : public QObject
{
    Q_OBJECT
public:
    Scene_battle();
    void mouseMove(const QPoint &pos);
    bool mousePress(const QPoint &pos);
    bool getPauseTime(void)const {return pauseTime;}
//参数pos代表鼠标位置
//同理于scene_startup mouseMove至少要判断鼠标在不在
//某一个按钮上面 在的话得换图片
//mousePress判断鼠标点的地方是不是按钮区域 并触发按钮效果
//我的背包系统也要写在这里面，所以我们共同开发
    void draw(QPainter &p);
    void reset();
private:
    bool pauseTime;
//背景照片
    QImage map1;
    QImage map2;
    QImage map3;
//在private section里写上你的需要在第一幅战斗场景嵌入的button
    Button pause;
    Button back;
    Button bag;
signals:
    void pauseSignal(bool);//true表示暂停  false表示启动
    void toStartUp(Background);
    void enableBag(void);
private slots:
    void setPause(void){emit pauseSignal(pauseTime);}
    void transfer(void) {emit toStartUp(Background::startup);}
 };

#endif // SCENE_BATTLE_H
