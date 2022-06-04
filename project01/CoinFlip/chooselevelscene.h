#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent*);

signals:
    //写自定义信号，告诉了主场景，点击了返回
    void chooseSenceBack();

};

#endif // CHOOSELEVELSCENE_H
