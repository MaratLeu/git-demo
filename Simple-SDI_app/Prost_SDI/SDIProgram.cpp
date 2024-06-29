#include "SDIProgram.h"

SDIProgram::SDIProgram(QWidget *pwgt) : QMainWindow(pwgt)
{
    QMenu* pmnuFile = new QMenu("&File");
    DocWindow* pdoc = new DocWindow;

    pmnuFile->addAction("&Open...", pdoc, SLOT(slotLoad()), QKeySequence(Qt::CTRL + Qt::Key_O));
    pmnuFile->addAction("&Save...", pdoc, SLOT(slotSave()), QKeySequence(Qt::CTRL + Qt::Key_S));
    pmnuFile->addAction("&SaveAs...", pdoc, SLOT(slotSaveAs()));
    pmnuFile->addSeparator();

    menuBar()->addMenu(pmnuFile);

    setCentralWidget(pdoc);
    connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(SlotChangeWindowTitle(const QString&)));

    statusBar()->showMessage("Ready", 2000);
}

void SDIProgram::SlotAbout() {
    QMessageBox::about(this, "Application", "SDI Example");
}

void SDIProgram::SlotChangeWindowTitle(const QString& str) {
    setWindowTitle(str);
}
