#include<lpc21xx.h>
#include "can_driver.h"
#include"delay.h"
#include"spi.h"

int main()
{	

	CAN2_MSG m1;	
	CAN2_INIT();
	SPI_INIT();
	m1.id=0x07;
	m1.rtr=0;
	m1.dlc=4;

	while(1)
		{
			m1.byteA=READ_ADC(0);	
			CAN2_TX(m1);
			delay_ms(200);
		}
}

