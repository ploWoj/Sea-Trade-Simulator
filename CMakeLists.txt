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

include_directories("{$gmock_SOURCE_DIR}/include")
set (SOURCE_FILE
    src/alcohol.cpp 
    src/cargo.cpp 
    src/coordinates.cpp 
    src/fruit.cpp 
    src/game.cpp 
    src/island.cpp 
    src/item.cpp 
    src/map.cpp 
    src/player.cpp 
    src/ship.cpp 
    src/store.cpp 
    src/time.cpp)

set (FLAGS 
    -Wall 
    -Wextra 
    # -Werror 
    -Wpedantic
    -g)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCE_FILE})
add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-ut tests/tests.cpp)

set(DIRECTORIES 
        src)
    
target_include_directories(${PROJECT_NAME} PRIVATE ${DIRECTORIES})
target_include_directories(${PROJECT_NAME}-lib PRIVATE ${DIRECTORIES})
target_include_directories(${PROJECT_NAME}-ut PRIVATE ${DIRECTORIES})

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${TEST_FLAGS})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main gmock gtest)

enable_testing()
add_test(NAME Tests-gtest COMMAND ${PROJECT_NAME}-ut)