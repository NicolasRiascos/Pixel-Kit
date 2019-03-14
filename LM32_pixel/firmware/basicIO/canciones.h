///////////////////////////77777
#include "soc-hw.h"

uint32_t i= 0x000FF00 ; 
uint32_t j=  0  ;
#define Do4   95420  
#define Do_4   90253  
#define Re4   85034  
#define Re_4   80385  
#define Mi4   75757  
#define Fa4   71633  
#define Fa_4   67567  
#define Sol4   63777  
#define Sol_4   60241  
#define La4  56818  
#define La_4   53648  
#define Si4   50607  

#define Do5   47801  
#define Do_5   45126  
#define Re5   42589  
#define Re_5   40193  
#define Mi5   37936  
#define Fa5   35816  
#define Fa_5   33783  
#define Sol5   29976  
#define Sol_5   30120  
#define La5  28409  
#define La_5   26824  
#define Si5   25329  


#define SS   1  

void setSound(freq){

		leds_refresh();
		set_freq(freq);
		while(leds_finish()==0){
		nsleep(100);
		}
		set_start(j, i);
		

		if(j==34){
			j=0;
			i=i+0x00000FF;
		}else{
		j=j+1;
		}

		if(i>=0xFFFFFFFF){
			i=i*0x100;
		}else{
		i=i;
		}

}

void ForElise(){

		setSound(Mi5);
		setSound(Re_5);
		setSound(Mi5);		
		setSound(Re_5);
		setSound(Mi5);		
		setSound(Si4);
		setSound(Re5);			
		setSound(Do5);	
		setSound(La4);		

		setSound(SS);		

		setSound(Do4);		
		setSound(Mi4);		
		setSound(La4);		
		setSound(Si4);		

		setSound(SS);		

		setSound(Mi4);		
		setSound(Sol_4);		
		setSound(Si4);		
		setSound(Do5);		

		setSound(SS);		

		setSound(Mi5);
		setSound(Re_5);
		setSound(Mi5);		
		setSound(Re_5);
		setSound(Mi5);		
		setSound(Si4);
		setSound(Re5);			
		setSound(Do5);	
		setSound(La4);		

		setSound(SS);		

		setSound(Do4);		
		setSound(Mi4);		
		setSound(La4);		
		setSound(Si4);		

		setSound(SS);		

		setSound(Mi4);		
		setSound(Do5);		
		setSound(Si4);		
		setSound(La4);		

		setSound(SS);		
/*
		setSound(Mi5);
		setSound(Re_5);
		setSound(Mi5);		
		setSound(Re_5);
		setSound(Mi5);		
		setSound(Si4);
		setSound(Re5);			
		setSound(Do5);	
		setSound(La4);		

		setSound(SS);		

		setSound(Do4);		
		setSound(Mi4);		
		setSound(La4);		
		setSound(Si4);		

		setSound(SS);		

		setSound(Mi4);		
		setSound(Sol_4);		
		setSound(Si4);		
		setSound(Do5);		

		setSound(SS);		

		setSound(Mi5);
		setSound(Re_5);
		setSound(Mi5);		
		setSound(Re_5);
		setSound(Mi5);		
		setSound(Si4);
		setSound(Re5);			
		setSound(Do5);	
		setSound(La4);		

		setSound(SS);		

		setSound(Do4);		
		setSound(Mi4);		
		setSound(La4);		
		setSound(Si4);		

		setSound(SS);		

		setSound(Mi4);		
		setSound(Do5);		
		setSound(Si4);		
		setSound(La4);		

		setSound(SS);		

		setSound(Si4);		
		setSound(Do5);		
		setSound(Re5);		
		setSound(Mi5);		

		setSound(SS);		

		setSound(La4);		
		setSound(Fa5);		
		setSound(Mi5);		
		setSound(Re5);		

		setSound(SS);		

		setSound(Sol4);		
		setSound(Mi5);		
		setSound(Re5);		
		setSound(Do5);		

		setSound(SS);		

		setSound(Fa4);		
		setSound(Re5);		
		setSound(Do5);		
		setSound(Si4);

		setSound(SS);*/
}

void Estrellita(){

		setSound(Do5);
      	setSound(Do5);
		setSound(Sol5);
		setSound(Sol5);
		setSound(La5);
		setSound(La5);
		setSound(Sol5);

		setSound(SS);

		setSound(Fa5);
		setSound(Fa5);
		setSound(Mi5);
		setSound(Mi5);
		setSound(Re5);
		setSound(Re5);
		setSound(Do5);

		setSound(SS);

		setSound(Sol5);
		setSound(Sol5);
		setSound(Fa5);
		setSound(Fa5);
		setSound(Mi5);
		setSound(Mi5);
		setSound(Re5);

		setSound(SS);

		setSound(Sol5);
		setSound(Sol5);
		setSound(Fa5);
		setSound(Fa5);
		setSound(Mi5);
		setSound(Mi5);
		setSound(Re5);

		setSound(SS);

		setSound(Do5);
		setSound(Do5);
		setSound(Sol5);
		setSound(Sol5);
		setSound(La5);
		setSound(La5);
		setSound(Sol5);

		setSound(SS);

		setSound(Fa5);
		setSound(Fa5);
		setSound(Mi5);
		setSound(Mi5);
		setSound(Re5);
		setSound(Re5);
		setSound(Do5);

		setSound(SS);
}

void Lullaby(){

		setSound(Fa_4);
		setSound(Fa_4);
		setSound(La4);

		setSound(SS);

		setSound(Fa_4);
		setSound(Fa_4);
		setSound(La4);

		setSound(SS);

		setSound(Fa_4);
		setSound(La4);
		setSound(Re5);
		setSound(Do_5);
		setSound(Si4);
		setSound(Si4);
		setSound(La4);

		setSound(SS);

		setSound(Mi4);
		setSound(Fa_4);
		setSound(Sol4);
		setSound(Mi4);

		setSound(SS);

		setSound(Mi4);
		setSound(Fa_4);
		setSound(Sol4);

		setSound(SS);

		setSound(Mi4);
		setSound(Sol4);
		setSound(Do_5);
		setSound(Si4);
		setSound(La4);
		setSound(Do_5);
		setSound(Re5);

		setSound(SS);
}

void playlist(uint8_t count){
	switch(count){

		   case 0: ForElise();
			   break;
		   case 1: Estrellita();
			   break;
		   case 2: Lullaby();
			   break;
		}

}





