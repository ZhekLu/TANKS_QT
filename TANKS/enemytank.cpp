#include "enemytank.h"


EnemyTank::EnemyTank(int x, int y, QGraphicsScene *scene, int speed, int rotation)
{
//    variables
    this->canMove = false;
    this->rotation = rotation;
    this->speed = speed;
//    body
    this->body = new QGraphicsPixmapItem(QPixmap::fromImage(imageMap[rotation]));
    body->setPos(x, y);
    scene->addItem(body);
//    moveTimer
    moveTimer = new QTimer(this);
    moveTimer->start(1000/100);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveTimerSlot()));
}

void EnemyTank::Rotate(int rotation)
{
    this->rotation = rotation;
    body->setPixmap(QPixmap::fromImage(imageMap[rotation]));
}

void EnemyTank::Move(int step)
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

QMap<int, QImage> EnemyTank::initImageMap()
{
    QMap<int, QImage> tempMap;
    tempMap [Rotation::LEFT] = QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxLEFT.png");
    tempMap [Rotation::UP] = QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxUP.png");
    tempMap [Rotation::RIGHT] = QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxRIGHT.png");
    tempMap [Rotation::DOWN] = QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxDOWN.png");
    return tempMap;
}

void EnemyTank::moveTimerSlot()
{

}

QMap<int, QImage> const EnemyTank::imageMap = initImageMap();

