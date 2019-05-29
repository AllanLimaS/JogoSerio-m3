#ifndef BARRAVIDA_H
#define BARRAVIDA_H
#include <QGraphicsRectItem>

class BarraVida : public QGraphicsRectItem
{
private:
    QGraphicsRectItem maxLifeBar;
    QGraphicsRectItem lifeBar;
public:
    BarraVida();
    void setValores(int Max, int Vida);
};

#endif // BARRAVIDA_H
