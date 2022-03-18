#include "dicomParse.h"
#include <itkDICOMSeriesFileNames.h>
#include <itkImageSeriesReader.h>
#include <itkGDCMImageIO.h>
#include <itkGDCMSeriesFileNames.h>
#include <itkDicomImageIO.h>
#include <itkImageFileReader.h>

dicomParse::dicomParse()
{
}

dicomParse::~dicomParse()
{
}

void dicomParse::setInputFile(std::vector<std::string> filenames)
{
	typedef itk::ImageSeriesReader< ImageType >     ReaderType;
	typedef itk::GDCMImageIO                        ImageIOType;

	unsigned int numberOfFilenames = filenames.size();
	std::cout << numberOfFilenames << std::endl;
	std::map<std::string,std::string> discripmap;
	for (unsigned int fni = 0; fni < numberOfFilenames; fni++)
	{
		ImageIOType::Pointer dicomIO = ImageIOType::New();
		using ReaderType = itk::ImageFileReader<ImageType>;
		ReaderType::Pointer reader = ReaderType::New();
		reader->SetImageIO(dicomIO);
		reader->SetFileName(filenames[fni]);
		reader->Update();

		std::string tagkeyLower = "0008|103e"; // Series Description
		std::string valueFromLower;
		dicomIO->GetValueFromTag(tagkeyLower, valueFromLower);
		std::cout << "description: " << valueFromLower << std::endl;
		discripmap[filenames[fni]] = valueFromLower;
	}
	return;
}
