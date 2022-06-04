#include "mainscene.h"
#include "ui_mainscene.h"
#include "qpainter.h"
#include "mypushbutton.h"
#include "qdebug.h"
#include <QTimer>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

/*配置主场景*/
    //设置固定大小
    setFixedSize(350, 588);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("翻金币主场景");
    //实现退出按钮
    connect(ui->actionquit, &QAction::triggered, [=](){
       this->close();
    });

    //开始按钮
    MyPushButton* startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.7);

    //实例化选择关卡场景
    chooseSence =  new ChooseLevelScene;

    //监听选择关卡的返回按钮的信号
    connect(chooseSence, &ChooseLevelScene::chooseSenceBack, this, [=](){
        chooseSence->hide();    //将选择关卡场景隐藏
       this->show();        //重新显示主场景
    });

    connect(startBtn, &MyPushButton::clicked, [=](){
        qDebug() << "点击了开始按钮！";
        //设置弹起特效
        startBtn->zoom1();
        startBtn->zoom2();

        //延时
        QTimer::singleShot(100, this, [=](){
            //进入到选择关卡界面：（1）将自身隐藏（2）显示选择关卡场景
            this->hide();
            chooseSence->show();

        });
    });

}

/*画背景图*/
void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");     //加载背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画背景上的图标
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);    //对图片进行缩放
    painter.drawPixmap(10, 30, pix);
}

MainScene::~MainScene()
{
    delete ui;
}

