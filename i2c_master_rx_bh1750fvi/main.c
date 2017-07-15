#include <stdint.h>
#include "../stm8s.h"
#include "init.h"
#include "timer4.h"
#include "i2c.h"
#include "bh1750.h"

typedef enum {
    MCU_IDLE,
    MCU_INIT_SENSOR,
    MCU_INIT_SENSOR_PENDING,
    MCU_READ_SENSOR,
    MCU_READ_SENSOR_PENDING,
    MCU_WRITE_SENSOR,
    MCU_WRITE_SENSOR_PENDING,
    MCU_ERROR
} mcu_state_t;

typedef enum {
    CMD_NONE,
    CMD_GET_LIGHTLEVEL
} mcu_cmd_t;


int main() {
    i2c_cmd_t device_cmd;
    mcu_state_t mcu_state = MCU_IDLE;
    mcu_cmd_t command = CMD_NONE;
    uint8_t sensor_timeout = 0;
    uint16_t sensor_result;

    port_init();
    clk_init();
    timer4_init();
    i2c_init();

    // For testing
    command = CMD_GET_LIGHTLEVEL;

    // Busy loop TODO add timeout, add delay/sleep
    while (1) {
        if (_i2c_error) {
            mcu_state = MCU_ERROR;
        }
        switch (mcu_state) {
            case MCU_READ_SENSOR:
                // We are waiting for the result
                // Check if 24 ms has elapsed
                if (0 == sensor_timeout) {
                    // yes
                    device_cmd.address = BH1750_ADDR;
                    device_cmd.size = 2;
                    i2c_read_cmd(&device_cmd);
                    mcu_state = MCU_READ_SENSOR_PENDING;
                }
            break;
            case MCU_READ_SENSOR_PENDING:
                if (_i2c_rx_complete) {
                    _i2c_rx_complete = 0;
                    // sensor_result has the sensor value, return it
                    // TODO UART
                    // Enable LED to mark successful measurement
                    PC_ODR |= 0x80;
                    sensor_result = ((device_cmd.data[0] << 8)| device_cmd.data[1]);
                    mcu_state = MCU_IDLE;
                }
            break;
            case MCU_INIT_SENSOR:
                // We are sending the power on command to the sensor
                device_cmd.address = BH1750_ADDR;
                device_cmd.data[0] = BH1750_CMD_POWER_ON;
                device_cmd.size = 1;
                i2c_write_cmd(&device_cmd);
                mcu_state = MCU_INIT_SENSOR_PENDING;
            break;
            case MCU_INIT_SENSOR_PENDING:
                if (_i2c_tx_complete) {
                    PC_ODR |= 0x80;
                    _i2c_tx_complete = 0;
                    mcu_state = MCU_WRITE_SENSOR;
                }
            break;
            case MCU_WRITE_SENSOR:
                // We are sending the command to the sensor
                device_cmd.address = BH1750_ADDR;
                device_cmd.data[0] = BH1750_CMD_ONETIME_LORES;
                device_cmd.size = 1;
                i2c_write_cmd(&device_cmd);
                mcu_state = MCU_WRITE_SENSOR_PENDING;
            break;
            case MCU_WRITE_SENSOR_PENDING:
                // I2C complete interrupt OR timeout will get us out of
                // this state
                if (_i2c_tx_complete) {
                    _i2c_tx_complete = 0;
                    timer4_init();
                    sensor_timeout = BH1750_ONETIME_LORES_SENSOR_TIMEOUT_MS;
                    timer4_start(&sensor_timeout);
                    mcu_state = MCU_READ_SENSOR;
                }
            break;
            case MCU_IDLE:
                // Waiting for command to initiate measurement
                if (CMD_GET_LIGHTLEVEL == command) {
                    command = 0;
                    mcu_state = MCU_INIT_SENSOR;
                }
            break;
            case MCU_ERROR:
            default:
                // For testing
                command = CMD_GET_LIGHTLEVEL;
                // TODO handle error
                // Restart request
                mcu_state = MCU_IDLE;
                i2c_init();
                __delay();
            break;
        }
    }
}
