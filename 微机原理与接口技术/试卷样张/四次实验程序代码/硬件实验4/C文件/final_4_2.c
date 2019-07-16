#include<reg51.h>	 
typedef unsigned int u16;
typedef unsigned char u8; 
u8 Buf[]="  0%\n"; 
u8 d;
u8 code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39 ,0x5e,0x79,0x71};
//----------------------------------总线位申明-------------------------------------------//
sbit sda=P2^0;
sbit scl=P2^1;
//-----------------------------------IIC时序-------------------------------------------//
void delay(u16 n){
	while (n--);
}
//--------------------------------us延时
void init_iic(){
	scl=0;
	delay(1);
	sda=1;
	delay(1);
	scl=1;
	delay(1);
}
//-------------------------IIC初始化释放总线
void start() {
	scl=0;
	delay(1);
	sda=1;
	delay(1);
	scl=1;
	delay(1);
	sda=0;//发送起始信号
//--------------------------------------------
	delay(1);
	scl=0;
	delay(1);
	sda=1;//释放数据总线，接受信号
	delay(1);
}
//--------------------------IIC起始信号（SDA在SCL=1时产生下降沿）
void write_byte(u8 date)
{
	u8 i,temp;
	temp=date;
	for(i=0;i<8;i++)
	{
		temp=temp<<1;
		scl=0;//允许数据总线接受新数据，数据可变
		delay(1);
		sda=CY;//数据由高位向低位依次传输<<循环左移将数据送往数据总线
		delay(1);//稳定信号
		scl=1;//读走数据
		delay(1);
	}
	scl=0;
	delay(1);
	sda=1;
	delay(1);//准备接受应答信号
	scl=1;
}
//--------------------------IIC字节写所用临时变量  ------i---temp
void response()
{
	u8 t;//计时系统默认应答
	while((sda==1)&&(t<250))t++;
	scl=0;
	delay(1);
}
//-----------------------应答信号--------------临时变量----t(长时间)
void stop()
{
	scl=0;
	delay(1);
	sda=0;
	delay(1);
	scl=1;
	delay(1);
	sda=1;
	delay(1);
}
//----------------------结束信号，SCL=1时，SDA出现有效的正跳变
u8 read_byte()
{
	u8 k,n;
	k=0x00;
	for(n=0;n<8;n++)
	{
		scl=0;
		delay(1);
		scl=1;
		delay(1);
		k=(k<<1)|sda;
	}//读完数据后将会产生非应答，以结束数据读取
	delay(1);
	return k;
}
//---------------------字节读，带有返回值，临时变量-----k(存储数据)------n(循环移位计数存入数据)
//----------------------------显示部分-----------------------------------------------------------------------//
void display()
{
	u8 bai,shi,ge;
	long y=d;
	long x=100-y*100/255;
	bai=(x/100)%10;
	shi=(x%100)/10;
	ge=x%10;
	P1=0xfe;
	P0=table[bai];
	delay(110);
	P1=0xFD;
	P0=table[shi];
	delay(110);
	P1=0xFB;
	P0=table[ge];
	delay(110);
	P1=0xFF;
	if (!bai) {
		Buf[0]=' ';
		if (!shi)
			Buf[1]=' ';
		else
			Buf[1]=shi+'0';	
	}
	else {
		Buf[0]=bai+'0';
		Buf[1]=shi+'0';
	}
	Buf[2]=ge+'0';
}
/*波特率为2400*/
void UART_init(void)
{
    SCON = 0x50;        //串口方式1
 
    TMOD = 0x20;        // 定时器使用方式2自动重载
    TL1 = 0xF3;  //设定定时初值
	 TH1 = 0xF3;  //设定定时初值
 
    TR1 = 1;//开启定时器，开始产生波特率
}
 
/*发送一个字符*/
void UART_send_byte(u8 dat)
{
	SBUF = dat;       //把数据放到SBUF中
	while (TI == 0);//未发送完毕就等待
	TI = 0;    //发送完毕后，要把TI重新置0
}
 
/*发送一个字符串*/
void UART_send_string(u8 *buf)
{
	while (*buf != '\0')
	{
		UART_send_byte(*buf++);
	}
}
//--------------------------------------------------------------------------------------------------//
void main()
{
	char i=0,j=0;
	init_iic();
	UART_init();
	while(1)
	{
		start();
		write_byte(0x90);//器件地址10010001
		response();
		write_byte(0x00);//控制字节
		response();
		delay(1100);//等待采集数据，存入数据寄存器
		stop();
		delay(550);
		start();
		write_byte(0x91);
		response();
		if (i==5) {
			d=read_byte();
			i=0;
		}
		delay(550);
		stop();
		display();
		i++;
		if (j>7) {
			UART_send_string(Buf);
			j=0;
		}
		else
			j++;
	}
}