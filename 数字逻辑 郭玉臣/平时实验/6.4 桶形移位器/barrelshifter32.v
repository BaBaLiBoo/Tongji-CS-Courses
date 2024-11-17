module barrelshifter32(
    input [31:0] a, //32 λԭʼ��������
    input [4:0] b, //5 λ�����źţ�������λ��λ��
    input [1:0] aluc, //2 λ�����źţ�������λ�ķ�ʽ
    output reg [31:0] c //32 λ��λ����������
); 
always @(*) begin
    case (aluc)
        2'b00: c = $signed(a) >>> b;   // �������� (sra)
        2'b01: c = a << b;             // �������� (sll)
        2'b10: c = a >> b;             // �߼����� (srl)
        2'b11: c = a << b;             // �߼����� (sll), ��Ϊ����������һ��
        default: c = a;
    endcase
end

endmodule