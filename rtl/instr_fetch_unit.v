module instr_fetch_unit(
    input  wire             clk,
    input  wire             reset,
    input  wire             done,
    input  wire             run,
    input  wire [15:0]      last_alu_result,
    output wire             run_core,
    output wire [15:0]      instr
);
    wire                    en_pc;
    wire [7:0]              updated_pc;
    wire [7:0]              current_pc;
    wire [15:0]             memory_out;

    reg  [15:0]             instr_reg;

    assign instr          = instr_reg;

    top_register PC(
        .clk(clk),
        .reset(reset),
        .en_i(en_pc),
        .d_in(updated_pc),
        .d_out(current_pc)
    );

    branch_logic BranchLogic(
        .instruction_from_memory(memory_out),
        .current_pc(current_pc),
        .last_alu_result(last_alu_result),
        .instr_done(done),
        .run(run),
        .updated_pc(updated_pc),
        .en_pc(en_pc),
        .run_core(run_core)
    );

    memory Memory(
        .addr(current_pc),
        .out(memory_out)
    );

    always @(*) begin
        if (reset)
            instr_reg = 16'b0;
        else
            instr_reg = memory_out;
    end

endmodule
