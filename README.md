# Pipit Engine

Minimal GLFW + GLAD OpenGL starter.

## Build & run (macOS + Homebrew GLFW)

```bash
cd Code/PipinEngine

mkdir -p build
clang -O2 -Wall -Wextra -I GLAD/include -I /opt/homebrew/include -c src/glad.c -o build/glad.o

clang++ -std=c++17 -O2 -Wall -Wextra -I GLAD/include -I /opt/homebrew/include \
  src/main.cpp build/glad.o \
  -L /opt/homebrew/lib -lglfw \
  -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo \
  -o pipit-engine

./pipit-engine
```

