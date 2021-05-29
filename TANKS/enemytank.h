#ifndef ENEMYTANK_H
#define ENEMYTANK_H

#include "definecells.h"
#include "bullet.h"
#include <QVector>
#include <QPointF>
#include <QImage>
#include <QMap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>

class EnemyTank : public QWidget
{
public:
    EnemyTank(int x, int y, QGraphicsScene* scene, int speed, int rotation = Rotation::DOWN);
    void Rotate(int rotation);
    void Move(int step = CELL);
private:
    //    variables
    int rotation;
    int speed;
    bool canMove;

    QTimer* moveTimer;
    //    elements
    QGraphicsScene* parentScene;
    QGraphicsPixmapItem* body;
    static QMap<int, QImage> const imageMap;
//    functions
    static QMap<int, QImage> initImageMap();

private slots:
    void moveTimerSlot();
};

#endif // ENEMYTANK_H
