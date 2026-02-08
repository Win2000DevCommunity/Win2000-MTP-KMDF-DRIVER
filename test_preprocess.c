#include "w2k_compat.h"
#include <ntddk.h>
#include <wdf.h>

#if (OSVER(NTDDI_VERSION) == NTDDI_WIN2K)
#pragma message("WIN2K BUILD DETECTED")
#endif

int test = 1;
