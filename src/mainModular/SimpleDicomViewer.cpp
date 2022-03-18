#include "SimpleDicomViewer.h"
#include "QFileDialog.h"
#include "qdebug.h"
#include "FourViews.h"
SimpleDicomViewer::SimpleDicomViewer(QWidget *parent)
    : QMainWindow(parent)
{
    vtkOutputWindow::SetGlobalWarningDisplay(0);
    ui.setupUi(this);
    ui.treeWidget->setHeaderHidden(true);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_OpenDicoms()));
}

void SimpleDicomViewer::on_OpenDicoms()
{
    QString srcDirPath = QFileDialog::getExistingDirectory(
        this, "choose src Directory",
        "/");

    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
        qDebug() << "srcDirPath=" << srcDirPath;
        srcDirPath += "/";
    }

    /***************����Dicom�ļ�����****************/

    /**********************end************************/

    /*********************QTreeList***********************/

    /*********************end***********************/

    /*********************FourViews***********************/
    ui.widget = new FourViews(this);
    ui.gridLayout->addWidget(ui.widget, 0, 1, 1, 1);
    ui.widget->show();
    /*********************end***********************/
}
