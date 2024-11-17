`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/30 15:37:21
// Design Name: 
// Module Name: Adder
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

module FA(
    input iA,    // 1 位二进制加数
    input iB,    // 1 位二进制被加数
    input iC,    // 低位的进位信号
    output oS,   // 1 位和数
    output oC    // 向高位的进位信号
);
    assign oS = iA ^ iB ^ iC;      // 和数
    assign oC = (iA & iB) | (iC & (iA ^ iB)); // 进位信号
endmodule

module Adder(
    input [7:0] iData_a,  // 8 位二进制加数
    input [7:0] iData_b,  // 8 位二进制被加数
    input iC,             // 低位的进位信号
    output [7:0] oData,   // 8 位和数
    output oData_C        // 向高位的进位信号
);
    wire [7:0] carry;     // 中间进位信号

    FA FA0(iData_a[0], iData_b[0], iC, oData[0], carry[0]);
    FA FA1(iData_a[1], iData_b[1], carry[0], oData[1], carry[1]);
    FA FA2(iData_a[2], iData_b[2], carry[1], oData[2], carry[2]);
    FA FA3(iData_a[3], iData_b[3], carry[2], oData[3], carry[3]);
    FA FA4(iData_a[4], iData_b[4], carry[3], oData[4], carry[4]);
    FA FA5(iData_a[5], iData_b[5], carry[4], oData[5], carry[5]);
    FA FA6(iData_a[6], iData_b[6], carry[5], oData[6], carry[6]);
    FA FA7(iData_a[7], iData_b[7], carry[6], oData[7], oData_C);
endmodule
