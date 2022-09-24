#ifndef SCENE_BAG_H
#define SCENE_BAG_H

#include <QObject>
#include <QRect>
#include <QImage>
#include "abstract_obj.h"
#include "constant.h"


class TalentWidget :public Abstract_obj,private QRect
{
public:
    TalentWidget(const QPoint img_location, const char **dirset);
    bool contains(const QPoint &pos) {return QRect::contains(pos);}
    void drawImage(QPainter &p, int index) {Abstract_obj::drawImage(p,index);}
};


class Scene_bag : public QObject,private QRect
{
    Q_OBJECT
public:
    Scene_bag();
    ~Scene_bag(){delete []pTalent;}
    void draw(QPainter &p);
    TalentType mousePress(const QPoint &pos);
    void addWidgetNum(TalentType tp);
    void changeMP(TalentType tp);
    void changeMP(int amount);
    void resetMP(void){MP=MAXMP;emit setMP(MP);}
private:
    int MP;
    int widgetLeft[9];
    QImage bag;
    TalentWidget Red;
    TalentWidget Blue;
    TalentWidget Cure;
    TalentWidget Firefree;
    TalentWidget Archer;
    TalentWidget Shooter;
    TalentWidget Frozen;
    TalentWidget Hail;
    TalentWidget Thunder;
    TalentWidget **pTalent;
signals:
    void disableBag(void);
    void setMP(int newMP);
public slots:
};



#endif // SCENE_BAG_H
