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
    QPointF getPos();   //função para retornar a posição do jogador

    void keyPressEvent(QKeyEvent * event);      //evento que ve a tecla pressionada
    void keyReleaseEvent(QKeyEvent * event);    //evento que ve a tecla solta
    void movimento();                           //função q verifica quais teclas estão pressionadas no momento
    int getVelocidadeTiro() const;
    void setVelocidadeTiro(int value);
    int getVelocidadeMovimento() const;
    void setVelocidadeMovimento(int value);
    void setAlcanceTiro(int value);
    int getAlcanceTiro() const;
};

#endif // JOGADOR_H
