`timescale 1ns / 1ns
module dram (
    input               clka,
    input       [15:0]  addra,
    input       [31:0]  dina,
    input       [3:0]   wea,
    input               ena,
    output  reg [31:0]  douta
);

/*
模拟ip核生成的dram
时序为同步写，同步读
we为0000时为读
we不为0时为写的掩码，每一位对应一个字节的写掩码

*/
    reg [31:0] mem [0:65535];

// initial begin: init_ram
//     integer i;
//     for(i=0; i<65536; i=i+1) begin
//         // mem[i] = 32'hefefefef;
//         mem[i] = 32'hefefefef;
//     end
// end

    initial begin
        $readmemh("./hex/test_src/dram.hex", mem); // 你的机器码文件
    end

    always @(posedge clka) begin
        if (ena) begin
            douta <= mem[addra];
        end
    end


    wire [31:0] tmp_data;
    assign tmp_data = mem[addra];
    always @(posedge clka) begin
        if (ena) begin
            case (wea)
                //单字节
                4'b0001: mem[addra] <= {tmp_data[31:8], dina[7:0]};
                4'b0010: mem[addra] <= {tmp_data[31:16], dina[15:8], tmp_data[7:0]};
                4'b0100: mem[addra] <= {tmp_data[31:24], dina[23:16], tmp_data[15:0]};
                4'b1000: mem[addra] <= {dina[31:24], tmp_data[23:0]};
                //双字节
                4'b0011: mem[addra] <= {tmp_data[31:16], dina[15:0]};
                //4'b0110: mem[addra] <= {tmp_data[31:24], dina[15:0], tmp_data[7:0]};
                4'b1100: mem[addra] <= {dina[31:16], tmp_data[15:0]};
                //还有其他比如3字节或者双字节的其他情况，但是用不上这里不考虑
                4'b1111: mem[addra] <= dina;
                default: mem[addra] <= tmp_data;
            endcase
        end
    end

endmodule
