#include "telapiso.h"
#include <QGraphicsScene>
#include "QFont"

TelaPiso::TelaPiso(QGraphicsTextItem * parent): QGraphicsTextItem (parent)
{
    setPlainText(QString("PISO : ") + QString::number(this->piso) + QString("\n") + QString("PONTOS UPGRADE : ") + QString::number(this->PontosUpgrade));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Comic",14));
    setPos(0,517);


}

void TelaPiso::setValores(int value, int value2)
{
    piso = value;
    PontosUpgrade = value2;

    setPlainText(QString("PISO : ") + QString::number(this->piso) + QString("\n") + QString("PONTOS UPGRADE : ") + QString::number(this->PontosUpgrade));


}

