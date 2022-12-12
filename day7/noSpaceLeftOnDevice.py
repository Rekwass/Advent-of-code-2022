from typing import List


class FileStruct:
    fileName: str
    size: int


class DirectoryStruct:
    files: List[FileStruct]
    direcories: List[DirectoryStruct]
    parentDirectory: str


def no_space_left_on_device(input: List[str]) -> int:

    return 0
