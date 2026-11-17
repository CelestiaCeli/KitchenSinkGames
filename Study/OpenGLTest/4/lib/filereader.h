#pragma once
#ifndef __FILEREADER_H__
#define __FILEREADER_H__

#include "log.h"

#include <string>
#include <fstream>
#include <sstream>
#include <ostream>

class FileReader
{
	private:

	protected:
	std::string fileContents;
	std::string filePath;

	public:
	bool ValidFile();
	std::string ReadFile();

	bool ValidFile(const char* _filePath);
	std::string ReadFile(const char* _filePath);


};

#endif
