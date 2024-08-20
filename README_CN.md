![luckfox](https://github.com/LuckfoxTECH/luckfox-pico/assets/144299491/cec5c4a5-22b9-4a9a-abb1-704b11651e88)
# Luckfox Pico LVGL example
[English](./README.md)
    
## 测试环境
+ Luckfox Pico Ultra / Luckfox Pico Ultra W ( Buildroot 系统 )
+ LF40-480480-ARK / LF40-720720-ARK ( 其他Framebuffer设备需要修改分辨率 )

## 编译
+ 设置环境变量
    ```
    export LUCKFOX_SDK_PATH=< luckfox-pico Sdk 地址>
    ```
    **注意**：使用绝对地址。
+ 使用 CMake 编译获取可执行程序 
    ```
    mkdir build
    cd build
    cmake ..
    make -j
    ```

## 运行
+ 将编译生成的可执行程序 `luckfox_lvgl_demo` 上传到 Luckfox Pico 上(可使用adb ssh等方式)
+ 设置可执行权限后执行
    ```
    chmod a+x luckfox_lvgl_demo
    ./luckfox_lvgl_demo
    ```

## 注意
+ 音乐播放仅支持 MP3 格式，将要播放的音乐放到 `/music` 文件下程序会在启动后检索

## 详细教程
[RGB 屏幕](https://wiki.luckfox.com/zh/Luckfox-Pico/Luckfox-Pico-Ultra-RGB-Screen)


