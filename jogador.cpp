#include "parede.h"
#include "game.h"
#include "jogador.h"
#include "tiro.h"
#include "escada.h"
#include "inimigo.h"
#include "upgrades.h"
#include "menu.h"

#include <QSound>
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsRectItem>
#include <QList>
#include <QtDebug>
#include <qtimer.h>

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

void Jogador::setPontosUpgrade(int value)
{
    pontosUpgrade = value;
}

int Jogador::getPontosUpgrade() const
{
    return pontosUpgrade;

}

void Jogador::atirar(){
    podeAtirar = true;
}

void Jogador::verificaDano()
{
    if(game->getTIRAO() == 1){
        if(getVida() > game->getDANO()){
            setVida(getVida() - game->getDANO());
            game->setTIRAO(0);
        } else {
            game->close(); // FIM TEMPORARIO
        }
    }
}

void Jogador::acao(){

//________________________________________MOVIMENTO________________________________________//

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

//________________________________________TIRO________________________________________//

    if (this->TiroUp==true){                //tiro pra cima
        if(podeAtirar==true){
            Tiro * tiro = new Tiro();                   //cria
            tiro->setPos(this->x()+10,this->y()+10);    //posiciona ele em cima do jogador
            tiro->setRotation(260+rand()%20-rand()%20); //seta a angulagem do tiro , o rand ali eh pra o tiro nao sair retinho
            tiro->setVelocidade(this->velocidadeTiro);  //^^ para deixr o tiro retinho eh só deixar os setRotation em multiplos de 90
            scene()->addItem(tiro);
            podeAtirar=false;
            QSound::play(":/audios/glock.wav");
        }
    }
    if (this->TiroDown==true){      //tiro pra baixo
        if(podeAtirar==true){
            Tiro * tiro = new Tiro();
            tiro->setPos(this->x()+10,this->y()+10);
            tiro->setRotation(90+rand()%20-rand()%20);
            tiro->setVelocidade(this->velocidadeTiro);
            scene()->addItem(tiro);
            podeAtirar=false;
            QSound::play(":/audios/glock.wav");
        }
    }
    if (this->TiroRight==true){     //tiro pra direita
        if(podeAtirar==true){
            Tiro * tiro = new Tiro();
            tiro->setPos(this->x()+10,this->y()+10);
            tiro->setRotation(0+rand()%20-rand()%20);
            tiro->setVelocidade(this->velocidadeTiro);
            scene()->addItem(tiro);
            podeAtirar=false;
            QSound::play(":/audios/glock.wav");
        }
    }
    if (this->TiroLeft==true){      //tiro pra esquerda
        if(podeAtirar==true){
            Tiro * tiro = new Tiro();
            tiro->setPos(this->x()+10,this->y()+10);
            tiro->setRotation(180+rand()%20-rand()%20);
            tiro->setVelocidade(this->velocidadeTiro);
            scene()->addItem(tiro);
            podeAtirar=false;
            QSound::play(":/audios/glock.wav");
        }
    }

//___________________________________________FASE-NOVA___________________________________________//


    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int  i = 0, n = colliding_items.size(); i < n; i++){

        if(typeid(*(colliding_items[i])) == typeid (Escada)){

            QList<QGraphicsItem *> colliding_items = scene()->items();
            for(int  i = 0, n = colliding_items.size(); i < n; i++){
                if(typeid(*(colliding_items[i]))== typeid (Inimigo)){
                    //TEM INIMIGO AINDA N PODE SAIR
                    TemInimigo = 1;
                }
            }
            if(TemInimigo == 0){ // CASO N TENHA ELE PASSA PELA PORTA

                setPos(600,263);
                PisoAtual = PisoAtual + 1;

                if(PisoAtual % 5 == 0){
                    Upgrades * upgrades = new Upgrades();
                    scene()->addItem(upgrades);

                }else{

                    QList<QGraphicsItem *> colliding_items = scene()->items();
                    for(int  i = 0, n = colliding_items.size(); i < n; i++){
                        if(typeid(*(colliding_items[i]))== typeid (Upgrades)){ // sempre procura uma placa para deletar
                            scene()->removeItem(colliding_items[i]);
                            delete (colliding_items[i]);
                        }
                    }

                    int select = rand() % 4;
                    int Quant = rand() % 3;
                    switch(select){
                    case 0:
                        for(int i =0; i<=Quant; i++){
                            Inimigo * inimigo = new Inimigo();  // CRIA NOVO INIMIGO
                            inimigo->Normal();
                            scene()->addItem(inimigo);
                        }

                        break;
                    case 1:

                        for(int i =0; i<=Quant; i++){
                            Inimigo * inimigo = new Inimigo();  // CRIA NOVO INIMIGO
                            inimigo->Inimigo12();
                            scene()->addItem(inimigo);
                        }

                        break;
                    case 2:

                        for(int i =0; i<=Quant; i++){
                            Inimigo * inimigo = new Inimigo();  // CRIA NOVO INIMIGO
                            inimigo->Metralha();
                             scene()->addItem(inimigo);
                        }

                        break;
                    case 3:
                        for(int i =0; i<=Quant; i++){
                            Inimigo * inimigo = new Inimigo();  // CRIA NOVO INIMIGO
                            inimigo->Sniper();
                             scene()->addItem(inimigo);
                        }

                        break;
                    default:
                        for(int i =0; i<=Quant; i++){
                            Inimigo * inimigo = new Inimigo();  // CRIA NOVO INIMIGO
                            inimigo->Normal();
                             scene()->addItem(inimigo);
                        }

                        break;
                    }
                }

                setPontosUpgrade(getPontosUpgrade() + 1);   // GANHA PONTOS DE UPGRADE

            } else {

                TemInimigo = 0; //ZERA A VARIAVEL DNV
            }
        }
    }
}

int Jogador::getPisoAtual() const
{
    return PisoAtual;
}

int Jogador::getVida() const
{
    return Vida;
}

void Jogador::setVida(int value)
{
    Vida = value;
}

int Jogador::getMaxVida() const
{
    return MaxVida;
}

void Jogador::setMaxVida(int value)
{
    MaxVida = value;
}

int Jogador::getDanoSofrido() const
{
    return DanoSofrido;
}

void Jogador::setDanoSofrido(int value)
{
    DanoSofrido = value;
}

Jogador::Jogador(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagens/imagens/player.png"));
    this->setVelocidadeTiro(15);
    this->setVelocidadeMovimento(10);

    QTimer * atirar_timer = new QTimer(this);
    connect(atirar_timer,SIGNAL(timeout()),this,SLOT(atirar()));    //timer para deletar a bala
    atirar_timer->start(250);

    QTimer * acao_timer = new QTimer(this);
    connect(acao_timer,SIGNAL(timeout()),this,SLOT(acao()));    //timer para deletar a bala
    acao_timer->start(50);

    QTimer * verifica_timer = new QTimer(this);
    connect(verifica_timer,SIGNAL(timeout()),this,SLOT(verificaDano()));    //timer para deletar a bala
    verifica_timer->start(1);

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
    update();   //nao sei ao certo pra que serve isso asuydhaudshaushd

    if (event->key() == Qt::Key_Escape){    //quita do game quando o jogador está focado
        game->close();

        // OBS: O JOGO NAO MORRE AQUI , ELE SIMPLESMENTE "MINIMIZA"

        Menu * menu = new Menu();
        menu->show();
    }

    if (event->key() == Qt::Key_Up){                //tiro pra cima
        this->TiroUp = true;
    }
    if (event->key() == Qt::Key_Down){      //tiro pra baixo
        this->TiroDown = true;
    }
    if (event->key() == Qt::Key_Right){     //tiro pra direita
        this->TiroRight = true;
    }
    if (event->key() == Qt::Key_Left){      //tiro pra esquerda
        this->TiroLeft = true;
    }

    QList<QGraphicsItem *> colliding_items = scene()->items();
    for(int  i = 0, n = colliding_items.size(); i < n; i++){        // VE SE ESTA NO PISO DE UP
        if(typeid(*(colliding_items[i]))== typeid (Upgrades)){

            if (event->key() == Qt::Key_1){
                if(getPontosUpgrade() >= 5){
                    if(getVida() < 12){                              // RECUPERA VIDA
                        setVida(getMaxVida());
                        setPontosUpgrade(getPontosUpgrade() - 5);
                    }
                }
            }
            if (event->key() == Qt::Key_2){
                if(getPontosUpgrade() > 0){
                    setVelocidadeMovimento(getVelocidadeMovimento()+1); //ANDA MAIS RAPIDO
                    setPontosUpgrade(getPontosUpgrade() - 1);
                }

            }
            if (event->key() == Qt::Key_3){
                if(getPontosUpgrade() > 0){
                    // UPA ALGO
                    setPontosUpgrade(getPontosUpgrade() - 1);
                }

            }

        }

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

    if (event->key() == Qt::Key_Up){
        this->TiroUp = false;
    }
    if (event->key() == Qt::Key_Down){
        this->TiroDown = false;
    }
    if (event->key() == Qt::Key_Right){
        this->TiroRight = false;
    }
    if (event->key() == Qt::Key_Left){
        this->TiroLeft = false;
    }

    update();
}

