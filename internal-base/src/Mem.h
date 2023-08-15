#pragma once
#include "pch.h"

namespace Mem
{
	void Patch(BYTE* dst, BYTE* src, UINT size);

	void Nop(BYTE* dst, UINT size);

	uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<UINT> offsets);
}

