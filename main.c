#include <gtk/gtk.h>
#include "gui.h"

/**
 * The entry point of the application.
 * Initializes the GTK application and starts the GUI.
 */
int main(int argc, char *argv[]) {
    // Initialize and start the GUI
    start_gui(argc, argv);

    // Return success
    return 0;
}