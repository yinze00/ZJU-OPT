#include<reg51.h>
#include<intrins.h>
#include<math.h>
#include<stdio.h>
typedef   unsigned char  uint8;
typedef   unsigned int   uint16;
unsigned char Init_DS18B20();
void Write_byte(unsigned char dat);	//DS18B20写一个字节函数
void Delay60us();		//@11.9157MHz
void Delay480us();		//@11.9157MHz
void Delay600us();		//@11.9157MHz
void Delay500ms();		//@11.9157MHz

unsigned char Read_byte(void);		//DS18B20读一个字节函数
unsigned int Get_Temperature(void);
unsigned char table[10]={'0','1','2','3','4','5','6','7','8','9'};
uint8 buf[]="The temperature is:";
uint8 bufend[]="°C right now!\n";
sbit DQ=P3^7;		  

unsigned char string[10];//储存10进制温度全局变量 
/*发送一个字符*/
void UART_send_byte(uint8 dat){
	SBUF = dat;       //把数据放到SBUF中
	while (TI == 0);//未发送完毕就等待
	TI = 0;    //发送完毕后，要把TI重新置0
}	
/*发送一个字符串*/	   
void UART_send_string(uint8 *buf){								
	while (*buf != '\0')	{							
		UART_send_byte(*buf++);	
	}							
}
void main(){
	//int t1;
	int t;

	unsigned char temp[8];
	double Temp;

	SCON=0x50;
	//PCON=0x80;
	TMOD=0x20;
	TH1=0xF3;
	TL1=0xF3;
	TR1=1;
//	Init_DS18B20();
/*	while(1){
		UART_send_string(buf);
		t1=Get_Temperature()/0x0f;
		SBUF=t1/10*16+t1%10;
		while(TI==0);
		TI=0;
		UART_send_string(bufend);
		Delay500ms(); 
	}
*/
;
	//UART_init();
	Init_DS18B20();
	while(1){
			UART_send_string(buf);
			t=Get_Temperature();
			// t = 0x5678;
			Temp=(double)(t&0x07ff)*0.0625;//数值位乘以0.0625
			//Temp = 温度
			if(t&0xf000){
				temp[0]='-';
			}
			else{
				temp[0]='+'; //符号位
			}
			temp[1]=table[(unsigned char)(Temp/100)%100];//百位
			if(temp[1]=='0'){
				temp[1]=' ';
			}
			Temp=Temp-(unsigned char)(Temp/100)*100;
			temp[2]=table[(unsigned char)(Temp/10)%10];//十位
			Temp=Temp-(unsigned char)(Temp/10)*10;
			temp[3]=table[(unsigned char)Temp]; //个位
			Temp=Temp-(unsigned char)Temp;
			temp[4]='.';
			Temp=Temp*10;
			temp[5]=table[(unsigned char)Temp];
			Temp=Temp-(unsigned char)Temp;
			Temp=Temp*10;
			temp[6]=table[(unsigned char)Temp];
			temp[7]='\0';
			UART_send_string(temp);
			UART_send_string(bufend);
			Delay500ms();
	}	
}
unsigned char Init_DS18B20(){
	unsigned char tdq;
	DQ=0;				//主线拉低总线
	Delay480us();			//等待480us
	DQ=1;				//主机释放总线
	Delay60us();			//等待60us
	tdq=DQ;				//主机检测总线
	Delay480us();			//等待应答脉冲结束
	return tdq;			//返回采样值
}
unsigned char Read_byte(void){
	unsigned char i=0;
	unsigned dat=0;
	for(i=8;i>0;i--){
		_nop_();
		_nop_();			//2次读操作之间至少间隔1us
		DQ=0;				//从高拉到低，并保持低电平至少1us
		_nop_();
		_nop_();
		DQ=1;				//释放总线
		_nop_();
		_nop_();
		dat>>=1;			//读入次序从低到高，先读最低位
		if(DQ){
			dat|=0x80;
		}
		Delay60us();			//至少等待60us，以确保读数成功
	}
	DQ=1;				//释放总线
	return(dat);

}
void Write_byte(unsigned char dat){
	unsigned char i=0;
	for(i=8;i>0;i--){
		DQ=1;
		_nop_();
		_nop_();		//保证两次写操作间隔至少1us
		DQ=0;			//开始一次写操作
		_nop_();
		_nop_();
		DQ=dat&0x01;	//写次序为先低位后高位
		Delay60us();		//至少保持60us写时间隙
		dat>>=1;		//右移一位
	}
	DQ=1;				//释放总线
}
unsigned int Get_Temperature(void){	//DS18B20读温度函数
	unsigned char a=0;
	unsigned char b=0;
	unsigned char c=0;
	unsigned int t=0;
	c=Init_DS18B20();				//DS18B20初始化函数，函数体与1——wire初始化函数Reset()相同
	
	if(c==0)						//是有器件挂接在总线上
	{
		Write_byte(0xCC);			//只接一个18b20芯片，跳过ROM
		Write_byte(0x44);			//温度转化
		Delay600us();					//延时600us(等待测量完毕，）一次测量时间为500us
		Init_DS18B20();				//重新初始化
		Write_byte(0xcc);
		Write_byte(0xbe);			//从RAM读数据
		a=Read_byte();				//先读低字节
		b=Read_byte();				//再读高字节
		t=b<<8;
		t=t|a;						//t为最后读得的数据
	}
	else
		t=0;
	return(t);
}
void Delay480us()		//@11.9157MHz
{
	unsigned char i;

	_nop_();
	i = 235;
	while (--i);
}


void Delay60us()		//@11.9157MHz
{
	unsigned char i;

	i = 27;
	while (--i);
}


void Delay600us()		//@11.9157MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 36;
	do
	{
		while (--j);
	} while (--i);
}

void Delay500ms()		//@11.9157MHz
{
	unsigned char i, j, k;

	i = 4;
	j = 198;
	k = 230;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}