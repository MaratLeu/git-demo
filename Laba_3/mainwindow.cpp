#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCursor>
#include <QPixmap>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    win = new chosing_character;
    connect(win, &chosing_character::first_window, this, &MainWindow::show);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    win -> show();
    this -> close();
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::about(this, "Правила игры", "Существует 3 уровня сложности, у каждого персонажа есть 3 жизни, одна жизнь равняется 1 попаданию");
}

