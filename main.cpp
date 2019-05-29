#include <QApplication>
#include "game.h"
#include "menu.h"
#include <time.h>

    Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));
    Menu * menu = new Menu();
    menu->show();

    return a.exec();
}
