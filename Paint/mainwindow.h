#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include "paintscene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    QTimer* timer;
    paintScene* scene;

    void resizeEvent(QResizeEvent* event);

private slots:
    void slotTimer();
    void on_action_rectangle_triggered();
    void on_action_oval_triggered();
    void on_action_rhombus_triggered();
    void on_action_line_triggered();
    void on_action_choose_color_triggered();
    void on_action_save_triggered();
    void on_action_load_triggered();
};
#endif // MAINWINDOW_H
