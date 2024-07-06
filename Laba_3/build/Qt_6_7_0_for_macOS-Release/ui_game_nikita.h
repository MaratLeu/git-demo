/********************************************************************************
** Form generated from reading UI file 'game_nikita.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_NIKITA_H
#define UI_GAME_NIKITA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_game_nikita
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *game_nikita)
    {
        if (game_nikita->objectName().isEmpty())
            game_nikita->setObjectName("game_nikita");
        game_nikita->resize(800, 600);
        game_nikita->setAutoFillBackground(false);
        pushButton = new QPushButton(game_nikita);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 55, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/image/nikita_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(60, 75));
        pushButton_2 = new QPushButton(game_nikita);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 210, 271, 51));

        retranslateUi(game_nikita);

        QMetaObject::connectSlotsByName(game_nikita);
    } // setupUi

    void retranslateUi(QDialog *game_nikita)
    {
        game_nikita->setWindowTitle(QCoreApplication::translate("game_nikita", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("game_nikita", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_nikita: public Ui_game_nikita {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_NIKITA_H
