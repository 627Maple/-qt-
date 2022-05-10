#include "implement.h"
#include "demonstration.h"
#include "simulation.h"
#include <QDebug>
implement::implement()
{

}
void Initial_City(City* city[])
{
    city[0] = new City;
    city[0]->Health = new QVector<int>;
    city[0]->Light_Sick = new QVector<int>;
    city[0]->Heavy_Sick = new QVector<int>;
    city[0]->Dead = new QVector<int>;
    city[0]->Vaccines = new QVector<int>;

    city[0]->Mark = Simulation::chosen1;
    city[0]->Quarantine = Simulation::chosen2;
    city[0]->Vaccine = Simulation::chosen3;
    city[0]->Big_Quarantine = Simulation::chosen4;
    city[0]->Rt = Simulation::chosen5;
    city[0]->Total_People = Simulation::chosen6;
    city[0]->Total_Health = Simulation::chosen6 - Simulation::chosen7;
    city[0]->Total_Light_Sick = Simulation::chosen7; //零代病人
    city[0]->Total_Heavy_Sick = 0;
    city[0]->Total_Dead = 0;
    city[0]->Total_Vaccines = 0;

    city[0]->Quuarantine_Speed = Simulation::chosen8;
    city[0]->Vaccines_Speed = Simulation::chosen9;
}

void Person::Initial_Pos()
{
    Pos_x = rand()%4140 + 3;
    Pos_y = rand()%2400 + 3;
    if(816 < Pos_x && Pos_x < 1215 && 543 < Pos_y && Pos_y < 1017) return Initial_Pos();
    if(2626 < Pos_x && Pos_x < 2908 && 8 < Pos_y && Pos_y < 2397) return Initial_Pos();
    if(2996 < Pos_x && Pos_x < 4144 && 1013 < Pos_y && Pos_y < 1905) return Initial_Pos();
}

Person::Person(int n,QString na,int ag,bool se)
{
    Num = n;
    Name = na;
    Age = ag;
    Sex = se;
    Health = 1;
    Quarantine = false;   //隔离，0为未隔离
    Vaccines = false;     //疫苗，0为未打疫苗
    Mask = false;         //口罩，0为未戴口罩
    Where = -1;       //所在建筑对应下标
    Day_L = 0;
    Day_H = 0;
}

Building::Building(QString str,int index,int X1,int Y1,int X2,int Y2)
{
    Health = new QList<int>;
    Light_Sick = new QList<int>;
    Heavy_Sick = new QList<int>;
    Name = str;
    Liquidity_Index = index;   //传播系数
    x1 = X1;
    y1 = Y1;
    x2 = X2;
    y2 = Y2;
}

void Initial_Building(Building* building[])  //初始化各个建筑物
{
    QFile file1(":/File_Sourse/Building_Source.txt");
    if(file1.open(QIODevice::ReadOnly | QIODevice::Text)){
    QTextStream tes1(&file1);
    for(int i = 0;i < 45;i++)
    {
        QString a;
        int b,c,d,e,f;
        tes1 >> a >> b >> c >> d >> e >> f;
        building[i] = new Building(a,b,c,d,e,f);
    }
    file1.close();
    }
    building[45] = new Building("室外",1,0,0,0,0);
}

void Initial_Person(City* city[],Person* person[],Tree* tree[])
{
      QString First_Name[120];
      QString Last_Name[120];
      srand((unsigned int)time(NULL));

      QFile file1(":/File_Sourse/First_Name.txt");
      if(file1.open(QIODevice::ReadOnly | QIODevice::Text)){
      QTextStream tes1(&file1);
      int num1 = 0;
      while(!tes1.atEnd())
      {
          tes1 >> First_Name[num1];
          num1++;
      }
      file1.close();
      }
      QFile file2(":/File_Sourse/Last_Name.txt");
      if(file2.open(QIODevice::ReadOnly | QIODevice::Text)){
      QTextStream tes2(&file2);
      int num2 = 0;
      while(!tes2.atEnd())
      {
          tes2 >> Last_Name[num2];
          num2++;
      }
      file2.close();
      }

      for(int i = 0;i < city[0]->Total_People;i++)
      {
        int judge = rand()%2;
        if(judge == 0)
        {
            person[i] = new Person(i,First_Name[rand()%120] + " " + Last_Name[rand()%120],rand()%80 + 1,false);  //男
        }
        else
        {
            person[i] = new Person(i,First_Name[rand()%120] + " " + Last_Name[rand()%120],rand()%80 + 1,true);
        }
        person[i]->Initial_Pos();

      }
      for(int j = 0;j < city[0]->Total_Light_Sick;j++)  //感染的0代病人
      {
          int num = rand()%city[0]->Total_People;
          if(person[num]->Health == 1) {
              person[num]->Health = 2;
              person[num]->Day_L++;
            }
          if(j == 0)
          {
              tree[0] = new Tree;
              tree[0]->Initial_Tree(num);
          }
          else
          {
              Node* p = tree[0]->root;
              while(p->rightchild != NULL)
              {
                  p = p->rightchild;
              }
              p->rightchild = new Node;
              p = p->rightchild;
              p->data = num;
              p->par = -1;
              p->leftchild = p->rightchild = NULL;
              tree[0]->index.push_back(p);
          }
      }
}

int Mouse_In_Where(int mouse_x,int mouse_y,int X,int Y,int X_Offset,int Y_Offset,Building* building[])   //鼠标位置所在范围
{
    //(5 <= mouse_x && mouse_x <= 910 && 5 <= mouse_y && mouse_y <= 910)

    if(X_Offset == 0 && Y_Offset == 0)
    {
        for(int i = 0;i < 45;i++)
        {
            if(building[i]->x1 <= mouse_x - X && mouse_x - X <= building[i]->x2 && building[i]->y1 <= mouse_y - Y && mouse_y - Y <= building[i]->y2)
            {
                return i;
                break;
            }
        }

    }
    else if(X == 5 && Y == 5)
    {
        for(int i = 0;i < 45;i++)
        {
            if(building[i]->x1 <= mouse_x + X_Offset && mouse_x + X_Offset <= building[i]->x2 && building[i]->y1 <= mouse_y + Y_Offset && mouse_y + Y_Offset <= building[i]->y2)
            {
                return i;
                break;
            }
        }
    }
    else if(Y == 5 && X_Offset == 0)
    {
        for(int i = 0;i < 45;i++)
        {
            if(building[i]->x1 <= mouse_x - X && mouse_x - X <= building[i]->x2 && building[i]->y1 <= mouse_y + Y_Offset && mouse_y + Y_Offset <= building[i]->y2)
            {
                return i;
                break;
            }
        }
    }
    else if(X == 5 && Y_Offset == 0)
    {
        for(int i = 0;i < 45;i++)
        {
            if(building[i]->x1 <= mouse_x + X_Offset && mouse_x + X_Offset <= building[i]->x2 && building[i]->y1 <= mouse_y - Y && mouse_y - Y <= building[i]->y2)
            {
                return i;
                break;
            }
        }
    }
    return 45;
}

void Initial_PersonInBuilding(City* city[],Building* building[],Person* person[])
{
    //qDebug() << city->Total_People << city->Total_Health;
    for(int i = 0;i < 45;i++)
    {
        for(int j = 0;j < city[0]->Total_People;j++)
        {
            if(building[i]->x1 <= person[j]->Pos_x && person[j]->Pos_x <= building[i]->x2 && building[i]->y1 <= person[j]->Pos_y && person[j]->Pos_y <= building[i]->y2)
            {
                person[j]->Where = i;
                if(person[j]->Health == 1) building[i]->Health->push_back(j);
                if(person[j]->Health == 2) building[i]->Light_Sick->push_back(j);
                if(person[j]->Health == 3) building[i]->Heavy_Sick->push_back(j);
                //if(person[j]->Vaccines == true) building[i]->Vaccines.push_back(j);
            }
        }
    }
    for(int j = 0;j < city[0]->Total_People;j++)
    {
        if(person[j]->Where == -1)
        {
        person[j]->Where = 45;   //在户外街道上
        if(person[j]->Health == 1) building[45]->Health->push_back(j);
        if(person[j]->Health == 2) building[45]->Light_Sick->push_back(j);
        if(person[j]->Health == 3) building[45]->Heavy_Sick->push_back(j);
        //if(person[j]->Vaccines == true) building[41]->Vaccines.push_back(j);
        }
    }
}

void OutBuilding(int k,int n,Building* building[],Person* person[])    //建筑下标，人下标
{
    if(person[n]->Health == 1)
    {
        building[k]->Health->removeOne(n);
//        for(QList<int>::iterator it = building[k]->Health->begin(); it != building[k]->Health->end();) {
//                if(*it == n)  it = building[k]->Health->erase(it);
//                else ++it;
//            }
    }
    if(person[n]->Health == 2)
    {
        building[k]->Light_Sick->removeOne(n);
//        for(QList<int>::iterator it = building[k]->Light_Sick->begin(); it != building[k]->Light_Sick->end();) {
//                if(*it == n)   it = building[k]->Light_Sick->erase(it);
//                else ++it;
//            }
    }
    if(person[n]->Health == 3)
    {
        building[k]->Heavy_Sick->removeOne(n);
//        for(QList<int>::iterator it = building[k]->Heavy_Sick->begin(); it != building[k]->Heavy_Sick->end();) {
//                if(*it == n)   it =  building[k]->Heavy_Sick->erase(it);
//                else ++it;
//            }
    }
}

void InBuilding(int k,int n,Building* building[],Person* person[])    //建筑下标，人下标
{
    if(person[n]->Health == 1)  building[k]->Health->push_back(n);
    if(person[n]->Health == 2)  building[k]->Light_Sick->push_back(n);
    if(person[n]->Health == 3)  building[k]->Heavy_Sick->push_back(n);
    person[n]->Where = k;
}

void PersonInBuilding(int n,Building* building[],Person* person[])
{
    int k = person[n]->Where;
    if(person[n]->Where == 45)    //在户外
    {
        for(int i = 0;i < 45;i++)
        {
            if(building[i]->x1 <= person[n]->Pos_x && person[n]->Pos_x <= building[i]->x2 && building[i]->y1 <= person[n]->Pos_y && person[n]->Pos_y <= building[i]->y2)
            {
                OutBuilding(45,n,building,person);          //从建筑的list容器中删除
                InBuilding(i,n,building,person);   //插入该建筑的list容器
                break;
            }
        }
    }
    else
    {
       if(building[k]->x1 > person[n]->Pos_x || person[n]->Pos_x > building[k]->x2 || building[k]->y1 > person[n]->Pos_y || person[n]->Pos_y > building[k]->y2)
       {
           OutBuilding(k,n,building,person);          //从建筑的list容器中删除
           for(int i = 0;i < 45;i++)
           {
               if(building[i]->x1 <= person[n]->Pos_x && person[n]->Pos_x <= building[i]->x2 && building[i]->y1 <= person[n]->Pos_y && person[n]->Pos_y <= building[i]->y2)
               {
                   InBuilding(i,n,building,person);   //插入该建筑的list容器
                   break;
               }          
           }
           if(person[n]->Where == k)
           {
               InBuilding(45,n,building,person);   //插入该建筑的list容器
           }
       }
    }

}

void Move_Single(int n,Building* building[],Person* person[])
{
        person[n]->Pos_x = rand()%100 + person[n]->Pos_x - 50;   //半径50范围内
        person[n]->Pos_y = rand()%100 + person[n]->Pos_y - 50;   //半径50范围内
        if(816 < person[n]->Pos_x && person[n]->Pos_x < 1215 && 543 < person[n]->Pos_y && person[n]->Pos_y < 1017)        person[n]->Initial_Pos();
        if(2626 < person[n]->Pos_x && person[n]->Pos_x < 2908 && 8 < person[n]->Pos_y && person[n]->Pos_y < 2397)         person[n]->Initial_Pos();
        if(2996 < person[n]->Pos_x && person[n]->Pos_x < 4144 && 1013 < person[n]->Pos_y && person[n]->Pos_y < 1905)         person[n]->Initial_Pos();
        if(1 >= person[n]->Pos_x || person[n]->Pos_x >= 4142 || 1 >= person[n]->Pos_y || person[n]->Pos_y >= 2402)          person[n]->Initial_Pos();

        PersonInBuilding(n,building,person);
}

void Move_All(City* city[],Building* building[],Person* person[])
{
    for(int i = 0;i < (city[0]->Total_Health + city[0]->Total_Light_Sick) / 20;i++)    //有健康和轻症的人才会移动
    {
        int n = rand()%city[0]->Total_People;
        if(person[n]->Health == 1 || person[n]->Health == 2)
        {
            Move_Single(n,building,person);
        }
    }
}

void Single_Infection(int m,int n,City* city[],Building* building[],Person* person[],Tree* tree[],int parent_num)  //该健康人是否被感染
{
    //m = person[n]->Where;
    if(person[n]->Vaccines == true)                                 //已经打了疫苗有2%概率患病
    {
        int test = rand()%100;
        if(0 <= test && test <= 1) person[n]->Health = 2;
    }
    else if(person[n]->Quarantine == true)                          //已经隔离有5%概率患病
    {
        int test = rand()%100;
        if(0 <= test && test <= 4) person[n]->Health = 2;
    }
    else if(person[n]->Mask == true)
    {
        int test = rand()%100;
        if(0 <= test && test <= 9) person[n]->Health = 2;
    }
    else
    {
        int test = rand()%5;
        if(city[0]->Rt == 1)
        {
            if(test == 0) person[n]->Health = 2;
        }
        if(city[0]->Rt == 2)
        {
            if(0 <= test && test <= 1) person[n]->Health = 2;
        }
        if(city[0]->Rt == 3)
        {
            if(0 <= test && test <= 2) person[n]->Health = 2;
        }
        if(city[0]->Rt == 4)
        {
            if(0 <= test && test <= 3) person[n]->Health = 2;
        }
        if(city[0]->Rt == 5)
        {
            person[n]->Health = 2;
        }
    }
    if(person[n]->Health == 2)
    {
        person[n]->Day_L++;
        city[0]->Total_Health--;
        city[0]->Total_Light_Sick++;
        //building[m]->Health->removeOne(n);
        //building[m]->Light_Sick->push_back(n);
        tree[0]->Insert(parent_num,n);
    }
}

void Infection(City* city[],Building* building[],Person* person[],Tree* tree[])
{
    for(int i = 0;i < 46;i++)
    {
        if(!building[i]->Light_Sick->empty())
        {
            for(QList<int>::iterator p = building[i]->Light_Sick->begin(); p != building[i]->Light_Sick->end(); p++) {
                for(QList<int>::iterator o = building[i]->Health->begin(); o != building[i]->Health->end(); o++) {
                    if(person[*o]->Health == 1)
                    {
                        if(building[i]->Liquidity_Index == 1)
                        {
                            if( pow(person[*p]->Pos_x - person[*o]->Pos_x,2) + pow(person[*p]->Pos_y - person[*o]->Pos_y,2) <= 225)
                            {
                                Single_Infection(i,*o,city,building,person,tree,*p);
                            }
                        }
                        if(building[i]->Liquidity_Index == 2)
                        {
                            if( pow(person[*p]->Pos_x - person[*o]->Pos_x,2) + pow(person[*p]->Pos_y - person[*o]->Pos_y,2) <= 400)
                            {
                                Single_Infection(i,*o,city,building,person,tree,*p);
                            }
                        }
                        if(building[i]->Liquidity_Index == 3)
                        {
                            if( pow(person[*p]->Pos_x - person[*o]->Pos_x,2) + pow(person[*p]->Pos_y - person[*o]->Pos_y,2) <= 625)
                            {
                                Single_Infection(i,*o,city,building,person,tree,*p);
                            }
                        }
                    }
                }
             }
        }
        if(!building[i]->Heavy_Sick->empty())
        {
            for(QList<int>::iterator p = building[i]->Heavy_Sick->begin(); p != building[i]->Heavy_Sick->end(); p++) {
                for(QList<int>::iterator o = building[i]->Health->begin(); o != building[i]->Health->end(); o++) {
                    if(person[*o]->Health == 1)
                    {
                        if(building[i]->Liquidity_Index == 1)
                        {
                            if( pow(person[*p]->Pos_x - person[*o]->Pos_x,2) + pow(person[*p]->Pos_y - person[*o]->Pos_y,2) <= 225)
                            {
                                Single_Infection(i,*o,city,building,person,tree,*p);
                            }
                        }
                        if(building[i]->Liquidity_Index == 2)
                        {
                            if( pow(person[*p]->Pos_x - person[*o]->Pos_x,2) + pow(person[*p]->Pos_y - person[*o]->Pos_y,2) <= 400)
                            {
                                Single_Infection(i,*o,city,building,person,tree,*p);
                            }
                        }
                        if(building[i]->Liquidity_Index == 3)
                        {
                            if( pow(person[*p]->Pos_x - person[*o]->Pos_x,2) + pow(person[*p]->Pos_y - person[*o]->Pos_y,2) <= 625)
                            {
                                Single_Infection(i,*o,city,building,person,tree,*p);
                            }
                        }
                    }
                }
             }
        }
    }

}

void Infection_Move(Building* building[],Person* person[])
{
    for(int i = 0;i < 46;i++)
    {
        for(QList<int>::iterator p = building[i]->Health->begin(); p != building[i]->Health->end();) {
            if(person[*p]->Health == 2)
            {
                 building[i]->Light_Sick->push_back(*p);
                 p = building[i]->Health->erase(p);
            }
            else
            {
                ++p;
            }
        }
    }
}

void Mask_Implement(City* city[],Person* person[])
{
    for(int i = 0;i < city[0]->Total_People;i++)
    {
        person[i]->Mask = true;
    }
}

void Vaccinate_Implement(City* city[],Person* person[])
{
    for(int i = 0;i < city[0]->Total_People;i++)
    {
        if(person[i]->Health == 1 && person[i]->Vaccines == false)
        {
            int num = rand()%99;
            if(city[0]->Vaccines_Speed == 1)       //较慢
            {
                if(0 <= num && num <= 4) person[i]->Vaccines = true;
            }
            if(city[0]->Vaccines_Speed == 2)       //一般
            {
                if(0 <= num && num <= 9) person[i]->Vaccines = true;
            }
            if(city[0]->Vaccines_Speed == 3)       //较快
            {
                if(0 <= num && num <= 14) person[i]->Vaccines = true;
            }
            if(person[i]->Vaccines == true)
            {
                city[0]->Total_Vaccines++;
            }
        }
    }
}

void Quarantine_Implement(City* city[],Building* building[],Person* person[])  //执行隔离措施
{
    for(int j = 0;j < city[0]->Total_People;j++)
    {
        if(person[j]->Health != 4 && 20 <= person[j]->Where && person[j]->Where <= 45 && (person[j]->Where != 34 && person[j]->Where != 37 && person[j]->Where != 44))
        {
            int num = rand()%20;
            person[j]->Pos_x = rand()%(building[num]->x2 - building[num]->x1) + building[num]->x1;
            person[j]->Pos_y = rand()%(building[num]->y2 - building[num]->y1) + building[num]->y1;
            person[j]->Where = num;
            if(person[j]->Health == 1) building[num]->Health->push_back(j);
            if(person[j]->Health == 2) building[num]->Light_Sick->push_back(j);
            if(person[j]->Health == 3) building[num]->Heavy_Sick->push_back(j);
        }
    }
    for(int i = 20;i < 46;i++)
    {
        if(i != 44 && i != 34 && i != 37)    //隔离区和医院,学校
        {
            building[i]->Health->clear();
            building[i]->Light_Sick->clear();
            building[i]->Heavy_Sick->clear();
        }
    }
}

void Move_All2(City* city[],Building* building[],Person* person[])   //隔离时的移动
{
    for(int n = 0;n < (city[0]->Total_Health + city[0]->Total_Light_Sick)/20;n++)
    {
        int j = rand()%city[0]->Total_People;
        if(person[j]->Health == 1 || person[j]->Health == 2)
        {
            person[j]->Pos_x = rand()%100 + person[j]->Pos_x - 50;
            person[j]->Pos_y = rand()%100 + person[j]->Pos_y - 50;
            int num = person[j]->Where;
            if(person[j]->Pos_x < building[num]->x1 || person[j]->Pos_x > building[num]->x2 || person[j]->Pos_y < building[num]->y1 || person[j]->Pos_y > building[num]->y2)
            {
                person[j]->Pos_x = rand()%(building[num]->x2 - building[num]->x1) + building[num]->x1;
                person[j]->Pos_y = rand()%(building[num]->y2 - building[num]->y1) + building[num]->y1;
            }
        }
    }
}

void B_Quarantine_Implement(City* city[],Building* building[],Person* person[])
{
    for(int i = 0;i < city[0]->Total_People;i++)
    {
        if(person[i]->Health == 2 && person[i]->Where != 44)
        {
            int num = rand()%99;
            bool l = false;
            if(city[0]->Quuarantine_Speed == 1)       //较慢
            {
                if(0 <= num && num <= 19) l = true;
            }
            if(city[0]->Quuarantine_Speed == 2)       //一般
            {
                if(0 <= num && num <= 29) l = true;
            }
            if(city[0]->Quuarantine_Speed == 3)       //较快
            {
                if(0 <= num && num <= 39) l = true;
            }
            if(l == true)
            {
                building[person[i]->Where]->Light_Sick->removeOne(i);
                person[i]->Pos_x = rand()%(building[44]->x2 - building[44]->x1) + building[44]->x1;
                person[i]->Pos_y = rand()%(building[44]->y2 - building[44]->y1) + building[44]->y1;
                person[i]->Where = 44;
                building[44]->Light_Sick->push_back(i);
            }
        }
    }
}

void Day_Add(City* city[],Building* building[],Person* person[])
{
    for(int i = 0;i < city[0]->Total_People;i++)
    {
        if(person[i]->Health == 2) person[i]->Day_L++;
        if(person[i]->Health == 3) person[i]->Day_H++;

        if(person[i]->Day_L == 7)
        {
            int num = rand()%4;
            if(0 <= num && num <= 1)                //40%转重症
            {
                person[i]->Health = 3;
                person[i]->Day_L = 0;
                person[i]->Day_H++;

                int k = person[i]->Where;
                building[k]->Light_Sick->removeOne(i);
                if(building[34]->Heavy_Sick->size() <= 50)          //医院有50个重症床位
                {
                    building[34]->Heavy_Sick->push_back(i);
                    person[i]->Where = 34;
                    person[i]->Pos_x = rand()%(building[34]->x2 - building[34]->x1) + building[34]->x1;
                    person[i]->Pos_y = rand()%(building[34]->y2 - building[34]->y1) + building[34]->y1;
                }
                else
                {
                    building[k]->Heavy_Sick->push_back(i);
                }

                city[0]->Total_Light_Sick--;
                city[0]->Total_Heavy_Sick++;
           }
        }
        if(person[i]->Day_L > 10 && person[i]->Where == 44)  //在隔离区域
        {
            int num = rand()%10;
            if(0 <= num && num <= 2)    //康复
            {
                person[i]->Health = 1;
                person[i]->Day_L = 0;

                int k = rand()%20;
                building[44]->Light_Sick->removeOne(i);
                building[k]->Health->push_back(i);
                person[i]->Where = k;
                person[i]->Pos_x = rand()%(building[k]->x2 - building[k]->x1) + building[k]->x1;
                person[i]->Pos_y = rand()%(building[k]->y2 - building[k]->y1) + building[k]->y1;

                city[0]->Total_Light_Sick--;   //是当前确诊病例，不是累积
                city[0]->Total_Health++;
            }
        }
        if(person[i]->Day_L > 10 && person[i]->Where != 44)   //康复
        {
            int num = rand()%10;
            if(0 == num)    //康复
            {
                person[i]->Health = 1;
                person[i]->Day_L = 0;

                int k = person[i]->Where;
                building[k]->Light_Sick->removeOne(i);
                building[k]->Health->push_back(i);

                city[0]->Total_Light_Sick--;
                city[0]->Total_Health++;
            }
        }


        if(person[i]->Day_H > 5 && person[i]->Where == 34)  //在医院接收治疗
        {
            int num = rand()%100;
            if(0 <= num && num <= 2)    //救助情况下死亡率为3%
            {
                person[i]->Health = 4;
                person[i]->Day_H = 0;

                building[34]->Heavy_Sick->removeOne(i);

                city[0]->Total_Heavy_Sick--;
                city[0]->Total_Dead++;
            }
            else
            {
                person[i]->Health = 1;   //治愈
                person[i]->Day_H = 0;

                int k = rand()%20;
                building[34]->Heavy_Sick->removeOne(i);
                building[k]->Health->push_back(i);
                person[i]->Where = k;
                person[i]->Pos_x = rand()%(building[k]->x2 - building[k]->x1) + building[k]->x1;
                person[i]->Pos_y = rand()%(building[k]->y2 - building[k]->y1) + building[k]->y1;

                city[0]->Total_Heavy_Sick--;
                city[0]->Total_Health++;
            }
        }
        if(person[i]->Day_H > 5 && person[i]->Where != 34)  //不在医院接收治疗
        {
            int num = rand()%100;
            int p = person[i]->Where;
            if(0 <= num && num <= 14)    //不救助情况下死亡率为15%
            {
                person[i]->Health = 4;
                person[i]->Day_H = 0;

                building[p]->Heavy_Sick->removeOne(i);

                city[0]->Total_Heavy_Sick--;
                city[0]->Total_Dead++;
            }
            else
            {
                person[i]->Health = 1;   //治愈
                person[i]->Day_H = 0;

                int k = person[i]->Where;
                if(k == 44)
                {
                    int e = rand()%20;
                    building[p]->Heavy_Sick->removeOne(i);
                    building[e]->Health->push_back(i);
                    person[i]->Where = e;
                    person[i]->Pos_x = rand()%(building[e]->x2 - building[e]->x1) + building[e]->x1;
                    person[i]->Pos_y = rand()%(building[e]->y2 - building[e]->y1) + building[e]->y1;
                }
                else
                {
                    building[k]->Heavy_Sick->removeOne(i);
                    building[k]->Health->push_back(i);
                }
                city[0]->Total_Heavy_Sick--;
                city[0]->Total_Health++;
            }
        }

    }
}

void Tree::Initial_Tree(int temp)
{
    root->data = temp;
    root->leftchild = root->rightchild = NULL;
    index.push_back(root);
    root->par = -1;  //根节点父亲为-1
}

void Tree::Insert(int fu,int data)
{
    Node* p; //要插入的节点
    Node* t = NULL; //父节点
    for (int i = 0; i < index.size(); i++)
    {
        if (index[i]->data == fu)
        {
            t = index[i];
            break;
        }
    }
    if (t->leftchild == NULL)
    {
        p = new Node;
        p->data = data;
        p->leftchild = p->rightchild = NULL;
        t->leftchild = p;
        index.push_back(p);
        p->par = t->data;
    }
    else
    {
        p = t->leftchild;
        while (p->rightchild)
        {
            p = p->rightchild;
        }
        p->rightchild = new Node;
        p = p->rightchild;
        p->data = data;
        p->leftchild = p->rightchild = NULL;
        index.push_back(p);
        p->par = t->data;
    }
}


//void Tree::PostOrder(Node* root)
//{
//    //树的后序遍历
//    if (root == NULL) return;
//    PostOrder(root->leftchild);
//    PostOrder(root->rightchild);
//    //cout << root->data << " " ;
//    //cout << endl;
//}

void Tree::Height(Node* root,int height,int num)   //遍历得到树高，即感染代数
{
    if (root == NULL)
    {
        height--;
        return;
    }
    Height(root->leftchild,++height,num);
    Height(root->rightchild,--height,num);
    if (root->data == num)
    {
        hei = height;
    }
}

void Tree::Next_Generation(int num)
{
    next.clear();
    Node* t = NULL;
    for (int i = 0; i < index.size(); i++)
    {
        if (index[i]->data == num)
        {
            t = index[i];
            break;
        }
    }
    if (t->leftchild != NULL)
    {
        t = t->leftchild;
        //qDebug() << t->data << endl;
        next.push_back(t->data);
        while (t->rightchild)
        {
            t = t->rightchild;
            //qDebug() << t->data << endl;
            next.push_back(t->data);
        }
    }
}



