`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/29 22:19:47
// Design Name: 
// Module Name: DataCompare4
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


module DataCompare8(
    input [7:0] iData_a,  // 输入数据 a
    input [7:0] iData_b,  // 输入数据 b
    output reg [2:0] oData // 比较结果
);

    wire [2:0] low_compare;  // 低 4 位比较器的输出
    wire [2:0] high_compare; // 高 4 位比较器的输出

    // 低 4 位数据比较器实例化
    DataCompare4 low_compare_inst(
        .a(iData_a[3:0]),
        .b(iData_b[3:0]),
        .gt(low_compare[2]),
        .eq(low_compare[1]),
        .lt(low_compare[0]),
        .cascade_in_gt(0),
        .cascade_in_eq(0),
        .cascade_in_lt(1)
    );

    // 高 4 位数据比较器实例化，级联低 4 位的输出
    DataCompare4 high_compare_inst(
        .a(iData_a[7:4]),
        .b(iData_b[7:4]),
        .gt(high_compare[2]),
        .eq(high_compare[1]),
        .lt(high_compare[0]),
        .cascade_in_gt(low_compare[2]),
        .cascade_in_eq(low_compare[1]),
        .cascade_in_lt(low_compare[0])
    );

    // 最终输出
    always @(*) begin
        oData = high_compare;
    end
endmodule

// 4位比较器模块
module DataCompare4(
    input [3:0] a,
    input [3:0] b,
    input cascade_in_gt,  // 级联输入
    input cascade_in_eq,
    input cascade_in_lt,
    output reg gt,
    output reg eq,
    output reg lt 
);

    always @(*) begin
        gt = 0;
        eq = 0;
        lt = 0;
        if (a > b) begin
            gt = 1;
            eq = 0;
            lt = 0;
        end else if (a < b) begin
            gt = 0;
            eq = 1;
            lt = 0;
        end else begin
            // 当 a = b 时，级联输入决定输出
            gt = cascade_in_gt;
            eq = cascade_in_eq;
            lt = cascade_in_lt;
        end
    end
endmodule

