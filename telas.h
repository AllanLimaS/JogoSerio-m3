#ifndef TELAS_H
#define TELAS_H

#include "menu.h"

#include <QGraphicsView>
#include <QObject>

class Telas: public QGraphicsView{
    Q_OBJECT
private:
    int tipoTela;
public:
    Telas();
    QGraphicsScene * scene;
    void keyPressEvent(QKeyEvent * event);
    void TelaInstrucoes();
    void TelaMorte();
};

#endif // TELAS_H
