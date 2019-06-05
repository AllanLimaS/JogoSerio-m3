#include "game.h"
#include "parede.h"
#include "chao.h"
#include "tiro.h"
#include "jogador.h"
#include "inimigo.h"
#include "escada.h"
#include "barravida.h"

#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QDebug>

int Game::getTIRAO() const
{
    return TIRAO;
}

void Game::setTIRAO(int value)
{
    TIRAO = value;
}

int Game::getDANO() const
{
    return DANO;
}

void Game::setDANO(int value)
{
    DANO = value;
}

int Game::getDanoJogador() const
{
    return DanoJogador;
}

void Game::setDanoJogador(int value)
{
    DanoJogador = value;
}

void Game::criaMapa(){

//    QList<QGraphicsItem *> colliding_items = scene->items();
//    for(int  i = 0, n = colliding_items.size(); i < n; i++){
//        if(typeid(*(colliding_items[i]))== typeid (Parede)){    BAGULHO QUEBRADO TALVEZ TENTAR ARRUMAR
//            scene->removeItem(colliding_items[i]);
//            delete (colliding_items[i]);

//        }
//        if(typeid(*(colliding_items[i]))== typeid (Chao)){
//            scene->removeItem(colliding_items[i]);
//            delete (colliding_items[i]);
//        }
//    }

    switch(rand()%2){

    case 0:     // mapa original
        for(int i = 0; i<13; i++){
            for(int j = 0; j<13; j++){
                if(i==0||j==0||i==12||j==12){
                    Parede * parede = new Parede(i, j,0);
                    scene -> addItem(parede);
                } else {
                    Chao * chao = new Chao(i,j,0);
                    scene->addItem(chao);
                }
            }
        }
        scene->setBackgroundBrush(QPixmap(":/imagens/imagens/parede.png"));
        break;

    case 1:    //dust
        for(int i = 0; i<13; i++){
            for(int j = 0; j<13; j++){
                if(i==0||j==0||i==12||j==12){
                    Parede * parede = new Parede(i, j,1);
                    scene -> addItem(parede);
                } else {
                    Chao * chao = new Chao(i,j,1);
                    scene->addItem(chao);
                }

            }
        }
        scene->setBackgroundBrush(QPixmap(":/tiles/imagens/mapas/dust_parede2.bmp"));
        break;
    }
}

int Game::getARMAO() const
{
    return ARMAO;
}

void Game::setARMAO(int value)
{
    ARMAO = value;
}

Game::Game():QGraphicsView(){

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    criaMapa(); //randomiza o mapa e cria

    telaPiso = new TelaPiso();
    scene->addItem(telaPiso);

    barraVida = new BarraVida();
    scene->addItem(barraVida->maxLifeBar);
    scene->addItem(barraVida->lifeBar);
    scene->addItem(barraVida->maxArmorBar);
    scene->addItem(barraVida->armorBar);

    jogador = new Jogador();
    scene->addItem(jogador);
    jogador->setPos(550,263);
    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Escada * escada = new Escada();
    scene->addItem(escada);
    escada->setZValue(2);       //seta prioridade do print

    QTimer * atualiza_timer = new QTimer(this);
    connect(atualiza_timer,SIGNAL(timeout()),this,SLOT(atualizaTela()));    //timer pra realizar cada movimento
    atualiza_timer->start(50);
}

void Game::atualizaTela(){
    telaPiso->setValores(jogador->getPisoAtual(),jogador->getPontosUpgrade());
    barraVida->setValores(jogador->getMaxVida(), jogador->getVida(), jogador->getMaxArmor(), jogador->getArmor());

}

