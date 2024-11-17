`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/05 21:29:06
// Design Name: 
// Module Name: pcreg
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


module pcreg(
    input clk,              
    input rst,            
    input ena,         
    input [31:0] data_in,   
    output reg [31:0] data_out 
);

    // 异步复位和使能逻辑
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            data_out <= 32'b0;      // 异步复位，高电平时清零寄存器
        end else if (ena) begin
            data_out <= data_in;    // 在使能信号有效时，赋值data_in
        end
    end
endmodule
