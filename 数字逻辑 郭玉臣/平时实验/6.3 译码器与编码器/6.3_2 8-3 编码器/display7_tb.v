`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/14 00:37:50
// Design Name: 
// Module Name: display7_tb
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

module display7_tb;

reg [3:0] iData;     // 测试输入
wire [6:0] oData;    // 测试输出

// 实例化七段数码管译码器模块
display7 uut (
    .iData(iData),
    .oData(oData)
);

// 测试过程
initial begin
    // 测试每个输入组合
    $monitor("iData=%b, oData=%b", iData, oData);
    
    // 测试0到9的输入
    for (iData = 0; iData < 10; iData = iData + 1) begin
        #10; // 每个测试之间延迟10个时间单位
    end
    
    // 测试无效输入
    iData = 4'b1111; // 默认情况下
    #10;

    $finish; // 结束仿真
end

endmodule
