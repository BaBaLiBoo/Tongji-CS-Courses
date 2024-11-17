`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/22 11:16:57
// Design Name: 
// Module Name: encoder83
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


// encoder83.v
module encoder83(
    input  [7:0] iData,  // 八位输入 D7~D0, 高电平有效
    output reg [2:0] oData  // 三位输出 Y2~Y0
);

always @(*) begin
    case (iData)
        8'b00000001: oData = 3'b000;  // D0 高电平
        8'b00000010: oData = 3'b001;  // D1 高电平
        8'b00000100: oData = 3'b010;  // D2 高电平
        8'b00001000: oData = 3'b011;  // D3 高电平
        8'b00010000: oData = 3'b100;  // D4 高电平
        8'b00100000: oData = 3'b101;  // D5 高电平
        8'b01000000: oData = 3'b110;  // D6 高电平
        8'b10000000: oData = 3'b111;  // D7 高电平
        default:     oData = 3'bxxx;  // 非法输入处理
    endcase
end

endmodule
