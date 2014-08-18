#include <stdio.h>
#define KEY 0x71
void main()
{
	char string[30];
	char *str;
	char qu=0,tem;
	gets(string);
	str=string;
	while(*str){
		tem=*str^KEY;
		qu-=tem;
		str++;
	}
	printf("%x\n",qu);

}