#include <iostream>
#include <list>
#include <itkImage.h>
using ImageType = itk::Image<float, 3>;
class dicomParse
{
public:
	dicomParse();
	~dicomParse();

	void setInputFile(std::vector<std::string>);
private:
	std::vector<std::vector<std::string>> m_list_fileFolder;
};
