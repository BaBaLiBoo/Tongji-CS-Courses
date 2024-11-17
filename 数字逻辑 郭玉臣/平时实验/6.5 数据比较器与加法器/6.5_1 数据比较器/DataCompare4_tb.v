`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/29 22:20:57
// Design Name: 
// Module Name: DataCompare4_tb
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

module DataCompare4_tb;

reg [3:0] iData_a;
reg [3:0] iData_b;
reg [2:0] iData;
wire [2:0] oData;

// 实例化被测试模块
DataCompare4 uut (
    .iData_a(iData_a),
    .iData_b(iData_b),
    .iData(iData),
    .oData(oData)
);

initial begin
    // 测试用例
    iData_a = 4'b0001; iData_b = 4'b0000; #10; // A > B
    iData_a = 4'b0000; iData_b = 4'b0001; #10; // A < B
    iData_a = 4'b0001; iData_b = 4'b0001; iData = 3'b001; #10; // A = B
    $finish;
end

initial begin
    $monitor("Time: %0t | A: %b | B: %b | oData: %b", $time, iData_a, iData_b, oData);
end

endmodule


