#include <stdint.h>
#include "../stm8s.h"
#include "timer4.h"
#include "i2c.h"
#include "bh1750.h"

typedef enum {
    SENSOR_INIT,
    SENSOR_INIT_PENDING,
    SENSOR_READ,
    SENSOR_READ_PENDING,
    SENSOR_WRITE,
    SENSOR_WRITE_PENDING,
    SENSOR_READY,
    SENSOR_ERROR
} sensor_state_t;

int bh1750_onetime_read(uint16_t *result, uint8_t resolution) {
    sensor_state_t sensor_state = SENSOR_INIT;
    uint8_t sensor_timeout = 0;
    uint32_t lux;
    i2c_cmd_t device_cmd;

    // TODO timeout, improved error handling
    while (1) {
    if (_i2c_error) {
            sensor_state = SENSOR_ERROR;
        }
        switch (sensor_state) {
            case SENSOR_READ:
                // We are waiting for the result
                // Check if 24 ms has elapsed
                if (0 == sensor_timeout) {
                    // yes
                    device_cmd.address = BH1750_ADDR;
                    device_cmd.size = 2;
                    i2c_read_cmd(&device_cmd);
                    sensor_state = SENSOR_READ_PENDING;
                }
            break;
            case SENSOR_READ_PENDING:
                if (_i2c_rx_complete) {
                    _i2c_rx_complete = 0;
                    // sensor_result has the sensor value, return it
                    // divide by 1.2 to get value in lux
                    lux = ((device_cmd.data[0] << 8)| device_cmd.data[1]);
                    lux *= 5;
                    if (resolution == BH1750_RESOLUTION_HI2) {
                        lux /= 12;
                    } else {
                        lux /= 6;
                    }
                    *result = (uint16_t)lux;
                    sensor_state = SENSOR_READY;

                    return 0;
                }
            break;
            case SENSOR_INIT:
                // We are sending the power on command to the sensor
                device_cmd.address = BH1750_ADDR;
                device_cmd.data[0] = BH1750_CMD_POWER_ON;
                device_cmd.size = 1;
                i2c_write_cmd(&device_cmd);
                sensor_state = SENSOR_INIT_PENDING;
            break;
            case SENSOR_INIT_PENDING:
                if (_i2c_tx_complete) {
                    _i2c_tx_complete = 0;
                    sensor_state = SENSOR_WRITE;
                }
            break;
            case SENSOR_WRITE:
                // We are sending the command to the sensor
                device_cmd.address = BH1750_ADDR;
                device_cmd.data[0] = resolution;
                device_cmd.size = 1;
                i2c_write_cmd(&device_cmd);
                sensor_state = SENSOR_WRITE_PENDING;
            break;
            case SENSOR_WRITE_PENDING:
                // I2C complete interrupt OR timeout will get us out of
                // this state
                if (_i2c_tx_complete) {
                    _i2c_tx_complete = 0;
                    timer4_init();
                    if (resolution == BH1750_RESOLUTION_LO) {
                        sensor_timeout = BH1750_ONETIME_LORES_SENSOR_TIMEOUT_MS;
                    } else {
                        sensor_timeout = BH1750_ONETIME_HIRES_SENSOR_TIMEOUT_MS;
                    }
                    timer4_start(&sensor_timeout);
                    sensor_state = SENSOR_READ;
                }
            break;
            case SENSOR_ERROR:
            default:
                // TODO handle error
                // Reinitialize
                i2c_init();

                return -1;
            break;
        }
    }
}
