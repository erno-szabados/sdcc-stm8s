#include <stdint.h>
#include "../stm8s.h"
#include "init.h"
#include "timer4.h"
#include "i2c.h"
#include "bh1750.h"

void main() {
    uint16_t sensor_result;

    port_init();
    clk_init();
    timer4_init();
    i2c_init();

    if (0 == bh1750_onetime_read(&sensor_result, BH1750_RESOLUTION_LO)) {
        PC_ODR |= 0x80;
    }

    while (1);
}
