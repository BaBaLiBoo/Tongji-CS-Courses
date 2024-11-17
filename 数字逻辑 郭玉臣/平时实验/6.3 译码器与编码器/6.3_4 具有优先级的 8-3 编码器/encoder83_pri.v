module encoder83_Pri(
    input [7:0] iData,  // 八位输入 D7~D0，低电平有效
    input iEI,          // 选通输入 EI，低电平有效
    output reg [2:0] oData, // 三位编码输出 Y2~Y0
    output reg oEO     // 扩展输出 EO，高电平有效
);

always @(*) begin
    if (iEI) begin
        // EI 为高电平时，编码器禁用，输出无效
        oData = 3'b111;
        oEO = 1'b1;
    end else begin
        // 根据输入信号优先级进行编码
        casez (iData)
            8'b0???????: oData = 3'b111;  // D7 有效
            8'b10??????: oData = 3'b110;  // D6 有效
            8'b110?????: oData = 3'b101;  // D5 有效
            8'b1110????: oData = 3'b100;  // D4 有效
            8'b11110???: oData = 3'b011;  // D3 有效
            8'b111110??: oData = 3'b010;  // D2 有效
            8'b1111110?: oData = 3'b001;  // D1 有效
            8'b11111110: oData = 3'b000;  // D0 有效
            default:     oData = 3'b111;  // 无效情况
        endcase
        // 扩展输出 EO 表示是否有任何有效输入
        oEO = (iData != 8'b11111111) ? 1'b1 : 1'b0;
    end
end

endmodule
