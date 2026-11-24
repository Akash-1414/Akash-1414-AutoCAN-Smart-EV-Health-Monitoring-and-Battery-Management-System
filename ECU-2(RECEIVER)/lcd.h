#include<lpc21xx.h>

#define LCD	0xff<<23

#define RS	1<<21

#define E	1<<22


void LCD_INIT(void);

void LCD_COMD(unsigned char);

void LCD_DATA(unsigned char);

void LCD_STR(unsigned char*);

void LCD_INTG(int);

void LCD_FLOAT(float);

void LCD_SCROLL(unsigned char *);





void LCD_INIT(void)

{

	IODIR1=LCD|RS|E;

	LCD_COMD(0x01);

	LCD_COMD(0x02);

	LCD_COMD(0x0c);

	LCD_COMD(0x38);


}


void LCD_COMD(unsigned char cmd)

{

	IOCLR1=LCD;

	IOSET1=(cmd<<23);

	IOCLR1=RS;

	IOSET1=E;

	delay_ms(2);

	IOCLR1=E;

}

void LCD_DATA(unsigned char data)

{

	IOCLR1=LCD;

	IOSET1=(data<<23);

	IOSET1=RS;

	IOSET1=E;

	delay_ms(2);

	IOCLR1=E;


}


void LCD_STR(unsigned char *s)

{

	while(*s)

	LCD_DATA(*s++);

}

void LCD_INTG(int n)

{

	char arr[32];

	int i=0;

	if(n==0)

	{

		LCD_DATA('0');

	}

	else

	{

		if(n<0)

		{

			LCD_DATA('-');

			n=-n;

		}

		while(n)

		{

			arr[i++]=n%10;

			n/=10;	

		}

		for(--i;i>=0;i--)

		{

			LCD_DATA(arr[i]+48);

		}

	}

}

void LCD_FLOAT(float f)

{

	int temp=f;

	LCD_INTG(temp);

	LCD_DATA('.');

	temp=(f-temp)*100;

	LCD_INTG(temp);

}
void LCD_SCROLL(unsigned char *s)

{

	char i,j,len=0;

	while(s[len]!='\0')

	len++;


	for(i=0;i<len;i++)

	{

		LCD_COMD(0x80);

		for(j=0;j<20;j++)

		{

			if((i+j)<len)

			{

				LCD_DATA(s[i+j]);

			}

			else

				LCD_DATA(' ');

			

		}

			delay_ms(300); 




	}

}




