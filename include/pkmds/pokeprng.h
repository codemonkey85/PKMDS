#pragma once
#ifdef PKMDS_CMAKE_USED
#include <pkmds/stdafx.h>
#else
#include "stdafx.h"
#endif
struct pkmprng
{
    uint32 mseed;
    DllExport uint32 previous()
	{
		return 0xeeb9eb65 * mseed + 0xa3561a1;
	}
    DllExport uint32 previousnum()
	{
		mseed = previous();
		return mseed;
	}
    DllExport uint32 next()
	{
		return (0x41c64e6d * mseed) + 0x6073;
	}
    DllExport uint32 nextnum()
	{
		mseed = next();
		return mseed;
	}
};
