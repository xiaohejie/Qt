#include "chooselevelscene.h"
#include <qmenubar.h>
#include "qpainter.h"
#include "qdebug.h"
#include "qstring.h"
#include "mypushbutton.h"
#include "qtimer.h"
#include "qlabel.h"
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡的场景
    //设置固定大小
    setFixedSize(350, 588);
    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单栏
    QMenuBar* bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu* startMenu = bar->addMenu("开始");
    //创建退出的菜单项
    QAction* quitAction = startMenu->addAction("退出");
    //点击实现退出
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    MyPushButton* backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(), this->height()-backBtn->height());
    //点击返回
    connect(backBtn, &MyPushButton::clicked, [=](){
        qDebug() << "点击了返回按钮！";
        //告诉主场景，返回了，主场景需要监听它的返回
        //加上一个延时返回
        QTimer::singleShot(100, this, [=](){
            emit this->chooseSenceBack();
        });
    });

    //创建选择关卡的按钮
    for(int i = 0; i < 20; i++){
        MyPushButton* menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(40+(i % 4) * 70, 130 + (i / 4) * 70);

        //监听每个按钮的点击事件
        connect(menuBtn, &MyPushButton::clicked, [=](){
            QString str = QString("选择的是第 %1 关").arg(i+1);
            qDebug() << str;
        });

        //设置label
        QLabel* label = new QLabel();
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        //还需要设置label上的文字对齐方式
        label->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        label->setText(QString::number(i+1));
        label->move(40+(i % 4) * 70, 130 + (i / 4) * 70);
        //设置让鼠标进行穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent*){
    //加载标题
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //加载背景
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);    //对图片进行缩放


}
