#include<reg51.h>
#include<intrins.h>
unsigned char student_id[]={3,1,7,0,1,0,5,9,7,0};
//							0 1 2 3 4 5 6 7 8 9
//							↑
unsigned char arrow_start = 0;
unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char P0_move[]={0xfe,0xfd,0xf7,0xef,0xbf,0x7f};
//						11111110 11111101 11111011 11110111 11101111 11011111
//							2	     3   :    5		9 	   :   5		9
sbit hourinc = P2^0;
sbit hourdec = P2^1;
sbit mininc = P2^2;
sbit mindec = P2^3;
sbit clear = P2^4; 
unsigned char  P0_val[8];
unsigned char count = 0,second=0, miniute=0, hour=0;							
void delay_ms(int z);

void main(){		  
	//题目任务P0 的 hh:mm:ss
	//		  P0    00100100
	//P1段码 、P0位码
   	int j=0;	
   	TMOD = 0x01;	//T0计时器以方式2运行
	EA = 1;
	ET0 = 1;
	TH0 = (65536-50000)/256;
	TL0 = (65536-50000)%256;
	TR0 = 1;
	//P0_val[2]=P0_val[5]=0x00;
 	while(1){
	if(clear==0){
		second = 0;
	}
	while(hourinc == 0){
		delay_ms(300);
		hour++;
	}
	while(hourdec ==0){
		delay_ms(300);

		hour--;
	}
	while(mininc == 0){
		delay_ms(300);
		miniute++;
	}
	while(mindec == 0){
		delay_ms(300);
		miniute--;
	}
			
		for(j=0;j<6;j++){
			P0 = P0_move[j];
			P1 = table[P0_val[5-j]];
			delay_ms(1);
		}
	}	  
}
void timer0() interrupt 1 using 1{		//每5ms定时

	if(count ==2){					//每20次改变一次
		char temp;
		TH0 = (65536-50000)/256;
		TL0 = (65536-50000)%256;

		second++;		
		miniute+=second/60;
		hour+=miniute/60;

		second%= 60;
		miniute%=60;
		hour%=24;

		count = 0;

		P0_val[0]=second%10;
		P0_val[1]=second/10;
		P0_val[2]=miniute%10;
		P0_val[3]=miniute/10;
		P0_val[4]=hour%10;
		P0_val[5]=hour/10;  
	}
	count++;		
}
void delay_ms(int z){
	int i,j;
	for(i = z;i>0;i--)
		for( j=110;j>0;j--);
}
