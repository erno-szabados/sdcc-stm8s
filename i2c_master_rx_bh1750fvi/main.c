#include <stdint.h>
#include <stdio.h>
#include "../stm8s.h"
#include "init.h"
#include "timer4.h"
#include "i2c.h"
#include "uart.h"
#include "bh1750.h"


void main() {
    uint16_t sensor_result;
    unsigned char buf[32];

    port_init();
    clk_init();
    timer4_init();
    i2c_init();
    uart_init();

    uart_puts("STM8S at 115200 baud. Measuring light using BH1750\r\n");


    while (1) {
        if (0 == bh1750_onetime_read(&sensor_result, BH1750_RESOLUTION_HI2)) {
            PC_ODR |= 0x80;
            sprintf(buf, "%u lux\r\n", sensor_result);
            uart_puts(buf);
            __delay();
        }  else {
            uart_puts("sensor read error\r\n");
            __delay();
        }
    }


}
