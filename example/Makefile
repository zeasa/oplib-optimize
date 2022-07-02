CROSS_PREFIX = riscv32-unknown-elf
CC = $(CROSS_PREFIX)-gcc
G++ = $(CROSS_PREFIX)-g++
AS = $(CROSS_PREFIX)-as
LD = $(CROSS_PREFIX)-ld
NM = $(CROSS_PREFIX)-nm
OBJCOPY = $(CROSS_PREFIX)-objcopy
OBJDUMP = $(CROSS_PREFIX)-objdump
STRIP = $(CROSS_PREFIX)-strip

output_name = npu_instr_ext_example
config = ./link.lds

elf = $(output_name).elf
bin = $(output_name).bin
data = $(output_name).dat
hex = $(output_name).hex
dump = $(output_name).asm

OUT_DIR			= ../build/example
INC_PATH		= ../include

OPTIMIZE		= -Os
INCLUDES 		= -I$(INC_PATH)
CFLAGS			= -march=rv32ima -mabi=ilp32 -mcmodel=medany -ffunction-sections -fdata-sections -g $(INCLUDES)
# LDFLAGS			= -nostartfiles -nostdlib -static -lgcc -Wl,--nmagic -Wl,--gc-sections
LDFLAGS			= -static -lgcc -Wl,--nmagic -Wl,--gc-sections

OBJ = \
		$(OUT_DIR)/example_main.o \
		$(OUT_DIR)/example_vec.o \
		$(OUT_DIR)/example_mtx.o \
		$(OUT_DIR)/example_spc.o

all: dir $(bin)

dir:
	mkdir -p $(OUT_DIR)

$(bin): $(OBJ) 
# $(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(DEFINES) -o $(OUT_DIR)/$(elf) -T $(config) -nostartfiles -nostdlib
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(OUT_DIR)/$(elf)
	$(OBJDUMP) -DSxtd $(OUT_DIR)/$(elf) > $(OUT_DIR)/$(dump)
	$(OBJCOPY) -O binary $(OUT_DIR)/$(elf) $(OUT_DIR)/$(bin)
#$(OBJCOPY) -O verilog $(OUT_DIR)/$(elf) $(OUT_DIR)/$(data)
#$(OBJCOPY) -O ihex $(OUT_DIR)/$(elf) $(OUT_DIR)/$(hex)

$(OUT_DIR)/%.o: %.s
	$(AS) -c $< -o $@ -march=rv32ima -mabi=ilp32

$(OUT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(OPTIMIZE) -c $< -o $@
	$(OBJDUMP) -DSxtd $@ > $@.asm

clean:
	rm -rf $(OBJ) $(OUT_DIR)/*

