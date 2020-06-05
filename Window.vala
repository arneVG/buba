public class MyApp.Window : Gtk.ApplicationWindow {
    
    public Window(Application application) {
        Object(
            application: application
        );
    }

    construct {
        title = "BuBa";
        window_position = Gtk.WindowPosition.CENTER;
        set_default_size(350, 80);
        
        show_all();
    }
}