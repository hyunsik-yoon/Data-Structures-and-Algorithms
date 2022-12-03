cmake_policy(SET CMP0048 NEW)

project(DSA_PROJECT VERSION 0.1.0)

cmake_minimum_required(VERSION 3.14)
option(BUILD_TEST "Build gtest" ON)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

file(GLOB DSA_TEST_FILES src/*.test.cpp)

file(GLOB DSA_SRC_FILES src/*.cpp)
list(REMOVE_ITEM DSA_SRC_FILES ${DSA_TEST_FILES})

add_library(dsa_lib STATIC ${DSA_SRC_FILES})
target_include_directories(dsa_lib PUBLIC "include")

if (BUILD_TEST)

    #
    # Copied from http://google.github.io/googletest/quickstart-cmake.html#set-up-a-project
    #
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.12.0.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    enable_testing()
    #
    # End of copy
    #

    add_executable(dsa_test ${DSA_TEST_FILES})

    target_link_libraries(dsa_test gtest_main)
    target_link_libraries(dsa_test dsa_lib)

    # Enabling '$ make test'
    add_test(NAME dsa_test COMMAND dsa_test)
endif()
