import tkinter as tk
from tkinter import scrolledtext
import subprocess
import threading

class WifiScanView:
    def __init__(self, root, back_callback):
        self.root = root
        self.back_callback = back_callback
        self.frame = tk.Frame(root, bg="black")
        self.frame.pack(fill="both", expand=True)

        tk.Label(self.frame, text="WLAN Scan läuft...", fg="white", bg="black", font=("Arial", 14)).pack(pady=5)

        self.output_text = scrolledtext.ScrolledText(
            self.frame, wrap=tk.WORD, bg="black", fg="green", font=("Courier", 9)
        )
        self.output_text.pack(expand=True, fill="both", padx=5, pady=5)
        self.output_text.insert(tk.END, "Starte WLAN Scan...\n")

        self.root.bind("<KeyPress-z>", self.go_back)

        self.process = subprocess.Popen(
    ["/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport", "-s"],
    stdout=subprocess.PIPE,
    stderr=subprocess.STDOUT,
    text=True
)

        self.thread = threading.Thread(target=self.run_scan, daemon=True)
        self.thread.start()

    def run_scan(self):
        # Beispiel WLAN Scan mit 'airport' (Mac) oder 'iwlist' (Linux)
        cmd = ["airport", "-s"]  # macOS Beispiel; für Linux z.B. ["sudo", "iwlist", "scan"]
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
