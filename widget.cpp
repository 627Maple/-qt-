#include "widget.h"
#include "ui_widget.h"
#include "simulation.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    simulation = new Simulation;  //实例化场景
    statistics_1=new statistics;
    connect(simulation,&Simulation::chooseSceneBack,this,[=](){   //监听simulation界面的返回信号
        simulation->hide();     //隐藏掉
        this->show();            //重新显示主场景
     });


    connect(ui->pushButton_1,&QPushButton::clicked,[=](){  //显示下一级simulation
        this->hide();
        simulation->show();

    });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->hide();
        statistics_1->show();


    });
}


Widget::~Widget()
{
    delete ui;
}

