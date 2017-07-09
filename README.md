# sdcc-stm8s

Examples for SDCC and STM8S microcontroller.
Includes a rudimentary header for register definitions, interrupts and bitmasks.
Compiled by the SDCC compiler version 3.5.0, tested on an ST8MSF103.

Links:

http://sdcc.sourceforge.net/
https://github.com/vdudouyt/stm8flash
http://www.st.com/en/microcontrollers/stm8s-series.html

Examples:

UART Example 

Demonstrates async serial connection with 115200 8N1 and configures 
Internal oscillator to run at 16MHz.

Timer 4 Example

Demonstrates a timer interrupt with 1ms interval (500Hz), toggles PIN PORTB3.

I2C Master TX Interrupt Example

Demonstrates I2C Master Transmission using interrupts. Counts upwards and sends single byte data 
to a PCF8574A IO expander. No error handling.
