Raylib Installation for Linux (Ubuntu/Debian)

To build and run **OpenPAS**, you must first install the development dependencies and 
compile the Raylib library from source.

### 1. Install System Dependencies
Open your terminal and run:

```bash
sudo apt update && sudo apt install build-essential git \
libasound2-dev libx11-dev libxrandr-dev libxi-dev \
libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev \
libxinerama-dev libxkbcommon-dev

### 2. Download and build raylib

# Clone the official repo
git clone [https://github.com/raysan5/raylib.git](https://github.com/raysan5/raylib.git)
cd raylib/src

# Compile the library
make PLATFORM=PLATFORM_DESKTOP

# Install to system directories
sudo make install

### 3. Once raylib is installed, use the following command to compile the
# program FROM THE ROOT DIRECTORY.
gcc main.c modules/src/*.c -o openpas \
-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

### 4. Execute it by running the binary.
./openpas 
```
