#ifndef TIROINIMIGO_H
#define TIROINIMIGO_H

#include "inimigo.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class TiroInimigo: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int velocidade,alcance;
public:
    TiroInimigo(QGraphicsItem * parent=0);
    void setVelocidade(int value);
    void setAlcance(int value);
    int getAlcance() const;

    int getVelocidade() const;

public slots:
    void move();
    void deleta();
};

#endif // TIROINIMIGO_H
