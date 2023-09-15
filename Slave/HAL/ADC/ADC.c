
#include <avr/io.h>
#include <util/delay.h>

#define setbit(reg,bit) reg|=(1<<bit)
#define clearbit(reg,bit) reg&=~(1<<bit)
#define toggelbit(reg,bit) reg^=(1<<bit)
#define readbit(reg,bit) ((reg>>bit)&1)


void ADC_init() // init
{
/*	setbit(ADMUX,REFS0);  // external v refrance
	setbit(ADCSRA,ADEN);  // ADC enable
	setbit(ADCSRA,ADPS2);	// pres caller 16 ADC f = 62500 with the range of ADC (50k:200k)Hz
*/
    ADMUX|=(1<<REFS0);//AVCC with external capacitor at AREF pin
	ADCSRA |=(1<<ADEN);//ADC Enable
	//ADC speed must be in range of 50k to 200k HZ
	ADCSRA |=(1<<ADPS2);//PRESCALER 16 --> freq = 62500 Hz
// 1- external refrence cap
// 2- enable
// 3- prescaler        1000,000 /  = 50-200 KH ==>62500

}

// return value int 0-255
// input selection for channel 
// ADC0-->ADC7
// 100  --> 4 


int ADC_read(int ADC_chanel)
{
	int adc_value=0;
	//0b01000000 &
	//0b11100000 |
	//0b00000100
//==> 0b01000100
	ADMUX = (ADMUX&0xE0)|ADC_chanel;//choose which ADC will work channel
	//0xE0 ==> 0b11100000
	ADCSRA |=(1<<ADSC);//ADC Start Conversion
	while(readbit(ADCSRA,ADIF)==0) //wait until Conversion complete using polling not int
	{    // 0 lessah or 1 tamam
	}
	//safty code for make sure conversion is ended 
	_delay_us(10);//wait until the value store in ADC REG.
	//decimal max 1023
	//2.5v == 512
	//1.25 == 256
	//5    == 1023
	adc_value =(int)ADCL+(int)ADCH*256;//calculate the ADC value
	// ADCL 8 bit lower 
	// ADCH 2 bit higher  0b01 =1
	// x = (ADCL =256 )+(ADCH =1*256 )= 512
	//10-bit 11 1111 1111 => 1023 
	return adc_value ;
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

