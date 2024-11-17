`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/05 19:09:53
// Design Name: 
// Module Name: Synchronous_D_FF_tb
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


`timescale 1ns/1ps

module Synchronous_D_FF_tb;

reg CLK;
reg D;
reg RST_n;
wire Q1;
wire Q2;

Synchronous_D_FF uut (
    .CLK(CLK),
    .D(D),
    .RST_n(RST_n),
    .Q1(Q1),
    .Q2(Q2)
);

initial begin
    CLK = 0;
    D = 0;
    RST_n = 0;
    #10 RST_n = 1;
    #10 D = 1;
    #10 D = 0;
    #10 D = 1;
    #10 RST_n = 0;
    #10 RST_n = 1;
    #10 $stop;
end

always #5 CLK = ~CLK;

endmodule

