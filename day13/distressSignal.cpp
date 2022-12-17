#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// number meaning:
//     -1 -> opening bracket
//     -2 -> closing bracket
//     * >= 0 -> an number

using Packet = int;

enum PacketRetValue {
    FIRST_BIGGER = (-1),
    SECOND_BIGGER = 1,
    EQUAL = 0
};

void initPacket(std::string& line, std::vector<Packet>& packets)
{
    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == '[') {
            packets.emplace_back(-1);
        } else if (isdigit(line[i]) != 0) {
            packets.emplace_back(std::atoi(&line[i]));
        } else if (line[i] == ']') {
            packets.emplace_back(-2);
        }
    }
}

PacketRetValue compareIntWithList(int firstNumber, std::vector<Packet>& secondPackets, int& j)
{
    int secondNumber = secondPackets.at(j);

    if (secondNumber == -1) {
        return (compareIntWithList(firstNumber, secondPackets, ++j));
    } else if (secondNumber == -2 or firstNumber > secondNumber) {
        return FIRST_BIGGER;
    } else if (firstNumber < secondNumber or secondPackets.at(j + 1) >= -1) {
        return SECOND_BIGGER;
    }
    ++j;
    return EQUAL;
}

PacketRetValue compareListWithInt(std::vector<Packet>& firstPackets, int secondNumber, int& i)
{
    int firstNumber = firstPackets.at(i);

    std::cout << firstNumber << " and " << secondNumber << std::endl;
    if (firstNumber == -1) {
        std::cout << firstNumber << " and " << secondNumber << std::endl;
        return (compareListWithInt(firstPackets, secondNumber, ++i));
    } else if (firstNumber == -2 or firstNumber < secondNumber) {
        return SECOND_BIGGER;
    } else if (firstNumber > secondNumber or firstPackets.at(i + 1) >= -1) {
        return FIRST_BIGGER;
    }
    ++i;
    return EQUAL;
}

PacketRetValue compareIntWithInt(int firstNumber, int secondNumber)
{
    if (firstNumber > secondNumber) {
        return FIRST_BIGGER;
    } else if (firstNumber < secondNumber) {
        return SECOND_BIGGER;
    }
    return EQUAL;
}

int comparePackets(std::vector<Packet>& firstPackets, std::vector<Packet>& secondPackets, int pairId)
{
    int firstNumber = 0;
    int secondNumber = 0;
    int comparaisonResult = 0;
    int i = 0;
    int j = 0;

    for (; i < firstPackets.size() and j < secondPackets.size(); ++i, ++j) {
        firstNumber = firstPackets.at(i);
        secondNumber = secondPackets.at(j);
        std::cout << firstNumber << " and " << secondNumber << std::endl;
        // INT and INT
        if (firstNumber >= 0 and secondNumber >= 0) {
            comparaisonResult = compareIntWithInt(firstNumber, secondNumber);
        }
        // INT and [
        else if (firstNumber >= 0 and secondNumber == -1) {
            comparaisonResult = compareIntWithList(firstNumber, secondPackets, ++j);
        }
        // [ and INT
        else if (firstNumber == -1 and secondNumber >= 0) {
            comparaisonResult = compareListWithInt(firstPackets, secondNumber, ++i);
        }
        // INT and ] or [ and ]
        else if ((firstNumber >= 0 and secondNumber == -2) or (firstNumber == -1 and secondNumber == -2)) {
            comparaisonResult = FIRST_BIGGER;
        } // ] and INT or ] and [
        else if ((firstNumber == -2 and secondNumber >= 0) or (firstNumber == -2 and secondNumber == -1)) {
            comparaisonResult = SECOND_BIGGER;
        }
        // [ and [ or ] and ]
        else if ((firstNumber == -1 or secondNumber == -1) or (firstNumber == -2 or secondNumber == -2)) {
            comparaisonResult = EQUAL;
        }
        if (comparaisonResult == FIRST_BIGGER) {
            return 0;
        } else if (comparaisonResult == SECOND_BIGGER) {
            return pairId;
        }
    }
    std::cout << "EQUAL ????????????????" << std::endl;
    return pairId;
}

void displayPackets(std::vector<Packet>& packets)
{
    std::string prefix;
    std::cout << "[";
    for (auto& packet : packets) {
        std::cout << prefix << packet;
        prefix = ", ";
    }
    std::cout << "]" << std::endl;
}

void distressSignal()
{
    std::stringstream ss;
    std::string word;
    std::vector<Packet> firstPackets;
    std::vector<Packet> secondPackets;
    int pairId = 1;
    int validPackets = 0;

    int result = 0;
    std::string tmp;
    for (std::string line; std::getline(std::cin, line);) {
        initPacket(line, firstPackets);
        tmp = line;
        std::getline(std::cin, line);
        initPacket(line, secondPackets);
        result = comparePackets(firstPackets, secondPackets, pairId);
        if (result != 0) {
            std::cout << "== Pair " << pairId << " ==" << std::endl;
            std::cout << tmp << std::endl
                      << line << std::endl;
            std::cout << "inputs are" << (result == 0 ? " NOT " : " ") << "in the right order" << std::endl
                      << std::endl;
        }
        std::getline(std::cin, line);
        validPackets += comparePackets(firstPackets, secondPackets, pairId);
        firstPackets.clear();
        secondPackets.clear();
        ++pairId;
    }
    std::cout << "ValidPackets " << validPackets << std::endl;
}
