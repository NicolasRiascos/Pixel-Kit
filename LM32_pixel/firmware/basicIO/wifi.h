#include "soc-hw.h"
 
void wifi_init(){
	msleep(5000);
	uart_putstr("AT\r\n");
	msleep(1000);
	uart_putstr("AT+CIPMUX=0\r\n");
	msleep(1000);
	uart_putstr("AT+CIPMODE=1\r\n");
	msleep(1000);
	uart_putstr("AT+CIPSTART=\"TCP\",\"192.168.4.2\",8888\r\n");
	msleep(1000);
	uart_putstr("AT+CIPSEND\r\n");
	msleep(1000);
}
