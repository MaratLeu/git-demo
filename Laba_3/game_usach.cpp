#include "game_usach.h"
#include "ui_game_usach.h"
#include <QMenuBar>
#include <QCursor>
#include <random>
#include <QPropertyAnimation>
using namespace std;
game_usach::game_usach(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::game_usach)
{
    ui->setupUi(this);

    QCursor cursor = QCursor(QPixmap(":/img/image/cursor_32.png"), 0, 0);
    this -> setCursor(cursor);

    QMenuBar* menubar_1 = new QMenuBar(this);
    QMenu* menu = menubar_1 -> addMenu("Выход из игры");
    QAction* exit = menu -> addAction("Выход из игры");
    connect(exit, &QAction::triggered, this, &game_usach::usachonok_window);

    live_1 = menubar_1 -> addMenu("❤️");
    hide_1 = live_1 -> addAction("");

    live_2 = menubar_1 -> addMenu("❤️");
    hide_2 = live_2 -> addAction("");

    live_3 = menubar_1 -> addMenu("❤️");
    hide_3 = live_3 -> addAction("");

    count = 0;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &game_usach::on_pushButton_2_clicked);
    timer -> start(100);
}

void game_usach::on_pushButton_2_clicked()
{
    const int angle = 360;
    mt19937_64 mersenne(static_cast <unsigned int> (time(0)));

    int diff_x = mersenne() % (this->width() - ui->pushButton->x());
    int diff_y = mersenne() % (this->height() - ui->pushButton->y());
    int new_angle_x = mersenne() % angle;
    int new_angle_y = mersenne() % angle;

    int new_pos_x = ui -> pushButton -> x() + cos(new_angle_x * M_PI / 180) * diff_x;
    int new_pos_y = ui -> pushButton -> y() + sin(new_angle_y * M_PI / 180) * diff_y;

    if (new_pos_x < 0 || new_pos_x > this -> width() - ui -> pushButton -> x()) {
        diff_x = -diff_x;
        new_pos_x = ui -> pushButton -> x() + cos(new_angle_x * M_PI / 180);
    }

    if (new_pos_y < 0 || new_pos_y > this -> height() - ui -> pushButton -> y()) {
        diff_y = -diff_y;
        new_pos_y = ui -> pushButton -> y() + sin(new_angle_y * M_PI / 180);
    }

    ui -> pushButton -> move(new_pos_x, new_pos_y);

    ui -> pushButton_2 -> close();
}


void game_usach::on_pushButton_clicked()
{
    count++;

    if (count == 1) {
        live_1 -> menuAction() -> setVisible(false);
        ui -> pushButton->setIcon(QIcon(":/img/image/usachonok_2.png"));
    }
    if (count == 2) {
        live_2 -> menuAction() -> setVisible(false);
        ui -> pushButton->setIcon(QIcon(":/img/image/usachonok_3.png"));
    }
    if (count == 3) {
        live_3->menuAction()->setVisible(false);
        timer->stop();
        QPushButton* grob = new QPushButton(this);
        QIcon icon_grob(":/img/image/grob.png");
        grob->setIcon(icon_grob);
        grob->setIconSize(ui->pushButton->size());
        grob->setGeometry(ui->pushButton->x() - 10, 0, 75, 75);
        grob->show();
        grob->raise();

        QPropertyAnimation* animation = new QPropertyAnimation(grob, "pos");
        animation->setStartValue(grob->pos());
        grob->move(ui->pushButton->pos().x() + ui->pushButton->width() + 10, ui->pushButton->pos().y());
        QPoint point(ui->pushButton->x(), height());
        animation->setEndValue(point);
        animation->setDuration(5000);
        animation->start();

        while (animation->state() != QAbstractAnimation::Stopped) {
            QApplication::processEvents();
            if (ui->pushButton->geometry().intersects(grob->geometry())) {
                ui->pushButton->hide();
            }

        }
    }
}

game_usach::~game_usach()
{
    delete ui;
}

