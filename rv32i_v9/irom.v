`timescale 1ns / 1ns
module irom (
    input  [12:0] a,
    output [31:0] spo
);

reg [31:0] mem [0:4096]; // 1024 条指令

// 仿真时自动加载 hex 文件
initial begin
    $readmemh("./hex/test_src/irom.hex", mem);
    // $readmemh("../rv32i_v3/hex/rv32ui-p-st_ld.hex", mem);
end

// 0 延迟，组合逻辑读出
assign spo = mem[a];

endmodule