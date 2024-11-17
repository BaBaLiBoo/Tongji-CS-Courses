`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/09/20 11:39:15
// Design Name: 
// Module Name: selector41
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


module selector41(
    input [3:0] iC0,
    input [3:0] iC1,
    input [3:0] iC2,
    input [3:0] iC3,
    input iS1,
    input iS0,
    output reg [3:0] oZ
);
    always @(*) begin
        case ({iS1, iS0})
            2'b00: oZ = iC0;
            2'b01: oZ = iC1;
            2'b10: oZ = iC2;
            2'b11: oZ = iC3;
            default: oZ = 4'b0000;
        endcase
    end
endmodule

