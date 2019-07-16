#include<reg51.h>
#include<intrins.h>
sbit p10 = P1^0;
unsigned int i;
unsigned int count;
unsigned char table[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned int number;
bit flag = 1; 
void display(unsigned int num);
void delay1ms();
void main(){
	TMOD = 0X10;
	TH1 = 0xfC;
	TL1 = 0x17;
	EA = 1;
	ET1 = 1;  
	TR1 = 1;
	count = 0;
	number = 60;
	while(1);		
}
void timer1() interrupt 3 using 1{	//1ms
	TH1 = 0xfC;
	TL1 = 0x6B;
	count++;
	if(flag){
		P0 = 0xbf; //1011 1111
		P1 = table[number/10];
		flag=0;
	}else{
		P0 = 0x7f; //0111 1111
		P1 = table[number%10];
		flag=1;
	}
	if(count==1000){
		count = 0;
		number--;
		if(number==0){
			number = 60;
		} 
	} 	
}



