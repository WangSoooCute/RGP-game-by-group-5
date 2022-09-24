#ifndef SCENE_STARTUP_H
#define SCENE_STARTUP_H

#include "constant.h"
#include "button.h"
#include <QObject>
//每一个场景都需要从qobject继承 来使用信号与槽机制
class Scene_startup:public QObject
{
    Q_OBJECT
private slots:
    void transfer(void){emit toHome(Background::home);}
    //void newtransfer(void){emit clearSettings();emit toHome(Background::home);}
signals:
//写自己需要的信号或槽函数
//这里的toHome函数和start这个button的信号clicked相连接
//完成从开始界面到家界面的切换
    void toHome(Background);
    //void clearSettings(void);
public:
//场景共有的东西：
//默认构造函数，mouseMove和mousePress对鼠标事件的处理函数
//draw画画函数,复制画背景和背景中嵌入的按钮
    Scene_startup();
    void mouseMove(const QPoint &pos);
    bool mousePress(const QPoint &pos);
    void reset(void);
    void draw(QPainter &p);
private:
//装了你需要嵌入的button和场景图片_background
    Button start;
    //Button newGame;
    QImage _background;
    QImage logo;
};

#endif // SCENE_STARTUP_H
