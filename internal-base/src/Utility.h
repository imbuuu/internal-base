#pragma once

namespace Util
{
	void CreateConsole();

	HMODULE GetModuleBaseAddr(CONST WCHAR* modName);
	HMODULE GetCurrentModuleBaseAddr();
}

