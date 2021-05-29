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
    QPointF UpRightPos() const;
    QPointF DownLeftPos() const;
    bool CanAttack() const;
    void setPos(int ax, int ay);
    void setPos(const QPointF &pos);
    uint getWidth() const;
    uint getHeight() const;
    int getBodyLen() const;

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
