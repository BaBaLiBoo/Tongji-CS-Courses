`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/22 11:17:23
// Design Name: 
// Module Name: encoder83_tb
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

// encoder83_tb.v
`timescale 1ns / 1ps

module encoder83_tb;
    reg [7:0] iData;  // ģ������
    wire [2:0] oData; // �۲����

    // ʵ����������ģ��
    encoder83 uut (
        .iData(iData),
        .oData(oData)
    );

    initial begin
        // ��ʼ������
        iData = 8'b00000000; #10;
        
        // ����ÿ����������
        iData = 8'b00000001; #10;  // D0 -> 000
        iData = 8'b00000010; #10;  // D1 -> 001
        iData = 8'b00000100; #10;  // D2 -> 010
        iData = 8'b00001000; #10;  // D3 -> 011
        iData = 8'b00010000; #10;  // D4 -> 100
        iData = 8'b00100000; #10;  // D5 -> 101
        iData = 8'b01000000; #10;  // D6 -> 110
        iData = 8'b10000000; #10;  // D7 -> 111
        
        // ��������
        $finish;
    end
endmodule

