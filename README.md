![luckfox](https://github.com/LuckfoxTECH/luckfox-pico/assets/144299491/cec5c4a5-22b9-4a9a-abb1-704b11651e88)
# Luckfox Pico LVGL example
[中文](./README_CN.md)

## Test Environment
+ Luckfox Pico Ultra / Luckfox Pico Ultra W (Buildroot System)
+ LF40-480480-ARK / LF40-720720-ARK (Other framebuffer devices may require resolution adjustments)

## Compilation
+ Set environment variables:
    ```
    export LUCKFOX_SDK_PATH=<path_to_luckfox-pico_sdk>
    ```
    **Note:** Use absolute paths.

+ Compile with CMake to obtain the executable:
    ```
    mkdir build
    cd build
    cmake ..
    make -j
    ```

## Running
+ Upload the compiled executable `luckfox_lvgl_demo` to the Luckfox Pico (using adb, ssh, or other methods).
+ Set executable permissions and run:
    ```
    chmod a+x luckfox_lvgl_demo
    ./luckfox_lvgl_demo
    ```

## Note
+ Music playback only supports MP3 format. Place the music files in the `/music` directory, and the program will scan for them upon startup.

## Detailed Tutorial
[RGB Screen](https://wiki.luckfox.com/Luckfox-Pico/Luckfox-Pico-Ultra-RGB-Screen/)
