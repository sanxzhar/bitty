module instr_fetch_unit(
    input  wire             clk,
    input  wire             reset,
    input  wire             done,
    output wire [15:0]      instr 
);

    wire [7:0] d_in;
    wire [7:0] d_out;
    wire [15:0] memory_out;

    reg [15:0] instr_reg;
    assign instr = instr_reg;

    top_register PC(
        .clk(clk),
        .reset(reset),
        .en_i(done),
        .d_in(d_in),
        .d_out(d_out)
    );

    assign d_in = d_out + 8'd1;

    memory Memory(
        .clk(clk),
        .addr(d_out),
        .out(memory_out)
    );

    always @(posedge clk or posedge reset) begin
        if (reset)
            instr_reg <= 16'b0;
        else
            instr_reg <= memory_out;
    end

endmodule
