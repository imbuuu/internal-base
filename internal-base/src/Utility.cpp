#include "pch.h"
#include "Utility.h"

void Util::CreateConsole()
{
	FILE* F;
	AllocConsole();
	freopen_s(&F, "CONOUT$", "w", stdout);	
}

HMODULE Util::GetModuleBaseAddr(CONST WCHAR* modName)
{
	return GetModuleHandle((LPCWSTR)modName);
}

HMODULE Util::GetCurrentModuleBaseAddr()
{
	return GetModuleHandle(0);
}