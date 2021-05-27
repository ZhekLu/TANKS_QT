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
    tankTimer->start(1000);
    connect(tankTimer, SIGNAL(timeout()), this, SLOT(tankTimerSlot()));
}

void MainScene::keyPressEvent(QKeyEvent *e)
{
    short speed = 2;
    switch (e->key()) {
    case Qt::Key_A:
        tank->Rotate(Tank::Rotation::LEFT);
        tank->Move(speed);
        break;
    case Qt::Key_W:
        tank->Rotate(Tank::Rotation::UP);
        tank->Move(speed);
        break;
    case Qt::Key_D:
        tank->Rotate(Tank::Rotation::RIGHT);
        tank->Move(speed);
        break;
    case Qt::Key_S:
        tank->Rotate(Tank::Rotation::DOWN);
        tank->Move(speed);
        break;
    }
}

void MainScene::tankTimerSlot()
{

}
