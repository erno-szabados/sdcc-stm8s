#ifndef __INIT_H
#define __INIT_H

// Busy wait
#define __delay() {\
    uint32_t i;\
    for(i = 0; i < 800000; i++) \
        __asm nop __endasm;\
}

void port_init();

void clk_init();

#endif /*__INIT_H*/
