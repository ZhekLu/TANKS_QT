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

//#include <QDir>
#include "definecells.h"
#include"bullet.h"
class Enemy : public QWidget
{
    Q_OBJECT
public:
    ~Enemy();
    Enemy(const QPointF &startPos, QGraphicsScene *scene, int speed, int rotation = Rotation::DOWN, QWidget *parent = nullptr);

    QVector<Bullet*> bullets;

//    functions
    uint getWidth() const;
    uint getHeight() const;
    QPointF UpRightPos() const;
    QPointF DownLeftPos() const;
    QPointF bulletStartPos();
    void setPos(int ax, int ay);
private:
//    elements
    QGraphicsPixmapItem* body;
    QGraphicsScene* parentScene;

    static QMap<int, QImage> const imageMap;
//    variables
    int bodyHeight;
    int bodyWidht;
    int rotation;
    int speed;
    bool canMove;

    QTimer* attackTimer;
    QTimer* moveTimer;
//    functions
    void Shot();
    void Move(int step = CELL);
    void Rotate(int rotation);
    static QMap<int, QImage> initImageMap();
private slots:
    void moveTimerEvent();
    void attackTimerEvent();
};

#endif // ENEMY_H
