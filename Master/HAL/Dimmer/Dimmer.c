
#include <avr/io.h>
#include <util/delay.h>

#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=~(1<<bit)
#define toggelbit(reg,bit) reg^=(1<<bit)
#define readbit(reg,bit) ((reg>>bit)&1)


void Dimmer(unsigned int d)
{
	// IN1 IN4 high	
	DDRC  |= (1<<PC5 ) | (1<<PC6);// IN1 IN0
	PORTC |= (1<<PC5);// IN1 IN4 high
		
	//(COM01 non inverting) cs00 prescaler 1    (wgm01 wgm00 fastpwm)
	TCCR1A = (1<<WGM00) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
	DDRD|=(1<<PD5);// PIN OC0 output Enable1 pwm
	OCR1A=d;// duty
}

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