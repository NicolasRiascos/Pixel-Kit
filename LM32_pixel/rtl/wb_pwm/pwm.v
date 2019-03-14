module pwm(
	input clk, //Clock
	input rst, //system reset
	input int, //initial
	input stop,
	output reg pwm //Servo signal
	);
	
//parameter freqsys = 50000000; //system freq 	

initial begin
pwm=0;
end

 parameter READY  = 3'b000;
 parameter STOPPING  = 3'b001;
 parameter RIGHT  = 3'b010;
 parameter LEFT  = 3'b011;
 parameter CENTER  = 3'b100;
 
 parameter AR = 52778;
 parameter AL = 50000;
 parameter AC = 51389;
 
 reg [2:0] state;
 reg [31:0] phi; //Angle
 reg [31:0] count=0; //Counter
 reg [31:0] timer=0; //time
 
 initial begin
  state = READY;
  pwm=0;
  end

always @(posedge clk) begin
    
    if (rst) begin
      state = READY;
    end else begin
    case(state)

     READY:begin
	   if(int)begin
          state = STOPPING;
          end
        else
          state = READY;
     end

     STOPPING:	
      if(stop==0)begin
	   phi=AR;
        state = RIGHT;
        timer = 25000000;
        end
      else
        begin  
	   phi=AC;   
        state = CENTER;
        end

     RIGHT: begin
     	if(count<(phi ))begin
		pwm=1'bz;
	end
	else begin
		pwm=0;
	end
	if (count==1000000) begin
		count=0;
		phi=AL;
	end
	else begin
	     	count=count+1;
	     	timer = timer -1;
	     	if (timer==0) begin
	     		timer = 25000000;
	     		state=LEFT;
	     	end 
	     	else	state=RIGHT;
	     	
	     end
     end  

  
     LEFT: begin
     	if(count<(phi ))begin
		pwm=1'bz;
	end
	else begin
		pwm=0;
	end
	if (count==1000000) begin
		count=0;
	end
	else begin
			count=count+1;
			timer = timer -1;
	     	if (timer==0) begin
	     		timer = 25000000;
	     		state=STOPPING;
	     	end 
	     	else	state=LEFT;
	     end
     end 

  
     CENTER: begin
     if(count<(phi ))begin
		pwm=1'bz;
	end
	else begin
		pwm=0;
	end
	if (count==1000000) begin
		count=0;
	end
	else begin
			count=count+1;
	     	timer = timer -1;
	     	if (timer==0) begin
	     		timer = 25000000;
	     		state=READY;
	     	end 
	     	else	state=CENTER;
	     end
     end

     default: state = READY;
     
   endcase
   end
 end




endmodule

