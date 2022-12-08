#include <iostream>

int calorieCounting();

bool displayHelp(const int ac, const char* av[])
{
    bool helpDisplayed = false;
    if (ac == 2 and (strcmp(av[1], "-h") == 0 or (strcmp(av[1], "--help") == 0))) {
        std::cout << "À L'AIDE" << std::endl;
        helpDisplayed = true;
    }
    return helpDisplayed;
}

int main(const int ac, const char* av[])
{
    if (displayHelp(ac, av)) {
        return 1;
    }
    calorieCounting();
    return 0;
}
