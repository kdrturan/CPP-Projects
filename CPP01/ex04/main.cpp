#include "FileOperations.hpp"

int main(int argc, char** argv) {

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	else 
	{
		const char*		fileName = argv[1];
		const char*		searchStr = argv[2];
		const char*		replaceStr = argv[3];

		FileOperations fileOperations = FileOperations(fileName);
		if (!fileOperations.replaceInFile(searchStr, replaceStr))
			return 1;
	}
	return	0;
}

