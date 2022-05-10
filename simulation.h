#ifndef SIMULATION_H
#define SIMULATION_H

#include <QWidget>
#include <demonstration.h>
//extern bool chosen1;
//extern bool chosen2;
//extern bool chosen3;
//extern bool chosen4;
//extern int chosen5;
//extern int chosen6;
//extern int chosen7;
//extern int chosen8;
//extern int chosen9;
namespace Ui {
class Simulation;
}

class Simulation : public QWidget
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = 0);
    ~Simulation();

    Demonstration* demonstration = NULL; //次一级的界面

    static bool chosen1;
    static bool chosen2;
    static bool chosen3;
    static bool chosen4;
    static int chosen5;
    static int chosen6;
    static int chosen7;
    static int chosen8;
    static int chosen9;
signals:
    //写一个自定义信号，告诉主场景点击了返回
    void chooseSceneBack();

private:
    Ui::Simulation *ui;
};


#endif // SIMULATION_H
