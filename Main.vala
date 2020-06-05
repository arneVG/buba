public static int main(string[] args) {
    
    if (args.length != 3 && args.length != 1) {
        Command.printUsage();
        return -1;
    } 
    else if (args.length == 1) {
        var app = new Application();
        return app.run(args);
    } 
    else {
        switch(args[1]) {
            case "-c":
                print("creating backup\n");
                return Command.create(args[2]);
            case "-r":
                print("restoring backup\n");
                return Command.restore(args[2]);
            default:
                Command.printUsage();
                return -1;
        }
    }
}