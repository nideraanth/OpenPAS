To build OpenPAS on Linux, you just need the standard C tools and the X11 development headers so the program can talk to your screen.

=============================================================
1. Install System Dependencies
**Bash**
```
sudo apt update && sudo apt install build-essential \
libasound2-dev libx11-dev libxrandr-dev libxi-dev \
libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev \
libxinerama-dev libxkbcommon-dev
```
-------------------------------------------------------------
2. Compile

Run this from the root directory of the project:
**Bash**
```
gcc main.c modules/src/*.c -o openpas \
-Iinclude -Llib/linux \
-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```
------------------------------------------------------------
3. Run

**Bash**
```
chmod +x openpas
./openpas
```
============================================================