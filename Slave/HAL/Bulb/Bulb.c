
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
		setbit(DDRA,3);
		setbit(PORTA,3);	
		}
		if(a==2)
		{
			setbit(DDRA,4);
			setbit(PORTA,4);
		}
		if(a==3)
		{
			setbit(DDRA,5);
			setbit(PORTA,5);
		}
		if(a==4)
		{
			setbit(DDRA,6);
			setbit(PORTA,6);
		}
		if(a==5)
		{
			setbit(DDRA,7);
			setbit(PORTA,7);
		}
}

void Bulb_off(int a)
{
		if(a==1)
		{
			clearbit(DDRA,3);
			clearbit(PORTA,3);
		}
		if(a==2)
		{
			clearbit(DDRA,4);
			clearbit(PORTA,4);
		}
		if(a==3)
		{
			clearbit(DDRA,5);
			clearbit(PORTA,5);
		}
		if(a==4)
		{
			clearbit(DDRA,6);
			clearbit(PORTA,6);
		}
		if(a==5)
		{
			clearbit(DDRA,7);
			clearbit(PORTA,7);
		}
}