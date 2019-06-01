#include "game.h"
#include "parede.h"
#include "chao.h"
#include "tiro.h"
#include "jogador.h"
#include "inimigo.h"
#include "escada.h"
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

Game::Game():QGraphicsView(){

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/imagens/imagens/parede.png"));

    for(int i = 0; i<13; i++){
        for(int j = 0; j<13; j++){
            if(i==0||j==0||i==12||j==12){
                Parede * parede = new Parede(i, j);
                scene -> addItem(parede);
            } else {
                Chao * chao = new Chao(i,j);
                scene->addItem(chao);
            }
        }
    }

    telaPiso = new TelaPiso();
    scene->addItem(telaPiso);

    barraVida = new BarraVida();
    scene->addItem(barraVida);

    jogador = new Jogador();
    scene->addItem(jogador);
    jogador->setPos(600,263);
    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Escada * escada = new Escada();
    scene->addItem(escada);

    QTimer * atualiza_timer = new QTimer(this);
    connect(atualiza_timer,SIGNAL(timeout()),this,SLOT(atualizaTela()));    //timer pra realizar cada movimento
    atualiza_timer->start(50);

    //Inimigo * inimigo = new Inimigo();
    //inimigo->Normal();
    //scene->addItem(inimigo);

    // ISSO QUEBRA DANO COMO EU FALEI PQ ACHO Q ELE CRIA
    // O INIMIGO E N TEM ONDE ELE ALOCAR O DANO DELE ASSIM ELE QUEBRA
}

void Game::atualizaTela(){

    telaPiso->setValores(jogador->getPisoAtual(),jogador->getPontosUpgrade());
    barraVida->setValores(jogador->getMaxVida(), jogador->getVida());

}

