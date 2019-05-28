#include "upgrades.h"
#include <QGraphicsScene>

Upgrades::Upgrades()
{

    QPixmap placa_png(QPixmap(":/imagens/imagens/placa.png"));

        setRect(341, 91, 120, 120);       // AQUI TEM Q FAZER UM PLACA EXPLICANDO PAR O PLAYER COMO UPA
        setBrush(QBrush(placa_png));

}
