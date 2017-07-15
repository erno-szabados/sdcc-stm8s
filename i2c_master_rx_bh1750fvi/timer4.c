#include <stddef.h>
#include "../stm8s.h"
#include "timer4.h"

volatile uint8_t *_t4_timeoutp;

/**
 * Timer 4 is a simple 8-bit upcounting counter.
 * Prescaler = 128, fMASTER = 16MHz, Counter = 125 => interrupt interval
 * is 1ms.
 */
void timer4_init() {
    nointerrupts();
    // CK_PSC (internal fMASTER) is divided by the prescaler value.
    TIM4_PSCR = TIM4_PSCR_128;
    // Enable update interrupt for timer 4
    TIM4_IER |= TIM4_IER_UIE;
    // Clear timer interrupt flag
    TIM4_SR &= ~TIM4_SR_UIF;
    interrupts();
}

void timer4_start(uint8_t *timeoutp) {
    // Enable timer 4
    _t4_timeoutp = timeoutp;
    TIM4_CR1 |= TIM4_CR1_CEN;
}

void timer4_stop() {
            // disable t4
    TIM4_CR1 &= ~TIM4_CR1_CEN;
    _t4_timeoutp = NULL;
}

void timer4_isr(void) __interrupt(INT_TIM4) {
    if (*_t4_timeoutp > 0) {
        (*_t4_timeoutp)--;
    } else {
        timer4_stop();
    }

    // Clear interrupt flag
    TIM4_SR &= ~TIM4_SR_UIF;
    // Rewrite counter, calculated value is 125
    TIM4_CNTR = 0xFF - 128;
}
