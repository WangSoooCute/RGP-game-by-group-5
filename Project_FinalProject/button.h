#ifndef BUTTON_H
#define BUTTON_H

#include <QRect>
#include "abstract_obj.h"

//button的dirset统一规定顺序：
//第一张代表正常按钮图片
//第二张为鼠标浮在按钮上方
//第三张为鼠标按下
//QRect里的函数和abstract_obj的函数都可以直接使用
//对于button 定义rlocation=0,obj_location=img_location

class Button : public Abstract_obj,private QRect
{
    Q_OBJECT
signals:
    void clicked(void);
private:
    int _index;
//index代表画哪一张 0 正常按钮 1 浮动按钮 2 按压按钮
public:
    Button(const QRect & rect, const char **dirset);
    bool contains(const QPoint &p)const {return QRect::contains(p);}
    int width() const {return QRect::width();}
    int height() const {return QRect::height();}
    const QPoint topLeft() const {return QRect::topLeft();}
    void setFloat() {_index=1;}
    void setPressed() {_index=2;}
    void setNormal() {_index=0;}
    void draw(QPainter &p);
};

#endif // BUTTON_H
