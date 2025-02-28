cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(pico_usb_drive)
pico_sdk_init()

add_executable(pico_usb_drive
    src/main.c
    src/usb.c
    src/flash_storage.c
)

target_include_directories(pico_usb_drive PRIVATE include)
target_link_libraries(pico_usb_drive pico_stdlib tinyusb_device tinyusb_board)

pico_add_extra_outputs(pico_usb_drive)
