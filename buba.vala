void create(string filename) {
    Posix.system("mkdir -p ~/.buba && dconf dump /com/solus-project/ > ~/.buba/budgie-dconf-dump && tar -czf " + filename + " -C ~/.buba . && rm -R ~/.buba/");
}

void restore(string filename) {
    Posix.system("mkdir -p ~/.buba/ && tar -C ~/.buba -xzf " + filename + " && dconf load /com/solus-project/ < ~/.buba/budgie-dconf-dump && rm -R ~/.buba/");
}

int main(string[] args) {
    if (args.length != 3) {
        print("usage: buba [args] <filename>\n args:\n  -c  create a backup\n  -r  restore a backup\n");
    } else {
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
                print("usage: buba [args] <filename>\n args:\n  -c  create a backup\n  -r  restore a backup\n");
                break;
        }
    }
    
    return 0;
}