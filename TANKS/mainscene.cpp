#include "mainscene.h"

MainScene::MainScene(QWidget *parent) : QWidget(parent)
{
    sceneLayout = new QHBoxLayout(this);
    sceneWidget = new QGraphicsView;
    this->setStyleSheet("background-color: black;");
    scene = new QGraphicsScene(0, 0, WIDTH, HEIGHT, sceneWidget);
    scene->addRect(scene->sceneRect());
    sceneWidget->setScene(scene);

    tank = new Tank(0, 0, scene, Rotation::DOWN);

    Enemy* enemy = new Enemy(QPointF(100, 100), scene, 1, Rotation::RIGHT);
    enemies.push_back(enemy);

    sceneLayout->addWidget(sceneWidget);
    setLayout(sceneLayout);

    updateTimer = new QTimer(this);
    updateTimer->start(5);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateTimerSlot()));

/*
//    style
    QImage *img = new QImage("D:\\STUDY\\projects\\CURSACH\\TANKS\\resources\\ironBlock");
    QPixmap *pxmap = new QPixmap(16, 16);
    pxmap->convertFromImage(*img);
    scene->addPixmap(*pxmap);
    */


}

MainScene::~MainScene()
{
    delete tank;
    delete scene;
    delete sceneWidget;
    delete sceneLayout;
    delete updateTimer;
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

void MainScene::updateBulletsCollision()
{
//    with walls
    int counter = 0;
//    player
    for(auto *bullet : tank->bullets)
    {
        if(bullet->UpRightPos().x() < 0 || bullet->UpRightPos().y() < 0 ||
                bullet->DownLeftPos().x() > WIDTH || bullet->DownLeftPos().y() > HEIGHT)
        {
            delete bullet; // delete(tank->bullets.at(counter));
            tank->bullets.erase(tank->bullets.begin() + counter);
        }
        counter++;
    }
//    enemies
    counter = 0;
    for(auto *enemy : enemies)
        for(auto *bullet : enemy->bullets)
        {
            if(bullet->UpRightPos().x() < 0 || bullet->UpRightPos().y() < 0 ||
                    bullet->DownLeftPos().x() > WIDTH || bullet->DownLeftPos().y() > HEIGHT)
            {
                delete bullet; // delete(tank->bullets.at(counter));
                enemy->bullets.erase(enemy->bullets.begin() + counter);
            }
            counter++;
        }
}

void MainScene::updatePlayerMoving()
{
//    with walls
    if(tank->DownLeftPos().rx() > WIDTH)
        tank->setPos(WIDTH - tank->getWidth(), tank->UpRightPos().ry());
    if(tank->DownLeftPos().ry() > HEIGHT)
        tank->setPos(tank->UpRightPos().rx(), HEIGHT - tank->getHeight());
    if(tank->UpRightPos().rx() < 0)
        tank->setPos(0 + tank->getWidth() - tank->getBodyLen(), tank->UpRightPos().ry());
    if(tank->UpRightPos().ry() < 0)
        tank->setPos(tank->UpRightPos().rx(), 0 + tank->getHeight() - tank->getBodyLen());

}

void MainScene::UpdateEnemiesMoving()
{
//    with walls
    for(auto *enemy : enemies)
    {
        if(enemy->DownLeftPos().rx() > WIDTH)
        {
            enemy->setPos(WIDTH - enemy->getWidth(), enemy->UpRightPos().ry());
            enemy->CanMove(false);
        }
        if(enemy->DownLeftPos().ry() > HEIGHT)
        {
            enemy->setPos(enemy->UpRightPos().rx(), HEIGHT - enemy->getHeight());
            enemy->CanMove(false);
        }
        if(enemy->UpRightPos().rx() < 0)
        {
            enemy->setPos(0, enemy->UpRightPos().ry());
            enemy->CanMove(false);
        }
        if(enemy->UpRightPos().ry() < 0)
        {
            enemy->setPos(enemy->UpRightPos().rx(), 0);
            enemy->CanMove(false);
        }
    }
}

void MainScene::updateTanksCollision()
{
    this->updatePlayerMoving();
    this->UpdateEnemiesMoving();
}

void MainScene::updateTimerSlot()
{
    this->updateBulletsCollision();
    this->updateTanksCollision();
}

/*
 *protected:
 * bool eventFilter(QObject *obj, QEvent *event) override;
 * bool upKey, downKey, rightKey, leftKey, fireKey;
 * void updateKeys();
 *
 *    // try fix moving with help of filters
 *    // in ctor:
 *    installEventFilter(this);
 *    upKey = downKey = rightKey = leftKey = fireKey = false;
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
