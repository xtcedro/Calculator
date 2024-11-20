# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(CalculatorApp)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Include directories for header files
include_directories(include)

# Define source files
set(SOURCES
    main.c
    src/gui.c
    src/events.c
    src/logic.c
)

# Add executable for the main application
add_executable(calculator ${SOURCES})

# Find GTK+3 package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

# Include GTK headers and link GTK libraries
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
add_definitions(${GTK_CFLAGS_OTHER})
target_link_libraries(calculator ${GTK_LIBRARIES})

# Optional: Add an install target
install(TARGETS calculator RUNTIME DESTINATION bin)
