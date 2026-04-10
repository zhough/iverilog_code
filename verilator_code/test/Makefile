# 工具链
CROSS = riscv32-unknown-elf-
CC = $(CROSS)gcc
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy

# 编译选项：纯 RV32I，裸机，地址从 0 开始
CFLAGS = -march=rv32i -mabi=ilp32 \
         -nostdlib -ffreestanding \
         -Ttext=0x0 -Tdata=0x1000

# 源文件
SRC = start.S test.c

# 默认目标
all: test.hex test.dump

# 1. 编译出 elf
test.elf: $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

# 2. 生成汇编 .dump（你用来对照分析）
test.dump: test.elf
	$(OBJDUMP) -D -S $< > $@

# 3. 生成 Verilog 标准 .hex：一行 8 字符 = 1 条指令
test.hex: test.elf
	$(OBJCOPY) --only-section=.text -O binary $< test.bin
	hexdump -v -e '/4 "%08x\n"' test.bin > $@
	rm test.bin

# 清理
clean:
	rm -f *.elf *.dump *.hex
	rm -rf obj_dir wave.vcd

TOP = top

build:
	verilator -Wall -Wno-fatal --top-module $(TOP) --cc --exe --trace *.v sim_main.cpp
	make -j -C obj_dir -f V$(TOP).mk V$(TOP)

run:
	./obj_dir/V$(TOP)