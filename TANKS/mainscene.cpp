#include "mainscene.h"

MainScene::MainScene(QWidget *parent) : QWidget(parent)
{
    sceneLayout = new QHBoxLayout(this);
    sceneWidget = new QGraphicsView;

    scene = new QGraphicsScene(0, 0, 600, 560, sceneWidget);
    scene->addRect(scene->sceneRect());
    sceneWidget->setScene(scene);

    tank = new Tank(0, 0, scene);

    sceneLayout->addWidget(sceneWidget);
    setLayout(sceneLayout);

    tankTimer = new QTimer(this);
    tankTimer->start(10);
    connect(tankTimer, SIGNAL(timeout()), this, SLOT(tankTimerSlot()));
}

void MainScene::keyPressEvent(QKeyEvent *e)
{
    short speed = 2;
    switch (e->key()) {
    case Qt::Key_A:
        tank->Rotate(Rotation::LEFT);
        tank->Move(speed);
        break;
    case Qt::Key_W:
        tank->Rotate(Rotation::UP);
        tank->Move(speed);
        break;
    case Qt::Key_D:
        tank->Rotate(Rotation::RIGHT);
        tank->Move(speed);
        break;
    case Qt::Key_S:
        tank->Rotate(Rotation::DOWN);
        tank->Move(speed);
        break;
    case Qt::Key_C:
        tank->Shot();
    }
}

//void MainScene::keyReleaseEvent(QKeyEvent *e)
//{
//}

void MainScene::tankTimerSlot()
{
//    static unsigned short int x = 65000;
//    qDebug() << x++;
}
