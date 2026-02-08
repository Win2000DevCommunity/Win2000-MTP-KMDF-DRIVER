/*
 * security_stub.c - Stub for buffer security checks not available in Windows 2000
 * 
 * The KMDF 1.9 WdfDriverEntry.lib was compiled with /GS (buffer security checks)
 * which requires __security_init_cookie. Windows 2000 doesn't have this function,
 * so we provide a minimal stub.
 */

#include <ntddk.h>

// Global security cookie (normally initialized by CRT)
DECLSPEC_SELECTANY ULONG_PTR __security_cookie = 0xBB40E64E;

// Security cookie initialization stub
VOID
__cdecl
__security_init_cookie(VOID)
{
    // On Windows 2000, we just use a static cookie value
    // Real implementation would use random number generation
    __security_cookie = 0xBB40E64E;
}
