module bitty_core (
    input  wire              clk,
    input  wire              reset,
    input  wire              run,
    input  wire [15:0]       instraction,
    output wire              done
);

    // input  wire             clk,
    // input  wire             reset,
    // input  wire             run,
    // input  wire [15:0]      d_in,
    // output wire             done,
    // output wire             mode,
    // output wire             en_s,
    // output wire             en_c,
    // output wire             en_0,
    // output wire             en_1,
    // output wire             en_2,
    // output wire             en_3,
    // output wire             en_4,
    // output wire             en_5,
    // output wire             en_6,
    // output wire             en_7,
    // output wire             en_i,
    // output wire [3:0]       alu_sel,
    // output wire [3:0]       mux_sel 

    wire [15:0] inst_d;
    wire [15:0] mux_d;
    wire [15:0] reg_s_d;
    wire [15:0] reg_c_d;
    wire [15:0] reg_0_d;
    wire [15:0] reg_1_d;
    wire [15:0] reg_2_d;
    wire [15:0] reg_3_d;
    wire [15:0] reg_4_d;
    wire [15:0] reg_5_d;
    wire [15:0] reg_6_d;
    wire [15:0] reg_7_d;
    wire [15:0] alu_d;

    wire        en_i;
    wire        en_s;
    wire        en_c;
    wire        en_0;
    wire        en_1;
    wire        en_2;
    wire        en_3;
    wire        en_4;
    wire        en_5;
    wire        en_6;
    wire        en_7;
    wire        alu_mode;
    wire [3:0]  alu_sel;
    wire [3:0]  mux_sel;

    register reg_inst(
        .clk(clk),
        .reset(reset),
        .en_i(en_i),
        .d_in(instraction),
        .d_out(inst_d),
    );

    register reg_s(
        .clk(clk),
        .reset(reset),
        .en_i(en_s),
        .d_in(mux_d),
        .d_out(reg_s_d),
    );

    register reg_c(
        .clk(clk),
        .reset(reset),
        .en_i(en_c),
        .d_in(alu_d),
        .d_out(reg_c_d),
    );

    register reg_0(
        .clk(clk),
        .reset(reset),
        .en_i(en_c),
        .d_in(alu_d),
        .d_out(reg_c_d),
    );

    control_unit cu(
        .clk(clk),
        .reset(reset),
        .run(run),
        .d_in(inst_d),
        .done(done),
        .mode(alu_mode),
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
        .en_i(en_i),
        .alu_sel(alu_sel)
        .mux_sel(mux_sel)
    );

    mux main_mux(
        .sel(mux_sel),
        .reg_0()
    );


endmodule
