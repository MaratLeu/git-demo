#include "chosing_character.h"
#include "ui_chosing_character.h"
chosing_character::chosing_character(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chosing_character)
{
    ui->setupUi(this);

    zubovich = new game;
    connect(zubovich, &game::zubovich_window, this, &chosing_character::show);

    usachonok = new game_usach;
    connect(usachonok, &game_usach::usachonok_window, this, &chosing_character::show);

    nikita = new game_nikita;
    connect(nikita, &game_nikita::nikita_window, this, &chosing_character::show);
}

chosing_character::~chosing_character()
{
    delete ui;
}

void chosing_character::on_pushButton_zubovich_clicked()
{
    zubovich -> showFullScreen();
    this -> close();
}


void chosing_character::on_pushButton_usachonok_clicked()
{
    usachonok -> showFullScreen();
    this -> close();
}


void chosing_character::on_pushButton_nikita_clicked()
{
    nikita -> showFullScreen();
    this -> close();
}


void chosing_character::on_pushButton_return_clicked()
{
    emit first_window();
    this -> close();
}



