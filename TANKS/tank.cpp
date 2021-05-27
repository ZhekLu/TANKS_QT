#include "tank.h"


Tank::Tank(int x, int y, QGraphicsScene *scene, QWidget *parent) : QWidget(parent)
{
    bodyLen = CELL * 3;
//    body
    body = new QGraphicsRectItem(0, 0, bodyLen, bodyLen);
    body->setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    body->setBrush(Qt::gray);
    body->setPos(x, y);
//    child cannon
    cannon = new QGraphicsRectItem(CELL, -CELL, CELL * 1, CELL * 2, body);
    cannon->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    cannon->setBrush(Qt::gray);
//    bullet
    bullet = new QGraphicsEllipseItem(0, 0, CELL, CELL, cannon);
    bullet->setPen(QPen(Qt::black));
    bullet->setBrush(Qt::black);
    bullet->hide();

    scene->addItem(body);
}
