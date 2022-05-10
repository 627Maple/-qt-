#include "demonstration.h"
#include "ui_demonstration.h"
//#include "simulation.h"
#include <QDebug>
#include <QPainter>
#include "implement.h"
#include "simulation.h"
#include "dialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "QTextStream"

Demonstration::Demonstration(QWidget *parent) :
    QWidget(parent),
    Paint(5,5,910,910),   //绘画区域
    ui(new Ui::Demonstration)
{
    ui->setupUi(this);
    ratio= 1.0;             //初始化图片缩放比例
    Day = 1;
    Hour = 0;
    Minute = 0;
    Num = 0;
    M_IM = false;
    V_IM = false;
    Q_IM = false;
    BQ_IM = false;
    //Second = 0;
    Original = 1000;
    Rate = 1;
    action = Demonstration::None;
    connect(ui->BigButton,SIGNAL(clicked()),this,SLOT(onBigClicked()));
    connect(ui->LittleButton,SIGNAL(clicked()),this,SLOT(onLittleClicked()));
    connect(ui->LiftButton,SIGNAL(clicked()),this,SLOT(OnLiftClicked()));
    connect(ui->RightButton,SIGNAL(clicked()),this,SLOT(OnRightClicked()));
    connect(ui->UpButton,SIGNAL(clicked()),this,SLOT(onUpClicked()));
    connect(ui->DownButton,SIGNAL(clicked()),this,SLOT(onDownClicked()));
    connect(ui->ResetButton,SIGNAL(clicked()),this,SLOT(onResetClicked()));
    connect(ui->OpenButton,SIGNAL(clicked()),this,SLOT(onOpenClicked()));
    connect(ui->ShowPeople,&QCheckBox::stateChanged,[=](int state){    //多选，2是选中，0是未选中
        Show_People = state;
        Demonstration::update();
    });
    connect(ui->Save,&QPushButton::clicked,[=](){
        QString str =  QFileDialog::getOpenFileName(this,"打开文件","C:\\Users");
        QFile file1(str);
        if(file1.open(QIODevice::WriteOnly | QIODevice::Text)){
             QTextStream out(&file1);
             for(int i = 0;i < city[0]->Health->size();i++)
             {
                 out << i + 1 << " " << city[0]->Health->at(i) << " " << city[0]->Light_Sick->at(i) << " " << city[0]->Heavy_Sick->at(i) << " " << city[0]->Dead->at(i) << " " << city[0]->Vaccines->at(i);
                 out << endl;
             }
             file1.close();
             QMessageBox::information(this,"事件","已成功保存");
             }
    });
    connect(ui->Start,&QPushButton::clicked,[=](){
        TimerID = startTimer(Original / Rate);
    });
    connect(ui->Pause,&QPushButton::clicked,[=](){
        killTimer(TimerID);
    });
    void(QSpinBox:: *spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->SpeedUp,spSignal,ui->Speed,&QSlider::setValue);
    connect(ui->Speed,QSlider::valueChanged,ui->SpeedUp,&QSpinBox::setValue);
    connect(ui->SpeedUp,spSignal,[=](){
        killTimer(TimerID);
        TimerID = startTimer(Original / ui->SpeedUp->value());
        Rate = ui->SpeedUp->value();
    });
    connect(ui->Speed,&QSlider::valueChanged,[=](){
        killTimer(TimerID);
        TimerID = startTimer(Original / ui->Speed->value());
        Rate = ui->Speed->value();
    });


    ui->label->setText("100%");
    this->setWindowTitle("疫情模拟");
    connect(ui->Return,&QPushButton::clicked,[=](){    //返回，显示上一级widget
    emit this->chooseSceneBack();
    });

    re.setColor(QPalette::WindowText,Qt::green);
    ui->one->setPalette(re);
    re.setColor(QPalette::WindowText,Qt::yellow);
    ui->two->setPalette(re);
    re.setColor(QPalette::WindowText,Qt::red);
    ui->three->setPalette(re);
    re.setColor(QPalette::WindowText,Qt::black);
    ui->four->setPalette(re);
    re.setColor(QPalette::WindowText,Qt::blue);
    ui->five->setPalette(re);

    image.load(":/File_Sourse/map.png");
    pix = pix.fromImage(image);
    crtPix = pix;
    num = 0;
    pixW = image.width();            //图片宽
    pixH = image.height();           //图片高

    //qDebug() << building[15]->Name <<  building[4]->Name << building[8]->Name;
    //qDebug() << person[15]->Name <<  person[4]->Name << person[8]->Name;


}

void Demonstration::mouseDoubleClickEvent(QMouseEvent *ev)   //双击左键
{
   int n = Mouse_In_Where(ev->x(),ev->y(),X,Y,X_Offset,Y_Offset,Demonstration::building);
   if(0 <= n && n <= 45)
   {
       Dialog* dla = new Dialog(this,n,Demonstration::building,Demonstration::person,Demonstration::tree);
       //dla->resize(400,350);
       dla->setWindowTitle(Demonstration::building[n]->Name);
       //QLabel label(QString::number(Demonstration::building[n]->Liquidity_Index));

       dla->exec();
   }



}

bool Demonstration::event(QEvent * event)
{
    static bool press=false;
    static QPoint PreDot;
    if(event->type() == QEvent::MouseButtonPress )
    {
           QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

           //判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
           if(mouse->button()==Qt::LeftButton && Paint.contains(mouse->pos()))
           {
               press=true;
               QApplication::setOverrideCursor(Qt::OpenHandCursor); //设置鼠标样式
               //qDebug() << mouse->x() << mouse->y();   //输出鼠标当前的坐标位置
               PreDot = mouse->pos();
               num = 1;
           }

    }
    else if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

        //判断鼠标是否是左键释放,且之前是在绘画区域
        if(mouse->button()==Qt::LeftButton && press )
        {
            QApplication::setOverrideCursor(Qt::ArrowCursor); //改回鼠标样式
            press=false;
        }
    }

     if(event->type() == QEvent::MouseMove)              //移动图片
     {
          if(press)
         {
            QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
            offset.setX(mouse->x() - PreDot.x());
            offset.setY(mouse->y() - PreDot.y());
            PreDot = mouse->pos();
            action = Demonstration::Move;
            this->update();
         }
     }
    return QWidget::event(event);
}


void Demonstration::wheelEvent(QWheelEvent* event)     //鼠标滑轮事件
{
 if (event->delta()>0) {      //上滑,缩小
    action=Demonstration::Shrink;
    this->update();
 } else {                    //下滑,放大
     action=Demonstration::Amplification;
     this->update();
 }
 event->accept();
}


void Demonstration::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform|QPainter::Antialiasing|QPainter::TextAntialiasing);
    painter.drawRect(Paint.x()-1,Paint.y()-1,Paint.width()+1,Paint.height()+1); //画框

    if(image.isNull())
    {
     return;
    }

    int NowW = ratio *pixW;
    int NowH = ratio *pixH;

    if(action==Demonstration::Shrink)           //缩小
    {
          ratio-=0.05*ratio;
        if(ratio<0.018)
          ratio = 0.01;

        /*显示比例*/
        QString str;
        str.sprintf("%.0f%",ratio*100);
        ui->label->setText(str) ;
        qDebug()<<"缩小:"<<ratio;
    }
    else  if(action==Demonstration::Amplification)           //放大
    {

         ratio+=0.05*ratio;
       if(ratio>4.5)
         ratio = 5.000;

        /*显示比例*/
        QString str;
        str.sprintf("%.0f%",ratio*100);
        ui->label->setText(str);
        qDebug()<<"放大:"<<ratio;
    }


    if(action==Demonstration::Amplification || action==Demonstration::Shrink || action==Demonstration::Reset)      //更新图片
    {
      NowW = ratio *pixW;
      NowH = ratio *pixH;


      crtPix= pix.scaled(NowW, NowH,Qt::KeepAspectRatio,Qt::SmoothTransformation); //重新装载

      action=Demonstration::None;
    }

    if(action==Demonstration::Move)                    //移动
    {
        int offsetx=Alloffset.x()+offset.x();
        Alloffset.setX(offsetx);

        int offsety=Alloffset.y()+offset.y();
        Alloffset.setY(offsety);
        action=Demonstration::None;
    }

    if(abs(Alloffset.x())>=(Paint.width()/2 + NowW/2 -10))    //限制X偏移值
    {
        if(Alloffset.x()>0)
            Alloffset.setX(Paint.width()/2 + NowW/2 -10);
        else
         Alloffset.setX(-Paint.width()/2 + -NowW/2 +10);

    }
    if(abs(Alloffset.y())>=(Paint.height()/2 + NowH/2 -10))    //限制Y偏移值
    {
        if(Alloffset.y()>0)
            Alloffset.setY(Paint.height()/2 + NowH/2 -10);
        else
         Alloffset.setY(-Paint.height()/2 + -NowH/2 +10);

    }

    int x = Paint.width()/2 + Alloffset.x() -NowW/2;
    if(x<0)
        x=0;

    int y = Paint.height()/2 + Alloffset.y() -NowH/2;
    if(y<0)
        y=0;

    int  sx = NowW/2 - Paint.width()/2 - Alloffset.x();
    if(sx<0)
        sx=0;

    int  sy = NowH/2 - Paint.height()/2 - Alloffset.y();
    if(sy<0)
        sy=0;

    int w =(NowW - sx)>Paint.width()? Paint.width() : (NowW - sx);
    if(w>(Paint.width()-x))
        w = Paint.width()-x;

    int h =(NowH - sy)>Paint.height()? Paint.height() : (NowH - sy);
    if(h>(Paint.height()-y))
        h = Paint.height()-y;

     X = x+Paint.x();
     Y = y+Paint.y();
     X_Offset = sx;
     Y_Offset = sy;
     painter.drawTiledPixmap(X,Y,w,h,crtPix,sx,sy);            //绘画图形

     if(Show_People == 2)
     {
         for(int i = 0;i < Demonstration::city[0]->Total_People;i++)
         {

             if(person[i]->Health == 1) painter.setBrush(Qt::green);
             if(person[i]->Health == 2) painter.setBrush(QBrush(QColor(225,128,0)));
             if(person[i]->Health == 3) painter.setBrush(Qt::red);
             if(person[i]->Health != 4)
             {
                 if(X_Offset == 0 && Y_Offset ==0)
                  {
                     if(5 <= person[i]->Pos_x + X && person[i]->Pos_x + X <= 910 && 5 <= person[i]->Pos_y + Y && person[i]->Pos_y + Y <= 910)
                        painter.drawEllipse(QPoint(person[i]->Pos_x + X,person[i]->Pos_y + Y),4,4);
                  }
                  if(X == 5 && Y == 5)
                  {
                      if(5 <= person[i]->Pos_x - X_Offset && person[i]->Pos_x - X_Offset <= 910 && 5 <= person[i]->Pos_y - Y_Offset && person[i]->Pos_y - Y_Offset <= 910 )
                        painter.drawEllipse(QPoint(person[i]->Pos_x - X_Offset,person[i]->Pos_y - Y_Offset),4,4);
                  }
                  if(Y == 5 && X_Offset == 0)  //超出边框
                  {
                      if(5 <= person[i]->Pos_x + X && person[i]->Pos_x + X <= 910 && person[i]->Pos_y - Y_Offset && person[i]->Pos_y - Y_Offset <= 910 )
                        painter.drawEllipse(QPoint(person[i]->Pos_x + X,person[i]->Pos_y - Y_Offset),4,4);
                  }
                  if(X == 5 && Y_Offset == 0)
                  {
                      if(5 <= person[i]->Pos_x - X_Offset && person[i]->Pos_x - X_Offset <= 910 && 5 <= person[i]->Pos_y + Y && person[i]->Pos_y + Y <= 910 )
                        painter.drawEllipse(QPoint(person[i]->Pos_x - X_Offset,person[i]->Pos_y + Y),4,4);
                  }
             }
         }
      }

}

void  Demonstration::onLittleClicked()
{
  action=Demonstration::Amplification;
  this->update();
}

void Demonstration::onOpenClicked()
{


    QString str = QFileDialog::getOpenFileName(this,
                                 "open",
                                 "D:",
                                 "img (*.png *.jpg)");

    if(!str.isNull())
    {
       image.load(str);
       pix = pix.fromImage(image);
       crtPix = pix;
       num = 0;
       pixW = image.width();            //图片宽
       pixH = image.height();           //图片高
       //this->setWindowTitle("图片浏览器("+str+")");
       onResetClicked();
    }
}

void  Demonstration::onBigClicked()
{
  action=Demonstration::Shrink;
  this->update();
}
void Demonstration::onUpClicked()
{
  action=Demonstration::Move;
  offset.setX(0);
  offset.setY(-20);

  this->update();
}
void Demonstration::onDownClicked()
{
  action=Demonstration::Move;
  offset.setX(0);
  offset.setY(20);
  this->update();
}
void Demonstration::onResetClicked()
{
  action=Demonstration::Reset;
  Alloffset.setX(0);
  Alloffset.setY(0);
  ratio = 1.000;
  ui->label->setText("100%");
  this->update();
}
void Demonstration::OnLiftClicked()
{
  action=Demonstration::Move;
  offset.setX(-20);
  offset.setY(0);

  this->update();
}
void Demonstration::OnRightClicked()
{
  action=Demonstration::Move;
  offset.setX(20) ;
  offset.setY(0) ;

  this->update();
}

Demonstration::~Demonstration()
{
    delete ui;
}

void Demonstration::timerEvent(QTimerEvent *event)
{  
    if (event->timerId() == TimerID)
    {
      Minute++;
      if (Minute == 60)
      {
        Minute = 0;
        Hour++;
        if(Hour == 24)
        {
           Hour = 0;

           city[0]->Health->push_back(city[0]->Total_Health);
           city[0]->Light_Sick->push_back(city[0]->Total_Light_Sick);    //累积感染人数
           city[0]->Heavy_Sick->push_back(city[0]->Total_Heavy_Sick);
           city[0]->Dead->push_back(city[0]->Total_Dead);
           city[0]->Vaccines->push_back(city[0]->Total_Vaccines);
           Day++;
           Day_Add(Demonstration::city,Demonstration::building,Demonstration::person);
           re.setColor(QPalette::WindowText,Qt::green);
           ui->one->setPalette(re);
           ui->one->setText("健康：" + QString::number(city[0]->Total_Health));
           re.setColor(QPalette::WindowText,QColor(225,128,0));
           ui->two->setPalette(re);
           ui->two->setText("感染者：" + QString::number(city[0]->Total_Light_Sick));
           re.setColor(QPalette::WindowText,Qt::red);
           ui->three->setPalette(re);
           ui->three->setText("重症患者：" + QString::number(city[0]->Total_Heavy_Sick));
           re.setColor(QPalette::WindowText,Qt::black);
           ui->four->setPalette(re);
           ui->four->setText("死亡：" + QString::number(city[0]->Total_Dead));
        }
      }
      QString str = QString::number(Hour) + "时" + QString::number(Minute) + "分";
      ui->Day_Time->setText(str);
      QString sr = "第" + QString::number(Day) + "天";
      ui->Day->setText(sr);

      if(Day == 1 && Hour == 0 && Minute == 1)
      {
          Initial_City(Demonstration::city);            //初始化城市
          //qDebug() << city[0]->Mark <<  city[0]->Rt << city[0]->Total_People << city[0]->Total_Light_Sick << city[0]->Quuarantine_Speed  << city[0]->Vaccines_Speed;
          Initial_Building(Demonstration::building);    //初始化建筑
          Initial_Person(Demonstration::city,Demonstration::person,Demonstration::tree);        //初始化人
          Initial_PersonInBuilding(Demonstration::city,Demonstration::building,Demonstration::person);
          re.setColor(QPalette::WindowText,Qt::green);
          ui->one->setPalette(re);
          ui->one->setText("健康：" + QString::number(city[0]->Total_Health));
          re.setColor(QPalette::WindowText,QColor(225,128,0));
          ui->two->setPalette(re);
          ui->two->setText("感染者：" + QString::number(city[0]->Total_Light_Sick));
          re.setColor(QPalette::WindowText,Qt::red);
          ui->three->setPalette(re);
          ui->three->setText("重症患者：" + QString::number(city[0]->Total_Heavy_Sick));
          re.setColor(QPalette::WindowText,Qt::black);
          ui->four->setPalette(re);
          ui->four->setText("死亡：" + QString::number(city[0]->Total_Dead));
          re.setColor(QPalette::WindowText,Qt::blue);
          ui->five->setPalette(re);
          ui->five->setText("已接种疫苗：" + QString::number(city[0]->Total_Vaccines));      

      }
      if( (Minute == 20 || Minute == 40 || Minute == 60) && Q_IM == false)
      {
          Move_All(Demonstration::city,Demonstration::building,Demonstration::person);
          Demonstration::update();     
      }
      if( (Minute == 20 || Minute == 40 || Minute == 60) && Q_IM == true)
      {
          Move_All2(Demonstration::city,Demonstration::building,Demonstration::person);
          Demonstration::update();
      }



      if(Hour % 4 == 0 && Minute == 30)   //感染
      {
          Infection(Demonstration::city,Demonstration::building,Demonstration::person,Demonstration::tree);
          Infection_Move(Demonstration::building,Demonstration::person);

//          int num = 0;
//          int k = 0;
//          for(int i = 0;i < 46;i++ )
//          {
//              num = num + building[i]->Health->size();
//              k = k + building[i]->Light_Sick->size();
//          }
//          qDebug() << num << k;

          re.setColor(QPalette::WindowText,Qt::green);
          ui->one->setPalette(re);
          ui->one->setText("健康：" + QString::number(city[0]->Total_Health));
          re.setColor(QPalette::WindowText,QColor(225,128,0));
          ui->two->setPalette(re);
          ui->two->setText("感染者：" + QString::number(city[0]->Total_Light_Sick));
      }

      if(Hour == 10 && Minute == 30 && V_IM == true)
      {
          Vaccinate_Implement(Demonstration::city,Demonstration::person);
          re.setColor(QPalette::WindowText,Qt::blue);
          ui->five->setPalette(re);
          ui->five->setText("已接种疫苗：" + QString::number(city[0]->Total_Vaccines));
      }
      if(Hour == 2 && Minute == 30 && BQ_IM == true)
      {
          B_Quarantine_Implement(Demonstration::city,Demonstration::building,Demonstration::person);
      }


      if( (city[0]->Mark == true) && (city[0]->Total_People / city[0]->Total_Light_Sick <= 20) && M_IM == false)   //感染率达到5%后开始戴口罩
      {
          killTimer(TimerID);
          QMessageBox::information(this,"事件","开始呼吁民众佩戴口罩");
          Mask_Implement(Demonstration::city,Demonstration::person);
          M_IM = true;
      }


      if( (city[0]->Vaccine == true) && (city[0]->Total_People / city[0]->Total_Light_Sick <= 10) && V_IM == false)   //感染率达到10%后开始号召接种疫苗
      {
          killTimer(TimerID);
          QMessageBox::information(this,"事件","开始呼吁民众接种疫苗");
          V_IM = true;
      }

      if( (city[0]->Quarantine == true) && (city[0]->Total_People / city[0]->Total_Light_Sick <= 7) && Q_IM == false)   //感染率达到15%后开始隔离
      {
          killTimer(TimerID);
          QMessageBox::information(this,"事件","开始执行隔离措施");
          Q_IM = true;
          Quarantine_Implement(Demonstration::city,Demonstration::building,Demonstration::person);
      }

      if( (city[0]->Big_Quarantine == true) && (city[0]->Total_People / city[0]->Total_Light_Sick <= 5) && BQ_IM == false)   //感染率达到20%后开始大规模隔离
      {
          killTimer(TimerID);
          QMessageBox::information(this,"事件","开始执行严格防疫措施");
          BQ_IM = true;
      }

    }
}




