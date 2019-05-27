#include "inimigo.h"
#include "game.h"
#include "jogador.h"
#include "chao.h"
#include "tiro.h"
#include "tiroinimigo.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QtDebug>
#include <QList>

extern Game * game;

Inimigo::Inimigo(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/imagens/imagens/inimigo.png"));
    setPos(200+rand()%400,100+ rand()%350);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(500);

    QTimer * atira_timer = new QTimer(this);
    connect(atira_timer,SIGNAL(timeout()),this,SLOT(atira()));
    atira_timer->start(500);

}

void Inimigo::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Inimigo::move(){

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


void Inimigo::atira(){
    TiroInimigo * tiroInimigo = new TiroInimigo();

    tiroInimigo ->setPos(this->x()+10,this->y()+10);
    tiroInimigo ->setRotation(rotation()+rand()%20-rand()%20);
    tiroInimigo ->setVelocidade(30);
    tiroInimigo ->setAlcance(10);
    scene()->addItem(tiroInimigo);

}
