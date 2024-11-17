`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/29 22:19:47
// Design Name: 
// Module Name: DataCompare4
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


module DataCompare4(
    input [3:0] iData_a, 
    input [3:0] iData_b,
    input [2:0] iData,
    output reg [2:0] oData 
);

always @(*) begin
    if (iData_a > iData_b) begin
        oData = 3'b100; // A > B
    end else if (iData_a < iData_b) begin
        oData = 3'b010; // A < B
    end else begin
        oData = iData; // A = B, 输出级联输入
    end
end

endmodule
