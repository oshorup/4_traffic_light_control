#include<reg51.h>
//values of 7-segment display from 9 to 0
unsigned char ch[]={0xF7,0XFF,0XE1,0XBF,0XB7,0X67,0XF3,0XDB,0X61,0xFD};
unsigned int i,z;

//giving a delay of 1sec
int delay()
{
	//20 times runing
  for(z=0;z<20;z++)
	{
		TMOD = 0X01;
		TL0 = 0XB0;
		TH0 = 0X3C;
		TR0 = 1;
		//50 ms delay
		while(TF0==0);
			TF0=0;
			TR0=0;
	}
}
void count(){
	P3 = 0XF7; //Port 3 for giving input to the 7 segment display, start from number 9
	//displaying each number on 7 segment display for 1 second
	for(i=0;i<sizeof ch;i++)
	{
		P3 = ch[i];
		delay();
	}
}
int main()
{
	while(1)
	{
		//;casee I - when East = Green, South = Yellow, West = Red, North = Red
		P2 = 0x2A;
		P1 = 0x04;
		count();
		
		//;casee II - when East = Red, South = Green, West = Yellow, North = Red
		P2 = 0x85;
		P1 = 0x04;
		count();
		
		//;casee III - when East = Red, South = Red, West = Green, North = Yellow
		P2 = 0x90;
		P1 = 0x0A;
		count();
		
		//;casee IV - when East = Yellow, South = Red, West = Red, North = Green
		P2 = 0x52;
		P1 = 0x01;
		count();
	}
}