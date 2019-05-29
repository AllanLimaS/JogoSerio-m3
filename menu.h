#ifndef MENU_H
#define MENU_H

#include "game.h"

#include <QGraphicsView>
#include <QObject>

class Menu: public QGraphicsView{
    Q_OBJECT
public:
    Menu();
    QGraphicsScene * scene;
    void keyPressEvent(QKeyEvent * event);
};

#endif // MENU_H
