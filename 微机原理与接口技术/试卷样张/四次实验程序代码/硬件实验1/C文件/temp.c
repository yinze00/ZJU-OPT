#include<reg51.h>
#include<intrins.h>

//亮和灭 
#define bright 0
#define out 1
//时间 
#define greentime 4	//绿灯时间
#define flashtime 3		//闪烁时间
#define yellowtime 2	//黄灯时间

sbit P11=P1^1;		//南北红
sbit P12=P1^2;		//南北黄
sbit P13=P1^3;		//南北绿
sbit P14=P1^4;		//东西红
sbit P15=P1^5;		//东西黄
sbit P16=P1^6;		//东西绿
char times,i;		//

void delay();

void main(){
	P1=0xFF;	//初始化
	TMOD=0x10;	//T1按方式1工作
	TR1=1;		//启动定时器
	//红灯亮两秒
	P11=bright;
	P14=bright;
	delay();
	delay();
	while(1){
		P14=out;	//东西红灯灭
		P16=bright;	//东西绿灯亮

		for(times=0;times<greentime;times++)
			delay();
		//绿灯闪
		for(times=0;times<flashtime;times++){
			P16=~P16;
			delay();
		}
		//绿灯灭
		P16=out;
		//黄灯亮
		P15=bright;
		for(times=0;times<yellowtime;times++)
			delay();
		//东西黄灯灭，红灯亮，南北绿灯亮
		P15=out;	P14=bright;
		P11=out;	//南北红灯灭 
		P13=bright;
		//南北绿灯亮greentime
		for(times=0;times<greentime;times++)
			delay();
		//南北绿灯闪烁
		for(times=0;times<flashtime;times++){
			P13=~P13;
			delay();
		}
		//南北绿灯灭
		P13=out;
		//南北黄灯亮yellowtime
		P12=bright;
		for(times=0;times<yellowtime;times++)
			delay();
		//南北黄灯灭,红灯亮 
		P12=out; 
		P11=bright;
	}
}

void delay(){
	for(i=0;i<10;i++){
		TH1=0x3C;
		TL1=0xB0;
		while(TF1==0);	
		TF1=0;
	}
	return;
}

