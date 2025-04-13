module top(
    input  wire             clk,
    input  wire             reset,
    input  wire             run
);

    wire                    instr_done;
    wire [15:0]             instr;

    bitty_core Core(
        .clk(clk),
        .reset(reset),
        .run(run),
        .instruction(instr),
        .done(instr_done)
    );

    instr_fetch_unit InstrFetchUnit(
        .clk(clk),
        .reset(reset),
        .done(instr_done),
        .instr(instr)
    );

endmodule
