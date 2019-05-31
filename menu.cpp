#include "menu.h"
#include "game.h"
#include "telas.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <windows.h>

extern Game * game;

Menu::Menu():QGraphicsView(){

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setBackgroundBrush(QPixmap(":/imagens/imagens/menu.png"));
}

void Menu::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_1){
        game = new Game();
        game->show();
        this->close();
    }

    if (event->key() == Qt::Key_2){
        // continua jogo
    }

    if (event->key() == Qt::Key_3){
        Telas * instrucoes = new Telas();
        instrucoes->TelaInstrucoes();
        instrucoes->show();
        this->close();
    }

    if (event->key() == Qt::Key_Escape){
        exit(0);
    }
}
