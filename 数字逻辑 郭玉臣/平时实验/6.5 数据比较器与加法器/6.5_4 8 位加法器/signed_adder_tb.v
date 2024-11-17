`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/30 16:06:42
// Design Name: 
// Module Name: signed_adder_tb
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


module Adder_tb;
    reg [7:0] a;
    reg [7:0] b;
    reg c_in;
    wire [7:0] sum;
    wire c_out;

    // 实例化有符号加法器
    Adder uut (
        .iData_a(a),
        .iData_b(b),
        .iC(c_in),
        .oData(sum),
        .oData_C(c_out)
    );

    initial begin
        // 测试用例
        a = 8'b00000001;  // 1
        b = 8'b00000001;  // 1
        c_in = 0;
        #10; // 等待10时间单位
        $display("Sum: %b, Carry: %b", sum, c_out);

        a = 8'b11111111;  // -1
        b = 8'b00000001;  // 1
        c_in = 0;
        #10; 
        $display("Sum: %b, Carry: %b", sum, c_out);

        a = 8'b01111111;  // 127
        b = 8'b00000001;  // 1
        c_in = 0;
        #10; 
        $display("Sum: %b, Carry: %b", sum, c_out);

        a = 8'b11111111;  // -1
        b = 8'b11111111;  // -1
        c_in = 0;
        #10; 
        $display("Sum: %b, Carry: %b", sum, c_out);
        
        $finish; // 结束仿真
    end
endmodule
