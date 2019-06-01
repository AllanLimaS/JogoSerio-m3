#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPolygonItem>
#include <QPointF>

class Boss : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

private:
    int VidaBoss = 20;

public:
    Boss();
    void rotateToPoint(QPointF p);

    int getVidaBoss() const;
    void setVidaBoss(int value);

public slots:
    void move();
    void verificaDano();
};

#endif // BOSS_H
