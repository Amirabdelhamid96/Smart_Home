
#include <avr/io.h>
#include <util/delay.h>

#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=~(1<<bit)
#define toggelbit(reg,bit) reg^=(1<<bit)
#define readbit(reg,bit) ((reg>>bit)&1)


// ubbr = (clk / 16 * baud)  -1
// ubbr ==> baud rate ) ( 16,000,000 /(16*9600))-1 = 104-1 =103
// ubbr = 103 --> 9600
// 1- data size  --> 8bits  --> send and recive
// 2- 1 stop bit --> 1 single bit
// 3- enable -->     TX/RX
// baude rate : speed of sending data    bit per second bps
// table of speed of baude rate: 3Mbps ~ 4800 bps (9600 bps) 9600 )
// 
void UART_INIT(unsigned int baud)//103  479 10101010101
{// 8 bit data 1 stop bit 
	UCSRB |= (1 << RXEN) | (1 << TXEN);	// Enable UART transmitter and receiver
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	//8 bit data and 1 stop bit
	UBRRL = baud;//lower
	UBRRH = (baud >> 8);//higher 
}


void UART_sendchar(unsigned char data)
{   
		while (! (UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer*/
		UDR = data ;
}
unsigned char UART_receivechar()
{
	while(readbit(UCSRA,RXC)==0) // wait the data to be receive
	{	;	}
	
	return UDR;// data source for variables
}



void UART_sendString(char *str)
{
	int count =0 ;
	while (str[count]  != 0)
	{
		UART_sendchar(str[count]);
		count ++;
	}
}




/*int main(void)
{
    
    UART_INIT(103);  // init baud = 9600
	
	LCD_INIT_4bit();
	LCD_send_string_4bit("AHMED ");
	
    while (1)  
    {
		UART_sendchar('A'); _delay_ms(1000);
		UART_sendchar('B'); _delay_ms(1000);
			
    }
}*/

