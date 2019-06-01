#include "boss.h"
#include "jogador.h"
#include "tiro.h"
#include "game.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <qmath.h>

extern Game * game;

int Boss::getVidaBoss() const
{
    return VidaBoss;
}

void Boss::setVidaBoss(int value)
{
    VidaBoss = value;
}

Boss::Boss()
{

    setPixmap(QPixmap(":/imagens/imagens/placa.png"));
    setPos(341,91);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(1000);

    QTimer * verifica_timer = new QTimer(this);
    connect(verifica_timer,SIGNAL(timeout()),this,SLOT(verificaDano()));
    verifica_timer->start(10);

}

void Boss::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Boss::move(){

    QList<QGraphicsItem *> colliding_items = scene()->items();
    for(int  i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i]))== typeid (Jogador)){
                rotateToPoint(colliding_items[i]->pos());
        }
    }

    int STEP_SIZE = 10;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(( theta * M_PI ) / 180);       //conta para faze o movimento com angulação
    double dx = STEP_SIZE * qCos(( theta * M_PI ) / 180);

    setPos(x()+dx, y()+dy);
}

void Boss::verificaDano(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int  i = 0, n = colliding_items.size(); i < n; i++){

        if(typeid(*(colliding_items[i]))== typeid (Tiro)){
            setVidaBoss(getVidaBoss()-game->getDanoJogador());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }

    if(getVidaBoss() == 0){
        scene()->removeItem(this);
        delete  (this);
        return;
    }
}
