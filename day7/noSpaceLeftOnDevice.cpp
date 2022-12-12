#include <iostream>
#include <sstream>
#include <string>

struct file {
    std::string fileName;
    int size = 0;
};

// struct directory {
//     std::vector<file> files{};
//     std::string parentDirectory;
// };

static void getNumberFromLine(std::string& line, int& nbBox, int& fromBoxPile, int& toBoxPile)
{
    std::stringstream ss;
    ss << line;

    std::string tmp;

    ss >> tmp;
    ss >> tmp;
    std::stringstream(tmp) >> nbBox;
    ss >> tmp;
    ss >> tmp;
    std::stringstream(tmp) >> fromBoxPile;
    ss >> tmp;
    ss >> tmp;
    std::stringstream(tmp) >> toBoxPile;
}

void noSpaceLeftOnDevice()
{
    std::string word;
    std::stringstream ss;
    std::string path;

    for (std::string line; std::getline(std::cin, line);) {
        std::cout << "==============" << std::endl;
        std::cout << line << std::endl;
        ss << line;
        ss >> word;
        std::cout << word << std::endl;
    }
}
