from typing import List

# A == X == ROCK == 1
# B == Y == PAPER == 2
# C == Z == SCISSORS == 3

# X == LOSS
# Y == DRAW
# Z == WIN

# LOSS = 0
# DRAW = 3
# WIN = 6


def get_opponent_move(line: str) -> str:
    return line[0]


def get_our_move(line: str) -> str:
    return line[2]


def get_our_move_score(move: str) -> int:
    if move == "X":
        return 0
    elif move == "Y":
        return 3
    elif move == "Z":
        return 6
    return 0


def rock_against_opponent(opponentMove: str) -> int:
    if opponentMove == "A":
        return 3
    elif opponentMove == "B":
        return 1
    elif opponentMove == "C":
        return 2
    return 0


def paper_against_opponent(opponentMove: str) -> int:
    if opponentMove == "A":
        return 1
    elif opponentMove == "B":
        return 2
    elif opponentMove == "C":
        return 3
    return 0


def scissors_against_opponent(opponentMove: str) -> int:
    if opponentMove == "A":
        return 2
    elif opponentMove == "B":
        return 3
    elif opponentMove == "C":
        return 1
    return 0


def evaluate_win(ourMove: str, opponentMove: str):
    if ourMove == "X":
        return rock_against_opponent(opponentMove)
    elif ourMove == "Y":
        return paper_against_opponent(opponentMove)
    elif ourMove == "Z":
        return scissors_against_opponent(opponentMove)
    return -1


def get_round_score(ourMove: str, opponentMove: str) -> int:
    gameResult: int = evaluate_win(ourMove, opponentMove)
    if gameResult == 1:
        return 1
    elif gameResult == 2:
        return 2
    elif gameResult == 3:
        return 3
    return 0


def rockPaperScissors(input: List[str]) -> int:
    score: int = 0

    for line in input:
        opponentMove: str = get_opponent_move(line)
        ourMove: str = get_our_move(line)
        score += get_our_move_score(ourMove)
        score += get_round_score(ourMove, opponentMove)

    print(score)

    return 0
