#include "parede.h"
#include <QGraphicsScene>
#include <QDebug>

Parede::Parede(int i, int j){
    QPixmap parede_png(QPixmap(":/imagens/imagens/parede.png"));
    QPixmap escada_png(QPixmap(":/imagens/imagens/escada.png"));

    if(i == 12 and j == 5){
        setRect(i*40+141,j*40+11, 40, 120);
        setBrush(QBrush(escada_png));

    }else if(i == 12 and j > 5 and j < 8) {


    }else{
        setRect(i*40+141,j*40+11,38,38);
        setBrush(QBrush(parede_png));
    }
}
