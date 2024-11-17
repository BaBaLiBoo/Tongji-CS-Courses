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
    reg CLK;       // ʱ���ź�
    reg J;         // J ����
    reg K;         // K ����
    reg RST_n;     // ��λ�ź�
    wire Q1;       // ��� Q
    wire Q2;       // ��� Q?

    // ʵ���� JK ������
    JK_FF uut (
        .CLK(CLK),
        .J(J),
        .K(K),
        .RST_n(RST_n),
        .Q1(Q1),
        .Q2(Q2)
    );

    // ʱ���ź�����
    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK;  // 10ns ʱ������
    end

    // ��������
    initial begin
        // ��ʼ��
        RST_n = 0; J = 0; K = 0;
        #10 RST_n = 1;

        // ���Ա���
        J = 0; K = 0; #10;
        
        // ������ 0
        J = 0; K = 1; #10;
        
        // ������ 1
        J = 1; K = 0; #10;
        
        // ���Խ���
        J = 1; K = 1; #20;

        // �����첽��λ
        RST_n = 0; #10;
        RST_n = 1; #10;

        $finish;
    end

endmodule

