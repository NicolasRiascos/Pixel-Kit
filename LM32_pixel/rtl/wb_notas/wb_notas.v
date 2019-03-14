//---------------------------------------------------------------------------
//
// Wishbone notas
//
// Register Description:
//
//    0x00 freq
//    0x04 stop
//	 0x008 done
//	0x0C señal de microfono
//---------------------------------------------------------------------------

module wb_notas (
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
   
   //Notas
   output clk_out,
   input mic  


);

//---------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------
reg  ack;
assign mic_intr=mic;
assign wb_ack_o = wb_stb_i & wb_cyc_i & ack;
reg [31:0] freq;
reg stop;
wire done;




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
       case (wb_adr_i[7:0])
       'h05: wb_dat_o  <= {31'h0, done};
       'h06: wb_dat_o  <= {31'h0, mic};
       endcase

      end
	 else if (wb_wr & ~ack ) begin // write cycle
       ack <= 1;
       case (wb_adr_i[7:0])
       'h00: freq  <= wb_dat_i[31:0];
       'h04: stop <= wb_dat_i[0];
       endcase
      end
     else ack <= 0;
    end
  end

Notas notas0(.clk(clk),.freq(freq),.clk_out(clk_out),.stop(stop), .done(done));
endmodule
