#ifndef TANK_H
#define TANK_H

#include<QDebug>
#include<QWidget>
#include <QTimer>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsEllipseItem>
#include<QPointF>
#include<QVector>

#include "definecells.h"
#include "bullet.h"

class Tank : public QWidget
{
    Q_OBJECT
public:
    ~Tank();
    Tank(int x, int y, QGraphicsScene *scene, int rotation = Rotation::STOP, QWidget* parent = nullptr);

    QVector<Bullet*> bullets;
    int rotation;
//    Functions
    void Move(int step = CELL);
    void Rotate(int rot);
    void Shot();
    QPointF bulletStartPos();
//    QPointF Pos();
//    int getRotation() const;

private:
    QGraphicsRectItem* cannon; //pushka
    QGraphicsRectItem* body;
    QGraphicsScene *parentScene;
    int bodyLen;
//    QTimer* shotTimer;

};

#endif // TANK_H
