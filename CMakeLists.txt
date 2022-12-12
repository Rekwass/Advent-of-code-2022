cmake_minimum_required(VERSION 3.17)

project("adventOfCode2022" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../)

###############################################################################
# SET COMPILATION FLAGS
###############################################################################

if (CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wshadow -Wno-unused-parameter -W")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb3")

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

###############################################################################
# SOURCES
###############################################################################

set(PROJECT_SOURCES
    main.cpp
    day1/calorieCounting.cpp
    day2/rockPaperScissors.cpp
    day3/rucksackReorganization.cpp
    day4/campCleanup.cpp
    day5/supplyStacks.cpp
    day6/tuningTrouble.cpp
    day7/noSpaceLeftOnDevice.cpp
    day8/treetopTreeHouse.cpp
    day12/hillClimbingAlgorithm.cpp
)

set(INCLUDES
    include/
)

###############################################################################
# CREATE EXECUTABLE
###############################################################################

add_executable(${PROJECT_NAME}
    main.cpp
    ${PROJECT_SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${INCLUDES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${LIBRARIES}
)
