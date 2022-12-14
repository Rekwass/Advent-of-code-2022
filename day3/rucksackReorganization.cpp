#include <iostream>
#include <string>

// char getItemInRucksack(const std::string& line)
// {
//     for (int i = 0; i < line.length() / 2; ++i) {
//         for (int j = line.length() / 2; j < line.length(); ++j) {
//             if (line[i] == line[j]) {
//                 return line[i];
//             }
//         }
//     }
//     return -1;
// }

void getItemsInRucksack(std::string& items, const std::string& firstRucksack, const std::string& secondRucksack)
{
    for (char i : firstRucksack) {
        for (char j : secondRucksack) {
            if (i == j and items.find(i) == std::string::npos) {
                items.append(1, i);
            }
        }
    }
}

char getItemFromThirdRucksack(const std::string& items, const std::string& thirdRucksack)
{
    for (char i : items) {
        for (char j : thirdRucksack) {
            if (i == j) {
                return i;
            }
        }
    }
    return -1;
}

void rucksackReorganization()
{
    char item = 0;
    int score = 0;
    std::string firstRucksack;
    std::string secondRucksack;
    std::string thirdRucksack;

    while (std::cin >> firstRucksack) {
        std::string items;
        std::cin >> secondRucksack;
        std::cin >> thirdRucksack;

        getItemsInRucksack(items, firstRucksack, secondRucksack);
        item = getItemFromThirdRucksack(items, thirdRucksack);

        if (item >= 'A' and item <= 'Z') {
            score += item - 'A' + 27;
        } else if (item >= 'a' and item <= 'z') {
            score += item - 'a' + 1;
        }
    }
    std::cout << "Score : " << score << std::endl;
}

// void rucksackReorganization()
// {
//     char item = 0;
//     int score = 0;
//
//     for (std::string line; std::getline(std::cin, line);) {
//         item = getItemInRucksack(line);
//         if (item >= 'A' and item <= 'Z') {
//             score += item - 'A' + 27;
//         } else if (item >= 'a' and item <= 'z') {
//             score += item - 'a' + 1;
//         }
//     }
//     std::cout << "Score : " << score << std::endl;
// }