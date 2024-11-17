`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/12 18:25:30
// Design Name: 
// Module Name: Counter8
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


module Counter8 (
    input CLK,         // ʱ���źţ���������Ч
    input rst_n,       // �첽��λ�źţ��͵�ƽ��Ч
    output reg [2:0] oQ, // �����Ƽ��������
    output reg [6:0] oDisplay // �߶�������ʾ�����
);

    // �����߼�
    always @(posedge CLK or negedge rst_n) begin
        if (!rst_n)
            oQ <= 3'b000; // �첽��λ����������
        else
            oQ <= (oQ == 3'b111) ? 3'b000 : oQ + 1; // ģ8����
    end

    // �߶���ʾ�������߼���0-7����ʾ��
    always @(*) begin
        case (oQ)
            3'b000: oDisplay = 7'b1000000; // ��ʾ0
            3'b001: oDisplay = 7'b1111001; // ��ʾ1
            3'b010: oDisplay = 7'b0100100; // ��ʾ2
            3'b011: oDisplay = 7'b0110000; // ��ʾ3
            3'b100: oDisplay = 7'b0011001; // ��ʾ4
            3'b101: oDisplay = 7'b0010010; // ��ʾ5
            3'b110: oDisplay = 7'b0000010; // ��ʾ6
            3'b111: oDisplay = 7'b1111000; // ��ʾ7
            default: oDisplay = 7'b1111111; // �������ȫ��
        endcase
    end

endmodule

