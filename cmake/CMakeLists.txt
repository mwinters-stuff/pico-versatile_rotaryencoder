cmake_minimum_required(VERSION 3.28)

add_library(Versatile_RotaryEncoder
        ../src/Versatile_RotaryEncoder.cpp
)

target_compile_definitions(Versatile_RotaryEncoder
        PUBLIC BUILD_FOR_PICO_CMAKE=1 BUILD_PICO_FORCE_UART=1 
)

target_include_directories(Versatile_RotaryEncoder PUBLIC
        ../src
)

target_link_libraries(Versatile_RotaryEncoder PUBLIC
        pico_stdlib hardware_pio hardware_irq hardware_timer)