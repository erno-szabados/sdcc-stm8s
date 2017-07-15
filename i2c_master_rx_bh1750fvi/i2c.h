#ifndef __I2C_H
#define __I2C_H

#include <stdint.h>

// Maximum message size you can send.
#define I2C_MSG_MAX_DATA_SIZE 8

extern volatile uint8_t _i2c_error;
extern volatile uint8_t _i2c_rx_complete;
extern volatile uint8_t _i2c_tx_complete;

/**
 * Stores state during interrupt calls and returns data
 */
typedef struct {
    uint8_t address; // I2C device address without direction bit
    uint8_t data[I2C_MSG_MAX_DATA_SIZE + 1]; // buffer
    uint8_t di;   // data index during write
    uint8_t size; // < MAX_DATA_SIZE
    uint8_t mode; // I2C_READ|WRITE
} i2c_cmd_t, *i2c_cmd_p;

extern volatile i2c_cmd_p _i2c_cmd_p;

void i2c_init();

void i2c_write_cmd(i2c_cmd_t *cmd);

void i2c_read_cmd(i2c_cmd_t *cmd);

/**
 * You don't need to call the interrupt routine, but it must be
 * visible in main.
 */
void i2c_isr(void) __interrupt(INT_I2C);

#endif /*__I2C_H*/
