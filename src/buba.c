#include "command.h"
#include "window.h"

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 1) {
        return print_usage();
    } else if (argc == 1) {
        setup_window(argc, argv);
    } else {
        if (!strcmp(argv[1], "-c")) {
            printf("creating backup\n");
            return create_backup(argv[2]);
        } else if (!strcmp(argv[1], "-r")) {
            printf("restoring bakcup\n");
            return restore_backup(argv[2]);
        } else {
            return print_usage();
        }
    }
}