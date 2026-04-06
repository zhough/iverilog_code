module irom (
    input  [12:0] a,
    output [31:0] spo
);

reg [31:0] mem [0:8192]; // 1024 条指令

// 仿真时自动加载 hex 文件
initial begin
    $readmemh("./hex/irom.hex", mem); // 你的机器码文件
end

// 0 延迟，组合逻辑读出
assign spo = mem[a];

endmodule