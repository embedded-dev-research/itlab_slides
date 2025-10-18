# 09 — Install, export, and CPack

Build and package:

```
cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
cmake --build build --config Release
cmake --install build --prefix build/install
(cd build && cpack -G ZIP)
```

Artifacts:
- Installed tree under `build/install`.
- Package archive in `build/`.

