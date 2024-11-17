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
        // ��ʼ���ź�
        iData_a = 8'b00001111;
        iData_b = 8'b00000001;
        iC = 0;

        #10; // �ȴ�һ��ʱ���Թ۲���
        $display("A: %b, B: %b, C: %b => Sum: %b, Carry: %b", iData_a, iData_b, iC, oData, oData_C);

        // ������������
        iData_a = 8'b11111111;
        iData_b = 8'b00000001;
        iC = 0;

        #10;
        $display("A: %b, B: %b, C: %b => Sum: %b, Carry: %b", iData_a, iData_b, iC, oData, oData_C);

        $finish; // ��������
    end
endmodule

