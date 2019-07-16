#include<reg51.h>
#include<intrins.h>

table[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
keycd[ ]={0xe7, 0xeb, 0xed, 0xee, 0xd7, 0xdb, 0xdd, 0xde, 0xb7,0xbb, 0xbd, 0xbe,0x77, 0x7b, 0x7d, 0x7e, 0xff};
void delay_ms(int z);
unsigned char FindKey(unsigned char keyCode);
void main(){
//采用右上角，共阳极数码管显示
	unsigned char temp1,temp2,totalcode;
	int b=0x00;		//b代表要显示的键值
	P0 = ~table[b];
	while(1){
		P0 = ~table[b];
		P1=0x0f;
		temp1=P1&0x0f;
		if(temp1!=0x0f){
			delay_ms(10);
			P1=0x0f;
			temp1 = P1&0x0f;
			if(temp1!=0x0f){	//确实有按键按下了。
				P1=0xf0;
				temp2 = P1&0xf0;
				totalcode = temp1 | temp2;
				if(totalcode!=0xff){
					b=FindKey(totalcode);
					P0 = ~table[b];				

				}
				
			}

		}
				
	}
	
}
void delay_ms(int z){
	int i,j;
	for( i = z ;i>0;i--){
		for(j=110;j>0;j--);
	} 	

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