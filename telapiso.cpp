#include "telapiso.h"
#include "QFont"

TelaPiso::TelaPiso(QGraphicsTextItem * parent): QGraphicsTextItem (parent)
{
    setPlainText(QString("PISO : ") + QString::number(this->piso));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Comic",14));
    setPos(0,517);

}

void TelaPiso::setPiso(int value)
{
    piso = value;

    setPlainText(QString("PISO : ") + QString::number(this->piso));

}

