#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    //构造函数  参数1  正常显示的图片路径   参数2 按下后显示的图片路径
    MyPushButton(QString normalImg, QString pressImg = "");

    //成员属性  保存用户传入的默认显示路径  以及按下后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;

    //设置弹跳特效
    void zoom1();
    void zoom2();

    //重写按钮的按下和释放事件
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

signals:

};

#endif // MYPUSHBUTTON_H
