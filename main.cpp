//      REGRAS PARA O CODIGO
//  1 - NOME DE VARIAVEIS TUDO JUNTO
//  EX: "vidaPlayer", "comerSeuCu"
//  2 - TAMANHO DOS PNG TUDO 20x20

#include <QApplication>
#include "game.h"

    Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();


    return a.exec();
}
