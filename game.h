#ifndef GAME_H
#define GAME_H

#include "jogador.h"
#include "telapiso.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include <QObject>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game();
    Jogador * jogador;
    QGraphicsScene * scene;
    TelaPiso * telaPiso;
public slots:
    void atualizaTela();
};

#endif // GAME_H
