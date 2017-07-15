#ifndef __TIMER4_H
#define __TIMER4_H

#include <stdint.h>

/**
 * Timer 4 is a simple 8-bit upcounting counter.
 * Prescaler = 128, fMASTER = 16MHz, Counter = 125 => interrupt interval
 * is 1ms.
 */
void timer4_init();

/**
 * Start the 8-bit timer.
 * @param timeoutp is decreased on every timer tick until 0.
 */
void timer4_start(uint8_t *timeoutp);

/**
 * Stop the timer and clear the internal pointer.
 */
void timer4_stop();

/**
 * You don't need to call the interrupt routine, but it must be
 * visible in main.
 */
void timer4_isr(void) __interrupt(INT_TIM4);

#endif /*__TIMER4_H*/
