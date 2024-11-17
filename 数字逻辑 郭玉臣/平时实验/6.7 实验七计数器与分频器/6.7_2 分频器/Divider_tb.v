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

    reg I_CLK;      // ����ʱ��
    reg rst;        // ͬ����λ�ź�
    wire O_CLK;     // ���ʱ���ź�

    // ʵ���� Divider ģ��
    Divider uut (
        .I_CLK(I_CLK),
        .rst(rst),
        .O_CLK(O_CLK)
    );

    // ����ʱ���ź�
    always begin
        I_CLK = 0; #5; I_CLK = 1; #5; // ÿ 10ns �л�һ��
    end

    initial begin
        // ��ʼ���ź�
        rst = 1;
        #20; // ��λ�źű���һ��ʱ��
        rst = 0; // �����λ

        // ģ�� 100 ��ʱ������
        #1000;
        $finish; // ��������
    end

    // ��ʾ����
    initial begin
        $dumpfile("divider_tb.vcd");
        $dumpvars(0, Divider_tb);
    end
endmodule


