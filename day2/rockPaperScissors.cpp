#include <fstream>
#include <iostream>
#include <string>

// A == X == ROCK == 1
// B == Y == PAPER == 2
// C == Z == SCISSORS == 3
//
// X == LOSS
// Y == DRAW
// Z == WIN
//
// LOSS = 0
// DRAW = 3
// WIN = 6

// ROCK PAPER
// PAPER SCISSORS
// SCISSORS ROCK

int getPlayValue(const char c)
{
    if (c == 'X') {
        return 1;
    }
    if (c == 'Y') {
        return 2;
    }
    return 3;
}

int matchRPS(const char us, const char enemy)
{
    if ((us == 'X' and enemy == 'B') or (us == 'Y' and enemy == 'C') or (us == 'Z' and enemy == 'A')) {
        return 0;
    }
    if ((us == 'X' and enemy == 'A') or (us == 'Y' and enemy == 'B') or (us == 'Z' and enemy == 'C')) {
        return 3;
    }
    return 6;
}

int calculateScore(const char us, const char enemy)
{
    return (getPlayValue(us) + matchRPS(us, enemy));
}

void rockPaperScissors(std::ifstream& fileContent)
{
    char us = 0;
    char enemy = 0;
    int result = 0;

    while (fileContent >> enemy >> us) {
        result += calculateScore(us, enemy);
    }
    std::cout << "Score: " << result << std::endl;
}
