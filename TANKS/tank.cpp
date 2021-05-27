#include "tank.h"


Tank::Tank(int x, int y, QGraphicsScene *scene, int rotation, QWidget *parent) : QWidget(parent)
{
    bodyLen = CELL * 3;
    this->rotation = rotation;
    Rotate(rotation);
//    body
    body = new QGraphicsRectItem(0, 0, bodyLen, bodyLen);
    body->setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    body->setBrush(Qt::gray);
    body->setPos(x, y);
//    child cannon
    cannon = new QGraphicsRectItem(0, 0, CELL * 1, CELL * 2, body);
    cannon->setPos(CELL, 2 * CELL);
    cannon->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    cannon->setBrush(Qt::gray);
//    bullet
    bullet = new QGraphicsEllipseItem(0, 0, CELL, CELL, cannon);
    bullet->setPen(QPen(Qt::black));
    bullet->setBrush(Qt::black);
    bullet->hide();

    scene->addItem(body);
}

void Tank::Move(int step)
{
    QPointF currPos = body->pos();
    switch (rotation)
    {
    case Rotation::LEFT:
        currPos.rx() -= step;
        break;
    case Rotation::UP:
        currPos.ry() -= step;
        break;
    case Rotation::RIGHT:
        currPos.rx() += step;

        break;
    case Rotation::DOWN:
        currPos.ry() += step;
        break;
    }
    body->setPos(currPos);
}

void Tank::Rotate(int rot)
{
    switch (rot)
    {
    case Rotation::LEFT:
//        cannon->setRotation(90);
        cannon->setRect(0, 0, CELL * 2, CELL * 1);
        cannon->setPos(-1 * CELL, 1 * CELL);
        rotation = Rotation::LEFT;
        break;
    case Rotation::UP:
//        cannon->setRotation(180);
        cannon->setRect(0, 0, CELL * 1, CELL * 2);
        cannon->setPos(1 * CELL, -1 * CELL);
        rotation = Rotation::UP;
        break;
    case Rotation::RIGHT:
//        cannon->setRotation(270);
        cannon->setRect(0, 0, CELL * 2, CELL * 1);
        cannon->setPos(2 * CELL, 1 * CELL);
        rotation = Rotation::RIGHT;

        break;
    case Rotation::DOWN:
//        cannon->setRotation(0);
        cannon->setRect(0, 0, CELL * 1, CELL * 2);
        cannon->setPos(1 * CELL, 2 * CELL);
        rotation = Rotation::DOWN;
        break;
    }
}
