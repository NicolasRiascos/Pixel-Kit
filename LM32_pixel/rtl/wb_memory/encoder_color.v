module encoder_color ( clk , encoder_a ,  encoder_b , color);

input clk;
input encoder_a;
input encoder_b;
output reg [23:0] color;

initial begin
color=24'hFF0000;
end


endmodule
