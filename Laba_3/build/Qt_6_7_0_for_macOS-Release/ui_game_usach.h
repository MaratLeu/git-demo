/********************************************************************************
** Form generated from reading UI file 'game_usach.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_USACH_H
#define UI_GAME_USACH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_game_usach
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *game_usach)
    {
        if (game_usach->objectName().isEmpty())
            game_usach->setObjectName("game_usach");
        game_usach->resize(800, 600);
        pushButton = new QPushButton(game_usach);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 60, 75));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/image/usachonok.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(60, 75));
        pushButton_2 = new QPushButton(game_usach);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(159, 231, 461, 101));

        retranslateUi(game_usach);

        QMetaObject::connectSlotsByName(game_usach);
    } // setupUi

    void retranslateUi(QDialog *game_usach)
    {
        game_usach->setWindowTitle(QCoreApplication::translate("game_usach", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("game_usach", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_usach: public Ui_game_usach {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_USACH_H
