#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();

signals:
    void zubovich_window();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::game *ui;
    int count;
public:
    QMenu* live_1;
    QMenu* live_2;
    QMenu* live_3;
    QAction* hide_1;
    QAction* hide_2;
    QAction* hide_3;
    QTimer* timer;
};

#endif // GAME_H
