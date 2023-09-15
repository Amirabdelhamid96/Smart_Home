#include <avr/io.h>
#include <avr/interrupt.h> // header interrupt
#include <util/delay.h>

// macros for DIO
#define setbit(reg,bit) reg|=(1<<bit)    // one
#define clearbit(reg,bit) reg&=~(1<<bit) // zero
#define toggelbit(reg,bit) reg^=(1<<bit) // toggle
#define readbit(reg,bit) ((reg>>bit)&1)  //read



void int1_init() // int1 intialization
{
	clearbit(DDRD,3);    // set pin as INPUT
	clearbit(MCUCR,ISC11); // The rising edge of INT1 generates an interrupt request.
	setbit(MCUCR,ISC10); // The rising edge of INT1 generates an interrupt request.
	setbit(GICR,INT1);   // external interrupt  EN  INT1
	sei();               // global interrupt EN
}



// pulse
//   R  ____  F     High level  5v
//     |    |
// ____|    |____   low level   0v

// Push button --> pulse  --> define wich part of the pulse
//
//



void int0_init()
{
	clearbit(DDRD,2);    // set pin as INPUT
	setbit(MCUCR,ISC01); // The rising edge of INT1 generates an interrupt request.
	setbit(MCUCR,ISC00); //The rising edge of INT1 generates an interrupt request.
	setbit(GICR,INT0);   // external interrupt  EN INT0
	sei();               // global interrupt EN
}

// handler : function --> subroutine other code for interrupt
//






// int1 --> set bit 5
ISR(INT1_vect)  // interrupt service routine ISR handler --> vetor name ==>table--> address to the function --> process subroutine
{	// the code needed
	int x;
	for(x=0;x<7;x++)
	{
		toggelbit(PORTA,5);
		_delay_ms(500);
	}
}

// int0 --> clear bit 5
ISR(INT0_vect)
{
	clearbit(PORTA,5);
}