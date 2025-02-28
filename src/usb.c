#include "usb.h"
#include "pico/stdlib.h"
#include "tusb.h"
#include "flash_storage.h"

// USB Descriptor
tusb_desc_device_t const desc_device = {
    .bcdUSB = 0x0100, // USB 1.0
    .idVendor = 0x1234,
    .idProduct = 0x5678,
    .bcdDevice = 0x0100,
    .iManufacturer = 1,
    .iProduct = 2,
    .iSerialNumber = 3,
    .bNumConfigurations = 1
};

// Mass storage callbacks
const tinyusb_msc_callback_t msc_callback = {
    .read = flash_read,
    .write = flash_write,
    .get_capacity = flash_get_capacity
};

void usb_init() {
    tusb_init();
    tinyusb_msc_init(&msc_callback);
}
