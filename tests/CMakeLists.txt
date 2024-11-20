cmake_minimum_required(VERSION 3.10)
project(CalculatorTests)

# Include directories
include_directories(../include)

# Add tests
add_executable(test_logic test_logic.c ../src/logic.c)
add_executable(test_events test_events.c ../src/logic.c ../src/events.c)

# Link necessary libraries (if needed, e.g., GTK for `events.c`)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
add_definitions(${GTK_CFLAGS_OTHER})

target_link_libraries(test_events ${GTK_LIBRARIES})
