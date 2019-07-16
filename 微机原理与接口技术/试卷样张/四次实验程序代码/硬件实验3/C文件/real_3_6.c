#include<reg51.h>
#include<intrins.h>
unsigned char student_id[]={3,1,7,0,1,0,5,9,7,0};
//							0 1 2 3 4 5 6 7 8 9
//							↑
unsigned char arrow_start = 0;
unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
keycd[ ]={0xe7, 0xeb, 0xed, 0xee, 0xd7, 0xdb, 0xdd, 0xde, 0xb7,0xbb, 0xbd, 0xbe,0x77, 0x7b, 0x7d, 0x7e, 0xff};
unsigned char P0_move[]={0xfd,0xfb,0xf7,0xef,0xdf,0xbf};
unsigned char count = 0;
unsigned char id_change=1;
unsigned char id_num = 0;						
void delay_ms(int z);
unsigned char FindKey(unsigned char keyCode);	
void main(){		  
	//8个数码管的最后一个是共阴极
	//P1口输出断码，P0口输出位码
	//动态显示3170105970 每次显示6个数，循环左移
   	int j=0;	
	unsigned char temp1,temp2,totalcode;
	int b=0x00;		//b代表要显示的键值
	//P0 = ~table[b];
	int num = 0;
	while(num<10){
		P2=0x0f;
		temp1=P2&0x0f;
		if(temp1!=0x0f){
			delay_ms(10);
			P2=0x0f;
			temp1 = P2&0x0f;
			if(temp1!=0x0f){	//确实有按键按下了。
				P2=0xf0;
				temp2 = P2&0xf0;
				totalcode = temp1 | temp2;
				if(totalcode!=0xff){
					b=FindKey(totalcode);
					student_id[num++] = ~table[b];
					P1 = ~table[b];				
				}														
			}											
		}																
	}

	num++;

   	P0 = 0xfe;				//1111 1110
  	P1 = 0x00; 
   	delay_ms(1000);
	TMOD = 0x01;	//T0计时器以方式2运行
	EA = 1;
	ET0 = 1;
	TH0 = (65536-50000)/256;
	TL0 = (65536-50000)%256;
	TR0 = 1;
 	while(1){
		for(j=0;j<6;j++){
			P0 = P0_move[j];

			// 23:59:59
			P1 = table[student_id[(arrow_start+j)%10]];
			delay_ms(1);
		}
		
	}	
	  
}
void timer0() interrupt 1 using 1{
	if(count == 20){
		TH0 = (65536-50000)/256;
		TL0 = (65536-50000)%256;
		arrow_start++;
		arrow_start%=10;
		count = 0;
	}
	count++;
		
}
void delay_ms(int z){
	int i,j;
	for(i = z;i>0;i--)
		for( j=110;j>0;j--);
}
unsigned char FindKey(unsigned char keyCode) //判断键值函数
{
	unsigned char i = 0;
	while(keycd[i] != 0xff)
	{
		if(keyCode==keycd[i])
			break;
		i++;
	}
	return i;
}