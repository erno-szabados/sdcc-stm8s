SDCC=sdcc
SDLD=sdld
FLASH=stm8flash
OBJECT=i2c.ihx
BOARD=stm8s103f3
PROGRAMMER=stlinkv2

.PHONY: all clean flash

all: $(OBJECT)

clean:
	rm -f $(OBJECT)

flash: $(OBJECT)
	$(FLASH) -c $(PROGRAMMER) -p $(BOARD) -w $(OBJECT)

%.ihx: main.c
	$(SDCC) -lstm8 -mstm8 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $< -o $@
