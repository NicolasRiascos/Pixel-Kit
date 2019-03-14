#ifndef SPIKEHW_H
#define SPIKEHW_H

#define PROMSTART 0x00000000
#define RAMSTART  0x00000800
#define RAMSIZE   0x600
#define RAMEND    (RAMSTART + RAMSIZE)

#define RAM_START 0x40000000
#define RAM_SIZE  0x06000000

#define FCPU      50000000

#define UART_RXBUFSIZE 32

#ifndef UART_COMMANDS_BUFFER_SIZE
#define UART_COMMANDS_BUFFER_SIZE 100
#endif
#define FINALCHARACTER1 '\r'
#define FINALCHARACTER2 '\n'
#define NULL ((void *)0)
#define UART_RXBUFSIZE 32
/****************************************************************************
 * Types
 */
typedef unsigned int  uint32_t;    // 32 Bit
typedef signed   int   int32_t;    // 32 Bit

typedef unsigned char  uint8_t;    // 8 Bit
typedef signed   char   int8_t;    // 8 Bit
typedef int size_t; //IDK 

/****************************************************************************
 * Interrupt handling
 */
typedef void(*isr_ptr_t)(void);

void     irq_enable();
void     irq_disable();
void     irq_set_mask(uint32_t mask);
uint32_t irq_get_mak();

void     isr_init();
void     isr_register(int irq, isr_ptr_t isr);
void     isr_unregister(int irq);

/****************************************************************************
 * General Stuff
 */
void     halt();
void     jump(uint32_t addr);


/****************************************************************************
 * Timer
 */
#define TIMER_EN     0x08    // Enable Timer
#define TIMER_AR     0x04    // Auto-Reload
#define TIMER_IRQEN  0x02    // IRQ Enable
#define TIMER_TRIG   0x01    // Triggered (reset when writing to TCR)

typedef struct {
    volatile uint32_t tcr0;
    volatile uint32_t compare0;
    volatile uint32_t counter0;
    volatile uint32_t tcr1;
    volatile uint32_t compare1;
    volatile uint32_t counter1;
} timer_t;

void msleep(uint32_t msec);
void nsleep(uint32_t nsec);
void tic_init();


/***************************************************************************
 * UART0
 */
#define UART_DR   0x01                    // RX Data Ready
#define UART_ERR  0x02                    // RX Error
#define UART_BUSY 0x10                    // TX Busy

typedef struct {
   volatile uint32_t ucr;
   volatile uint32_t rxtx;
   volatile uint32_t en;
   volatile uint32_t txbusy;
   volatile uint32_t rxavail;
   volatile uint32_t rxdata;
} uart_t;

void uart_init();
void uart_putchar(char c);
void uart_putstr(char *str);
void uart_putdata(uint8_t data);
char uart_getchar();
uint32_t txbusy(void);
uint32_t rxavail();


/***************************************************************************
 * pwm0
 */

typedef struct {
   volatile uint32_t int1;
   volatile uint32_t stop;
} pwm_t;

void int_move();
void stop_move();

/***************************************************************************
 * I2C0
//---------------------------------------------------------------------------
  ****************************************************************************/

#define I2C_DR	 0x03			//RX Data Ready
#define I2C_BUSY 0x04			//I2C Busy
#define I2C_ERR  0x02			//RX Error

typedef struct {
   volatile uint32_t scr;
   volatile uint32_t i2c_rx_data;
   volatile uint32_t s_address;
   volatile uint32_t s_reg;
   volatile uint32_t tx_data;
   volatile uint32_t start_wr;
   volatile uint32_t start_rd;
} i2c_t;

uint8_t i2c_read(uint8_t slave_addr, uint8_t per_addr);
void i2c_write(uint8_t slave_addr, uint8_t per_addr, uint8_t data);


/***************************************************************************
 * Notas
 */

typedef struct {
   volatile uint32_t freq;
   volatile uint8_t stop;
   volatile uint8_t done;	
   volatile uint8_t mic;
} notas_t;

void set_freq(uint32_t freq0);

uint8_t mic();

/***************************************************************************
 * Leds
 */



typedef struct {
   volatile uint32_t init;        //0x00
   volatile uint32_t done;        //0x04
   volatile uint32_t start_add;   //0x08
   volatile uint32_t data;        //0x0C
   volatile uint32_t rw;	  //0x10
   volatile uint32_t datos;       //0x14
   volatile uint32_t pos_rec;	  //0x18
   volatile uint32_t pl;	  //0x1C
   volatile uint32_t ce;	  //0x20
   volatile uint32_t cp;	  //0x24
   volatile uint32_t iniciar;    //0x28
   volatile uint32_t w_AD;    //0x2C
   volatile uint32_t encoder_a; //0x30
   volatile uint32_t encoder_b; //0x34
   volatile uint32_t color;     //0x38
} leds_t;

void set_start(uint32_t start0, uint32_t data0);
void leds_refresh(void);
uint32_t leds_finish(void);
uint32_t read_position(void);
uint32_t read_color(void);
void set_cero(void);
void set_one(void);
void set_cero_blue(void);
void set_one_blue(void);

/***************************************************************************
 * Pointer to actual components
 */
extern timer_t  *timer0;
extern uart_t   *uart0;  
extern uint32_t *sram0; 
extern i2c_t 	 *i2c0;
extern notas_t  *notas0;
extern leds_t   *leds0; 
extern pwm_t    *pwm0; 

#endif // SPIKEHW_H
