#ifndef GROWCUTWINDOW_H
#define GROWCUTWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include "ModelGrowCut/CellularAutomata.h"
#include <QImage>
#include "myqlabel.h"

namespace Ui {
class GrowCutWindow;
}

class GrowCutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GrowCutWindow(QWidget *parent = 0);
    ~GrowCutWindow();

private slots:
    void on_actionOpen_triggered();


    void on_runPushButton_clicked();

    void Mouse_current_pos();

    void on_actionSave_triggered();

private:
    Ui::GrowCutWindow *ui;
    CellularAutomata automata;
    QImage img;
};

#endif // GROWCUTWINDOW_H
