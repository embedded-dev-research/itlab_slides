# 06 — Testing with CTest and GoogleTest

Configure, build, and run tests:

```
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure -j
```

Notes:
- GoogleTest is fetched at configure time via `FetchContent`.
- Use `-DBUILD_TESTS=OFF` to skip tests.

