#include "../stm8s.h"
#include "i2c.h"

/* Interrupt handler uses this to transfer data. */
volatile i2c_cmd_p _i2c_cmd_p;
volatile uint8_t _i2c_rx_complete;
volatile uint8_t _i2c_tx_complete;
volatile uint8_t _i2c_error;

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

    I2C_CR2 |= I2C_CR2_ACK;

    /* Configuration ready, re-enable I2C */
    I2C_CR1 |= I2C_CR1_PE;
    interrupts();
}

void i2c_write_cmd(i2c_cmd_t *cmd) {
    cmd->mode = I2C_WRITE;
    cmd->di = 0;
    _i2c_cmd_p = cmd;
    _i2c_tx_complete = 0;
    _i2c_error = 0;
    /* Switch to master mode. */
    I2C_CR2 |= I2C_CR2_START;
}

void i2c_read_cmd(i2c_cmd_t *cmd) {
    cmd->mode = I2C_READ;
    cmd->di = 0;
    _i2c_cmd_p = cmd;
    _i2c_rx_complete = 0;
    _i2c_error = 0;
    /* Switch to master mode. */
    I2C_CR2 |= I2C_CR2_ACK;
    I2C_CR2 |= I2C_CR2_START;
}

/* I2C interrupt service routine for master receiver */
void i2c_isr(void) __interrupt(INT_I2C) {
    uint8_t r;
    if (I2C_SR1 & I2C_SR1_SB) {

        /* Start condition bit set */
        /* Generate start signal and start sending address */
        r = I2C_SR1;
        /* Write slave address to data register */
        I2C_DR = (_i2c_cmd_p->address << 1) | _i2c_cmd_p->mode;

        return;
    } else if (I2C_SR1 & I2C_SR1_ADDR) {
        /* Address sent, ACK received, now send data */
        r = I2C_SR1;
        r = I2C_SR3;
        if (I2C_WRITE == _i2c_cmd_p->mode) {
            // Write first byte of TX
            I2C_DR = _i2c_cmd_p->data[_i2c_cmd_p->di++];
        }

        return;
    } else if (I2C_SR1 & I2C_SR1_RXNE) {
        // RX buffer not empty, ready to receive next byte
        _i2c_cmd_p->data[_i2c_cmd_p->di++] = I2C_DR;
        if (_i2c_cmd_p->di + 1 == _i2c_cmd_p->size) {
            I2C_CR2 |= I2C_CR2_STOP;
            I2C_CR2 &= ~I2C_CR2_ACK;
            _i2c_rx_complete = 1;

            return;
        }
    } else if (I2C_SR1 & I2C_SR1_TXE) {
        if (_i2c_cmd_p->di == _i2c_cmd_p->size) {
            // TX ready, generate stop signal
            I2C_CR2 |= I2C_CR2_STOP;
            _i2c_tx_complete = 1;

            return;
        }
        // else TX buffer empty, send next byte
        I2C_DR = _i2c_cmd_p->data[_i2c_cmd_p->di++];
    } else if (I2C_SR2 & I2C_SR2_AF) {
        // No ACK Error
        _i2c_error = 1;
    }
}
