module read_buttons( clk , rst ,  iniciar , datos , finish , position , pl , ce ,cp);

//PL señal de control para guardar de manera asincrona o secuencial - low carga las entradas paralelas
//CE clock enable active low
//CP clock

 input clk;
 input rst;
 input iniciar; 
 input datos;

 output reg finish;
 output reg [5:0] position;
 output reg pl;
 output reg ce;
 output reg cp;
initial begin
  position=5;
end

 parameter READY  = 3'b	000;
 parameter PL0  = 3'b001;
 parameter PL1  = 3'b010;
 parameter ENABLE= 3'b011;
 parameter SHIFT  = 3'b100;
 parameter RESET  = 3'b101;

 parameter RES = 2500; 
 reg [2:0] state;
 reg [15:0] timer;
 reg [4:0] i;
 reg en;
 reg [2:0]count;
 initial begin
  cp = 1;
  pl = 1;
  ce = 1;
  state = READY;
  timer= 0;
  i=3;
  count = 7;
  en = iniciar;
 end

always @(posedge clk) begin
	 if(datos==1)
		position=6;
 	else
		position=7;
 end 

/*

 



 if(i==0)begin
	cp = ~cp;
	i=3;
 end
 else
	i = i-1; 
 end

always @(posedge cp) begin
	    
   
    if (rst) begin
      state = READY;
    end else begin

    case(state)

     READY:begin
  	en = iniciar; 
     if(en)begin
       state = PL0; 
	timer = 84;
       end    
     else
     state = READY;    
        end

     PL0:begin
	if(timer == 0)begin
	   pl=1;
	   timer = 84;
	   state = PL1;
	end
	else begin
	   pl=0;
	   timer= timer-1;
	end
	end

      PL1:begin
	if(timer==0)begin
	   state = SHIFT;
	end
	else begin
	   pl=1;
	   timer= timer-1;
	end
	end
 
     ENABLE:begin
       if(cp==1)begin
	   ce=0;
	    state=SHIFT;
	end	
	else
	  state=ENABLE;
	   
     end

    SHIFT:begin
	if(datos==1)begin
	   position=count;
		if(count==0)
	   	   state=RESET;
	end
	else begin
	   count= count-1;
	end
     end
        
     RESET:begin
      finish=0;
      timer = timer - 1;
      
      if (timer==0)begin
	finish=1;
  	count = 7;  
      	state = READY;
      end
     end

     default: state = READY;
     
   endcase
   end
 end
*/
endmodule
