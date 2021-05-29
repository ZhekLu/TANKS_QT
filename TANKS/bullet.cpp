#include "bullet.h"

Bullet::Bullet(QPointF startpos, QGraphicsScene *scene, int speed, int rotation, QWidget *parent)
    : QWidget(parent)
{
//    variables
    size = CELL;
    this->rotation = rotation;
    parentScene = scene;
    this->speed = speed;
//    body
    body = new QGraphicsEllipseItem(0, 0, size, size);
    body->setPen(QPen(Qt::black));
    body->setBrush(Qt::black);
    body->setPos(startpos);

    scene->addItem(body);

//    timer
    moveTimer = new QTimer(this);
    moveTimer->start(10);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveTimerEvent()));
}

void Bullet::Move(int step)
{
    QPointF currPos = body->pos();
    switch (rotation) {
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

void Bullet::moveTimerEvent()
{
    this->Move(speed);
}
