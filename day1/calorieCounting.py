from typing import List


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
    return 0
