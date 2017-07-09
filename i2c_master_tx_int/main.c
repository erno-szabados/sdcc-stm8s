#include <stdint.h>
#include "../stm8s.h"
#include "pcf8574.h"

/**
 * I2C Write example for STM8S with 7-bit address using interrupts.
 * ST8M master transfers a single byte to a PCF8574A I2C IO Expander.
 */

/* Interrupt handler uses this to transfer data. */
static volatile i2c_cmd_p _i2c_cmd_p;

#define __delay() {\
    uint32_t i;\
    for(i = 0; i < 40000; i++) \
        __asm nop __endasm;\
}

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
 * Initialize I2C at 100KHz standard mode.
 */
void i2c_init() {
    /* Disable I2C */
    I2C_CR1 &= ~I2C_CR1_PE;
    I2C_FREQR = 16;
    /* Configure I2C clock */
    I2C_CCRH = I2C_CCRH_16MHZ_STD_100;
    I2C_CCRL = I2C_CCRL_16MHZ_STD_100;
    I2C_TRISER = I2C_TRISER_16MHZ_STD_100;

    /* Must always be written as 1 */
    I2C_OARH |= I2C_OARH_ADDCONF;
    /* 7-bit slave address */
    I2C_OARH &= ~I2C_OARH_ADDMODE;

    /* Enable I2C interrupts */
    I2C_ITR |= (I2C_ITR_ITBUFEN|I2C_ITR_ITERREN|I2C_ITR_ITEVTEN);
    /* Configuration ready, re-enable I2C */
    I2C_CR1 |= I2C_CR1_PE;
}

void i2c_send_cmd(i2c_cmd_t *cmd) {
    _i2c_cmd_p = cmd;
    /* Switch to master mode. */
    I2C_CR2 |= I2C_CR2_START;
}

int main() {
    i2c_cmd_t pcf85741_cmd;

    port_init();
    clk_init();
    i2c_init();

    pcf85741_cmd.address = PCF85741A_ADDR_MASK(0b000);
    pcf85741_cmd.data = 0xAA;

    while (1) {
        for (pcf85741_cmd.data = 0; pcf85741_cmd.data < 0xFF; pcf85741_cmd.data++) {
            i2c_send_cmd(&pcf85741_cmd);
            __delay();
        }
    }
}

/* I2C interrupt service routine for master transfer */
void i2c_isr(void) __interrupt(INT_I2C) {
    uint8_t r;
    if (I2C_SR1 & I2C_SR1_SB) {
        /* Start condition bit set, generate start signal and
         * start sending address */
        r = I2C_SR1;
        /* Write slave address to data register */
        I2C_DR = (_i2c_cmd_p->address << 1) | I2C_WRITE;
    } else if (I2C_SR1 & I2C_SR1_ADDR) {
        /* Address sent, ACK received, now send data */
        r = I2C_SR1;
        r = I2C_SR3;
        I2C_DR = _i2c_cmd_p->data;
    } else if (I2C_SR1 & I2C_SR1_TXE) {
        /* Transfer ready, generate stop signal */
        I2C_CR2 |= I2C_CR2_STOP;
    }
}
