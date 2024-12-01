## Set CMake Minimum Version
cmake_minimum_required(VERSION 3.28)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## C++ Version
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

## Project Name and Version
project(AoC VERSION 24.01.00 LANGUAGES CXX)

####################################################################################################################
##                                                    Options                                                     ##
####################################################################################################################

## Enable or Disable Tests Mode
set(BUILD_TESTS_MODE ON CACHE STRING "Enable Tests Mode")

## Enable Verbose Test Output
set(ENABLE_VERBOSE_TESTS OFF CACHE STRING "Enable verbose output for tests")

## Year of Event to Build
set(YEAR_TO_BUILD_MODE 2024 CACHE STRING "Year of Event to Build")

## Day of Event to Build (or "all" to build all)
set(DAY_TO_BUILD_MODE 01 CACHE STRING "Day of Event to Build (or 'all' to build all)")

####################################################################################################################
##                                         Configuration Based on Options                                         ##
####################################################################################################################

message("-- Advent of Code System Options:")

## Build Unit Tests
if (BUILD_TESTS_MODE)
    message("--   [x]: Build Unit Tests: Enabled")
    enable_testing()
else()
    message("--   [ ]: Build Unit Tests: Disabled")
endif()

## Enable Verbose Tests
if (ENABLE_VERBOSE_TESTS)
    message("--   [x]: Verbose Tests: Enabled")
else()
    message("--   [ ]: Verbose Tests: Disabled")
endif()

## Year/Day Build Mode
if (DAY_TO_BUILD_MODE STREQUAL "all")
    message("--        Year to Build: ${YEAR_TO_BUILD_MODE}")
    message("--        Day to Build: ${DAY_TO_BUILD_MODE}")
    
    set(EXE_NAME "${PROJECT_NAME}_${YEAR_TO_BUILD_MODE}")
    set(DAY_PATH "day[0-2][0-9]")
    set(RUNNER_PATH "")
else()
    message("--        Year to Build: ${YEAR_TO_BUILD_MODE}")
    message("--        Day to Build: ${DAY_TO_BUILD_MODE}")
    
    set(EXE_NAME "${PROJECT_NAME}_${YEAR_TO_BUILD_MODE}_${DAY_TO_BUILD_MODE}")
    set(DAY_PATH "day${DAY_TO_BUILD_MODE}")
    set(RUNNER_PATH "day${DAY_TO_BUILD_MODE}/")
endif()


####################################################################################################################
##                                           Dependencies and Libraries                                           ##
####################################################################################################################

## Find Threads
find_package(Threads REQUIRED)

## Find Google Test
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

## Find Yearly Data Inputs
set(DATA_DIR "${CMAKE_SOURCE_DIR}/data/${YEAR_TO_BUILD_MODE}/")
add_compile_definitions(DATA_DIR="${DATA_DIR}")

####################################################################################################################
##                                                Build Executable                                                ##
####################################################################################################################

## Search Project Directories for CPP Files
file(GLOB_RECURSE Year_SRC      CONFIGURE_DEPENDS  "src/${YEAR_TO_BUILD_MODE}/${DAY_PATH}/${DAY_PATH}.cpp")
file(GLOB         Runner_SRC    CONFIGURE_DEPENDS  "src/${YEAR_TO_BUILD_MODE}/${RUNNER_PATH}main.cpp")
file(GLOB         Day_SRC       CONFIGURE_DEPENDS  "src/day.cpp")

add_executable(${EXE_NAME} ${Day_SRC} ${Year_SRC} ${Runner_SRC})

## Compile Options
if (MSVC)
    target_compile_options(${EXE_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${EXE_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

## Link Libraries
set(${EXE_NAME}_LIBRARIES Threads::Threads gcov)
target_link_libraries(${EXE_NAME} PRIVATE ${${EXE_NAME}_LIBRARIES})

## Link Compile Definitions
target_compile_definitions(${EXE_NAME} PRIVATE DATA_DIR="${DATA_DIR}")

####################################################################################################################
##                                             Installation and Tests                                             ##
####################################################################################################################

## Tests Mode
if (BUILD_TESTS_MODE)
    if (DAY_TO_BUILD_MODE STREQUAL "all")
        # Find all test files for all days
        file(GLOB_RECURSE AllTests_SRC CONFIGURE_DEPENDS "src/${YEAR_TO_BUILD_MODE}/day*/test.cpp")

        foreach(test_file ${AllTests_SRC})
            # Extract day from file path (e.g., "src/2024/day01/test.cpp" -> "day01")
            get_filename_component(test_dir ${test_file} DIRECTORY)
            string(REGEX MATCH "day[0-2][0-9]" day_name ${test_dir})

            # Locate the corresponding day source file (e.g., day01.cpp)
            file(GLOB_RECURSE day_src_file CONFIGURE_DEPENDS "src/${YEAR_TO_BUILD_MODE}/${day_name}/${day_name}.cpp")

            if (NOT day_src_file)
                message(FATAL_ERROR "No source file found for test: ${test_file}")
            endif()

            # Define executable name for the day's test suite
            set(day_test_exe "${PROJECT_NAME}_${YEAR_TO_BUILD_MODE}_${day_name}_Tests")

            # Create test executable with both the test file and day source file
            add_executable(${day_test_exe} ${test_file} ${day_src_file} ${Day_SRC})

            # Link test executable with required libraries
            target_link_libraries(${day_test_exe} GTest::gtest GTest::gtest_main ${${EXE_NAME}_LIBRARIES})

            # Register test suite with CTest
            add_test(NAME ${day_test_exe} COMMAND ${day_test_exe})
            set_tests_properties(${day_test_exe} PROPERTIES LABELS ${day_name})
            set_tests_properties(${day_test_exe} PROPERTIES LABELS "Year_${YEAR_TO_BUILD_MODE}:Day_${day_name}")

            # Display information about registered tests
            message("--   Test Suite Registered: ${day_test_exe} (Day Source: ${day_src_file})")
        endforeach()

    else()
        # Single day test setup
        file(GLOB_RECURSE UnitTests_SRC CONFIGURE_DEPENDS "src/${YEAR_TO_BUILD_MODE}/${DAY_PATH}/test.cpp")
        file(GLOB_RECURSE Day_SRC_FILE CONFIGURE_DEPENDS "src/${YEAR_TO_BUILD_MODE}/${DAY_PATH}/${DAY_PATH}.cpp")

        list(LENGTH UnitTests_SRC UnitTests_LEN)

        if (UnitTests_LEN GREATER 0)
            add_executable(${EXE_NAME}_UnitTests ${UnitTests_SRC} ${Day_SRC_FILE} ${Day_SRC})
            target_link_libraries(${EXE_NAME}_UnitTests GTest::gtest GTest::gtest_main ${${EXE_NAME}_LIBRARIES})

            # Register the test executable with CTest
            add_test(NAME ${EXE_NAME}_UnitTests COMMAND ${EXE_NAME}_UnitTests)

            # Optional: Add labels for test grouping
            set_tests_properties(${EXE_NAME}_UnitTests PROPERTIES LABELS "UnitTests")
        else()
            message("No Unit Tests!")
        endif()
    endif()
endif()

####################################################################################################################
##                                           Final Build Configuration                                            ##
####################################################################################################################

message("-- Final AoC Configuration Summary")
message("--   Executable Name: ${EXE_NAME}")
message("--   Tests Mode: ${BUILD_TESTS_MODE}")
message("--   Year to Build: ${YEAR_TO_BUILD_MODE}")
message("--   Day to Build: ${DAY_TO_BUILD_MODE}")
## Summary of Registered Tests
if (BUILD_TESTS_MODE)
    message("-- Registered Tests:")
    get_property(REGISTERED_TESTS DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY TESTS)
    foreach(test ${REGISTERED_TESTS})
        message("--   ${test}")
    endforeach()
endif()