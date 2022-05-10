#include "simulation.h"
#include "ui_simulation.h"
#include "demonstration.h"
//#include "demonstration.h"

bool Simulation::chosen1;
bool Simulation::chosen2;
bool Simulation::chosen3;
bool Simulation::chosen4;
int Simulation::chosen5;
int Simulation::chosen6;
int Simulation::chosen7;
int Simulation::chosen8;
int Simulation::chosen9;
Simulation::Simulation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);
    demonstration = new Demonstration;

    connect(demonstration,&Demonstration::chooseSceneBack,this,[=](){   //监听simulation界面的返回信号
        demonstration->hide();     //隐藏掉
        this->show();            //重新显示主场景
    });

    connect(ui->Begin_Simulation,&QPushButton::clicked,[=](){   //显示下一级map
        this->hide();
        demonstration->show();

    });
    connect(ui->Return,&QPushButton::clicked,[=](){    //返回，显示上一级widget
        emit this->chooseSceneBack();
    });
    ui->method1->setPixmap(QPixmap(":/File_Sourse/method_1.png"));
    ui->method2->setPixmap(QPixmap(":/File_Sourse/method_2.png"));
    ui->method3->setPixmap(QPixmap(":/File_Sourse/method_3.png"));
    ui->method4->setPixmap(QPixmap(":/File_Sourse/method_4.png"));
    this->setWindowTitle("防疫策略选择");

    connect(ui->Method_1,&QRadioButton::clicked,[=](){
       chosen1 = false;
       chosen2 = false;
       chosen3 = false;
       chosen4 = false;
    });
    connect(ui->Method_2,&QRadioButton::clicked,[=](){
       chosen1 = false;
       chosen2 = false;
       chosen3 = true;
       chosen4 = false;
    });
    connect(ui->Method_3,&QRadioButton::clicked,[=](){
       chosen1 = true;
       chosen2 = true;
       chosen3 = true;
       chosen4 = false;
    });
    connect(ui->Method_4,&QRadioButton::clicked,[=](){
       chosen1 = true;
       chosen2 = true;
       chosen3 = true;
       chosen4 = true;
    });

    void(QSpinBox:: *spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->Rt,spSignal,[=](){
        chosen5 = ui->Rt->value();
    });
    void(QSpinBox:: *spSignal2)(int) = &QSpinBox::valueChanged;
    connect(ui->People,spSignal2,[=](){
        chosen6 = ui->People->value();
    });
    void(QSpinBox:: *spSignal3)(int) = &QSpinBox::valueChanged;
    connect(ui->Zero,spSignal3,[=](){
        chosen7 = ui->Zero->value();
    });

    connect(ui->Slow,&QRadioButton::clicked,[=](){
        chosen8 = 1;
    });
    connect(ui->Middle,&QRadioButton::clicked,[=](){
        chosen8 = 2;
    });
    connect(ui->Fast,&QRadioButton::clicked,[=](){
        chosen8 = 3;
    });
    connect(ui->Slow_2,&QRadioButton::clicked,[=](){
        chosen9 = 1;
    });
    connect(ui->Middle_2,&QRadioButton::clicked,[=](){
        chosen9 = 2;
    });
    connect(ui->Fast_2,&QRadioButton::clicked,[=](){
        chosen9 = 3;
    });


}



Simulation::~Simulation()
{
    delete ui;
}
