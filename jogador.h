#ifndef JOGADOR_H
#define JOGADOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Jogador:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    bool Up=0,Down=0,Right=0,Left=0;
    int velocidadeTiro,velocidadeMovimento,alcanceTiro;
public:
    Jogador(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void movimento();
    int getVelocidadeTiro() const;
    void setVelocidadeTiro(int value);
    int getVelocidadeMovimento() const;
    void setVelocidadeMovimento(int value);
    void setAlcanceTiro(int value);
    int getAlcanceTiro() const;
};

#endif // JOGADOR_H
