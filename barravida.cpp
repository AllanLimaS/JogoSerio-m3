#include "barravida.h"
#include <QGraphicsScene>

BarraVida::BarraVida()
{


}

void BarraVida::setValores(int Max, int Vida){

    this->maxLifeBar.setRect(300,550,Max*30, 20);
    this->maxLifeBar.setBrush(QBrush(Qt::darkRed));
    scene()->addItem(&maxLifeBar);

    this->lifeBar.setRect(300,550,Vida*30,20);
    this->lifeBar.setBrush(QBrush(Qt::red));
    scene()->addItem(&lifeBar);

}
