`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/12 18:25:51
// Design Name: 
// Module Name: Counter8_tb
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


module Counter8_tb;

    reg CLK;
    reg rst_n;
    wire [2:0] oQ;
    wire [6:0] oDisplay;

    // ʵ����������ģ��
    Counter8 uut (
        .CLK(CLK),
        .rst_n(rst_n),
        .oQ(oQ),
        .oDisplay(oDisplay)
    );

    // ʱ������
    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK; // 10ns����
    end

    // �����߼�
    initial begin
        rst_n = 0; // ��ʼ��λ
        #20 rst_n = 1; // �ͷŸ�λ
        #200 $stop; // ֹͣ����
    end

endmodule

