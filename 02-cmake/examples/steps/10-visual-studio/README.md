# 10 — Visual Studio (Windows)

Configure and build with VS 2022 (x64):

```
cmake -S . -B build-vs -G "Visual Studio 17 2022" -A x64
cmake --build build-vs --config Debug
```

Open solution:

- `build-vs/VisualStudioTips.sln` → F7 to Build, Ctrl+F5 to Run.

Tips:

- Use clang-cl toolset: `-T clangcl`
- Use vcpkg for deps: `-DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake`
- Set startup project via `VS_STARTUP_PROJECT` (already done).

