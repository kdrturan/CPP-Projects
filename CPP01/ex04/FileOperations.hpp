#ifndef FILEOPERATIONS_HPP
#define FILEOPERATIONS_HPP


#include <string>
#include <iostream>
#include <fstream> 

class FileOperations {
private:
	const char* fileName;
	bool errorMessage(const char* message);
public:
	FileOperations(const char* fileName);
	~FileOperations();
 bool replaceInFile(const char* searchStr, const char* replaceStr);
};



#endif