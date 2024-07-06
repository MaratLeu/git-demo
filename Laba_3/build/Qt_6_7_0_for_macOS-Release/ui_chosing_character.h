/********************************************************************************
** Form generated from reading UI file 'chosing_character.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOSING_CHARACTER_H
#define UI_CHOSING_CHARACTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_chosing_character
{
public:
    QLabel *label;
    QPushButton *pushButton_usachonok;
    QPushButton *pushButton_zubovich;
    QPushButton *pushButton_nikita;
    QPushButton *pushButton_return;

    void setupUi(QDialog *chosing_character)
    {
        if (chosing_character->objectName().isEmpty())
            chosing_character->setObjectName("chosing_character");
        chosing_character->resize(800, 600);
        label = new QLabel(chosing_character);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 800, 50));
        label->setAlignment(Qt::AlignCenter);
        pushButton_usachonok = new QPushButton(chosing_character);
        pushButton_usachonok->setObjectName("pushButton_usachonok");
        pushButton_usachonok->setGeometry(QRect(0, 50, 800, 150));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        pushButton_usachonok->setFont(font);
        pushButton_usachonok->setStyleSheet(QString::fromUtf8("background-color:rgb(20, 120, 20)"));
        pushButton_zubovich = new QPushButton(chosing_character);
        pushButton_zubovich->setObjectName("pushButton_zubovich");
        pushButton_zubovich->setGeometry(QRect(0, 200, 800, 150));
        pushButton_zubovich->setFont(font);
        pushButton_zubovich->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 20)"));
        pushButton_nikita = new QPushButton(chosing_character);
        pushButton_nikita->setObjectName("pushButton_nikita");
        pushButton_nikita->setGeometry(QRect(0, 350, 800, 150));
        pushButton_nikita->setFont(font);
        pushButton_nikita->setStyleSheet(QString::fromUtf8("background-color:rgb(150, 20, 20)"));
        pushButton_return = new QPushButton(chosing_character);
        pushButton_return->setObjectName("pushButton_return");
        pushButton_return->setGeometry(QRect(0, 500, 800, 100));
        pushButton_return->setFont(font);
        pushButton_return->setStyleSheet(QString::fromUtf8("backgroung-color: rgb(255, 255, 255)"));

        retranslateUi(chosing_character);

        QMetaObject::connectSlotsByName(chosing_character);
    } // setupUi

    void retranslateUi(QDialog *chosing_character)
    {
        chosing_character->setWindowTitle(QCoreApplication::translate("chosing_character", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("chosing_character", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\260 \321\207\321\202\320\276\320\261\321\213 \320\275\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
        pushButton_usachonok->setText(QCoreApplication::translate("chosing_character", "\320\220\321\200\321\202\320\265\320\274\320\270\320\271 \320\243\321\201\320\260\321\207\321\221\320\275\320\276\320\272(\320\223\320\265\320\275\320\270\320\271 QT) - easy", nullptr));
        pushButton_zubovich->setText(QCoreApplication::translate("chosing_character", "\320\227\321\203\320\261\320\276\320\262\320\270\321\207 \320\232\320\276\320\275\321\201\321\202\320\260\320\275\321\202\320\270\320\275 \320\220\320\275\321\202\320\276\320\275\320\276\320\262\320\270\321\207(\320\223\320\265\320\275\320\270\320\271 Assembler \320\270 \320\277\320\270\321\201\320\265\320\274) - medium", nullptr));
        pushButton_nikita->setText(QCoreApplication::translate("chosing_character", "\320\235\320\270\320\272\320\270\321\202\320\260(\320\233\321\203\321\207\321\210\320\270\320\271 \320\264\321\200\321\203\320\263, \320\223\320\265\320\275\320\270\320\271 \321\204\320\270\320\267\320\270\320\272\320\270 \320\264\320\260 \320\270 \320\262 \321\206\320\265\320\273\320\276\320\274 \320\262\321\201\320\265\320\263\320\276 \320\275\320\260 \321\201\320\262\320\265\321\202\320\265) - hard", nullptr));
        pushButton_return->setText(QCoreApplication::translate("chosing_character", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\263\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chosing_character: public Ui_chosing_character {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOSING_CHARACTER_H
