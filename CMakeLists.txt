cmake_minimum_required(VERSION 3.13)

set(project_name "demoproject")

include(vendor/pico-sdk/external/pico_sdk_import.cmake)

project(${project_name} C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${project_name})

target_sources(${project_name} PUBLIC
    src/main.cpp
)

target_include_directories(${project_name} PUBLIC src/)

target_link_libraries(${project_name} pico_stdlib)

pico_enable_stdio_usb(${project_name} 1)
pico_enable_stdio_uart(${project_name} 0)

pico_add_extra_outputs(${project_name})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")