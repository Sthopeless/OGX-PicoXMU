#include <stdio.h>
#include "pico/stdlib.h"
#include "tusb.h"
#include "usb.h"

int main() {
    stdio_init_all();
    tusb_init();

    while (true) {
        tud_task(); // Handle USB events
    }
}
