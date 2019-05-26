#ifndef TIRO_H
#define TIRO_H

#include "jogador.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Tiro: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int velocidade,alcance;
public:
    Tiro(QGraphicsItem * parent=0);
    void setVelocidade(int value);
    void setAlcance(int value);
    int getAlcance() const;

public slots:
    void move();
    void deleta();
};

#endif // TIRO_H
