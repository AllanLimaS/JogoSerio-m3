#ifndef INIMIGO_H
#define INIMIGO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Inimigo:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Inimigo(QGraphicsItem * parent=0);
    void Inimigo12();
    void Normal();
    void Metralha();
    void Sniper();

    void rotateToPoint(QPointF p);
public slots:
    void move();
    void atira();
    void atiraDeDoze();
    void atiraMetralha();
    void atiraSniper();

};

#endif // INIMIGO_H
