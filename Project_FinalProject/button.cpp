#include "button.h"

Button::Button(const QRect &rect,const char **dirset):
    Abstract_obj(rect.topLeft(),3,dirset),QRect(rect),_index(0){}

void Button::draw(QPainter &p)
{
    drawImage(p,_index);
    switch (_index) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        _index=1;
        emit clicked();
        break;
    }
}
