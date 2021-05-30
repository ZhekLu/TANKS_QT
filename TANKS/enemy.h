#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPointF>
#include <QTimer>
#include <QVector>
#include <QPointF>
#include <QPixmap>
#include <QImage>
#include <QMap>
#include <QGraphicsPixmapItem>

#include "definecells.h"
#include"bullet.h"
class Enemy : public QWidget
{
    Q_OBJECT
public:
    ~Enemy();
    Enemy(const QPointF &startPos, QGraphicsScene *scene, int speed, int rotation = Rotation::DOWN, QWidget *parent = nullptr);
//    functions
    QPointF UpRightPos() const; //  do u need this?
    QPointF DownLeftPos() const;
private:
//    elements
    QGraphicsPixmapItem* body;
    QGraphicsScene* parentScene;

    static QMap<int, QImage> const imageMap;
//    variables
    int size;
    int rotation;
    int speed;
    bool canMove;

    QTimer* moveTimer;
//    functions
    void Move(int step = CELL);
    void Rotate(int rotation);
    static QMap<int, QImage> initImageMap();
private slots:
    void moveTimerEvent();

};

#endif // ENEMY_H
