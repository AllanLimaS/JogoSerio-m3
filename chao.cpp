#include "chao.h"
#include <QGraphicsScene>
#include <QDebug>

Chao::Chao(int i, int j, int mapa){

    setRect(i*40+141,j*40+11,40,40);

    switch(mapa){
    case 0:     //mapa origiankl
        setBrush(QPixmap(":/imagens/imagens/chao.png"));
        break;

    case 1:     //DUST
        switch(rand()%10){
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_chao1.bmp"));
            break;
        case 7:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_chao2.bmp"));
            break;
        case 8:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_chao3.bmp"));
            break;
        case 9:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_chao4.bmp"));
            break;
        default:
            setBrush(QPixmap(":/tiles/imagens/mapas/dust_chao1.bmp"));
            break;
        }
        break;

    case 2:     //aztec
        switch(rand()%10){
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
            setBrush(QPixmap(":/tiles/imagens/mapas/aztec_chao1.bmp"));
            break;
        case 7:
            setBrush(QPixmap(":/tiles/imagens/mapas/aztec_chao2.bmp"));
            break;
        case 8:
            setBrush(QPixmap(":/tiles/imagens/mapas/aztec_chao3.bmp"));
            break;
        case 9:
            setBrush(QPixmap(":/tiles/imagens/mapas/aztec_chao4.bmp"));
            break;
        default:
            setBrush(QPixmap(":/tiles/imagens/mapas/aztec_chao1.bmp"));
            break;

        }
    }
}
