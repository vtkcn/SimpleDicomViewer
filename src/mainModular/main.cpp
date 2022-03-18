#include "SimpleDicomViewer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleDicomViewer w;
    w.show();
    //w.showMaximized();
    return a.exec();
}
