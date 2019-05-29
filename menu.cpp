#include "menu.h"
#include "game.h"

#include <QGraphicsScene>
#include <QPixmap>

extern Game * game;

Menu::Menu():QGraphicsView(){

    scene->addPixmap(":/imagens/imagens/menu.png");

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
       //instruções
    }

    if (event->key() == Qt::Key_Escape){
        exit(0);
    }
}
