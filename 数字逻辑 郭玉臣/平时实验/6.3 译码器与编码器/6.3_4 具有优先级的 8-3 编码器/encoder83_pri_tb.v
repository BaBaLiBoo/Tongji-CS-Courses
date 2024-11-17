`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/22 11:40:36
// Design Name: 
// Module Name: encoder83_pri_tb
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


// encoder83_Pri_tb.v
`timescale 1ns / 1ps

module encoder83_Pri_tb;
    reg [7:0] iData;  
    reg iEI;          
    wire [2:0] oData;
    wire oEO;        


    encoder83_Pri uut (
        .iData(iData),
        .iEI(iEI),
        .oData(oData),
        .oEO(oEO)
    );

    initial begin

        iEI = 1; iData = 8'b11111110; #10;
        $display("oData=%b, oEO=%b", oData, oEO); 

        iEI = 0; iData = 8'b11111110; #10;
        $display("oData=%b, oEO=%b", oData, oEO);

        iData = 8'b11110110; #10;
        $display("oData=%b, oEO=%b", oData, oEO);

        iData = 8'b11111111; #10;
        $display("oData=%b, oEO=%b", oData, oEO);
        $finish;
    end
endmodule

