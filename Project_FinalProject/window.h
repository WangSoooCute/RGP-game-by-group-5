#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QSettings>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QImage>
#include <forward_list>
#include "constant.h"
#include "scene_startup.h"
#include "scene_home.h"
#include "princess.h"
#include "iceball.h"
#include "missile.h"
#include "scene_transition.h"
#include "stable_obj.h"
#include "scene_battle.h"
#include "scene_bag.h"
#include "enemy_cavalry_wolf.h"
#include "enemy_firecow.h"
#include "enemy_firewizard.h"
#include "enemy_pigsoldier.h"
#include "enemy_greenmonster.h"
#include "greenstone.h"
#include "fireball.h"
#include "fireball2.h"
#include "fireball3.h"
#include "orangeball.h"

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event){update();}

    bool timing(void);
    void changetime(void);
    void newplayer();//时间判断函数，投放怪物

private:
    Ui::Window *ui;
    void loadImage(void);//装载所有对话框所使用函数
    void loadSettings();//游戏开始时载入存档
    void saveSettings();//保存当前存档点 在每一更改story的时候都要调用一下
    void processPlayer(QPainter &p);

    void paintStartup(QPainter &p);
    void paintHome(QPainter &p);
    void paintBattle(QPainter &p);//三幅战斗场景对应的画图函数。用于减轻paintevent的负担

//输了以后从上一关开始。（第一关从home，
    void restart();
    void reset();//重置各种window.cpp变量，用于change函数离开一个场景时
    void setPauseAll(bool pause);//对应player obj set暂停状态

    void deleteAll(void);//清空所有的援军 怪物 技能，即player,pic,obj里的所有东西

    void clearPlayer(void);//删除为deletable的player
    Pic producePic();//随机产生掉落物品的函数
    QPoint mousepos;//鼠标当前位置
    QSettings settings;
    Background condition;//描述当前是在哪一幅场景里面
    Background nextCondition;//描述下一幅场景是什么

    Story story;//描述即将到来的是哪副剧情了,一般用于restart
    Dialog dialogStatus;//描述及讲道理的是哪张对话图片了
    TalentType talent;//描述使用的技能

    bool passornot;//是否通过这一关，判断victory要不要画出来
    bool loseornot;//是否输掉，判断failure要不要画出来，是否调用restart函数重新开始
    bool talentTime;//true表示属于使用技能的时间 此时mousepressevent只处理使用技能

    bool controlPrincess;//无法控制冰女，包括鼠标左键和A，S

    bool dialogTime;//此时除了点击鼠标继续 所有操作都会失效。背景敌人、技能也都暂停了

    bool bagTime;//true时显示bag
    int deathamount;//记录击杀怪物数量
    
    bool cycleornot;//第三幅地图专用，开启循环
    int cycleamount;

    int timing1,timing2;//定时投放需要的变量
    Playerput _playerput;//定时投放什么东西的判断

    Princess princess;
    std::forward_list<Live_player*> player;
    std::forward_list<Thrown_obj*> obj;
    std::forward_list<Stable_obj*> pic;//pic用于装各种静态图片  如门、掉落技能

    Scene_startup startup;
    Scene_home home;
    Scene_transition transition;
    Scene_battle battle;//三个战斗场景
    Scene_bag bag;
private slots:    
    void emit_iceball(const QPoint &);
    void emit_missile(const QPoint &);
    void emit_arrow(const QPoint&,const QPoint&);//以上都是信号发射函数，标记公主，boss和援军的攻击方式
    void emit_fireball(const QPoint & location,const QPoint &rival_heart);
    void emit_fireball2(const QPoint & location,const QPoint &rival_heart);
    void emit_fireball3(const QPoint & location,const QPoint &rival_heart);
    void emit_orangeball(const QPoint & location, const int _direction);
    void emit_greenstone(const QPoint &location, const QPoint &rival_heart);
    void emit_mymissile(const QPoint &location);
    void emit_bullet(const QPoint & location,const QPoint &rival_heart);
    void create_boss_b(const QPoint &);

    void archerArrive(void);//当archer到达设定的destination时会发送信号，这个是对应的槽函数（剧情需要）

    void deathincrease(void){deathamount++;}//标记死亡数量，用于判断victory

    void lose(void);//用于判断failure

    void pauseSlot(bool isPausing){setPauseAll(isPausing);controlPrincess=!controlPrincess;}//对应pause按钮的状态

    void back(void){transfer(Background::startup);}//对应back按钮的状态

    void transfer(Background type);//准备切换场景，转换到下一幅场景

    void change(void);//调用该函数表明门关好了 切换场景
    void end(void);//调用该函数表示打开完全了————————————门的判断函数

    void receiveMsg(Pic);//掉落物品、magic_area等被冰女按s键时会发送message(void)信号

    void enableBag(void){bagTime=true;}//槽函数 与Scene_battle中信号函数相连 打开背包
    void disableBag(void){bagTime=false;}//槽函数，与scene_bag中信号函数相连 关闭背包
signals:
    void deleteArcher(void);
    void setArcherDes(const QPoint &des);//剧情需要 有时要删除archer 有时要让archer走到一个地方

    void deleteMagicArea(void);//剧情需要 把princess传过来 magic_area就应该消失了
};

#endif // WINDOW_H
