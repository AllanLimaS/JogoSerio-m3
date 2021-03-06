#ifndef GAME_H
#define GAME_H

#include "menu.h"
#include "jogador.h"
#include "telapiso.h"
#include "barravida.h"
#include "tiroinimigo.h"
#include "escada.h"

#include <QGraphicsView>
#include <QMouseEvent>
#include <QObject>

class Game: public QGraphicsView{
    Q_OBJECT

private:
    int TIRAO = 0;
    int DANO = 0;
    int ARMAO = 0;
    int DanoJogador = 1;

public:
    Game();

    Jogador * jogador;
    QGraphicsScene * scene;
    TelaPiso * telaPiso;
    BarraVida * barraVida;
    Escada * escada;

    int getTIRAO() const;
    void setTIRAO(int value);

    int getDANO() const;
    void setDANO(int value);

    int getDanoJogador() const;
    void setDanoJogador(int value);

    void criaMapa();

    int getARMAO() const;
    void setARMAO(int value);

public slots:
    void atualizaTela();
};

#endif // GAME_H
