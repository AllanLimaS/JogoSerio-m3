#include "parede.h"
#include "game.h"
#include <QGraphicsScene>

extern Game * game;

Parede::Parede(int i, int j,int mapa){

    QPixmap escada_png(QPixmap(":/imagens/imagens/escada.png"));

    if(i == 12 and j == 5){
        setRect(i*40+141,j*40+11, 40, 120);
        setBrush(QBrush(escada_png));

    }else if(i == 12 and j > 5 and j < 8) {


    }else{
        setRect(i*40+141,j*40+11,38,38);
    }

    switch(mapa){

    case 0: //mapa original
        setBrush(QPixmap(":/imagens/imagens/parede.png"));
        break;

    case 1: //dust

        switch (rand()%5){  //aleatoriza a parede
        case 0:
        case 1:
        case 2:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_parede2.bmp"));
            break;
        case 3:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_parede1.bmp"));
            break;
        case 4:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_parede3.bmp"));
            break;
        default:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_parede2.bmp"));
            break;
        }
        break;


    case 2: //aztec

        switch (rand()%5){  //aleatoriza a parede
        case 0:
        case 1:
        case 2:
            setBrush(QPixmap(":/tiles/imagens/mapas/aztec_parede1.bmp"));
            break;
        case 3:
        case 4:
            setBrush(QPixmap(":/tiles/imagens/mapas/aztec_parede2.bmp"));
            break;
        default:
            setBrush(QPixmap(":/tiles/imagens/mapas/aztec_parede1.bmp"));
            break;
        }
        break;
    }
}
