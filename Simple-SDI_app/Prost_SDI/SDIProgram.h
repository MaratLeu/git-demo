#ifndef SDIPROGRAM_H
#define SDIPROGRAM_H

#include <QMainWindow>
#include <QtWidgets>
#include "DocWindow.h"
class SDIProgram : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram(QWidget *pwgt = 0);

public slots:
    void SlotAbout();
    void SlotChangeWindowTitle(const QString&);
};
#endif // SDIPROGRAM_H
