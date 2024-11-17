`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/05 21:11:27
// Design Name: 
// Module Name: JK_FF_tb
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

`timescale 1ns / 1ps

module JK_FF_tb();
    reg CLK;       // 时钟信号
    reg J;         // J 输入
    reg K;         // K 输入
    reg RST_n;     // 复位信号
    wire Q1;       // 输出 Q
    wire Q2;       // 输出 Q?

    // 实例化 JK 触发器
    JK_FF uut (
        .CLK(CLK),
        .J(J),
        .K(K),
        .RST_n(RST_n),
        .Q1(Q1),
        .Q2(Q2)
    );

    // 时钟信号生成
    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK;  // 10ns 时钟周期
    end

    // 测试向量
    initial begin
        // 初始化
        RST_n = 0; J = 0; K = 0;
        #10 RST_n = 1;

        // 测试保持
        J = 0; K = 0; #10;
        
        // 测试置 0
        J = 0; K = 1; #10;
        
        // 测试置 1
        J = 1; K = 0; #10;
        
        // 测试交替
        J = 1; K = 1; #20;

        // 测试异步复位
        RST_n = 0; #10;
        RST_n = 1; #10;

        $finish;
    end

endmodule

