#include "game.h"
#include "parede.h"
#include "chao.h"
#include "tiro.h"
#include "jogador.h"
#include <QGraphicsScene>


Game::Game():QGraphicsView(){

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/imagens/imagens/parede.png"));

    for(int i = 0; i<13; i++){
        for(int j = 0; j<13; j++){
            Chao * chao = new Chao(i,j);
            scene->addItem(chao);
            if(i==0||j==0||i==12||j==12){
                Parede * parede = new Parede(i, j);
                scene -> addItem(parede);
            }
        }
    }

    Jogador * jogador = new Jogador();
    scene->addItem(jogador);
    jogador->setPos(250,250);
    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



}

