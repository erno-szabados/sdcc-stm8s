#include <stdint.h>
#include <stdio.h>
#include "../stm8s.h"
#include "init.h"


void main() {
    port_init();
    clk_init();

    while (1) {
            PB_ODR ^= 0x20;
            __delay();
    }

}
