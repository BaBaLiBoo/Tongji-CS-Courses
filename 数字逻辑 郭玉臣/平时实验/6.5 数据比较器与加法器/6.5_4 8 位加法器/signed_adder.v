`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/30 16:07:36
// Design Name: 
// Module Name: signed_adder
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


module Adder(
    input [7:0] iData_a,  // 8位有符号加数
    input [7:0] iData_b,  // 8位有符号被加数
    input iC,             // 低位进位信号
    output [7:0] oData,   // 8位和数
    output oData_C        // 向高位的进位信号
);
    wire [8:0] sum;  // 用于存储9位结果（包括进位）

    assign sum = {1'b0, iData_a} + {1'b0, iData_b} + iC; // 计算和

    assign oData = sum[7:0];   // 取低8位作为输出
    assign oData_C = sum[8];   // 取最高位作为进位输出
endmodule

