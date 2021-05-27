#ifndef TANK_H
#define TANK_H

#include<QWidget>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsEllipseItem>
#include "definecells.h"
class Tank : public QWidget
{
    Q_OBJECT
public:
    Tank(int x, int y, QGraphicsScene *scene, QWidget* parent = nullptr);
private:
    QGraphicsRectItem* cannon; //pushka
    QGraphicsRectItem* body;
    QGraphicsEllipseItem* bullet; // shot
    int bodyLen;
};

#endif // TANK_H
