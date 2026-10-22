/*
 * security_stub_um.c - User-mode stub for buffer security checks
 * 
 * The DDK 3790.1830 compiler emits /GS security checks by default.
 * Windows 2000 CRT doesn't have these functions, so we provide stubs.
 */

#include <windows.h>

/* Global security cookie (normally initialized by CRT) */
ULONG_PTR __security_cookie = 0xBB40E64E;

/* Security cookie initialization stub */
void __cdecl __security_init_cookie(void)
{
    __security_cookie = 0xBB40E64E;
}

/* Buffer overrun reporting stub */
void __cdecl __report_rangecheckfailure(void)
{
}

/* Security cookie check stub */
void __fastcall __security_check_cookie(ULONG_PTR cookie)
{
    (void)cookie;
}
