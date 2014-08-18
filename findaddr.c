#include <windows.h>
#include <stdio.h>
#include <string.h>
#define DLL_NAME "user32.dll"


main()
{
	BYTE * ptr;
	int weizhi,addr,count=0;
	HINSTANCE handle;
	BOOL done_flag=FALSE;
	handle=LoadLibrary(DLL_NAME);
	if(!handle)
	{
		printf("load handle error \n");
		exit(0);
	}
	
	ptr= (BYTE*)handle;
	for(weizhi=0;1;weizhi++){
		if(ptr[weizhi]==0XFF && ptr[weizhi+1]==0XE4)
		{
			int adrr=(int)ptr+weizhi;
			printf("address:0X%x\n",adrr);
			done_flag=TRUE;
			count++;
		}
		
	
	}
}