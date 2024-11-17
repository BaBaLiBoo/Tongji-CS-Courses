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
    reg [3:0] iC0, iC1, iC2, iC3; // �����ź�
    reg iS0, iS1;                  // ѡ���ź�
    wire [3:0] oZ;                 // ����ź�

    // ʵ����ѡ����
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
        // ��������
        iC0 = 4'b0001; // ѡ�� iC0
        iC1 = 4'b0010; // ѡ�� iC1
        iC2 = 4'b0100; // ѡ�� iC2
        iC3 = 4'b1000; // ѡ�� iC3

        // ��������ѡ�����
        iS0 = 0; iS1 = 0; #10; // ������� iC0
        iS0 = 1; iS1 = 0; #10; // ������� iC1
        iS0 = 0; iS1 = 1; #10; // ������� iC2
        iS0 = 1; iS1 = 1; #10; // ������� iC3
        $finish; // ��������
    end
endmodule

