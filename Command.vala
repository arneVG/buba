namespace Command {
    int create(string filename) {
        return Posix.system("mkdir -p ~/.buba && dconf dump /com/solus-project/ > ~/.buba/budgie-dconf-dump && tar -czf " + filename + " -C ~/.buba . && rm -R ~/.buba/");
    }
    
    int restore(string filename) {
        return Posix.system("mkdir -p ~/.buba/ && tar -C ~/.buba -xzf " + filename + " && dconf load /com/solus-project/ < ~/.buba/budgie-dconf-dump && rm -R ~/.buba/");
    }

    void printUsage() {
        print("usage: buba [args] <filename>\n args:\n  none  start gui\n  -c    create a backup\n  -r    restore a backup\n");
    }
}