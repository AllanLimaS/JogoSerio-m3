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
extern Jogador * jogador;

Inimigo::Inimigo(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

}

void Inimigo::Normal(){
    setPixmap(QPixmap(":/imagens/imagens/inimigo.png"));
    setPos(200+rand()%400,100+ rand()%350);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(500);

    QTimer * atira_timer = new QTimer(this);
    connect(atira_timer,SIGNAL(timeout()),this,SLOT(atira()));
    atira_timer->start(1500);
}

void Inimigo::Metralha(){
    setPixmap(QPixmap(":/imagens/imagens/inimigo.png"));
    setPos(200+rand()%400,100+ rand()%350);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(500);

    QTimer * atira_timer = new QTimer(this);
    connect(atira_timer,SIGNAL(timeout()),this,SLOT(atiraMetralha()));
    atira_timer->start(160);
}


void Inimigo::Inimigo12(){
    setPixmap(QPixmap(":/imagens/imagens/inimigo.png"));
    setPos(200+rand()%400,100+ rand()%350);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(400);

    QTimer * atira_timer = new QTimer(this);
    connect(atira_timer,SIGNAL(timeout()),this,SLOT(atiraDeDoze()));
    atira_timer->start(2500);

}

void Inimigo::Sniper(){
    setPixmap(QPixmap(":/imagens/imagens/inimigo.png"));
    setPos(200+rand()%400,100+ rand()%350);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(4000);

    QTimer * atira_timer = new QTimer(this);
    connect(atira_timer,SIGNAL(timeout()),this,SLOT(atiraSniper()));
    atira_timer->start(2800);

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
    tiroInimigo ->setVelocidade(15);
    tiroInimigo ->setAlcance(10);
    scene()->addItem(tiroInimigo);

}

void Inimigo::atiraMetralha(){
    TiroInimigo * tiroInimigo = new TiroInimigo();

    tiroInimigo ->setPos(this->x()+10,this->y()+10);
    tiroInimigo ->setRotation(rotation()+rand()%20-rand()%20);
    tiroInimigo ->setVelocidade(18);
    tiroInimigo ->setAlcance(2);
    scene()->addItem(tiroInimigo);
}

void Inimigo::atiraSniper(){
    TiroInimigo * tiroInimigo = new TiroInimigo();

    QList<QGraphicsItem *> colliding_items = scene()->items();
    for(int  i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i]))== typeid (Jogador)){
                rotateToPoint(colliding_items[i]->pos());
        }
    }

    tiroInimigo ->setPos(this->x()+10,this->y()+10);
    tiroInimigo ->setRotation(rotation()+rand()%1-rand()%1);
    tiroInimigo ->setVelocidade(30);
    tiroInimigo ->setAlcance(2);
    scene()->addItem(tiroInimigo);
}

void Inimigo::atiraDeDoze(){
    TiroInimigo * tiroInimigo = new TiroInimigo();
    TiroInimigo * tiroInimigo2 = new TiroInimigo();
    TiroInimigo * tiroInimigo3 = new TiroInimigo();

    tiroInimigo ->setPos(this->x()+10,this->y()+10);
    tiroInimigo2 ->setPos(this->x()+10,this->y()+10);
    tiroInimigo3 ->setPos(this->x()+10,this->y()+10);

    tiroInimigo ->setRotation(rotation()+rand()%30-rand()%30);
    tiroInimigo2 ->setRotation(rotation()+rand()%30-rand()%30);
    tiroInimigo3 ->setRotation(rotation()+rand()%30-rand()%30);

    tiroInimigo ->setVelocidade(10);
    tiroInimigo2 ->setVelocidade(10);
    tiroInimigo3 ->setVelocidade(10);

    tiroInimigo ->setAlcance(10);
    tiroInimigo2 ->setAlcance(10);
    tiroInimigo3 ->setAlcance(10);

    scene()->addItem(tiroInimigo);
    scene()->addItem(tiroInimigo2);
    scene()->addItem(tiroInimigo3);
}
