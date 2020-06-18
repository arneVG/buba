import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk
from .fileio import list_files


class Window(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title="Buba")
        self.set_default_size(350, 250)
        self.set_border_width(10)

        grid = Gtk.Grid()
        grid.set_column_spacing(10)
        self.add(grid)

        files = list_files()

        layout_liststore = Gtk.ListStore(str)
        for file in files:
            layout_liststore.append([file])

        scrolled_window = Gtk.ScrolledWindow()
        scrolled_window.set_policy(Gtk.PolicyType.AUTOMATIC, Gtk.PolicyType.AUTOMATIC)

        treeview = Gtk.TreeView(layout_liststore)
        for i, column_title in enumerate(
            ["Layout"]
        ):
            renderer = Gtk.CellRendererText()
            column = Gtk.TreeViewColumn(column_title, renderer, text=i)
            treeview.append_column(column)

        treeview.set_hexpand(True)
        treeview.set_vexpand(True)

        scrolled_window.add_with_viewport(treeview)

        btnImport = Gtk.Button(label="Import")
        btnApply = Gtk.Button(label="Apply")
        btnRename = Gtk.Button(label="Rename")

        box = Gtk.VBox(spacing=10)
        box.pack_start(btnImport, False, False, 0)
        box.pack_start(btnApply, False, False, 0)
        box.pack_start(btnRename, False, False, 0)

        grid.add(scrolled_window)
        grid.attach_next_to(box, scrolled_window, Gtk.PositionType.RIGHT, 1, 1)

def setup_window():
    win = Window()
    win.connect("destroy", Gtk.main_quit)
    win.show_all()
    Gtk.main()