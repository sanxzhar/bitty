module rgstr(
    input  wire                  clk,
    input  wire                  reset,
    input  wire                  en_i,
    input  wire [15:0]           d_in,
    output wire [15:0]           d_out
);

    reg [15:0] reg_d_out;
    assign d_out = reg_d_out;

    always @(posedge clk or posedge reset) begin
        if(reset) begin
            reg_d_out <= 16'b0;
        end else begin
            if(en_i) reg_d_out <= d_in;
        end
    end

endmodule
