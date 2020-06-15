#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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