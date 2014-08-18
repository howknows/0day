#include <stdio.h>
#include <windows.h>

DWORD gethash(char *string)
{
	DWORD res=0;
	while(*string)
	{
		res=((res<<25)|(res>>7));
		res+=*string;
		string++;
	}
	return res;
}

void main()
{
	char string[512];
	DWORD hash;
	printf("-----------Hash-calc---------\n");
	gets(string);
	hash=gethash(string);
	printf("result:0x%.8x\n",hash);
}
