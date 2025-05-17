module memory(
    input  wire             en_write,
    input  wire [15:0]      addr,
    input  wire [15:0]      data_in,
    output wire [15:0]      out
);

    reg [15:0] reg_out;
    assign out = reg_out;

    reg [15:0] memory_cell [0:65535];

    initial begin
        $readmemh("/Users/sanzhar/coding/mdv/bitty/testing_tools/generator/program.txt", memory_cell);
    end
    
    always @(*) begin
        reg_out = memory_cell[addr];
    end

    always @(*) begin
        if(en_write)
            memory_cell[addr] = data_in;
    end

endmodule
