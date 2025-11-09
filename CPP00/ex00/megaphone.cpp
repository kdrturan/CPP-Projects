#include <iostream>
#include <string>
#include <algorithm> 


int main(int argc, char **argv) 
{
    if (argc == 1) 
	{
        char msg[] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        std::cout << msg << std::endl;
        return 0;
    }
    std::string result;
    for (int i = 1; i < argc; ++i) 
	{
        if (i > 1)
            result += " ";
        result += argv[i];
    }
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    std::cout << result << std::endl;
    return 0;
}