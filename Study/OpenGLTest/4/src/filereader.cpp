#include "../lib/filereader.h"

std::string FileReader::ReadFile(const char* _filePath)
{
	filePath = _filePath;
	std::string fileContents;
	std::ifstream file;

	file.exceptions (std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(filePath);
		std::stringstream fileStream;

		fileStream << file.rdbuf();

		file.close();

		fileContents = fileStream.str();
		return fileContents;
	}
	catch(std::string error)
	{
		Logger::GetInstance().Log(LogType::WARNING, LogContent::FILE_INVALID);
		std::printf("%s\n", filePath.c_str());
		return "null";
	}
}

std::string FileReader::ReadFile()
{
	return ReadFile(filePath.c_str());
}

bool FileReader::ValidFile(const char* _filePath)
{
	std::ifstream file;

 // file.exceptions (std::ifstream::failbit | std::ifstream::badbit);

  try
	{
		file.open(_filePath);
		if(file.fail())
		{
      std::printf("Lost!\n%s\n", _filePath);
			return false;
		}
		else
		{
      std::printf("win!\n");
			return true;
		}
	}
	catch(std::string error)
	{
		return false;
	}
}

bool FileReader::ValidFile()
{
	ValidFile(filePath.c_str());
}
