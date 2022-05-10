#include "dialog.h"
#include "ui_dialog.h"
#include "demonstration.h"

Dialog::Dialog(QWidget *parent, int n,Building* building[],Person* person[],Tree* tree[]) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    for(int i = 0;i < 8000;i++)
    {
        persons[i] = person[i];
    }
    trees = tree[0];
    //buildings = building;
    if(building[n]->Liquidity_Index == 1)  ui->label->setText( "建筑内流动指数：良好" );
    if(building[n]->Liquidity_Index == 2)  ui->label->setText( "建筑内流动指数：一般" );
    if(building[n]->Liquidity_Index == 3)  ui->label->setText( "建筑内流动指数：较差" );
    ui->label_2->setText( "建筑内总人数：" + QString::number(building[n]->Health->size() + building[n]->Light_Sick->size() + building[n]->Heavy_Sick->size()) );
    ui->label_3->setText( "健康人数：" + QString::number(building[n]->Health->size() ));
    ui->label_4->setText( "轻症人数：" + QString::number(building[n]->Light_Sick->size() ));
    ui->label_5->setText( "重症人数：" + QString::number(building[n]->Heavy_Sick->size()) );

    ui->treeWidget->setHeaderLabels(QStringList()<<"身份编号"<<"姓名"<<"性别"<<"年龄"); //设置水平表头

    QTreeWidgetItem * one = new QTreeWidgetItem(QStringList()<<"健康");
    QTreeWidgetItem * two = new QTreeWidgetItem(QStringList()<<"感染者");
    QTreeWidgetItem * three = new QTreeWidgetItem(QStringList()<<"重症患者");  //加载顶层节点

    ui->treeWidget->addTopLevelItem(one);
    ui->treeWidget->addTopLevelItem(two);
    ui->treeWidget->addTopLevelItem(three);

    //追加子节点

    for(QList<int>::iterator it = building[n]->Health->begin(); it != building[n]->Health->end(); it++)
    {
        //vec.push_back(person[*it]);
        QStringList heal;
        if(person[*it]->Sex == false)
        {
            heal << QString::number(person[*it]->Num) << person[*it]->Name << "男" << QString::number(person[*it]->Age);
        }
        if(person[*it]->Sex == true)
        {
            heal << QString::number(person[*it]->Num) << person[*it]->Name << "女" << QString::number(person[*it]->Age);
        }
        QTreeWidgetItem * l1 = new QTreeWidgetItem(heal);
        one->addChild(l1);
    }
    for(QList<int>::iterator itt = building[n]->Light_Sick->begin(); itt != building[n]->Light_Sick->end(); itt++)
    {
        //vec.push_back(person[*itt]);
        QStringList heal2;
        if(person[*itt]->Sex == false)
        {
            heal2 << QString::number(person[*itt]->Num) << person[*itt]->Name << "男" << QString::number(person[*itt]->Age);
        }
        if(person[*itt]->Sex == true)
        {
            heal2 << QString::number(person[*itt]->Num) << person[*itt]->Name << "女" << QString::number(person[*itt]->Age);
        }
        QTreeWidgetItem * l2 = new QTreeWidgetItem(heal2);
        two->addChild(l2);
    }
    for(QList<int>::iterator iit = building[n]->Heavy_Sick->begin(); iit != building[n]->Heavy_Sick->end(); iit++)
    {
        //vec.push_back(person[*iit]);
        QStringList heal3;
        if(person[*iit]->Sex == false)
        {
            heal3 << QString::number(person[*iit]->Num) << person[*iit]->Name << "男" << QString::number(person[*iit]->Age);
        }
        if(person[*iit]->Sex == true)
        {
            heal3 << QString::number(person[*iit]->Num) << person[*iit]->Name << "女" << QString::number(person[*iit]->Age);
        }
        QTreeWidgetItem * l3 = new QTreeWidgetItem(heal3);
        three->addChild(l3);
    }


    //右键弹出菜单-右键菜单支持
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(OnWidgetContextMeun(QPoint)));
    connect(ui->actionAdd,SIGNAL(triggered(bool)),this,SLOT(OnMenuAdd()));
    //connect(ui->actionRemove,SIGNAL(triggered(bool)),this,SLOT(OnMenuRemove()));




}

int Dialog::OnWidgetContextMeun(const QPoint &pt){
    //当前选中项
    QTreeWidgetItem *selected=ui->treeWidget->itemAt(pt);
    //qDebug()<<row;


    QMenu menu;
    menu.addAction(ui->actionAdd);
    if(selected){
       //menu.addAction(ui->actionRemove);
    }
    //显示菜单
    menu.exec(ui->treeWidget->mapToGlobal(pt));
    return 0;
}

int Dialog::OnMenuAdd(){
    QString msg = ui->treeWidget->currentItem()->text(0); //获取当前行的数据
    int mgs = msg.toInt();
//    Person* current;
//    for(int i = 0;i < vec.size();i++)
//    {
//        if(vec[i]->Num == mgs) current = vec[i];
//    }
    //qDebug()<< person[mgs]->Num << person[mgs]->Name ;
    //QMessageBox::information(this,tr("提示"),"当前选中的信息为:"+msg,QMessageBox::Ok);
    ui->textEdit->clear();
    ui->textEdit->append("编号:" + QString::number( persons[mgs]->Num ) );
    ui->textEdit->append("年龄:" +  persons[mgs]->Name );
    if(persons[mgs]->Sex == false)
    {
        ui->textEdit->append("性别:男");
    }
    else
    {
        ui->textEdit->append("性别:女");
    }
    if(persons[mgs]->Health == 1)  ui->textEdit->append("健康状况：健康");
    if(persons[mgs]->Health == 2)  ui->textEdit->append("健康状况：轻症感染");
    if(persons[mgs]->Health == 3)  ui->textEdit->append("健康状况：重症感染");

    if(persons[mgs]->Mask == false)
    {
        ui->textEdit->append("是否佩戴口罩:否");
    }
    else
    {
        ui->textEdit->append("是否佩戴口罩:是");
    }
    if(persons[mgs]->Quarantine == false)
    {
        ui->textEdit->append("是否已经隔离:否");
    }
    else
    {
        ui->textEdit->append("是否已经隔离:是");
    }
    if(persons[mgs]->Vaccines == false)
    {
        ui->textEdit->append("是否已接种疫苗:否");
    }
    else
    {
        ui->textEdit->append("是否已接种疫苗:是");
    }

    if(persons[mgs]->Health != 1)
    {
        trees->Height(trees->root,0,mgs);
        ui->textEdit->append("感染情况：第" + QString::number( trees->hei ) + "代");
        int pp;
        for(int j = 0;j < trees->index.size();j++)
        {
            if(trees->index[j]->data == mgs) pp = trees->index[j]->par;
        }
        if(pp == -1)
        {
            ui->textEdit->append("感染的上一代:无");
        }
        else
        {
            ui->textEdit->append("感染的上一代:");
            ui->textEdit->append(QString::number( pp ) + " " + persons[pp]->Name);
        }

        trees->Next_Generation(mgs);
        if(trees->next.size() == 0)
        {
            ui->textEdit->append("感染的下一代:无");
        }
        else
        {
            ui->textEdit->append("感染的下一代:");
            for (int i = 0; i < trees->next.size(); i++)
            {
                ui->textEdit->append(QString::number( i ) + " " + persons[i]->Name);
            }
        }

    }
    return 0;
}

//int Dialog::OnMenuRemove(){
//    QString msg=ui->treeWidget->currentItem()->text(0); //获取当前行的数据
//    //qDebug()<<msg;

//    QMessageBox::information(this,tr("提示"),"当前选中的信息为:"+msg,QMessageBox::Ok);
//    return 0;
//}


Dialog::~Dialog()
{
    delete ui;
}




