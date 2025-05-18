import tkinter as tk
from tkinter import scrolledtext
import subprocess
import threading

class ReaverView:
    def __init__(self, root, back_callback):
        self.root = root
        self.back_callback = back_callback
        self.frame = tk.Frame(root, bg="black")
        self.frame.pack(fill="both", expand=True)

        tk.Label(self.frame, text="Reaver läuft...", fg="white", bg="black", font=("Arial", 14)).pack(pady=5)

        self.output_text = scrolledtext.ScrolledText(
            self.frame, wrap=tk.WORD, bg="black", fg="green", font=("Courier", 9)
        )
        self.output_text.pack(expand=True, fill="both", padx=5, pady=5)
        self.output_text.insert(tk.END, "Starte Reaver...\n")

        self.root.bind("<KeyPress-z>", self.go_back)

        self.process = None
        self.thread = threading.Thread(target=self.run_reaver, daemon=True)
        self.thread.start()

    def run_reaver(self):
        # Beispielbefehl, bitte anpassen an deine Umgebung und Interface
        cmd = ["reaver", "-i", "wlan0", "-b", "00:11:22:33:44:55", "-vv"]
        self.process = subprocess.Popen(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True
        )
        for line in self.process.stdout:
            self.output_text.insert(tk.END, line)
            self.output_text.see(tk.END)

    def go_back(self, event=None):
        self.close()

    def close(self):
        if self.process and self.process.poll() is None:
            self.process.terminate()
        self.frame.destroy()
        self.back_callback()
