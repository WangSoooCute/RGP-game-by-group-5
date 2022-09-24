#include "window.h"
#include "ui_window.h"
#include <QPainter>
#include <ctime>
#include <cstdlib>
#include "iceball.h"
#include "missile.h"
#include "arrow.h"
#include "guard_archer.h"
#include "enemy_boss_a.h"
#include "enemy_boss_b.h"
#include "enemy_wolf.h"
#include "enemy_monster.h"
#include "enemy_firewolf.h"
#include "enemy_woodmonster.h"
#include "enemy_spider.h"
#include "enemy_greenmonster.h"
#include "enemy_cavalry_wolf.h"
#include "enemy_firemonster.h"
#include "shooter.h"
#include "bullet.h"
#include "mymissile.h"
#include "lightning.h"
#include "icecone.h"
#include "icefrozen.h"
#include "orangeball.h"
#include <QDebug>
//这个函数为sort提供比较原则,通过底部坐标的y值判断先画哪个
static bool compare(const Live_player*a,const Live_player*b)
{
    return a->getObj_locationY()<b->getObj_locationY();
}

void Window::loadImage(void)
{
    for(int i=0;i<dialog_img_num;i++)
    {
        dialog_img[i].load(dialog_dir[i]);
    }
    for(int i=0;i<2;i++)
    {
        icon_img[i].load(icon_dir[i]);
    }
}

void Window::loadSettings()
{
    story=(Story)settings.value("story",0).toInt();
    switch (story) {
    case Story::homereport:
        dialogStatus=report1;
        break;
    case Story::map1report1:
        dialogStatus=battle1intro1;
        break;
    case Story::map1report2:
        dialogStatus=battle1vic1;
        break;
    case Story::map2report1:
        dialogStatus=battle2intro1;
        break;
    case Story::map3report1:
        dialogStatus=battle3intro1;
        break;
    case Story::map3report2:
        dialogStatus=victoryall1;
        break;
    default:
        break;
    }
}

void Window::saveSettings()
{
    switch (story) {
    case Story::homereport:
        settings.setValue("story",0);
        break;
    case Story::map1report1:
        settings.setValue("story",1);
        break;
    case Story::map1report2:
        settings.setValue("story",2);
        break;
    case Story::map2report1:
        settings.setValue("story",3);
        break;
    case Story::map3report1:
        settings.setValue("story",4);
        break;
    case Story::map3report2:
        settings.setValue("story",5);
        break;
    default:
        break;
    }
    settings.sync();
}

Window::Window(QWidget *parent) :
    QWidget(parent),ui(new Ui::Window),settings("RUC","Protect Her Country"),
    condition(Background::startup),nextCondition(Background::home),story(Story::homereport),dialogStatus(report1),
    talent(nothing),cycleornot(false),passornot(false),loseornot(false),talentTime(false),controlPrincess(false),
    dialogTime(false),bagTime(false),deathamount(0),cycleamount(0),timing1(0),timing2(0),_playerput(Playerput::player_start)
{
    ui->setupUi(this);
    setMouseTracking(true);
    QObject::startTimer(25);
    loadImage();
    connect(&battle,SIGNAL(pauseSignal(bool)),this,SLOT(pauseSlot(bool)),Qt::UniqueConnection);
    connect(&battle,SIGNAL(toStartUp(Background)),this,SLOT(transfer(Background)),Qt::UniqueConnection);
    connect(&startup,SIGNAL(toHome(Background)),this,SLOT(transfer(Background)),Qt::UniqueConnection);

    connect(&princess,SIGNAL(princessDeath()),this,SLOT(lose()),Qt::UniqueConnection);
    connect(&princess,SIGNAL(iceball(QPoint)),this,SLOT(emit_iceball(QPoint)),Qt::UniqueConnection);
    connect(&bag,SIGNAL(setMP(int)),&princess,SLOT(setMP(int)),Qt::UniqueConnection);
    connect(&transition,SIGNAL(change()),this,SLOT(change()),Qt::UniqueConnection);
    connect(&transition,SIGNAL(end()),this,SLOT(end()),Qt::UniqueConnection);

    connect(&battle,SIGNAL(enableBag()),this,SLOT(enableBag()),Qt::UniqueConnection);
    connect(&bag,SIGNAL(disableBag()),this,SLOT(disableBag()),Qt::UniqueConnection);
}





void Window::setPauseAll(bool pause)
{
    for(auto i=player.begin();i!=player.end();i++)
    {
        (*i)->setPause(pause);
    }
    for(auto i=obj.begin();i!=obj.end();i++)
    {
        (*i)->setPause(pause);
    }
    princess.setPause(pause);
}


void Window::deleteAll(void)
{
    for(auto it=player.begin();it!=player.end();++it)
    {
        delete (*it);
    }
    player.clear();
    for(auto it=obj.begin();it!=obj.end();++it)
    {
        delete (*it);
    }
    obj.clear();
    for(auto it=pic.begin();it!=pic.end();++it)
    {
        delete (*it);
    }
    pic.clear();
}


Pic Window::producePic()
{
    srand((unsigned)time(NULL));
    Pic result;
    int resultInt;
    switch (global_condition) {
    case Background::map1:
        resultInt=rand()%(talentWeight[redPic]+talentWeight[bluePic]);
        if(resultInt<talentWeight[redPic])
            result=redPic;
        else result=bluePic;
        break;
    case Background::map2:
        resultInt=rand()%(talentWeight[redPic]+talentWeight[bluePic]+talentWeight[curePic]);
        if(resultInt<talentWeight[redPic])
            result=redPic;
        else if(resultInt<talentWeight[redPic]+talentWeight[bluePic])
            result=bluePic;
        else result=curePic;
        break;
    case Background::map3:
        resultInt=rand()%(talentWeight[redPic]+talentWeight[bluePic]+talentWeight[firefreePic]);
        if(resultInt<talentWeight[redPic])
            result=redPic;
        else if(resultInt<talentWeight[redPic]+talentWeight[bluePic])
            result=bluePic;
        else result=firefreePic;
        break;
    default:
        break;
    }
    return result;
}

void Window::clearPlayer()
{
    auto prev=player.before_begin();
    auto curr=player.begin();
    while(curr!=player.end())
    {
        if((*curr)->isDeletable())
        {
            if(((*curr)->getType())==Type::enemy||((*curr)->getType())==Type::boss)
            {
                deathincrease();
                pic.push_front(new Stable_obj((*curr)->getObj_location(),producePic()));
                connect(pic.front(),SIGNAL(message(Pic)),this,SLOT(receiveMsg(Pic)));
            }
            delete (*curr);
            curr=player.erase_after(prev);
        }
        else
        {
            prev=curr;
            curr++;
        }
    }
}


void Window::reset()
{
    talent=nothing;
    passornot=false;
    loseornot=false;
    talentTime=false;
    dialogTime=false;
    bagTime=false;
    restart();
    bag.resetMP();
    princess.reset();
    switch (condition) {
    case Background::startup:
        startup.reset();
        break;
    case Background::map1:
        if(story==Story::map1report1)
        {
            dialogStatus=battle1intro1;
        }
        else if(story==Story::map1report2)
        {
            dialogStatus=battle1vic1;
        }
        break;
    case Background::map2:
        if(story==Story::map2report1)
        {
            dialogStatus=battle2intro1;
        }
        break;
    case Background::map3:
        if(story==Story::map3report1)
        {
            dialogStatus=battle3intro1;
        }
        break;
    default:
        break;
    }//先复原里面的设置记录再转换
}
//被调用时 则触发开门动画 准备进行场景装换到type
void Window::transfer(Background type)
{
    if(type==condition) return;
    if(type==Background::home&&condition==Background::startup)
        loadSettings();
    nextCondition=type;
    transition.beginTrans(type);
//此时场上不能再有东西移动了
    setPauseAll(true);
}
//槽函数 接受门合上的信号  变换场景 要对下一个场景的所有内容进行布局
//change函数还需要实现的功能：把story和dialogStatus复原
void Window::change(void)
{
    reset();//把复原独立写了一个函数
    condition=nextCondition;
    global_condition=condition;
    deleteAll();
    princess.setPause(false);
    switch (condition) {
    case Background::home:
        pic.push_front(new Stable_obj(home_magic_area,magic_area));
        connect(pic.front(),SIGNAL(message(Pic)),this,SLOT(receiveMsg(Pic)),Qt::UniqueConnection);
        if(story==Story::homereport)
        {
            princess.setObj_location(home_center);
            controlPrincess=false;
        }
        else
        {
            princess.setObj_location(home_magic_area);
            controlPrincess=false;//门还未完全打开 不让移动
        }
         break;
    case Background::map1:
        if(story==Story::map1report1)
        {
            pic.push_front(new Stable_obj(map1_magic_area,magic_area));
            connect(this,SIGNAL(deleteMagicArea()),pic.front(),SLOT(deleteMe()),Qt::UniqueConnection);
            princess.setObj_location(map1_magic_area);
            player.push_front(new Guard_archer(map1_archer_info_pos));
            connect(player.front(),SIGNAL(arrow(QPoint,QPoint)),this,SLOT(emit_arrow(QPoint,QPoint)),Qt::UniqueConnection);
            //将来考虑archer对完话 变成第一个可掉落的物品弓箭图画
            //冰女吃了可以随时召唤
            controlPrincess=false;
            _playerput=Playerput::player_start;
        }
        else if(story==Story::map1report2)
        {
            princess.setObj_location(map1_magic_area);
            princess.turnFace(QPoint(1250,519));
            controlPrincess=false;
        }
        break;
    case Background::map2:
        if(story==Story::map2report1)
        {
            princess.setObj_location(map2_princess_start);
            player.push_front(new Guard_archer(map2_archer_start));
            connect(player.front(),SIGNAL(arrow(QPoint,QPoint)),this,SLOT(emit_arrow(QPoint,QPoint)),Qt::UniqueConnection);
            _playerput=Playerput::player_middile1;
        }
        break;
    case Background::map3:
        if(story==Story::map3report1)
        {
            princess.setObj_location(map3_princess_start);
            player.push_front(new Guard_archer(map3_archer_start));
            connect(player.front(),SIGNAL(arrow(QPoint,QPoint)),this,SLOT(emit_arrow(QPoint,QPoint)),Qt::UniqueConnection);
            _playerput=Playerput::player_middile2;
        }
        break;
    default:
        break;
        //门未完全打开 需要让怪物都暂停
    }
    setPauseAll(true);
}

void Window::end(void)
{
    switch (condition) {
    case Background::home:
        if(story==Story::homereport)
        {
            setPauseAll(false);
            controlPrincess=false;
            player.push_front(new Guard_archer(home_magic_area));
            connect(player.front(),SIGNAL(arrive()),this,SLOT(archerArrive()),Qt::UniqueConnection);
            connect(this,SIGNAL(deleteArcher()),player.front(),SLOT(deleteMe()),Qt::UniqueConnection);
            connect(this,SIGNAL(setArcherDes(QPoint)),player.front(),SLOT(setMyDes(QPoint)),Qt::UniqueConnection);
            player.front()->setDestination(home_before_stair);
        }
        else
        {
            setPauseAll(false);
            controlPrincess=true;
        }
        break;
    case Background::map1:
        if(story==Story::map1report1)
        {
            dialogTime=true;
            setPauseAll(false);
        }
        else if(story==Story::map1report2)
        {
            setPauseAll(false);
            player.push_front(new Enemy_boss_b(QPoint(1250,519)));
            dialogTime=true;
        }
        break;
    case Background::map2:
        if(story==Story::map2report1)
        {
            setPauseAll(false);
            dialogTime=true;
        }
        break;
    case Background::map3:
        if(story==Story::map3report1)
        {
            setPauseAll(false);
            dialogTime=true;
        }
    default:
        break;
    }
}


void Window::archerArrive(void)
{
    switch (story) {
    case Story::homereport:
        if(dialogStatus==report1)
            dialogTime=true;
        else{
            emit deleteArcher();
            controlPrincess=true;
            story=Story::map1report1;//homereport剧情结束
            saveSettings();
        }
        break;
    default:
        break;
    }
}

void Window::receiveMsg(Pic picType)
{
    switch (picType) {
    case magic_area:
        if(condition==Background::home&&(story==Story::map1report1||story==Story::map1report2||story==Story::map3report2))
            transfer(Background::map1);
        else if(condition==Background::home&&(story==Story::map2report1))
            transfer(Background::map2);
        else if(condition==Background::home&&(story==Story::map3report1))
            transfer(Background::map3);
        break;
    case curePic:
        bag.addWidgetNum(cure);
        break;
    case redPic:
        bag.addWidgetNum(red);
        break;
    case bluePic:
        bag.addWidgetNum(blue);
        break;
    case firefreePic:
        bag.addWidgetNum(firefree);
        break;
    default:
        break;
    }
}



void Window::restart()
{
    timing1=timing2=0;
    deathamount=0;
    loseornot=false;
}







void Window::lose(void)
{
    loseornot=true;
    setPauseAll(true);
    controlPrincess=false;
}






void Window::emit_iceball(const QPoint & location)
{
    if(!controlPrincess) return;
    if(location!=mousepos)
        obj.push_front(new Iceball(location,mousepos));
}

void Window::emit_missile(const QPoint &location)
{
    if(!controlPrincess) return;
    obj.push_front(new Missile(location));
}

void Window::emit_arrow(const QPoint &obj_location, const QPoint &rival_heart)
{
    if(!controlPrincess) return;
    if(obj_location==rival_heart)  return;
    obj.push_front(new Arrow(obj_location,rival_heart));
}


void Window::emit_fireball(const QPoint & location,const QPoint &rival_heart)
{
    if(!controlPrincess) return;
    if(location!=rival_heart)
    obj.push_front(new Fireball(location,rival_heart));
}

void Window::emit_fireball2(const QPoint & location,const QPoint &rival_heart)
{
    if(!controlPrincess) return;
    if(location!=rival_heart)
    obj.push_front(new Fireball2(location,rival_heart));
}

void Window::emit_fireball3(const QPoint & location,const QPoint &rival_heart)
{
    if(!controlPrincess) return;
    if(location!=rival_heart)
    obj.push_front(new Fireball3(location,rival_heart));
}
void Window::emit_greenstone(const QPoint & location,const QPoint &rival_heart)
{
    if(!controlPrincess) return;
    if(location!=rival_heart)
    obj.push_front(new greenstone(location,rival_heart));
}

void Window::emit_orangeball(const QPoint &location,const int direction)
{
    if(!controlPrincess) return;
    obj.push_front(new orangeball(location,direction));
}

void Window::emit_bullet(const QPoint & location,const QPoint &rival_heart)
{
    if(!controlPrincess) return;
    if(location!=rival_heart)
    obj.push_front(new Bullet(location,rival_heart));
}

void Window::emit_mymissile(const QPoint &location)
{
    if(!controlPrincess) return;
    obj.push_front(new mymissile(location));
}


void Window::create_boss_b(const QPoint & location)
{
    player.push_front(new Enemy_boss_b(location));
    connect(player.front(),SIGNAL(Orangeball(QPoint,int)),this,SLOT(emit_orangeball(QPoint,int)),Qt::UniqueConnection);
}

void Window::processPlayer(QPainter &p)
{
//处理部分
    for(auto i=player.begin();i !=player.end();++i)
    {
        (*i)->process(princess);
        //处理player与princess的关系
        for(auto j=i;j!=player.end();++j)
        {
            {
                auto k=i;
                k++;
                if(k==player.end()) break;
                //end函数并不是返回最后一个，而是返回最后一个的下面一个位置
                //所以在i=player.end()的上一轮
                //此时i已经指向了链表末端 不能再进入第二层循环了 要退出
            }
            if(j==i) j++;
            //j应该从链表节点i后面一个开始，但链表迭代器不支持j=i+1这样的加法操作
            //所以这样 在第一轮循环的时候把j加一下
            (*i)->process(**j);
            (*j)->process(**i);
            //i,j都是指向Live_player*的指针，即Live_player的二级指针
            //互相process的操作
        }
    }
    //下面是处理obj和princess player关系的循环
    for(auto i=obj.begin();i!=obj.end();i++)
    {
        (*i)->process(princess);
        //处理thrown_obj和princess的关系
        for(auto j=player.begin();j!=player.end();j++)
        {
            (*i)->process(**j);
            //处理thrown_obj和princess关系
        }
    }
//删除部分
    clearPlayer();
    clear(obj);
    clear(pic);
//排序部分
    player.sort(compare);
//画画部分
    bool drawPrincess=true;
    for(auto i=player.cbegin();i!=player.cend();i++)
    {
        if(drawPrincess&&princess.getObj_locationY()<(*i)->getObj_locationY())
        {
            princess.draw(p);
            drawPrincess=false;
        }
        (*i)->draw(p);
    }
    if(drawPrincess) princess.draw(p);
    draw(obj,p);
}

void Window::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    switch (condition) {
    case Background::startup:
        paintStartup(p);
        break;
    case Background::home:
        paintHome(p);
        break;
    case Background::map1:
        paintBattle(p);
        break;
    case Background::map2:
        paintBattle(p);
        break;
    case Background::map3:
        paintBattle(p);
    default:
        break;
    }
    transition.draw(p);
}

void Window::paintStartup(QPainter &p)
{
    startup.draw(p);
}

void Window::paintHome(QPainter &p)
{
    home.draw(p);
    //把所有物品画一遍
    draw(pic,p);
    //处理所有东西
    processPlayer(p);
    if(dialogTime)
    {
        p.drawImage(dialog_img_pos,dialog_img[dialogStatus]);
    }
}

void Window::paintBattle(QPainter &p)
{
    battle.draw(p);
    draw(pic,p);
    //画掉落物品和magic_area
    processPlayer(p);
    if(dialogTime)
    {
        p.drawImage(dialog_img_pos,dialog_img[dialogStatus]);
        return;
    }
    else if(bagTime)
        bag.draw(p);
    if((deathamount==enemyamount[0]&&condition==Background::map1)||(deathamount==enemyamount[1]&&condition==Background::map2)||(deathamount==(enemyamount[2]+cycleamount*4)&&condition==Background::map3))
    {
        if(story==Story::map1report1||story==Story::map2report1||story==Story::map3report1)
        {
            setPauseAll(true);
            p.drawImage(QPoint(400,350),icon_img[1]);
            controlPrincess=false;
        }
        return;
    }
    else if(loseornot==true)
    {
        p.drawImage(QPoint(400,350),icon_img[0]);
        setPauseAll(true);
        return;
    }
    else
    {
        changetime();
        newplayer();
    }
}





void Window::keyPressEvent(QKeyEvent *event)
{
    if(!controlPrincess) return;
    //按键应是只能控制冰女
    switch (condition) {
        case Background::home:
            if(event->key()==Qt::Key_S)
            {
                for(auto i=pic.begin();i!=pic.end();i++)
                {
                    (*i)->process(princess);
                }
            }
            break;
        case Background::map1:
            if(event->key()==Qt::Key_A)
                princess.react(Command::Longattack);
            else if(event->key()==Qt::Key_S)
                for(auto i=pic.begin();i!=pic.end();i++)
                {
                    (*i)->process(princess);
                }
            break;
        case Background::map2:
            if(event->key()==Qt::Key_A)
                princess.react(Command::Longattack);
            else if(event->key()==Qt::Key_S)
                for(auto i=pic.begin();i!=pic.end();i++)
                {
                    (*i)->process(princess);
                }
            break;
        case Background::map3:
            if(event->key()==Qt::Key_A)
                princess.react(Command::Longattack);
            else if(event->key()==Qt::Key_S)
                for(auto i=pic.begin();i!=pic.end();i++)
                {
                    (*i)->process(princess);
                }
            break;
        default:
            break;
    }
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
    switch (condition) {
    case Background::startup:
        startup.mouseMove(event->pos());
        break;
    case Background::home:
        if(!controlPrincess) return;
        //此时不能控制冰女
        princess.turnFace(event->pos());
        break;
    case Background::map1:
        if(dialogTime||bagTime||loseornot) return;
        mousepos=event->pos();
        battle.mouseMove(mousepos);
        if(controlPrincess) princess.turnFace(mousepos);
        break;
    case Background::map2:
        if(dialogTime||bagTime||loseornot) return;
        mousepos=event->pos();
        battle.mouseMove(mousepos);
        if(controlPrincess) princess.turnFace(mousepos);
        break;
    case Background::map3:
        if(dialogTime||bagTime||loseornot) return;
        mousepos=event->pos();
        battle.mouseMove(mousepos);
        if(controlPrincess) princess.turnFace(mousepos);
        break;
    default:
        break;
    }
}

void Window::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if (talentTime)
        {
            if(inRegion(event->pos()))
            {
                switch (talent) {
                case archer:
                    player.push_front(new Guard_archer(event->pos()));
                    connect(player.front(),SIGNAL(arrow(QPoint,QPoint)),this,SLOT(emit_arrow(QPoint,QPoint)),Qt::UniqueConnection);
                    bag.changeMP(archer);
                    break;
                case shooter:
                    player.push_front(new Shooter(event->pos()));
                    connect(player.front(),SIGNAL(mymissile(QPoint)),this,SLOT(emit_mymissile(QPoint)),Qt::UniqueConnection);
                    connect(player.front(),SIGNAL(bullet(QPoint,QPoint)),this,SLOT(emit_bullet(QPoint,QPoint)),Qt::UniqueConnection);
                    bag.changeMP(shooter);
                    break;
                case frozen:
                    obj.push_front(new Icefrozen(event->pos()));
                    bag.changeMP(frozen);
                    break;
                case thunder:
                    obj.push_front(new Lightning(event->pos()));
                    bag.changeMP(thunder);
                    break;
                case hail:
                    for(int i=0;i<hailNum;i++)
                    {
                        if(inRegion(hailAround[i]+event->pos()))
                            obj.push_front(new Icecone(hailAround[i]+event->pos()));
                    }
                    bag.changeMP(hail);
                    break;
                default:
                    break;
                }
            }
            talent=nothing;
            talentTime=false;
            return;
        }

        switch (condition) {
        case Background::startup:
            startup.mousePress(event->pos());
            break;
        case Background::home:
            if(dialogTime)
            {
                dialogStatus=Dialog(dialogStatus+1);
                if(dialogStatus==battle1intro1)
                {
                    //此时家中的小兵和冰女的对话已经结束了
                    dialogTime=false;
                    setArcherDes(home_magic_area);
                }
            }
            else if(controlPrincess)
                princess.setDestination(event->pos());
            break;
        case Background::map1:
            if(deathamount==enemyamount[0]&&story==Story::map1report1)//第一关胜利
            {
                player.push_front(new Enemy_boss_b(QPoint(1250,519)));
                player.front()->setPause(false);
                story=Story::map1report2;
                restart();
                saveSettings();
                princess.turnFace(QPoint(1250,519));
                controlPrincess=false;
                dialogTime=true;
                return;
            }
            if(dialogTime)
            {
                dialogStatus=Dialog(dialogStatus+1);
                if(dialogStatus==battle1vic1)
                {
                    //此时战斗介绍对话已经结束了
                    dialogTime=false;
                    restart();
                    _playerput=Playerput::player_start;
                    emit deleteMagicArea();
                    controlPrincess=true;
                }
                else if(dialogStatus==battle2intro1)
                {
                    //第一关剧情正式结束
                    dialogTime=false;
                    story=Story::map2report1;
                    saveSettings();
                    transfer(Background::map2);
                }
                return;
            }
            if(loseornot==true)
            {
                restart();
                _playerput=Playerput::player_start;
                transfer(Background::home);
                return;
            }
            if(bagTime)
            {
                talent=bag.mousePress(event->pos());
                if(talent==archer||talent==shooter||talent==thunder||talent==hail||talent==frozen)
                    talentTime=true;
                else if(talent==red)
                    princess.addHP(100);
                else if(talent==blue)
                    bag.changeMP(100);
                return;
            }
            if((!battle.mousePress(event->pos()))&&controlPrincess)
                    princess.setDestination(event->pos());
            break;
        case Background::map2:
            if(deathamount==enemyamount[1]&&story==Story::map2report1)//第二关胜利
            {
                restart();
                story=Story::map3report1;
                saveSettings();
                transfer(Background::map3);
                return;
            }
            if(dialogTime)
            {
                dialogStatus=Dialog(dialogStatus+1);
                if(dialogStatus==battle3intro1)
                {
                    //此时战斗介绍对话已经结束了
                    dialogTime=false;
                    controlPrincess=true;
                    restart();
                    _playerput=Playerput::player_middile1;
                }

                return;
            }
            if(loseornot==true)
            {
                restart();
                _playerput=Playerput::player_middile1;
                transfer(Background::home);
                return;
            }
            if(bagTime)
            {
                talent=bag.mousePress(event->pos());
                if(talent==archer||talent==shooter||talent==thunder||talent==hail||talent==frozen)
                    talentTime=true;
                return;
            }
            if((!battle.mousePress(event->pos()))&&controlPrincess)
                    princess.setDestination(event->pos());
            break;
        case Background::map3:
            /*if(deathamount==enemyamount[3]&&story==Story::map3report1)//第三关胜利
            {
                story=Story::map3report2;
                saveSettings();
                transfer(Background::map1);
                return;
            }*/
            if(dialogTime)
            {
                dialogStatus=Dialog(dialogStatus+1);
                if(dialogStatus==victoryall1)
                {
                    //第三关开头剧情结束
                    dialogTime=false;
                    controlPrincess=true;
                    restart();
                    _playerput=Playerput::player_middile2;
                }
                return;
            }
            if(loseornot==true)
            {
                restart();
                _playerput=Playerput::player_middile2;
                transfer(Background::home);
                return;
            }
            if(bagTime)
            {
                talent=bag.mousePress(event->pos());
                if(talent==archer||talent==shooter||talent==thunder||talent==hail||talent==frozen)
                    talentTime=true;
                return;
            }
            if((!battle.mousePress(event->pos()))&&controlPrincess)
                    princess.setDestination(event->pos());
            break;
        default:
            break;
        }
    }
    else if(event->button()==Qt::RightButton)
    {
        switch (condition) {
        case Background::startup:
            if(startup.mousePress(event->pos()))
            {
                settings.clear();
            }
            break;
        case Background::map2:
            if(!controlPrincess) return;
            if(!inRegion(event->pos())) return;
            princess.flashMove(event->pos());
            bag.changeMP(flashMove);
            break;
        case Background::map3:
            if(!controlPrincess) return;
            if(!inRegion(event->pos())) return;
            princess.flashMove(event->pos());
            bag.changeMP(flashMove);
            break;
        default:
            break;
        }
    }
}





//是用于改变time的
void Window::changetime()
{
    if(!controlPrincess) return;
    timing1++;
    if(timing1==200)
    {
        timing1=0;
        timing2++;
    }
    return;
}
//是用于根据time的值改变怪物投放状态的
bool Window::timing()
{
    if((timing2+1)%4==0)
    {
        if(cycleornot==true)
        {
            if(_playerput==Playerput::map3_third||_playerput==Playerput::map3_forth)
            {
                cycleamount++;
                _playerput=Playerput::map3_second;
            }
        }
        if((story==Story::map1report1&&_playerput<player_middile1)||
                (story==Story::map2report1&&_playerput<player_middile2)||
                story==Story::map3report1)
            _playerput=Playerput(1+_playerput);
        else return false;
        timing2=0;
        if(_playerput==Playerput::map3_forth)
        {
            cycleornot=true;
        }
        return true;
    }
    else
        return false;
}



//投放怪物
void Window::newplayer()
{
    if(!timing())return;
    else
    {
        switch (_playerput){
            case Playerput::map1_first:
                player.push_front(new Enemy_wolf(map1_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_monster(map1_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_wolf(map1_3));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
            break;

            case Playerput::map1_second:
                player.push_front(new Enemy_monster(map1_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_wolf(map1_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_monster(map1_3));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
            break;

            case Playerput::map1_third:
                player.push_front(new Enemy_monster(map1_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_pigsoldier(map1_2));
                connect(player.front(),SIGNAL(fireball3(QPoint,QPoint)),this,SLOT(emit_fireball3(QPoint,QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_monster(map1_3));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
            break;


            case Playerput::map2_first:
                player.push_front(new Enemy_cavalry_wolf(map2_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_greenmonster(map2_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(greenstone(QPoint,QPoint)),this,SLOT(emit_greenstone(QPoint,QPoint)),Qt::UniqueConnection);
                player.push_front(new Enemy_cavalry_wolf(map2_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_greenmonster(map2_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(greenstone(QPoint,QPoint)),this,SLOT(emit_greenstone(QPoint,QPoint)),Qt::UniqueConnection);
            break;

            case Playerput::map2_second:
                player.push_front(new Enemy_pigsoldier(map2_1));
                connect(player.front(),SIGNAL(fireball3(QPoint,QPoint)),this,SLOT(emit_fireball3(QPoint,QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_greenmonster(map2_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(greenstone(QPoint,QPoint)),this,SLOT(emit_greenstone(QPoint,QPoint)),Qt::UniqueConnection);
                player.push_front(new Enemy_pigsoldier(map2_2));
                connect(player.front(),SIGNAL(fireball3(QPoint,QPoint)),this,SLOT(emit_greenstone(QPoint,QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_greenmonster(map2_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(greenstone(QPoint,QPoint)),this,SLOT(emit_greenstone(QPoint,QPoint)),Qt::UniqueConnection);
            break;
            case Playerput::map2_third:
                player.push_front(new Enemy_spider(map2_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_spider(map2_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_woodmonster(map2_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_woodmonster(map2_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
            break;

            case Playerput::map3_first:
                player.push_front(new Enemy_firewolf(map3_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_firemonster(map3_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_firemonster(map3_3));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_firewolf(map3_4));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);

            break;
            case Playerput::map3_second:
                //player.push_front(new Enemy_firecow(map3_1));
                //connect(player.front(),SIGNAL(fireball2(QPoint,QPoint)),this,SLOT(emit_fireball2(QPoint,QPoint)),Qt::UniqueConnection);
                //connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                //player.push_front(new Enemy_firewizard(map3_2));
                //connect(player.front(),SIGNAL(fireball(QPoint,QPoint)),this,SLOT(emit_fireball(QPoint,QPoint)),Qt::UniqueConnection);
                //connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                //player.push_front(new Enemy_firewizard(map3_3));
                //connect(player.front(),SIGNAL(fireball(QPoint,QPoint)),this,SLOT(emit_fireball(QPoint,QPoint)),Qt::UniqueConnection);
                //connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                //player.push_front(new Enemy_firecow(map3_4));
                //connect(player.front(),SIGNAL(fireball2(QPoint,QPoint)),this,SLOT(emit_fireball2(QPoint,QPoint)),Qt::UniqueConnection);
                //connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);*/
            break;
            case Playerput::map3_third:
                player.push_front(new Enemy_firewolf(map3_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_firemonster(map3_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_firemonster(map3_3));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                player.push_front(new Enemy_firewolf(map3_3));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
            break;
            case Playerput::map3_forth:
                player.push_front(new Enemy_boss_a(map3_2));
                connect(player.front(),SIGNAL(missile(QPoint)),this,SLOT(emit_missile(QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(boss_b(QPoint)),this,SLOT(create_boss_b(QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
            break;
            default:
            break;
        }
    }
    return;
}

/*
 * 以下是所有怪物的函数
 *              石怪
 *              player.push_front(new Enemy_monster(map1_2));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                火石怪
 *              player.push_front(new Enemy_firemonster(map1_2));
                connect(player.front(),SIGNAL(death()),this,SLOT(deathincrease()),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                狼
                player.push_front(new Enemy_wolf(map1_3));
                connect(player.front(),SIGNAL(death()),this,SLOT(deathincrease()),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                骑兵狼
                player.push_front(new Enemy_cavalry_wolf(map1_1));
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                火牛
                player.push_front(new Enemy_firecow(map1_2));
                connect(player.front(),SIGNAL(fireball2(QPoint,QPoint)),this,SLOT(emit_fireball2(QPoint,QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                火巫师
                player.push_front(new Enemy_firewizard(map1_3));
                connect(player.front(),SIGNAL(fireball(QPoint,QPoint)),this,SLOT(emit_fireball(QPoint,QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                火狼
                player.push_front(new Enemy_firewolf(map1_1));
                connect(player.front(),SIGNAL(death()),this,SLOT(deathincrease()),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                骑兵猪
                player.push_front(new Enemy_pigsoldier(map1_3));
                connect(player.front(),SIGNAL(fireball3(QPoint,QPoint)),this,SLOT(emit_fireball3(QPoint,QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                绿怪物
                player.push_front(new Enemy_greenmonster(map1_3));
                connect(player.front(),SIGNAL(greenstone(QPoint,QPoint)),this,SLOT(emit_fireball3(QPoint,QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
                BOSSa
                player.push_front(new Enemy_boss_a(map1_2));
                connect(player.front(),SIGNAL(missile(QPoint)),this,SLOT(emit_missile(QPoint)),Qt::UniqueConnection);
                connect(player.front(),SIGNAL(lose()),this,SLOT(lose()),Qt::UniqueConnection);
*/


Window::~Window()
{
    delete ui;
    deleteAll();
}


