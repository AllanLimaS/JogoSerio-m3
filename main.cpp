#include <QApplication>
#include "game.h"
#include <time.h>

    Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    game = new Game();
    game->show();


    return a.exec();
}
