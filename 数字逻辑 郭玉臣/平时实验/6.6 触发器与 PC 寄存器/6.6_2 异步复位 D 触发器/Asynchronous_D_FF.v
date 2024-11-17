`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/05 19:35:30
// Design Name: 
// Module Name: Asynchronous_D_FF
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


module Asynchronous_D_FF(
    input CLK,      // ʱ���źţ���������Ч
    input D,        // �����ź� D
    input RST_n,    // ��λ�źţ��͵�ƽ��Ч
    output reg Q1,  // ����ź� Q
    output reg Q2   // ����ź� Q?
);

always @(posedge CLK or negedge RST_n) begin
    if (!RST_n) begin
        Q1 <= 0;   // ��λ״̬
        Q2 <= 1;
    end else begin
        Q1 <= D;   // ��λ״̬
        Q2 <= ~D;
    end
end

endmodule
