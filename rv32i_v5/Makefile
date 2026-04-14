TOP = top

all:
	verilator -Wall -Wno-fatal --top-module $(TOP) --cc --exe --trace *.v sim_main.cpp
	make -j -C obj_dir -f V$(TOP).mk V$(TOP)

run:
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir wave.vcd
