#include <gtk/gtk.h>
#include "gui.h"
#include "events.h"

// Widgets used globally
GtkWidget *entry;

// Callback function to handle button clicks (delegates to event handlers)
void on_button_clicked(GtkWidget *button, gpointer user_data) {
    const char *button_label = gtk_button_get_label(GTK_BUTTON(button));
    handle_button_click(button_label); // Delegate to events.c
}

// Function to create a button and connect its signal
GtkWidget *create_button(const char *label) {
    GtkWidget *button = gtk_button_new_with_label(label);
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    return button;
}

// Function to set up the GUI
void start_gui(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create the entry widget for displaying input/output
    entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(entry), FALSE);
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

    // Create buttons for digits and basic operations
    const char *buttons[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", "C", "=", "+"
    };

    int pos = 0;
    for (int row = 1; row <= 4; row++) {
        for (int col = 0; col < 4; col++) {
            GtkWidget *button = create_button(buttons[pos++]);
            gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
        }
    }

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();
}

// Function to update the calculator's entry field (used by event handlers)
void update_display(const char *text) {
    gtk_entry_set_text(GTK_ENTRY(entry), text);
}
