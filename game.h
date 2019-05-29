#ifndef GAME_H
#define GAME_H

#include "menu.h"
#include "jogador.h"
#include "telapiso.h"
#include "barravida.h"
#include "tiroinimigo.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include <QObject>

class Game: public QGraphicsView{
    Q_OBJECT
private:
    int TIRAO = 0;
public:
    Game();
    Jogador * jogador;
    QGraphicsScene * scene;
    TelaPiso * telaPiso;
    BarraVida * barraVida;
    int getTIRAO() const;
    void setTIRAO(int value);

public slots:
    void atualizaTela();
};

#endif // GAME_H
