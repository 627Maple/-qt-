#ifndef BUILDING_SHOW_H
#define BUILDING_SHOW_H

#include <QWidget>

namespace Ui {
class Building_Show;
}

class Building_Show : public QWidget
{
    Q_OBJECT

public:
    explicit Building_Show(QWidget *parent = 0);
    ~Building_Show();

private:
    Ui::Building_Show *ui;
};

#endif // BUILDING_SHOW_H
