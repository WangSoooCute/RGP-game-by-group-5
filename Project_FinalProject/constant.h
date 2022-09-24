#ifndef CONSTANT_H
#define CONSTANT_H
#include <QPoint>
#include <forward_list>
#include <QPolygon>
#include <QPainter>
#include <QImage>

enum class Command{Lstand,Rstand,Longattack,Move,Lwalk,Lmove,Rmove,Umove,Lattack,Rattack,Death,Appear,Disappear};//6.14
enum class Background{startup,home,map1,map2,map3};
enum class Type{princess,guard,enemy,boss,others};
enum class Story{homereport,map1report1,map1report2,map2report1,map3report1,map3report2};
enum Pic{magic_area,redPic,bluePic,curePic,firefreePic};
enum TalentType{red,blue,cure,firefree,archer,shooter,frozen,hail,thunder,flashMove,nothing};
enum Route{map1_1,map1_2,map1_3,map2_1,map2_2,map3_1,map3_2,map3_3,map3_4};
enum Playerput{player_start,map1_first,map1_second,map1_third,player_middile1,map2_first,map2_second,map2_third,player_middile2,map3_first,map3_second,map3_third,map3_forth};//判断状态来switch投放怪物
enum Dialog{report1,report2,report3,report4,report5,report6,
           battle1intro1,battle1vic1,battle1vic2,
            battle1vic3,battle2intro1,battle3intro1,battle3intro2,battle3intro3,battle3intro4,battle3intro5,
           victoryall1,victoryall2,enddialog};
int const enemyamount[3]{9,12,10};//每一个地图投放的怪物数量，用来判断胜利与否。

/*story的指南
homereport剧情结束在小兵从home的魔法阵消失的时候
在小兵消失时，story改为map1report1
map1report1剧情结束在第一关打过 胜利标志出现时
在胜利标志出现时 story改为map1report2
map1report2结束在map1向map2转换场景的change函数时（此时窗口最黑）
在change函数里把map1report2改为map2report1
map2report1结束在第二关打过胜利标志出现时 story改为map3report1
第二关胜利标志出现， 用户点击鼠标后 就开始用黑屏的转换为map3
map3report1结束在第三关打赢 出现胜利标志时 此时更换为map3report2
然后仍然选择黑屏过渡转换到map1(从满目疮痍的家园回来)
进行最后的对话 然后返回startup界面 游戏结束

在剧情中断后 从home魔法阵传送时
story=map1report1  转换到第一关 正常开始小兵介绍第一关怪物的剧情
story=map1report2  转换到第一关 开始冰女和巫师对话剧情
story=map2report1  转换到第二关 开始第二关开始介绍怪物剧情
story=map3report1 转换到第三关 开始第三关小兵介绍怪物剧情
story=map3report2 转换到第一关 开始最后的结束剧情


所以整个场景转换的逻辑是
要么一路按照剧情正常玩下去
要么中途退出到startup 在到home  在根据story进度用魔法阵传送到对应关卡剧情处

以上是story什么时候换下一个的处理
dialogStatus和story随时同步

考虑dialogStatus和story发生不同步都是什么时候
1 游戏输了 此时场景转换到home
2 中途退出 场景转换到startup
只要在场景转换调用change函数时 依据story的状态把dialogStatus复原即可

又 场景之间转换选择黑幕还是开关门
map1-map2-map3-map1均选择黑幕
startup-home-map1,2,3均选择开关门
map1,2,3-home选择开关门
*/

struct Stable_obj_info
{
//rlocation代表这个东西的逻辑坐标相对于图片左上角的坐标
    const QPoint rlocation;
//dir为图片文件路径
    const char *dir;
//多大范围内冰女在里面 能触发
    const int range;
};

template<typename T>
void clear(std::forward_list<T> &mylist)
{
    auto prev=mylist.before_begin();
    auto curr=mylist.begin();
    while(curr!=mylist.end())
    {
        if((*curr)->isDeletable())
        {
            delete (*curr);
            curr=mylist.erase_after(prev);
        }
        else
        {
            prev=curr;
            curr++;
        }
    }
}



template<typename T>
void draw(std::forward_list<T> &mylist,QPainter &p)
{
    for(auto it=mylist.begin();it!=mylist.end();++it)
    {
        (*it)->draw(p);
    }
}


//可走范围限制函数
bool inRegion(const QPoint &pos);


extern const QPoint destination[9][4];
extern const QPoint startposition[9];

//构造掉落图片的对象所需要的信息
extern const Stable_obj_info info[];

//当前场景
extern Background global_condition;

//对话框左上角
extern const QPoint dialog_img_pos;

//家里 传送阵中心坐标
extern const QPoint home_magic_area;//对话后右下角传送阵坐标

//家里台上冰女站位
extern const QPoint home_center;

//家中弓箭手报告点站位
extern const QPoint home_before_stair;

//第一幅图传送阵中心坐标
extern const QPoint map1_magic_area;//第一幅地图传送后传动点坐标

//第一幅图弓箭手站立位置
extern const QPoint map1_archer_info_pos;

//第二关冰女和士兵的初始站位
extern const QPoint map2_princess_start;
extern const QPoint map2_archer_start;
//第三关冰女和士兵的初始站位
extern const QPoint map3_princess_start;
extern const QPoint map3_archer_start;

//对话图片数组
extern QImage dialog_img[];

//对话图片总数量
extern const int dialog_img_num;


//每一张图片load时需要的路径
extern const char *dialog_dir[];

//胜利或者失败的图片数组
extern QImage icon_img[];
//失败or胜利的标志图片
extern const char *icon_dir[];


extern const int hailNum;
extern const QPoint hailAround[];
//怪物随机掉落red blue cure firefree的权重
extern const unsigned int talentWeight[];

extern const int MAXMP;
#endif // CONSTANT_H
