#include<reg51.h>
#include<intrins.h>
void delay();

void main(){
	TMOD=0x10;	//T1按方式1工作
	TR1=1;		//启动定时器
	P1=0xAA;	//全红
	delay();
	P1=~P1;		//全绿
	delay();
	P1=0xFF;	//全黄
	delay();
	
	P3=0x9C;	//P3 = 1001 1100 (依次红、绿、黄、暗）
	P1=P3;
	while(1){
		delay();
		P3=_cror_(P3,2);  //每次循环移动2个
		P1=P3;
	}
	
}

void delay(){
	char i;
	for(i=0;i<20;i++){
		TH1=0x3C;
		TL1=0xB0;
		while(TF1==0);	//直到查询到TF==1
		TF1=0;
	 }
	 return;
}
