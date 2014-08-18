#include <windows.h>

void main()
{
	LoadLibrary("msvcrt.dll");
	system("calc");
}