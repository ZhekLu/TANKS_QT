#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem> //hz
#include <QTimer>
#include <QHBoxLayout>

#include <QGraphicsRectItem>
#include <QDebug>

#include "tank.h"

class MainScene : public QWidget
{
    Q_OBJECT
public:
    MainScene(QWidget *parent = nullptr);
    QHBoxLayout* sceneLayout;
    QGraphicsView* sceneWidget;
    QGraphicsScene* scene;
    QTimer* tankTimer;

    Tank *tank;
private slots:
//   void tankTimerSlot();

};


#endif // MAINSCENE_H
