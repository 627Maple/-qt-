/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QAction *actionAdd;
    QLabel *label;
    QTreeWidget *treeWidget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(670, 542);
        actionAdd = new QAction(Dialog);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/File_Sourse/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 151, 31));
        treeWidget = new QTreeWidget(Dialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 80, 351, 441));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 30, 171, 16));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 50, 121, 16));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 50, 121, 16));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 50, 121, 16));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(400, 80, 231, 441));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        actionAdd->setText(QApplication::translate("Dialog", "\346\230\276\347\244\272\350\257\246\347\273\206\344\277\241\346\201\257", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("Dialog", "\346\230\276\347\244\272\350\257\246\347\273\206\344\277\241\346\201\257", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Dialog", "\345\273\272\347\255\221\345\206\205\346\265\201\351\200\232\346\214\207\346\225\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\345\273\272\347\255\221\345\206\205\346\200\273\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "\345\201\245\345\272\267\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "\350\275\273\347\227\207\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "\351\207\215\347\227\207\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
