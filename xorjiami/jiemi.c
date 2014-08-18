void main()
{
	__asm{
		add eax,0x14
		xor ecx,ecx
s:
		mov bl,[ecx+eax]
		xor bl,0x44
		mov [ecx+eax],bl

		inc ecx
		cmp bl,0x90
		jne s
	
	}
}