module encoder83_Pri(
    input [7:0] iData,  // ��λ���� D7~D0���͵�ƽ��Ч
    input iEI,          // ѡͨ���� EI���͵�ƽ��Ч
    output reg [2:0] oData, // ��λ������� Y2~Y0
    output reg oEO     // ��չ��� EO���ߵ�ƽ��Ч
);

always @(*) begin
    if (iEI) begin
        // EI Ϊ�ߵ�ƽʱ�����������ã������Ч
        oData = 3'b111;
        oEO = 1'b1;
    end else begin
        // ���������ź����ȼ����б���
        casez (iData)
            8'b0???????: oData = 3'b111;  // D7 ��Ч
            8'b10??????: oData = 3'b110;  // D6 ��Ч
            8'b110?????: oData = 3'b101;  // D5 ��Ч
            8'b1110????: oData = 3'b100;  // D4 ��Ч
            8'b11110???: oData = 3'b011;  // D3 ��Ч
            8'b111110??: oData = 3'b010;  // D2 ��Ч
            8'b1111110?: oData = 3'b001;  // D1 ��Ч
            8'b11111110: oData = 3'b000;  // D0 ��Ч
            default:     oData = 3'b111;  // ��Ч���
        endcase
        // ��չ��� EO ��ʾ�Ƿ����κ���Ч����
        oEO = (iData != 8'b11111111) ? 1'b1 : 1'b0;
    end
end

endmodule
