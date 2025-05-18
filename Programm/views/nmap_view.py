import tkinter as tk
from tkinter import scrolledtext
import subprocess
import threading

class NmapView:
    def __init__(self, root, back_callback):
        self.root = root
        self.back_callback = back_callback
        self.frame = tk.Frame(root, bg="black")
        self.frame.pack(fill="both", expand=True)

        tk.Label(self.frame, text="nmap Scan läuft...", fg="white", bg="black", font=("Arial", 14)).pack(pady=5)

        self.output_text = scrolledtext.ScrolledText(
            self.frame, wrap=tk.WORD, bg="black", fg="green", font=("Courier", 9)
        )
        self.output_text.pack(expand=True, fill="both", padx=5, pady=5)
        self.output_text.insert(tk.END, "Starte nmap...\n")

        self.root.bind("<KeyPress-z>", self.go_back)

        self.process = None
        self.thread = threading.Thread(target=self.run_nmap, daemon=True)
        self.thread.start()

    def append_text(self, text):
        self.output_text.insert(tk.END, text)
        self.output_text.see(tk.END)

    def run_nmap(self):
        try:
            self.process = subprocess.Popen(
                ["nmap", "-sP", "192.168.2.0/24"],
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                text=True
            )
            for line in self.process.stdout:
                self.root.after(0, self.append_text, line)
        except Exception as e:
            self.root.after(0, self.append_text, f"Fehler: {e}\n")

    def go_back(self, event=None):
        self.close()

    def close(self):
        if self.process and self.process.poll() is None:
            self.process.terminate()
        self.frame.destroy()
        if self.back_callback:
            self.back_callback()

