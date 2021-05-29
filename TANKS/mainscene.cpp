#include "mainscene.h"

MainScene::MainScene(QWidget *parent) : QWidget(parent)
{
    sceneLayout = new QHBoxLayout(this);
    sceneWidget = new QGraphicsView;

    scene = new QGraphicsScene(0, 0, 600, 560, sceneWidget);
    scene->addRect(scene->sceneRect());
    sceneWidget->setScene(scene);

    tank = new Tank(0, 0, scene, Rotation::DOWN);

    sceneLayout->addWidget(sceneWidget);
    setLayout(sceneLayout);

    tankTimer = new QTimer(this);
    tankTimer->start(10);
    connect(tankTimer, SIGNAL(timeout()), this, SLOT(tankTimerSlot()));


/*
 *    try fix moving with help of filters
 *    installEventFilter(this);
 *    upKey = downKey = rightKey = leftKey = fireKey = false;
*/
}

MainScene::~MainScene()
{
    delete tank;
    delete scene;
    delete sceneWidget;
    delete sceneLayout;
    delete tankTimer;
}

void MainScene::keyPressEvent(QKeyEvent *e)
{
    short speed = 2;
    keys[e->key()] = true;
        QWidget::keyPressEvent(e);

            if(keys[Qt::Key_A])
            {
                tank->Rotate(Rotation::LEFT);
                tank->Move(speed);
            }
            else if(keys[Qt::Key_W])
            {
                tank->Rotate(Rotation::UP);
                tank->Move(speed);
            }
            else if(keys[Qt::Key_D])
            {
                tank->Rotate(Rotation::RIGHT);
                tank->Move(speed);
            }
            else if(keys[Qt::Key_S])
            {
                tank->Rotate(Rotation::DOWN);
                tank->Move(speed);
            }
            if(keys[Qt::Key_C] && tank->CanAttack())
                tank->Shot();
}

void MainScene::keyReleaseEvent(QKeyEvent *e)
{
    keys[e->key()] = false;
    QWidget::keyReleaseEvent(e);
}

void MainScene::tankTimerSlot()
{
//    static unsigned short int x = 65000;
//    qDebug() << x++;
}

/*
 * filters fix
bool MainScene::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* ke = static_cast<QKeyEvent*>(event);
            bool b;
            event->type() == QEvent::KeyPress ? b = true : b = false;
            switch(ke->key())
            {
            case Qt::Key_W:
                upKey = b;
                break;
            case Qt::Key_S:
                downKey = b;
                break;
            case Qt::Key_D:
                rightKey = b;
                break;
            case Qt::Key_A:
                leftKey = b;
                break;
            case Qt::Key_C:
                fireKey = b;
                break;
            }
            updateKeys();
            return true;
        }

        return QObject::eventFilter(obj, event);
}

void MainScene::updateKeys()
{
    int speed = 2;
    if(upKey)
    {
        tank->Rotate(Rotation::UP);
        tank->Move(speed);
    }
    if(leftKey)
    {
        tank->Rotate(Rotation::LEFT);
        tank->Move(speed);
    }
    if(downKey)
    {
        tank->Rotate(Rotation::DOWN);
        tank->Move(speed);
    }
    if(rightKey)
    {
        tank->Rotate(Rotation::RIGHT);
        tank->Move(speed);
    }
    if(fireKey && tank->CanAttack())
        tank->Shot();

}
*/
