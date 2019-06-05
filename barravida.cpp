#include "barravida.h"
#include "game.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>

extern Game * game;

BarraVida::BarraVida()
{
    maxLifeBar = new QGraphicsRectItem();
    lifeBar = new QGraphicsRectItem();
    maxArmorBar = new QGraphicsRectItem();
    armorBar = new QGraphicsRectItem();

    maxLifeBar->setRect(300,550,30, 20);
    maxLifeBar->setBrush(QBrush(Qt::darkRed));

    lifeBar->setRect(300,550,30,20);
    lifeBar->setBrush(QBrush(Qt::red));

    maxArmorBar->setRect(300,570,30, 20);
    maxArmorBar->setBrush(QBrush(Qt::gray));

    armorBar->setRect(300,570,30,20);
    armorBar->setBrush(QBrush(Qt::blue));

}

void BarraVida::setValores(int Max, int Vida, int MaxA, int armor){

    maxLifeBar->setRect(300,550,Max*30, 20);
    lifeBar->setRect(300,550,Vida*30,20);
    maxArmorBar->setRect(300,570,MaxA*3, 20);
    armorBar->setRect(300,570,armor*3,20);
}
