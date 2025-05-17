module bitty_core (
    input  wire              clk,
    input  wire              reset,
    input  wire              run,
    input  wire [15:0]       instruction,
    output wire              done,
    output wire              en_memory_inst,
    output wire              en_memory_write,
    output wire [15:0]       last_alu_result,
    output wire [15:0]       memory_addr,
    output wire [15:0]       data_to_memory
);

    wire                     en_s;
    wire                     en_c;
    wire                     en_0;
    wire                     en_1;
    wire                     en_2;
    wire                     en_3;
    wire                     en_4;
    wire                     en_5;
    wire                     en_6;
    wire                     en_7;
    wire                     en_i;

    wire [15:0]              reg_inst_to_control_unit;
    wire [2:0]               control_unit_to_alu_sel;
    wire [3:0]               control_unit_to_mux_sel;
    wire [15:0]              control_unit_to_mux_imm_val;

    wire [15:0]              reg_c_to_regs;
    wire [15:0]              reg0_to_mux;
    wire [15:0]              reg1_to_mux;
    wire [15:0]              reg2_to_mux;
    wire [15:0]              reg3_to_mux;
    wire [15:0]              reg4_to_mux;
    wire [15:0]              reg5_to_mux;
    wire [15:0]              reg6_to_mux;
    wire [15:0]              reg7_to_mux;
    wire [15:0]              mux_out;

    wire [15:0]              reg_s_to_alu;
    wire [15:0]              mux_to_reg_c;
    wire [15:0]              alu_to_reg_c_mux;

    assign last_alu_result = reg_c_to_regs;
    assign memory_addr     = reg_s_to_alu;
    assign data_to_memory  = mux_out;

    register RegInst(
        .clk(clk),
        .reset(reset),
        .en_i(en_i),
        .d_in(instruction),
        .d_out(reg_inst_to_control_unit)
    );

    register Reg0(
        .clk(clk),
        .reset(reset),
        .en_i(en_0),
        .d_in(reg_c_to_regs),
        .d_out(reg0_to_mux)
    );

    register Reg1(
        .clk(clk),
        .reset(reset),
        .en_i(en_1),
        .d_in(reg_c_to_regs),
        .d_out(reg1_to_mux)
    );

    register Reg2(
        .clk(clk),
        .reset(reset),
        .en_i(en_2),
        .d_in(reg_c_to_regs),
        .d_out(reg2_to_mux)
    );

    register Reg3(
        .clk(clk),
        .reset(reset),
        .en_i(en_3),
        .d_in(reg_c_to_regs),
        .d_out(reg3_to_mux)
    );

    register Reg4(
        .clk(clk),
        .reset(reset),
        .en_i(en_4),
        .d_in(reg_c_to_regs),
        .d_out(reg4_to_mux)
    );

    register Reg5(
        .clk(clk),
        .reset(reset),
        .en_i(en_5),
        .d_in(reg_c_to_regs),
        .d_out(reg5_to_mux)
    );

    register Reg6(
        .clk(clk),
        .reset(reset),
        .en_i(en_6),
        .d_in(reg_c_to_regs),
        .d_out(reg6_to_mux)
    );

    register Reg7(
        .clk(clk),
        .reset(reset),
        .en_i(en_7),
        .d_in(reg_c_to_regs),
        .d_out(reg7_to_mux)
    );

    control_unit ControlUnit(
        .clk(clk),
        .reset(reset),
        .run(run),
        .d_in(reg_inst_to_control_unit),
        .done(done),
        .en_s(en_s),
        .en_c(en_c),
        .en_0(en_0),
        .en_1(en_1),
        .en_2(en_2),
        .en_3(en_3),
        .en_4(en_4),
        .en_5(en_5),
        .en_6(en_6),
        .en_7(en_7),
        .en_i(en_i),
        .en_memory_inst(en_memory_inst),
        .en_memory_write(en_memory_write),
        .alu_sel(control_unit_to_alu_sel),
        .mux_sel(control_unit_to_mux_sel),
        .imm_val(control_unit_to_mux_imm_val)
    );

    mux Mux(
        .sel(control_unit_to_mux_sel),
        .reg_0(reg0_to_mux),
        .reg_1(reg1_to_mux),
        .reg_2(reg2_to_mux),
        .reg_3(reg3_to_mux),
        .reg_4(reg4_to_mux),
        .reg_5(reg5_to_mux),
        .reg_6(reg6_to_mux),
        .reg_7(reg7_to_mux),
        .reg_8(control_unit_to_mux_imm_val),
        .reg_9(16'b0),
        .out(mux_out)
    );

    two_to_one_mux MuxRegC(
        .sel(en_memory_inst),
        .reg_0(alu_to_reg_c_mux),
        .reg_1(instruction),
        .out(mux_to_reg_c)
    );

    register RegS(
        .clk(clk),
        .reset(reset),
        .en_i(en_s),
        .d_in(mux_out),
        .d_out(reg_s_to_alu)
    );

    alu Alu(
        .in_a(reg_s_to_alu),
        .in_b(mux_out),
        .sel(control_unit_to_alu_sel),
        .out(alu_to_reg_c_mux)
    );

    register RegC(
        .clk(clk),
        .reset(reset),
        .en_i(en_c),
        .d_in(mux_to_reg_c),
        .d_out(reg_c_to_regs)
    );

    bitty_monitor Monitor(
        .clk(clk),
        .done(done),
        .instruction(reg_inst_to_control_unit),
        .reg0(reg0_to_mux),
        .reg1(reg1_to_mux),
        .reg2(reg2_to_mux),
        .reg3(reg3_to_mux),
        .reg4(reg4_to_mux),
        .reg5(reg5_to_mux),
        .reg6(reg6_to_mux),
        .reg7(reg7_to_mux)
    );

endmodule
