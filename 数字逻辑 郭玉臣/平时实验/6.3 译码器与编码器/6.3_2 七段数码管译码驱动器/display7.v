`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/14 00:37:05
// Design Name: 
// Module Name: display7
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


module display7(
    input [3:0] iData,         // 四位输入 D3~D0
    output reg [6:0] oData     // 七段译码输出 g~a
);

always @(*) begin
    case(iData)
        4'b0000: oData = 7'b1000000; // 显示 0
        4'b0001: oData = 7'b1111001; // 显示 1
        4'b0010: oData = 7'b0100100; // 显示 2
        4'b0011: oData = 7'b0110000; // 显示 3
        4'b0100: oData = 7'b0011001; // 显示 4
        4'b0101: oData = 7'b0010010; // 显示 5
        4'b0110: oData = 7'b0000010; // 显示 6
        4'b0111: oData = 7'b1111000; // 显示 7
        4'b1000: oData = 7'b0000000; // 显示 8
        4'b1001: oData = 7'b0010000; // 显示 9
        default: oData = 7'b1111111; // 默认关闭所有段
    endcase
end

endmodule

