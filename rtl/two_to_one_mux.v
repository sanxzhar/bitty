module two_to_one_mux(
    input  wire             sel,
    input  wire [15:0]      reg_0,
    input  wire [15:0]      reg_1,
    output wire [15:0]      out
);

    reg [15:0] reg_out;
    assign out = reg_out;

    always @(*) begin
        case(sel)
            1'b0:       reg_out = reg_0;
            1'b1:       reg_out = reg_1;
            default:    reg_out = 16'b0;
        endcase
    end


endmodule
