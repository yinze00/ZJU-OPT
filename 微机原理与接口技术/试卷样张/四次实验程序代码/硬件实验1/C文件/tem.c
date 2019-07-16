#include<reg51.h>
#include<intrins.h>
void delay();
sbit K1 = P0^0;
sbit K2 = P0^1;

void main(){	
	bit f1 = 1;
	bit f2 = 1;
	char rec=0x01;
	P1=0x00;
	
	P2=0xAA;
	TMOD=0x10;	//T1按方式1工作
	TR1=1;		//启动定时器

	while(1){
	
		if(K1 == 0){	//K1按下了，
			f1=~f1;	//f1=0;
		}
		if(K2==0){
			f2=~f2;
		}			  		
	
		if (!f1)
			if (!f2)
				P1=0xFF;
			else {
				P1=P2;
				P2=~P2;
			}
		else if (!f2) {
			P1=rec;
			rec=_cror_(rec,1);
		}
		else {
			P1=0x00;
		}
		delay();
	}
}

void delay(){
	char i;
	bit pre_k1 = K1;
	bit pre_k2 = K2;
	for(i=0;i<20;i++){
		if(pre_k1==K1&&pre_k2==K2){
			TH1=0x3C;
			TL1=0xB0;
			while(TF1==0);	//直到查询到TF==1
			TF1=0;
		}else{
			return;
		}
	 }
	 return;
}
