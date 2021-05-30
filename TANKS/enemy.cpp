#include "enemy.h"

Enemy::Enemy(const QPointF &startpos, QGraphicsScene *scene, int speed, int rotation, QWidget *parent)
    : QWidget(parent)
{
//    variables
    size = 4 * CELL;
    canMove = true;
    this->rotation = rotation;
    parentScene = scene;
    this->speed = speed;

//    body
    this->body = new QGraphicsPixmapItem(QPixmap::fromImage(imageMap[rotation]));
//    body = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxLEFT.png")));
    body->setPos(startpos);

    scene->addItem(body);

//    timer
    moveTimer = new QTimer(this);
    moveTimer->start(5);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveTimerEvent()));
}

Enemy::~Enemy()
{
    parentScene->removeItem(body);
    delete body;
    delete moveTimer;
}

QPointF Enemy::UpRightPos() const
{
    return body->pos();
}

QPointF Enemy::DownLeftPos() const
{
    return QPointF(body->pos().x() + size, body->pos().y() + size);
}

void Enemy::Move(int step)
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

void Enemy::Rotate(int rotation)
{
    this->rotation = rotation;
    body->setPixmap(QPixmap::fromImage(imageMap[rotation]));

}

QMap<int, QImage> Enemy::initImageMap()
{
    QMap<int, QImage> tempMap;
    tempMap [Rotation::LEFT] = QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxLEFT.png");
    tempMap [Rotation::UP] = QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxUP.png");
    tempMap [Rotation::RIGHT] = QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxRIGHT.png");
    tempMap [Rotation::DOWN] = QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\enemyTank40pxDOWN.png");
    return tempMap;

}
QMap<int, QImage> const Enemy::imageMap = initImageMap();

void Enemy::moveTimerEvent()
{
    this->Move(speed);
}
