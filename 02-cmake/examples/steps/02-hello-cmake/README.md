# 02 — Hello (CMake minimal)

Generic:

```
cmake -S . -B build
cmake --build build
./build/hello           # Linux/macOS
build\\hello.exe        # Windows
```

Ninja:

```
cmake -S . -B build-ninja -G Ninja -D CMAKE_BUILD_TYPE=Release
cmake --build build-ninja
```

Visual Studio (Windows x64):

```
cmake -S . -B build-vs -G "Visual Studio 17 2022" -A x64
cmake --build build-vs --config Debug
```

Unix Makefiles (Linux/macOS):

```
cmake -S . -B build-make -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug
cmake --build build-make
```

