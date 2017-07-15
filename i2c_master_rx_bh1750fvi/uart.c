/**
 * SDCC - STM8 Example for UART Configuration.
 *
 * UART Settings: 115200 8N1
 * Clock: 16MHz INTOSC
 *
 **/

#include <string.h>
#include <stdint.h>
#include "../stm8s.h"
#include "uart.h"


/**
 * Write string to uart.
 * @param
 *
 * @return bytes written.
 */
int uart_puts(const char *s) {
    uint8_t i;
    for(i = 0; i < strlen(s); i++) {
        while(!(UART1_SR & UART_SR_TXE));
        UART1_DR = s[i];
    }

    return(i);
}

/**
 * Initialize UART with fixed settings: 115200 8N1
 */
void uart_init() {
    /* Configure RX and TX pins */
    PD_DDR = 0xBF;
    PD_CR1 = 0xFF;

    /* Enable TX & RX */
    UART1_CR2 = UART_CR2_TEN | UART_CR2_REN;
    /* 1 stop bit */
    UART1_CR3 &= ~(UART_CR3_STOP1 | UART_CR3_STOP0);
    /* 115200 baud, 16MHz, Error:0.08%   */
    UART1_BRR2 = 0x0B;
    UART1_BRR1 = 0x08;
}
