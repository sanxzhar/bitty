import "DPI-C" function void compare_results(
    input bit [15:0] instruction,
    input bit [15:0] reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7
);

module bitty_monitor (
    input wire             clk,
    input wire             done,
    input wire [15:0]      instruction,
    input wire [15:0]      reg0,
    input wire [15:0]      reg1,
    input wire [15:0]      reg2,
    input wire [15:0]      reg3,
    input wire [15:0]      reg4,
    input wire [15:0]      reg5,
    input wire [15:0]      reg6,
    input wire [15:0]      reg7
);  

    reg                    en_dpi;

    always @(posedge clk) begin
        if(done) begin
            en_dpi <= 0'b1;
        end else begin
            en_dpi <= 0'b0;
        end
    end

    always @(posedge en_dpi) begin
        compare_results(
            instruction,
            reg0, reg1, reg2, reg3,
            reg4, reg5, reg6, reg7
        );
    end

endmodule
