#include "escada.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

Escada::Escada()
{
    QPixmap escada_png(QPixmap(":/imagens/imagens/escada.png"));
    setRect(141,210,40,120);
    setBrush(QBrush(escada_png));
    setPen(QPen(Qt::red));
}
