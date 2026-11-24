#include<lpc21xx.h>

#define MODE3 0x18

#define CS 1<<7


void SPI_INIT(void);

char SPIO(char);

float READ_ADC(char);



void SPI_INIT(void)

{

	PINSEL0|=0x1500;

	S0SPCCR=150;

	S0SPCR=(1<<5)|MODE3;

	IODIR0=CS;

	IOSET0=CS; 


}

char SPIO(char data)

{

	char stat;

	stat=S0SPSR;

	S0SPDR=data;

	while(((S0SPSR>>7)&1)==0);

	return S0SPDR;

}


float READ_ADC(char channel_no)

{

	char hbyte,lbyte;

	int adc=0;


	IOCLR0=CS;
	SPIO(0x06);

	hbyte=SPIO((channel_no&0x03)<<6);

	lbyte=SPIO(0x00);

	IOSET0=CS;


	adc=(((hbyte & (0x0f))<<8)|lbyte);

	
	if(channel_no==1)
	{
		return adc;
	}
	else
	  return(((adc*5)/4096));

}










