#include "tiro.h"
#include "parede.h"
#include "game.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QtDebug>

    extern Game * game;

    void Tiro::setVelocidade(int value)
    {
        velocidade = value;
    }

    void Tiro::setAlcance(int value)
    {
        this->alcance = value;
    }

    int Tiro::getAlcance() const
    {
        return alcance;
    }

Tiro::Tiro(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/imagens/imagens/tiro.png"));

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
    qDebug()<<this->alcance;
    qDebug()<<getAlcance();

    QTimer * deleta_timer = new QTimer(this);
    connect(deleta_timer,SIGNAL(timeout()),this,SLOT(deleta()));
    deleta_timer->start(500);



}

void Tiro::move(){

    int STEP_SIZE = this->velocidade;
    double theta = rotation();
    double dy = STEP_SIZE * qSin(( theta * M_PI ) / 180);
    double dx = STEP_SIZE * qCos(( theta * M_PI ) / 180);

    setPos(x()+dx, y()+dy);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int  i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i]))== typeid (Parede)){
         //   delete (this);
        }
    }
}

void Tiro::deleta()
{
    delete (this);
}
