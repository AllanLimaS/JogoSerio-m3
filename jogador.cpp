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

QPointF Jogador::getPos(){
    return QPointF(this->x(),this->y());
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
    update();   //nao sei ao certo pra que serve isso asuydhaudshaushd

    if (event->key() == Qt::Key_Escape){    //quita do game quando o jogador está focado
        exit(1);
    }

    if (event->key() == Qt::Key_Up){        //tiro pra cima
        Tiro * tiro = new Tiro();               //cria
        tiro->setPos(this->x()+10,this->y()+10);//posiciona ele em cima do jogador
        tiro->setRotation(260+rand()%20-rand()%20);     //seta a angulagem do tiro , o rand ali eh pra o tiro nao sair retinho
        tiro->setVelocidade(this->velocidadeTiro);//^^ para deixr o tiro retinho eh só deixar os setRotation em multiplos de 90
        tiro->setAlcance(this->alcanceTiro);
        scene()->addItem(tiro);
    }
    if (event->key() == Qt::Key_Down){      //tiro pra baixo
        Tiro * tiro = new Tiro();
        tiro->setPos(this->x()+10,this->y()+10);
        tiro->setRotation(90+rand()%20-rand()%20);
        tiro->setVelocidade(this->velocidadeTiro);
        tiro->setAlcance(this->alcanceTiro);
        scene()->addItem(tiro);
    }
    if (event->key() == Qt::Key_Right){     //tiro pra direita
        Tiro * tiro = new Tiro();
        tiro->setPos(this->x()+10,this->y()+10);
        tiro->setRotation(0+rand()%20-rand()%20);
        tiro->setVelocidade(this->velocidadeTiro);
        tiro->setAlcance(this->alcanceTiro);
        scene()->addItem(tiro);
    }
    if (event->key() == Qt::Key_Left){      //tiro pra esquerda
        Tiro * tiro = new Tiro();
        tiro->setPos(this->x()+10,this->y()+10);
        tiro->setRotation(180+rand()%20-rand()%20);
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
