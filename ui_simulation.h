/********************************************************************************
** Form generated from reading UI file 'simulation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATION_H
#define UI_SIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simulation
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QLabel *method1;
    QWidget *tab_2;
    QLabel *method2;
    QWidget *tab_3;
    QLabel *method3;
    QWidget *tab_4;
    QLabel *method4;
    QPushButton *Begin_Simulation;
    QPushButton *Return;
    QWidget *widget;
    QSpinBox *Rt;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *Zero;
    QLabel *label_3;
    QSpinBox *People;
    QGroupBox *GeLi;
    QRadioButton *Slow;
    QRadioButton *Middle;
    QRadioButton *Fast;
    QGroupBox *YiMiao;
    QRadioButton *Slow_2;
    QRadioButton *Middle_2;
    QRadioButton *Fast_2;
    QGroupBox *Method;
    QRadioButton *Method_1;
    QRadioButton *Method_2;
    QRadioButton *Method_3;
    QRadioButton *Method_4;

    void setupUi(QWidget *Simulation)
    {
        if (Simulation->objectName().isEmpty())
            Simulation->setObjectName(QStringLiteral("Simulation"));
        Simulation->resize(737, 541);
        tabWidget = new QTabWidget(Simulation);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 481, 251));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        method1 = new QLabel(tab_1);
        method1->setObjectName(QStringLiteral("method1"));
        method1->setGeometry(QRect(0, 0, 471, 221));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        method2 = new QLabel(tab_2);
        method2->setObjectName(QStringLiteral("method2"));
        method2->setGeometry(QRect(0, 0, 471, 221));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        method3 = new QLabel(tab_3);
        method3->setObjectName(QStringLiteral("method3"));
        method3->setGeometry(QRect(0, 0, 471, 221));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        method4 = new QLabel(tab_4);
        method4->setObjectName(QStringLiteral("method4"));
        method4->setGeometry(QRect(0, 0, 471, 221));
        tabWidget->addTab(tab_4, QString());
        Begin_Simulation = new QPushButton(Simulation);
        Begin_Simulation->setObjectName(QStringLiteral("Begin_Simulation"));
        Begin_Simulation->setGeometry(QRect(610, 430, 111, 41));
        Return = new QPushButton(Simulation);
        Return->setObjectName(QStringLiteral("Return"));
        Return->setGeometry(QRect(610, 490, 111, 41));
        widget = new QWidget(Simulation);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 280, 481, 251));
        Rt = new QSpinBox(widget);
        Rt->setObjectName(QStringLiteral("Rt"));
        Rt->setGeometry(QRect(120, 10, 51, 31));
        Rt->setMinimum(1);
        Rt->setMaximum(5);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 91, 31));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 91, 21));
        Zero = new QSpinBox(widget);
        Zero->setObjectName(QStringLiteral("Zero"));
        Zero->setGeometry(QRect(120, 50, 51, 31));
        Zero->setMinimum(1);
        Zero->setMaximum(50);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 81, 21));
        People = new QSpinBox(widget);
        People->setObjectName(QStringLiteral("People"));
        People->setGeometry(QRect(120, 90, 51, 31));
        People->setMinimum(3000);
        People->setMaximum(8000);
        GeLi = new QGroupBox(widget);
        GeLi->setObjectName(QStringLiteral("GeLi"));
        GeLi->setGeometry(QRect(10, 140, 441, 41));
        Slow = new QRadioButton(GeLi);
        Slow->setObjectName(QStringLiteral("Slow"));
        Slow->setGeometry(QRect(10, 20, 112, 19));
        Middle = new QRadioButton(GeLi);
        Middle->setObjectName(QStringLiteral("Middle"));
        Middle->setGeometry(QRect(140, 20, 112, 19));
        Fast = new QRadioButton(GeLi);
        Fast->setObjectName(QStringLiteral("Fast"));
        Fast->setGeometry(QRect(280, 20, 112, 19));
        YiMiao = new QGroupBox(widget);
        YiMiao->setObjectName(QStringLiteral("YiMiao"));
        YiMiao->setGeometry(QRect(10, 200, 441, 41));
        Slow_2 = new QRadioButton(YiMiao);
        Slow_2->setObjectName(QStringLiteral("Slow_2"));
        Slow_2->setGeometry(QRect(10, 20, 112, 19));
        Middle_2 = new QRadioButton(YiMiao);
        Middle_2->setObjectName(QStringLiteral("Middle_2"));
        Middle_2->setGeometry(QRect(140, 20, 112, 19));
        Fast_2 = new QRadioButton(YiMiao);
        Fast_2->setObjectName(QStringLiteral("Fast_2"));
        Fast_2->setGeometry(QRect(280, 20, 112, 19));
        Method = new QGroupBox(Simulation);
        Method->setObjectName(QStringLiteral("Method"));
        Method->setGeometry(QRect(500, 40, 111, 201));
        Method_1 = new QRadioButton(Method);
        Method_1->setObjectName(QStringLiteral("Method_1"));
        Method_1->setGeometry(QRect(10, 30, 61, 19));
        Method_2 = new QRadioButton(Method);
        Method_2->setObjectName(QStringLiteral("Method_2"));
        Method_2->setGeometry(QRect(10, 70, 61, 19));
        Method_3 = new QRadioButton(Method);
        Method_3->setObjectName(QStringLiteral("Method_3"));
        Method_3->setGeometry(QRect(10, 110, 71, 19));
        Method_4 = new QRadioButton(Method);
        Method_4->setObjectName(QStringLiteral("Method_4"));
        Method_4->setGeometry(QRect(10, 150, 81, 19));

        retranslateUi(Simulation);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Simulation);
    } // setupUi

    void retranslateUi(QWidget *Simulation)
    {
        Simulation->setWindowTitle(QApplication::translate("Simulation", "Form", Q_NULLPTR));
        method1->setText(QApplication::translate("Simulation", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("Simulation", "\347\255\226\347\225\2451", Q_NULLPTR));
        method2->setText(QApplication::translate("Simulation", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Simulation", "\347\255\226\347\225\2452", Q_NULLPTR));
        method3->setText(QApplication::translate("Simulation", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Simulation", "\347\255\226\347\225\2453", Q_NULLPTR));
        method4->setText(QApplication::translate("Simulation", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Simulation", "\347\255\226\347\225\2454", Q_NULLPTR));
        Begin_Simulation->setText(QApplication::translate("Simulation", "\345\274\200\345\247\213\346\250\241\346\213\237", Q_NULLPTR));
        Return->setText(QApplication::translate("Simulation", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("Simulation", "Rt\346\214\207\346\225\260\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Simulation", "0\344\273\243\347\227\205\344\272\272\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Simulation", "\346\250\241\346\213\237\346\200\273\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        GeLi->setTitle(QApplication::translate("Simulation", "\351\232\224\347\246\273\351\200\237\345\272\246", Q_NULLPTR));
        Slow->setText(QApplication::translate("Simulation", "\350\276\203\346\205\242", Q_NULLPTR));
        Middle->setText(QApplication::translate("Simulation", "\344\270\200\350\210\254", Q_NULLPTR));
        Fast->setText(QApplication::translate("Simulation", "\350\276\203\345\277\253", Q_NULLPTR));
        YiMiao->setTitle(QApplication::translate("Simulation", "\347\226\253\350\213\227\346\216\245\347\247\215\351\200\237\345\272\246", Q_NULLPTR));
        Slow_2->setText(QApplication::translate("Simulation", "\350\276\203\346\205\242", Q_NULLPTR));
        Middle_2->setText(QApplication::translate("Simulation", "\344\270\200\350\210\254", Q_NULLPTR));
        Fast_2->setText(QApplication::translate("Simulation", "\350\276\203\345\277\253", Q_NULLPTR));
        Method->setTitle(QApplication::translate("Simulation", "\351\200\211\346\213\251\347\255\226\347\225\245", Q_NULLPTR));
        Method_1->setText(QApplication::translate("Simulation", "\347\255\226\347\225\2451", Q_NULLPTR));
        Method_2->setText(QApplication::translate("Simulation", "\347\255\226\347\225\2452", Q_NULLPTR));
        Method_3->setText(QApplication::translate("Simulation", "\347\255\226\347\225\2453", Q_NULLPTR));
        Method_4->setText(QApplication::translate("Simulation", "\347\255\226\347\225\2454", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Simulation: public Ui_Simulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION_H
