module instr_fetch_unit(
    input  wire                     clk,
    input  wire                     reset,
    input  wire                     done,
    input  wire                     run,
    input  wire                     en_memory_inst,
    input  wire                     en_memory_write,
    input  wire [15:0]              last_alu_result,
    input  wire [15:0]              memory_addr,
    input  wire [15:0]              data_to_memory,
    output wire                     run_core,
    output wire [15:0]              instr
);
    wire                            en_pc;
    wire [15:0]                     updated_pc;
    wire [15:0]                     current_pc;
    wire [15:0]                     memory_out;
    wire [15:0]                     mux_to_memory;

    reg  [15:0]                     reg_instr;

    assign instr                  = reg_instr;

    localparam NOP_INSTRUCTION    = 16'b0000000000000000;

    register PC(
        .clk(clk),
        .reset(reset),
        .en_i(en_pc),
        .d_in(updated_pc),
        .d_out(current_pc)
    );

    branch_logic BranchLogic(
        .instruction_from_memory(en_memory_inst ? NOP_INSTRUCTION : memory_out),
        .current_pc(current_pc),
        .last_alu_result(last_alu_result),
        .instr_done(done),
        .run(run),
        .updated_pc(updated_pc),
        .en_pc(en_pc),
        .run_core(run_core)
    );

    two_to_one_mux Mux(
        .sel(en_memory_inst),
        .reg_0(current_pc),
        .reg_1(memory_addr),
        .out(mux_to_memory)
    );

    memory Memory(
        .en_write(en_memory_write),
        .addr(mux_to_memory),
        .data_in(data_to_memory),
        .out(memory_out)
    );

    always @(*) begin
        if (reset)
            reg_instr = 16'b0;
        else
            reg_instr = memory_out;
    end

endmodule
