
#include "soc-hw.h"

char UartBuffer[UART_COMMANDS_BUFFER_SIZE];
uint32_t UartBufferPtr = 0;


char *itoa(uint32_t i, char b[])
{
    char const digit[] = "0123456789";
    char *p = b;
    if (i < 0)
    {
        *p++ = '-';
        i *= -1;
    }
    uint32_t shifter = i;
    do
    { //Move to where representation ends
        ++p;
        shifter = shifter / 10;
    } while (shifter);
    *p = '\0';
    do
    { //Move back, inserting digits as u go
        *--p = digit[i % 10];
        i = i / 10;
    } while (i);
    return b;
}


int main (){

uint32_t i;
uint32_t a;
uint32_t b;
uint32_t lectura=0;
//msleep(5000);
	
msleep(20);

b=0x00FF00;
while(1){

i=read_color();
lectura = read_position();

if(i=10){

 a=0x00FF00;
}

msleep(20);

set_start(2, 0x0000FF);
set_start(6, 0x0000FF);
set_start(10, 0x0000FF);
set_start(14, 0x0000FF);
leds_refresh();
msleep(20);
}
//set_start(lectura, 0x00FF00);
/*
while(1){
msleep(200);
if(read_datos()==1){

		set_start(10,0x00FF00);
		set_start(11,0x00FF00);
		set_start(12,0x00FF00);
		set_start(13,0x00FF00);
		set_start(14,0x00FFFF);
		set_start(15,0x00FFFF);
		set_start(16,0x00FFFF);
		set_start(17,0x00FFFF);
		set_start(18,0x00FFFF);
		set_start(19,0xFF0000);
		set_start(20,0xFF0000);
leds_refresh();
}else{
 		set_start(0,0xFF0000);

		set_start(10,0x0000FF);
		set_start(11,0x0000FF);
		set_start(12,0x0000FF);
		set_start(13,0x0000FF);
		set_start(14,0x0000FF);
		set_start(15,0x0000FF);
		set_start(16,0x0000FF);
		set_start(17,0x0000FF);
		set_start(18,0x0000FF);
		set_start(19,0x0000FF);
		set_start(20,0x0000FF);
leds_refresh();
}
		

		
	//msleep(5000);
}
*/
/*
while(1){
			//brg
		set_start(0,0x00FFFF);
		set_start(1,0x00FFFF);
		set_start(2,0x00FFFF);
		set_start(3,0x00FFFF);
		set_start(4,0x00FFFF);
		set_start(5,0xFF0000);
		set_start(6,0xFF0000);
		set_start(7,0xFF0000);
		set_start(8,0xFF0000);
		set_start(9,0xFF0000);
		set_start(10,0x00FF00);
		set_start(11,0x00FF00);
		set_start(12,0x00FF00);
		set_start(13,0x00FF00);
		set_start(14,0x00FFFF);
		set_start(15,0x00FFFF);
		set_start(16,0x00FFFF);
		set_start(17,0x00FFFF);
		set_start(18,0x00FFFF);
		set_start(19,0xFF0000);
		set_start(20,0xFF0000);
		set_start(21,0xFF0000);
		set_start(22,0xFF0000);
		set_start(23,0xFF0000);
		set_start(24,0x00FF00);
		set_start(25,0x00FF00);
		set_start(26,0x00FF00);
		set_start(27,0x00FF00);
		set_start(28,0x00FFFF);
		set_start(29,0x00FFFF);
		set_start(30,0x00FFFF);
		set_start(31,0x00FFFF);
		set_start(32,0x00FFFF);
		set_start(33,0xFF0000);
		set_start(34,0xFF0000);
		set_start(35,0xFF0000);
		set_start(36,0xFF0000);
		set_start(37,0xFF0000);
		set_start(38,0x00FF00);
		set_start(39,0x00FF00);
		set_start(40,0x00FF00);
		set_start(41,0x00FF00);
		set_start(42,0x00FFFF);
		set_start(43,0x00FFFF);
		set_start(44,0x00FFFF);
		set_start(45,0x00FFFF);
		set_start(46,0x00FFFF);
		set_start(47,0xFF0000);
		set_start(48,0xFF0000);
		set_start(49,0xFF0000);
		set_start(50,0xFF0000);
		set_start(51,0xFF0000);
		set_start(52,0x00FF00);
		set_start(53,0x00FF00);
		set_start(54,0x00FF00);
		set_start(55,0x00FF00);
		set_start(56,0x00FFFF);
		set_start(57,0x00FFFF);
		set_start(58,0x00FFFF);
		set_start(59,0x00FFFF);
		set_start(60,0x00FFFF);
		set_start(61,0xFF0000);
		set_start(62,0xFF0000);
		set_start(63,0xFF0000);
		



		leds_refresh();
		while(leds_finish()==0){
			nsleep(10);
		}
	msleep(5000);


			//brg
		set_start(0,0x0000FF);
		set_start(1,0x0000FF);
		set_start(2,0x0000FF);
		set_start(3,0x0000FF);
		set_start(4,0x0000FF);
		set_start(5,0xFF00FF);
		set_start(6,0xFF00FF);
		set_start(7,0xFF00FF);
		set_start(8,0xFF00FF);
		set_start(9,0xFF00FF);
		set_start(10,0x0F0F0F);
		set_start(11,0x0F0F0F);
		set_start(12,0x0F0F0F);
		set_start(13,0x0F0F0F);
		set_start(14,0x0000FF);
		set_start(15,0x0000FF);
		set_start(16,0x0000FF);
		set_start(17,0x0000FF);
		set_start(18,0x0000FF);
		set_start(19,0x0F0F0F);
		set_start(20,0x0F0F0F);
		set_start(21,0x0F0F0F);
		set_start(22,0x0F0F0F);
		set_start(23,0x0F0F0F);
		set_start(24,0x0000FF);
		set_start(25,0x0000FF);
		set_start(26,0x0000FF);
		set_start(27,0x0000FF);
		set_start(28,0x0000FF);
		set_start(29,0xFF00FF);
		set_start(30,0xFF00FF);
		set_start(31,0xFF00FF);
		set_start(32,0xFF00FF);
		set_start(33,0xFF00FF);
		set_start(34,0x0F0F0F);
		set_start(35,0x0F0F0F);
		set_start(36,0x0F0F0F);
		set_start(37,0x0F0F0F);
		set_start(38,0x0000FF);
		set_start(39,0x0000FF);
		set_start(40,0x0000FF);
		set_start(41,0x0000FF);
		set_start(42,0x0000FF);
		set_start(43,0x0F0F0F);
		set_start(44,0x0F0F0F);
		set_start(45,0x0F0F0F);
		set_start(46,0x0F0F0F);
		set_start(47,0x0F0F0F);
		set_start(48,0x0000FF);
		set_start(49,0x0000FF);
		set_start(50,0x0000FF);
		set_start(51,0x0000FF);
		set_start(52,0x0000FF);
		set_start(53,0xFF00FF);
		set_start(54,0xFF00FF);
		set_start(55,0xFF00FF);
		set_start(56,0xFF00FF);
		set_start(57,0xFF00FF);
		set_start(58,0x0F0F0F);
		set_start(59,0x0F0F0F);
		set_start(60,0x0F0F0F);
		set_start(61,0x0F0F0F);
		set_start(62,0x0000FF);
		set_start(63,0x0000FF);
		



		leds_refresh();

	msleep(5000);


}
*/

		
return(0);
	}


