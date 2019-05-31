#ifndef JOGADOR_H
#define JOGADOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "telapiso.h"

class Jogador:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:

    bool Up=0,Down=0,Right=0,Left=0,podeAtirar=0,
         TiroUp=0,TiroDown=0,TiroRight=0,TiroLeft=0;

    int velocidadeTiro,velocidadeMovimento;
    int pontosUpgrade = 0;

    int MaxVida = 12;
    int Vida = 12;
    int DanoSofrido = 0;
    int Arma = 0; // 0 PISTOLA // 1 DOZE // 2 SNIPER

    int TemInimigo = 0; // VARIAVEL PARA CONTROLE DE SAIDA
    int PisoAtual = 0;  // PISO ATUAL (JUST THAT)

public:

    Jogador(QGraphicsItem * parent = 0);
    QPointF getPos();                           //função para retornar a posição do jogador

    void keyPressEvent(QKeyEvent * event);      //evento que ve a tecla pressionada
    void keyReleaseEvent(QKeyEvent * event);    //evento que ve a tecla solta

    int getVelocidadeTiro() const;
    void setVelocidadeTiro(int value);
    int getVelocidadeMovimento() const;
    void setVelocidadeMovimento(int value);
    void setPontosUpgrade(int value);
    int getPontosUpgrade() const;
    int getPisoAtual() const;

    int getVida() const;
    void setVida(int value);

    int getMaxVida() const;
    void setMaxVida(int value);

    int getDanoSofrido() const;
    void setDanoSofrido(int value);

public slots:
    void atirar();
    void verificaDano();
    void acao();                //funcao onde realiza o movimento SUAVEEEEEEEEEEEEEEE
};

#endif // JOGADOR_H
