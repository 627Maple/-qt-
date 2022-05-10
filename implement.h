#ifndef IMPLEMENT_H
#define IMPLEMENT_H
#include <QString>
#include <QTimer>
#include <QVector>
#include <QList>
#include "demonstration.h"
#include "QFile"
#include "time.h"
#include "stdlib.h"
#include "QTextStream"
#include "QDebug"
#include <QPainter>

class implement
{
public:
    implement();
};

class Person
{
public:
    int Num;    //编号
    QString Name;  //名字
    int Age;      //年龄
    bool Sex;     //性别 0男1女

    int Health;    //健康状况：1正常；2感染者；3重症患者；4死亡
    bool Quarantine;   //隔离，0为未隔离
    bool Vaccines;     //疫苗，0为未打疫苗
    bool Mask;         //口罩，0为未戴口罩

    int Pos_x;    //位置的x坐标
    int Pos_y;    //位置的y坐标
    int Where;     //位置所在对应建筑物的下标
    int Day_L;     //轻症日期
    int Day_H;

    Person(int,QString,int,bool); //对应编号、名字、年龄、性别
    void Initial_Pos();      //初始化坐标

    //srand((unsigned int)time(NULL));
    //int Probability = rand()%101;  //感染的概率

};

class City
{
public:
    bool Mark;        //是否戴口罩
    bool Vaccine;      //是否接种疫苗
    bool Quarantine;   //是否隔离
    bool Big_Quarantine;  //是否大规模在隔离区隔离
    int Vaccines_Speed;      //疫苗接种的效率（123）5
    int Quuarantine_Speed;      //在隔离区隔离的效率4

    QVector<int> *Health;        //存储当天健康的人的人数（用于画图,下标+1是天数），Building类中则存储该建筑物中健康的人的编号
    QVector<int> *Light_Sick;    //轻症
    QVector<int> *Heavy_Sick;    //重症
    QVector<int> *Dead;          //死亡
    //<int> Total_Quarantine;    隔离
    QVector<int> *Vaccines;      //疫苗

    int Rt;                    //感染系数1
    int Total_People;          //3
    int Total_Health;          //3
    int Total_Light_Sick;      //零代病人数量2
    int Total_Heavy_Sick;
    int Total_Dead;
    int Total_Vaccines;

};

class Building
{
public:

    QString Name;   //建筑物名字
    int Liquidity_Index;  //建筑物内部的流动指数

    int x1;    //左上角横坐标
    int y1;
    int x2;    //右下角横坐标
    int y2;

    QList<int> *Health;        //存储健康人的编号，Total_Health.size()即为人数
    QList<int> *Light_Sick;    //轻症
    QList<int> *Heavy_Sick;    //重症
    //QVector<int> Quarantine;    //隔离
    //QVector<int> Dead;        //死亡
    // QVector<int> Vaccines;      //疫苗

    Building(QString,int,int,int,int,int);

};

class Node
{
public:
    int data;
    Node* leftchild;
    Node* rightchild;
    int par;
};

class Tree
{
public:
    Node* root = new Node;
    QVector<Node*> index;

    void Initial_Tree(int);
    void Insert(int,int);
    //void PostOrder(Node*);      //后序遍历
    void Height(Node*,int,int);
    void Next_Generation(int);

    int hei;
    QVector<int> next;

};


void Initial_City(City *[]);                //初始化城市
void Initial_Building(Building *[]);     //初始化建筑
void Initial_Person(City *[],Person *[],Tree *[]);         //初始化人
void Initial_PersonInBuilding(City *[],Building *[],Person *[]);         //初始化看建筑物中有哪些人
void OutBuilding(int,int,Building *[],Person *[]);    //建筑下标，人下标
void InBuilding(int,int,Building *[],Person *[]);    //建筑下标，人下标

void PersonInBuilding(Building *[],Person *[]);
void Move_Single(int, Building *[],Person *[]);
void Move_All(City *[], Building *[], Person *[]);

void Single_Infection(int,int,City *[],Building *[],Person *[],Tree *[],int); //该健康人是否被感染
void Infection(City *[],Building *[], Person *[],Tree *[]);   //感染
void Infection_Move(Building *[],Person *[]);

void Mask_Implement(City *[],Person *[]);
void Vaccinate_Implement(City *[],Person *[]);
void Quarantine_Implement(City *[],Building *[],Person *[]);
void Move_All2(City *[],Building *[],Person *[]);
void B_Quarantine_Implement(City *[],Building *[],Person *[]);
void Day_Add(City *[],Building *[],Person *[]);


int Mouse_In_Where(int,int,int,int,int,int,Building *[]);  //鼠标当前所在的建筑物


#endif // IMPLEMENT_H
