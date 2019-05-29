#ifndef TELAPISO_H
#define TELAPISO_H

#include "QGraphicsTextItem"



class TelaPiso: public QGraphicsTextItem
{
private:
    int piso = 0, PontosUpgrade = 0;

public:
    TelaPiso(QGraphicsTextItem * parent = 0);
    void setValores(int value, int value2);
};
#endif // TELAPISO_H
