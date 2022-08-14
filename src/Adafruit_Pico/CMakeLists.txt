add_library(Adafruit_Pico INTERFACE)

target_sources(Adafruit_Pico INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/Adafruit_Pico_I2CDevice.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Adafruit_Pico_Si7021.cpp
)

target_include_directories(Adafruit_Pico INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(Adafruit_Pico INTERFACE pico_stdlib hardware_i2c)