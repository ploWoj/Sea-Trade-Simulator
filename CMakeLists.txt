cmake_minimum_required(VERSION 3.2)
project(SHM_2077)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILES
     src/island.cpp
    src/map.cpp
    src/player.cpp
    src/ship.cpp
    src/cargo.cpp
    src/store.cpp
    src/alcohol.cpp
    src/item.cpp 
    src/fruit.cpp
    src/time.cpp
    src/game.cpp
    )

set(FLAGS 
    -Wall 
    #-Wextra 
    -Wpedantic 
    -Wconversion 
    -O0)

add_executable(${PROJECT_NAME} main.cpp ${FILES})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
