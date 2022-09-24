#ifndef ICECONE_H
#define ICECONE_H
#include "thrown_obj.h"
#include "constant.h"

class Icecone : public Thrown_obj
{
public:
    Icecone(const QPoint &pos);
    void draw(QPainter &p);
    void process(Live_player & player);


private:
    int _range;
    int idx;
    int sleep_idx;
    bool timeControl;
};

#endif // ICECONE_H
