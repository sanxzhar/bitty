module arithmeticUnit(
    input wire          carry_in,
    input wire [15:0]   in_a,
    input wire [15:0]   in_b,
    input wire [3:0]    sel,
    output wire         compare,
    output wire         carry_out,
    output wire [15:0]  arithmetic_out 
);

    reg [16:0]  result_with_carry_out;
    reg         temp_compare;

    assign arithmetic_out = result_with_carry_out[15:0];
    assign carry_out = result_with_carry_out[16];
    assign compare = temp_compare;

    always @(*) begin

        if(in_a == in_b)
            temp_compare = 1'b1;
        else
            temp_compare = 1'b0; 

        if(sel == 4'b0000)
            result_with_carry_out = {1'b0, in_a};
        else if(sel == 4'b0001)
            result_with_carry_out = {1'b0, in_a} | {1'b0, in_b};
        else if(sel == 4'b0010)
            result_with_carry_out = {1'b0, in_a} | ~{1'b0, in_b};
        else if(sel == 4'b0011)
            result_with_carry_out = {1'b0, 16'b1111111111111111};
        else if(sel == 4'b0100)
            result_with_carry_out = {1'b0, in_a} | ({1'b0, in_a} & ~{1'b0, in_b});
        else if(sel == 4'b0101)
            result_with_carry_out = ({1'b0, in_a} | {1'b0, in_b}) + ({1'b0, in_a} & ~{1'b0, in_b}) + {16'b0, carry_in};
        else if(sel == 4'b0110)
            result_with_carry_out = {1'b0, in_a} - {1'b0, in_b} + {1'b1, 16'b1111_1111_1111_1111};
        else if(sel == 4'b0111)
            result_with_carry_out = ({1'b0, in_a} & ~{1'b0, in_b}) + {1'b1, 16'b1111_1111_1111_1111};
        else if(sel == 4'b1000)
            result_with_carry_out = {1'b0, in_a} + ({1'b0, in_a} & {1'b0, in_b}) + {16'b0, carry_in};
        else if(sel == 4'b1001)
            result_with_carry_out = {1'b0, in_a} + {1'b0, in_b} + {16'b0, carry_in};
        else if(sel == 4'b1010)
            result_with_carry_out = ({1'b0, in_a} | ~{1'b0, in_b}) + ({1'b0, in_a} & {1'b0, in_b}) + {16'b0, carry_in};
        else if(sel == 4'b1011)
            result_with_carry_out = ({1'b0, in_a} & {1'b0, in_b}) + {1'b1, 16'b1111_1111_1111_1111};
        else if(sel == 4'b1100)
            result_with_carry_out = {1'b0, in_a} + {1'b0, in_a} + {16'b0, carry_in};
        else if(sel == 4'b1101)
            result_with_carry_out = ({1'b0, in_a} | {1'b0, in_b}) + {1'b0, in_a} + {16'b0, carry_in};
        else if(sel == 4'b1110)
            result_with_carry_out = ({1'b0, in_a} | ~{1'b0, in_b}) + {1'b0, in_a} + {16'b0, carry_in};
        else
            result_with_carry_out = {1'b0, in_a} + {1'b1, 16'b1111_1111_1111_1111};

    end
        

endmodule
