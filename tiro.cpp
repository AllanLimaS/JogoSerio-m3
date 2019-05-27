#include "tiro.h"
#include "parede.h"
#include "game.h"
#include "inimigo.h"
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

    int Tiro::getVelocidade() const
    {
        return velocidade;
    }

    Tiro::Tiro(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/imagens/imagens/tiro.png"));

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));    //timer pra realizar cada movimento
    move_timer->start(50);

    QTimer * deleta_timer = new QTimer(this);
    connect(deleta_timer,SIGNAL(timeout()),this,SLOT(deleta()));    //timer para deletar a bala
    deleta_timer->start(500);



}

void Tiro::move(){

    int STEP_SIZE = this->velocidade;
    double theta = rotation();
    double dy = STEP_SIZE * qSin(( theta * M_PI ) / 180);       //conta para faze o movimento com angulação
    double dx = STEP_SIZE * qCos(( theta * M_PI ) / 180);

    setPos(x()+dx, y()+dy);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int  i = 0, n = colliding_items.size(); i < n; i++){

        if(typeid(*(colliding_items[i]))== typeid (Parede)){
         //   delete (this);
        }
        if(typeid(*(colliding_items[i]))== typeid (Inimigo)){
            scene()->removeItem(colliding_items[i]);
            delete (colliding_items[i]);    //mata inimigo
            delete (this);
        }
    }
}

void Tiro::deleta()
{
    delete (this);
}
