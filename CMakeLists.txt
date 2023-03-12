cmake_minimum_required(VERSION 3.14)
project(RayTracerChallenge LANGUAGES CXX VERSION 0.0.1)



#GooleTest Requires at least C++14
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -DCMAKE_C_COMPILER='c:/msys64/mingw64/bin/g++.exe'")

find_package(Catch2 3 REQUIRED)

add_executable(
    main
    main.cpp
    src/myCanvas.cpp
    src/myColours.cpp
    src/myData.cpp
    src/myTests.cpp
    src/util.cpp
    )
target_link_libraries(main PRIVATE Catch2::Catch2)

include_directories("${CMAKE_CURRECT_SOURCE_DIRECTORY}/include"
                    "${CMAKE_CURRECT_SOURCE_DIRECTORY}/src")

include(CTest)
include(Catch)
catch_discover_tests(main)