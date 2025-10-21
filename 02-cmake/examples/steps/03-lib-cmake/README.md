# 03 — Library + app

Configure and build (generic):

```
cmake -S . -B build
cmake --build build
./build/app             # Linux/macOS
build\\app.exe          # Windows
```

Notes:
- `add` is a simple library linked to `app`.
- Headers are exposed via `target_include_directories(add PUBLIC include)`.

