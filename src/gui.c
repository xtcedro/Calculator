#include <gtk/gtk.h>
#include "gui.h"
#include "events.h"

GtkWidget *window;
GtkWidget *grid;
GtkWidget *display;

void on_button_clicked(GtkWidget *widget, gpointer data) {
    const char *button_label = gtk_button_get_label(GTK_BUTTON(widget));
    handle_event(button_label);
}

void gui_create_window(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create grid layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create display
    display = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(display), FALSE);
    gtk_entry_set_alignment(GTK_ENTRY(display), 1.0);
    gtk_grid_attach(GTK_GRID(grid), display, 0, 0, 4, 1);

    // Button labels
    const char *buttons[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+"
    };

    // Add buttons to grid
    int row = 1, col = 0;
    for (int i = 0; i < 16; i++) {
        GtkWidget *button = gtk_button_new_with_label(buttons[i]);
        g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
        gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);

        col++;
        if (col == 4) {
            col = 0;
            row++;
        }
    }

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();
}

void gui_update_display(const char *text) {
    gtk_entry_set_text(GTK_ENTRY(display), text);
}
