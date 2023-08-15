#pragma once
#include "pch.h"

namespace Hook
{	
	BOOL Detour(void* target,void* hookOffset, UINT size);
}
