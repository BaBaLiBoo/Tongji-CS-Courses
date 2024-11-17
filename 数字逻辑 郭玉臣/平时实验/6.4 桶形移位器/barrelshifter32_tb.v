`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/23 10:49:10
// Design Name: 
// Module Name: barrelshifter32_tb
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

module barrelshifter32_tb;

    // 输入信号声明
    reg [31:0] a;
    reg [4:0] b;
    reg [1:0] aluc;

    // 输出信号
    wire [31:0] c;

    // 实例化桶形移位器模块
    barrelshifter32 uut (
        .a(a),
        .b(b),
        .aluc(aluc),
        .c(c)
    );

    initial begin
        // 打印头信息
        $display("Time\taluc\tb\tInput A\t\tOutput C");
        $monitor("%0dns\t%b\t%d\t%h\t%h", $time, aluc, b, a, c);

        // 初始化信号
        a = 32'hA5A5A5A5; b = 5'd1; aluc = 2'b00; #10; // 算术右移 1位
        a = 32'hA5A5A5A5; b = 5'd4; aluc = 2'b01; #10; // 算术左移 4位
        a = 32'h5A5A5A5A; b = 5'd8; aluc = 2'b10; #10; // 逻辑右移 8位
        a = 32'h5A5A5A5A; b = 5'd2; aluc = 2'b11; #10; // 逻辑左移 2位

        // 结束仿真
        #10;
        $finish;
    end

endmodule


