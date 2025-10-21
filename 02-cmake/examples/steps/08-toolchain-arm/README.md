# 08 — Cross-compiling with a toolchain (ARM)

Requires `arm-none-eabi-gcc` toolchain.

```
cmake -S . -B build-arm \
  -DCMAKE_TOOLCHAIN_FILE=toolchains/arm-none-eabi.cmake \
  -D CMAKE_BUILD_TYPE=Release
cmake --build build-arm
```

This produces binaries for the ARM target (not runnable on host).

