#include "parede.h"
#include "game.h"
#include "jogador.h"
#include "tiro.h"
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsRectItem>
#include <QList>
#include <QtDebug>

extern Game * game;

int Jogador::getVelocidadeTiro() const
{
    return velocidadeTiro;
}

void Jogador::setVelocidadeTiro(int value)
{
    velocidadeTiro = value;
}

int Jogador::getVelocidadeMovimento() const
{
    return velocidadeMovimento;
}

void Jogador::setVelocidadeMovimento(int value)
{
    velocidadeMovimento = value;
}

void Jogador::setAlcanceTiro(int value)
{
    alcanceTiro = value;
}

int Jogador::getAlcanceTiro() const
{
    return alcanceTiro;
}

Jogador::Jogador(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagens/imagens/player.png"));
    this->setVelocidadeTiro(50);
    this->setVelocidadeMovimento(10);
    this->setAlcanceTiro(10);        // nao funciona por algum motivo

}

void Jogador::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_A){
        this->Left = true;
    }

    if (event->key() == Qt::Key_D){
        this->Right = true;
    }

    if (event->key() == Qt::Key_W){
        this->Up = true;
    }

    if (event->key() == Qt::Key_S){
        this->Down = true;
    }
    movimento();
    update();

    if (event->key() == Qt::Key_Escape){
        exit(1);
    }

    if (event->key() == Qt::Key_Up){
        Tiro * tiro = new Tiro();
        tiro->setPos(this->x()+10,this->y()+10);
        tiro->setRotation(250 + rand()%30);
        tiro->setVelocidade(this->velocidadeTiro);
        tiro->setAlcance(this->alcanceTiro);
        scene()->addItem(tiro);
    }
    if (event->key() == Qt::Key_Down){
        Tiro * tiro = new Tiro();
        tiro->setPos(this->x()+10,this->y()+10);
        tiro->setRotation(70 + rand()%30);
        tiro->setVelocidade(this->velocidadeTiro);
        tiro->setAlcance(this->alcanceTiro);
        scene()->addItem(tiro);
    }
    if (event->key() == Qt::Key_Right){
        Tiro * tiro = new Tiro();
        tiro->setPos(this->x()+10,this->y()+10);
        tiro->setRotation(-10 +rand()%30);
        tiro->setVelocidade(this->velocidadeTiro);
        tiro->setAlcance(this->alcanceTiro);
        scene()->addItem(tiro);
    }
    if (event->key() == Qt::Key_Left){
        Tiro * tiro = new Tiro();
        tiro->setPos(this->x()+10,this->y()+10);
        tiro->setRotation(160 + rand()%30);
        tiro->setVelocidade(this->velocidadeTiro);
        tiro->setAlcance(this->alcanceTiro);
        scene()->addItem(tiro);
    }

}

void Jogador::keyReleaseEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_A){
        this->Left = false;
    }

    if (event->key() == Qt::Key_D){
        this->Right = false;
    }

    if (event->key() == Qt::Key_W){
        this->Up = false;
    }

    if (event->key() == Qt::Key_S){
        this->Down = false;
    }
    movimento();
    update();
}

void Jogador::movimento(){

    if (this->Up==true){
        setPos(x(),y()-this->velocidadeMovimento);
        setPixmap(QPixmap(":/imagens/imagens/player_up.png"));
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int  i = 0, n = colliding_items.size(); i < n; i++){
            if(typeid(*(colliding_items[i]))== typeid (Parede)){
                setPos(x(),y()+this->velocidadeMovimento);
            }else{
                setPos(x(),y());
            }
        }


    }

    if(this->Down==true){
        setPos(x(),y()+this->velocidadeMovimento);
        setPixmap(QPixmap(":/imagens/imagens/player_down.png"));
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int  i = 0, n = colliding_items.size(); i < n; i++){
            if(typeid(*(colliding_items[i]))== typeid (Parede)){
                setPos(x(),y()-this->velocidadeMovimento);
            }else{
                setPos(x(),y());
            }
        }
    }
    if(this->Right==true){
        setPos(x()+this->velocidadeMovimento,y());
        setPixmap(QPixmap(":/imagens/imagens/player_right.png"));
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int  i = 0, n = colliding_items.size(); i < n; i++){
            if(typeid(*(colliding_items[i]))== typeid (Parede)){
                setPos(x()-this->velocidadeMovimento,y());
            }else{
                setPos(x(),y());
            }
        }
    }
    if(this->Left==true){
        setPos(x()-this->velocidadeMovimento,y());
        setPixmap(QPixmap(":/imagens/imagens/player_left.png"));
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int  i = 0, n = colliding_items.size(); i < n; i++){
            if(typeid(*(colliding_items[i]))== typeid (Parede)){
                setPos(x()+this->velocidadeMovimento,y());
            }else{
                setPos(x(),y());
            }
        }
    }
}
