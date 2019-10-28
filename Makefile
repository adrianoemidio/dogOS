PROJNAME = c_test
TARGET=$(PROJNAME).elf
BIN=$(PROJNAME).bin
OBJ := main.o init.o hw_config.o uart.o gpioTest.o video.o GFX2d.o
LDSCRIPT=lnk.ld
CC=arm-none-eabi-gcc
CROSS=arm-none-eabi-
CFLAGS := -nostartfiles -g -mcpu=cortex-m4 -march=armv7e-m -mthumb
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
#CFLAGS += -ffunction-sections -fdata-sections
#CFLAGS += -Wl,--gc-sections -Wl,-Map=$(PROJNAME).map
#CFLAGS += -Wl,--defsym,jhc_zeroAddress=0
LDFLAGS := -o
OBJCPFLAGS := -Obinary
DEPDIR := .d
# "> null 2>&1" is a Windows equivalent for > /dev/null in Linux
#$(shell mkdir $(DEPDIR) > null 2>&1)
$(shell mkdir $(DEPDIR) > null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) -c
RM = rm


all: $(BIN)


%.o : %.c
%.o : %.c $(DEPDIR)/%.d
	$(COMPILE.c) $<
        

$(TARGET): $(OBJ) $(LDSCRIPT)
	$(CROSS)ld $(LDFLAGS) $@ -T $(LDSCRIPT) $(OBJ)

$(BIN): $(TARGET)
	$(CROSS)objcopy $(OBJCPFLAGS) $(TARGET) $@
	
list: $(TARGET)
	arm-none-eabi-objdump -S $(TARGET) > $(PROJNAME).list

clean:
	$(RM) *.o *.elf *.bin


$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS))))
