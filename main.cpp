/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "mcp3008.h"

#define SPI_CLOCK (1312500)
#define WAIT_TIME_MS 500

SPI spiM(PB_15, PB_14, PB_13);
MCP3008 mcp3008_0(&spiM, PB_2);

int main() {
  printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n",
         MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
  spiM.frequency(SPI_CLOCK);
  uint16_t v0[8];

  while (true) {
    for (int i = 0; i < 8; i++) {
      v0[i] = mcp3008_0.read_input_u16(i);
    }

    for (int i = 0; i < 8; i++) {
      printf("%4d\t", v0[i]);
    }
    printf("\r\n");
    thread_sleep_for(WAIT_TIME_MS);
  }
}
