module mux(
    input  wire [3:0]        sel,
    input  wire [15:0]       reg_0,
    input  wire [15:0]       reg_1,
    input  wire [15:0]       reg_2,
    input  wire [15:0]       reg_3,
    input  wire [15:0]       reg_4,
    input  wire [15:0]       reg_5,
    input  wire [15:0]       reg_6,
    input  wire [15:0]       reg_7,
    input  wire [15:0]       reg_8,
    input  wire [15:0]       reg_9,
    output wire [15:0]       out
);

    reg [15:0] reg_out;
    assign out = reg_out;

    always @(*) begin
        case(sel)
            4'b0000:
                reg_out = reg_0;
            4'b0001:
                reg_out = reg_1;
            4'b0010:
                reg_out = reg_2;
            4'b0011:
                reg_out = reg_3;
            4'b0100:
                reg_out = reg_4;
            4'b0101:
                reg_out = reg_5;
            4'b0110:
                reg_out = reg_6;
            4'b0111:
                reg_out = reg_7;
            4'b1000:
                reg_out = reg_8;
            4'b1001:
                reg_out = reg_9;
            default:
                reg_out = 16'b0;
        endcase
    end

endmodule

