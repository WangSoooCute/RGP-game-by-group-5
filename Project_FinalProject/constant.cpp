#include "constant.h"
#include <QPolygon>
#include <QDebug>


const QPoint destination[9][4]=
{{QPoint(1152,228),QPoint(950,430),QPoint(293,477),QPoint(-60,520)},
 {QPoint(1020,497),QPoint(760,497),QPoint(380,497),QPoint(-60,520)},
 {QPoint(985,625),QPoint(776,625),QPoint(230,640),QPoint(-60,530)},
 {QPoint(918,322),QPoint(696,382),QPoint(172,327),QPoint(-60,397)},
 {QPoint(995,716),QPoint(644,812),QPoint(301,728),QPoint(-60,741)},
 {QPoint(445,190),QPoint(426,411),QPoint(205,545),QPoint(-60,520)},
 {QPoint(882,266),QPoint(834,441),QPoint(432,412),QPoint(-60,515)},
 {QPoint(911,624),QPoint(847,468),QPoint(442,422),QPoint(-60,533)},
 {QPoint(900,844),QPoint(630,683),QPoint(605,378),QPoint(-60,522)}
};

const int hailNum=20;
const QPoint hailAround[]={
    QPoint(0,0),QPoint(-30,5),QPoint(-50,20),QPoint(-40,-10),
    QPoint(-30,80),QPoint(-20,90),QPoint(-90,-70),
    QPoint(-40,-70),QPoint(30,50),QPoint(20,80),QPoint(140,-10),
    QPoint(60,-40),
    QPoint(-120,-80),QPoint(-100,-90),QPoint(4,50),QPoint(30,70),
    QPoint(30,15),QPoint(45,-30),QPoint(50,-80),QPoint(90,0)
};

const QPoint startposition[9]=
{
    QPoint(1250,228),QPoint(1250,520),QPoint(1250,750),
    QPoint(1250,384),QPoint(1250,800),
    QPoint(373,-50),QPoint(1250,260),QPoint(1250,620),QPoint(910,1050)
};


static const QVector<QPoint> homePoints{
    QPoint(824,504),QPoint(833,449),QPoint(793,405),QPoint(696,367),
    QPoint(591,357),QPoint(489,370),QPoint(411,407),QPoint(371,448),
    QPoint(376,499),QPoint(431,543),QPoint(499,575),QPoint(586,588),
    QPoint(665,569),QPoint(698,584),QPoint(775,682),QPoint(913,750),
    QPoint(1045,657),QPoint(922,601),QPoint(849,516)
};


static const QVector<QPoint> map1Points_no1{//我添加的东西
    QPoint(0,480),QPoint(130,480),QPoint(260,350),QPoint(945,350),
    QPoint(1120,160),QPoint(1200,150),QPoint(1200,0),QPoint(0,0),
    QPoint(0,480)
};
static const QVector<QPoint> map1Points_no2{
    QPoint(1200,270),QPoint(1170,270),QPoint(1080,400),QPoint(1088,415),
    QPoint(1102,422),QPoint(1200,440),QPoint(1200,270)
};
static const QVector<QPoint> map1Points_no3{
    QPoint(1200,560),QPoint(1045,545),QPoint(1037,555),QPoint(1200,640),
    QPoint(1200,560)
};
static const QVector<QPoint> map1Points_no4{
    QPoint(1200,800),QPoint(1000,680),QPoint(230,680),QPoint(70,590),
    QPoint(0,590),QPoint(0,480),QPoint(0,1200),QPoint(1200,1200)
};


static const QVector<QPoint> map2Points_no1{//我添加的东西
    QPoint(0,310),QPoint(60,310),QPoint(150,240),QPoint(735,230),
    QPoint(890,50),QPoint(950,10),QPoint(950,180),QPoint(1130,280),
    QPoint(1200,260),QPoint(1200,0),QPoint(0,0)
};
static const QVector<QPoint> map2Points_no2{
    QPoint(1200,688),QPoint(1200,510),QPoint(840,405),QPoint(800,480),
    QPoint(550,470),QPoint(550,443),QPoint(385,440),QPoint(486,511),
    QPoint(552,628),QPoint(593,633),QPoint(614,566),QPoint(703,573),
    QPoint(711,634),QPoint(980,570),QPoint(1200,688)
};
static const QVector<QPoint> map2Points_no3{
    QPoint(1200,897),QPoint(1100,886),QPoint(1027,803),QPoint(997,825),
    QPoint(914,822),QPoint(881,805),QPoint(450,852),QPoint(394,795),
    QPoint(306,831),QPoint(233,805),QPoint(156,833),QPoint(0,806),QPoint(0,1200),
    QPoint(1200,1200),QPoint(1200,897)
};
static const QVector<QPoint> map2Points_no4{
    QPoint(0,594),QPoint(450,567),QPoint(461,622),QPoint(473,560),
    QPoint(297,433),QPoint(204,471),QPoint(120,436),QPoint(80,486),
    QPoint(0,470)
};


static const QVector<QPoint> map3Points_no1{//我添加的东西
    QPoint(0,100),QPoint(120,100),QPoint(180,170),QPoint(170,228),
    QPoint(228,273),QPoint(95,363),QPoint(80,408),QPoint(1,410),
    QPoint(0,100)
};

static const QVector<QPoint> map3Points_no2{
    QPoint(522,0),QPoint(654,130),QPoint(700,127),QPoint(844,8),
    QPoint(1103,135),QPoint(1200,123),QPoint(1200,0),QPoint(522,0)
};
static const QVector<QPoint> map3Points_no3{
    QPoint(0,580),QPoint(88,576),QPoint(135,627),QPoint(78,733),
    QPoint(286,784),QPoint(273,822),QPoint(213,848),QPoint(247,880),
    QPoint(300,878),QPoint(344,974),QPoint(276,1000),QPoint(0,1000),
    QPoint(0,580)
};




const Stable_obj_info info[]={
    {QPoint(50,33),":/others/image/others/magic_area.png",16},
    {QPoint(13,13),":/talent/image/talent/smallRed.png",13},
    {QPoint(13,13),":/talent/image/talent/smallBlue.png",13},
    {QPoint(13,13),":/talent/image/talent/smallCure.png",13},
    {QPoint(13,13),":/talent/image/talent/smallFirefree.png",13}
};

const unsigned int talentWeight[5]={0,5,5,2,2};
//分别为：magic_area,red blue cure firefree

const int dialog_img_num=18;

QImage dialog_img[dialog_img_num];

const int MAXMP=400;

QImage icon_img[2];


const char *icon_dir[]={
    ":/others/image/others/LOSE.png",
    ":/others/image/others/victory.png"
};

const char *dialog_dir[]={
    ":/dialog/image/dialog/1.png",
    ":/dialog/image/dialog/2.png",
    ":/dialog/image/dialog/3.png",
    ":/dialog/image/dialog/4.png",
    ":/dialog/image/dialog/5.png",
    ":/dialog/image/dialog/6.png",
    ":/dialog/image/dialog/7.png",
    ":/dialog/image/dialog/8.png",
    ":/dialog/image/dialog/9.png",
    ":/dialog/image/dialog/10.png",
    ":/dialog/image/dialog/11.png",
    ":/dialog/image/dialog/12.png",
    ":/dialog/image/dialog/13.png",
    ":/dialog/image/dialog/14.png",
    ":/dialog/image/dialog/15.png",
    ":/dialog/image/dialog/16.png",
    ":/dialog/image/dialog/17.png",
    ":/dialog/image/dialog/18.png",
};




const QPoint dialog_img_pos(72,667);
const QPoint home_magic_area(947,683);
const QPoint home_center(605,480);
const QPoint home_before_stair(872,649);
const QPoint map1_magic_area(65,535);
const QPoint map1_archer_info_pos(254,533);
const QPoint map2_princess_start(81,706);
const QPoint map2_archer_start(349,347);
const QPoint map3_princess_start(57,499);
const QPoint map3_archer_start(317,417);

const static QPolygon homeRegion(homePoints);
const static QPolygon map1Region_no1(map1Points_no1);//我添加的东西
const static QPolygon map1Region_no2(map1Points_no2);//我添加的东西
const static QPolygon map1Region_no3(map1Points_no3);//我添加的东西
const static QPolygon map1Region_no4(map1Points_no4);//我添加的东西
const static QPolygon map2Region_no1(map2Points_no1);//我添加的东西
const static QPolygon map2Region_no2(map2Points_no2);//我添加的东西
const static QPolygon map2Region_no3(map2Points_no3);//我添加的东西
const static QPolygon map2Region_no4(map2Points_no4);//我添加的东西
const static QPolygon map3Region_no1(map3Points_no1);//我添加的东西
const static QPolygon map3Region_no2(map3Points_no2);//我添加的东西
const static QPolygon map3Region_no3(map3Points_no3);//我添加的东西


Background global_condition=Background::startup;



bool inRegion(const QPoint &pos)
{
    switch (global_condition) {
    case Background::home:
        return homeRegion.containsPoint(pos,Qt::OddEvenFill);
        break;
    case Background::map1: 
        return  (!map1Region_no1.containsPoint(pos,Qt::OddEvenFill))
                &&(!map1Region_no2.containsPoint(pos,Qt::OddEvenFill))
                &&(!map1Region_no3.containsPoint(pos,Qt::OddEvenFill))
                &&(!map1Region_no4.containsPoint(pos,Qt::OddEvenFill));
        break;
    case Background::map2:
        return (!map2Region_no1.containsPoint(pos,Qt::OddEvenFill))
               &&(!map2Region_no2.containsPoint(pos,Qt::OddEvenFill))
               &&(!map2Region_no3.containsPoint(pos,Qt::OddEvenFill))
               &&(!map2Region_no4.containsPoint(pos,Qt::OddEvenFill));
        break;
    case Background::map3:
        return (!map3Region_no1.containsPoint(pos,Qt::OddEvenFill))
                &&(!map3Region_no2.containsPoint(pos,Qt::OddEvenFill))
                &&(!map3Region_no3.containsPoint(pos,Qt::OddEvenFill));
        break;
    default:
        return false;
        break;
    }
}


