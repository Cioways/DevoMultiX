import tkinter as tk
from tkinter import ttk
import importlib
from theme import BG_COLOR, BTN_COLOR, BTN_HOVER, TEXT_COLOR, TEXT_HIGHLIGHT, FONT

class MenuView:
    def __init__(self, root, menu_structure, back_callback=None):
        self.root = root
        self.menu_structure = menu_structure
        self.back_callback = back_callback
        self.frame = tk.Frame(root, bg=BG_COLOR)
        self.frame.pack(fill="both", expand=True)

        # Style für dunkle Buttons definieren
        style = ttk.Style()
        style.theme_use('default')
        style.configure('Dark.TButton',
                        background=BTN_COLOR,
                        foreground=TEXT_COLOR,
                        font=FONT,
                        borderwidth=0,
                        focusthickness=3,
                        focuscolor=BTN_HOVER)
        style.map('Dark.TButton',
                  background=[('active', BTN_HOVER), ('pressed', BTN_HOVER)],
                  foreground=[('active', TEXT_HIGHLIGHT), ('pressed', TEXT_HIGHLIGHT)])

        self.button_style = 'Dark.TButton'

        self.history = []
        self.current_menu = menu_structure
        self.show_menu(self.current_menu)

        self.root.bind("<KeyPress-z>", self.go_back)

    def show_menu(self, menu_dict):
        for widget in self.frame.winfo_children():
            widget.destroy()

        for label, target in menu_dict.items():
            btn = ttk.Button(
                self.frame,
                text=label,
                style=self.button_style,
                command=lambda t=target, l=label: self.handle_selection(t, l)
            )
            btn.pack(fill="x", pady=6, padx=12, ipadx=5, ipady=4)

    def handle_selection(self, target, label):
        if target == "BACK":
            self.go_back()
        elif isinstance(target, dict):
            self.history.append(self.current_menu)
            self.current_menu = target
            self.show_menu(self.current_menu)
        elif isinstance(target, str):
            try:
                module_path, class_name = target.rsplit(".", 1)
                module = importlib.import_module(module_path)
                view_class = getattr(module, class_name)
                self.frame.destroy()
                view_class(self.root, self.show_main_menu)
            except Exception as e:
                print(f"Fehler beim Laden der View {target}: {e}")

    def go_back(self, event=None):
        if self.history:
            self.current_menu = self.history.pop()
            self.show_menu(self.current_menu)
        elif self.back_callback:
            self.frame.destroy()
            self.back_callback()

    def show_main_menu(self):
        self.frame = tk.Frame(self.root, bg=BG_COLOR)
        self.frame.pack(fill="both", expand=True)
        self.current_menu = self.menu_structure
        self.history = []
        self.show_menu(self.current_menu)
