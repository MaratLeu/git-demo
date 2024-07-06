#ifndef GAME_USACH_H
#define GAME_USACH_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class game_usach;
}

class game_usach : public QDialog
{
    Q_OBJECT

public:
    explicit game_usach(QWidget *parent = nullptr);
    ~game_usach();

signals:
    void usachonok_window();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::game_usach *ui;
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

#endif // GAME_USACH_H
