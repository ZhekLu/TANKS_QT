#include "bullet.h"

Bullet::Bullet(const QPointF &startpos, QGraphicsScene *scene, int speed, int rotation, QWidget *parent)
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
    moveTimer->start(5);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveTimerEvent()));
}

Bullet::~Bullet()
{
    parentScene->removeItem(body);
    delete body;
    delete moveTimer;
}

QPointF Bullet::UpRightPos() const
{
    return body->pos();
}

QPointF Bullet::DownLeftPos() const
{
    return QPointF(body->pos().x() + size, body->pos().y() + size);
}

void Bullet::setPos(int ax, int ay)
{
    body->setPos(ax, ay);
}

void Bullet::setPos(const QPointF &pos)
{
    body->setPos(pos);
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
