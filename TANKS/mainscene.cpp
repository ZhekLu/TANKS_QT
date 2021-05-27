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
}
