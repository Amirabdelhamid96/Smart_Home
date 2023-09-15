
#include <avr/io.h>
#include <util/delay.h>

#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=~(1<<bit)
#define toggelbit(reg,bit) reg^=(1<<bit)
#define readbit(reg,bit) ((reg>>bit)&1)


void motor_start(void)
{
	DDRD  |= (1<<PD3 ) | (1<<PD4);// IN1 IN0
	PORTD |= (1<<PD3);
}

void motor_stop(void)
{
	DDRD  |= (1<<PD3 ) | (1<<PD4);// IN1 IN0
	clearbit(PORTD,3);
	clearbit(PORTD,4);
	
}

/*void motor(unsigned int d,unsigned char r)
{
	// IN1 IN4 high	
	DDRA  |= (1<<PA0 ) | (1<<PA1)| (1<<PA2)| (1<<PA3);// IN1 IN0
	if (r>=1)
	PORTA = (1<<PA1) | (1<<PA3);// IN1 IN4 high
	else
	PORTA = (1<<PA0) | (1<<PA2);             //  IN2 IN3 high
	
	//(COM01 non inverting) cs00 prescaler 1    (wgm01 wgm00 fastpwm)
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);// PIN OC0 output Enable1 pwm
	OCR0=d;// duty
}*/

/*int main(void)
{
   int direction=1;
    LCD_INIT_4bit(); // init lcd 
	int x =0;
	clearbit(DDRA,4);//adc4 input
	setbit(DDRA,7);//led output
	ADC_init();// calling init
			clearbit(DDRD,4);
			clearbit(DDRD,5);
    while (1)
    {
		if(((PIND>>4)&1)==1)
		direction=0;
		if(((PIND>>5)&1)==1)
		direction=1;		
		x =ADC_read(4);//adc_value
		motor(x/4,direction);
	    if (x>511)
	    setbit(PORTA,7);//led on
	    else
	    clearbit(PORTA,7);//led off
		LCD_send_command_4bit(0x02);// return home
		Int_ASC(x);
		//_delay_us(10);
				
    }
}*/