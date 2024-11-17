`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/12 19:15:42
// Design Name: 
// Module Name: Divider_tb
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


`timescale 1ns/1ps
module Divider_tb;

    reg I_CLK;      // 输入时钟
    reg rst;        // 同步复位信号
    wire O_CLK;     // 输出时钟信号

    // 实例化 Divider 模块
    Divider uut (
        .I_CLK(I_CLK),
        .rst(rst),
        .O_CLK(O_CLK)
    );

    // 生成时钟信号
    always begin
        I_CLK = 0; #5; I_CLK = 1; #5; // 每 10ns 切换一次
    end

    initial begin
        // 初始化信号
        rst = 1;
        #20; // 复位信号保持一段时间
        rst = 0; // 解除复位

        // 模拟 100 个时钟周期
        #1000;
        $finish; // 结束仿真
    end

    // 显示波形
    initial begin
        $dumpfile("divider_tb.vcd");
        $dumpvars(0, Divider_tb);
    end
endmodule


