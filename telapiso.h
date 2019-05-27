#ifndef TELAPISO_H
#define TELAPISO_H


#include "QGraphicsTextItem"


class TelaPiso: public QGraphicsTextItem
{
private:
    int piso;
public:
    TelaPiso(QGraphicsTextItem * parent = 0);
    void setPiso(int value);
};
#endif // TELAPISO_H
