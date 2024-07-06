#ifndef GAME_NIKITA_H
#define GAME_NIKITA_H
#include <QDialog>
#include <QTimer>
namespace Ui {
class game_nikita;
}

class game_nikita : public QDialog
{
    Q_OBJECT

public:
    explicit game_nikita(QWidget *parent = nullptr);
    ~game_nikita();

signals:
    void nikita_window();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::game_nikita *ui;
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

#endif // GAME_NIKITA_H
