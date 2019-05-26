#include "chao.h"
#include <QGraphicsScene>
#include <QDebug>

Chao::Chao(int i, int j){
    QPixmap chao_png(QPixmap(":/imagens/imagens/chao.png"));
    setRect(i*40+141,j*40+11,40,40);
    setBrush(QBrush(chao_png));
}
