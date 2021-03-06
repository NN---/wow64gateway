// wow64gateway.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

__declspec(naked) int f()
{
	__asm mov eax, 10
	__asm retf;
}

int call64(void* f64, void* ctp)
{
#pragma pack(push, 1)
	struct call1632
	{
		void* addr;
		short selector;
	};
#pragma pack(pop)

	call1632 g64 = { f64, 0x33 };
	_asm
	{
		mov	ecx, ctp
		// call 16:32
		// fword: 6 bytes
		call fword ptr g64
	}
}

int main()
{
	int r = call64(f, 0);
	std::cout << r;
    return 0;
}
