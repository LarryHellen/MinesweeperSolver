cmake_minimum_required(VERSION 3.29)
project(MinesweeperBacktracing)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(MinesweeperBacktracing main.cpp SpriteSheetCutter.h SpriteSheetCutter.cpp
        View.cpp
        View.h
        Model.cpp
        Model.h
        Controller.cpp
        Controller.h
        Node.cpp
        Node.h)

target_link_libraries(MinesweeperBacktracing sfml-system sfml-window sfml-graphics sfml-network sfml-audio)