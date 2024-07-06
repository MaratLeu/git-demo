#ifndef CHOSING_CHARACTER_H
#define CHOSING_CHARACTER_H
#include <game.h>
#include <game_nikita.h>
#include <game_usach.h>
#include <QDialog>

namespace Ui {
class chosing_character;
}

class chosing_character : public QDialog
{
    Q_OBJECT

public:
    explicit chosing_character(QWidget *parent = nullptr);
    ~chosing_character();

signals:
    void first_window();

private slots:
    void on_pushButton_zubovich_clicked();

    void on_pushButton_usachonok_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_nikita_clicked();

private:
    Ui::chosing_character *ui;
    game_usach* usachonok;
    game* zubovich;
    game_nikita* nikita;
};

#endif // CHOSING_CHARACTER_H
