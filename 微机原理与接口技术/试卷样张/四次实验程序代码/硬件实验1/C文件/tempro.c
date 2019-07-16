#include<reg51.h>
#include<intrins.h>
void main(){
	unsigned char s[]={"Hello,World!"};
	int i = 0;
	for(i = 0;i<12;i++){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i] = s[i]+'a'-'A';											   	
		}
	}
}


