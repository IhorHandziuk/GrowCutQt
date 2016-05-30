#include "growcutwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GrowCutWindow w;
    w.show();

    return a.exec();
}
