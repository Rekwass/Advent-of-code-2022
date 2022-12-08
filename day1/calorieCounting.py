from typing import List


def displayTopThreeCalories(calories: List[int]) -> None:

    calorie: int = 0
    totalCalories: int = 0

    for _ in range(0, 3):
        calorie = max(calories)
        calories.remove(calorie)
        totalCalories += calorie
    print(totalCalories)


def calorieCounting(input: List[str]) -> int:

    elvesCalories: List[int] = []
    totalCalories: int = 0

    for line in input:
        if not line:
            elvesCalories.append(totalCalories)
            totalCalories = 0
        else:
            totalCalories += int(line)

    print(max(elvesCalories))
    displayTopThreeCalories(elvesCalories)
    return 0
