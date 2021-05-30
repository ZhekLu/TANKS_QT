#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem> //hz
#include <QTimer>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QVector>
#include <QGraphicsRectItem>
#include <QMap>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "tank.h"
#include "definecells.h"
#include "enemy.h"

class MainScene : public QWidget
{
    Q_OBJECT
public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
protected:
    Tank *tank;
    QVector<Enemy*> enemies;
private:
//    elements
    QHBoxLayout* sceneLayout;
    QGraphicsView* sceneWidget;
    QGraphicsScene* scene;
    QTimer* updateTimer;
//    moving events
    void keyPressEvent(QKeyEvent*) override;
    void keyReleaseEvent(QKeyEvent*) override;
    QMap<int, bool> keys;
//    fuctions
    void updateBulletsCollision();
    void updatePlayerMoving();
    void UpdateEnemiesMoving();
    void updateTanksCollision();
private slots:
   void updateTimerSlot();

};


#endif // MAINSCENE_H
