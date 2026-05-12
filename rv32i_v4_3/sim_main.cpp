#include <stdio.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // 实例化 Verilog 模块
    Vtop* top = new Vtop;

    // 复位
    top->rst = 0;
    top->eval();
    main_time++;
    
    top->rst = 1;
    top->clk = 0;
    top->eval();
    main_time++;

    top->rst = 0;
    top->eval();
    main_time++;


    while (1) {
        top->clk = !top->clk; // 时钟翻转
        top->eval();
        main_time++;

        if ((top->perip_addr >= 0x80200000) && (top->perip_addr < 0x802000FF) && (top->perip_mask != 7)) {
            printf("perip_addr=0x%08x | perip_wdata=0x%08x | perip_rdata=0x%08x | cnt=%d | pred_rate=%f\n",
                    top->perip_addr, top->perip_wdata, top->perip_rdata,
                     top->cnt,((double)top->pred_count / (double)top->branch_count)
            );
        }
    }

    return 0;
}