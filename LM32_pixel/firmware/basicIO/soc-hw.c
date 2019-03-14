#include "soc-hw.h"

uart_t     *uart0    = (uart_t *)    0x20000000;
timer_t    *timer0   = (timer_t *)   0x30000000;
pwm_t      *pwm0     = (pwm_t *)     0x40000000;
i2c_t 	 *i2c0	 = (i2c_t *)	  0x50000000;
notas_t    *notas0   = (notas_t *)   0x60000000;
leds_t     *leds0    = (leds_t *)    0x70000000;

isr_ptr_t isr_table[32];

void tic_isr();
/***************************************************************************
 * IRQ handling
 */
void isr_null()
{
}

void irq_handler(uint32_t pending)
{
    int i;

    for(i=0; i<32; i++) {
        if (pending & 0x01) (*isr_table[i])();
        pending >>= 1;
    }
}

void isr_init()
{
    int i;
    for(i=0; i<32; i++)
        isr_table[i] = &isr_null;
}

void isr_register(int irq, isr_ptr_t isr)
{
    isr_table[irq] = isr;
}

void isr_unregister(int irq)
{
    isr_table[irq] = &isr_null;
}

/***************************************************************************
 * TIMER Functions
 */
uint32_t tic_msec;

void msleep(uint32_t msec)
{
    uint32_t tcr;

    // Use timer0.1
    timer0->compare1 = (FCPU/1000)*msec;
    timer0->counter1 = 0;	
    timer0->tcr1 = TIMER_EN;

    do {
        //halt();
         tcr = timer0->tcr1;
     } while ( ! (tcr & TIMER_TRIG) );
}

void nsleep(uint32_t nsec)
{
    uint32_t tcr;

    // Use timer0.1
    timer0->compare1 = (FCPU/1000000)*nsec;
    timer0->counter1 = 0;
    timer0->tcr1 = TIMER_EN;

    do {
        //halt();
         tcr = timer0->tcr1;
     } while ( ! (tcr & TIMER_TRIG) );
}

void tic_isr()
{
    tic_msec++;
    timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;
}

void tic_init()
{
    tic_msec = 0;

    // Setup timer0.0
    timer0->compare0 = (FCPU/10000);
    timer0->counter0 = 0;
    timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;

    isr_register(3, &tic_isr);
}


/***************************************************************************
 * UART Functions
 */

char uart_getchar()
{   
    return uart0->rxdata;
}

void uart_putchar(char c)
{
    uart0->rxtx = c;
    uart0->en =1;
    uart0->en=0; 
    
}

void uart_putstr(char *str)
{
    char *c = str;
    while(*c) {
        uart_putchar(*c);
        while(txbusy()){
        nsleep(1);
        }
        c++;
    }
}

void uart_putdata(uint8_t data){

    uart0->rxtx = data;
    uart0->en =1;
    uart0->en=0; 

}

uint32_t txbusy(void){
	return uart0->txbusy;
}
uint32_t rxavail(){
	return uart0->rxavail;
}
/***************************************************************************
 * I2C Functions
 */

uint8_t i2c_read(uint8_t slave_addr, uint8_t per_addr)
{
		
	while(!(i2c0->scr & I2C_DR));		//Se verifica que el bus esté en espera
	i2c0->s_address = slave_addr;
	i2c0->s_reg 	= per_addr;
	i2c0->start_rd 	= 0x00;
	while(!(i2c0->scr & I2C_DR));
	return i2c0->i2c_rx_data;
	msleep(2);
}

void i2c_write(uint8_t slave_addr, uint8_t per_addr, uint8_t data){
	
	while(!(i2c0->scr & I2C_DR));		//Se verifica que el bus esté en espera
	i2c0->s_address = slave_addr;
	i2c0->s_reg 	= per_addr;
	i2c0->tx_data 	= data;
	i2c0->start_wr 	= 0x00;
	msleep(1);
}

/***************************************************************************
 * Notas Functions
 */

void set_freq(uint32_t freq0)
{
  notas0->stop = 0;
  notas0->freq = freq0;
  msleep(350);
  notas0->stop = 1;
  
}

uint8_t mic()
{
  return notas0->mic;
}

/***************************************************************************
 *Leds
 */

void set_start(uint32_t start0, uint32_t data0)
{ 	
	 leds0->init = 0;
	 leds0->rw = 0;
	 leds0->start_add = start0;
 	 leds0->data = data0;
}
void leds_refresh(void){
  leds0->rw=1;
  leds0->init = 1;
  leds0->init = 0;	
}
uint32_t leds_finish(void){
	return leds0->done;
}
uint32_t read_position(void){
	 
	return  leds0->pos_rec; 
}
uint32_t read_color(void){
	 
	return  leds0->color; 
}

/***************************************************************************
 * PWM Functions
 */
 
void int_move()
{
  pwm0->stop = 0;
  pwm0->int1 = 1;
  pwm0->int1 = 0;
}
              
void stop_move()
{
  pwm0->stop = 1;
}

/***************************************************************************
 * C Functions
 */
/**
 * strstr - Find the first substring in a %NUL terminated string
 * @s1: The string to search for
 * @s2: The string to be searched
 */
 /**
 * memcmp - Compare two areas of memory
 * @cs: One area of memory
 * @ct: Another area of memory
 * @count: The size of the area.
 */
int memcmp(const void *cs, const void *ct, size_t count)
{
    const unsigned char *su1, *su2;
    int res = 0;

    for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
        if ((res = *su1 - *su2) != 0)
            break;
    return res;
}
char *strstr(const char *s1, const char *s2)
{
    size_t l1, l2;

    l2 = strlen(s2);
    if (!l2)
        return (char *)s1;
    l1 = strlen(s1);
    while (l1 >= l2) {
        l1--;
        if (!memcmp(s1, s2, l2))
            return (char *)s1;
        s1++;
    }
    return NULL;
}

/**
 * strlen - Find the length of a string
 * @s: The string to be sized
 */
size_t strlen(const char *s)
{
    const char *sc;

    for (sc = s; *sc != '\0'; ++sc)
        /* nothing */;
    return sc - s;
}
