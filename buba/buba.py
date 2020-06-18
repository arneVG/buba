import sys
from .command import print_usage, create_backup, restore_backup
from .window import setup_window

argv = sys.argv
argc = len(sys.argv)

def main():
    if (argc != 3 and argc != 1):
        print_usage()
    elif (argc == 1):
        setup_window()
    else:
        if argv[1] == "-c":
            print("creating backup")
            create_backup(argv[2])
        elif argv[1] == "-r":
            print("restoring backup")
            restore_backup(argv[2])
        else:
            print_usage()