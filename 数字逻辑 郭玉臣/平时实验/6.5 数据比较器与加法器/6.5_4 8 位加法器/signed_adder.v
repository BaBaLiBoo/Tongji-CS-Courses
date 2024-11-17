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
    input [7:0] iData_a,  // 8λ�з��ż���
    input [7:0] iData_b,  // 8λ�з��ű�����
    input iC,             // ��λ��λ�ź�
    output [7:0] oData,   // 8λ����
    output oData_C        // ���λ�Ľ�λ�ź�
);
    wire [8:0] sum;  // ���ڴ洢9λ�����������λ��

    assign sum = {1'b0, iData_a} + {1'b0, iData_b} + iC; // �����

    assign oData = sum[7:0];   // ȡ��8λ��Ϊ���
    assign oData_C = sum[8];   // ȡ���λ��Ϊ��λ���
endmodule

