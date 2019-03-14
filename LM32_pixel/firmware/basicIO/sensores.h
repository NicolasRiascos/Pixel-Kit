#include "soc-hw.h"
/*
uint8_t H_OUT_L;
uint8_t H_OUT_H;
uint8_t H0_T0_OUT_L;
uint8_t H0_T0_OUT_H;
uint8_t H1_T0_OUT_L;
uint8_t H1_T0_OUT_H;
uint8_t H0_rH_x2;
uint8_t H1_rH_x2;

uint32_t H_OUT;
uint32_t H0_T0_OUT;
uint32_t H1_T0_OUT;

uint32_t H;
*/
uint8_t T_OUT_L;
uint8_t T_OUT_H;
uint8_t T0_OUT_L;
uint8_t T0_OUT_H;
uint8_t T1_OUT_L;
uint8_t T1_OUT_H;
uint8_t T0_degC_x8;
uint8_t T1_degC_x8;

uint32_t T_OUT;
uint32_t T0_OUT;
uint32_t T1_OUT;

uint32_t T;

/*
uint32_t sensorHumidity(){
	
    	H_OUT_L = i2c_getdata(0x5F, 0x28); 
  	H_OUT_H = i2c_getdata(0x5F, 0x29);
	H0_T0_OUT_L = i2c_getdata(0x5F, 0x36); 
  	H0_T0_OUT_H = i2c_getdata(0x5F, 0x37);
	H1_T0_OUT_L = i2c_getdata(0x5F, 0x3A); 
  	H1_T0_OUT_H = i2c_getdata(0x5F, 0x3B);
	H0_rH_x2 = i2c_getdata(0x5F, 0x30); 
  	H1_rH_x2 = i2c_getdata(0x5F, 0x31);

	H_OUT = (H_OUT_H*256)+H_OUT_L;
	H0_T0_OUT = (H0_T0_OUT_H*256)+H0_T0_OUT_L;
	H1_T0_OUT = (H1_T0_OUT_H*256)+H1_T0_OUT_L;

	H=(((H1_rH_x2/2)-(H0_rH_x2/2))/(H1_T0_OUT-H0_T0_OUT))*H_OUT;
    		
	return H;		
	
}

*/
uint32_t sensorTemp(){
	
    	T_OUT_L = i2c_getdata(0x5F, 0x2A); 
  	T_OUT_H = i2c_getdata(0x5F, 0x2B);
	T0_OUT_L = i2c_getdata(0x5F, 0x3C); 
  	T0_OUT_H = i2c_getdata(0x5F, 0x3D);
	T1_OUT_L = i2c_getdata(0x5F, 0x3E); 
  	T1_OUT_H = i2c_getdata(0x5F, 0x3F);
	T0_degC_x8 = i2c_getdata(0x5F, 0x32); 
  	T1_degC_x8 = i2c_getdata(0x5F, 0x33);

	T_OUT = (T_OUT_H*256)+T_OUT_L;
	T0_OUT = (T0_OUT_H*256)+T0_OUT_L;
	T1_OUT = (T1_OUT_H*256)+T1_OUT_L;

	T=(((T1_degC_x8/8)-(T0_degC_x8/8))/(T1_OUT-T0_OUT))*T_OUT;
    		
	return T;		
	
}




