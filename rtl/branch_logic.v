module branch_logic(
    input  wire [15:0]               instruction_from_memory,
    input  wire [7:0]                current_pc,
    input  wire [15:0]               last_alu_result,
    input  wire                      instr_done,
    input  wire                      run,
    output wire [7:0]                updated_pc,
    output wire                      en_pc,
    output wire                      run_core
);

    reg        reg_run_core;
    reg  [7:0] reg_updated_pc;

    wire [1:0] instr_format              = instruction_from_memory[1:0];
    wire [1:0] branch_condition          = instruction_from_memory[3:2];
    wire [7:0] jump_branch_address       = instruction_from_memory[11:4];
    
    // just to avoid warning
    wire [3:0] empty_holder              = instruction_from_memory[15:12];
    wire _unused_holder_used             = |empty_holder;

    assign run_core                      = reg_run_core;
    assign updated_pc                    = reg_updated_pc;
    assign en_pc                         = (instr_done | ~(instr_done | run_core)) & run;

    always @(*) begin
        reg_run_core = (instr_format != 2'b10);
    end

    always @(*) begin
        if(instr_format == 2'b10) begin
            case(branch_condition)
                2'b00: begin
                    if(last_alu_result == 16'd0) begin
                        reg_updated_pc = jump_branch_address;
                    end else begin
                        reg_updated_pc = current_pc + 1;
                    end
                end
                2'b01: begin
                    if(last_alu_result == 16'd1) begin
                        reg_updated_pc = jump_branch_address;
                    end else begin
                        reg_updated_pc = current_pc + 1;
                    end
                end
                2'b10: begin
                    if(last_alu_result == 16'd2) begin
                        reg_updated_pc = jump_branch_address;
                    end else begin
                        reg_updated_pc = current_pc + 1;
                    end
                end
                default: reg_updated_pc = current_pc + 1;
            endcase
        end else begin
            reg_updated_pc = current_pc + 1;
        end
    end

endmodule
