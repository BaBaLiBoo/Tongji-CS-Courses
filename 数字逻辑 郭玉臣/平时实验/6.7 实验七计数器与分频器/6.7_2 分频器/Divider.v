`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/12 19:15:21
// Design Name: 
// Module Name: Divider
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


module Divider(
    input I_CLK,    // 输入时钟信号
    input rst,      // 同步复位信号，高电平有效
    output O_CLK    // 输出时钟，先高电平再低电平
);
    reg [4:0] count;   // 用于分频的计数器，5位计数器可以提供 20 的分频
    reg o_clk_reg = 0; 

    // 设置分频倍数为 20
    parameter DIVIDE_BY = 20;

    always @(posedge I_CLK or posedge rst) begin
        if (rst) begin
            count <= 0;
            o_clk_reg <= 1;  // 复位时初始化为1，确保从高电平开始
        end else if (count == DIVIDE_BY - 1) begin
            count <= 0;
            o_clk_reg <= ~o_clk_reg;  // 每次分频器完成一次计数后反转输出时钟
        end else begin
            count <= count + 1;
        end
    end

    assign O_CLK = o_clk_reg;
endmodule

