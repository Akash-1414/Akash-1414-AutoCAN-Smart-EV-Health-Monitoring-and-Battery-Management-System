#include<lpc21xx.h>
#include "can_driver.h"
#include"delay.h"
#include"spi.h"



int main()
{	

	CAN2_MSG m1;	
	CAN2_INIT(); 
	SPI_INIT();
	

	m1.id=0x14;
	m1.rtr=0;
	m1.dlc=8;


	while(1)
		{			
			m1.byteA=READ_ADC(0);
			delay_ms(200);
			m1.byteB=READ_ADC(1);	
			
			CAN2_TX(m1);
			delay_ms(200);
			
		}
}

