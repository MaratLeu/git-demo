#include "DocWindow.h"
#include <QFileDialog>
using namespace std;
DocWindow::DocWindow(QWidget* pwgt) : QTextEdit(pwgt)
{
}

void DocWindow::slotLoad()
{
    QString str = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::currentPath(), tr("*txt; *bin"));
    if (str.isEmpty()) {
        return;
    }
    QFile file(str);
    if (file.open(QIODevice::ReadOnly)) {
        if (str.contains(".txt")) {
            QTextStream stream(&file);
            setPlainText(stream.readAll());
        }
        else if (str.contains(".bin")) {
            QByteArray bytes = file.readAll();
            QString hexString = QString::fromUtf8(bytes);

            qDebug() << hexString << "\n";

            setPlainText(hexString);

        }
        file.close();

        m_strFilename = str;
        emit changeWindowTitle(m_strFilename);
    }
}

void DocWindow::slotSaveAs() {
    QString str = QFileDialog::getSaveFileName(0, m_strFilename);
    if (!str.isEmpty()) {
        m_strFilename = str;
        slotSave();
    }
}

void DocWindow::slotSave() {
    if (m_strFilename.isEmpty()) {
        slotSaveAs();
        return;
    }
    QFile file(m_strFilename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream(&file) << toPlainText();
        file.close();
        emit changeWindowTitle(m_strFilename);
    }
}
