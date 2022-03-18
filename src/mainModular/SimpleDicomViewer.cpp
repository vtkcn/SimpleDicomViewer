#include "SimpleDicomViewer.h"

SimpleDicomViewer::SimpleDicomViewer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.treeWidget->setHeaderHidden(true);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_OpenDicoms()));
}

void SimpleDicomViewer::on_OpenDicoms()
{
}
