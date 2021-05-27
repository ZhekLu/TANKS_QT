#ifndef TANKSWINDOW_H
#define TANKSWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem> //hz
#include <QTimer>
#include <QHBoxLayout>

#include <QGraphicsRectItem>
#include <QDebug>

class myGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
   myGraphicsView(QWidget* parent = 0);
private:
   QGraphicsScene* scene;
   QGraphicsRectItem* rectItem;
   QTimer* myRectTimer;

   void personaj();
   QGraphicsRectItem *childItem;
private slots:
   void myTimerRect();
};

class TanksWindow : public QWidget
{
    Q_OBJECT

public:
    TanksWindow(QWidget *parent = nullptr);
    ~TanksWindow();
private:
    QHBoxLayout* myLayoutScene;
    myGraphicsView* myGraphics;
};
#endif // TANKSWINDOW_H
