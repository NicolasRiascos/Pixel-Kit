#include "soc-hw.h"

void all(uint32_t color){

	uint8_t i;
	for(i=0;i<14;i++){
		set_start(i,color);
	}
	leds_refresh();
	while(leds_finish()==0){
		nsleep(100);
		}
}
