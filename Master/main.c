//Master
#define F_CPU 16000000ul
#include <avr/io.h>
#include <avr/interrupt.h> // header interrupt
#include <util/delay.h>
#include "keypad.h"

#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=~(1<<bit)
#define toggelbit(reg,bit) reg^=(1<<bit)
#define readbit(reg,bit) ((reg>>bit)&1)

void LCD_send_command(unsigned char cmd);
void LCD_send_data(unsigned char data);
void LCD_INIT(void);
void LCD_send_string( char str[]);
void LCD_send_data_4bit(unsigned char data);
void LCD_send_command_4bit(unsigned char cmd);
void LCD_INIT_4bit(void);
void LCD_send_string_4bit( char* str);
void Int_ASC(int ab);
void motor_start(void);
void motor_stop(void);
void ADC_init();
int ADC_read(int ADC_chanel);
void UART_INIT(unsigned int baud);
void UART_sendchar(unsigned char data);
unsigned char UART_receivechar();
void UART_sendString(char *str);
void Servo(unsigned int d);
void Dimmer(unsigned int d);
void int1_init();   // INT1
void int0_init();   // INT0
void Bulb_on(int a);
void Bulb_off(int a);
void SPI_Init();
void SPI_Write(char data);
char SPI_Read();
void LCD_Next_Line(void);
void LCD_Shift_Right(void);
void LCD_Shift_Left(void);
void LCD_Clear(void);
void LCD_Home(void);
void Timer1_init();
void Timer1_start();
void Timer1_set_freq(int frequency);
void Timer1_set_direction(int angle);
void Servo_init(void);
void Servo_open(void);
void Servo_close(void);
void Buzzer(void);
unsigned char get_answer(void);
void menu(void);


int main(void)
{
	_delay_ms(500);
	LCD_INIT_4bit();    // init lcd
	keypad_init();      // define key pad   //1//
	UART_INIT(103);
	SPI_Init();

	LCD_send_string_4bit("Smart Home Proj.");
	_delay_ms(1000);
	LCD_Clear();
	LCD_Home();
	menu();	
}