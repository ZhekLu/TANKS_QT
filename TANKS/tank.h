#ifndef TANK_H
#define TANK_H

#include<QDebug>
#include<QWidget>
#include <QTimer>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsEllipseItem>
#include<QPointF>
#include<QVector>

#include "definecells.h"
#include "bullet.h"

class Tank : public QWidget
{
    Q_OBJECT
public:
    ~Tank();
    Tank(int x, int y, QGraphicsScene *scene, int rotation = Rotation::STOP, QWidget* parent = nullptr);

    QVector<Bullet*> bullets;

//    functions
    void Move(int step = CELL);
    void Rotate(int rot);
    void Shot();
    QPointF bulletStartPos();
    bool CanAttack() const;

private:
//    elements
    QGraphicsRectItem* cannon; //pushka
    QGraphicsRectItem* body;
    QGraphicsScene *parentScene;
//    variables
    int bodyLen;
    int rotation;
    bool canAttack;

    QTimer* attackTimer;

private slots:
    void UpdateAttack();

};

#endif // TANK_H
