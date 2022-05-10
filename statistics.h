#ifndef STATISTICS_H
#define STATISTICS_H
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include <QMainWindow>
#include <qchart.h>
#include <QBarSet>

namespace Ui {
class statistics;
}

class statistics : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistics(QWidget *parent = 0);
    ~statistics();


private slots:
    void on_actionZoomOut_triggered();

    void on_actionZoomIn_triggered();

    void on_actionZoomReset_triggered();

    void on_actionopen_triggered();



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



    void on_actionQuit_triggered();

private:
    Ui::statistics *ui;
    void creatchart();
    QChart *chart_1;
    QChart *chart_2;
    QChart *chart_3;
    QChart *chart_4;
    QChart *chart_5;
    QChart *chart_6;
     QSplineSeries *series;
     QSplineSeries *series_2;
     QSplineSeries *series_2_2;
     QSplineSeries *series_3;
     QSplineSeries *series_4;
     QSplineSeries *series_5;

     QBarSet *set_1;
     QBarSet *set_2;
     QBarSet *set_3;
     QBarSet *set_4;
     QBarSet *set_5;
     QBarSeries *barseries;
     int r_count;

};

#endif // STATISTICS_H
