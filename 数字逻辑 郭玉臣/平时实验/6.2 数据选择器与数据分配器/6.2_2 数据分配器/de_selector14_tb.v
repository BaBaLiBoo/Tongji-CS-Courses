`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/09/20 14:43:27
// Design Name: 
// Module Name: de_selector14_tb
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

module tb_de_selector14;
   reg iC;
   reg iS1;
   reg iS0;
   wire oZ0;
   wire oZ1;
   wire oZ2;
   wire oZ3;

   de_selector14 uut (
       .iC(iC),
       .iS1(iS1),
       .iS0(iS0),
       .oZ0(oZ0),
       .oZ1(oZ1),
       .oZ2(oZ2),
       .oZ3(oZ3)    
   );
    initial 
    begin
       $monitor("Time: %0t | iC: %b, iS1: %b, iS0: %b | oZ0: %b, oZ1: %b, oZ2: %b, oZ3: %b", 
                $time, iC, iS1, iS0, oZ0, oZ1, oZ2, oZ3);
       iC = 1; iS1 = 0; iS0 = 0; #10; 
       iC = 1; iS1 = 0; iS0 = 1; #10; 
       iC = 1; iS1 = 1; iS0 = 0; #10; 
       iC = 1; iS1 = 1; iS0 = 1; #10; 
       iC = 0; iS1 = 0; iS0 = 0; #10; 
       iC = 0; iS1 = 0; iS0 = 1; #10; 
       iC = 0; iS1 = 1; iS0 = 0; #10;
       iC = 0; iS1 = 1; iS0 = 1; #10; 
       $finish;
   end

endmodule
