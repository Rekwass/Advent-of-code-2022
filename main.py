from day1.calorieCounting import calorieCounting
from day2.rockPaperScissors import rockPaperScissors
from day9.ropeBridge import ropeBridge
from typing import List
from sys import stdin


def readInput() -> List[str]:
    input: List[str] = []
    for line in stdin:
        input.append(line.rstrip("\n"))
    return input


def readFile(filePath: str) -> List[str]:
    input: List[str] = []
    content: List[str] = []
    with open(filePath) as f:
        input: List[str] = f.readlines()

    [content.append(elem.rstrip("\n")) for elem in input]
    return content


def main() -> int:
    # input: List[str] = readFile("day9/puzzle_input.txt")
    # ropeBridge(input)
    input: List[str] = readFile("day2/puzzle_input.txt")
    rockPaperScissors(input)
    return 0


def entrypoint() -> int:

    return main()


# Allow this file to be the one and only entrypoint

if __name__ == "__main__":
    exit(entrypoint())
