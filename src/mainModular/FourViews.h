#include "ui_FourViews.h"
#include "vtkOutputWindow.h"
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);
class FourViews : public QWidget
{
public:
	FourViews(QWidget* parent = Q_NULLPTR);
	~FourViews();

private:
	Ui::Form ui;
};
