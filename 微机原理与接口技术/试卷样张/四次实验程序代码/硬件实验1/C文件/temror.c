#include<reg51.h>
#include<intrins.h>
void main(){
	char s[16]={"0123456789ABCDEF"};
	long int a = 12345678;
	char ans_hex[8]={"00000000"};
	int i=7;
	while(a){
		ans_hex[i--]=s[a%16];
		a/=16;
	}										   
}

