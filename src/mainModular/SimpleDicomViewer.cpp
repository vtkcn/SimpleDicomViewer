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

void SimpleDicomViewer::getAllFileName(QString path, std::vector<std::string>& path_vec)
{
    QDir* dir = new QDir(path);
    QStringList filter;
    QList<QFileInfo>* fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
    for (int i = 0; i < fileInfo->count(); ++i)
    {
        const QFileInfo info_tmp = fileInfo->at(i);
        QString path_tmp = info_tmp.filePath();
        if (info_tmp.fileName() == ".." || info_tmp.fileName() == ".")
        {
        }
        else if (info_tmp.isFile()) {
            path_vec.push_back(path_tmp.toStdString());
        }
        else if (info_tmp.isDir()) {
            getAllFileName(path_tmp, path_vec);
        }
    }
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

    std::vector<std::string> path_vec;
    getAllFileName(srcDirPath, path_vec);

    /***************解析Dicom文件序列****************/
    dicomParse parse;
    parse.setInputFile(path_vec);
    /**********************end************************/

    /*********************QTreeList***********************/

    /*********************end***********************/

    /*********************FourViews***********************/
    ui.widget = new FourViews(this);
    ui.gridLayout->addWidget(ui.widget, 0, 1, 1, 1);
    ui.widget->show();
    /*********************end***********************/
}
