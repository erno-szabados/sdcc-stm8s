#include <stdint.h>
#include "../stm8s.h"

/*
 * All unused pins are output in push-pull configuration,
 * low, interrupts disabled, speed slow (<= 2MHz)
 */
inline static void port_init() {
    PA_ODR = 0x00;
    PA_DDR = 0xFF;
    PA_CR1 = 0xFF;
    PA_CR2 = 0x00;

    PB_ODR = 0x00;
    PB_DDR = 0xFF;
    PB_CR1 = 0xFF;
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
inline static void clk_init()
{
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


/**
 * Timer 4 is a simple 8-bit upcounting counter.
 * Prescaler = 128, fMASTER = 16MHz, Counter = 125 => interrupt interval
 * is 1ms.
 */
static void timer4_init() {
    // CK_PSC (internal fMASTER) is divided by the prescaler value.
    TIM4_PSCR = TIM4_PSCR_128;
    // Enable update interrupt for timer 4
    TIM4_IER |= TIM4_IER_UIE;
    // Clear timer interrupt flag
    TIM4_SR &= ~TIM4_SR_UIF;
    // Precalculated value
    //TIM4_CNTR = 0xFF - 126;
    // Enable timer 4
    TIM4_CR1 |= TIM4_CR1_CEN;
    interrupts();
}

int main() {
    port_init();
    clk_init();
    timer4_init();

    while (1) {
        __asm nop __endasm;
    }
}

void timer4_isr(void) __interrupt(INT_TIM4) {
    // Blink led
    PB_ODR ^= 0x20;
    // Clear interrupt flag
    TIM4_SR &= ~TIM4_SR_UIF;
    // Rewrite counter, calculated value is 125
    TIM4_CNTR = 0xFF - 123;
}
