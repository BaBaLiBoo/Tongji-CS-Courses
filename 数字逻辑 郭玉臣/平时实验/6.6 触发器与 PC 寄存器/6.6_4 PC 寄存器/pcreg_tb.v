`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/05 21:32:19
// Design Name: 
// Module Name: pcreg_tb
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
`timescale 1ns / 1ps

module pcreg_tb;

    reg clk;
    reg rst;
    reg ena;
    reg [31:0] data_in;
    wire [31:0] data_out;

    pcreg uut (
        .clk(clk),
        .rst(rst),
        .ena(ena),
        .data_in(data_in),
        .data_out(data_out)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        rst = 0;
        ena = 0;
        data_in = 32'hA5A5A5A5;

        #10 rst = 1; 
        #10 rst = 0; 

        #10 ena = 0;
        data_in = 32'h5A5A5A5A;  
        #10;  
        #10 ena = 1;
        #10 data_in = 32'h12345678;
        #10;  

        #10 rst = 1;
        #10 rst = 0;

        #10 $stop;
    end
endmodule

