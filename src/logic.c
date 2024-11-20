#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "logic.h"
#include "gui.h"

static char current_input[256] = "";
static double result = 0;
static char last_operator = '\0';
static int reset_input = 0;

void process_input(const char *input) {
    if (strcmp(input, "C") == 0) {
        clear_calculator();
        return;
    }

    if (strcmp(input, "=") == 0) {
        calculate_result();
        return;
    }

    if (strchr("+-*/", input[0]) != NULL) {
        set_operator(input[0]);
        return;
    }

    append_input(input);
}

void calculate_result() {
    double current_number = atof(current_input);

    switch (last_operator) {
        case '+':
            result += current_number;
            break;
        case '-':
            result -= current_number;
            break;
        case '*':
            result *= current_number;
            break;
        case '/':
            if (current_number != 0) {
                result /= current_number;
            } else {
                gui_update_display("Error: Divide by 0");
                clear_calculator();
                return;
            }
            break;
        default:
            result = current_number;
            break;
    }

    char result_str[256];
    snprintf(result_str, sizeof(result_str), "%g", result);
    gui_update_display(result_str);

    // Prepare for the next operation
    reset_input = 1;
    strcpy(current_input, result_str);
    last_operator = '\0';
}

void set_operator(char operator) {
    if (last_operator != '\0' && !reset_input) {
        calculate_result();
    } else {
        result = atof(current_input);
    }

    last_operator = operator;
    reset_input = 1;
}

void append_input(const char *input) {
    if (reset_input) {
        strcpy(current_input, "");
        reset_input = 0;
    }

    if (strlen(current_input) + strlen(input) < sizeof(current_input)) {
        strcat(current_input, input);
        gui_update_display(current_input);
    }
}

void clear_calculator() {
    result = 0;
    last_operator = '\0';
    reset_input = 0;
    strcpy(current_input, "");
    gui_update_display("0");
}
