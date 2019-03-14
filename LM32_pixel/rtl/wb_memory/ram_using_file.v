module ram_using_file #(             //-- Parametros
         parameter AW = 6,   //-- Bits de las direcciones (Adress width)
         parameter DW = 24)   //-- Bits de los datos (Data witdh)

       (        //-- Puertos
         input clk,                      //-- Señal de reloj global
         input [AW-1: 0] addr_out,      //-- Direcciones
         input wire rw,                  //-- Modo lectura (1) o escritura (0)
         input wire [AW-1: 0] addr_in,
         input wire [DW-1: 0] data_in,   //-- Dato de entrada
         output reg [DW-1: 0] data_out); //-- Dato a escribir

//-- Parametro: Nombre del fichero con el contenido de la RAM
parameter ROMFILE = "memory.ram";

//-- Calcular el numero de posiciones totales de memoria
localparam NPOS = 2 ** AW;

  //-- Memoria
  reg [23: 0] ram [0: 63];
//
always @(posedge clk ) begin
	if (rw) begin
		data_out = ram[addr_out];	
	end
	else begin
		ram[addr_in]=data_in;
	end
end


initial begin
  //$readmemh(ROMFILE, ram);
	ram[0]=24'h000000;
	ram[1]=24'h000000;
	ram[2]=24'h000000;
	ram[3]=24'h000000;
	ram[4]=24'h000000;
	ram[5]=24'h000000;
	ram[6]=24'h000000;
	ram[7]=24'h000000;
	ram[8]=24'h000000;
	ram[9]=24'h000000;
	ram[10]=24'h000000;
	ram[11]=24'h000000;
	ram[12]=24'h000000;
	ram[13]=24'h000000;
	ram[14]=24'h000000;
	ram[15]=24'h000000;
	ram[16]=24'h000000;
	ram[17]=24'h000000;
	ram[18]=24'h000000;
	ram[19]=24'h000000;
	ram[20]=24'h000000;
	ram[21]=24'h000000;
	ram[22]=24'h000000;
	ram[23]=24'h000000;
	ram[24]=24'h000000;
	ram[25]=24'h000000;
	ram[26]=24'h000000;
	ram[27]=24'h000000;
	ram[28]=24'h000000;
	ram[29]=24'h000000;
	ram[30]=24'h000000;
	ram[31]=24'h000000;
	ram[32]=24'h000000;
	ram[33]=24'h000000;
	ram[34]=24'h000000;
	ram[35]=24'h000000;
	ram[36]=24'h000000;
	ram[37]=24'h000000;
	ram[38]=24'h000000;
	ram[39]=24'h000000;
	ram[40]=24'h000000;
	ram[41]=24'h000000;
	ram[42]=24'h000000;
	ram[43]=24'h000000;
	ram[44]=24'h000000;
	ram[45]=24'h000000;
	ram[46]=24'h000000;
	ram[47]=24'h000000;
	ram[48]=24'h000000;
	ram[49]=24'h000000;
	ram[50]=24'h000000;
	ram[61]=24'h000000;
	ram[62]=24'h000000;
	ram[63]=24'h000000;
	
end

endmodule
