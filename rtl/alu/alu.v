module alu (
    input wire          carry_in,
    input wire [15:0]   in_a,
    input wire [15:0]   in_b,
    input wire [3:0]    select,
    input wire          mode,
    output wire         carry_out,
    output wire         compare,
    output wire [15:0]  alu_out
); 

    reg [15:0]          temp_alu_out;
    wire [15:0]         temp_logic_alu_out;
    wire [15:0]         temp_arithmetic_out;
    reg                 temp_carry_out;
    reg                 temp_arithmetic_carry_out;

    assign alu_out = temp_alu_out;
    assign carry_out = temp_carry_out;

    logicUnit logic_alu(
        .in_a(in_a),
        .in_b(in_b),
        .sel(select),
        .logic_out(temp_logic_alu_out)
    );

    arithmeticUnit arithmetic_alu(
        .carry_in(carry_in),
        .in_a(in_a),
        .in_b(in_b),
        .sel(select),
        .compare(compare),
        .carry_out(temp_arithmetic_carry_out),
        .arithmetic_out(temp_arithmetic_out)
    );

    always @(*) begin
        if(mode) begin
            temp_alu_out = temp_logic_alu_out;
            temp_carry_out = 1'b0;
        end else begin
            temp_alu_out = temp_arithmetic_out;
            temp_carry_out = temp_arithmetic_carry_out;
        end
    end

endmodule
