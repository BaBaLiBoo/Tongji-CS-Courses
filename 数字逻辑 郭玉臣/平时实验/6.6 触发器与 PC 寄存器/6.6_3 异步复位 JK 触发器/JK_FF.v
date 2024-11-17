`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/05 21:10:56
// Design Name: 
// Module Name: JK_FF
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


module JK_FF(
    input CLK,        // 时钟信号，上升沿有效
    input J,          // 输入信号 J
    input K,          // 输入信号 K
    input RST_n,      // 异步复位信号，低电平有效
    output reg Q1,    // 输出信号 Q
    output reg Q2     // 输出信号 Q?
);

always @(posedge CLK or negedge RST_n) begin
    if (!RST_n) begin
        Q1 <= 0;      // 复位时 Q1 设为 0
        Q2 <= 1;      // 复位时 Q2 设为 1
    end else begin
        case ({J, K})
            2'b00: begin  // 保持状态
                Q1 <= Q1;
                Q2 <= Q2;
            end
            2'b01: begin  // 复位
                Q1 <= 0;
                Q2 <= 1;
            end
            2'b10: begin  // 置位
                Q1 <= 1;
                Q2 <= 0;
            end
            2'b11: begin  // 交替
                Q1 <= ~Q1;
                Q2 <= ~Q2;
            end
        endcase
    end
end

endmodule
