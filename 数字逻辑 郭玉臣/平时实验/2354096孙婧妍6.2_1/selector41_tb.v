`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/09/20 11:40:45
// Design Name: 
// Module Name: selector41_tb
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


module selector41_tb;
    reg [3:0] iC0, iC1, iC2, iC3; // 输入信号
    reg iS0, iS1;                  // 选择信号
    wire [3:0] oZ;                 // 输出信号

    // 实例化选择器
    selector41 uut (
        .iC0(iC0),
        .iC1(iC1),
        .iC2(iC2),
        .iC3(iC3),
        .iS0(iS0),
        .iS1(iS1),
        .oZ(oZ)
    );

    initial begin
        // 设置输入
        iC0 = 4'b0001; // 选择 iC0
        iC1 = 4'b0010; // 选择 iC1
        iC2 = 4'b0100; // 选择 iC2
        iC3 = 4'b1000; // 选择 iC3

        // 测试所有选择情况
        iS0 = 0; iS1 = 0; #10; // 期望输出 iC0
        iS0 = 1; iS1 = 0; #10; // 期望输出 iC1
        iS0 = 0; iS1 = 1; #10; // 期望输出 iC2
        iS0 = 1; iS1 = 1; #10; // 期望输出 iC3
        $finish; // 结束仿真
    end
endmodule

