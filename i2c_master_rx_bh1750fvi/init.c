#include "../stm8s.h"
#include "init.h"

/*
 * All unused pins are output in push-pull configuration,
 * low, interrupts disabled, speed slow (<= 2MHz)
 */
void port_init() {
    PA_ODR = 0x00;
    PA_DDR = 0xFF;
    PA_CR1 = 0xFF;
    PA_CR2 = 0x00;

    PB_ODR = 0x00;
    PB_DDR = 0xFF;
    // PIN B 45 I2C is open drain
    PB_CR1 = 0xCF;
    PB_CR2 = 0x00;

    PC_ODR = 0x00;
    PC_DDR = 0xFF;
    PC_CR1 = 0xFF;
    PC_CR2 = 0x00;

    PD_ODR = 0x00;
    PD_DDR = 0xFF;
    PD_CR1 = 0xFF;
    PD_CR2 = 0x00;
}

/**
 * Reconfigure System clock, use high speed internal oscillator,
 * disable prescaler.
 */
void clk_init() {
    nointerrupts();
    CLK_ICKR = 0;
    CLK_ICKR |= CLK_ICKR_HSIEN;
    CLK_ECKR = 0;
    CLK_SWR = CLK_SWR_HSI;
    while (0 == (CLK_ICKR & CLK_ICKR_HSIRDY));
    CLK_CKDIVR = 0;
    CLK_PCKENR1 = 0xFF;
    CLK_PCKENR2 = 0xFF;
    CLK_CCOR = 0;
    CLK_HSITRIMR = 0;
    CLK_SWIMCCR = 0;

    CLK_SWCR = 0;
    CLK_SWCR |= CLK_SWCR_SWEN;
    while (0 != (CLK_SWCR & CLK_SWCR_SWBSY));
    interrupts();
}
