#include "pch.h"
#include "Mem.h"

void Mem::Patch(BYTE* dst, BYTE* src, UINT size)
{
	DWORD oldProtect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(dst, src, size);
	VirtualProtect(dst, size, oldProtect, &oldProtect);
}

void Mem::Nop(BYTE* dst, UINT size)
{
	DWORD oldProtect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldProtect, &oldProtect);
}

uintptr_t Mem::FindDMAAddy(uintptr_t ptr, std::vector<UINT> offsets)
{
	uintptr_t addr = ptr;

	for (UINT i = 0; i < offsets.size(); ++i)
	{
		addr = *(uintptr_t*)addr;
		addr += offsets[i];
	}

	return addr;
}
