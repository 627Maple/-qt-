#ifndef DEMONSTRATION_H
#define DEMONSTRATION_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QApplication>
#include <QFileDialog>
#include <QImage>
#include <QDialog>
#include <QPoint>
#include <QTimer>
#include "implement.h"

namespace Ui {
class Demonstration;
}



class Demonstration : public QWidget
{
    Q_OBJECT

public:
    explicit Demonstration(QWidget *parent = 0);
    ~Demonstration();

     int X;               //坐标偏移
     int Y;
     int X_Offset;        //画布偏移
     int Y_Offset;
     int Show_People;     //显示人
     int Day;
     int Hour;
     int Minute;
     //int Second;
     int Original;        //初始间隔
     int Rate;            //比率
     int TimerID;         //定时器

     class City* city[2];
     class Building* building[46];
     class Person* person[8000];
     class Tree* tree[2];


    enum  Type {
        None          = 0,
        Amplification ,
        Shrink,
        Lift,
        Right,
        Up,
        Down,
        Move,
        Reset
    };

private:
    Ui::Demonstration *ui;

    QPixmap  pix;
    QPixmap  crtPix;
    QPalette re;

    int num;   //可去
    int Num;
    bool M_IM;
    bool V_IM;
    bool Q_IM;
    bool BQ_IM;


    int action;          //动作(放大,缩小,移动...)
    int pixW;            //图片宽
    int pixH;            //图片高

    QRect Paint;         //绘画区域

    QImage image;        //打开的图片


    float ratio;              //缩放比例
    QPoint offset;           //一次的图片偏移值
    QPoint Alloffset;          //总偏移

    void AddComboItem(QComboBox* cmbo);

    virtual void mouseDoubleClickEvent(QMouseEvent *ev);

    bool event(QEvent * event);
    void wheelEvent(QWheelEvent* e);     //鼠标滑轮事件
private slots:
    void    onUpClicked();
    void    onDownClicked();
    void    onResetClicked(); //重置操作
    void    OnLiftClicked();
    void    OnRightClicked();
    void    onLittleClicked();
    void    onBigClicked();

    void    onOpenClicked();

    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

signals:
    //写一个自定义信号，告诉主场景点击了返回
    void chooseSceneBack();


};

#endif // DEMONSTRATION_H
