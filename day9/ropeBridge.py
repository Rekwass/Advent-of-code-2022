from typing import List
from copy import copy
from time import sleep


class Position:
    """
    @param List[float]: a list of floats
    """

    x: int
    y: int


def get_max_move_direction(input: List[str], char: str) -> int:
    size: int = 0

    for line in input:
        if line[0] == char:
            size += int(line[2])

    return size


def get_map_width(input: List[str]) -> int:
    width: int = 0
    maxWidth: int = 0

    for line in input:
        if line[0] == "R":
            width += int(line[2])
        elif line[0] == "L":
            width -= int(line[2])
        if width > maxWidth:
            maxWidth = width
    return maxWidth + 1


def get_map_height(input: List[str]) -> int:
    height: int = 0
    maxHeight: int = 0

    for line in input:
        if line[0] == "U":
            height += int(line[2])
        elif line[0] == "D":
            height -= int(line[2])
        if height > maxHeight:
            maxHeight = height
    return maxHeight + 1


def init_map(input: List[str]) -> List[str]:
    map: List[str] = []
    mapWidth: int = get_map_width(input) * 2
    mapHeight: int = get_map_height(input) * 2

    line: str = "." * mapWidth

    for _ in range(0, mapHeight):
        map.append(line)

    return map


def display_spawn(map: List[str], spawnPosition: Position) -> None:

    if map[spawnPosition.y][spawnPosition.x] == ".":
        map[spawnPosition.y] = (
            map[spawnPosition.y][: spawnPosition.x]
            + "s"
            + map[spawnPosition.y][spawnPosition.x + 1 :]
        )


def update_head(map: List[str], line: str, headPosition: Position) -> None:

    map[headPosition.y] = (
        map[headPosition.y][: headPosition.x]
        + "."
        + map[headPosition.y][headPosition.x + 1 :]
    )

    if line == "R":
        headPosition.x += 1
    elif line == "D":
        headPosition.y += 1
    elif line == "L":
        headPosition.x -= 1
    elif line == "U":
        headPosition.y -= 1

    map[headPosition.y] = (
        map[headPosition.y][: headPosition.x]
        + "H"
        + map[headPosition.y][headPosition.x + 1 :]
    )


def is_head_near_x(headPosition: Position, tailPosition: Position) -> bool:
    return (
        tailPosition.x == headPosition.x
        or tailPosition.x + 1 == headPosition.x
        or tailPosition.x - 1 == headPosition.x
    )


def is_head_near_y(headPosition: Position, tailPosition: Position) -> bool:
    return (
        tailPosition.y == headPosition.y
        or tailPosition.y + 1 == headPosition.y
        or tailPosition.y - 1 == headPosition.y
    )


def is_head_position_near(headPosition: Position, tailPosition: Position) -> bool:
    near_x: bool = is_head_near_x(headPosition, tailPosition)
    near_y: bool = is_head_near_y(headPosition, tailPosition)

    return near_x and near_y


def head_right(headPosition: Position, tailPosition: Position) -> bool:
    return headPosition.x > tailPosition.x


def head_down(headPosition: Position, tailPosition: Position) -> bool:
    return headPosition.y > tailPosition.y


def head_left(headPosition: Position, tailPosition: Position) -> bool:
    return headPosition.x < tailPosition.x


def head_up(headPosition: Position, tailPosition: Position) -> bool:
    return headPosition.y < tailPosition.y


def update_tail_direction(headPosition: Position, tailPosition: Position) -> None:
    right: bool = head_right(headPosition, tailPosition)
    down: bool = head_down(headPosition, tailPosition)
    left: bool = head_left(headPosition, tailPosition)
    up: bool = head_up(headPosition, tailPosition)

    if right:
        tailPosition.x += 1
    elif left:
        tailPosition.x -= 1
    if down:
        tailPosition.y += 1
    elif up:
        tailPosition.y -= 1
    return


def update_tail(map: List[str], headPosition: Position, tailPosition: Position) -> None:
    if headPosition.x == tailPosition.x and headPosition.y == tailPosition.y:
        return

    map[tailPosition.y] = (
        map[tailPosition.y][: tailPosition.x]
        + "."
        + map[tailPosition.y][tailPosition.x + 1 :]
    )
    if not is_head_position_near(headPosition, tailPosition):
        update_tail_direction(headPosition, tailPosition)

    map[tailPosition.y] = (
        map[tailPosition.y][: tailPosition.x]
        + "T"
        + map[tailPosition.y][tailPosition.x + 1 :]
    )


def add_tail_pos(tailPosition: Position, tailPositions: List[Position]) -> None:
    alreadyIn: bool = False
    for position in tailPositions:
        if tailPosition.x == position.x and tailPosition.y == position.y:
            alreadyIn = True
            break
    if not alreadyIn:
        currentPos: Position = Position()
        currentPos.x = copy(tailPosition.x)
        currentPos.y = copy(tailPosition.y)
        tailPositions.append(currentPos)


def update_display_map_and_then_display_the_shit_out_of_it(
    map: List[str], tailPositions: List[Position]
) -> None:
    for tailPosition in tailPositions:
        map[tailPosition.y] = (
            map[tailPosition.y][: tailPosition.x]
            + "#"
            + map[tailPosition.y][tailPosition.x + 1 :]
        )
    for line in map:
        print(line)


def ropeBridge(input: List[str]) -> int:

    map: List[str] = init_map(input)

    headPosition: Position = Position()
    headPosition.x = get_map_width(input)
    headPosition.y = get_map_height(input) - 1

    tailPosition: Position = Position()
    tailPosition.x = get_map_width(input)
    tailPosition.y = get_map_height(input) - 1

    spawnPosition: Position = Position()
    spawnPosition.x = get_map_width(input)
    spawnPosition.y = get_map_height(input) - 1

    tailPositions: List[Position] = [spawnPosition]

    map[headPosition.y] = (
        map[headPosition.y][: headPosition.x]
        + "H"
        + map[headPosition.y][headPosition.x + 1 :]
    )

    for line in map:
        print(line)
    for line in input:
        char: str = line[0]
        repeat: int = int(line[2])
        for _ in range(0, repeat):
            print("\n================\n")
            update_head(map, char, headPosition)
            update_tail(map, headPosition, tailPosition)
            display_spawn(map, spawnPosition)
            # print(f"tailPosition = [{tailPosition.x}, {tailPosition.y}]")
            add_tail_pos(tailPosition, tailPositions)
            for line in map:
                print(line)
            sleep(0.06)

    display_map: List[str] = init_map(input)

    update_display_map_and_then_display_the_shit_out_of_it(display_map, tailPositions)

    print(len(tailPositions))

    count: int = 0

    for line in display_map:
        for char in line:
            if char == "#":
                count += 1

    print(count)

    return 0
