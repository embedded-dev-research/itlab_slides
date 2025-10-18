# Hello Example (Cross‑platform)

Build with your preferred generator:

- Generic (works everywhere):
  - `cmake -S . -B build`
  - `cmake --build build`
  - Run: `./build/hello` (Linux/macOS) or `build\hello.exe` (Windows)

- Ninja:
  - `cmake -S . -B build-ninja -G Ninja -D CMAKE_BUILD_TYPE=Release`
  - `cmake --build build-ninja`

- Unix Makefiles (Linux/macOS):
  - `cmake -S . -B build-make -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug`
  - `cmake --build build-make`

- Visual Studio (Windows, x64):
  - `cmake -S . -B build-vs -G "Visual Studio 17 2022" -A x64`
  - `cmake --build build-vs --config Release`
  - Or open `build-vs/HelloCMake.sln` in Visual Studio.

- MinGW (Windows):
  - `cmake -S . -B build-mingw -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release`
  - `cmake --build build-mingw`

Presets are provided in `CMakePresets.json` for common setups.

