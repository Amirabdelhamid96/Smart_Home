
#include <avr/io.h>
#include <util/delay.h>

#define MOSI 5 //master out
#define SCK 7 //clock
#define SS  4 //sel
#define MISO 6 //master in
//1-init
//2-function send
//3-function recive
void SPI_Init()					/* SPI Initialize function */
{
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);	//Make MOSI, SCK, SS as Output pin
	DDRB &= ~(1<<MISO);			// Make MISO pin as input pin
	PORTB |= (1<<SS);			// Make high on SS pin
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	// Enable SPI in master mode with Fosc/16
	SPSR &= ~(1<<SPI2X);			// Disable speed doubler
	PORTB &=~(1<<SS);  //Deselect
}


void SPI_Write(unsigned char data)		/* SPI write data function */
{
	
	SPDR = data;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
	
	
}


char SPI_Read()				/* SPI read data function */
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return(SPDR);			/* Return received data */
}

/*
int main(void)
{
	SPI_Init();

	PORTB &=~(1<<SS);
	while (1)
	{
		SPI_Write('A');//char 0 ascii
		_delay_ms(2000);
		//2 --> 0x02
		SPI_Write('B');//char 0 ascii
		_delay_ms(2000);
		SPI_Write('C');//char 0 ascii
		_delay_ms(2000);
	}
}*/

