cmake_minimum_required(VERSION 3.10)

set(SDK_PATH $ENV{LUCKFOX_SDK_PATH})
if(NOT SDK_PATH)
    message(WARNING "Please Set Luckfox-pico SDK Path. Such as:export LUCKFOX_SDK_PATH=/home/user/luckfox-pico")
    return()
endif()

set(CMAKE_C_COMPILER "${SDK_PATH}/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-gcc"
)
set(CMAKE_CXX_COMPILER "${SDK_PATH}/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-g++"
)

project(luckfox_lvgl_demo)


include_directories( 
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/drm
    ${CMAKE_SOURCE_DIR}/lib
    ${CMAKE_SOURCE_DIR}/lib/lvgl
    ${CMAKE_SOURCE_DIR}/lib/lv_drivers
    ${CMAKE_SOURCE_DIR}/custom 
    ${CMAKE_SOURCE_DIR}/generated 
    ${CMAKE_SOURCE_DIR}/generated/guider_customer_fonts 
    ${CMAKE_SOURCE_DIR}/generated/guider_fonts
    ${CMAKE_SOURCE_DIR}/generated/images 
)

link_directories(${CMAKE_SOURCE_DIR}/lib/libdrm
                 ${CMAKE_SOURCE_DIR}/lib/libcjson)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
SET(CMAKE_INSTALL_RPATH "/usr/lib")


# lvgl
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/lvgl)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/lv_drivers)



file(GLOB SRC ${CMAKE_SOURCE_DIR}/src/*.c
            ${CMAKE_SOURCE_DIR}/custom/*.c
            ${CMAKE_SOURCE_DIR}/generated/*.c
            ${CMAKE_SOURCE_DIR}/generated/images/*.c
            ${CMAKE_SOURCE_DIR}/generated/guider_fonts/*.c
)

add_executable(${PROJECT_NAME} 
            ${SRC}
    )
# debug
add_compile_options(-fPIC -Wall -O3 -g0)
# warnning
add_compile_options(
    -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wall -Wextra -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith 
    -fno-strict-aliasing -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess 
    -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic 
    -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body -Wtype-limits -Wshift-negative-value -Wstack-usage=2048 
    -Wno-unused-value -Wno-unused-parameter -Wno-missing-field-initializers -Wuninitialized -Wmaybe-uninitialized -Wall -Wextra -Wno-unused-parameter 
    -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wpointer-arith -Wno-cast-qual -Wmissing-prototypes 
    -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wno-discarded-qualifiers -Wformat-security -Wno-ignored-qualifiers -Wno-sign-compare -std=c99
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/drm
    ${CMAKE_CURRENT_SOURCE_DIR}/include/cjson
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lvgl/src
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lvgl/font
)

target_link_libraries(${PROJECT_NAME}
    #PRIVATE lvgl_examples
    PRIVATE lvgl::drivers
    pthread
    drm
    cjson
)


