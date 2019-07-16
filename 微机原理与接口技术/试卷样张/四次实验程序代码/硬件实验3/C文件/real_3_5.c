#include<reg51.h>
#include<intrins.h>
unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char P0_move[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//						11111110 11111101 11111011 11110111 11101111 11011111 10111111 01111111
//							2	     3   :    5		9 	   :   5		9
//方框显示效果：
//				- - - - 
//						|
//			   | _ _ _ _
//
//	对于某一个单一数码管，有 上、下、上左下、下左上、下右上、上右下；
//		对应段码为：		 01  08    11	   28      0a      05
//对应依次送入段码为   P0_move = [11,08,01,08,01,08,01,0a];
//					   P0_move = [28,01,08,01,08,01,08,05];	
unsigned char P1_move[2][8]={{0x11,0x08,0x01,0x08,0x01,0x08,0x01,0x0a},
						 {0x28,0x01,0x08,0x01,0x08,0x01,0x08,0x05}};

unsigned char  P0_val[8];
unsigned char flag = 0;
unsigned char count = 0,second=0, miniute=0, hour=0;							
void delay_ms(int z);

void main(){		  
	//题目任务P0 的 hh:mm:ss
	//		  P0    00100100
	//P1段码 、P0位码
   	int j=0;
	unsigned char temp;	
   	TMOD = 0x01;	//T0计时器以方式2运行
	EA = 1;
	ET0 = 1;
	TH0 = (65536-50000)/256;
	TL0 = (65536-50000)%256;
	TR0 = 1;
	P0 = 0x7f;
 	while(1){
		if(flag){
			for(j=0;j<8;j++){
				P0 = P0_move[j];
				P1 = P1_move[0][j];
				delay_ms(1);
			}
		}else{
			for(j=0;j<8;j++){
				P0 = P0_move[j];
				P1 = P1_move[1][j];
				delay_ms(1);
			}	
		}		
	}	  
}
void timer0() interrupt 1 using 1{		//每50ms定时
	
	if(count ==20){					//每20次改变一次
		TH0 = (65536-50000)/256;	 
		TL0 = (65536-50000)%256;	  
		count = 0;

		if(flag)
			flag=0;
		else
			flag = 1;
	}
	count++;		
}
void delay_ms(int z){
	int i,j;
	for(i = z;i>0;i--)
		for( j=110;j>0;j--);
}
