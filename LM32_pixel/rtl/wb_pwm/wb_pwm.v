//---------------------------------------------------------------------------
//
// Wishbone notas
//
// Register Description:
//
//    
//
//---------------------------------------------------------------------------

module wb_pwm (
   input              clk,
   input              reset,
   // Wishbone interface
   input              wb_stb_i,
   input              wb_cyc_i,
   output             wb_ack_o,
   input              wb_we_i,
   input       [31:0] wb_adr_i,
   input        [3:0] wb_sel_i,
   input       [31:0] wb_dat_i,
   output reg  [31:0] wb_dat_o,
   
   //pwm
   output pwm   


);

//---------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------
reg  ack;

reg int;
reg stop;
assign wb_ack_o = wb_stb_i & wb_cyc_i & ack;
wire wb_rd = wb_stb_i & wb_cyc_i & ~wb_we_i;
wire wb_wr = wb_stb_i & wb_cyc_i &  wb_we_i;

  always @(posedge clk)
  begin
    if (reset) begin
      ack      <= 0;
    end else begin

      // Handle WISHBONE access
      ack    <= 0;

     if (wb_rd & ~ack) begin           // read cycle
       ack <= 1;
      // wb_dat_o <= 0;
     end else if (wb_wr & ~ack ) begin // write cycle
       ack <= 1;
       case (wb_adr_i[7:0])
       'h00: int  <= wb_dat_i[0];
       'h04: stop <= wb_dat_i[0];	
       endcase	
     end
     else ack <= 0;
    end
  end

pwm pwm0 (.clk(clk), .rst(reset), .int(int), .stop(stop), .pwm(pwm));

endmodule
