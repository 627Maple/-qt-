#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "demonstration.h"
#include "implement.h"
#include "simulation.h"
#include "widget.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QIcon>
#include <QMenu>
#include <QVector>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0, int = 0,Building *[] = NULL,Person *[] = NULL,Tree *[] = NULL);
    //class Building* buildings[46];
    class Person* persons[8000];
    //QVector<Person*> vec;
    class Tree* trees;



    ~Dialog();

private slots:
    int OnWidgetContextMeun(const QPoint& pt);  //右键弹出菜单
    int OnMenuAdd();
    //int OnMenuRemove();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
