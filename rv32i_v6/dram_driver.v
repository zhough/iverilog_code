`timescale 1ns / 1ns
module dram_driver (
    input               clk,
    input               rst,
    input       [31:0]  addr,
    input       [31:0]  din,    
    input       [2:0]   mask,
    input               wen,
    output  reg [31:0]  dout
);

    /*
    dram驱动
    mask对应
    mask对应laod_op和store_op
    wen = 1 时为store， wen = 0时为load
    load时douta有一拍延迟，load时应该将wen和offest以及mask打一拍
    */

    wire    [15:0]  addra;
    reg     [3:0]   wea;
    wire    [31:0]  douta;
    wire    [1:0]   offest;
    reg     [31:0]  dina;
    
    assign addra = addr[17:2];
    assign offest = addr[1:0];

    dram u_dram (
        .clka       (clk),
        .addra      (addra),
        .dina       (dina),
        .wea        (wea),
        .ena        (1'b1),
        .douta      (douta)
    );

    always @(*) begin
        //写控制
        if (wen) begin
            case ({offest, mask})
                //单字节
                5'b00000: begin
                     wea = 4'b0001;
                     dina = din;
                end
                5'b01000: begin
                    wea = 4'b0010;
                    dina = {din[23:0], 8'b0};
                end
                5'b10000: begin
                    wea = 4'b0100;
                    dina = {din[15:0], 16'b0};
                end
                5'b11000: begin
                    wea = 4'b1000;
                    dina = {din[7:0], 24'b0};
                end
                //双字节
                5'b00001: begin
                    wea = 4'b0011;
                    dina = din;
                end
                5'b10001: begin
                    wea = 4'b1100;
                    dina = {din[15:0], 16'b0};
                end
                //4字节
                5'b00010: begin
                    wea = 4'b1111;
                    dina = din;
                end
                default: begin
                    wea = 4'b0000;
                    dina = din;
                end
            endcase
        end else begin
            wea = 4'b0000;
        end
    end

    //wen, offest, mask打一拍
    reg     [1:0]   offest_reg;
    reg     [2:0]   mask_reg;
    reg             wen_reg;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mask_reg <= 3'b111;
            offest_reg <= 2'b0;
            wen_reg <= 1'b0;
        end else begin
            mask_reg <= mask;
            offest_reg <= offest;
            wen_reg <= wen;
        end
    end

    reg [31:0]  dout_reg;

    always @(*) begin
        case ({offest_reg, mask_reg})   
        //有符号单字节
        5'b00000: dout_reg = {{24{douta[7]}}, douta[7:0]};
        5'b01000: dout_reg = {{24{douta[15]}}, douta[15:8]};
        5'b10000: dout_reg = {{24{douta[23]}}, douta[23:16]};
        5'b11000: dout_reg = {{24{douta[31]}}, douta[31:24]};
        //无符号单字节
        5'b00100: dout_reg = {24'b0, douta[7:0]};
        5'b01100: dout_reg = {24'b0, douta[15:8]};
        5'b10100: dout_reg = {24'b0, douta[23:16]};
        5'b11100: dout_reg = {24'b0, douta[31:24]};
        //有符号双字节
        5'b00001: dout_reg = {{16{douta[15]}}, douta[15:0]};
        5'b10001: dout_reg = {{16{douta[31]}}, douta[31:16]};
        //无符号双字节
        5'b00101: dout_reg = {16'b0, douta[15:0]};
        5'b10101: dout_reg = {16'b0, douta[31:16]};
        //4字节
        5'b00010: dout_reg = douta;
        default: dout_reg = douta;
        endcase 
    end

    //打一拍
    always (posedge clk or posedge rst) begin
        if (rst) begin
            dout <= 32'b0;
        end else begin
            dout <= dout_reg;
        end
    end 

endmodule