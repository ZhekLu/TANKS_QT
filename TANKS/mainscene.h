#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem> //hz
#include <QTimer>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QMap>
#include <QDebug>

#include "tank.h"
#include "definecells.h"

class MainScene : public QWidget
{
    Q_OBJECT
public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    Tank *tank;
private:
    QHBoxLayout* sceneLayout;
    QGraphicsView* sceneWidget;
    QGraphicsScene* scene;
    QTimer* tankTimer;

    void keyPressEvent(QKeyEvent*) override;
    void keyReleaseEvent(QKeyEvent*) override;
    QMap<int, bool> keys;

protected:

/*
 * bool eventFilter(QObject *obj, QEvent *event) override;
 * bool upKey, downKey, rightKey, leftKey, fireKey;
 * void updateKeys();
*/

private slots:
   void tankTimerSlot();

};


#endif // MAINSCENE_H
