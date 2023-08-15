#include "pch.h"
#include "Hook.h"

BOOL Hook::Detour(void* target, void* ourFunc, UINT len)
{
	if (len < 5)
	{
		return false;
	}

	DWORD oldProtect;

	VirtualProtect(target, len, PAGE_EXECUTE_READWRITE, &oldProtect);

	memset(target, 0x90, len);

	DWORD relativeAddr = ((DWORD)ourFunc - (DWORD)target) + 5;

	*(BYTE*)target = 0xE9;
	*(DWORD*)((DWORD)target + 1) = relativeAddr;

	VirtualProtect(target, len, oldProtect, &oldProtect);

	return true;
}