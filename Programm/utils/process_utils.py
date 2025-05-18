import subprocess
import threading

def run_command(command, output_widget):
    def _target():
        process = subprocess.Popen(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True
        )
        for line in process.stdout:
            output_widget.insert("end", line)
            output_widget.see("end")

    thread = threading.Thread(target=_target)
    thread.start()
