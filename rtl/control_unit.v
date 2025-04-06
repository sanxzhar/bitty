module control_unit(
    input  wire             clk,
    input  wire             reset,
    input  wire             run,
    input  wire [15:0]      d_in,
    output wire             done,
    output wire             en_s,
    output wire             en_c,
    output wire             en_0,
    output wire             en_1,
    output wire             en_2,
    output wire             en_3,
    output wire             en_4,
    output wire             en_5,
    output wire             en_6,
    output wire             en_7,
    output wire             en_i,
    output wire [2:0]       alu_sel,
    output wire [3:0]       mux_sel,
    output wire [15:0]      imm_val
);

    reg              reg_done;
    reg              reg_en_s;
    reg              reg_en_c;
    reg              reg_en_0;
    reg              reg_en_1;
    reg              reg_en_2;
    reg              reg_en_3;
    reg              reg_en_4;
    reg              reg_en_5;
    reg              reg_en_6;
    reg              reg_en_7;
    reg              reg_en_i;
    reg [2:0]        reg_alu_sel;
    reg [3:0]        reg_mux_sel;
    reg [15:0]       reg_imm_val;

    assign done    = reg_done;
    assign en_s    = reg_en_s;
    assign en_c    = reg_en_c;
    assign en_0    = reg_en_0;
    assign en_1    = reg_en_1;
    assign en_2    = reg_en_2;
    assign en_3    = reg_en_3;
    assign en_4    = reg_en_4;
    assign en_5    = reg_en_5;
    assign en_6    = reg_en_6;
    assign en_7    = reg_en_7;
    assign en_i    = reg_en_i;
    assign alu_sel = reg_alu_sel;
    assign mux_sel = reg_mux_sel;
    assign imm_val = reg_imm_val;

    parameter INITIAL_STATE     = 2'b00;
    parameter LOAD_STATE        = 2'b01;
    parameter CALCULATE_STATE   = 2'b10;
    parameter STORE_STATE       = 2'b11;

    parameter R_TYPE_INST       = 2'b00;
    parameter I_TYPE_INST       = 2'b01;

    reg [1:0] current_state, next_state;

    wire [1:0] inst_format = d_in[1:0];
    wire [2:0] alu_selection = d_in[4:2];
    wire [2:0] first_operand = d_in[15:13];

    // R_TYPE
    wire [2:0] second_operand = d_in[12:10];

    // I_TYPE
    wire [7:0] immediate_val  = d_in[12:5];

    always @(posedge clk or posedge reset) begin
        if(reset)
            current_state <= INITIAL_STATE;
        else if(run) begin
            current_state <= next_state;
        end
    end

    always @(*) begin
        case(current_state)
            INITIAL_STATE:   next_state = LOAD_STATE;
            LOAD_STATE:      next_state = CALCULATE_STATE;
            CALCULATE_STATE: next_state = STORE_STATE;
            STORE_STATE:     next_state = INITIAL_STATE;
            default:         next_state = INITIAL_STATE;
        endcase
    end

    always @(*) begin

        reg_done = 1'b0;
        reg_en_s = 1'b0;
        reg_en_c = 1'b0;
        reg_en_0 = 1'b0;
        reg_en_1 = 1'b0;
        reg_en_2 = 1'b0;
        reg_en_3 = 1'b0;
        reg_en_4 = 1'b0;
        reg_en_5 = 1'b0;
        reg_en_6 = 1'b0;
        reg_en_7 = 1'b0;
        reg_en_i = 1'b0;
        reg_alu_sel = 3'b000;
        reg_mux_sel = 4'b0000;

        if(!reset && run) begin
            case(current_state)
                INITIAL_STATE: begin
                    reg_en_i    = 1'b1;
                end
                LOAD_STATE: begin
                    reg_mux_sel = {1'b0, first_operand};
                    reg_en_s    = 1'b1;
                end
                CALCULATE_STATE: begin
                    case(inst_format)
                        R_TYPE_INST: begin
                            reg_mux_sel = {1'b0, second_operand};
                            reg_en_c    = 1'b1; 
                            reg_alu_sel = alu_selection[2:0];
                        end
                        I_TYPE_INST: begin
                            reg_mux_sel = {4'b1000};
                            reg_imm_val = {{8{immediate_val[7]}}, immediate_val};
                            reg_en_c    = 1'b1;
                            reg_alu_sel = alu_selection[2:0];
                        end
                        default: begin
                            reg_mux_sel = {1'b0, second_operand};
                            reg_en_c    = 1'b1; 
                            reg_alu_sel = alu_selection[2:0];
                        end
                    endcase
                end
                STORE_STATE: begin
                    case(first_operand)
                        3'b000: reg_en_0 = 1'b1;
                        3'b001: reg_en_1 = 1'b1;
                        3'b010: reg_en_2 = 1'b1;
                        3'b011: reg_en_3 = 1'b1;
                        3'b100: reg_en_4 = 1'b1;
                        3'b101: reg_en_5 = 1'b1;
                        3'b110: reg_en_6 = 1'b1;
                        3'b111: reg_en_7 = 1'b1;
                    endcase
                    reg_done = 1'b1;
                end
                default: begin
                    reg_done = 1'b0;
                    reg_en_s = 1'b0;
                    reg_en_c = 1'b0;
                    reg_en_0 = 1'b0;
                    reg_en_1 = 1'b0;
                    reg_en_2 = 1'b0;
                    reg_en_3 = 1'b0;
                    reg_en_4 = 1'b0;
                    reg_en_5 = 1'b0;
                    reg_en_6 = 1'b0;
                    reg_en_7 = 1'b0;
                    reg_en_i = 1'b0;
                    reg_alu_sel = 3'b000;
                    reg_mux_sel = 4'b0000;
                end
            endcase
        end
    end

endmodule
