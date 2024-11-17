`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/10 22:18:48
// Design Name: 
// Module Name: decoder_tb
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


module decoder_tb;
    reg [2:0] iData;
    reg [1:0] iEna;
    wire [7:0] oData;

    // Instantiate the decoder module
    decoder uut (
        .iData(iData),
        .iEna(iEna),
        .oData(oData)
    );

    initial begin
        // Test when disabled
        iEna = 2'b00; iData = 3'b000;
        #10;
        iEna = 2'b01; iData = 3'b001;
        #10;

        // Enable the decoder and test all inputs
        iEna = 2'b10; // G1 = 1, G2 = 0
        iData = 3'b000;
        #10;
        iData = 3'b001;
        #10;
        iData = 3'b010;
        #10;
        iData = 3'b011;
        #10;
        iData = 3'b100;
        #10;
        iData = 3'b101;
        #10;
        iData = 3'b110;
        #10;
        iData = 3'b111;
        #10;

        // Test with disabled enable signals again
        iEna = 2'b11; iData = 3'b100;
        #10;
        iEna = 2'b00; iData = 3'b010;
        #10;

        $stop;
    end
endmodule

