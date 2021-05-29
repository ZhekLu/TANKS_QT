#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPointF>
#include <QTimer>

#include "definecells.h"

class Bullet : public QWidget
{
    Q_OBJECT
public:
    Bullet(QPointF startPos, QGraphicsScene *scene, int speed, int rotation = Rotation::STOP, QWidget *parent = nullptr);
    void Move(int step = CELL);
private:
    QGraphicsEllipseItem* body;
    QGraphicsScene* parentScene;
    int size;
    int rotation;
    int speed;
    QTimer* moveTimer;
private slots:
    void moveTimerEvent();

};

#endif // BULLET_H
