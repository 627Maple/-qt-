#include "dialogpen.h"
#include "ui_dialogpen.h"

DialogPen::DialogPen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPen)
{
    ui->setupUi(this);
}

DialogPen::~DialogPen()
{
    delete ui;
}
