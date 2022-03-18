#include "FourViews.h"

FourViews::FourViews(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	ui.qvtkWidget->GetRenderWindow();
	ui.qvtkWidget_2->GetRenderWindow();
	ui.qvtkWidget_3->GetRenderWindow();
	ui.qvtkWidget_4->GetRenderWindow();
}

FourViews::~FourViews()
{

}