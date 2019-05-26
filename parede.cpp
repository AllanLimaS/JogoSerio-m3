#include "parede.h"
#include <QGraphicsScene>
#include <QDebug>

Parede::Parede(int i, int j){
    QPixmap parede_png(QPixmap(":/imagens/imagens/parede.png"));
    setRect(i*40+141,j*40+11,38,38);
    setBrush(QBrush(parede_png));
}
