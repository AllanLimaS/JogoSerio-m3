#include "barravida.h"
#include "game.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>

extern Game * game;

BarraVida::BarraVida()
{
    maxLifeBar = new QGraphicsRectItem();
    lifeBar = new QGraphicsRectItem();

    maxLifeBar->setRect(300,550,30, 20);
    maxLifeBar->setBrush(QBrush(Qt::darkRed));

    lifeBar->setRect(300,550,30,20);
    lifeBar->setBrush(QBrush(Qt::red));

}

void BarraVida::setValores(int Max, int Vida){

    maxLifeBar->setRect(300,550,Max*30, 20);
    lifeBar->setRect(300,550,Vida*30,20);

}
