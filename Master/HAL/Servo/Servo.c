
#include <avr/io.h>
#include <util/delay.h>

#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=~(1<<bit)
#define toggelbit(reg,bit) reg^=(1<<bit)
#define readbit(reg,bit) ((reg>>bit)&1)


/*void Servo(unsigned int d)
{
	//(COM01 non inverting) cs00 prescaler 1    (wgm01 wgm00 fastpwm)
	TCCR2 = (1<<WGM20) | (1<<WGM21) | (1<<COM21) | (1<<CS00);
	DDRD|=(1<<PD7);// PIN OC0 output Enable1 pwm
	OCR2=d;// duty
}*/

	void Timer1_init()
	{
		//select PWM mode 14
		clearbit(TCCR1A,0);
		setbit(TCCR1A,1);
		setbit(TCCR1B,3);
		setbit(TCCR1B,4);

		//non-inverting
		clearbit(TCCR1A,6);
		setbit(TCCR1A,7);

		//user manual says PD5 and Kit says PD7 so i make the two
		//set OC1A Pin to be output: it has PWM
		setbit(DDRD,5);

		//set OC1A Pin to be output: it has PWM
		setbit(DDRD,7);
	}

	void Timer1_start()
	{
		//select 64 prescaller
		setbit(TCCR1B,0);
		setbit(TCCR1B,1);
		clearbit(TCCR1B,2);
	}

	void Timer1_set_freq(int frequency){
		//setting frequency by setting Period time in ICR
		int period_time = (1/frequency)*1000;    // in milli
		period_time*=1000;                      // in micro
		//period_time = (ICR1+1)*4;
		//(ICR1+1) = period_time / 4;
		ICR1 = (period_time / 4) - 1;
	}

	void Timer1_set_direction(int angle){
		//Ton = (OCR+1)*4u;
		//(OCR+1) = Ton/4;
		//OCR = (Ton/4)-1;
		//OCR = (angle/4)-1;

		//------ 0 degree: Ton = 1.5ms i.e. 1500u (0 degree of servo is 45 degree in reality) --------------------
		switch(angle){
			case 0:   OCR1A = (374);
			break;
			//-------------------- 90 degree: Ton = 2ms i.e. 2000u --------------------
			case 90:   OCR1A = (499);
			break;
			//-------------------- 180 degree: Ton = 1ms i.e. 1000u --------------------
			case 180:   OCR1A = (249);
			break;
		}
	}

void Servo_init(void)
{
	Timer1_init();
	Timer1_set_freq(50);
	Timer1_start();

}

void Servo_open(void)
{Timer1_set_direction(180);}
void Servo_close(void)
{Timer1_set_direction(0);}


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