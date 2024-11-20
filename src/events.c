#include <string.h>
#include "events.h"
#include "logic.h"
#include "gui.h"

// Function to handle button clicks
void handle_button_click(const char *button_label) {
    if (strcmp(button_label, "C") == 0) {
        // Clear button
        clear_all();
        update_display(""); // Clear the display
    } else if (strcmp(button_label, "=") == 0) {
        // Equals button
        calculate_result();
        update_display(get_current_input()); // Show the result
    } else if (strcmp(button_label, "+") == 0 || strcmp(button_label, "-") == 0 ||
               strcmp(button_label, "*") == 0 || strcmp(button_label, "/") == 0) {
        // Operator buttons
        set_operator(button_label[0]);
        update_display(""); // Clear the display for the next number
    } else {
        // Number or decimal point buttons
        append_to_input(button_label);
        update_display(get_current_input()); // Update the display
    }
}
