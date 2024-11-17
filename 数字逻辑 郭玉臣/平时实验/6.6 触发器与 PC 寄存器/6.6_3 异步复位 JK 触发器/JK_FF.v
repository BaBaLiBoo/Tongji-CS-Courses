`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/05 21:10:56
// Design Name: 
// Module Name: JK_FF
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


module JK_FF(
    input CLK,        // ʱ���źţ���������Ч
    input J,          // �����ź� J
    input K,          // �����ź� K
    input RST_n,      // �첽��λ�źţ��͵�ƽ��Ч
    output reg Q1,    // ����ź� Q
    output reg Q2     // ����ź� Q?
);

always @(posedge CLK or negedge RST_n) begin
    if (!RST_n) begin
        Q1 <= 0;      // ��λʱ Q1 ��Ϊ 0
        Q2 <= 1;      // ��λʱ Q2 ��Ϊ 1
    end else begin
        case ({J, K})
            2'b00: begin  // ����״̬
                Q1 <= Q1;
                Q2 <= Q2;
            end
            2'b01: begin  // ��λ
                Q1 <= 0;
                Q2 <= 1;
            end
            2'b10: begin  // ��λ
                Q1 <= 1;
                Q2 <= 0;
            end
            2'b11: begin  // ����
                Q1 <= ~Q1;
                Q2 <= ~Q2;
            end
        endcase
    end
end

endmodule
