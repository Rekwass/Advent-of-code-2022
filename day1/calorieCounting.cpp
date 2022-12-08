#include <iostream>
#include <string>

int getSmallestCaloriesIndex(const int topThreeCalories[3])
{
    int smallestCalories = topThreeCalories[0];
    int smallestCaloriesIndex = 0;

    for (int i = 0; i < 3; ++i) {
        if (topThreeCalories[i] <= smallestCalories) {
            smallestCaloriesIndex = i;
        }
    }
    return smallestCaloriesIndex;
}

void addCalories(const int totalCalories, int topThreeCalories[3])
{
    int i = getSmallestCaloriesIndex(topThreeCalories);

    if (topThreeCalories[i] < totalCalories) {
        topThreeCalories[i] = totalCalories;
    }
}

int calorieCounting()
{
    int calorie = 0;
    int totalCalories = 0;
    int mostCalories = 0;
    int topThreeCalories[3] = {0};

    for (std::string line; std::getline(std::cin, line);) {
        if (line.empty()) {
            addCalories(totalCalories, topThreeCalories);
            mostCalories = mostCalories < totalCalories ? totalCalories : mostCalories;
            totalCalories = 0;
        } else {
            calorie = std::atoi(line.c_str());
            totalCalories += calorie;
        }
    }
    std::cout << "Most Calories : " << mostCalories << std::endl;
    std::cout << "Top Three : [" << topThreeCalories[0] << ", " << topThreeCalories[1] << ", " << topThreeCalories[2] << "]" << std::endl;
    std::cout << "Sum of top three : " << topThreeCalories[0] + topThreeCalories[1] + topThreeCalories[2] << std::endl;
    return 0;
}
