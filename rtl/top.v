module top(
    input  wire             clk,
    input  wire             reset,
    input  wire             run
);

    wire                    instr_done;
    wire                    run_core;
    wire                    en_memory_inst;
    wire                    en_memory_write;
    wire [15:0]             instr;
    wire [15:0]             last_alu_result;
    wire [15:0]             memory_addr;

    bitty_core Core(
        .clk(clk),
        .reset(reset),
        .run(run_core),
        .instruction(instr),
        .done(instr_done),
        .en_memory_inst(en_memory_inst),
        .last_alu_result(last_alu_result),
        .memory_addr(memory_addr)
    );

    instr_fetch_unit InstrFetchUnit(
        .clk(clk),
        .reset(reset),
        .done(instr_done),
        .run(run),
        .en_memory_inst(en_memory_inst),
        .last_alu_result(last_alu_result),
        .memory_addr(memory_addr),
        .run_core(run_core),
        .instr(instr)
    );

endmodule
