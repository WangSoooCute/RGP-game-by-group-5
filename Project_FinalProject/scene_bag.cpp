#include "scene_bag.h"
#include <QDebug>

static const int talentCost[]={0,0,0,0,100,100,200,200,100,10,0};

static const int talentNum=9;

static const QPoint img_location(0,624);

static const QPoint rlocation[]={
    QPoint(12,83),QPoint(108,79),QPoint(206,78),
    QPoint(12,176),QPoint(109,178),QPoint(202,176),
    QPoint(8,273),QPoint(105,273),QPoint(206,278)
};


static const char *reddir[]={
    ":/talent/image/talent/reddark.png",
    ":/talent/image/talent/red.png"
};

static const char *bluedir[]={
    ":/talent/image/talent/bluedark.png",
    ":/talent/image/talent/blue.png"
};

static const char *curedir[]={
    ":/talent/image/talent/curedark.png",
    ":/talent/image/talent/cure.png"
};

static const char *firefreedir[]={
    ":/talent/image/talent/firefreedark.png",
    ":/talent/image/talent/firefree.png"
};

static const char *archerdir[]={
    ":/talent/image/talent/arrowdark.png",
    ":/talent/image/talent/arrow.png"
};

static const char *shooterdir[]={
    ":/talent/image/talent/shooterdark.png",
    ":/talent/image/talent/shooter.png"
};

static const char *frozendir[]={
    ":/talent/image/talent/frozendark.png",
    ":/talent/image/talent/frozen.png"
};

static const char *haildir[]={
    ":/talent/image/talent/haildark.png",
    ":/talent/image/talent/hail.png"
};

static const char *thunderdir[]={
    ":/talent/image/talent/thunderbdark.png",
    ":/talent/image/talent/thunder.png"
};

/*static TalentWidget Red(rlocation[0]+img_location,reddir);
static TalentWidget Blue(rlocation[1]+img_location,bluedir);
static TalentWidget Cure(rlocation[2]+img_location,curedir);
static TalentWidget Firefree(rlocation[3]+img_location,firefreedir);
static TalentWidget Archer(rlocation[4]+img_location,archerdir);
static TalentWidget Shooter(rlocation[5]+img_location,shooterdir);
static TalentWidget Frozen(rlocation[6]+img_location,frozendir);
static TalentWidget Hail(rlocation[7]+img_location,haildir);
static TalentWidget Thunder(rlocation[8]+img_location,thunderdir);*/


TalentWidget::TalentWidget(const QPoint img_location, const char **dirset):
    Abstract_obj(img_location,2,dirset),QRect(img_location,QSize(90,90)){}


Scene_bag::Scene_bag():QRect(img_location,QSize(312,381)),
    MP(MAXMP),bag(":/others/image/others/bag.png"),
    Red(rlocation[0]+img_location,reddir),
    Blue(rlocation[1]+img_location,bluedir),
    Cure(rlocation[2]+img_location,curedir),
    Firefree(rlocation[3]+img_location,firefreedir),
    Archer(rlocation[4]+img_location,archerdir),
    Shooter(rlocation[5]+img_location,shooterdir),
    Frozen(rlocation[6]+img_location,frozendir),
    Hail(rlocation[7]+img_location,haildir),
    Thunder(rlocation[8]+img_location,thunderdir),
    pTalent(new TalentWidget*[talentNum]{&Red,&Blue,&Cure,
    &Firefree,&Archer,&Shooter,&Frozen,&Hail,&Thunder})
{
    for(int i=0;i<talentNum;i++)
    {
        widgetLeft[i]=0;
    }
}
    /*Frozen(rlocation[0]+img_location,&talentdir[0]),
    Hail(rlocation[1]+img_location,&talentdir[2]),
    Thunder(rlocation[2]+img_location,&talentdir[4]),
    Firefree(rlocation[3]+img_location,&talentdir[6]),
    Red(rlocation[4]+img_location,&talentdir[8]),
    Archer(rlocation[5]+img_location,&talentdir[10]),
    Cure(rlocation[6]+img_location,&talentdir[12]),
    Blue(rlocation[7]+img_location,&talentdir[14]),
    Shooter(rlocation[8]+img_location,&talentdir[16])*/


void Scene_bag::addWidgetNum(TalentType tp)
{
    if(tp<4)
        widgetLeft[tp]++;
}

void Scene_bag::draw(QPainter &p)
{
    p.drawImage(img_location,bag);
    for(int i=0;i<talentNum;i++)
    {
        if(i<4)
        {
            if(widgetLeft[i]>0)  pTalent[i]->drawImage(p,1);
            else pTalent[i]->drawImage(p,0);
        }
        else
        {
            if(MP<talentCost[i]) pTalent[i]->drawImage(p,0);
            else pTalent[i]->drawImage(p,1);
        }
    }
    /*if(redNum>0) Red.drawImage(p,1);
    else Red.drawImage(p,0);
    if(blueNum>0) Blue.drawImage(p,1);
    else Blue.drawImage(p,0);
    if(firefreeNum>0) Firefree.drawImage(p,1);
    else Firefree.drawImage(p,0);
    if(cureNum>0) Cure.drawImage(p,1);
    else Cure.drawImage(p,0);
    if(MP<shooterCost) Shooter.drawImage(p,0);
    else Shooter.drawImage(p,1);
    if(MP<archerCost) Archer.drawImage(p,0);
    else Archer.drawImage(p,1);
    if(MP<thunderCost) Thunder.drawImage(p,0);
    else Thunder.drawImage(p,1);
    if(MP<hailCost) Hail.drawImage(p,0);
    else Hail.drawImage(p,1);
    if(MP<frozenCost) Frozen.drawImage(p,0);
    else Frozen.drawImage(p,1);*/
}

void Scene_bag::changeMP(TalentType tp)
{
    changeMP(-talentCost[tp]);
}

void Scene_bag::changeMP(int amount)
{
    if(amount>0)
    {
        if(MP+amount<MAXMP)
            MP+=amount;
        else MP=MAXMP;
    }
    else
    {
        if(MP+amount>0)
            MP+=amount;
        else MP=0;
    }
    emit setMP(MP);
}


TalentType Scene_bag::mousePress(const QPoint &pos)
{
    emit disableBag();
    for(int i=0;i<talentNum;i++)
    {
        if(i<4)
        {
            if(pTalent[i]->contains(pos)&&widgetLeft[i]>0)
            {
                widgetLeft[i]--;
                return (TalentType)i;
            }
        }
        else
        {
            if(pTalent[i]->contains(pos)&&MP>=talentCost[i])
            {
                return (TalentType)i;
            }
        }
    }
    return nothing;
}
