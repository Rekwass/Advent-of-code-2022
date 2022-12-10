#include "adventOfCode2022.hpp"

#include <iostream>

bool displayHelp(const int ac, const char* const av[])
{
    bool helpDisplayed = false;
    if (ac == 1 or (ac == 2 and (strcmp(av[1], "-h") == 0 or (strcmp(av[1], "--help") == 0)))) {
        std::cout << "À L'AIDE" << std::endl;
        helpDisplayed = true;
    }
    return helpDisplayed;
}

bool checkArgs(const int ac, const char* const av[])
{
    if (ac != 2) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return false;
    }
    // NOLINTNEXTLINE
    const int selectedDay = std::atoi(av[1]);
    if (selectedDay < 1 or selectedDay > 25) {
        std::cerr << "Invalid argument, you must enter a number between 0 and 25" << std::endl;
        return false;
    }
    return true;
}

int main(const int ac, const char* av[])
{
    if (displayHelp(ac, av) or not checkArgs(ac, av)) {
        return 1;
    }

    void (*functionPointer[4])() = {&calorieCounting, &calorieCounting, &rucksackReorganization, &campCleanup};
    (*functionPointer[3])();
    return 0;
}
