`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/12 19:15:21
// Design Name: 
// Module Name: Divider
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


module Divider(
    input I_CLK,    // ����ʱ���ź�
    input rst,      // ͬ����λ�źţ��ߵ�ƽ��Ч
    output O_CLK    // ���ʱ�ӣ��ȸߵ�ƽ�ٵ͵�ƽ
);
    reg [4:0] count;   // ���ڷ�Ƶ�ļ�������5λ�����������ṩ 20 �ķ�Ƶ
    reg o_clk_reg = 0; 

    // ���÷�Ƶ����Ϊ 20
    parameter DIVIDE_BY = 20;

    always @(posedge I_CLK or posedge rst) begin
        if (rst) begin
            count <= 0;
            o_clk_reg <= 1;  // ��λʱ��ʼ��Ϊ1��ȷ���Ӹߵ�ƽ��ʼ
        end else if (count == DIVIDE_BY - 1) begin
            count <= 0;
            o_clk_reg <= ~o_clk_reg;  // ÿ�η�Ƶ�����һ�μ�����ת���ʱ��
        end else begin
            count <= count + 1;
        end
    end

    assign O_CLK = o_clk_reg;
endmodule

