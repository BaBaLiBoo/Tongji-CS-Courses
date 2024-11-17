`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/12 18:25:30
// Design Name: 
// Module Name: Counter8
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


module Counter8 (
    input CLK,         // 时钟信号，上升沿有效
    input rst_n,       // 异步复位信号，低电平有效
    output reg [2:0] oQ, // 二进制计数器输出
    output reg [6:0] oDisplay // 七段数字显示管输出
);

    // 计数逻辑
    always @(posedge CLK or negedge rst_n) begin
        if (!rst_n)
            oQ <= 3'b000; // 异步复位，计数清零
        else
            oQ <= (oQ == 3'b111) ? 3'b000 : oQ + 1; // 模8计数
    end

    // 七段显示器译码逻辑（0-7的显示）
    always @(*) begin
        case (oQ)
            3'b000: oDisplay = 7'b1000000; // 显示0
            3'b001: oDisplay = 7'b1111001; // 显示1
            3'b010: oDisplay = 7'b0100100; // 显示2
            3'b011: oDisplay = 7'b0110000; // 显示3
            3'b100: oDisplay = 7'b0011001; // 显示4
            3'b101: oDisplay = 7'b0010010; // 显示5
            3'b110: oDisplay = 7'b0000010; // 显示6
            3'b111: oDisplay = 7'b1111000; // 显示7
            default: oDisplay = 7'b1111111; // 其他情况全灭
        endcase
    end

endmodule

