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
    input [7:0] iData_a,  // �������� a
    input [7:0] iData_b,  // �������� b
    output reg [2:0] oData // �ȽϽ��
);

    wire [2:0] low_compare;  // �� 4 λ�Ƚ��������
    wire [2:0] high_compare; // �� 4 λ�Ƚ��������

    // �� 4 λ���ݱȽ���ʵ����
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

    // �� 4 λ���ݱȽ���ʵ������������ 4 λ�����
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

    // �������
    always @(*) begin
        oData = high_compare;
    end
endmodule

// 4λ�Ƚ���ģ��
module DataCompare4(
    input [3:0] a,
    input [3:0] b,
    input cascade_in_gt,  // ��������
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
            // �� a = b ʱ����������������
            gt = cascade_in_gt;
            eq = cascade_in_eq;
            lt = cascade_in_lt;
        end
    end
endmodule

