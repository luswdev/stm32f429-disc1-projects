cmake_minimum_required(VERSION 3.13)

set(CROSS_COMPILER      "/opt/gcc-arm-none-eabi-x86_64-linux/bin/arm-none-eabi-")
set(CMAKE_C_COMPILER    "${CROSS_COMPILER}gcc")
set(CMAKE_CXX_COMPILER  "${CROSS_COMPILER}g++")
set(ASM_COMPILER        "${CROSS_COMPILER}g++")

set(CMAKE_C_COMPILER_LAUNCHER          "ccache")
set(CMAKE_CXX_COMPILER_LAUNCHER        "ccache")

set(CMAKE_OBJSIZE       "${CROSS_COMPILER}size")
set(CMAKE_OBJCOPY       "${CROSS_COMPILER}objcopy")
set(CMAKE_OBJDUMP       "${CROSS_COMPILER}objdump")

set(CMAKE_C_FLAGS
    "-Wall -fno-common -O0 -g -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs"
)
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})
set(CMAKE_ASM_FLAGS ${CMAKE_C_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_CURRENT_LIST_DIR}/drivers/linker/STM32F429ZI_FLASH.ld")

project(stm32-framework
    LANGUAGES C ASM)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/app/src app)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/drivers/cmsis/src cmsis)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/drivers/stm32f4xx/src stm32f4xx)

include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/app/inc
    ${CMAKE_CURRENT_LIST_DIR}/drivers/cmsis/inc
    ${CMAKE_CURRENT_LIST_DIR}/drivers/stm32f4xx/inc
)

add_executable(
    ${PROJECT_NAME}.elf
    ${app}
    ${cmsis}
    ${stm32f4xx}
    ${CMAKE_CURRENT_LIST_DIR}/drivers/startup/startup_stm32f429_439xx.s
)

target_link_libraries(
     ${PROJECT_NAME}.elf
)

add_custom_command(
    TARGET ${PROJECT_NAME}.elf
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ARGS -Obinary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
    COMMAND ${CMAKE_OBJSIZE} ARGS ${PROJECT_NAME}.elf
    COMMAND md5sum ARGS ${PROJECT_NAME}.bin
)
