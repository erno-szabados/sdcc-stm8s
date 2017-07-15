#ifndef __BH1750_H
#define __BH1750_H

/**
 * BH1750 Light sensitivity sensor with I2C interface.
 *
 * HI Resolution measurement: takes longer, better resolution and
 * noise rejection.
 * LOW Resolution measurement: faster, worse resolution and poor
 * noise rejection.
 *
 * Continuous measurement - keep measuring.
 * One time measurement - return to power down mode after measurement.
 *
 * See specification for more details.
 **/

// Depends on ADDR pin (GND,VCC)
#define BH1750_ADDR_HIGH 0x5C
#define BH1750_ADDR_LOW  0x23
#define BH1750_ADDR BH1750_ADDR_LOW

#define BH1750_CMD_POWER_DOWN 0x00
#define BH1750_CMD_POWER_ON 0x01

// Reset is not accepted in power down
#define BH1750_CMD_RESET 0x07

// 1LUX, high resolution continuous measurements, measurement time ca 120ms
#define BH1750_CMD_CONT_HIRES 0x10
// 0.5LUX, highest resolution continuous measurements
#define BH1750_CMD_CONT_HIRES_MODE2 0x11
// 4LUX, least resolution continuous measurements, measurement time ca 16ms
#define BH1750_CMD_CONT_LORES 0x13

// 1LUX, high resolution single shot measurements
#define BH1750_CMD_ONETIME_HIRES 0x20
// 0.5LUX, highest resolution single shot measurements
#define BH1750_CMD_ONETIME_HIRES_MODE2 0x21
// 4LUX, low resolution single shot measurements
#define BH1750_CMD_ONETIME_LORES 0x23

#define BH1750_ONETIME_LORES_SENSOR_TIMEOUT_MS 24

// Change measurement time, high bits
#define BH1750_CMD_CHG_MSMT_HIGH(n) (0b01000000 | (0b00000111 & (n)))
// Change measurement time, low bits
#define BH1750_CMD_CHG_MSMT_LOW(n)  (0b01100000 | (0b00011111 & (n)))


#endif /*__BH1750_H*/
