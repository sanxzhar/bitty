module alu(
    input  wire [15:0]               in_a,
    input  wire [15:0]               in_b,
    input  wire [2:0]                sel,
    output wire [15:0]               out
);

    reg [15:0] temp_out;
    assign out = temp_out;

    always @(*) begin
        case(sel)
            3'b000: temp_out = in_a + in_b;
            3'b001: temp_out = in_a - in_b;
            3'b010: temp_out = in_a & in_b;
            3'b011: temp_out = in_a | in_b;
            3'b100: temp_out = in_a ^ in_b;
            3'b101: temp_out = in_a << (in_b % 16);
            3'b110: temp_out = in_a >> (in_b % 16);
            3'b111: temp_out = (in_a == in_b) ? 16'd0 : ((in_a > in_b) ? 16'd1 : 16'd2);
            default: temp_out = 16'h0000;
        endcase
    end


endmodule
