SDCC=sdcc
SDLD=sdld
LDFLAGS=--out-fmt-ihx
CFLAGS=
FLASH=stm8flash
OBJECTS=init.rel main.rel
SYMBOLS=$(OBJECTS:.rel=.sym)
ASMS=$(OBJECTS:.rel=.asm)
LISTS=$(OBJECTS:.rel=.lst)
RSTS=$(OBJECTS:.rel=.rst)
TARGET=blinker.ihx
MAP=$(TARGET:.ihx=.map)
LK=$(TARGET:.ihx=.lk)
CDB=$(TARGET:.ihx=.cdb)

BOARD=stm8s103f3
PROGRAMMER=stlinkv2

.PHONY: all clean flash

all: $(TARGET)

flash: $(TARGET)
	$(FLASH) -c $(PROGRAMMER) -p $(BOARD) -w $(TARGET)

%.rel: %.c
	$(SDCC) -mstm8 -lstm8 $(CFLAGS) -c $<

$(TARGET): $(OBJECTS)
	$(SDCC) -mstm8 -lstm8 $(LDFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(SYMBOLS) $(ASMS) $(LISTS) $(RSTS)
	rm -f $(TARGET) $(MAP) $(LK) $(CDB)

.PHONY: all clean flash
