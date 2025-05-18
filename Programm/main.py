from views.menu_view import MenuView
from menu_structure import menu
import tkinter as tk

def main():
    root = tk.Tk()
    root.geometry("320x240")  # 2.8" TFT Display

    app = MenuView(root, menu)
    root.mainloop()

if __name__ == "__main__":
    main()
