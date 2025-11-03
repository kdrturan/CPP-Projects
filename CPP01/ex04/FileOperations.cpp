#include "FileOperations.hpp"


FileOperations::FileOperations(const char* fileName) : fileName(fileName) {}
FileOperations::~FileOperations() {}

bool FileOperations::errorMessage(const char* message) {
	std::cout << message << std::endl;
	return false;
}

bool FileOperations::replaceInFile(const char* searchStr, const char* replaceStr) {

	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
		return errorMessage("Could not open file.");

	std::ofstream outputFile((std::string(fileName) + ".replace").c_str());
	if (outputFile.is_open())
	{
		std::size_t		pos = 0;
		std::string		line;
		while (std::getline(inputFile, line))
		{
			pos = line.find(searchStr);
			while (pos != std::string::npos)
			{
				line.erase(pos, std::string(searchStr).length());
				line.insert(pos, replaceStr);
				pos = line.find(searchStr);
			}
			outputFile << line << std::endl;
		}
		outputFile.close();
		inputFile.close();
		return true;
	}
	else 
	{		
		inputFile.close();
		return errorMessage("Could not open file.");
	}
}