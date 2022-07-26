# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico-btn-led-nn C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
if (TARGET tinyusb_device)
    add_executable(pico-btn-led-nn pico-btn-led-nn.c )

    pico_set_program_name(pico-btn-led-nn "pico-btn-led-nn")
    pico_set_program_description(pico-btn-led-nn "Test to control external and internal in with multicore.")
    pico_set_program_url(pico-btn-led-nn "https://github.com/irgalieri/pico-btn-led-nn")
    pico_set_program_version(pico-btn-led-nn "0.2")

    pico_enable_stdio_uart(pico-btn-led-nn 0)
    pico_enable_stdio_usb(pico-btn-led-nn 1)

    # Add the standard library to the build
    target_link_libraries(pico-btn-led-nn pico_stdlib pico_multicore)

    pico_add_extra_outputs(pico-btn-led-nn)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()
