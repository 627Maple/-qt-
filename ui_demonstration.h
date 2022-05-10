/********************************************************************************
** Form generated from reading UI file 'demonstration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMONSTRATION_H
#define UI_DEMONSTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Demonstration
{
public:
    QPushButton *BigButton;
    QPushButton *LittleButton;
    QPushButton *LiftButton;
    QPushButton *RightButton;
    QPushButton *UpButton;
    QPushButton *DownButton;
    QPushButton *ResetButton;
    QPushButton *OpenButton;
    QLabel *label;
    QPushButton *Return;
    QPushButton *Save;
    QCheckBox *ShowPeople;
    QLabel *Day;
    QLabel *Day_Time;
    QPushButton *Start;
    QPushButton *Pause;
    QSpinBox *SpeedUp;
    QSlider *Speed;
    QWidget *widget;
    QLabel *one;
    QLabel *two;
    QLabel *three;
    QLabel *five;
    QLabel *four;

    void setupUi(QWidget *Demonstration)
    {
        if (Demonstration->objectName().isEmpty())
            Demonstration->setObjectName(QStringLiteral("Demonstration"));
        Demonstration->resize(1200, 950);
        BigButton = new QPushButton(Demonstration);
        BigButton->setObjectName(QStringLiteral("BigButton"));
        BigButton->setGeometry(QRect(960, 450, 92, 28));
        LittleButton = new QPushButton(Demonstration);
        LittleButton->setObjectName(QStringLiteral("LittleButton"));
        LittleButton->setGeometry(QRect(960, 480, 92, 28));
        LiftButton = new QPushButton(Demonstration);
        LiftButton->setObjectName(QStringLiteral("LiftButton"));
        LiftButton->setGeometry(QRect(960, 510, 92, 28));
        RightButton = new QPushButton(Demonstration);
        RightButton->setObjectName(QStringLiteral("RightButton"));
        RightButton->setGeometry(QRect(960, 540, 92, 28));
        UpButton = new QPushButton(Demonstration);
        UpButton->setObjectName(QStringLiteral("UpButton"));
        UpButton->setGeometry(QRect(960, 570, 92, 28));
        DownButton = new QPushButton(Demonstration);
        DownButton->setObjectName(QStringLiteral("DownButton"));
        DownButton->setGeometry(QRect(960, 600, 92, 28));
        ResetButton = new QPushButton(Demonstration);
        ResetButton->setObjectName(QStringLiteral("ResetButton"));
        ResetButton->setGeometry(QRect(960, 210, 92, 28));
        OpenButton = new QPushButton(Demonstration);
        OpenButton->setObjectName(QStringLiteral("OpenButton"));
        OpenButton->setGeometry(QRect(960, 240, 92, 28));
        label = new QLabel(Demonstration);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(990, 280, 72, 15));
        Return = new QPushButton(Demonstration);
        Return->setObjectName(QStringLiteral("Return"));
        Return->setGeometry(QRect(960, 300, 92, 28));
        Save = new QPushButton(Demonstration);
        Save->setObjectName(QStringLiteral("Save"));
        Save->setGeometry(QRect(960, 360, 92, 28));
        ShowPeople = new QCheckBox(Demonstration);
        ShowPeople->setObjectName(QStringLiteral("ShowPeople"));
        ShowPeople->setGeometry(QRect(960, 420, 88, 19));
        Day = new QLabel(Demonstration);
        Day->setObjectName(QStringLiteral("Day"));
        Day->setGeometry(QRect(1000, 10, 71, 21));
        Day_Time = new QLabel(Demonstration);
        Day_Time->setObjectName(QStringLiteral("Day_Time"));
        Day_Time->setGeometry(QRect(1000, 40, 72, 15));
        Start = new QPushButton(Demonstration);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(960, 150, 92, 28));
        Pause = new QPushButton(Demonstration);
        Pause->setObjectName(QStringLiteral("Pause"));
        Pause->setGeometry(QRect(960, 180, 92, 28));
        SpeedUp = new QSpinBox(Demonstration);
        SpeedUp->setObjectName(QStringLiteral("SpeedUp"));
        SpeedUp->setGeometry(QRect(960, 90, 46, 22));
        SpeedUp->setMaximum(500);
        Speed = new QSlider(Demonstration);
        Speed->setObjectName(QStringLiteral("Speed"));
        Speed->setGeometry(QRect(1010, 90, 160, 22));
        Speed->setMaximum(500);
        Speed->setOrientation(Qt::Horizontal);
        widget = new QWidget(Demonstration);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 900, 611, 41));
        one = new QLabel(widget);
        one->setObjectName(QStringLiteral("one"));
        one->setGeometry(QRect(0, 20, 91, 20));
        two = new QLabel(widget);
        two->setObjectName(QStringLiteral("two"));
        two->setGeometry(QRect(100, 20, 101, 16));
        three = new QLabel(widget);
        three->setObjectName(QStringLiteral("three"));
        three->setGeometry(QRect(220, 20, 111, 21));
        five = new QLabel(widget);
        five->setObjectName(QStringLiteral("five"));
        five->setGeometry(QRect(460, 20, 121, 16));
        four = new QLabel(widget);
        four->setObjectName(QStringLiteral("four"));
        four->setGeometry(QRect(340, 20, 91, 16));

        retranslateUi(Demonstration);

        QMetaObject::connectSlotsByName(Demonstration);
    } // setupUi

    void retranslateUi(QWidget *Demonstration)
    {
        Demonstration->setWindowTitle(QApplication::translate("Demonstration", "Form", Q_NULLPTR));
        BigButton->setText(QApplication::translate("Demonstration", "\347\274\251\345\260\217", Q_NULLPTR));
        LittleButton->setText(QApplication::translate("Demonstration", "\346\224\276\345\244\247", Q_NULLPTR));
        LiftButton->setText(QApplication::translate("Demonstration", "\345\220\221\345\267\246", Q_NULLPTR));
        RightButton->setText(QApplication::translate("Demonstration", "\345\220\221\345\217\263", Q_NULLPTR));
        UpButton->setText(QApplication::translate("Demonstration", "\345\220\221\344\270\212", Q_NULLPTR));
        DownButton->setText(QApplication::translate("Demonstration", "\345\220\221\344\270\213", Q_NULLPTR));
        ResetButton->setText(QApplication::translate("Demonstration", "\350\277\230\345\216\237", Q_NULLPTR));
        OpenButton->setText(QApplication::translate("Demonstration", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("Demonstration", "100%", Q_NULLPTR));
        Return->setText(QApplication::translate("Demonstration", "\350\277\224\345\233\236", Q_NULLPTR));
        Save->setText(QApplication::translate("Demonstration", "\344\277\235\345\255\230\350\207\263\346\226\207\344\273\266", Q_NULLPTR));
        ShowPeople->setText(QApplication::translate("Demonstration", "\346\230\276\347\244\272\344\272\272", Q_NULLPTR));
        Day->setText(QApplication::translate("Demonstration", "\347\254\2541\345\244\251", Q_NULLPTR));
        Day_Time->setText(QApplication::translate("Demonstration", "0\346\227\2660\345\210\206", Q_NULLPTR));
        Start->setText(QApplication::translate("Demonstration", "\345\274\200\345\247\213", Q_NULLPTR));
        Pause->setText(QApplication::translate("Demonstration", "\346\232\202\345\201\234", Q_NULLPTR));
        one->setText(QApplication::translate("Demonstration", "\345\201\245\345\272\267\357\274\232", Q_NULLPTR));
        two->setText(QApplication::translate("Demonstration", "\346\204\237\346\237\223\350\200\205\357\274\232", Q_NULLPTR));
        three->setText(QApplication::translate("Demonstration", "\351\207\215\347\227\207\346\202\243\350\200\205\357\274\232", Q_NULLPTR));
        five->setText(QApplication::translate("Demonstration", "\345\267\262\346\216\245\347\247\215\347\226\253\350\213\227\357\274\232", Q_NULLPTR));
        four->setText(QApplication::translate("Demonstration", "\346\255\273\344\272\241\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Demonstration: public Ui_Demonstration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMONSTRATION_H
