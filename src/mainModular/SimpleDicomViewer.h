#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SimpleDicomViewer.h"
#include "sdvInclude.h"
#include "dicomModular/dicomParse.h"
class SimpleDicomViewer : public QMainWindow
{
    Q_OBJECT

public:
    SimpleDicomViewer(QWidget *parent = Q_NULLPTR);
    void getAllFileName(QString path, std::vector<std::string>& path_vec);
public slots:
    void on_OpenDicoms();
private:
    QWidget* m_wid;
    Ui::SimpleDicomViewerClass ui;
};
