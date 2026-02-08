/*
 * security_cookie.c - Security cookie stub for Windows 2000 DDK
 */

unsigned long __security_cookie = 0xBB40E64E;

void __fastcall __security_check_cookie(unsigned long cookie)
{
    /* Stub - no actual security check on Windows 2000 */
    (void)cookie;
}
