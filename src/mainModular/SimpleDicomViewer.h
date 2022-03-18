#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SimpleDicomViewer.h"
#include "sdvInclude.h"
class SimpleDicomViewer : public QMainWindow
{
    Q_OBJECT

public:
    SimpleDicomViewer(QWidget *parent = Q_NULLPTR);
public slots:
    void on_OpenDicoms();
private:
    Ui::SimpleDicomViewerClass ui;
};
