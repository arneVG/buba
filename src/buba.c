#include <gtk/gtk.h>

static int print_usage() {
    return printf("usage: buba [args] <filename>\n args:\n  none  start gui\n  -c    create a backup\n  -r    restore a backup\n");
}

static int create_backup(char filename[]) {
    char command[1024];
    strcpy(command, "mkdir -p ~/.buba && dconf dump /com/solus-project/ > ~/.buba/budgie-dconf-dump && tar -czf ");
    strcat(command, filename);
    strcat(command, " -C ~/.buba . && rm -R ~/.buba/");
    return system(command);
}

static int restore_backup(char filename[]) {
    char command[1024];
    char nohup[48];
    strcpy(nohup, "nohup budgie-panel --replace > /dev/null 2>&1 &");
    strcpy(command, "mkdir -p ~/.buba/ && tar -C ~/.buba -xzf ");
    strcat(command, filename);
    strcat(command, " && dconf load /com/solus-project/ < ~/.buba/budgie-dconf-dump && rm -R ~/.buba/");
    system(command);
    return system(nohup);
}

static void on_active(GtkApplication *app) {
    
    GtkWidget *window = gtk_application_window_new(app);

    GtkWidget *button = gtk_button_new_with_label("Hello, world!");

    g_signal_connect_swapped(button, "clicked", G_CALLBACK(create_backup("test")), window);
    gtk_container_add(GTK_CONTAINER (window), button);
    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    
    if (argc != 3 && argc != 1) {
        return print_usage();
    }
    else if (argc == 1) {
        printf("no args");
        GtkApplication *app = gtk_application_new("comn.example.GtkApplication",
                                                G_APPLICATION_FLAGS_NONE);
        g_signal_connect (app, "activate", G_CALLBACK(on_active), NULL);
        return g_application_run (G_APPLICATION(app), argc, argv);
    }
    else {
        if(!strcmp(argv[1], "-c"))
        {
            printf("creating backup");
            return create_backup(argv[2]);
        }
        else if (!strcmp(argv[1], "-r"))
        {
            printf("restoring bakcup");
            return restore_backup(argv[2]);
        }
        else
        {
            return print_usage();
        }
    }
    
    
    
    
}