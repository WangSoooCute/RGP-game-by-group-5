#ifndef ABSTRACT_OBJ_H
#define ABSTRACT_OBJ_H

#include <QObject>
#include <QImage>
#include <QPoint>
#include <QPainter>

class Abstract_obj:public QObject
{
private:
    int _img_num;
    bool _deletable;
    QPoint _obj_location;
    QPoint _img_location;
    QImage *_pimg;
public:
    Abstract_obj(const QPoint & obj_location,const int img_num, const char *const*dir_set,const QPoint &rlocation=QPoint());
    const QPoint& getObj_location()const {return _obj_location;}
    int getObj_locationX(void)const {return _obj_location.x();}
    int getObj_locationY(void)const {return _obj_location.y();}
    const QPoint & getImg_location()const {return _img_location;}
    int getImgX()const {return _pimg[0].width();}
    int getImgY()const {return _pimg[0].height();}
    int ObjDistanceWith(const Abstract_obj & obj)const;
    bool isDeletable(void)const {return _deletable;}
    virtual ~Abstract_obj(){delete []_pimg;}
protected:
    virtual void drawImage(QPainter &p,int index);    
    void setObj_location(const QPoint & obj_location);
    virtual void deleteIt(void) {_deletable=true;}
};


#endif // ABSTRACT_OBJ_H
