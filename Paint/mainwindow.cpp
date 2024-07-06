#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shape.h"
#include "rectangle.h"
#include "oval.h"
#include <rhombus.h>
#include <paintscene.h>
#include <QColorDialog>
#include <QFileDialog>
#include <QDomDocument>
#include <QDomElement>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new paintScene();

    connect(ui -> action_rectangle, &QAction::triggered, this, &MainWindow::on_action_rectangle_triggered);
    connect(ui -> action_oval, &QAction::triggered, this, &MainWindow::on_action_oval_triggered);
    connect(ui -> action_rhombus, &QAction::triggered, this, &MainWindow::on_action_rhombus_triggered);
    connect(ui -> action_line, &QAction::triggered, this, &MainWindow::on_action_line_triggered);
    connect(ui -> action_open, &QAction::triggered, this, &MainWindow::on_action_load_triggered);

    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
    }

    void MainWindow::slotTimer()
    {
        timer->stop();
        scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    }

    void MainWindow::resizeEvent(QResizeEvent *event)
    {
        timer->start(100);
        QWidget::resizeEvent(event);
    }

    void MainWindow::on_action_rectangle_triggered() {
        scene->drawingMode = paintScene::DRAWING_RECTANGLE;
    }


    void MainWindow::on_action_oval_triggered() {
        scene->drawingMode = paintScene::DRAWING_OVAL;
    }

    void MainWindow::on_action_rhombus_triggered() {
        scene->drawingMode = paintScene::DRAWING_RHOMBUS;
    }

    void MainWindow::on_action_line_triggered() {
        scene -> drawingMode = paintScene::DRAWING_LINE;
    }

    void MainWindow::on_action_choose_color_triggered() {
        QColor currentColor = scene->penColor();
        QColor newColor = QColorDialog::getColor(currentColor, this, "Выбрать цвет");
        if (newColor.isValid()) {
            scene->setPenColor(newColor);
        }
    }

    void MainWindow::on_action_save_triggered()
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save Scene"), "", tr("JSON Files (*.json)"));
        if (!fileName.isEmpty()) {
            QJsonObject json;
            scene->serializeToJson(json);

            QJsonDocument jsonDoc(json);
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(jsonDoc.toJson());
                file.close();
            } else {
                QMessageBox::warning(this, tr("Save Scene"), tr("Unable to save the scene to the file."));
            }
        }
    }

    void MainWindow::on_action_load_triggered()
    {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Load Scene"), "", tr("JSON Files (*.json)"));
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly)) {
                QByteArray data = file.readAll();
                file.close();

                QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
                QJsonObject json = jsonDoc.object();

                scene->deserializeFromJson(json);
            } else {
                QMessageBox::warning(this, tr("Load Scene"), tr("Unable to load the scene from the file."));
            }
        }
    }

MainWindow::~MainWindow()
{
    delete ui;
}
