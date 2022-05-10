#ifndef DIALOGPEN_H
#define DIALOGPEN_H

#include <QDialog>

namespace Ui {
class DialogPen;
}

class DialogPen : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPen(QWidget *parent = 0);
    ~DialogPen();

private:
    Ui::DialogPen *ui;
};

#endif // DIALOGPEN_H
