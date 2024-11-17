module barrelshifter32(
    input [31:0] a, //32 位原始输入数据
    input [4:0] b, //5 位输入信号，控制移位的位数
    input [1:0] aluc, //2 位输入信号，控制移位的方式
    output reg [31:0] c //32 位移位后的输出数据
); 
always @(*) begin
    case (aluc)
        2'b00: c = $signed(a) >>> b;   // 算术右移 (sra)
        2'b01: c = a << b;             // 算术左移 (sll)
        2'b10: c = a >> b;             // 逻辑右移 (srl)
        2'b11: c = a << b;             // 逻辑左移 (sll), 行为与算术左移一致
        default: c = a;
    endcase
end

endmodule