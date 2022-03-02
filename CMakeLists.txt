cmake_minimum_required(VERSION 3.2)
project(SHM_2077)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



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

add_library(${PROJECT_NAME}-lib STATIC ${FILES})
add_executable(${PROJECT_NAME} main.cpp ${FILES})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)


set(TESTS
    tests/friutTest.cpp
)

add_executable(${PROJECT_NAME}-gt ${TEST} ${FILES})
target_link_libraries(${PROJECT_NAME}-gt ${PROJECT_NAME}-lib gtest_main)

target_compile_options(${PROJECT_NAME}-gt PRIVATE ${FLAGS})

enable_testing()
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-gt)
# target_compile_options(${PROJECT_NAME}-gt PRIVATE ${FLAGS})s


# target_link_libraries(${PROJECT_NAME}-ut2 ${PROJECT_NAME}-lib gtest_main)