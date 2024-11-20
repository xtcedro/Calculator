# Calculator Application

A simple calculator application built in C with a **Graphical User Interface (GUI)** using **GTK+3**. This project demonstrates modular programming with separate files for GUI, event handling, and logic, and includes unit tests for the core functionality.

---

## Features

- **Basic Operations**: Addition, Subtraction, Multiplication, and Division.
- **Graphical Interface**: Intuitive layout with buttons for numbers and operators.
- **Modular Design**:
  - **`gui.c`**: Manages the graphical user interface.
  - **`events.c`**: Handles user interactions and connects GUI to logic.
  - **`logic.c`**: Implements the core calculator operations.
- **Unit Tests**:
  - Logic and event handling are tested independently.
  - Tests ensure code reliability and prevent regressions.

---

## File Structure

calculator/
├── CMakeLists.txt         # Main CMake build script
├── README.md              # Project documentation
├── main.c                 # Entry point for the application
├── src/                   # Source files for the application
│   ├── gui.c              # GUI implementation
│   ├── events.c           # Event handling implementation
│   ├── logic.c            # Core logic implementation
├── include/               # Header files
│   ├── gui.h              # Header for gui.c
│   ├── events.h           # Header for events.c
│   ├── logic.h            # Header for logic.c
├── assets/                # Assets for the GUI
│   ├── logo.png           # Example logo file
│   ├── icons/             # Directory for button/icons (optional)
│   ├── themes/            # Directory for theme files (optional)
├── tests/                 # Unit tests
│   ├── test_logic.c       # Unit tests for logic.c
│   ├── test_events.c      # Unit tests for events.c
│   ├── CMakeLists.txt     # CMake build script for tests