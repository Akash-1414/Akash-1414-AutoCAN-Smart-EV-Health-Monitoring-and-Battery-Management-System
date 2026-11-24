#include <LPC21xx.H>

typedef unsigned int u32;

typedef struct CAN2
{
	u32 id;
	u32 rtr;
	u32 dlc;
	float byteA;
	float byteB;

}CAN2_MSG;

void CAN2_INIT(void);
void CAN2_TX(CAN2_MSG m1);
void CAN2_RX(CAN2_MSG *m1);

void CAN2_INIT(void)
{

	PINSEL1|=0x00014000;
	VPBDIV=1; 
	C2MOD=0x1; 
	AFMR=0x2; 
	C2BTR=0x001C001D; 
	C2MOD=0x0; 

}

void CAN2_TX(CAN2_MSG m1)
{

    C2TID1=m1.id;
	C2TFI1=(m1.dlc<<16);	

	if(m1.rtr==0) 
	{
		C2TFI1&=~(1<<30);
		C2TDA1=m1.byteA; 
		C2TDB1=m1.byteB; 
	}

	else
	{
		C2TFI1|=(1<<30); 
	}

	C2CMR=(1<<0)|(1<<5);
	while(((C2GSR>>3)&1)==0);

}

void CAN2_RX(CAN2_MSG *m1){

	while(((C2GSR)&1)==0);
	m1->id=C2RID;
	m1->dlc=(C2RFS>>16)&0xF;
	m1->rtr=(C2RFS>>30)&0x1;
	if(m1->rtr==0)
	{
		m1->byteA=C2RDA;
		m1->byteB=C2RDB;
	}

	C2CMR=(1<<2);

}





























