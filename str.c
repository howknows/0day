#include <stdio.h>
#include <windows.h>
#define PASSWD "21389321"

/*void strcopy(char *buffer,char *password)
{
	int i=0;
	while(*(buffer+i)=*(password+i))
		i++;
}*/

int yanzheng(char *password)
{
	int res;
	char buffer[44];
	res=strcmp(password,PASSWD);
	strcpy(buffer,password);
	return res;
}

main()
{
	int flag=0;
	char password[2014];
	FILE *fp;
	LoadLibrary("user32.dll");
//	gets(password);
	if(!(fp=fopen("password.txt","rw+"))){
		printf("file error \n");
		exit(0);
	}
	fscanf(fp,"%s",password);
	flag=yanzheng(password);
	printf("result:%d\n",flag);
	fclose(fp);
}
