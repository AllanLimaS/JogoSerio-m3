#ifndef BARRAVIDA_H
#define BARRAVIDA_H
#include <QGraphicsRectItem>

class BarraVida : public QGraphicsRectItem
{
public:

    QGraphicsRectItem * maxLifeBar;
    QGraphicsRectItem *lifeBar;

    QGraphicsRectItem * maxArmorBar;
    QGraphicsRectItem *armorBar;

    BarraVida();
    void setValores(int Max, int Vida, int MaxA, int armor);

};

#endif // BARRAVIDA_H
