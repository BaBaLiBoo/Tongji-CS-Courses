`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/10 22:17:58
// Design Name: 
// Module Name: decoder
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


module decoder(
    input [2:0] iData,     // Three-bit input (D2, D1, D0)
    input [1:0] iEna,      // Enable signals (G1, G2)
    output reg [7:0] oData // 8-bit output (Y7~Y0, active low)
);
    always @(*) begin
        if (iEna == 2'b10) begin // G1 = 1, G2 = 0
            case (iData)
                3'b000: oData = 8'b11111110; // Y0 = 0, active low
                3'b001: oData = 8'b11111101; // Y1 = 0
                3'b010: oData = 8'b11111011; // Y2 = 0
                3'b011: oData = 8'b11110111; // Y3 = 0
                3'b100: oData = 8'b11101111; // Y4 = 0
                3'b101: oData = 8'b11011111; // Y5 = 0
                3'b110: oData = 8'b10111111; // Y6 = 0
                3'b111: oData = 8'b01111111; // Y7 = 0
                default: oData = 8'b11111111; // All outputs inactive (high)
            endcase
        end else begin
            oData = 8'b11111111; // If not enabled, all outputs are inactive (high)
        end
    end
endmodule

