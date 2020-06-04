int create(string filename) {
    Posix.system("mkdir -r ~/.buba && dconf dump /com/solus-project/ > ~/.buba/budgie-dconf-dump && tar -czvf " + filename + " -C ~/.buba . && rm -R ~/.buba/");
    return 0;
}

int restore(string filename) {
    Posix.system("mkdir -p ~/.buba/ && tar -C ~/.buba -xzvf " + filename + " && dconf load /com/solus-project/ < ~/.buba/budgie-dconf-dump && rm -R ~/.buba/");
    return 0;
}

int main(string[] args) {
    switch(args[1]) {
        case "-c":
            print("creating backup\n");
            create(args[2]);
            break;
        case "-r":
            print("restoring backup\n");
            restore(args[2]);
            break;
        default:
            print("usage: buba [args] <filename>\nargs:\n -c  create a backup\n -r  restore a backup\n");
            break;
    }
    
    return 0;
}