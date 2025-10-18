# 05 — Dependencies via find_package (fmt)

Requires fmt to be discoverable by CMake.

Install fmt:

- Ubuntu/Debian: `sudo apt install libfmt-dev`
- macOS (Homebrew): `brew install fmt`
- Windows (vcpkg):
  - `vcpkg install fmt`
  - Configure with: `-DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake`

Build:

```
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"  # on Windows/vcpkg
cmake --build build
```

