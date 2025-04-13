module memory(
    input  wire             clk,
    input  wire [7:0]       addr,
    output wire [15:0]      out
);

    reg [15:0] reg_out;
    assign out = reg_out;

    reg [15:0] memory_cell [0:255];

    initial begin
        $readmemh("/Users/sanzhar/coding/mdv/bitty/testing_tools/generator/program.txt", memory_cell);
    end
    
    always @(posedge clk) begin
        reg_out <= memory_cell[addr];
    end

endmodule
