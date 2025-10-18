# Modern CMake Example (Cross‑platform)

Build options:

- Ninja (fast, single‑config):
  - `cmake --preset ninja-debug`
  - `cmake --build --preset build-ninja-debug`
  - Run: `./build/ninja-debug/app` or `build\ninja-debug\app.exe`

- Unix Makefiles (Linux/macOS):
  - `cmake --preset unix-make-debug`
  - `cmake --build --preset build-unix-debug`

- Visual Studio 2022 (Windows, x64):
  - `cmake --preset vs2022-x64`
  - `cmake --build --preset build-vs-debug`
  - Or open `build/vs2022/x64/ModernCMakeExamples.sln` and build.

- MinGW (Windows):
  - `cmake --preset mingw-release`
  - `cmake --build --preset build-mingw-release`

- Xcode (macOS):
  - `cmake --preset xcode-debug`
  - `cmake --build --preset build-xcode-debug`

Tests:

- After configuring with any preset that enables tests (all of the above), run:
  - `ctest --preset test-ninja-debug` (Ninja)
  - `ctest --preset test-vs-debug` (Visual Studio)
  - Or from a build dir: `ctest --output-on-failure -j`

Cross‑compiling (ARM, example):

```
cmake -S . -B build-arm \
  -DCMAKE_TOOLCHAIN_FILE=toolchains/arm-none-eabi.cmake \
  -D CMAKE_BUILD_TYPE=Release
cmake --build build-arm
```

Packaging:

- `cpack -G ZIP` from the configured build directory to create an archive.

