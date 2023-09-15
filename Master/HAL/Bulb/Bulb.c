
#include <avr/io.h>
#include <util/delay.h>

#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=~(1<<bit)
#define toggelbit(reg,bit) reg^=(1<<bit)
#define readbit(reg,bit) ((reg>>bit)&1)


void Bulb_on(int a)
{
		if(a==1)
		{
		setbit(DDRA,7);
		setbit(PORTA,7);	
		}
		if(a==2)
		{
			setbit(DDRB,0);
			setbit(PORTB,0);
		}
		if(a==3)
		{
			setbit(DDRB,1);
			setbit(PORTB,1);
		}
		if(a==4)
		{
			setbit(DDRB,2);
			setbit(PORTB,2);
		}
		if(a==5)
		{
			setbit(DDRB,3);
			setbit(PORTB,3);
		}
}

void Bulb_off(int a)
{
		if(a==1)
		{
			clearbit(DDRA,7);
			clearbit(PORTA,7);
		}
		if(a==2)
		{
			clearbit(DDRB,0);
			clearbit(PORTB,0);
		}
		if(a==3)
		{
			clearbit(DDRB,1);
			clearbit(PORTB,1);
		}
		if(a==4)
		{
			clearbit(DDRB,2);
			clearbit(PORTB,2);
		}
		if(a==5)
		{
			clearbit(DDRB,3);
			clearbit(PORTB,3);
		}
}