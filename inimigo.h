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
    void rotateToPoint(QPointF p);
public slots:
    void move();
    void atira();
};

#endif // INIMIGO_H
