#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <simulation.h>
#include <statistics.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    statistics * statistics_1=NULL;
    Simulation * simulation = NULL; //次一级的界面

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
