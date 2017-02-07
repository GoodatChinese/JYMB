#include<reg51.h>
#define portled P1
#define uchar unsigned char
uchar data timcnt,second;
void display(uchar);
void main(void)
{
	second = 0;
	timcnt = 0;
	TMOD = 0x00;
	TL0 = (8192 - 4608) % 32;
	TH0 = (8192 - 4608) / 32;
	ET0 =1;
	EA = 1;
	TR0 = 1;
	while(1)
	{PCON=PCON|0X01;}
}
void tim0() interrupt 1 using 1
{
	TL0 = (8192 - 4608) % 32;
	TH0 = (8192 - 4608) / 32;
	timcnt++;
	if(timcnt >= 200)
	{
		timcnt = 0;
		second++;
		if (second>=60) second=0;
}display(second);
}
void display(uchar time)
{
	portled = ~ (((time/10) << 4)|(time % 10));
}