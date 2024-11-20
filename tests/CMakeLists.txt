# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name for unit tests
project(CalculatorTests)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Include directories for header files
include_directories(../include)

# Define source files for unit tests
set(TEST_SOURCES
    test_logic.c
    test_events.c
)

# Add executable for logic tests
add_executable(test_logic test_logic.c ../src/logic.c)

# Add executable for event tests
add_executable(test_events test_events.c ../src/events.c ../src/logic.c)

# Find GTK for event test (if needed)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

# Include GTK headers and link GTK libraries for event tests
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
add_definitions(${GTK_CFLAGS_OTHER})
target_link_libraries(test_events ${GTK_LIBRARIES})

# Optional: Add an install target for the tests
install(TARGETS test_logic test_events RUNTIME DESTINATION bin/tests)
