#include "telas.h"
#include "game.h"
#include "menu.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <windows.h>

extern Game * game;

Telas::Telas():QGraphicsView(){

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void Telas::keyPressEvent(QKeyEvent *event)
{
    if(this->tipoTela == 1){

        Menu * menu = new Menu();
        menu->show();
        this->close();
        delete (this);
    }
    if(this->tipoTela == 2){
        //TELA DE MORTE OU SEI LÁ QUALQUER COISA
    }
}

void Telas::TelaInstrucoes()
{
    scene->setBackgroundBrush(QPixmap(":/imagens/imagens/instrucoes.png"));
    this->tipoTela=1;

}
