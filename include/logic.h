#ifndef LOGIC_H
#define LOGIC_H

// Appends a digit or decimal point to the current input
void append_to_input(const char *value);

// Sets the operator for the calculation
void set_operator(char operator);

// Clears the current input and calculator state
void clear_all();

// Performs the calculation and stores the result
void calculate_result();

// Retrieves the current input or result for display
const char* get_current_input();

#endif // LOGIC_H
