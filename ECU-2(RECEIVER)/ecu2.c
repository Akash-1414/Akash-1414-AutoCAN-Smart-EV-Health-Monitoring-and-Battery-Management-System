#include<lpc21xx.h>
#include "can_driver.h"
#include "delay.h"
#include"lcd.h"

#define MAX_V 5.5
#define MIN_V 4.5

#define M1 1<<8
#define M2 1<<9
#define LEDT 1<<10
#define LEDBP 1<<11
#define BUZ 1<<12

char str[]="CAN Based EV Health Monitoring and Battery Management System Using LPC2129";

float R1=30000.0f; //voltage sensor resistor values
float R2=7500.0f;


int main()
{	

	CAN2_MSG m1;
	float volt=0,current=0,adc_voltage=0,adc_current=0,power=0;
	int battery_percentage=0,temp=0;

	IODIR0|=M1|M2;
	IOSET0=M1|M2;

	CAN2_INIT();
	LCD_INIT();

	IODIR0|=LEDT|LEDBP|M1|M2|BUZ;
	IOSET0=LEDT|LEDBP|M1|M2|BUZ;

	LCD_COMD(0x80);
	LCD_SCROLL(str);
	LCD_COMD(0x01);


	LCD_COMD(0x85);
	LCD_STR("DASH BOARD");
	



	while(1)
	{			
		CAN2_RX(&m1);

		if(m1.id==0x14 && m1.rtr==0)
		{
			adc_voltage=m1.byteA;
			volt=((adc_voltage)*((R1+R2)/R2));

			adc_current=m1.byteB;
			current=((((adc_current*5)/4096)-2.5)/0.185);

			battery_percentage=(((volt-MIN_V)/(MAX_V-MIN_V))*100);
			power=volt*current;	
		}

		if(m1.id==0x07 && m1.rtr==0)
		{
			temp=m1.byteA;
		}
	 
		if(m1.rtr==0)
		{

			LCD_COMD(0xc0);
			LCD_STR("V:");
			LCD_FLOAT(volt);
			LCD_COMD(0xc7);
			LCD_STR("C:");
			LCD_FLOAT(current);
			LCD_COMD(0xce);
			LCD_STR("P:");
			LCD_FLOAT(power);
		
			LCD_COMD(0x94);
			LCD_STR("T:");
			LCD_INTG(temp);
			LCD_STR("C");
			if(temp>=30)
			{
				LCD_COMD(0x9B);
				LCD_STR("HIGH");
				LCD_COMD(0xA2);
				LCD_STR("FS:ON");
				
				IOSET0|=M1;
				IOCLR0|=M2|LEDT|BUZ;
				delay_ms(100);
				IOSET0|=LEDT;
			}
			else
			{
				LCD_COMD(0x9B);
				LCD_STR("NORMAL");
				LCD_COMD(0xA2);
			   	LCD_STR("FS:OFF");
				IOSET0|=M1|M2|LEDT|BUZ;

			}

			LCD_COMD(0xD4);
			LCD_STR("CP:");
			LCD_INTG(battery_percentage);
			LCD_DATA('%');


			if(battery_percentage<=30)
			{
				LCD_COMD(0xDC);
				LCD_STR("LOW BATTERY");
				IOCLR0|=LEDBP|BUZ;
			}
			else
				IOSET0|=LEDBP|BUZ;


			delay_sec(1);
			LCD_COMD(0xc0);
			LCD_STR("                    ");
			LCD_COMD(0x94);
			LCD_STR("                    ");
			LCD_COMD(0xD4);
			LCD_STR("                    ");
		}	

	}
}

