#ifndef TANK_H
#define TANK_H

#include<QDebug>

#include<QWidget>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsEllipseItem>
#include<QPointF>
#include "definecells.h"
class Tank : public QWidget
{
    Q_OBJECT
public:
    Tank(int x, int y, QGraphicsScene *scene, int rotation = Rotation::STOP, QWidget* parent = nullptr);
    enum Rotation
    {
        LEFT, UP, RIGHT, DOWN, STOP
    };
    int rotation;
    void Move(int step = CELL);
    void Rotate(int rot);
//    QPointF Pos();
private:
    QGraphicsRectItem* cannon; //pushka
    QGraphicsRectItem* body;
    QGraphicsEllipseItem* bullet; // shot
    int bodyLen;

};

#endif // TANK_H
