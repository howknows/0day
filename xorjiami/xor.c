#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define KEY 0x44

void main()
{
	FILE *fpinput,*fpoutput;
	char input[2048],*output,temp=-1;
	int len,i;
	int j=0;
	if((fpinput=fopen("shellcode.txt","r+"))==NULL)
	{
		printf("Open file error!\n");
		exit(0);
	}
	while(temp!='\0')
		temp=input[j++]=fgetc(fpinput);
	len=strlen(input);
	output=(char *)malloc(len+1);
	for(i=0;i<len;i++)
		*(output+i)=input[i]^KEY;
	*(output+i)='\0';
	if((fpoutput=fopen("encode.txt","wr+"))==NULL)
	{
		printf("Creat file error!\n");
		exit(0);
	}
	temp=-1;
	for(j=0;temp!='\0';j++){
		fputc(temp=*(output+j),fpoutput);
	}
	
	fclose(fpoutput);
	fclose(fpinput);
	free(output);

}

