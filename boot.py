import usb_cdc
import usb_msc
import storage
import board
import busio
import adafruit_sdcard
import digitalio
import os

# Function to check if SD card is inserted
def check_sdcard():
    try:
        # Use SPI interface to communicate with SD card
        spi = busio.SPI(board.SCK, board.MOSI, board.MISO)
        cs = digitalio.DigitalInOut(board.D13)
        sdcard = adafruit_sdcard.SDCard(spi, cs)
        
        # Mount the SD card
        vfs = storage.VfsFat(sdcard)
        storage.mount(vfs, "/sd")
        
        print("SD card mounted successfully.")
        return True
    except Exception as e:
        print("No SD card found:", e)
        return False

# Modify the USB device descriptor
usb_cdc.serial.set_usb_descriptor(
    vendor=0x1234,
    product=0x5678,
    device=0x0100,
    manufacturer="OGX-PicoXMU",
    product="OGX-PicoXMU",
    serial="1234567890ABCDEF"
)

# Check if SD card is inserted, if not use internal storage
if check_sdcard():
    storage.remount("/sd", readonly=False)
else:
    storage.remount("/", readonly=False)

# Set up USB Mass Storage
usb_msc.mount(storage)
