#include "flash_storage.h"

#define BLOCK_SIZE 512
#define NUM_BLOCKS 64 // Simulating a small USB 1.0 drive (32KB)

static uint8_t flash_data[NUM_BLOCKS * BLOCK_SIZE];

void flash_read(uint32_t lba, uint8_t* buffer, uint32_t bufsize) {
    memcpy(buffer, &flash_data[lba * BLOCK_SIZE], bufsize);
}

void flash_write(uint32_t lba, uint8_t* buffer, uint32_t bufsize) {
    memcpy(&flash_data[lba * BLOCK_SIZE], buffer, bufsize);
}

uint32_t flash_get_capacity() {
    return NUM_BLOCKS;
}
