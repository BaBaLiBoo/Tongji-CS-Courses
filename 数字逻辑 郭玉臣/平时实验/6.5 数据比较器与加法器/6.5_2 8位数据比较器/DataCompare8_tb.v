`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/30 10:15:35
// Design Name: 
// Module Name: DataCompare8_tb
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


module DataCompare8_tb;
    reg [7:0] iData_a;
    reg [7:0] iData_b;
    wire [2:0] oData;

    // 实例化被测试模块
    DataCompare8 uut (
        .iData_a(iData_a),
        .iData_b(iData_b),
        .oData(oData)
    );

    initial begin
        // 测试用例
        iData_a = 8'b00000000; iData_b = 8'b00000000; #10;
        iData_a = 8'b00000000; iData_b = 8'b00001000; #10; 
        iData_a = 8'b00001000; iData_b = 8'b00001000; #10; 
        iData_a = 8'b00001000; iData_b = 8'b00001111; #10; 
        iData_a = 8'b11110000; iData_b = 8'b11110000; #10; 
        iData_a = 8'b11110000; iData_b = 8'b11111111; #10; 
        iData_a = 8'b11111111; iData_b = 8'b11111111; #10; 
        $stop;
    end
endmodule


