#ifndef __PCF8574_H
#define __PCF8574_H

/**
 * PCF8574/PCF8574A I2C IO Expander. Only the slave address base
 * portion differs.
 * Up to 8 devices of the same type can be operated on the same I2C bus.
 */

/*
 * This value will be left-shifted 1-bit to calculate the
 * read/write address.
 * E.g for 0x38 write address, 0x70 will be transmitted.
 */
#define PCF85741_ADDR 0x27
#define PCF85741A_ADDR 0x38

/* Masks for the device address variations. n is A2:A1:A0 bits */
#define PCF85741_ADDR_MASK(n) (PCF85741_ADDR | ((n) & 0b111))
#define PCF85741A_ADDR_MASK(n) (PCF85741A_ADDR | ((n) & 0b111))

/*
 * Single byte data transfer structure.
 */
typedef struct {
    uint8_t address;
    uint8_t data;
} i2c_cmd_t, *i2c_cmd_p;

#endif /*__PCF8574_H*/
