#ifndef BARRAVIDA_H
#define BARRAVIDA_H
#include <QGraphicsRectItem>

class BarraVida : public QGraphicsRectItem
{
public:

    QGraphicsRectItem * maxLifeBar;
    QGraphicsRectItem *lifeBar;

    BarraVida();
    void setValores(int Max, int Vida);

};

#endif // BARRAVIDA_H
