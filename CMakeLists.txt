cmake_minimum_required(VERSION 3.10)

set(SDK_PATH $ENV{LUCKFOX_SDK_PATH})
set(GLIBC_COMPILER $ENV{GLIBC_COMPILER})
if(NOT SDK_PATH)
    message(WARNING "Please Set Luckfox-pico SDK Path. Such as:export LUCKFOX_SDK_PATH=/home/user/luckfox-pico")
    if (NOT GLIBC_COMPILER) 
        message(WARNING "Please Set arm32 glibc compiler Path. Such as:export GLIBC_COMPILER=/opt/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-")
        return()
    else()
        set(CMAKE_C_COMPILER    "${GLIBC_COMPILER}gcc")
        set(CMAKE_CXX_COMPILER  "${GLIBC_COMPILER}g++")
        option(SYSTEM_UBUNTU "Compiled for Ubuntu systems" ON)
    endif()
else()
    set(CMAKE_C_COMPILER "${SDK_PATH}/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-gcc")
    set(CMAKE_CXX_COMPILER "${SDK_PATH}/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-g++")
endif()

project(luckfox_lvgl_demo)

if(SYSTEM_UBUNTU)
    include_directories( 
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/glibc/drm
        ${CMAKE_SOURCE_DIR}/include/glibc/drm/libdrm
        ${CMAKE_SOURCE_DIR}/include/glibc/cjson
        ${CMAKE_SOURCE_DIR}/lib
        ${CMAKE_SOURCE_DIR}/lib/lvgl
        ${CMAKE_SOURCE_DIR}/lib/lv_drivers
        ${CMAKE_SOURCE_DIR}/custom 
        ${CMAKE_SOURCE_DIR}/generated 
        ${CMAKE_SOURCE_DIR}/generated/guider_customer_fonts 
        ${CMAKE_SOURCE_DIR}/generated/guider_fonts
        ${CMAKE_SOURCE_DIR}/generated/images 
    )
    link_directories(${CMAKE_SOURCE_DIR}/lib/glibc/libdrm
                     ${CMAKE_SOURCE_DIR}/lib/glibc/libcjson)
    set(CMAKE_INSTALL_RPATH "$ORIGIN/lib")
else()
    include_directories( 
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/uclibc/drm
        ${CMAKE_SOURCE_DIR}/include/uclibc/cjson
        ${CMAKE_SOURCE_DIR}/lib
        ${CMAKE_SOURCE_DIR}/lib/lvgl
        ${CMAKE_SOURCE_DIR}/lib/lv_drivers
        ${CMAKE_SOURCE_DIR}/custom 
        ${CMAKE_SOURCE_DIR}/generated 
        ${CMAKE_SOURCE_DIR}/generated/guider_customer_fonts 
        ${CMAKE_SOURCE_DIR}/generated/guider_fonts
        ${CMAKE_SOURCE_DIR}/generated/images 
    )
    link_directories(${CMAKE_SOURCE_DIR}/lib/uclibc/libdrm
                     ${CMAKE_SOURCE_DIR}/lib/uclibc/libcjson)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
    SET(CMAKE_INSTALL_RPATH "/usr/lib")
endif()

# lvgl
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/lvgl EXCLUDE_FROM_ALL)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/lv_drivers EXCLUDE_FROM_ALL)


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

if(SYSTEM_UBUNTU)
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/glibc/drm
        ${CMAKE_CURRENT_SOURCE_DIR}/include/glibc/cjson
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/lvgl/src
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/lvgl/font
    )
else()
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/uclibc/drm
        ${CMAKE_CURRENT_SOURCE_DIR}/include/uclibc/cjson
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/lvgl/src
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/lvgl/font
    )
endif()

target_link_libraries(${PROJECT_NAME}
    #PRIVATE lvgl_examples
    PRIVATE lvgl::drivers
    pthread
    drm
    cjson
)

if(SYSTEM_UBUNTU) 
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install/${PROJECT_NAME}")
    install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
    file(GLOB LIBCJSON_FILES "${CMAKE_CURRENT_SOURCE_DIR}/lib/glibc/libcjson/*.so*")  
    file(GLOB LIBDRM_FILES "${CMAKE_CURRENT_SOURCE_DIR}/lib/glibc/libdrm/*.so*")  
    install(FILES ${LIBCJSON_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)                    
    install(FILES ${LIBDRM_FILES}   DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)                    
endif()
