`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/30 15:43:20
// Design Name: 
// Module Name: Adder_tb
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


module Adder_tb;
    reg [7:0] iData_a;
    reg [7:0] iData_b;
    reg iC;
    wire [7:0] oData;
    wire oData_C;
    Adder uut (
        .iData_a(iData_a),
        .iData_b(iData_b),
        .iC(iC),
        .oData(oData),
        .oData_C(oData_C)
    );

    initial begin
        // 初始化信号
        iData_a = 8'b00001111;
        iData_b = 8'b00000001;
        iC = 0;

        #10; // 等待一段时间以观察结果
        $display("A: %b, B: %b, C: %b => Sum: %b, Carry: %b", iData_a, iData_b, iC, oData, oData_C);

        // 其他测试用例
        iData_a = 8'b11111111;
        iData_b = 8'b00000001;
        iC = 0;

        #10;
        $display("A: %b, B: %b, C: %b => Sum: %b, Carry: %b", iData_a, iData_b, iC, oData, oData_C);

        $finish; // 结束仿真
    end
endmodule

