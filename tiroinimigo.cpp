#include "tiroinimigo.h"
#include "tiro.h"
#include "parede.h"
#include "jogador.h"
#include "game.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QtDebug>

extern Game * game;

TiroInimigo::TiroInimigo(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/imagens/imagens/tiroInimigo.png"));

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));    //timer pra realizar cada movimento
    move_timer->start(50);

    QTimer * deleta_timer = new QTimer(this);
    connect(deleta_timer,SIGNAL(timeout()),this,SLOT(deleta()));    //timer para deletar a bala
    deleta_timer->start(1000);

}

void TiroInimigo::setVelocidade(int value)
{
    this->velocidade = value    ;
}

void TiroInimigo::setAlcance(int value)
{
    this->alcance = value;
}

int TiroInimigo::getAlcance() const
{
    return this->alcance;
}

int TiroInimigo::getVelocidade() const
{
    return this->velocidade;
}

void TiroInimigo::move(){

    int STEP_SIZE = this->velocidade;
    double theta = rotation();
    double dy = STEP_SIZE * qSin(( theta * M_PI ) / 180);       //conta para faze o movimento com angulação
    double dx = STEP_SIZE * qCos(( theta * M_PI ) / 180);

    setPos(x()+dx, y()+dy);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int  i = 0, n = colliding_items.size(); i < n; i++){

        if(typeid(*(colliding_items[i]))== typeid (Parede)){
            scene()->removeItem(this);
            delete this;
            return;
        }

        if(typeid(*(colliding_items[i]))== typeid (Jogador)){
             game->setTIRAO(1);
             scene()->removeItem(this);
             delete this;
             return;
        }

        if(typeid(*(colliding_items[i]))== typeid (Tiro)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete (colliding_items[i]);
            delete (this);
            return;
        }
    }
}

void TiroInimigo::deleta()
{
    scene()->removeItem(this);
    delete (this);
}
