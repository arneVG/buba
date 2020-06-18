import os

def print_usage():
    print("usage: buba [args] <filename>\n args:\n  none  start gui\n  -c    create a backup\n  -r    restore a backup\n")

def create_backup(filename):
    os.system("mkdir -p ~/.buba && dconf dump /com/solus-project/ > ~/.buba/budgie-dconf-dump && tar -czf " + filename + " -C ~/.buba . && rm -R ~/.buba/")

def restore_backup(filename):
    os.system("mkdir -p ~/.buba/ && tar -C ~/.buba -xzf " + filename + " && dconf load /com/solus-project/ < ~/.buba/budgie-dconf-dump && rm -R ~/.buba/")
    os.system("nohup budgie-panel --replace > /dev/null 2>&1 &")