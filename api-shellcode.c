void main()
{
	__asm{
	CLD;clear DF
	push 0x1e380a6a
	push 0x4fd18963
	push 0x0c917432
	mov esi,esp
	lea edi,[esi-0xc]

	xor ebx,ebx
	mov bh,0x04
	sub esp,ebx

	mov bx,0x3233
	push ebx
	push 0x72657375
	push esp
	xor edx,edx

	mov ebx,fs:[edx+0x30]
	mov ecx,[ebx+0x0c]
	mov ecx,[ecx+0x1c]
	mov ecx,[ecx]
	mov ebp,[ecx+0x08]

find_lib_functions:
	lodsd
	cmp eax,0x1e380a6a
	jne find_functions
	xchg eax,ebp
	call [edi-0x8]
	xchg eax,ebp

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
	mov esi,[ebx+edi*4]
	add esi,ebp

	cdq

hash_loop:
	movsx eax,byte ptr[esi]
	cmp al,ah
	jz compare_hash
	ror edx,7
	add edx,eax
	inc esi
	jmp hash_loop

compare_hash:
	cmp edx,[esp+0x1c]
	jnz next_function_loop
	mov ebx,[ecx+0x24]
	add ebx,ebp
	mov di,[ebx+2*edi]
	mov ebx,[ecx+0x1c]

	add ebx,ebp
	add ebp,[ebx+4*edi]

	xchg eax,ebp
	pop edi
	stosd

	push edi
	popad

	cmp eax,0x1e380a6a
	jne find_lib_functions


function_call:
	xor ebx,ebx
	push ebx
	push 0x74736577
	push 0x6c696166
	mov eax,esp
	push ebx
	push eax
	push eax
	push ebx
	call [edi-0x04]
	push ebx
	call [edi-0x08]
	nop
	nop
	nop
	nop
	}
}