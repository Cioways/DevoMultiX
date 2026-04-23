# 📜 Adding New Scripts & Tools

DevoMultiX is highly extensible. You can store your own tools or scripts on the Raspberry Pi and call them natively via the Pi's display menu.

## Using Open-Source Tools (Third-Party)

You don't have to reinvent the wheel! It is highly encouraged to utilize existing, trusted open-source tools from the community.
For example, if your script requires `nmap` or `tcpdump`, you can just document the standard Debian installation commands here:

```bash
sudo apt update
sudo apt install nmap
```

*Note: Always link to the original project and respect their open-source licenses when integrating third-party tools.*

## How to Share Your Scripts with the Community

When you (or someone else) write a great script for DevoMultiX, we want the community to benefit!
There are several ways to share it:

1. **Pull Request to this Repo (Recommended)**: You can add your script to a `community-scripts/` folder in our repository and submit a Pull Request. That way, it becomes an official part of the project.
2. **Wiki / Docs Update**: You can write a tutorial on this documentation site explaining how to install and configure your script from your own repository.
3. **External Repository**: Host the script/tool on your own GitHub and we can link to it in a future "Community Plugins" section.

## How the Triggering Works

- The main menu runs on the Raspberry Pi (Debian).
- When you select a hardware-specific task (like scanning an IR code), the Pi sends a UART command (e.g., `START_IR_SCAN`) to the ESP32.
- The ESP32 executes the real-time task and sends the data back to the Pi to display it.
