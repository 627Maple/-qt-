#include "widget.h"
#include <QApplication>
#include <QTextCodec>

#include <QSplashScreen>
#include <QPixmap>
#include <QDebug>
#include <QElapsedTimer>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Widget w;
    w.show();





    return a.exec();
}
