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

reg [3:0] iData;     // ��������
wire [6:0] oData;    // �������

// ʵ�����߶������������ģ��
display7 uut (
    .iData(iData),
    .oData(oData)
);

// ���Թ���
initial begin
    // ����ÿ���������
    $monitor("iData=%b, oData=%b", iData, oData);
    
    // ����0��9������
    for (iData = 0; iData < 10; iData = iData + 1) begin
        #10; // ÿ������֮���ӳ�10��ʱ�䵥λ
    end
    
    // ������Ч����
    iData = 4'b1111; // Ĭ�������
    #10;

    $finish; // ��������
end

endmodule
