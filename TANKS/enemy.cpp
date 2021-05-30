#include "enemy.h"

Enemy::Enemy(const QPointF &startpos, QGraphicsScene *scene, int speed, int rotation, QWidget *parent)
    : QWidget(parent)
{
//    variables
    bodyHeight = 40;
    bodyWidht = 35;
    canMove = true;
    this->rotation = rotation;
    parentScene = scene;
    this->speed = speed;

//    body
    this->body = new QGraphicsPixmapItem(QPixmap::fromImage(imageMap[rotation]));
    body->setPos(startpos);

    scene->addItem(body);

//    timers
    moveTimer = new QTimer(this);
    moveTimer->start(15);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveTimerEvent()));

    attackTimer = new QTimer(this);
    attackTimer->start(1000/1);
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(attackTimerEvent()));
}

uint Enemy::getWidth() const
{
    return (rotation == LEFT || rotation == RIGHT)?
                bodyHeight :
                bodyWidht;
}

uint Enemy::getHeight() const
{
    return (rotation == LEFT || rotation == RIGHT)?
                bodyWidht :
                bodyHeight;
}

Enemy::~Enemy()
{
    for(auto *i : bullets)
    {
        delete i;
        bullets.pop_front();
    }
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
    QPointF currBodyPos = body->pos();
    switch(rotation)
    {
    case Rotation::LEFT:
    case Rotation::RIGHT:
        currBodyPos.rx() += bodyHeight;
        currBodyPos.ry() += bodyWidht;
        break;
    case Rotation::UP:
    case Rotation::DOWN:
        currBodyPos.ry() += bodyHeight;
        currBodyPos.rx() += bodyWidht;
        break;
    }

    return currBodyPos;
}

void Enemy::Shot()
{
    if(rotation != Rotation::STOP)
    {
        Bullet* newBul = new Bullet(bulletStartPos(), parentScene, 1, rotation);
        bullets.push_back(newBul);
    }
}

QPointF Enemy::bulletStartPos()
{
    QPointF currBodyPos = body->pos();
    float displacement = ((float)bodyWidht - bodyWidht * 3.f / 16) / 2.f;

    switch (rotation) {
    case Rotation::LEFT:
        currBodyPos.ry() += displacement;
        break;
    case Rotation::UP:
        currBodyPos.rx() += displacement;
        break;
    case Rotation::RIGHT:
        currBodyPos.rx() += bodyHeight;
        currBodyPos.ry() += displacement;
        break;
    case Rotation::DOWN:
        currBodyPos.rx() += displacement;
        currBodyPos.ry() += bodyHeight;
        break;
    }
    return currBodyPos;
}

void Enemy::setPos(int ax, int ay)
{
    body->setPos(ax, ay);
}

void Enemy::Move(int step)
{
    QPointF currBodyPos = body->pos();
    switch (rotation) {
    case Rotation::LEFT:
        currBodyPos.rx() -= step;
        break;
    case Rotation::UP:
        currBodyPos.ry() -= step;
        break;
    case Rotation::RIGHT:
        currBodyPos.rx() += step;
        break;
    case Rotation::DOWN:
        currBodyPos.ry() += step;
        break;
    }
    body->setPos(currBodyPos);
}

void Enemy::Rotate(int rotation)
{
    this->rotation = rotation;
    body->setPixmap(QPixmap::fromImage(imageMap[rotation]));
}

QMap<int, QImage> Enemy::initImageMap()
{
    QMap<int, QImage> tempMap;
    // size 35x40
    tempMap [Rotation::LEFT] = QImage(".\\..\\TANKS\\resources\\enemyTank-ob-40px-LEFT.png");
    tempMap [Rotation::UP] = QImage(".\\..\\TANKS\\resources\\enemyTank-ob-40px-UP.png");
    tempMap [Rotation::RIGHT] = QImage(".\\..\\TANKS\\resources\\enemyTank-ob-40px-RIGHT.png");
    tempMap [Rotation::DOWN] = QImage(".\\..\\TANKS\\resources\\enemyTank-ob-40px-DOWN.png");
//    qDebug() << QDir::currentPath();
    return tempMap;

}
QMap<int, QImage> const Enemy::imageMap = initImageMap();

void Enemy::moveTimerEvent()
{
    if(canMove)
        this->Move(speed);
}

void Enemy::attackTimerEvent()
{
    this->Shot();
}
