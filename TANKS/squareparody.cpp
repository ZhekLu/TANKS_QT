#include "squareparody.h"

TanksWindow::TanksWindow(QWidget *parent)
    : QWidget(parent)
{
    myLayoutScene = new QHBoxLayout(this);
    myGraphics = new myGraphicsView;
    myLayoutScene->addWidget(myGraphics);
    setLayout(myLayoutScene);
}

TanksWindow::~TanksWindow()
{
}


myGraphicsView::myGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(0, 0, 600, 560, this);
    scene->addRect(scene->sceneRect());
    setScene(scene);

    myRectTimer = new QTimer(this);
    myRectTimer->start(1000/100);
    connect(myRectTimer, SIGNAL(timeout()), this, SLOT(myTimerRect()));

    rectItem = new QGraphicsRectItem(0, 0, 60, 60);
    rectItem->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    rectItem->setBrush(Qt::gray);
    rectItem->setPos(0, 500);
    personaj();
    scene->addItem(rectItem);
}

void myGraphicsView::personaj()
{
    childItem = new QGraphicsRectItem(20, -20, 20, 40, rectItem);
    childItem->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    childItem->setBrush(Qt::gray);
}

void myGraphicsView::myTimerRect()
{
//    static int i = 0;
//    qDebug() << "tiner" << (i++);
}
