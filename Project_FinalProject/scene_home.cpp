#include "scene_home.h"

Scene_home::Scene_home():_background(QImage(":/background/image/map/home.jpg")){}

void Scene_home::draw(QPainter &p)
{
    p.drawImage(QPoint(0,0),_background);
}
