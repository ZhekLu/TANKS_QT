#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPointF>
#include <QTimer>

#include "definecells.h"

class Bullet : public QWidget
{
    Q_OBJECT
public:
    ~Bullet();
    Bullet(const QPointF &startPos, QGraphicsScene *scene, int speed, int rotation = Rotation::STOP, QWidget *parent = nullptr);
//    functions
    QPointF UpRightPos() const;
    QPointF DownLeftPos() const;
    void setPos(int ax, int ay);
    void setPos(const QPointF &pos);
private:
//    elements
    QGraphicsEllipseItem* body;
    QGraphicsScene* parentScene;
//    variables
    int size;
    int rotation;
    int speed;

    QTimer* moveTimer;
//    functions
    void Move(int step = CELL);

private slots:
    void moveTimerEvent();

};

#endif // BULLET_H
