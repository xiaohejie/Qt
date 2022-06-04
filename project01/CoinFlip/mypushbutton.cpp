#include "mypushbutton.h"
#include "qdebug.h"
#include "QPropertyAnimation"
//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg){
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool res = pix.load(normalImg);
    if(!res){
        qDebug() << "图片加载失败！";
        return;
    }
    //图片加载成功
    //设置图片固定大小
    this->setFixedSize(pix.width(), pix.height());

    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
}

//设置弹跳特效
void MyPushButton::zoom1(){ //向下跳
    //创建动画对象
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    //设置动画的时间间隔
    animation->setDuration(200);
    //设置起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutInQuad);
    //执行动画
    animation->start();
}
void MyPushButton::zoom2(){ //向上跳
    //创建动画对象
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    //设置动画的时间间隔
    animation->setDuration(20);
    //设置起始位置
    animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutInQuad);
    //执行动画
    animation->start();
}

//重写按钮的按下和释放事件
void MyPushButton::mousePressEvent(QMouseEvent* e){
    //通过按钮的第二参数是否为空进行判断该事件是否进行
    if(this->pressImgPath != ""){
        QPixmap pix;
        bool res = pix.load(this->pressImgPath);
        if(!res){
            qDebug() << "图片加载失败！";
            return;
        }
        //图片加载成功
        //设置图片固定大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    //让父类执行其他的内容，否则的话就没有其他功能
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent* e){
    //通过按钮的第二参数是否为空进行判断该事件是否进行
    if(this->pressImgPath != ""){
        QPixmap pix;
        bool res = pix.load(this->normalImgPath);
        if(!res){
            qDebug() << "图片加载失败！";
            return;
        }
        //图片加载成功
        //设置图片固定大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    //让父类执行其他的内容
    return QPushButton::mouseReleaseEvent(e);
}
