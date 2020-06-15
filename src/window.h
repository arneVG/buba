#include <gtk/gtk.h>

enum {
    COL_NAME = 0,
    COL_AGE,
    NUM_COLS
};

static void on_button_click(GtkApplication *app, gpointer user_data) {
    GtkProgressBar *progress_bar = user_data;
    gtk_progress_bar_pulse(progress_bar);
}

static GtkTreeModel * create_and_fill_model(void) {
    GtkListStore *store;
    GtkTreeIter iter;

    store = gtk_list_store_new(NUM_COLS, G_TYPE_STRING, G_TYPE_UINT);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, COL_NAME, "Heinz El-Mann", COL_AGE, 51, -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, COL_NAME, "Jane Doe", COL_AGE, 23, -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, COL_NAME, "Joe Bungopop", COL_AGE, 91, -1);

    return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model(void) {
    GtkCellRenderer *renderer;
    GtkTreeModel *model;
    GtkWidget *view;

    view = gtk_tree_view_new();

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW (view), -1, "Name", renderer, "text", COL_NAME, NULL);

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW (view), -1, "Age", renderer, "text", COL_AGE, NULL);

    model = create_and_fill_model();

    gtk_tree_view_set_model(GTK_TREE_VIEW (view), model);

    g_object_unref(model);

    return view;
}

static void on_active(GtkApplication *app) {
    GtkWidget *grid;
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *view;
    GtkWidget *progress_bar;
    
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "BuBa");

    button = gtk_button_new_with_label("Button");

    progress_bar = gtk_progress_bar_new();

    view = create_view_and_model();

    grid = gtk_grid_new();
    gtk_grid_attach(GTK_GRID (grid), view, 1, 1, 1, 2);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);
    gtk_grid_attach_next_to(GTK_GRID (grid), progress_bar, button, GTK_POS_BOTTOM, 1, 1);

    g_signal_connect(GTK_BUTTON (button), "clicked", G_CALLBACK (on_button_click), progress_bar);

    gtk_container_add(GTK_CONTAINER (window), GTK_WIDGET (grid));

    gtk_widget_show_all(window);
}

static int setup_window(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("comn.example.GtkApplication",
                                                  G_APPLICATION_FLAGS_NONE);
        g_signal_connect(app, "activate", G_CALLBACK(on_active), NULL);
        return g_application_run(G_APPLICATION(app), argc, argv);
}