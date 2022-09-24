#ifndef SCENE_HOME_H
#define SCENE_HOME_H

#include "button.h"
#include <QObject>
#include <QPoint>
#include <QPainter>

class Scene_home:public QObject
{
    Q_OBJECT
public:
    Scene_home();
    void mouseMove(const QPoint &pos){}
    bool mousePress(const QPoint &pos){return false;}
    void draw(QPainter &p);
private:
    QImage _background;
};

#endif // SCENE_HOME_H
