module control_unit(
    input  wire             clk,
    input  wire             reset,
    input  wire             run,
    input  wire [15:0]      d_in,
    output wire             done,
    output wire             mode,
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
    output wire [3:0]       alu_sel,
    output wire [3:0]       mux_sel
);

    reg             reg_done;
    reg             reg_mode;
    reg             reg_en_s;
    reg             reg_en_c;
    reg             reg_en_0;
    reg             reg_en_1;
    reg             reg_en_2;
    reg             reg_en_3;
    reg             reg_en_4;
    reg             reg_en_5;
    reg             reg_en_6;
    reg             reg_en_7;
    reg             reg_en_i;
    reg [3:0]       reg_alu_sel;
    reg [3:0]       reg_mux_sel;

    assign done    = reg_done;
    assign mode    = reg_mode;
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

    parameter INITIAL_STATE     = 2'b00;
    parameter LOAD_STATE        = 2'b01;
    parameter CALCULATE_STATE   = 2'b10;
    parameter STORE_STATE       = 2'b11;

    reg [1:0] current_state = INITIAL_STATE;

    wire alu_mode = d_in[2]; 
    wire [3:0] alu_selection = d_in[6:3];
    wire [2:0] first_operand = d_in[15:13];
    wire [2:0] second_operand = d_in[12:10];
    
    always @(posedge clk or posedge reset) begin
        if(reset)
            current_state <= INITIAL_STATE;
        else if(run) begin
            case(current_state)
                INITIAL_STATE:   current_state <= LOAD_STATE;
                LOAD_STATE:      current_state <= CALCULATE_STATE;
                CALCULATE_STATE: current_state <= STORE_STATE;
                STORE_STATE:     current_state <= INITIAL_STATE;
                default:         current_state <= INITIAL_STATE;
            endcase
        end
    end

    always @(*) begin

        reg_done = 1'b0;
        reg_mode = 1'b0;
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
        reg_alu_sel = 4'b0000;
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
                    reg_mux_sel = {1'b0, second_operand};
                    reg_en_c    = 1'b1; 
                    reg_alu_sel = alu_selection;
                    reg_mode    = alu_mode;
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
                    reg_mode = 1'b0;
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
                    reg_alu_sel = 4'b0000;
                    reg_mux_sel = 4'b0000;
                end
            endcase
        end
    end

endmodule
