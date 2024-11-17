`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/12 18:25:51
// Design Name: 
// Module Name: Counter8_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Counter8_tb;

    reg CLK;
    reg rst_n;
    wire [2:0] oQ;
    wire [6:0] oDisplay;

    // 实例化被测试模块
    Counter8 uut (
        .CLK(CLK),
        .rst_n(rst_n),
        .oQ(oQ),
        .oDisplay(oDisplay)
    );

    // 时钟生成
    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK; // 10ns周期
    end

    // 测试逻辑
    initial begin
        rst_n = 0; // 初始复位
        #20 rst_n = 1; // 释放复位
        #200 $stop; // 停止仿真
    end

endmodule

