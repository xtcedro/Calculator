#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "logic.h"

// Static variables to store the current state
static char current_input[256] = "";
static char current_operator = '\0';
static double stored_value = 0.0;

// Internal helper function to perform calculations
static double calculate(double a, double b, char operator) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0; // Avoid division by zero
        default: return b; // No operation
    }
}

// Appends a digit or decimal point to the current input
void append_to_input(const char *value) {
    if (strlen(current_input) + strlen(value) < sizeof(current_input)) {
        strcat(current_input, value);
    }
}

// Handles an operator press
void set_operator(char operator) {
    if (strlen(current_input) > 0) {
        stored_value = atof(current_input);
        current_operator = operator;
        current_input[0] = '\0'; // Clear the input for the next operand
    }
}

// Clears the current input and state
void clear_all() {
    current_input[0] = '\0';
    stored_value = 0.0;
    current_operator = '\0';
}

// Processes the "=" button press
void calculate_result() {
    if (strlen(current_input) > 0 && current_operator != '\0') {
        double current_value = atof(current_input);
        double result = calculate(stored_value, current_value, current_operator);
        
        // Convert the result back to a string
        snprintf(current_input, sizeof(current_input), "%.10g", result);
        
        // Reset operator for the next calculation
        current_operator = '\0';
    }
}

// Retrieves the current input for display
const char* get_current_input() {
    return current_input;
}
