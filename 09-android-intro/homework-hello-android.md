# Домашнее задание: Hello World на Android (NDK)

Подробная инструкция, чтобы собрать и запустить нативный `hello` под Android и сдать результат.

## Что нужно установить
1) **Android SDK command-line tools** (sdkmanager/avdmanager/emulator) — нужны и для эмулятора, и чтобы ставить NDK.
2) **Android NDK** (например, r28c). Пусть в переменной `ANDROID_NDK_PATH`.
3) **Platform Tools (ADB)**. Положите `adb` в PATH или задайте `ANDROID_TOOLS_PATH`.
4) **CMake + Ninja** на хосте (Linux/macOS/Windows WSL).
5) (Опционально) **Эмулятор** из Android SDK, если нет физического устройства.

### Установка SDK/NDK на Linux (через command-line tools)
```bash
# 1. Скачайте command-line tools
wget https://dl.google.com/android/repository/commandlinetools-linux-11076708_latest.zip -O cmd-tools.zip
mkdir -p $HOME/Android/cmdline-tools
unzip -q cmd-tools.zip -d $HOME/Android/cmdline-tools
mv $HOME/Android/cmdline-tools/cmdline-tools $HOME/Android/cmdline-tools/latest

# 2. Пути и sdkmanager
export ANDROID_SDK_ROOT=$HOME/Android
export PATH="$ANDROID_SDK_ROOT/cmdline-tools/latest/bin:$ANDROID_SDK_ROOT/platform-tools:$PATH"

# 3. Примите лицензии (один раз)
yes | sdkmanager --licenses

# 4. Ставим нужное
sdkmanager "platform-tools" \
           "ndk;28.0.12433566" \  # r28c, можно выбрать иную версию
           "cmake;3.31.1" \
           "emulator" \
           "system-images;android-35;google_apis;x86_64"

# 5. Пути для задания
export ANDROID_NDK_PATH="$ANDROID_SDK_ROOT/ndk/28.0.12433566"
export ANDROID_TOOLS_PATH="$ANDROID_SDK_ROOT/platform-tools"
```
Теперь можно продолжать по инструкции ниже.

## Переменные окружения (пропишите в шелле)
```bash
export ANDROID_NDK_PATH=/path/to/android-ndk-r28c
export ANDROID_TOOLS_PATH=/path/to/platform-tools
export PATH="$ANDROID_TOOLS_PATH:$PATH"

# выберите под ваше устройство/эмулятор
export CURRENT_ANDROID_ABI=arm64-v8a        # или armeabi-v7a, x86_64
export CURRENT_ANDROID_PLATFORM=35          # не выше API устройства
export CURRENT_ANDROID_STL=c++_shared       # можно c++_static для бонуса
export CURRENT_CMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_PATH/build/cmake/android.toolchain.cmake
```

Проверки:
- `adb devices` должен показать устройство/эмулятор.
- `adb shell getprop ro.product.cpu.abi` — узнать ABI, чтобы не промахнуться.

## Исходник
Сохраните в `hello.cpp`:
```cpp
#include <iostream>
int main() { std::cout << "Hello Android!\n"; }
```

## Сборка (host → Android)
```bash
cmake -B build -G Ninja \
  -DANDROID_ABI=$CURRENT_ANDROID_ABI \
  -DANDROID_PLATFORM=$CURRENT_ANDROID_PLATFORM \
  -DANDROID_STL=$CURRENT_ANDROID_STL \
  -DCMAKE_TOOLCHAIN_FILE=$CURRENT_CMAKE_TOOLCHAIN_FILE \
  -DCMAKE_BUILD_TYPE=Release

cmake --build build --parallel
```
Результат: `build/hello` — ELF под целевую ABI.

## Запуск на устройстве / эмуляторе
```bash
adb push build/hello /data/local/tmp/
adb shell "chmod +x /data/local/tmp/hello && /data/local/tmp/hello"
```
Ожидаемый вывод: `Hello Android!`

Если видите ошибки:
- `exec format error` — ABI не совпадает.
- `not found` / `linker` — проверьте `ANDROID_PLATFORM` и `c++_shared`. Можно пушнуть `libc++_shared.so` из `$ANDROID_NDK_PATH/toolchains/llvm/prebuilt/.../sysroot/usr/lib/<abi>/`.

## Быстрый подъём эмулятора (CLI)
Если нет устройства, можно пройти задание на эмуляторе.

1) Убедитесь, что в PATH есть `sdkmanager`, `avdmanager`, `emulator` (ставятся через Android SDK command-line tools).
2) Скачайте системный образ (пример: API 35, x86_64, Google APIs):
   ```bash
   sdkmanager "system-images;android-35;google_apis;x86_64"
   ```
3) Создайте виртуальное устройство:
   ```bash
   avdmanager create avd -n ov-emul -k "system-images;android-35;google_apis;x86_64"
   ```
4) Запустите headless:
   ```bash
   emulator -avd ov-emul -no-window -gpu swiftshader_indirect
   ```
5) Проверьте подключение:
   ```bash
   adb devices
   ```
   Должна появиться строка `emulator-5554 device`.
6) Дальше используйте те же команды `adb push/chmod/run`, что и для физического устройства.

## Сдача
В одном сообщении прикрепите:
1) ABI и API level, на которые собирали (например, `arm64-v8a`, API 33).
2) Команды, которые запускали (коротко, можно скопировать из терминала).
3) Скриншот или лог вывода `Hello Android!`.
4) Если что-то не заработало — что именно и какие действия пробовали.
