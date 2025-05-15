module top(
    input  wire             clk,
    input  wire             reset,
    input  wire             run
);

    wire                    instr_done;
    wire                    run_core;
    wire [15:0]             instr;
    wire [15:0]             last_alu_result;

    bitty_core Core(
        .clk(clk),
        .reset(reset),
        .run(run_core),
        .instruction(instr),
        .done(instr_done),
        .last_alu_result(last_alu_result)
    );

    instr_fetch_unit InstrFetchUnit(
        .clk(clk),
        .reset(reset),
        .done(instr_done),
        .run(run),
        .last_alu_result(last_alu_result),
        .run_core(run_core),
        .instr(instr)
    );

endmodule
