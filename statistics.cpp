#include "statistics.h"
#include"widget.h"
#include "ui_statistics.h"

statistics::statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistics)
{
    ui->setupUi(this);

    creatchart();
   // prepareDate();
    //updateFromChart();
}

statistics::~statistics()
{
    delete ui;
}


void statistics::on_actionZoomOut_triggered()
{
    ui->chartview->chart()->zoom(0.8);
     ui->chartview_2->chart()->zoom(0.8);
      ui->chartview_3->chart()->zoom(0.8);
       ui->chartview_4->chart()->zoom(0.8);
        ui->chartview_5->chart()->zoom(0.8);
         ui->chartview_6->chart()->zoom(0.8);
}

void statistics::on_actionZoomIn_triggered()
{
    ui->chartview->chart()->zoom(1.2);
    ui->chartview_2->chart()->zoom(1.2);
    ui->chartview_3->chart()->zoom(1.2);
    ui->chartview_4->chart()->zoom(1.2);
    ui->chartview_5->chart()->zoom(1.2);
    ui->chartview_6->chart()->zoom(1.2);
}

void statistics::on_actionZoomReset_triggered()
{
    ui->chartview->chart()->zoomReset();
    ui->chartview_2->chart()->zoomReset();
    ui->chartview_3->chart()->zoomReset();
    ui->chartview_4->chart()->zoomReset();
    ui->chartview_5->chart()->zoomReset();
    ui->chartview_6->chart()->zoomReset();
}

void statistics::creatchart()
{

}


void statistics::on_actionopen_triggered()
{
    QString curPath=QCoreApplication::applicationDirPath();
        QString dlgTitle="打开文件";
        QString filter="文本(*.txt);;所有（*.*）";
        QString fileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
        if(fileName.isEmpty()) return;
        QFile file(fileName);


        //    QString file_name = QFileDialog::getOpenFileName(NULL,"标题",".","*.txt");
        //    QFile file(file_name);
        if (file.open(QIODevice::ReadOnly))
        {
            r_count = 0;
            QTextStream in(&file);
            in.setCodec("GBK");

            series=new QSplineSeries();
            series_2=new QSplineSeries();
            series_2_2=new QSplineSeries();
            series_3=new QSplineSeries();
            series_4=new QSplineSeries();
            series_5=new QSplineSeries();
            set_1=new QBarSet("健康人数");
            set_2=new QBarSet("感染人数");
            set_3=new QBarSet("健康人数");
            set_4=new QBarSet("健康人数");
            set_5=new QBarSet("健康人数");



            while (!in.atEnd())
            {
                QString line=in.readLine();
                QStringList column;
                column=line.split(" ",QString::SkipEmptyParts);
                double first_column=column.at(0).toInt();
                double second_column=column.at(1).toInt();
                double third_column=column.at(2).toInt();
                double fourth_column=column.at(3).toInt();
                double fifth_column=column.at(4).toInt();
                double sixth_column=column.at(5).toInt();

                qDebug()<<first_column;qDebug()<<second_column;qDebug()<<third_column;qDebug()<<fourth_column;qDebug()<<fifth_column;qDebug()<<sixth_column;
                set_1->append(column.at(1).toInt());
                set_2->append(column.at(2).toInt());
                set_3->append(column.at(3).toInt());
                set_4->append(column.at(4).toInt());
                set_5->append(column.at(5).toInt());


                series->append(QPointF(first_column,second_column));
                series_2->append(QPointF(first_column,third_column));
                series_2_2->append(QPointF(first_column,third_column));
                series_3->append(QPointF(first_column,fourth_column));
                series_4->append(QPointF(first_column,fifth_column));
                series_5->append(QPointF(first_column,sixth_column));
                r_count ++;
            }


//            chart_1->addSeries(series);//曲线1

//            series_2->setColor(QColor(80,100,25));
//            series_2->setName("感染人数");
//            series_2->setVisible(true);
            //series_2->setPointLabelsFormat("(@xPoint,@yPoint)");
            //series_2->setPointLabelsVisible(true);

//            chart_1->addSeries(series_2);//曲线2

//            series_3->setColor(QColor(255,128,0));
//            series_3->setName("健康人数");
//            series_3->setVisible(true);
//            //series_3->setPointLabelsFormat("(@xPoint,@yPoint)");
//            //series_3->setPointLabelsVisible(true);
//            chart_1->addSeries(series_3);//曲线3

//            series_4->setColor(QColor(255,215,0));
//            series_4->setName("感染人数");
//            series_4->setVisible(true);
//            //series_2->setPointLabelsFormat("(@xPoint,@yPoint)");
//            //series_2->setPointLabelsVisible(true);
//            chart_1->addSeries(series_4);//曲线4

//            series_5->setColor(QColor(51,161,201));
//            series_5->setName("感染人数");
//            series_5->setVisible(true);
//            //series_2->setPointLabelsFormat("(@xPoint,@yPoint)");
//            //series_2->setPointLabelsVisible(true);
//            chart_1->addSeries(series_5);//曲线4



//            QValueAxis*axisx=new QValueAxis;
//            axisx->setRange(0,20);
//            axisx->setTitleText("时间");
//            QValueAxis*axisY=new QValueAxis;
//            axisY->setRange(0,3000);
//            axisY->setTitleText("人数");

//            chart_1->setAxisX(axisx,series);
//            chart_1->setAxisY(axisY,series);
//            chart_1->setAxisX(axisx,series_2);
//            chart_1->setAxisY(axisY,series_2);
//            chart_1->setAxisX(axisx,series_3);
//            chart_1->setAxisY(axisY,series_3);
//            chart_1->setAxisX(axisx,series_4);
//            chart_1->setAxisY(axisY,series_4);
//            chart_1->setAxisX(axisx,series_5);
//            chart_1->setAxisY(axisY,series_5);

//            chart_1->legend()->setVisible(true);
//            chart_1->legend()->setAlignment(Qt::AlignBottom);//底部对齐
//            chart_1->legend()->setBackgroundVisible(true);//设置背景是否可视
//            //chart->legend()->setAutoFillBackground(true);//设置背景自动填充
//            chart_1->legend()->setColor(QColor(222,233,251));//设置颜色
//            chart_1->legend()->setLabelColor(QColor(0,100,255));//设置标签颜色


//            chart_1->legend()->setMaximumHeight(100);
//            chart_1->setAnimationOptions(QChart::SeriesAnimations);//动画效果




//            QValueAxis*axisx_2=new QValueAxis;
//            axisx_2->setRange(0,20);
//            axisx_2->setTitleText("时间");
//            QValueAxis*axisY_2=new QValueAxis;
//            axisY_2->setRange(0,3000);
//            axisY_2->setTitleText("人数");
//            chart_2->addSeries(series);
//            chart_2->setAxisX(axisx_2,series);
//            chart_2->setAxisY(axisY_2,series);
//            chart_2->legend()->setVisible(true);
//            chart_2->legend()->setAlignment(Qt::AlignBottom);//底部对齐
//            chart_2->legend()->setBackgroundVisible(true);//设置背景是否可视
//            chart_2->legend()->setColor(QColor(222,233,251));//设置颜色
//            chart_2->legend()->setLabelColor(QColor(0,100,255));//设置标签颜色
//            chart_2->legend()->setMaximumHeight(100);
//            chart_2->setAnimationOptions(QChart::SeriesAnimations);//动画效果
//            ui->chartview->setChart(chart_1);
//            ui->chartview->setRenderHint(QPainter::Antialiasing);//总体的统计结果
//            ui->chartview_2->setChart(chart_2);
//            ui->chartview_2->setRenderHint(QPainter::Antialiasing);//健康人数的统计结果


}}



void statistics::on_pushButton_clicked()
{
    chart_1=new QChart();
    chart_1->setTitle("疫情模拟结果");
    chart_1->setTheme(QChart::ChartThemeLight);
    series->setColor(QColor(0,100,255));
    series->setName("健康人数");
    chart_1->addSeries(series);
//    series->setPointLabelsFormat("(@xPoint,@yPoint)");
//    series->setPointLabelsVisible(true);
//    series->setVisible(true);


    QValueAxis*axisx=new QValueAxis;
    axisx->setRange(1,r_count);
    axisx->setTitleText("时间");
    axisx->setLabelFormat("%u");
    axisx->setGridLineVisible(true);
    axisx->setTickCount(20);
    axisx->setMinorTickCount(1);

    QValueAxis*axisY=new QValueAxis;
    axisY->setRange(0,3000);
    axisY->setTitleText("人数");
    axisY->setLabelFormat("%u");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(10);
    axisY->setMinorTickCount(2);


                chart_1->setAxisX(axisx,series);
                chart_1->setAxisY(axisY,series);
                chart_1->legend()->setVisible(true);
                chart_1->legend()->setAlignment(Qt::AlignBottom);//底部对齐
                chart_1->legend()->setBackgroundVisible(true);//设置背景是否可视
                chart_1->legend()->setAutoFillBackground(true);//设置背景自动填充
                chart_1->legend()->setColor(QColor(222,233,251));//设置颜色
                chart_1->legend()->setLabelColor(QColor(0,100,255));//设置标签颜色


                chart_1->legend()->setMaximumHeight(50);
                chart_1->setAnimationOptions(QChart::SeriesAnimations);//动画效果






    ui->chartview->setChart(chart_1);

}


void statistics::on_pushButton_2_clicked()
{
    chart_2=new QChart();
    chart_2->setTitle("疫情模拟结果");
    chart_2->setTheme(QChart::ChartThemeLight);
    series_2->setColor(QColor(0,100,255));
    series_2->setName("感染人数");
    chart_2->addSeries(series_2);

    QValueAxis*axisx=new QValueAxis;
    axisx->setRange(1,r_count);
    axisx->setTitleText("时间");
    axisx->setLabelFormat("%u");
    axisx->setGridLineVisible(true);
    axisx->setTickCount(20);
    axisx->setMinorTickCount(2);

    QValueAxis*axisY=new QValueAxis;
    axisY->setRange(0,2000);
    axisY->setTitleText("人数");
    axisY->setLabelFormat("%u");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(5);
    axisY->setMinorTickCount(1);


    chart_2->setAxisX(axisx,series_2);
    chart_2->setAxisY(axisY,series_2);
    chart_2->legend()->setVisible(true);
    chart_2->legend()->setAlignment(Qt::AlignBottom);
    chart_2->legend()->setBackgroundVisible(true);
    chart_2->legend()->setAutoFillBackground(true);
    chart_2->legend()->setColor(QColor(222,233,251));
    chart_2->legend()->setLabelColor(QColor(0,100,255));


    chart_2->legend()->setMaximumHeight(50);
    chart_2->setAnimationOptions(QChart::SeriesAnimations);


    ui->chartview_2->setChart(chart_2);
}

void statistics::on_pushButton_3_clicked()
{
    chart_3=new QChart();
    chart_3->setTitle("疫情模拟结果");
    chart_3->setTheme(QChart::ChartThemeLight);
    series_3->setColor(QColor(0,100,255));
    series_3->setName("重症患者人数");
    chart_3->addSeries(series_3);

    QValueAxis*axisx=new QValueAxis;
    axisx->setRange(1,r_count);
    axisx->setTitleText("时间");
    axisx->setLabelFormat("%u");
    axisx->setGridLineVisible(true);
    axisx->setTickCount(20);
    axisx->setMinorTickCount(1);

    QValueAxis*axisY=new QValueAxis;
    axisY->setRange(0,500);
    axisY->setTitleText("人数");
    axisY->setLabelFormat("%u");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(5);
    axisY->setMinorTickCount(1);


    chart_3->setAxisX(axisx,series_3);
    chart_3->setAxisY(axisY,series_3);
    chart_3->legend()->setVisible(true);
    chart_3->legend()->setAlignment(Qt::AlignBottom);
    chart_3->legend()->setBackgroundVisible(true);
    chart_3->legend()->setAutoFillBackground(true);
    chart_3->legend()->setColor(QColor(222,233,251));
    chart_3->legend()->setLabelColor(QColor(0,100,255));


    chart_3->legend()->setMaximumHeight(50);
    chart_3->setAnimationOptions(QChart::SeriesAnimations);


    ui->chartview_3->setChart(chart_3);
}

void statistics::on_pushButton_4_clicked()
{
    chart_4=new QChart();
    chart_4->setTitle("疫情模拟结果");
    chart_4->setTheme(QChart::ChartThemeLight);
    series_4->setColor(QColor(0,100,255));
    series_4->setName("死亡人数");
    chart_4->addSeries(series_4);

//    QValueAxis*axisx=new QValueAxis;
//    axisx->setRange(1,20);
//    axisx->setTitleText("时间");
//    QValueAxis*axisY=new QValueAxis;
//    axisY->setRange(0,50);
//    axisY->setTitleText("人数");

    QValueAxis*axisx=new QValueAxis;
    axisx->setRange(1,r_count);
    axisx->setTitleText("时间");
    axisx->setLabelFormat("%u");
    axisx->setGridLineVisible(true);
    axisx->setTickCount(20);
    axisx->setMinorTickCount(1);

    QValueAxis*axisY=new QValueAxis;
    axisY->setRange(0,100);
    axisY->setTitleText("人数");
    axisY->setLabelFormat("%u");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(5);
    axisY->setMinorTickCount(1);


    chart_4->setAxisX(axisx,series_4);
    chart_4->setAxisY(axisY,series_4);
    chart_4->legend()->setVisible(true);
    chart_4->legend()->setAlignment(Qt::AlignBottom);
    chart_4->legend()->setBackgroundVisible(true);
    chart_4->legend()->setAutoFillBackground(true);
    chart_4->legend()->setColor(QColor(222,233,251));
    chart_4->legend()->setLabelColor(QColor(0,100,255));


    chart_4->legend()->setMaximumHeight(50);
    chart_4->setAnimationOptions(QChart::SeriesAnimations);


    ui->chartview_4->setChart(chart_4);
}

void statistics::on_pushButton_5_clicked()
{
    chart_5=new QChart();
    chart_5->setTitle("疫情模拟结果");
    chart_5->setTheme(QChart::ChartThemeLight);
    series_5->setColor(QColor(0,100,255));
    series_5->setName("接种人数");
    chart_5->addSeries(series_5);



    QValueAxis*axisx=new QValueAxis;
    axisx->setRange(1,r_count);
    axisx->setTitleText("时间");
    axisx->setLabelFormat("%u");
    axisx->setGridLineVisible(true);
    axisx->setTickCount(20);
    axisx->setMinorTickCount(1);

    QValueAxis*axisY=new QValueAxis;
    axisY->setRange(0,3000);
    axisY->setTitleText("人数");
    axisY->setLabelFormat("%u");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(10);
    axisY->setMinorTickCount(1);


    chart_5->setAxisX(axisx,series_5);
    chart_5->setAxisY(axisY,series_5);
    chart_5->legend()->setVisible(true);
    chart_5->legend()->setAlignment(Qt::AlignBottom);
    chart_5->legend()->setBackgroundVisible(true);
    chart_5->legend()->setAutoFillBackground(true);
    chart_5->legend()->setColor(QColor(222,233,251));
    chart_5->legend()->setLabelColor(QColor(0,100,255));


    chart_5->legend()->setMaximumHeight(50);
    chart_5->setAnimationOptions(QChart::SeriesAnimations);


    ui->chartview_5->setChart(chart_5);
}

void statistics::on_pushButton_6_clicked()
{

                barseries=new QBarSeries();
                barseries->append(set_1);
                barseries->append(set_2);
                barseries->append(set_3);
                barseries->append(set_4);
                barseries->append(set_5);
    chart_6=new QChart();

    chart_6->setTitle("疫情模拟结果");
     chart_6->addSeries(barseries);
    chart_6->setAnimationOptions(QChart::SeriesAnimations);
    chart_6->createDefaultAxes();//创建默认的左侧的坐标轴


    chart_6->legend()->setVisible(true); //设置图例为显示状态
    chart_6->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    ui->chartview_6->setChart(chart_6);

}




void statistics::on_actionQuit_triggered()
{
    Widget *widget=new Widget;
    widget->show();
    this->hide();
}
