#line 1 "Usb.c"




#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"
#pragma once








#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\driverspecs.h"
#pragma once



#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\specstrings.h"
#pragma once



































































































































#line 134 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\specstrings.h"
#line 6 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\driverspecs.h"



































#line 42 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\driverspecs.h"
#line 11 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"




#line 16 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"







#line 24 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"





#line 30 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 34 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 38 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 42 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 46 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 50 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 54 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 58 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"




#line 63 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 67 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"




#line 72 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"



#line 76 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"




typedef struct _GROUP_AFFINITY {
    ULONG_PTR Mask;
    USHORT Group;
    USHORT Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY;
#line 86 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"




typedef struct _WDF_INTERRUPT_EXTENDED_POLICY WDF_INTERRUPT_EXTENDED_POLICY, *PWDF_INTERRUPT_EXTENDED_POLICY;
#line 92 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\w2k_compat.h"
#line 6 "Usb.c"
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"























#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"















#pragma once
#line 18 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"






#line 25 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"







#pragma pack(push,8)
#line 34 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"














#line 49 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"
#line 50 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"






#line 57 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"





typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;






struct _EXCEPTION_RECORD;
struct _CONTEXT;
typedef struct _EXCEPTION_POINTERS *Exception_info_ptr;
struct _DISPATCHER_CONTEXT;



EXCEPTION_DISPOSITION __cdecl _except_handler (
    struct _EXCEPTION_RECORD *ExceptionRecord,
    void * EstablisherFrame,
    struct _CONTEXT *ContextRecord,
    void * DispatcherContext
    );





















#line 109 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"















unsigned long __cdecl _exception_code(void);
void *        __cdecl _exception_info(void);
int           __cdecl _abnormal_termination(void);

#line 129 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"

















#pragma pack(pop)
#line 148 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"

#line 150 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\excpt.h"

#line 25 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
























#pragma once
#line 27 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"














#pragma once
#line 17 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"






#line 24 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"























#line 48 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"


typedef unsigned short wchar_t;

#line 53 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"


typedef unsigned short wint_t;
typedef unsigned short wctype_t;

#line 59 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"



#line 63 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"


























                                













__declspec(dllimport) int __cdecl _isctype(int, int);
__declspec(dllimport) int __cdecl isalpha(int);
__declspec(dllimport) int __cdecl isupper(int);
__declspec(dllimport) int __cdecl islower(int);
__declspec(dllimport) int __cdecl isdigit(int);
__declspec(dllimport) int __cdecl isxdigit(int);
__declspec(dllimport) int __cdecl isspace(int);
__declspec(dllimport) int __cdecl ispunct(int);
__declspec(dllimport) int __cdecl isalnum(int);
__declspec(dllimport) int __cdecl isprint(int);
__declspec(dllimport) int __cdecl isgraph(int);
__declspec(dllimport) int __cdecl iscntrl(int);
__declspec(dllimport) int __cdecl toupper(int);
__declspec(dllimport) int __cdecl tolower(int);
__declspec(dllimport) int __cdecl _tolower(int);
__declspec(dllimport) int __cdecl _toupper(int);
__declspec(dllimport) int __cdecl __isascii(int);
__declspec(dllimport) int __cdecl __toascii(int);
__declspec(dllimport) int __cdecl __iscsymf(int);
__declspec(dllimport) int __cdecl __iscsym(int);

#line 125 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"







__declspec(dllimport) int __cdecl iswalpha(wint_t);
__declspec(dllimport) int __cdecl iswupper(wint_t);
__declspec(dllimport) int __cdecl iswlower(wint_t);
__declspec(dllimport) int __cdecl iswdigit(wint_t);
__declspec(dllimport) int __cdecl iswxdigit(wint_t);
__declspec(dllimport) int __cdecl iswspace(wint_t);
__declspec(dllimport) int __cdecl iswpunct(wint_t);
__declspec(dllimport) int __cdecl iswalnum(wint_t);
__declspec(dllimport) int __cdecl iswprint(wint_t);
__declspec(dllimport) int __cdecl iswgraph(wint_t);
__declspec(dllimport) int __cdecl iswcntrl(wint_t);
__declspec(dllimport) int __cdecl iswascii(wint_t);
__declspec(dllimport) int __cdecl isleadbyte(int);

__declspec(dllimport) wchar_t __cdecl towupper(wchar_t);
__declspec(dllimport) wchar_t __cdecl towlower(wchar_t);

__declspec(dllimport) int __cdecl iswctype(wint_t, wctype_t);


__declspec(dllimport) int __cdecl is_wctype(wint_t, wctype_t);



#line 157 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"














































































































































#line 300 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"

#line 302 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"






#line 309 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\ctype.h"

#line 29 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"


     







#line 40 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"







#line 48 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 52 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 56 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 60 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 64 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 68 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"







#line 76 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 78 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"








#line 87 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"


#line 90 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"




#line 95 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 97 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"









#line 107 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"






#line 114 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 118 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"


















#line 137 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 141 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

typedef unsigned long POINTER_64_INT;
#line 144 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 146 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 150 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 152 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"
























#pragma once
#line 27 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"









typedef int LONG32, *PLONG32;
typedef int INT32, *PINT32;





typedef unsigned int ULONG32, *PULONG32;
typedef unsigned int DWORD32, *PDWORD32;
typedef unsigned int UINT32, *PUINT32;






#line 53 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"
#line 54 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"

















#line 72 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"











#line 84 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"
    typedef __w64 int INT_PTR, *PINT_PTR;
    typedef __w64 unsigned int UINT_PTR, *PUINT_PTR;

    typedef __w64 long LONG_PTR, *PLONG_PTR;
    typedef __w64 unsigned long ULONG_PTR, *PULONG_PTR;

    

#line 93 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"
#line 94 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"


























































































































































typedef unsigned short UHALF_PTR, *PUHALF_PTR;
typedef short HALF_PTR, *PHALF_PTR;
typedef __w64 unsigned long HANDLE_PTR;















#line 267 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"





















typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef LONG_PTR SSIZE_T, *PSSIZE_T;





typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;





typedef __int64 LONG64, *PLONG64;
typedef __int64 INT64,  *PINT64;






typedef unsigned __int64 ULONG64, *PULONG64;
typedef unsigned __int64 DWORD64, *PDWORD64;
typedef unsigned __int64 UINT64,  *PUINT64;





#line 318 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\basetsd.h"

#line 154 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"





#line 160 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"







#line 168 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"






#line 175 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 176 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"






#line 183 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 184 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"




#line 189 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 191 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 192 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"




#line 197 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 199 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 200 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"






#line 207 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 208 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"






#line 215 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 216 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"




#line 221 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

#line 223 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 224 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"






#line 231 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 232 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"








typedef void *PVOID;
typedef void *  PVOID64;







#line 250 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"










#line 261 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
















#line 278 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"











typedef char CHAR;
typedef short SHORT;
typedef long LONG;
#line 293 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"






typedef wchar_t WCHAR;    



#line 304 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

typedef WCHAR *PWCHAR;
typedef WCHAR *LPWCH, *PWCH;
typedef const WCHAR *LPCWCH, *PCWCH;
typedef WCHAR *NWPSTR;
typedef WCHAR *LPWSTR, *PWSTR;

typedef const WCHAR *LPCWSTR, *PCWSTR;




typedef CHAR *PCHAR;
typedef CHAR *LPCH, *PCH;

typedef const CHAR *LPCCH, *PCCH;
typedef CHAR *NPSTR;
typedef CHAR *LPSTR, *PSTR;
typedef const CHAR *LPCSTR, *PCSTR;





















typedef char TCHAR, *PTCHAR;
typedef unsigned char TUCHAR, *PTUCHAR;

#line 348 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

typedef LPSTR LPTCH, PTCH;
typedef LPSTR PTSTR, LPTSTR;
typedef LPCSTR PCTSTR, LPCTSTR;


#line 355 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"





typedef double DOUBLE;

typedef struct _QUAD {              
    double  DoNotUseThisField;      
} QUAD;                             
                                    
                                    





typedef SHORT *PSHORT;  
typedef LONG *PLONG;    
typedef QUAD *PQUAD;








typedef unsigned char UCHAR;
typedef unsigned short USHORT;
typedef unsigned long ULONG;
typedef QUAD UQUAD;





typedef UCHAR *PUCHAR;
typedef USHORT *PUSHORT;
typedef ULONG *PULONG;
typedef UQUAD *PUQUAD;





typedef signed char SCHAR;
typedef SCHAR *PSCHAR;




#line 408 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 409 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"








typedef void *HANDLE;




#line 423 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
typedef HANDLE *PHANDLE;





typedef UCHAR  FCHAR;
typedef USHORT FSHORT;
typedef ULONG  FLONG;





typedef LONG HRESULT;

#line 440 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"




    
#line 446 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"









#line 456 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"













#line 470 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"































typedef char CCHAR;          
typedef short CSHORT;
typedef ULONG CLONG;

typedef CCHAR *PCCHAR;
typedef CSHORT *PCSHORT;
typedef CLONG *PCLONG;







typedef ULONG LCID;         
typedef PULONG PLCID;       
typedef USHORT LANGID;      





typedef ULONG LOGICAL;
typedef ULONG *PLOGICAL;






typedef LONG NTSTATUS;
  
typedef NTSTATUS *PNTSTATUS;
  

























































































#line 625 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
typedef struct _FLOAT128 {
    __int64 LowPart;
    __int64 HighPart;
} FLOAT128;

typedef FLOAT128 *PFLOAT128;













typedef __int64 LONGLONG;
typedef unsigned __int64 ULONGLONG;














#line 661 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"

typedef LONGLONG *PLONGLONG;
typedef ULONGLONG *PULONGLONG;



typedef LONGLONG USN;



#line 672 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
typedef union _LARGE_INTEGER {
    struct {
        ULONG LowPart;
        LONG HighPart;
    };
    struct {
        ULONG LowPart;
        LONG HighPart;
    } u;
#line 682 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
    LONGLONG QuadPart;
} LARGE_INTEGER;

typedef LARGE_INTEGER *PLARGE_INTEGER;




#line 691 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
typedef union _ULARGE_INTEGER {
    struct {
        ULONG LowPart;
        ULONG HighPart;
    };
    struct {
        ULONG LowPart;
        ULONG HighPart;
    } u;
#line 701 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
    ULONGLONG QuadPart;
} ULARGE_INTEGER;

typedef ULARGE_INTEGER *PULARGE_INTEGER;








typedef struct _LUID {
    ULONG LowPart;
    LONG HighPart;
} LUID, *PLUID;


typedef ULONGLONG  DWORDLONG;
typedef DWORDLONG *PDWORDLONG;









typedef LARGE_INTEGER PHYSICAL_ADDRESS, *PPHYSICAL_ADDRESS;

























#line 757 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"































































#line 821 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"











ULONGLONG
__stdcall
Int64ShllMod32 (
    ULONGLONG Value,
    ULONG ShiftCount
    );

LONGLONG
__stdcall
Int64ShraMod32 (
    LONGLONG Value,
    ULONG ShiftCount
    );

ULONGLONG
__stdcall
Int64ShrlMod32 (
    ULONGLONG Value,
    ULONG ShiftCount
    );


#pragma warning(push)
#line 856 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#pragma warning(disable:4035)               

__inline ULONGLONG
__stdcall
Int64ShllMod32 (
    ULONGLONG Value,
    ULONG ShiftCount
    )
{
    __asm    {
        mov     ecx, ShiftCount
        mov     eax, dword ptr [Value]
        mov     edx, dword ptr [Value+4]
        shld    edx, eax, cl
        shl     eax, cl
    }
}

__inline LONGLONG
__stdcall
Int64ShraMod32 (
    LONGLONG Value,
    ULONG ShiftCount
    )
{
    __asm {
        mov     ecx, ShiftCount
        mov     eax, dword ptr [Value]
        mov     edx, dword ptr [Value+4]
        shrd    eax, edx, cl
        sar     edx, cl
    }
}

__inline ULONGLONG
__stdcall
Int64ShrlMod32 (
    ULONGLONG Value,
    ULONG ShiftCount
    )
{
    __asm    {
        mov     ecx, ShiftCount
        mov     eax, dword ptr [Value]
        mov     edx, dword ptr [Value+4]
        shrd    eax, edx, cl
        shr     edx, cl
    }
}


#pragma warning(pop)


#line 911 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"




























































#line 972 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"







typedef enum _EVENT_TYPE {
    NotificationEvent,
    SynchronizationEvent
    } EVENT_TYPE;





typedef enum _TIMER_TYPE {
    NotificationTimer,
    SynchronizationTimer
    } TIMER_TYPE;





typedef enum _WAIT_TYPE {
    WaitAll,
    WaitAny
    } WAIT_TYPE;





typedef CHAR *PSZ;
typedef const char *PCSZ;






typedef struct _STRING {
    USHORT Length;
    USHORT MaximumLength;



    PCHAR Buffer;
} STRING;
typedef STRING *PSTRING;

typedef STRING ANSI_STRING;
typedef PSTRING PANSI_STRING;

typedef STRING OEM_STRING;
typedef PSTRING POEM_STRING;





typedef struct _CSTRING {
    USHORT Length;
    USHORT MaximumLength;
    const char *Buffer;
} CSTRING;
typedef CSTRING *PCSTRING;


typedef STRING CANSI_STRING;
typedef PSTRING PCANSI_STRING;






typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;



    PWSTR  Buffer;
#line 1058 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
} UNICODE_STRING;
typedef UNICODE_STRING *PUNICODE_STRING;
typedef const UNICODE_STRING *PCUNICODE_STRING;








typedef UCHAR BOOLEAN;           
typedef BOOLEAN *PBOOLEAN;       









typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, * PRLIST_ENTRY;






typedef struct _SINGLE_LIST_ENTRY {
    struct _SINGLE_LIST_ENTRY *Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY;








typedef struct LIST_ENTRY32 {
    ULONG Flink;
    ULONG Blink;
} LIST_ENTRY32;
typedef LIST_ENTRY32 *PLIST_ENTRY32;

typedef struct LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
} LIST_ENTRY64;
typedef LIST_ENTRY64 *PLIST_ENTRY64;





__inline
void
ListEntry32To64(
     PLIST_ENTRY32 l32,
     PLIST_ENTRY64 l64
    )
{
    l64->Flink = (ULONGLONG)(LONGLONG)(LONG)l32->Flink;
    l64->Blink = (ULONGLONG)(LONGLONG)(LONG)l32->Blink;
}

__inline
void
ListEntry64To32(
     PLIST_ENTRY64 l64,
     PLIST_ENTRY32 l32
    )
{
    l32->Flink = (ULONG)l64->Flink;
    l32->Blink = (ULONG)l64->Blink;
}
#line 1139 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"











typedef struct _STRING32 {
    USHORT   Length;
    USHORT   MaximumLength;
    ULONG  Buffer;
} STRING32;
typedef STRING32 *PSTRING32;

typedef STRING32 UNICODE_STRING32;
typedef UNICODE_STRING32 *PUNICODE_STRING32;

typedef STRING32 ANSI_STRING32;
typedef ANSI_STRING32 *PANSI_STRING32;


typedef struct _STRING64 {
    USHORT   Length;
    USHORT   MaximumLength;
    ULONGLONG  Buffer;
} STRING64;
typedef STRING64 *PSTRING64;

typedef STRING64 UNICODE_STRING64;
typedef UNICODE_STRING64 *PUNICODE_STRING64;

typedef STRING64 ANSI_STRING64;
typedef ANSI_STRING64 *PANSI_STRING64;




















typedef struct _OBJECT_ATTRIBUTES {
    ULONG Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;        
    PVOID SecurityQualityOfService;  
} OBJECT_ATTRIBUTES;
typedef OBJECT_ATTRIBUTES *POBJECT_ATTRIBUTES;







































#line 1245 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
#line 1246 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"





#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"



















#line 21 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[ 8 ];
} GUID;

#line 29 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 30 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"







#line 38 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 39 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"




























#line 68 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"








typedef GUID *LPGUID;
#line 78 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"



typedef const GUID *LPCGUID;
#line 83 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"




typedef GUID IID;
typedef IID *LPIID;


typedef GUID CLSID;
typedef CLSID *LPCLSID;


typedef GUID FMTID;
typedef FMTID *LPFMTID;







#line 105 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"







#line 113 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 114 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"







#line 122 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 123 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"







#line 131 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 132 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"







#line 140 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 141 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"

#line 143 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"




#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"















#pragma once
#line 18 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"






#line 25 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"













#line 39 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"















#line 55 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"






typedef __w64 unsigned int   size_t;
#line 63 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"

#line 65 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"










#line 76 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"















        void *  __cdecl memcpy(void *, const void *, size_t);
#line 93 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"
        int     __cdecl memcmp(const void *, const void *, size_t);
        void *  __cdecl memset(void *, int, size_t);
        char *  __cdecl _strset(char *, int);
        char *  __cdecl strcpy(char *, const char *);
        char *  __cdecl strcat(char *, const char *);
        int     __cdecl strcmp(const char *, const char *);
        size_t  __cdecl strlen(const char *);
__declspec(dllimport) void *  __cdecl _memccpy(void *, const void *, int, size_t);
__declspec(dllimport) void *  __cdecl memchr(const void *, int, size_t);
__declspec(dllimport) int     __cdecl _memicmp(const void *, const void *, size_t);



#line 107 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"
__declspec(dllimport) void *  __cdecl memmove(void *, const void *, size_t);
#line 109 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"

__declspec(dllimport) char *  __cdecl strchr(const char *, int);
__declspec(dllimport) int     __cdecl _strcmpi(const char *, const char *);
__declspec(dllimport) int     __cdecl _stricmp(const char *, const char *);
__declspec(dllimport) int     __cdecl strcoll(const char *, const char *);
__declspec(dllimport) int     __cdecl _stricoll(const char *, const char *);
__declspec(dllimport) int     __cdecl _strncoll(const char *, const char *, size_t);
__declspec(dllimport) int     __cdecl _strnicoll(const char *, const char *, size_t);
__declspec(dllimport) size_t  __cdecl strcspn(const char *, const char *);
__declspec(dllimport) char *  __cdecl _strdup(const char *);
__declspec(dllimport) char *  __cdecl _strerror(const char *);
__declspec(dllimport) char *  __cdecl strerror(int);
__declspec(dllimport) char *  __cdecl _strlwr(char *);
__declspec(dllimport) char *  __cdecl strncat(char *, const char *, size_t);
__declspec(dllimport) int     __cdecl strncmp(const char *, const char *, size_t);
__declspec(dllimport) int     __cdecl _strnicmp(const char *, const char *, size_t);
__declspec(dllimport) char *  __cdecl strncpy(char *, const char *, size_t);
__declspec(dllimport) char *  __cdecl _strnset(char *, int, size_t);
__declspec(dllimport) char *  __cdecl strpbrk(const char *, const char *);
__declspec(dllimport) char *  __cdecl strrchr(const char *, int);
__declspec(dllimport) char *  __cdecl _strrev(char *);
__declspec(dllimport) size_t  __cdecl strspn(const char *, const char *);
__declspec(dllimport) char *  __cdecl strstr(const char *, const char *);
__declspec(dllimport) char *  __cdecl strtok(char *, const char *);
__declspec(dllimport) char *  __cdecl _strupr(char *);
__declspec(dllimport) size_t  __cdecl strxfrm (char *, const char *, size_t);





__declspec(dllimport) void * __cdecl memccpy(void *, const void *, int, size_t);
__declspec(dllimport) int __cdecl memicmp(const void *, const void *, size_t);
__declspec(dllimport) int __cdecl strcmpi(const char *, const char *);
__declspec(dllimport) int __cdecl stricmp(const char *, const char *);
__declspec(dllimport) char * __cdecl strdup(const char *);
__declspec(dllimport) char * __cdecl strlwr(char *);
__declspec(dllimport) int __cdecl strnicmp(const char *, const char *, size_t);
__declspec(dllimport) char * __cdecl strnset(char *, int, size_t);
__declspec(dllimport) char * __cdecl strrev(char *);
        char * __cdecl strset(char *, int);
__declspec(dllimport) char * __cdecl strupr(char *);

#line 153 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"






__declspec(dllimport) wchar_t * __cdecl wcscat(wchar_t *, const wchar_t *);
__declspec(dllimport) wchar_t * __cdecl wcschr(const wchar_t *, wchar_t);
__declspec(dllimport) int __cdecl wcscmp(const wchar_t *, const wchar_t *);
__declspec(dllimport) wchar_t * __cdecl wcscpy(wchar_t *, const wchar_t *);
__declspec(dllimport) size_t __cdecl wcscspn(const wchar_t *, const wchar_t *);
__declspec(dllimport) size_t __cdecl wcslen(const wchar_t *);
__declspec(dllimport) wchar_t * __cdecl wcsncat(wchar_t *, const wchar_t *, size_t);
__declspec(dllimport) int __cdecl wcsncmp(const wchar_t *, const wchar_t *, size_t);
__declspec(dllimport) wchar_t * __cdecl wcsncpy(wchar_t *, const wchar_t *, size_t);
__declspec(dllimport) wchar_t * __cdecl wcspbrk(const wchar_t *, const wchar_t *);
__declspec(dllimport) wchar_t * __cdecl wcsrchr(const wchar_t *, wchar_t);
__declspec(dllimport) size_t __cdecl wcsspn(const wchar_t *, const wchar_t *);
__declspec(dllimport) wchar_t * __cdecl wcsstr(const wchar_t *, const wchar_t *);
__declspec(dllimport) wchar_t * __cdecl wcstok(wchar_t *, const wchar_t *);
__declspec(dllimport) wchar_t * __cdecl _wcserror(int);
__declspec(dllimport) wchar_t * __cdecl __wcserror(const wchar_t *);

__declspec(dllimport) wchar_t * __cdecl _wcsdup(const wchar_t *);
__declspec(dllimport) int __cdecl _wcsicmp(const wchar_t *, const wchar_t *);
__declspec(dllimport) int __cdecl _wcsnicmp(const wchar_t *, const wchar_t *, size_t);
__declspec(dllimport) wchar_t * __cdecl _wcsnset(wchar_t *, wchar_t, size_t);
__declspec(dllimport) wchar_t * __cdecl _wcsrev(wchar_t *);
__declspec(dllimport) wchar_t * __cdecl _wcsset(wchar_t *, wchar_t);

__declspec(dllimport) wchar_t * __cdecl _wcslwr(wchar_t *);
__declspec(dllimport) wchar_t * __cdecl _wcsupr(wchar_t *);
__declspec(dllimport) size_t __cdecl wcsxfrm(wchar_t *, const wchar_t *, size_t);
__declspec(dllimport) int __cdecl wcscoll(const wchar_t *, const wchar_t *);
__declspec(dllimport) int __cdecl _wcsicoll(const wchar_t *, const wchar_t *);
__declspec(dllimport) int __cdecl _wcsncoll(const wchar_t *, const wchar_t *, size_t);
__declspec(dllimport) int __cdecl _wcsnicoll(const wchar_t *, const wchar_t *, size_t);







__declspec(dllimport) wchar_t * __cdecl wcsdup(const wchar_t *);
__declspec(dllimport) int __cdecl wcsicmp(const wchar_t *, const wchar_t *);
__declspec(dllimport) int __cdecl wcsnicmp(const wchar_t *, const wchar_t *, size_t);
__declspec(dllimport) wchar_t * __cdecl wcsnset(wchar_t *, wchar_t, size_t);
__declspec(dllimport) wchar_t * __cdecl wcsrev(wchar_t *);
__declspec(dllimport) wchar_t * __cdecl wcsset(wchar_t *, wchar_t);
__declspec(dllimport) wchar_t * __cdecl wcslwr(wchar_t *);
__declspec(dllimport) wchar_t * __cdecl wcsupr(wchar_t *);
__declspec(dllimport) int __cdecl wcsicoll(const wchar_t *, const wchar_t *);

#line 208 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"


#line 211 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"























#line 235 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"





#line 241 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\crt\\string.h"

#line 148 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"



























#line 176 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"



























#line 204 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 205 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 206 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"
#line 207 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"

#line 1252 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"




typedef struct  _OBJECTID {     
    GUID Lineage;
    ULONG Uniquifier;
} OBJECTID;
#line 1261 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"


















































struct _CONTEXT;
struct _EXCEPTION_RECORD;

typedef
EXCEPTION_DISPOSITION
(*PEXCEPTION_ROUTINE) (
     struct _EXCEPTION_RECORD *ExceptionRecord,
     PVOID EstablisherFrame,
      struct _CONTEXT *ContextRecord,
      PVOID DispatcherContext
    );







typedef UCHAR KIRQL;

typedef KIRQL *PKIRQL;







typedef enum _NT_PRODUCT_TYPE {
    NtProductWinNt = 1,
    NtProductLanManNt,
    NtProductServer
} NT_PRODUCT_TYPE, *PNT_PRODUCT_TYPE;








typedef enum _SUITE_TYPE {
    SmallBusiness,
    Enterprise,
    BackOffice,
    CommunicationServer,
    TerminalServer,
    SmallBusinessRestricted,
    EmbeddedNT,
    DataCenter,
    SingleUserTS,
    Personal,
    MaxSuiteType
} SUITE_TYPE;








































































































































































































































































































































































#line 1726 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"
























#line 1751 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"



#line 1755 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntdef.h"


#line 26 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntstatus.h"

































  










































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































  


#line 8721 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntstatus.h"
#line 8722 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntstatus.h"


#line 27 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\bugcodes.h"
































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 2370 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\bugcodes.h"


#line 28 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\ntiologc.h"














































































































































































































































































































































































































































































































































































































































#line 624 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\ntiologc.h"

#line 29 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"














































typedef struct _KTHREAD *PKTHREAD;
typedef struct _ETHREAD *PETHREAD;
typedef struct _EPROCESS *PEPROCESS;
typedef struct _PEB *PPEB;
typedef struct _KINTERRUPT *PKINTERRUPT;
typedef struct _IO_TIMER *PIO_TIMER;
typedef struct _OBJECT_TYPE *POBJECT_TYPE;
typedef struct _CALLBACK_OBJECT *PCALLBACK_OBJECT;
typedef struct _DEVICE_HANDLER_OBJECT *PDEVICE_HANDLER_OBJECT;
typedef struct _BUS_HANDLER *PBUS_HANDLER;













#line 99 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


PKTHREAD __stdcall KeGetCurrentThread();
#line 103 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

















#line 121 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



extern PCCHAR KeNumberProcessors;
















#line 142 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

typedef union _SLIST_HEADER {
    ULONGLONG Alignment;
    struct {
        SINGLE_LIST_ENTRY Next;
        USHORT Depth;
        USHORT Sequence;
    };
} SLIST_HEADER, *PSLIST_HEADER;

#line 153 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




























#line 182 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




extern ULONG NtGlobalFlag;






#line 194 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"










typedef CCHAR KPROCESSOR_MODE;

typedef enum _MODE {
    KernelMode,
    UserMode,
    MaximumMode
} MODE;











struct _KAPC;

typedef
void
(*PKNORMAL_ROUTINE) (
     PVOID NormalContext,
     PVOID SystemArgument1,
     PVOID SystemArgument2
    );

typedef
void
(*PKKERNEL_ROUTINE) (
     struct _KAPC *Apc,
      PKNORMAL_ROUTINE *NormalRoutine,
      PVOID *NormalContext,
      PVOID *SystemArgument1,
      PVOID *SystemArgument2
    );

typedef
void
(*PKRUNDOWN_ROUTINE) (
     struct _KAPC *Apc
    );

typedef
BOOLEAN
(*PKSYNCHRONIZE_ROUTINE) (
     PVOID SynchronizeContext
    );

typedef
BOOLEAN
(*PKTRANSFER_ROUTINE) (
    void
    );






typedef struct _KAPC {
    CSHORT Type;
    CSHORT Size;
    ULONG Spare0;
    struct _KTHREAD *Thread;
    LIST_ENTRY ApcListEntry;
    PKKERNEL_ROUTINE KernelRoutine;
    PKRUNDOWN_ROUTINE RundownRoutine;
    PKNORMAL_ROUTINE NormalRoutine;
    PVOID NormalContext;

    
    
    

    PVOID SystemArgument1;
    PVOID SystemArgument2;
    CCHAR ApcStateIndex;
    KPROCESSOR_MODE ApcMode;
    BOOLEAN Inserted;
} KAPC, *PKAPC, * PRKAPC;






struct _KDPC;

typedef
void
(*PKDEFERRED_ROUTINE) (
     struct _KDPC *Dpc,
     PVOID DeferredContext,
     PVOID SystemArgument1,
     PVOID SystemArgument2
    );

















































typedef enum _KDPC_IMPORTANCE {
    LowImportance,
    MediumImportance,
    HighImportance
} KDPC_IMPORTANCE;





typedef struct _KDPC {
    CSHORT Type;
    UCHAR Number;
    UCHAR Importance;
    LIST_ENTRY DpcListEntry;
    PKDEFERRED_ROUTINE DeferredRoutine;
    PVOID DeferredContext;
    PVOID SystemArgument1;
    PVOID SystemArgument2;
    PULONG_PTR Lock;
} KDPC, *PKDPC, * PRKDPC;





typedef PVOID PKIPI_CONTEXT;

typedef
void
(*PKIPI_WORKER)(
     PKIPI_CONTEXT PacketContext,
     PVOID Parameter1,
     PVOID Parameter2,
     PVOID Parameter3
    );





typedef struct _KIPI_COUNTS {
    ULONG Freeze;
    ULONG Packet;
    ULONG DPC;
    ULONG APC;
    ULONG FlushSingleTb;
    ULONG FlushMultipleTb;
    ULONG FlushEntireTb;
    ULONG GenericCall;
    ULONG ChangeColor;
    ULONG SweepDcache;
    ULONG SweepIcache;
    ULONG SweepIcacheRange;
    ULONG FlushIoBuffers;
    ULONG GratuitousDPC;
} KIPI_COUNTS, *PKIPI_COUNTS;









#line 418 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

























typedef struct _MDL {
    struct _MDL *Next;
    CSHORT Size;
    CSHORT MdlFlags;
    struct _EPROCESS *Process;
    PVOID MappedSystemVa;
    PVOID StartVa;
    ULONG ByteCount;
    ULONG ByteOffset;
} MDL, *PMDL;








































#line 494 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"















#line 510 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"














#line 525 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"







typedef PVOID PACCESS_TOKEN;            





typedef PVOID PSECURITY_DESCRIPTOR;     





typedef PVOID PSID;     

typedef ULONG ACCESS_MASK;
typedef ACCESS_MASK *PACCESS_MASK;

















































typedef struct _GENERIC_MAPPING {
    ACCESS_MASK GenericRead;
    ACCESS_MASK GenericWrite;
    ACCESS_MASK GenericExecute;
    ACCESS_MASK GenericAll;
} GENERIC_MAPPING;
typedef GENERIC_MAPPING *PGENERIC_MAPPING;












#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"























#pragma warning(disable:4103)

#pragma pack(push,4)


#line 30 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"
#line 34 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"

#line 617 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

typedef struct _LUID_AND_ATTRIBUTES {
    LUID Luid;
    ULONG Attributes;
    } LUID_AND_ATTRIBUTES, * PLUID_AND_ATTRIBUTES;
typedef LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES_ARRAY[1];
typedef LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;

#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


#line 36 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"
#line 37 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"

#line 626 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
















typedef struct _ACL {
    UCHAR AclRevision;
    UCHAR Sbz1;
    USHORT AclSize;
    USHORT AceCount;
    USHORT Sbz2;
} ACL;
typedef ACL *PACL;































typedef struct _PRIVILEGE_SET {
    ULONG PrivilegeCount;
    ULONG Control;
    LUID_AND_ATTRIBUTES Privilege[1];
    } PRIVILEGE_SET, * PPRIVILEGE_SET;



















































typedef enum _SECURITY_IMPERSONATION_LEVEL {
    SecurityAnonymous,
    SecurityIdentification,
    SecurityImpersonation,
    SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL, * PSECURITY_IMPERSONATION_LEVEL;












typedef BOOLEAN SECURITY_CONTEXT_TRACKING_MODE,
                    * PSECURITY_CONTEXT_TRACKING_MODE;







typedef struct _SECURITY_QUALITY_OF_SERVICE {
    ULONG Length;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    SECURITY_CONTEXT_TRACKING_MODE ContextTrackingMode;
    BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_OF_SERVICE, * PSECURITY_QUALITY_OF_SERVICE;






typedef struct _SE_IMPERSONATION_STATE {
    PACCESS_TOKEN Token;
    BOOLEAN CopyOnOpen;
    BOOLEAN EffectiveOnly;
    SECURITY_IMPERSONATION_LEVEL Level;
} SE_IMPERSONATION_STATE, *PSE_IMPERSONATION_STATE;


typedef ULONG SECURITY_INFORMATION, *PSECURITY_INFORMATION;


























typedef ULONG KAFFINITY;
typedef KAFFINITY *PKAFFINITY;





typedef LONG KPRIORITY;







typedef ULONG_PTR KSPIN_LOCK;
typedef KSPIN_LOCK *PKSPIN_LOCK;







typedef
void
(*PKINTERRUPT_ROUTINE) (
    void
    );




typedef enum _KPROFILE_SOURCE {
    ProfileTime,
    ProfileAlignmentFixup,
    ProfileTotalIssues,
    ProfilePipelineDry,
    ProfileLoadInstructions,
    ProfilePipelineFrozen,
    ProfileBranchInstructions,
    ProfileTotalNonissues,
    ProfileDcacheMisses,
    ProfileIcacheMisses,
    ProfileCacheMisses,
    ProfileBranchMispredictions,
    ProfileStoreInstructions,
    ProfileFpInstructions,
    ProfileIntegerInstructions,
    Profile2Issue,
    Profile3Issue,
    Profile4Issue,
    ProfileSpecialInstructions,
    ProfileTotalCycles,
    ProfileIcacheIssues,
    ProfileDcacheAccesses,
    ProfileMemoryBarrierCycles,
    ProfileLoadLinkedIssues,
    ProfileMaximum
} KPROFILE_SOURCE;










#line 882 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"







__declspec(dllimport)
void
__stdcall
RtlAssert(
    PVOID FailedAssertion,
    PVOID FileName,
    ULONG LineNumber,
    PCHAR Message
    );












#line 911 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




















































































































































#line 1060 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
__declspec(dllimport)
void
__stdcall
RtlGetCallersAddress(
     PVOID *CallersAddress,
     PVOID *CallersCaller
    );
#line 1068 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
ULONG
__stdcall
RtlWalkFrameChain (
     PVOID *Callers,
     ULONG Count,
     ULONG Flags);





typedef NTSTATUS (__stdcall * PRTL_QUERY_REGISTRY_ROUTINE)(
     PWSTR ValueName,
     ULONG ValueType,
     PVOID ValueData,
     ULONG ValueLength,
     PVOID Context,
     PVOID EntryContext
    );

typedef struct _RTL_QUERY_REGISTRY_TABLE {
    PRTL_QUERY_REGISTRY_ROUTINE QueryRoutine;
    ULONG Flags;
    PWSTR Name;
    PVOID EntryContext;
    ULONG DefaultType;
    PVOID DefaultData;
    ULONG DefaultLength;

} RTL_QUERY_REGISTRY_TABLE, *PRTL_QUERY_REGISTRY_TABLE;








                                                
                                                


                                                


                                                


                                                
                                                


                                                
                                                
                                                


                                                
                                                
                                                
                                                
                                                
                                                
                                                


                                                

__declspec(dllimport)
NTSTATUS
__stdcall
RtlQueryRegistryValues(
     ULONG RelativeTo,
     PCWSTR Path,
     PRTL_QUERY_REGISTRY_TABLE QueryTable,
     PVOID Context,
     PVOID Environment 
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlWriteRegistryValue(
     ULONG RelativeTo,
     PCWSTR Path,
     PCWSTR ValueName,
     ULONG ValueType,
     PVOID ValueData,
     ULONG ValueLength
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlDeleteRegistryValue(
     ULONG RelativeTo,
     PCWSTR Path,
     PCWSTR ValueName
    );



__declspec(dllimport)
NTSTATUS
__stdcall
RtlCreateRegistryKey(
     ULONG RelativeTo,
     PWSTR Path
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlCheckRegistryKey(
     ULONG RelativeTo,
     PWSTR Path
    );

















__declspec(dllimport)                                            
NTSTATUS                                            
__stdcall                                               
RtlCharToInteger (                                  
    PCSZ String,                                    
    ULONG Base,                                     
    PULONG Value                                    
    );                                              

__declspec(dllimport)
NTSTATUS
__stdcall
RtlIntegerToUnicodeString (
    ULONG Value,
    ULONG Base,
    PUNICODE_STRING String
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlInt64ToUnicodeString (
     ULONGLONG Value,
     ULONG Base ,
      PUNICODE_STRING String
    );





#line 1236 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
NTSTATUS
__stdcall
RtlUnicodeStringToInteger (
    PUNICODE_STRING String,
    ULONG Base,
    PULONG Value
    );
















#line 1262 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

extern BOOLEAN (*NlsMbCodePageTag);     
extern BOOLEAN (*NlsMbOemCodePageTag); 

__declspec(dllimport)
void
__stdcall
RtlInitString(
    PSTRING DestinationString,
    PCSZ SourceString
    );

__declspec(dllimport)
void
__stdcall
RtlInitAnsiString(
    PANSI_STRING DestinationString,
    PCSZ SourceString
    );

__declspec(dllimport)
void
__stdcall
RtlInitUnicodeString(
    PUNICODE_STRING DestinationString,
    PCWSTR SourceString
    );


__declspec(dllimport)
void
__stdcall
RtlCopyString(
    PSTRING DestinationString,
    PSTRING SourceString
    );

__declspec(dllimport)
CHAR
__stdcall
RtlUpperChar (
    CHAR Character
    );

__declspec(dllimport)
LONG
__stdcall
RtlCompareString(
    PSTRING String1,
    PSTRING String2,
    BOOLEAN CaseInSensitive
    );

__declspec(dllimport)
BOOLEAN
__stdcall
RtlEqualString(
    PSTRING String1,
    PSTRING String2,
    BOOLEAN CaseInSensitive
    );


__declspec(dllimport)
void
__stdcall
RtlUpperString(
    PSTRING DestinationString,
    PSTRING SourceString
    );





__declspec(dllimport)
NTSTATUS
__stdcall
RtlAnsiStringToUnicodeString(
    PUNICODE_STRING DestinationString,
    PANSI_STRING SourceString,
    BOOLEAN AllocateDestinationString
    );


__declspec(dllimport)
NTSTATUS
__stdcall
RtlUnicodeStringToAnsiString(
    PANSI_STRING DestinationString,
    PUNICODE_STRING SourceString,
    BOOLEAN AllocateDestinationString
    );


__declspec(dllimport)
LONG
__stdcall
RtlCompareUnicodeString(
    PUNICODE_STRING String1,
    PUNICODE_STRING String2,
    BOOLEAN CaseInSensitive
    );

__declspec(dllimport)
BOOLEAN
__stdcall
RtlEqualUnicodeString(
    const UNICODE_STRING *String1,
    const UNICODE_STRING *String2,
    BOOLEAN CaseInSensitive
    );



__declspec(dllimport)
BOOLEAN
__stdcall
RtlPrefixUnicodeString(
     PUNICODE_STRING String1,
     PUNICODE_STRING String2,
     BOOLEAN CaseInSensitive
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlUpcaseUnicodeString(
    PUNICODE_STRING DestinationString,
    PCUNICODE_STRING SourceString,
    BOOLEAN AllocateDestinationString
    );


__declspec(dllimport)
void
__stdcall
RtlCopyUnicodeString(
    PUNICODE_STRING DestinationString,
    PUNICODE_STRING SourceString
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlAppendUnicodeStringToString (
    PUNICODE_STRING Destination,
    PUNICODE_STRING Source
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlAppendUnicodeToString (
    PUNICODE_STRING Destination,
    PCWSTR Source
    );



__declspec(dllimport)
WCHAR
__stdcall
RtlUpcaseUnicodeChar(
    WCHAR SourceCharacter
    );



__declspec(dllimport)
void
__stdcall
RtlFreeUnicodeString(
    PUNICODE_STRING UnicodeString
    );

__declspec(dllimport)
void
__stdcall
RtlFreeAnsiString(
    PANSI_STRING AnsiString
    );


__declspec(dllimport)
ULONG
__stdcall
RtlxAnsiStringToUnicodeSize(
    PANSI_STRING AnsiString
    );



















#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"

























































#line 59 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"








#line 68 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\guiddef.h"












































































































































#line 1472 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




    
#line 1478 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


    
#line 1482 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


    
    





        

    #line 1494 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#line 1495 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
NTSTATUS
__stdcall
RtlStringFromGUID(
     const GUID * const Guid,
     PUNICODE_STRING GuidString
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlGUIDFromString(
     PUNICODE_STRING GuidString,
     GUID* Guid
    );







__declspec(dllimport)
SIZE_T
__stdcall
RtlCompareMemory (
    const void *Source1,
    const void *Source2,
    SIZE_T Length
    );


















































#line 1577 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"







#line 1585 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


__forceinline
PVOID
RtlSecureZeroMemory(
     PVOID ptr,
     SIZE_T cnt
    )
{
    volatile char *vptr = (volatile char *)ptr;
    while (cnt) {
        *vptr = 0;
        vptr++;
        cnt--;
    }
    return ptr;
}
#line 1603 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"











































#line 1647 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"





#line 1653 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
void
_fastcall
RtlPrefetchMemoryNonTemporal(
     PVOID Source,
     SIZE_T Length
    );








void
__stdcall
DbgBreakPoint(
    void
    );



__declspec(dllimport)
void
__stdcall
DbgBreakPointWithStatus(
     ULONG Status
    );































#line 1715 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



ULONG
_cdecl
DbgPrint(
    PCH Format,
    ...
    );



ULONG
_cdecl
DbgPrintReturnControlC(
    PCH Format,
    ...
    );


#line 1736 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"










__inline
LARGE_INTEGER
__stdcall
RtlLargeIntegerAdd (
    LARGE_INTEGER Addend1,
    LARGE_INTEGER Addend2
    )
{
    LARGE_INTEGER Sum;

    Sum.QuadPart = Addend1.QuadPart + Addend2.QuadPart;
    return Sum;
}





__inline
LARGE_INTEGER
__stdcall
RtlEnlargedIntegerMultiply (
    LONG Multiplicand,
    LONG Multiplier
    )
{
    LARGE_INTEGER Product;

    Product.QuadPart = (LONGLONG)Multiplicand * (ULONGLONG)Multiplier;
    return Product;
}





__inline
LARGE_INTEGER
__stdcall
RtlEnlargedUnsignedMultiply (
    ULONG Multiplicand,
    ULONG Multiplier
    )
{
    LARGE_INTEGER Product;

    Product.QuadPart = (ULONGLONG)Multiplicand * (ULONGLONG)Multiplier;
    return Product;
}





__inline
ULONG
__stdcall
RtlEnlargedUnsignedDivide (
     ULARGE_INTEGER Dividend,
     ULONG Divisor,
     PULONG Remainder
    )
{
    ULONG Quotient;

    Quotient = (ULONG)(Dividend.QuadPart / Divisor);
    if (( (CHAR *)(Remainder) != (CHAR *)(((void *)0)) )) {

        *Remainder = (ULONG)(Dividend.QuadPart % Divisor);
    }

    return Quotient;
}





__inline
LARGE_INTEGER
__stdcall
RtlLargeIntegerNegate (
    LARGE_INTEGER Subtrahend
    )
{
    LARGE_INTEGER Difference;

    Difference.QuadPart = -Subtrahend.QuadPart;
    return Difference;
}





__inline
LARGE_INTEGER
__stdcall
RtlLargeIntegerSubtract (
    LARGE_INTEGER Minuend,
    LARGE_INTEGER Subtrahend
    )
{
    LARGE_INTEGER Difference;

    Difference.QuadPart = Minuend.QuadPart - Subtrahend.QuadPart;
    return Difference;
}

#line 1856 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"





__declspec(dllimport)
LARGE_INTEGER
__stdcall
RtlExtendedMagicDivide (
    LARGE_INTEGER Dividend,
    LARGE_INTEGER MagicDivisor,
    CCHAR ShiftCount
    );





__declspec(dllimport)
LARGE_INTEGER
__stdcall
RtlExtendedLargeIntegerDivide (
    LARGE_INTEGER Dividend,
    ULONG Divisor,
    PULONG Remainder
    );






__declspec(dllimport)
LARGE_INTEGER
__stdcall
RtlLargeIntegerDivide (
    LARGE_INTEGER Dividend,
    LARGE_INTEGER Divisor,
    PLARGE_INTEGER Remainder
    );






__declspec(dllimport)
LARGE_INTEGER
__stdcall
RtlExtendedIntegerMultiply (
    LARGE_INTEGER Multiplicand,
    LONG Multiplier
    );




































































#line 1978 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


#pragma warning(push)
#line 1982 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#pragma warning(disable:4035)               





__inline LARGE_INTEGER
__stdcall
RtlConvertLongToLargeInteger (
    LONG SignedInteger
    )
{
    __asm {
        mov     eax, SignedInteger
        cdq                 ; (edx:eax) = signed LargeInt
    }
}





__inline LARGE_INTEGER
__stdcall
RtlConvertUlongToLargeInteger (
    ULONG UnsignedInteger
    )
{
    __asm {
        sub     edx, edx    ; zero highpart
        mov     eax, UnsignedInteger
    }
}





__inline LARGE_INTEGER
__stdcall
RtlLargeIntegerShiftLeft (
    LARGE_INTEGER LargeInteger,
    CCHAR ShiftCount
    )
{
    __asm    {
        mov     cl, ShiftCount
        and     cl, 0x3f                    ; mod 64

        cmp     cl, 32
        jc      short sl10

        mov     edx, LargeInteger.LowPart   ; ShiftCount >= 32
        xor     eax, eax                    ; lowpart is zero
        shl     edx, cl                     ; store highpart
        jmp     short done

sl10:
        mov     eax, LargeInteger.LowPart   ; ShiftCount < 32
        mov     edx, LargeInteger.HighPart
        shld    edx, eax, cl
        shl     eax, cl
done:
    }
}


__inline LARGE_INTEGER
__stdcall
RtlLargeIntegerShiftRight (
    LARGE_INTEGER LargeInteger,
    CCHAR ShiftCount
    )
{
    __asm    {
        mov     cl, ShiftCount
        and     cl, 0x3f               ; mod 64

        cmp     cl, 32
        jc      short sr10

        mov     eax, LargeInteger.HighPart  ; ShiftCount >= 32
        xor     edx, edx                    ; lowpart is zero
        shr     eax, cl                     ; store highpart
        jmp     short done

sr10:
        mov     eax, LargeInteger.LowPart   ; ShiftCount < 32
        mov     edx, LargeInteger.HighPart
        shrd    eax, edx, cl
        shr     edx, cl
done:
    }
}


__inline LARGE_INTEGER
__stdcall
RtlLargeIntegerArithmeticShift (
    LARGE_INTEGER LargeInteger,
    CCHAR ShiftCount
    )
{
    __asm {
        mov     cl, ShiftCount
        and     cl, 3fh                 ; mod 64

        cmp     cl, 32
        jc      short sar10

        mov     eax, LargeInteger.HighPart
        sar     eax, cl
        bt      eax, 31                     ; sign bit set?
        sbb     edx, edx                    ; duplicate sign bit into highpart
        jmp     short done
sar10:
        mov     eax, LargeInteger.LowPart   ; (eax) = LargeInteger.LowPart
        mov     edx, LargeInteger.HighPart  ; (edx) = LargeInteger.HighPart
        shrd    eax, edx, cl
        sar     edx, cl
done:
    }
}


#pragma warning(pop)


#line 2111 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

#line 2113 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

































































































































typedef struct _TIME_FIELDS {
    CSHORT Year;        
    CSHORT Month;       
    CSHORT Day;         
    CSHORT Hour;        
    CSHORT Minute;      
    CSHORT Second;      
    CSHORT Milliseconds;
    CSHORT Weekday;     
} TIME_FIELDS;
typedef TIME_FIELDS *PTIME_FIELDS;


__declspec(dllimport)
void
__stdcall
RtlTimeToTimeFields (
    PLARGE_INTEGER Time,
    PTIME_FIELDS TimeFields
    );





__declspec(dllimport)
BOOLEAN
__stdcall
RtlTimeFieldsToTime (
    PTIME_FIELDS TimeFields,
    PLARGE_INTEGER Time
    );













































































































































































#line 2448 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"















































































typedef struct _RTL_BITMAP {
    ULONG SizeOfBitMap;                     
    PULONG Buffer;                          
} RTL_BITMAP;
typedef RTL_BITMAP *PRTL_BITMAP;







__declspec(dllimport)
void
__stdcall
RtlInitializeBitMap (
    PRTL_BITMAP BitMapHeader,
    PULONG BitMapBuffer,
    ULONG SizeOfBitMap
    );






__declspec(dllimport)
void
__stdcall
RtlClearAllBits (
    PRTL_BITMAP BitMapHeader
    );

__declspec(dllimport)
void
__stdcall
RtlSetAllBits (
    PRTL_BITMAP BitMapHeader
    );











__declspec(dllimport)
ULONG
__stdcall
RtlFindClearBits (
    PRTL_BITMAP BitMapHeader,
    ULONG NumberToFind,
    ULONG HintIndex
    );

__declspec(dllimport)
ULONG
__stdcall
RtlFindSetBits (
    PRTL_BITMAP BitMapHeader,
    ULONG NumberToFind,
    ULONG HintIndex
    );












__declspec(dllimport)
ULONG
__stdcall
RtlFindClearBitsAndSet (
    PRTL_BITMAP BitMapHeader,
    ULONG NumberToFind,
    ULONG HintIndex
    );

__declspec(dllimport)
ULONG
__stdcall
RtlFindSetBitsAndClear (
    PRTL_BITMAP BitMapHeader,
    ULONG NumberToFind,
    ULONG HintIndex
    );






__declspec(dllimport)
void
__stdcall
RtlClearBits (
    PRTL_BITMAP BitMapHeader,
    ULONG StartingIndex,
    ULONG NumberToClear
    );

__declspec(dllimport)
void
__stdcall
RtlSetBits (
    PRTL_BITMAP BitMapHeader,
    ULONG StartingIndex,
    ULONG NumberToSet
    );









typedef struct _RTL_BITMAP_RUN {

    ULONG StartingIndex;
    ULONG NumberOfBits;

} RTL_BITMAP_RUN;
typedef RTL_BITMAP_RUN *PRTL_BITMAP_RUN;

__declspec(dllimport)
ULONG
__stdcall
RtlFindClearRuns (
    PRTL_BITMAP BitMapHeader,
    PRTL_BITMAP_RUN RunArray,
    ULONG SizeOfRunArray,
    BOOLEAN LocateLongestRuns
    );








__declspec(dllimport)
ULONG
__stdcall
RtlFindLongestRunClear (
    PRTL_BITMAP BitMapHeader,
    PULONG StartingIndex
    );








__declspec(dllimport)
ULONG
__stdcall
RtlFindFirstRunClear (
    PRTL_BITMAP BitMapHeader,
    PULONG StartingIndex
    );

























__declspec(dllimport)
ULONG
__stdcall
RtlNumberOfClearBits (
    PRTL_BITMAP BitMapHeader
    );

__declspec(dllimport)
ULONG
__stdcall
RtlNumberOfSetBits (
    PRTL_BITMAP BitMapHeader
    );






__declspec(dllimport)
BOOLEAN
__stdcall
RtlAreBitsClear (
    PRTL_BITMAP BitMapHeader,
    ULONG StartingIndex,
    ULONG Length
    );

__declspec(dllimport)
BOOLEAN
__stdcall
RtlAreBitsSet (
    PRTL_BITMAP BitMapHeader,
    ULONG StartingIndex,
    ULONG Length
    );

__declspec(dllimport)
ULONG
__stdcall
RtlFindNextForwardRunClear (
     PRTL_BITMAP BitMapHeader,
     ULONG FromIndex,
     PULONG StartingRunIndex
    );

__declspec(dllimport)
ULONG
__stdcall
RtlFindLastBackwardRunClear (
     PRTL_BITMAP BitMapHeader,
     ULONG FromIndex,
     PULONG StartingRunIndex
    );







__declspec(dllimport)
CCHAR
__stdcall
RtlFindLeastSignificantBit (
     ULONGLONG Set
    );

__declspec(dllimport)
CCHAR
__stdcall
RtlFindMostSignificantBit (
     ULONGLONG Set
    );























__inline LUID
__stdcall
RtlConvertLongToLuid(
    LONG Long
    )
{
    LUID TempLuid;
    LARGE_INTEGER TempLi;

    TempLi = RtlConvertLongToLargeInteger(Long);
    TempLuid.LowPart = TempLi.LowPart;
    TempLuid.HighPart = TempLi.HighPart;
    return(TempLuid);
}

__inline LUID
__stdcall
RtlConvertUlongToLuid(
    ULONG Ulong
    )
{
    LUID TempLuid;

    TempLuid.LowPart = Ulong;
    TempLuid.HighPart = 0;
    return(TempLuid);
}
#line 2852 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


__declspec(dllimport)
void
__stdcall
RtlMapGenericMask(
    PACCESS_MASK AccessMask,
    PGENERIC_MAPPING GenericMapping
    );




__declspec(dllimport)
NTSTATUS
__stdcall
RtlCreateSecurityDescriptor (
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    ULONG Revision
    );


__declspec(dllimport)
BOOLEAN
__stdcall
RtlValidSecurityDescriptor (
    PSECURITY_DESCRIPTOR SecurityDescriptor
    );


__declspec(dllimport)
ULONG
__stdcall
RtlLengthSecurityDescriptor (
    PSECURITY_DESCRIPTOR SecurityDescriptor
    );

__declspec(dllimport)
BOOLEAN
__stdcall
RtlValidRelativeSecurityDescriptor (
     PSECURITY_DESCRIPTOR SecurityDescriptorInput,
     ULONG SecurityDescriptorLength,
     SECURITY_INFORMATION RequiredInformation
    );


__declspec(dllimport)
NTSTATUS
__stdcall
RtlSetDaclSecurityDescriptor (
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    BOOLEAN DaclPresent,
    PACL Dacl,
    BOOLEAN DaclDefaulted
    );






typedef struct _RTL_RANGE {

    
    
    
    ULONGLONG Start;    

    
    
    
    ULONGLONG End;      

    
    
    
    PVOID UserData;     

    
    
    
    PVOID Owner;        

    
    
    
    UCHAR Attributes;    

    
    
    
    UCHAR Flags;       

} RTL_RANGE, *PRTL_RANGE;





typedef struct _RTL_RANGE_LIST {

    
    
    
    LIST_ENTRY ListHead;

    
    
    
    ULONG Flags;        

    
    
    
    ULONG Count;

    
    
    
    
    
    ULONG Stamp;

} RTL_RANGE_LIST, *PRTL_RANGE_LIST;

typedef struct _RANGE_LIST_ITERATOR {

    PLIST_ENTRY RangeListHead;
    PLIST_ENTRY MergedHead;
    PVOID Current;
    ULONG Stamp;

} RTL_RANGE_LIST_ITERATOR, *PRTL_RANGE_LIST_ITERATOR;


__declspec(dllimport)
void
__stdcall
RtlInitializeRangeList(
      PRTL_RANGE_LIST RangeList
    );

__declspec(dllimport)
void
__stdcall
RtlFreeRangeList(
     PRTL_RANGE_LIST RangeList
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlCopyRangeList(
     PRTL_RANGE_LIST CopyRangeList,
     PRTL_RANGE_LIST RangeList
    );




__declspec(dllimport)
NTSTATUS
__stdcall
RtlAddRange(
      PRTL_RANGE_LIST RangeList,
     ULONGLONG Start,
     ULONGLONG End,
     UCHAR Attributes,
     ULONG Flags,
     PVOID UserData,  
     PVOID Owner      
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlDeleteRange(
      PRTL_RANGE_LIST RangeList,
     ULONGLONG Start,
     ULONGLONG End,
     PVOID Owner
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlDeleteOwnersRanges(
      PRTL_RANGE_LIST RangeList,
     PVOID Owner
    );




typedef
BOOLEAN
(*PRTL_CONFLICT_RANGE_CALLBACK) (
     PVOID Context,
     PRTL_RANGE Range
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlFindRange(
     PRTL_RANGE_LIST RangeList,
     ULONGLONG Minimum,
     ULONGLONG Maximum,
     ULONG Length,
     ULONG Alignment,
     ULONG Flags,
     UCHAR AttributeAvailableMask,
     PVOID Context ,
     PRTL_CONFLICT_RANGE_CALLBACK Callback ,
     PULONGLONG Start
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlIsRangeAvailable(
     PRTL_RANGE_LIST RangeList,
     ULONGLONG Start,
     ULONGLONG End,
     ULONG Flags,
     UCHAR AttributeAvailableMask,
     PVOID Context ,
     PRTL_CONFLICT_RANGE_CALLBACK Callback ,
     PBOOLEAN Available
    );













__declspec(dllimport)
NTSTATUS
__stdcall
RtlGetFirstRange(
     PRTL_RANGE_LIST RangeList,
     PRTL_RANGE_LIST_ITERATOR Iterator,
     PRTL_RANGE *Range
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlGetLastRange(
     PRTL_RANGE_LIST RangeList,
     PRTL_RANGE_LIST_ITERATOR Iterator,
     PRTL_RANGE *Range
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlGetNextRange(
      PRTL_RANGE_LIST_ITERATOR Iterator,
     PRTL_RANGE *Range,
     BOOLEAN MoveForwards
    );



__declspec(dllimport)
NTSTATUS
__stdcall
RtlMergeRangeLists(
     PRTL_RANGE_LIST MergedRangeList,
     PRTL_RANGE_LIST RangeList1,
     PRTL_RANGE_LIST RangeList2,
     ULONG Flags
    );

__declspec(dllimport)
NTSTATUS
__stdcall
RtlInvertRangeList(
     PRTL_RANGE_LIST InvertedRangeList,
     PRTL_RANGE_LIST RangeList
    );










USHORT
_fastcall
RtlUshortByteSwap(
     USHORT Source
    );

ULONG
_fastcall
RtlUlongByteSwap(
     ULONG Source
    );

ULONGLONG
_fastcall
RtlUlonglongByteSwap(
     ULONGLONG Source
    );






__declspec(dllimport)
NTSTATUS
__stdcall
RtlVolumeDeviceToDosName(
      PVOID           VolumeDeviceObject,
     PUNICODE_STRING DosName
    );

typedef struct _OSVERSIONINFOA {
    ULONG dwOSVersionInfoSize;
    ULONG dwMajorVersion;
    ULONG dwMinorVersion;
    ULONG dwBuildNumber;
    ULONG dwPlatformId;
    CHAR   szCSDVersion[ 128 ];     
} OSVERSIONINFOA, *POSVERSIONINFOA, *LPOSVERSIONINFOA;

typedef struct _OSVERSIONINFOW {
    ULONG dwOSVersionInfoSize;
    ULONG dwMajorVersion;
    ULONG dwMinorVersion;
    ULONG dwBuildNumber;
    ULONG dwPlatformId;
    WCHAR  szCSDVersion[ 128 ];     
} OSVERSIONINFOW, *POSVERSIONINFOW, *LPOSVERSIONINFOW, RTL_OSVERSIONINFOW, *PRTL_OSVERSIONINFOW;





typedef OSVERSIONINFOA OSVERSIONINFO;
typedef POSVERSIONINFOA POSVERSIONINFO;
typedef LPOSVERSIONINFOA LPOSVERSIONINFO;
#line 3209 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

typedef struct _OSVERSIONINFOEXA {
    ULONG dwOSVersionInfoSize;
    ULONG dwMajorVersion;
    ULONG dwMinorVersion;
    ULONG dwBuildNumber;
    ULONG dwPlatformId;
    CHAR   szCSDVersion[ 128 ];     
    USHORT wServicePackMajor;
    USHORT wServicePackMinor;
    USHORT wSuiteMask;
    UCHAR wProductType;
    UCHAR wReserved;
} OSVERSIONINFOEXA, *POSVERSIONINFOEXA, *LPOSVERSIONINFOEXA;
typedef struct _OSVERSIONINFOEXW {
    ULONG dwOSVersionInfoSize;
    ULONG dwMajorVersion;
    ULONG dwMinorVersion;
    ULONG dwBuildNumber;
    ULONG dwPlatformId;
    WCHAR  szCSDVersion[ 128 ];     
    USHORT wServicePackMajor;
    USHORT wServicePackMinor;
    USHORT wSuiteMask;
    UCHAR wProductType;
    UCHAR wReserved;
} OSVERSIONINFOEXW, *POSVERSIONINFOEXW, *LPOSVERSIONINFOEXW, RTL_OSVERSIONINFOEXW, *PRTL_OSVERSIONINFOEXW;





typedef OSVERSIONINFOEXA OSVERSIONINFOEX;
typedef POSVERSIONINFOEXA POSVERSIONINFOEX;
typedef LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#line 3245 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


























































ULONGLONG
__stdcall
VerSetConditionMask(
          ULONGLONG   ConditionMask,
          ULONG   TypeMask,
          UCHAR   Condition
        );




__declspec(dllimport)
NTSTATUS
RtlGetVersion(
     PRTL_OSVERSIONINFOW lpVersionInformation
    );

__declspec(dllimport)
NTSTATUS
RtlVerifyVersionInfo(
     PRTL_OSVERSIONINFOEXW VersionInfo,
     ULONG TypeMask,
     ULONGLONG  ConditionMask
    );





























































































































































































































































































































































typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        PVOID Pointer;
    };

    ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;






#line 3691 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"






typedef
void
(__stdcall *PIO_APC_ROUTINE) (
     PVOID ApcContext,
     PIO_STATUS_BLOCK IoStatusBlock,
     ULONG Reserved
    );









typedef enum _FILE_INFORMATION_CLASS {

    FileDirectoryInformation       = 1,
    FileFullDirectoryInformation,   
    FileBothDirectoryInformation,   
    FileBasicInformation,           
    FileStandardInformation,        
    FileInternalInformation,        
    FileEaInformation,              
    FileAccessInformation,          
    FileNameInformation,            
    FileRenameInformation,          
    FileLinkInformation,            
    FileNamesInformation,           
    FileDispositionInformation,     
    FilePositionInformation,        
    FileFullEaInformation,          
    FileModeInformation,            
    FileAlignmentInformation,       
    FileAllInformation,             
    FileAllocationInformation,      
    FileEndOfFileInformation,       
    FileAlternateNameInformation,   
    FileStreamInformation,          
    FilePipeInformation,            
    FilePipeLocalInformation,       
    FilePipeRemoteInformation,      
    FileMailslotQueryInformation,   
    FileMailslotSetInformation,     
    FileCompressionInformation,     
    FileObjectIdInformation,        
    FileCompletionInformation,      
    FileMoveClusterInformation,     
    FileQuotaInformation,           
    FileReparsePointInformation,    
    FileNetworkOpenInformation,     
    FileAttributeTagInformation,    
    FileTrackingInformation,        
    FileIdBothDirectoryInformation, 
    FileIdFullDirectoryInformation, 
    FileMaximumInformation

} FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;





typedef struct _FILE_BASIC_INFORMATION {                    
    LARGE_INTEGER CreationTime;                             
    LARGE_INTEGER LastAccessTime;                           
    LARGE_INTEGER LastWriteTime;                            
    LARGE_INTEGER ChangeTime;                               
    ULONG FileAttributes;                                   
} FILE_BASIC_INFORMATION, *PFILE_BASIC_INFORMATION;         
                                                            
typedef struct _FILE_STANDARD_INFORMATION {                 
    LARGE_INTEGER AllocationSize;                           
    LARGE_INTEGER EndOfFile;                                
    ULONG NumberOfLinks;                                    
    BOOLEAN DeletePending;                                  
    BOOLEAN Directory;                                      
} FILE_STANDARD_INFORMATION, *PFILE_STANDARD_INFORMATION;   
                                                            
typedef struct _FILE_POSITION_INFORMATION {                 
    LARGE_INTEGER CurrentByteOffset;                        
} FILE_POSITION_INFORMATION, *PFILE_POSITION_INFORMATION;   
                                                            
typedef struct _FILE_ALIGNMENT_INFORMATION {                
    ULONG AlignmentRequirement;                             
} FILE_ALIGNMENT_INFORMATION, *PFILE_ALIGNMENT_INFORMATION; 
                                                            
typedef struct _FILE_NAME_INFORMATION {                     
    ULONG FileNameLength;                                   
    WCHAR FileName[1];                                      
} FILE_NAME_INFORMATION, *PFILE_NAME_INFORMATION;           
                                                            
typedef struct _FILE_NETWORK_OPEN_INFORMATION {                 
    LARGE_INTEGER CreationTime;                                 
    LARGE_INTEGER LastAccessTime;                               
    LARGE_INTEGER LastWriteTime;                                
    LARGE_INTEGER ChangeTime;                                   
    LARGE_INTEGER AllocationSize;                               
    LARGE_INTEGER EndOfFile;                                    
    ULONG FileAttributes;                                       
} FILE_NETWORK_OPEN_INFORMATION, *PFILE_NETWORK_OPEN_INFORMATION;   
                                                                
typedef struct _FILE_ATTRIBUTE_TAG_INFORMATION {               
    ULONG FileAttributes;                                       
    ULONG ReparseTag;                                           
} FILE_ATTRIBUTE_TAG_INFORMATION, *PFILE_ATTRIBUTE_TAG_INFORMATION;  
                                                                
typedef struct _FILE_DISPOSITION_INFORMATION {                  
    BOOLEAN DeleteFile;                                         
} FILE_DISPOSITION_INFORMATION, *PFILE_DISPOSITION_INFORMATION; 
                                                                
typedef struct _FILE_END_OF_FILE_INFORMATION {                  
    LARGE_INTEGER EndOfFile;                                    
} FILE_END_OF_FILE_INFORMATION, *PFILE_END_OF_FILE_INFORMATION; 
                                                                

typedef struct _FILE_FULL_EA_INFORMATION {
    ULONG NextEntryOffset;
    UCHAR Flags;
    UCHAR EaNameLength;
    USHORT EaValueLength;
    CHAR EaName[1];
} FILE_FULL_EA_INFORMATION, *PFILE_FULL_EA_INFORMATION;







typedef enum _FSINFOCLASS {
    FileFsVolumeInformation       = 1,
    FileFsLabelInformation,      
    FileFsSizeInformation,       
    FileFsDeviceInformation,     
    FileFsAttributeInformation,  
    FileFsControlInformation,    
    FileFsFullSizeInformation,   
    FileFsObjectIdInformation,   
    FileFsMaximumInformation
} FS_INFORMATION_CLASS, *PFS_INFORMATION_CLASS;

typedef struct _FILE_FS_DEVICE_INFORMATION {                    
    ULONG DeviceType;                                     
    ULONG Characteristics;                                      
} FILE_FS_DEVICE_INFORMATION, *PFILE_FS_DEVICE_INFORMATION;     
                                                                





typedef union _FILE_SEGMENT_ELEMENT {
    PVOID64 Buffer;
    ULONGLONG Alignment;
}FILE_SEGMENT_ELEMENT, *PFILE_SEGMENT_ELEMENT;





typedef enum _INTERFACE_TYPE {
    InterfaceTypeUndefined = -1,
    Internal,
    Isa,
    Eisa,
    MicroChannel,
    TurboChannel,
    PCIBus,
    VMEBus,
    NuBus,
    PCMCIABus,
    CBus,
    MPIBus,
    MPSABus,
    ProcessorInternal,
    InternalPowerBus,
    PNPISABus,
    PNPBus,
    MaximumInterfaceType
}INTERFACE_TYPE, *PINTERFACE_TYPE;





typedef enum _DMA_WIDTH {
    Width8Bits,
    Width16Bits,
    Width32Bits,
    MaximumDmaWidth
}DMA_WIDTH, *PDMA_WIDTH;





typedef enum _DMA_SPEED {
    Compatible,
    TypeA,
    TypeB,
    TypeC,
    TypeF,
    MaximumDmaSpeed
}DMA_SPEED, *PDMA_SPEED;






typedef void (*PINTERFACE_REFERENCE)(PVOID Context);
typedef void (*PINTERFACE_DEREFERENCE)(PVOID Context);







typedef enum _BUS_DATA_TYPE {
    ConfigurationSpaceUndefined = -1,
    Cmos,
    EisaConfiguration,
    Pos,
    CbusConfiguration,
    PCIConfiguration,
    VMEConfiguration,
    NuBusConfiguration,
    PCMCIAConfiguration,
    MPIConfiguration,
    MPSAConfiguration,
    PNPISAConfiguration,
    SgiInternalConfiguration,
    MaximumBusDataType
} BUS_DATA_TYPE, *PBUS_DATA_TYPE;






typedef struct _IO_ERROR_LOG_PACKET {
    UCHAR MajorFunctionCode;
    UCHAR RetryCount;
    USHORT DumpDataSize;
    USHORT NumberOfStrings;
    USHORT StringOffset;
    USHORT EventCategory;
    NTSTATUS ErrorCode;
    ULONG UniqueErrorValue;
    NTSTATUS FinalStatus;
    ULONG SequenceNumber;
    ULONG IoControlCode;
    LARGE_INTEGER DeviceOffset;
    ULONG DumpData[1];
}IO_ERROR_LOG_PACKET, *PIO_ERROR_LOG_PACKET;






typedef struct _IO_ERROR_LOG_MESSAGE {
    USHORT Type;
    USHORT Size;
    USHORT DriverNameLength;
    LARGE_INTEGER TimeStamp;
    ULONG DriverNameOffset;
    IO_ERROR_LOG_PACKET EntryData;
}IO_ERROR_LOG_MESSAGE, *PIO_ERROR_LOG_MESSAGE;














































#line 4016 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"














































                                                    


                                                    


                                                    


                                                    
                                                    































typedef struct _KEY_BASIC_INFORMATION {
    LARGE_INTEGER LastWriteTime;
    ULONG   TitleIndex;
    ULONG   NameLength;
    WCHAR   Name[1];            
} KEY_BASIC_INFORMATION, *PKEY_BASIC_INFORMATION;

typedef struct _KEY_NODE_INFORMATION {
    LARGE_INTEGER LastWriteTime;
    ULONG   TitleIndex;
    ULONG   ClassOffset;
    ULONG   ClassLength;
    ULONG   NameLength;
    WCHAR   Name[1];            

} KEY_NODE_INFORMATION, *PKEY_NODE_INFORMATION;

typedef struct _KEY_FULL_INFORMATION {
    LARGE_INTEGER LastWriteTime;
    ULONG   TitleIndex;
    ULONG   ClassOffset;
    ULONG   ClassLength;
    ULONG   SubKeys;
    ULONG   MaxNameLen;
    ULONG   MaxClassLen;
    ULONG   Values;
    ULONG   MaxValueNameLen;
    ULONG   MaxValueDataLen;
    WCHAR   Class[1];           
} KEY_FULL_INFORMATION, *PKEY_FULL_INFORMATION;


typedef struct _KEY_NAME_INFORMATION {
    ULONG   NameLength;
    WCHAR   Name[1];            
} KEY_NAME_INFORMATION, *PKEY_NAME_INFORMATION;


typedef enum _KEY_INFORMATION_CLASS {
    KeyBasicInformation,
    KeyNodeInformation,
    KeyFullInformation

    ,
    KeyNameInformation

} KEY_INFORMATION_CLASS;

typedef struct _KEY_WRITE_TIME_INFORMATION {
    LARGE_INTEGER LastWriteTime;
} KEY_WRITE_TIME_INFORMATION, *PKEY_WRITE_TIME_INFORMATION;

typedef enum _KEY_SET_INFORMATION_CLASS {
    KeyWriteTimeInformation
} KEY_SET_INFORMATION_CLASS;





typedef struct _KEY_VALUE_BASIC_INFORMATION {
    ULONG   TitleIndex;
    ULONG   Type;
    ULONG   NameLength;
    WCHAR   Name[1];            
} KEY_VALUE_BASIC_INFORMATION, *PKEY_VALUE_BASIC_INFORMATION;

typedef struct _KEY_VALUE_FULL_INFORMATION {
    ULONG   TitleIndex;
    ULONG   Type;
    ULONG   DataOffset;
    ULONG   DataLength;
    ULONG   NameLength;
    WCHAR   Name[1];            

} KEY_VALUE_FULL_INFORMATION, *PKEY_VALUE_FULL_INFORMATION;

typedef struct _KEY_VALUE_PARTIAL_INFORMATION {
    ULONG   TitleIndex;
    ULONG   Type;
    ULONG   DataLength;
    UCHAR   Data[1];            
} KEY_VALUE_PARTIAL_INFORMATION, *PKEY_VALUE_PARTIAL_INFORMATION;

typedef struct _KEY_VALUE_PARTIAL_INFORMATION_ALIGN64 {
    ULONG   Type;
    ULONG   DataLength;
    UCHAR   Data[1];            
} KEY_VALUE_PARTIAL_INFORMATION_ALIGN64, *PKEY_VALUE_PARTIAL_INFORMATION_ALIGN64;

typedef struct _KEY_VALUE_ENTRY {
    PUNICODE_STRING ValueName;
    ULONG           DataLength;
    ULONG           DataOffset;
    ULONG           Type;
} KEY_VALUE_ENTRY, *PKEY_VALUE_ENTRY;

typedef enum _KEY_VALUE_INFORMATION_CLASS {
    KeyValueBasicInformation,
    KeyValueFullInformation,
    KeyValuePartialInformation,
    KeyValueFullInformationAlign64,
    KeyValuePartialInformationAlign64
} KEY_VALUE_INFORMATION_CLASS;
































typedef struct _OBJECT_NAME_INFORMATION {               
    UNICODE_STRING Name;                                
} OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION;   








typedef enum _SECTION_INHERIT {
    ViewShare = 1,
    ViewUnmap = 2
} SECTION_INHERIT;





































































typedef struct _CLIENT_ID {
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
} CLIENT_ID;
typedef CLIENT_ID *PCLIENT_ID;
















typedef struct _NT_TIB {
    struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
    PVOID StackBase;
    PVOID StackLimit;
    PVOID SubSystemTib;
    union {
        PVOID FiberData;
        ULONG Version;
    };
    PVOID ArbitraryUserPointer;
    struct _NT_TIB *Self;
} NT_TIB;
typedef NT_TIB *PNT_TIB;




typedef enum _PROCESSINFOCLASS {
    ProcessBasicInformation,
    ProcessQuotaLimits,
    ProcessIoCounters,
    ProcessVmCounters,
    ProcessTimes,
    ProcessBasePriority,
    ProcessRaisePriority,
    ProcessDebugPort,
    ProcessExceptionPort,
    ProcessAccessToken,
    ProcessLdtInformation,
    ProcessLdtSize,
    ProcessDefaultHardErrorMode,
    ProcessIoPortHandlers,          
    ProcessPooledUsageAndLimits,
    ProcessWorkingSetWatch,
    ProcessUserModeIOPL,
    ProcessEnableAlignmentFaultFixup,
    ProcessPriorityClass,
    ProcessWx86Information,
    ProcessHandleCount,
    ProcessAffinityMask,
    ProcessPriorityBoost,
    ProcessDeviceMap,
    ProcessSessionInformation,
    ProcessForegroundInformation,
    ProcessWow64Information,
    MaxProcessInfoClass
    } PROCESSINFOCLASS;




typedef enum _THREADINFOCLASS {
    ThreadBasicInformation,
    ThreadTimes,
    ThreadPriority,
    ThreadBasePriority,
    ThreadAffinityMask,
    ThreadImpersonationToken,
    ThreadDescriptorTableEntry,
    ThreadEnableAlignmentFaultFixup,
    ThreadEventPair_Reusable,
    ThreadQuerySetWin32StartAddress,
    ThreadZeroTlsCell,
    ThreadPerformanceCount,
    ThreadAmILastThread,
    ThreadIdealProcessor,
    ThreadPriorityBoost,
    ThreadSetTlsArrayAddress,
    ThreadIsIoPending,
    ThreadHideFromDebugger,
    MaxThreadInfoClass
    } THREADINFOCLASS;








typedef struct _PROCESS_WS_WATCH_INFORMATION {
    PVOID FaultingPc;
    PVOID FaultingVa;
} PROCESS_WS_WATCH_INFORMATION, *PPROCESS_WS_WATCH_INFORMATION;






typedef struct _PROCESS_BASIC_INFORMATION {
    NTSTATUS ExitStatus;
    PPEB PebBaseAddress;
    ULONG_PTR AffinityMask;
    KPRIORITY BasePriority;
    ULONG_PTR UniqueProcessId;
    ULONG_PTR InheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION;
typedef PROCESS_BASIC_INFORMATION *PPROCESS_BASIC_INFORMATION;








typedef struct _PROCESS_DEVICEMAP_INFORMATION {
    union {
        struct {
            HANDLE DirectoryHandle;
        } Set;
        struct {
            ULONG DriveMap;
            UCHAR DriveType[ 32 ];
        } Query;
    };
} PROCESS_DEVICEMAP_INFORMATION, *PPROCESS_DEVICEMAP_INFORMATION;







typedef struct _PROCESS_SESSION_INFORMATION {
    ULONG SessionId;
} PROCESS_SESSION_INFORMATION, *PPROCESS_SESSION_INFORMATION;











typedef struct _QUOTA_LIMITS {
    SIZE_T PagedPoolLimit;
    SIZE_T NonPagedPoolLimit;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    SIZE_T PagefileLimit;
    LARGE_INTEGER TimeLimit;
} QUOTA_LIMITS;
typedef QUOTA_LIMITS *PQUOTA_LIMITS;









typedef struct _IO_COUNTERS {
    ULONGLONG  ReadOperationCount;
    ULONGLONG  WriteOperationCount;
    ULONGLONG  OtherOperationCount;
    ULONGLONG ReadTransferCount;
    ULONGLONG WriteTransferCount;
    ULONGLONG OtherTransferCount;
} IO_COUNTERS;
typedef IO_COUNTERS *PIO_COUNTERS;







typedef struct _VM_COUNTERS {
    SIZE_T PeakVirtualSize;
    SIZE_T VirtualSize;
    ULONG PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
} VM_COUNTERS;
typedef VM_COUNTERS *PVM_COUNTERS;






typedef struct _POOLED_USAGE_AND_LIMITS {
    SIZE_T PeakPagedPoolUsage;
    SIZE_T PagedPoolUsage;
    SIZE_T PagedPoolLimit;
    SIZE_T PeakNonPagedPoolUsage;
    SIZE_T NonPagedPoolUsage;
    SIZE_T NonPagedPoolLimit;
    SIZE_T PeakPagefileUsage;
    SIZE_T PagefileUsage;
    SIZE_T PagefileLimit;
} POOLED_USAGE_AND_LIMITS;
typedef POOLED_USAGE_AND_LIMITS *PPOOLED_USAGE_AND_LIMITS;








typedef struct _PROCESS_ACCESS_TOKEN {

    
    
    
    

    HANDLE Token;

    
    
    
    
    
    
    

    HANDLE Thread;

} PROCESS_ACCESS_TOKEN, *PPROCESS_ACCESS_TOKEN;







typedef struct _KERNEL_USER_TIMES {
    LARGE_INTEGER CreateTime;
    LARGE_INTEGER ExitTime;
    LARGE_INTEGER KernelTime;
    LARGE_INTEGER UserTime;
} KERNEL_USER_TIMES;
typedef KERNEL_USER_TIMES *PKERNEL_USER_TIMES;
__declspec(dllimport)
NTSTATUS
__stdcall
NtOpenProcess (
     PHANDLE ProcessHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes,
     PCLIENT_ID ClientId 
    );

__declspec(dllimport)
NTSTATUS
__stdcall
NtQueryInformationProcess(
     HANDLE ProcessHandle,
     PROCESSINFOCLASS ProcessInformationClass,
     PVOID ProcessInformation,
     ULONG ProcessInformationLength,
     PULONG ReturnLength 
    );





typedef enum _SYSTEM_POWER_STATE {
    PowerSystemUnspecified = 0,
    PowerSystemWorking,
    PowerSystemSleeping1,
    PowerSystemSleeping2,
    PowerSystemSleeping3,
    PowerSystemHibernate,
    PowerSystemShutdown,
    PowerSystemMaximum
} SYSTEM_POWER_STATE, *PSYSTEM_POWER_STATE;

typedef enum {
    PowerActionNone = 0,
    PowerActionReserved,
    PowerActionSleep,
    PowerActionHibernate,
    PowerActionShutdown,
    PowerActionShutdownReset,
    PowerActionShutdownOff,
    PowerActionWarmEject
} POWER_ACTION, *PPOWER_ACTION;

typedef enum _DEVICE_POWER_STATE {
    PowerDeviceUnspecified = 0,
    PowerDeviceD0,
    PowerDeviceD1,
    PowerDeviceD2,
    PowerDeviceD3,
    PowerDeviceMaximum
} DEVICE_POWER_STATE, *PDEVICE_POWER_STATE;

typedef union _POWER_STATE {
    SYSTEM_POWER_STATE SystemState;
    DEVICE_POWER_STATE DeviceState;
} POWER_STATE, *PPOWER_STATE;

typedef enum _POWER_STATE_TYPE {
    SystemPowerState = 0,
    DevicePowerState
} POWER_STATE_TYPE, *PPOWER_STATE_TYPE;



























typedef ULONG EXECUTION_STATE;

typedef enum {
    LT_DONT_CARE,
    LT_LOWEST_LATENCY
} LATENCY_TIME;



typedef enum {
    SystemPowerPolicyAc,
    SystemPowerPolicyDc,
    VerifySystemPolicyAc,
    VerifySystemPolicyDc,
    SystemPowerCapabilities,
    SystemBatteryState,
    SystemPowerStateHandler,
    ProcessorStateHandler,
    SystemPowerPolicyCurrent,
    AdministratorPowerPolicy,
    SystemReserveHiberFile,
    ProcessorInformation,
    SystemPowerInformation
} POWER_INFORMATION_LEVEL;



#line 4712 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"








typedef ULONG PFN_COUNT;

typedef LONG SPFN_NUMBER, *PSPFN_NUMBER;
typedef ULONG PFN_NUMBER, *PPFN_NUMBER;

























typedef union _MCI_STATS {
    struct {
        USHORT  McaCod;
        USHORT  MsCod;
        ULONG   OtherInfo : 25;
        ULONG   Damage : 1;
        ULONG   AddressValid : 1;
        ULONG   MiscValid : 1;
        ULONG   Enabled : 1;
        ULONG   UnCorrected : 1;
        ULONG   OverFlow : 1;
        ULONG   Valid : 1;
    } MciStats;

    ULONGLONG QuadPart;

} MCI_STATS, *PMCI_STATS;
































__declspec(dllimport)
UCHAR
READ_REGISTER_UCHAR(
    PUCHAR  Register
    );

__declspec(dllimport)
USHORT
READ_REGISTER_USHORT(
    PUSHORT Register
    );

__declspec(dllimport)
ULONG
READ_REGISTER_ULONG(
    PULONG  Register
    );

__declspec(dllimport)
void
READ_REGISTER_BUFFER_UCHAR(
    PUCHAR  Register,
    PUCHAR  Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
READ_REGISTER_BUFFER_USHORT(
    PUSHORT Register,
    PUSHORT Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
READ_REGISTER_BUFFER_ULONG(
    PULONG  Register,
    PULONG  Buffer,
    ULONG   Count
    );


__declspec(dllimport)
void
WRITE_REGISTER_UCHAR(
    PUCHAR  Register,
    UCHAR   Value
    );

__declspec(dllimport)
void
WRITE_REGISTER_USHORT(
    PUSHORT Register,
    USHORT  Value
    );

__declspec(dllimport)
void
WRITE_REGISTER_ULONG(
    PULONG  Register,
    ULONG   Value
    );

__declspec(dllimport)
void
WRITE_REGISTER_BUFFER_UCHAR(
    PUCHAR  Register,
    PUCHAR  Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
WRITE_REGISTER_BUFFER_USHORT(
    PUSHORT Register,
    PUSHORT Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
WRITE_REGISTER_BUFFER_ULONG(
    PULONG  Register,
    PULONG  Buffer,
    ULONG   Count
    );

__declspec(dllimport)
UCHAR
READ_PORT_UCHAR(
    PUCHAR  Port
    );

__declspec(dllimport)
USHORT
READ_PORT_USHORT(
    PUSHORT Port
    );

__declspec(dllimport)
ULONG
READ_PORT_ULONG(
    PULONG  Port
    );

__declspec(dllimport)
void
READ_PORT_BUFFER_UCHAR(
    PUCHAR  Port,
    PUCHAR  Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
READ_PORT_BUFFER_USHORT(
    PUSHORT Port,
    PUSHORT Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
READ_PORT_BUFFER_ULONG(
    PULONG  Port,
    PULONG  Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
WRITE_PORT_UCHAR(
    PUCHAR  Port,
    UCHAR   Value
    );

__declspec(dllimport)
void
WRITE_PORT_USHORT(
    PUSHORT Port,
    USHORT  Value
    );

__declspec(dllimport)
void
WRITE_PORT_ULONG(
    PULONG  Port,
    ULONG   Value
    );

__declspec(dllimport)
void
WRITE_PORT_BUFFER_UCHAR(
    PUCHAR  Port,
    PUCHAR  Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
WRITE_PORT_BUFFER_USHORT(
    PUSHORT Port,
    PUSHORT Buffer,
    ULONG   Count
    );

__declspec(dllimport)
void
WRITE_PORT_BUFFER_ULONG(
    PULONG  Port,
    PULONG  Buffer,
    ULONG   Count
    );




































typedef struct _KPCR {







    NT_TIB  NtTib;
    struct _KPCR *SelfPcr;              
    struct _KPRCB *Prcb;                
    KIRQL   Irql;
    ULONG   IRR;
    ULONG   IrrActive;
    ULONG   IDR;
    ULONG   Reserved2;

    struct _KIDTENTRY *IDT;
    struct _KGDTENTRY *GDT;
    struct _KTSS      *TSS;
    USHORT  MajorVersion;
    USHORT  MinorVersion;
    KAFFINITY SetMember;
    ULONG   StallScaleFactor;
    UCHAR   DebugActive;
    UCHAR   Number;

} KPCR;
typedef KPCR *PKPCR;





typedef struct _KFLOATING_SAVE {
    ULONG   ControlWord;
    ULONG   StatusWord;
    ULONG   ErrorOffset;
    ULONG   ErrorSelector;
    ULONG   DataOffset;                 
    ULONG   DataSelector;
    ULONG   Cr0NpxState;
    ULONG   Spare1;                     
} KFLOATING_SAVE, *PKFLOATING_SAVE;

































#line 5086 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"













extern PVOID *MmHighestUserAddress;
extern PVOID *MmSystemRangeStart;
extern ULONG *MmUserProbeAddress;



















#line 5122 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"





























































typedef enum _INTERLOCKED_RESULT {
    ResultNegative = ((0x8000 & ~0x4000) & (0x8000 | 0x4000)),
    ResultZero     = ((~0x8000 & 0x4000) & (0x8000 | 0x4000)),
    ResultPositive = ((~0x8000 & ~0x4000) & (0x8000 | 0x4000))
} INTERLOCKED_RESULT;

__declspec(dllimport)
INTERLOCKED_RESULT
_fastcall
Exfi386InterlockedIncrementLong (
     PLONG Addend
    );

__declspec(dllimport)
INTERLOCKED_RESULT
_fastcall
Exfi386InterlockedDecrementLong (
     PLONG Addend
    );

__declspec(dllimport)
LARGE_INTEGER
ExInterlockedExchangeAddLargeInteger (
     PLARGE_INTEGER Addend,
     LARGE_INTEGER Increment,
     PKSPIN_LOCK Lock
    );

__declspec(dllimport)
ULONG
_fastcall
Exfi386InterlockedExchangeUlong (
     PULONG Target,
     ULONG Value
    );









__declspec(dllimport)
LONG
_fastcall
InterlockedIncrement(
     PLONG Addend
    );

__declspec(dllimport)
LONG
_fastcall
InterlockedDecrement(
     PLONG Addend
    );

__declspec(dllimport)
LONG
_fastcall
InterlockedExchange(
      PLONG Target,
     LONG Value
    );




LONG
_fastcall
InterlockedExchangeAdd(
      PLONG Addend,
     LONG Increment
    );

__declspec(dllimport)
LONG
_fastcall
InterlockedCompareExchange(
      PLONG Destination,
     LONG ExChange,
     LONG Comperand
    );






#line 5274 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"








#pragma warning(disable:4035)               

    







__declspec(dllimport)
KIRQL
KeGetCurrentIrql();






__inline ULONG KeGetCurrentProcessorNumber(void)
{
    __asm {  movzx eax, fs:[0] KPCR.Number  }
}


#line 5308 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


__declspec(dllimport)
NTSTATUS
__stdcall
KeSaveFloatingPointState (
     PKFLOATING_SAVE     FloatSave
    );

__declspec(dllimport)
NTSTATUS
__stdcall
KeRestoreFloatingPointState (
     PKFLOATING_SAVE      FloatSave
    );


#line 5326 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



























#line 5354 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


































































































































































































































































































































































































































































































































































































































































































































































































































#line 6157 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



























































































































































































































































































































































































































































































































































































































































































































































































































































































#line 7017 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"







typedef struct _KSYSTEM_TIME {
    ULONG LowPart;
    LONG High1Time;
    LONG High2Time;
} KSYSTEM_TIME, *PKSYSTEM_TIME;

#line 7031 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"













#pragma warning(push)
#line 7046 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#pragma warning(disable:4164)   
                                

#pragma function(_enable)
#pragma function(_disable)
#line 7052 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


#pragma warning(pop)


#line 7058 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

#line 7060 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#line 7061 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


















































#line 7112 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



typedef struct _FLOATING_SAVE_AREA {
    ULONG   ControlWord;
    ULONG   StatusWord;
    ULONG   TagWord;
    ULONG   ErrorOffset;
    ULONG   ErrorSelector;
    ULONG   DataOffset;
    ULONG   DataSelector;
    UCHAR   RegisterArea[80];
    ULONG   Cr0NpxState;
} FLOATING_SAVE_AREA;

typedef FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;











typedef struct _CONTEXT {

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    ULONG ContextFlags;

    
    
    
    
    

    ULONG   Dr0;
    ULONG   Dr1;
    ULONG   Dr2;
    ULONG   Dr3;
    ULONG   Dr6;
    ULONG   Dr7;

    
    
    
    

    FLOATING_SAVE_AREA FloatSave;

    
    
    
    

    ULONG   SegGs;
    ULONG   SegFs;
    ULONG   SegEs;
    ULONG   SegDs;

    
    
    
    

    ULONG   Edi;
    ULONG   Esi;
    ULONG   Ebx;
    ULONG   Edx;
    ULONG   Ecx;
    ULONG   Eax;

    
    
    
    

    ULONG   Ebp;
    ULONG   Eip;
    ULONG   SegCs;              
    ULONG   EFlags;             
    ULONG   Esp;
    ULONG   SegSs;

    
    
    
    
    

    UCHAR   ExtendedRegisters[512];

} CONTEXT;



typedef CONTEXT *PCONTEXT;



#line 7232 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

#line 7234 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"










#line 7245 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



































































































































































































































































































































































































































































































































































































































typedef
void
(*PTIMER_APC_ROUTINE) (
     PVOID TimerContext,
     ULONG TimerLowValue,
     LONG TimerHighValue
    );

















typedef enum _ALTERNATIVE_ARCHITECTURE_TYPE {
    StandardDesign,                 
    NEC98x86,                       
    EndAlternatives                 
} ALTERNATIVE_ARCHITECTURE_TYPE;

































#line 7919 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"










typedef struct _KUSER_SHARED_DATA {

    
    
    
    
    

    volatile ULONG TickCountLow;
    ULONG TickCountMultiplier;

    
    
    

    volatile KSYSTEM_TIME InterruptTime;


#line 7948 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

    
    
    





#line 7958 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
    volatile KSYSTEM_TIME SystemTime;
#line 7960 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

    
    
    

    volatile KSYSTEM_TIME TimeZoneBias;


#line 7969 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

    
    
    
    
    

    USHORT ImageNumberLow;
    USHORT ImageNumberHigh;

    
    
    

    WCHAR NtSystemRoot[ 260 ];

    
    
    

    ULONG MaxStackTraceDepth;

    
    
    

    ULONG CryptoExponent;

    
    
    

    ULONG TimeZoneId;

    ULONG Reserved2[ 8 ];

    
    
    

    NT_PRODUCT_TYPE NtProductType;
    BOOLEAN ProductTypeIsValid;

    
    
    
    
    

    ULONG NtMajorVersion;
    ULONG NtMinorVersion;

    
    
    

    BOOLEAN ProcessorFeatures[64];

    
    
    
    ULONG Reserved1;
    ULONG Reserved3;

    
    
    

    volatile ULONG TimeSlip;

    
    
    

    ALTERNATIVE_ARCHITECTURE_TYPE AlternativeArchitecture;

    
    
    
    
    
    

    LARGE_INTEGER SystemExpirationDate;

    
    
    
    ULONG SuiteMask;













#line 8072 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

    
    
    
    BOOLEAN KdDebuggerEnabled;

} KUSER_SHARED_DATA, *PKUSER_SHARED_DATA;














                                            



























































typedef enum _CM_SERVICE_NODE_TYPE {
    DriverType               = 0x00000001,
    FileSystemType           = 0x00000002,
    Win32ServiceOwnProcess   = 0x00000010,
    Win32ServiceShareProcess = 0x00000020,
    AdapterType              = 0x00000004,
    RecognizerType           = 0x00000008
} SERVICE_NODE_TYPE;

typedef enum _CM_SERVICE_LOAD_TYPE {
    BootLoad    = 0x00000000,
    SystemLoad  = 0x00000001,
    AutoLoad    = 0x00000002,
    DemandLoad  = 0x00000003,
    DisableLoad = 0x00000004
} SERVICE_LOAD_TYPE;

typedef enum _CM_ERROR_CONTROL_TYPE {
    IgnoreError   = 0x00000000,
    NormalError   = 0x00000001,
    SevereError   = 0x00000002,
    CriticalError = 0x00000003
} SERVICE_ERROR_TYPE;


























typedef int CM_RESOURCE_TYPE;

























typedef enum _CM_SHARE_DISPOSITION {
    CmResourceShareUndetermined = 0,    
    CmResourceShareDeviceExclusive,
    CmResourceShareDriverExclusive,
    CmResourceShareShared
} CM_SHARE_DISPOSITION;







typedef PVOID PASSIGNED_RESOURCE;
#line 8243 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"































































































#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"























#pragma warning(disable:4103)

#pragma pack(push,4)


#line 30 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"
#line 34 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"

#line 8339 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
typedef struct _CM_PARTIAL_RESOURCE_DESCRIPTOR {
    UCHAR Type;
    UCHAR ShareDisposition;
    USHORT Flags;
    union {

        
        
        
        
        

        struct {
            PHYSICAL_ADDRESS Start;
            ULONG Length;
        } Generic;

        
        
        
        
        
        
        

        struct {
            PHYSICAL_ADDRESS Start;
            ULONG Length;
        } Port;

        
        
        
        
        
        

        struct {
            ULONG Level;
            ULONG Vector;
            ULONG Affinity;
        } Interrupt;

        
        
        
        
        

        struct {
            PHYSICAL_ADDRESS Start;    
            ULONG Length;
        } Memory;

        
        
        

        struct {
            ULONG Channel;
            ULONG Port;
            ULONG Reserved1;
        } Dma;

        
        
        
        

        struct {
            ULONG Data[3];
        } DevicePrivate;

        
        
        

        struct {
            ULONG Start;
            ULONG Length;
            ULONG Reserved;
        } BusNumber;

        
        
        
        
        
        

        struct {
            ULONG DataSize;
            ULONG Reserved1;
            ULONG Reserved2;
        } DeviceSpecificData;
    } u;
} CM_PARTIAL_RESOURCE_DESCRIPTOR, *PCM_PARTIAL_RESOURCE_DESCRIPTOR;
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


#line 36 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"
#line 37 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"

#line 8437 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"












typedef struct _CM_PARTIAL_RESOURCE_LIST {
    USHORT Version;
    USHORT Revision;
    ULONG Count;
    CM_PARTIAL_RESOURCE_DESCRIPTOR PartialDescriptors[1];
} CM_PARTIAL_RESOURCE_LIST, *PCM_PARTIAL_RESOURCE_LIST;


















typedef struct _CM_FULL_RESOURCE_DESCRIPTOR {
    INTERFACE_TYPE InterfaceType; 
    ULONG BusNumber; 
    CM_PARTIAL_RESOURCE_LIST PartialResourceList;
} CM_FULL_RESOURCE_DESCRIPTOR, *PCM_FULL_RESOURCE_DESCRIPTOR;






typedef struct _CM_RESOURCE_LIST {
    ULONG Count;
    CM_FULL_RESOURCE_DESCRIPTOR List[1];
} CM_RESOURCE_LIST, *PCM_RESOURCE_LIST;













typedef struct _DEVICE_FLAGS {
    ULONG Failed : 1;
    ULONG ReadOnly : 1;
    ULONG Removable : 1;
    ULONG ConsoleIn : 1;
    ULONG ConsoleOut : 1;
    ULONG Input : 1;
    ULONG Output : 1;
} DEVICE_FLAGS, *PDEVICE_FLAGS;





typedef struct _CM_COMPONENT_INFORMATION {
    DEVICE_FLAGS Flags;
    ULONG Version;
    ULONG Key;
    ULONG AffinityMask;
} CM_COMPONENT_INFORMATION, *PCM_COMPONENT_INFORMATION;












typedef struct _CM_ROM_BLOCK {
    ULONG Address;
    ULONG Size;
} CM_ROM_BLOCK, *PCM_ROM_BLOCK;



#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack1.h"























#pragma warning(disable:4103)

#pragma pack(push,1)


#line 30 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack1.h"


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack1.h"
#line 34 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack1.h"

#line 8541 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"







typedef struct _CM_INT13_DRIVE_PARAMETER {
    USHORT DriveSelect;
    ULONG MaxCylinders;
    USHORT SectorsPerTrack;
    USHORT MaxHeads;
    USHORT NumberDrives;
} CM_INT13_DRIVE_PARAMETER, *PCM_INT13_DRIVE_PARAMETER;







typedef struct _CM_MCA_POS_DATA {
    USHORT AdapterId;
    UCHAR PosData1;
    UCHAR PosData2;
    UCHAR PosData3;
    UCHAR PosData4;
} CM_MCA_POS_DATA, *PCM_MCA_POS_DATA;





typedef struct _EISA_MEMORY_TYPE {
    UCHAR ReadWrite: 1;
    UCHAR Cached : 1;
    UCHAR Reserved0 :1;
    UCHAR Type:2;
    UCHAR Shared:1;
    UCHAR Reserved1 :1;
    UCHAR MoreEntries : 1;
} EISA_MEMORY_TYPE, *PEISA_MEMORY_TYPE;

typedef struct _EISA_MEMORY_CONFIGURATION {
    EISA_MEMORY_TYPE ConfigurationByte;
    UCHAR DataSize;
    USHORT AddressLowWord;
    UCHAR AddressHighByte;
    USHORT MemorySize;
} EISA_MEMORY_CONFIGURATION, *PEISA_MEMORY_CONFIGURATION;






typedef struct _EISA_IRQ_DESCRIPTOR {
    UCHAR Interrupt : 4;
    UCHAR Reserved :1;
    UCHAR LevelTriggered :1;
    UCHAR Shared : 1;
    UCHAR MoreEntries : 1;
} EISA_IRQ_DESCRIPTOR, *PEISA_IRQ_DESCRIPTOR;

typedef struct _EISA_IRQ_CONFIGURATION {
    EISA_IRQ_DESCRIPTOR ConfigurationByte;
    UCHAR Reserved;
} EISA_IRQ_CONFIGURATION, *PEISA_IRQ_CONFIGURATION;






typedef struct _DMA_CONFIGURATION_BYTE0 {
    UCHAR Channel : 3;
    UCHAR Reserved : 3;
    UCHAR Shared :1;
    UCHAR MoreEntries :1;
} DMA_CONFIGURATION_BYTE0;

typedef struct _DMA_CONFIGURATION_BYTE1 {
    UCHAR Reserved0 : 2;
    UCHAR TransferSize : 2;
    UCHAR Timing : 2;
    UCHAR Reserved1 : 2;
} DMA_CONFIGURATION_BYTE1;

typedef struct _EISA_DMA_CONFIGURATION {
    DMA_CONFIGURATION_BYTE0 ConfigurationByte0;
    DMA_CONFIGURATION_BYTE1 ConfigurationByte1;
} EISA_DMA_CONFIGURATION, *PEISA_DMA_CONFIGURATION;






typedef struct _EISA_PORT_DESCRIPTOR {
    UCHAR NumberPorts : 5;
    UCHAR Reserved :1;
    UCHAR Shared :1;
    UCHAR MoreEntries : 1;
} EISA_PORT_DESCRIPTOR, *PEISA_PORT_DESCRIPTOR;

typedef struct _EISA_PORT_CONFIGURATION {
    EISA_PORT_DESCRIPTOR Configuration;
    USHORT PortAddress;
} EISA_PORT_CONFIGURATION, *PEISA_PORT_CONFIGURATION;








typedef struct _CM_EISA_SLOT_INFORMATION {
    UCHAR ReturnCode;
    UCHAR ReturnFlags;
    UCHAR MajorRevision;
    UCHAR MinorRevision;
    USHORT Checksum;
    UCHAR NumberFunctions;
    UCHAR FunctionInformation;
    ULONG CompressedId;
} CM_EISA_SLOT_INFORMATION, *PCM_EISA_SLOT_INFORMATION;






typedef struct _CM_EISA_FUNCTION_INFORMATION {
    ULONG CompressedId;
    UCHAR IdSlotFlags1;
    UCHAR IdSlotFlags2;
    UCHAR MinorRevision;
    UCHAR MajorRevision;
    UCHAR Selections[26];
    UCHAR FunctionFlags;
    UCHAR TypeString[80];
    EISA_MEMORY_CONFIGURATION EisaMemory[9];
    EISA_IRQ_CONFIGURATION EisaIrq[7];
    EISA_DMA_CONFIGURATION EisaDma[4];
    EISA_PORT_CONFIGURATION EisaPort[20];
    UCHAR InitializationData[60];
} CM_EISA_FUNCTION_INFORMATION, *PCM_EISA_FUNCTION_INFORMATION;



















typedef struct _CM_PNP_BIOS_DEVICE_NODE {
    USHORT Size;
    UCHAR Node;
    ULONG ProductId;
    UCHAR DeviceType[3];
    USHORT DeviceAttributes;
    
    
} CM_PNP_BIOS_DEVICE_NODE,*PCM_PNP_BIOS_DEVICE_NODE;





typedef struct _CM_PNP_BIOS_INSTALLATION_CHECK {
    UCHAR Signature[4];             
    UCHAR Revision;
    UCHAR Length;
    USHORT ControlField;
    UCHAR Checksum;
    ULONG EventFlagAddress;         
    USHORT RealModeEntryOffset;
    USHORT RealModeEntrySegment;
    USHORT ProtectedModeEntryOffset;
    ULONG ProtectedModeCodeBaseAddress;
    ULONG OemDeviceId;
    USHORT RealModeDataBaseAddress;
    ULONG ProtectedModeDataBaseAddress;
} CM_PNP_BIOS_INSTALLATION_CHECK, *PCM_PNP_BIOS_INSTALLATION_CHECK;

#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


#line 36 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"
#line 37 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"

#line 8739 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




















































typedef struct _CM_SCSI_DEVICE_DATA {
    USHORT Version;
    USHORT Revision;
    UCHAR HostIdentifier;
} CM_SCSI_DEVICE_DATA, *PCM_SCSI_DEVICE_DATA;









typedef struct _CM_VIDEO_DEVICE_DATA {
    USHORT Version;
    USHORT Revision;
    ULONG VideoClock;
} CM_VIDEO_DEVICE_DATA, *PCM_VIDEO_DEVICE_DATA;





typedef struct _CM_SONIC_DEVICE_DATA {
    USHORT Version;
    USHORT Revision;
    USHORT DataConfigurationRegister;
    UCHAR EthernetAddress[8];
} CM_SONIC_DEVICE_DATA, *PCM_SONIC_DEVICE_DATA;





typedef struct _CM_SERIAL_DEVICE_DATA {
    USHORT Version;
    USHORT Revision;
    ULONG BaudClock;
} CM_SERIAL_DEVICE_DATA, *PCM_SERIAL_DEVICE_DATA;









typedef struct _CM_MONITOR_DEVICE_DATA {
    USHORT Version;
    USHORT Revision;
    USHORT HorizontalScreenSize;
    USHORT VerticalScreenSize;
    USHORT HorizontalResolution;
    USHORT VerticalResolution;
    USHORT HorizontalDisplayTimeLow;
    USHORT HorizontalDisplayTime;
    USHORT HorizontalDisplayTimeHigh;
    USHORT HorizontalBackPorchLow;
    USHORT HorizontalBackPorch;
    USHORT HorizontalBackPorchHigh;
    USHORT HorizontalFrontPorchLow;
    USHORT HorizontalFrontPorch;
    USHORT HorizontalFrontPorchHigh;
    USHORT HorizontalSyncLow;
    USHORT HorizontalSync;
    USHORT HorizontalSyncHigh;
    USHORT VerticalBackPorchLow;
    USHORT VerticalBackPorch;
    USHORT VerticalBackPorchHigh;
    USHORT VerticalFrontPorchLow;
    USHORT VerticalFrontPorch;
    USHORT VerticalFrontPorchHigh;
    USHORT VerticalSyncLow;
    USHORT VerticalSync;
    USHORT VerticalSyncHigh;
} CM_MONITOR_DEVICE_DATA, *PCM_MONITOR_DEVICE_DATA;





typedef struct _CM_FLOPPY_DEVICE_DATA {
    USHORT Version;
    USHORT Revision;
    CHAR Size[8];
    ULONG MaxDensity;
    ULONG MountDensity;
    
    
    
    UCHAR StepRateHeadUnloadTime;
    UCHAR HeadLoadTime;
    UCHAR MotorOffTime;
    UCHAR SectorLengthCode;
    UCHAR SectorPerTrack;
    UCHAR ReadWriteGapLength;
    UCHAR DataTransferLength;
    UCHAR FormatGapLength;
    UCHAR FormatFillCharacter;
    UCHAR HeadSettleTime;
    UCHAR MotorSettleTime;
    UCHAR MaximumTrackValue;
    UCHAR DataTransferRate;
} CM_FLOPPY_DEVICE_DATA, *PCM_FLOPPY_DEVICE_DATA;














typedef struct _CM_KEYBOARD_DEVICE_DATA {
    USHORT Version;
    USHORT Revision;
    UCHAR Type;
    UCHAR Subtype;
    USHORT KeyboardFlags;
} CM_KEYBOARD_DEVICE_DATA, *PCM_KEYBOARD_DEVICE_DATA;





typedef struct _CM_DISK_GEOMETRY_DEVICE_DATA {
    ULONG BytesPerSector;
    ULONG NumberOfCylinders;
    ULONG SectorsPerTrack;
    ULONG NumberOfHeads;
} CM_DISK_GEOMETRY_DEVICE_DATA, *PCM_DISK_GEOMETRY_DEVICE_DATA;






typedef struct _CM_PCCARD_DEVICE_DATA {
    UCHAR Flags;
    UCHAR ErrorCode;
    USHORT Reserved;
    ULONG BusData;
    ULONG DeviceId;
    ULONG LegacyBaseAddress;
    UCHAR IRQMap[16];
} CM_PCCARD_DEVICE_DATA, *PCM_PCCARD_DEVICE_DATA;






























typedef struct _IO_RESOURCE_DESCRIPTOR {
    UCHAR Option;
    UCHAR Type;                         
    UCHAR ShareDisposition;             
    UCHAR Spare1;
    USHORT Flags;                       
    USHORT Spare2;                      

    union {
        struct {
            ULONG Length;
            ULONG Alignment;
            PHYSICAL_ADDRESS MinimumAddress;
            PHYSICAL_ADDRESS MaximumAddress;
        } Port;

        struct {
            ULONG Length;
            ULONG Alignment;
            PHYSICAL_ADDRESS MinimumAddress;
            PHYSICAL_ADDRESS MaximumAddress;
        } Memory;

        struct {
            ULONG MinimumVector;
            ULONG MaximumVector;
        } Interrupt;

        struct {
            ULONG MinimumChannel;
            ULONG MaximumChannel;
        } Dma;

        struct {
            ULONG Length;
            ULONG Alignment;
            PHYSICAL_ADDRESS MinimumAddress;
            PHYSICAL_ADDRESS MaximumAddress;
        } Generic;

        struct {
            ULONG Data[3];
        } DevicePrivate;

        
        
        

        struct {
            ULONG Length;
            ULONG MinBusNumber;
            ULONG MaxBusNumber;
            ULONG Reserved;
        } BusNumber;



        struct {
            PASSIGNED_RESOURCE AssignedResource;
        } AssignedResource;     

        struct {
            UCHAR Type;                 
            UCHAR Reserved[3];
            PASSIGNED_RESOURCE AssignedResource;
            PHYSICAL_ADDRESS Transformation;
        } SubAllocateFrom;      



        struct {
            ULONG Priority;   
            ULONG Reserved1;
            ULONG Reserved2;
        } ConfigData;

    } u;

} IO_RESOURCE_DESCRIPTOR, *PIO_RESOURCE_DESCRIPTOR;




typedef struct _IO_RESOURCE_LIST {
    USHORT Version;
    USHORT Revision;

    ULONG Count;
    IO_RESOURCE_DESCRIPTOR Descriptors[1];
} IO_RESOURCE_LIST, *PIO_RESOURCE_LIST;


typedef struct _IO_RESOURCE_REQUIREMENTS_LIST {
    ULONG ListSize;
    INTERFACE_TYPE InterfaceType; 
    ULONG BusNumber; 
    ULONG SlotNumber;
    ULONG Reserved[3];
    ULONG AlternativeLists;
    IO_RESOURCE_LIST  List[1];
} IO_RESOURCE_REQUIREMENTS_LIST, *PIO_RESOURCE_REQUIREMENTS_LIST;




















typedef struct _EXCEPTION_RECORD {
    NTSTATUS ExceptionCode;
    ULONG ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    ULONG NumberParameters;
    ULONG_PTR ExceptionInformation[15];
    } EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD32 {
    NTSTATUS ExceptionCode;
    ULONG ExceptionFlags;
    ULONG ExceptionRecord;
    ULONG ExceptionAddress;
    ULONG NumberParameters;
    ULONG ExceptionInformation[15];
} EXCEPTION_RECORD32, *PEXCEPTION_RECORD32;

typedef struct _EXCEPTION_RECORD64 {
    NTSTATUS ExceptionCode;
    ULONG ExceptionFlags;
    ULONG64 ExceptionRecord;
    ULONG64 ExceptionAddress;
    ULONG NumberParameters;
    ULONG __unusedAlignment;
    ULONG64 ExceptionInformation[15];
} EXCEPTION_RECORD64, *PEXCEPTION_RECORD64;





typedef struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;








typedef enum _CONFIGURATION_TYPE {
    ArcSystem,
    CentralProcessor,
    FloatingPointProcessor,
    PrimaryIcache,
    PrimaryDcache,
    SecondaryIcache,
    SecondaryDcache,
    SecondaryCache,
    EisaAdapter,
    TcAdapter,
    ScsiAdapter,
    DtiAdapter,
    MultiFunctionAdapter,
    DiskController,
    TapeController,
    CdromController,
    WormController,
    SerialController,
    NetworkController,
    DisplayController,
    ParallelController,
    PointerController,
    KeyboardController,
    AudioController,
    OtherController,
    DiskPeripheral,
    FloppyDiskPeripheral,
    TapePeripheral,
    ModemPeripheral,
    MonitorPeripheral,
    PrinterPeripheral,
    PointerPeripheral,
    KeyboardPeripheral,
    TerminalPeripheral,
    OtherPeripheral,
    LinePeripheral,
    NetworkPeripheral,
    SystemMemory,
    DockingInformation,
    RealModeIrqRoutingTable,
    MaximumType
} CONFIGURATION_TYPE, *PCONFIGURATION_TYPE;







typedef enum _KINTERRUPT_MODE {
    LevelSensitive,
    Latched
    } KINTERRUPT_MODE;





typedef enum _KWAIT_REASON {
    Executive,
    FreePage,
    PageIn,
    PoolAllocation,
    DelayExecution,
    Suspended,
    UserRequest,
    WrExecutive,
    WrFreePage,
    WrPageIn,
    WrPoolAllocation,
    WrDelayExecution,
    WrSuspended,
    WrUserRequest,
    WrEventPair,
    WrQueue,
    WrLpcReceive,
    WrLpcReply,
    WrVirtualMemory,
    WrPageOut,
    WrRendezvous,
    Spare2,
    Spare3,
    Spare4,
    Spare5,
    Spare6,
    WrKernel,
    MaximumWaitReason
    } KWAIT_REASON;







typedef struct _DISPATCHER_HEADER {
    UCHAR Type;
    UCHAR Absolute;
    UCHAR Size;
    UCHAR Inserted;
    LONG SignalState;
    LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER;


typedef struct _KWAIT_BLOCK {
    LIST_ENTRY WaitListEntry;
    struct _KTHREAD * Thread;
    PVOID Object;
    struct _KWAIT_BLOCK * NextWaitBlock;
    USHORT WaitKey;
    USHORT WaitType;
} KWAIT_BLOCK, *PKWAIT_BLOCK, * PRKWAIT_BLOCK;





typedef
void
(*PKSTART_ROUTINE) (
     PVOID StartContext
    );









typedef struct _KDEVICE_QUEUE {
    CSHORT Type;
    CSHORT Size;
    LIST_ENTRY DeviceListHead;
    KSPIN_LOCK Lock;
    BOOLEAN Busy;
} KDEVICE_QUEUE, *PKDEVICE_QUEUE, * PRKDEVICE_QUEUE;

typedef struct _KDEVICE_QUEUE_ENTRY {
    LIST_ENTRY DeviceListEntry;
    ULONG SortKey;
    BOOLEAN Inserted;
} KDEVICE_QUEUE_ENTRY, *PKDEVICE_QUEUE_ENTRY, * PRKDEVICE_QUEUE_ENTRY;






typedef struct _KEVENT {
    DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT, * PRKEVENT;





typedef
BOOLEAN
(*PKSERVICE_ROUTINE) (
     struct _KINTERRUPT *Interrupt,
     PVOID ServiceContext
    );




typedef struct _KMUTANT {
    DISPATCHER_HEADER Header;
    LIST_ENTRY MutantListEntry;
    struct _KTHREAD * OwnerThread;
    BOOLEAN Abandoned;
    UCHAR ApcDisable;
} KMUTANT, *PKMUTANT, * PRKMUTANT, KMUTEX, *PKMUTEX, * PRKMUTEX;






typedef struct _KSEMAPHORE {
    DISPATCHER_HEADER Header;
    LONG Limit;
} KSEMAPHORE, *PKSEMAPHORE, * PRKSEMAPHORE;






typedef struct _KTIMER {
    DISPATCHER_HEADER Header;
    ULARGE_INTEGER DueTime;
    LIST_ENTRY TimerListEntry;
    struct _KDPC *Dpc;
    LONG Period;
} KTIMER, *PKTIMER, * PRKTIMER;





__declspec(dllimport)
void
KeInitializeDpc (
     PRKDPC Dpc,
     PKDEFERRED_ROUTINE DeferredRoutine,
     PVOID DeferredContext
    );

__declspec(dllimport)
BOOLEAN
KeInsertQueueDpc (
     PRKDPC Dpc,
     PVOID SystemArgument1,
     PVOID SystemArgument2
    );

__declspec(dllimport)
BOOLEAN
KeRemoveQueueDpc (
     PRKDPC Dpc
    );



__declspec(dllimport)
void
KeSetImportanceDpc (
     PRKDPC Dpc,
     KDPC_IMPORTANCE Importance
    );

__declspec(dllimport)
void
KeSetTargetProcessorDpc (
     PRKDPC Dpc,
     CCHAR Number
    );






__declspec(dllimport)
void
KeInitializeDeviceQueue (
     PKDEVICE_QUEUE DeviceQueue
    );

__declspec(dllimport)
BOOLEAN
KeInsertDeviceQueue (
     PKDEVICE_QUEUE DeviceQueue,
     PKDEVICE_QUEUE_ENTRY DeviceQueueEntry
    );

__declspec(dllimport)
BOOLEAN
KeInsertByKeyDeviceQueue (
     PKDEVICE_QUEUE DeviceQueue,
     PKDEVICE_QUEUE_ENTRY DeviceQueueEntry,
     ULONG SortKey
    );

__declspec(dllimport)
PKDEVICE_QUEUE_ENTRY
KeRemoveDeviceQueue (
     PKDEVICE_QUEUE DeviceQueue
    );

__declspec(dllimport)
PKDEVICE_QUEUE_ENTRY
KeRemoveByKeyDeviceQueue (
     PKDEVICE_QUEUE DeviceQueue,
     ULONG SortKey
    );

__declspec(dllimport)
BOOLEAN
KeRemoveEntryDeviceQueue (
     PKDEVICE_QUEUE DeviceQueue,
     PKDEVICE_QUEUE_ENTRY DeviceQueueEntry
    );

__declspec(dllimport)                                         
BOOLEAN                                             
KeSynchronizeExecution (                            
     PKINTERRUPT Interrupt,                       
     PKSYNCHRONIZE_ROUTINE SynchronizeRoutine,    
     PVOID SynchronizeContext                     
    );                                              
                                                    







__declspec(dllimport)
void
KeInitializeEvent (
     PRKEVENT Event,
     EVENT_TYPE Type,
     BOOLEAN State
    );

__declspec(dllimport)
void
KeClearEvent (
     PRKEVENT Event
    );

__declspec(dllimport)
LONG
KePulseEvent (
     PRKEVENT Event,
     KPRIORITY Increment,
     BOOLEAN Wait
    );

__declspec(dllimport)
LONG
KeReadStateEvent (
     PRKEVENT Event
    );



__declspec(dllimport)
LONG
KeResetEvent (
     PRKEVENT Event
    );

__declspec(dllimport)
LONG
KeSetEvent (
     PRKEVENT Event,
     KPRIORITY Increment,
     BOOLEAN Wait
    );





__declspec(dllimport)
void
KeInitializeMutex (
     PRKMUTEX Mutex,
     ULONG Level
    );

__declspec(dllimport)
LONG
KeReadStateMutant (
     PRKMUTANT
    );



__declspec(dllimport)
LONG
KeReleaseMutex (
     PRKMUTEX Mutex,
     BOOLEAN Wait
    );





__declspec(dllimport)
void
KeInitializeSemaphore (
     PRKSEMAPHORE Semaphore,
     LONG Count,
     LONG Limit
    );

__declspec(dllimport)
LONG
KeReadStateSemaphore (
     PRKSEMAPHORE Semaphore
    );

__declspec(dllimport)
LONG
KeReleaseSemaphore (
     PRKSEMAPHORE Semaphore,
     KPRIORITY Increment,
     LONG Adjustment,
     BOOLEAN Wait
    );

__declspec(dllimport)                                         
NTSTATUS                                            
KeDelayExecutionThread (                            
     KPROCESSOR_MODE WaitMode,                    
     BOOLEAN Alertable,                           
     PLARGE_INTEGER Interval                      
    );                                              
                                                    
__declspec(dllimport)                                         
KPRIORITY                                           
KeQueryPriorityThread (                             
     PKTHREAD Thread                              
    );                                              
                                                    
__declspec(dllimport)                                         
LONG                                                
KeSetBasePriorityThread (                           
     PKTHREAD Thread,                             
     LONG Increment                               
    );                                              
                                                    
__declspec(dllimport)                                         
KPRIORITY                                           
KeSetPriorityThread (                               
     PKTHREAD Thread,                             
     KPRIORITY Priority                           
    );                                              
                                                    





__declspec(dllimport)
void
KeEnterCriticalRegion (
    void
    );

__declspec(dllimport)
void
KeLeaveCriticalRegion (
    void
    );

































































#line 9652 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"







__declspec(dllimport)
void
KeInitializeTimer (
     PKTIMER Timer
    );

__declspec(dllimport)
void
KeInitializeTimerEx (
     PKTIMER Timer,
     TIMER_TYPE Type
    );

__declspec(dllimport)
BOOLEAN
KeCancelTimer (
     PKTIMER
    );

__declspec(dllimport)
BOOLEAN
KeReadStateTimer (
    PKTIMER Timer
    );

__declspec(dllimport)
BOOLEAN
KeSetTimer (
     PKTIMER Timer,
     LARGE_INTEGER DueTime,
     PKDPC Dpc 
    );

__declspec(dllimport)
BOOLEAN
KeSetTimerEx (
     PKTIMER Timer,
     LARGE_INTEGER DueTime,
     LONG Period ,
     PKDPC Dpc 
    );




__declspec(dllimport)
NTSTATUS
KeWaitForMultipleObjects (
     ULONG Count,
     PVOID Object[],
     WAIT_TYPE WaitType,
     KWAIT_REASON WaitReason,
     KPROCESSOR_MODE WaitMode,
     BOOLEAN Alertable,
     PLARGE_INTEGER Timeout ,
     PKWAIT_BLOCK WaitBlockArray 
    );

__declspec(dllimport)
NTSTATUS
KeWaitForSingleObject (
     PVOID Object,
     KWAIT_REASON WaitReason,
     KPROCESSOR_MODE WaitMode,
     BOOLEAN Alertable,
     PLARGE_INTEGER Timeout 
    );















#line 9742 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"





__declspec(dllimport)
void
__stdcall
KeInitializeSpinLock (
     PKSPIN_LOCK SpinLock
    );



__declspec(dllimport)
void
_fastcall
KefAcquireSpinLockAtDpcLevel (
     PKSPIN_LOCK SpinLock
    );

__declspec(dllimport)
void
_fastcall
KefReleaseSpinLockFromDpcLevel (
     PKSPIN_LOCK SpinLock
    );




__declspec(dllimport)
KIRQL
_fastcall
KfAcquireSpinLock (
     PKSPIN_LOCK SpinLock
    );

__declspec(dllimport)
void
_fastcall
KfReleaseSpinLock (
     PKSPIN_LOCK SpinLock,
     KIRQL NewIrql
    );



__declspec(dllimport)
KIRQL
_fastcall
KeAcquireSpinLockRaiseToSynch (
     PKSPIN_LOCK SpinLock
    );











































#line 9840 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




__declspec(dllimport)
void
_fastcall
KfLowerIrql (
     KIRQL NewIrql
    );

__declspec(dllimport)
KIRQL
_fastcall
KfRaiseIrql (
     KIRQL NewIrql
    );



__declspec(dllimport)
KIRQL
KeRaiseIrqlToDpcLevel(
    void
    );

__declspec(dllimport)
KIRQL
KeRaiseIrqlToSynchLevel(
    void
    );


















































#line 9922 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"







BOOLEAN
KeGetBugMessageText(
     ULONG MessageId,
     PANSI_STRING ReturnedString 
    );

typedef enum _KBUGCHECK_BUFFER_DUMP_STATE {
    BufferEmpty,
    BufferInserted,
    BufferStarted,
    BufferFinished,
    BufferIncomplete
} KBUGCHECK_BUFFER_DUMP_STATE;

typedef
void
(*PKBUGCHECK_CALLBACK_ROUTINE) (
     PVOID Buffer,
     ULONG Length
    );

typedef struct _KBUGCHECK_CALLBACK_RECORD {
    LIST_ENTRY Entry;
    PKBUGCHECK_CALLBACK_ROUTINE CallbackRoutine;
    PVOID Buffer;
    ULONG Length;
    PUCHAR Component;
    ULONG_PTR Checksum;
    UCHAR State;
} KBUGCHECK_CALLBACK_RECORD, *PKBUGCHECK_CALLBACK_RECORD;

__declspec(dllimport)
__declspec(noreturn)
void
__stdcall
KeBugCheck (
     ULONG BugCheckCode
    );



__declspec(dllimport)
__declspec(noreturn)
void
KeBugCheckEx(
     ULONG BugCheckCode,
     ULONG_PTR BugCheckParameter1,
     ULONG_PTR BugCheckParameter2,
     ULONG_PTR BugCheckParameter3,
     ULONG_PTR BugCheckParameter4
    );






__declspec(dllimport)
BOOLEAN
KeDeregisterBugCheckCallback (
     PKBUGCHECK_CALLBACK_RECORD CallbackRecord
    );

__declspec(dllimport)
BOOLEAN
KeRegisterBugCheckCallback (
     PKBUGCHECK_CALLBACK_RECORD CallbackRecord,
     PKBUGCHECK_CALLBACK_ROUTINE CallbackRoutine,
     PVOID Buffer,
     ULONG Length,
     PUCHAR Component
    );

__declspec(dllimport)
void
KeEnterKernelDebugger (
    void
    );


__declspec(dllimport)
ULONGLONG
KeQueryInterruptTime (
    void
    );

__declspec(dllimport)
void
KeQuerySystemTime (
     PLARGE_INTEGER CurrentTime
    );

__declspec(dllimport)
ULONG
KeQueryTimeIncrement (
    void
    );


__declspec(dllimport)
KAFFINITY
KeQueryActiveProcessors (
    void
    );





typedef
void
(_fastcall *PSWAP_CONTEXT_NOTIFY_ROUTINE)(
     HANDLE OldThreadId,
     HANDLE NewThreadId
    );

__declspec(dllimport)
void
_fastcall
KeSetSwapContextNotifyRoutine(
     PSWAP_CONTEXT_NOTIFY_ROUTINE NotifyRoutine
    );





typedef
LOGICAL
(_fastcall *PTHREAD_SELECT_NOTIFY_ROUTINE)(
     HANDLE ThreadId
    );

__declspec(dllimport)
void
_fastcall
KeSetThreadSelectNotifyRoutine(
     PTHREAD_SELECT_NOTIFY_ROUTINE NotifyRoutine
    );





typedef
void
(_fastcall *PTIME_UPDATE_NOTIFY_ROUTINE)(
     HANDLE ThreadId,
     KPROCESSOR_MODE Mode
    );

__declspec(dllimport)
void
_fastcall
KeSetTimeUpdateNotifyRoutine(
     PTIME_UPDATE_NOTIFY_ROUTINE NotifyRoutine
    );

extern volatile KSYSTEM_TIME KeTickCount;           

typedef enum _MEMORY_CACHING_TYPE_ORIG {
    MmFrameBufferCached = 2
} MEMORY_CACHING_TYPE_ORIG;

typedef enum _MEMORY_CACHING_TYPE {
    MmNonCached = 0,
    MmCached = 1,
    MmWriteCombined = MmFrameBufferCached,
    MmHardwareCoherentCached,
    MmNonCachedUnordered,       
    MmUSWCCached,
    MmMaximumCacheType
} MEMORY_CACHING_TYPE;








extern PBOOLEAN KdDebuggerNotPresent;
extern PBOOLEAN KdDebuggerEnabled;






#line 10119 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




typedef struct _DBGKD_DEBUG_DATA_HEADER64 *PDBGKD_DEBUG_DATA_HEADER64;

BOOLEAN
KdRegisterDebuggerDataBlock(
     ULONG Tag,
     PDBGKD_DEBUG_DATA_HEADER64 DataHeader,
     ULONG Size
    );

void
KdDeregisterDebuggerDataBlock32(
     PDBGKD_DEBUG_DATA_HEADER64 DataHeader
    );

void
KdDisableDebugger(
    void
    );

void
KdEnableDebugger(
    void
    );





typedef enum _POOL_TYPE {
    NonPagedPool,
    PagedPool,
    NonPagedPoolMustSucceed,
    DontUseThisType,
    NonPagedPoolCacheAligned,
    PagedPoolCacheAligned,
    NonPagedPoolCacheAlignedMustS,
    MaxPoolType

    
    ,
    
    
    
    

    NonPagedPoolSession = 32,
    PagedPoolSession = NonPagedPoolSession + 1,
    NonPagedPoolMustSucceedSession = PagedPoolSession + 1,
    DontUseThisTypeSession = NonPagedPoolMustSucceedSession + 1,
    NonPagedPoolCacheAlignedSession = DontUseThisTypeSession + 1,
    PagedPoolCacheAlignedSession = NonPagedPoolCacheAlignedSession + 1,
    NonPagedPoolCacheAlignedMustSSession = PagedPoolCacheAlignedSession + 1,

    

    } POOL_TYPE;


__declspec(dllimport)
PVOID
ExAllocatePool(
     POOL_TYPE PoolType,
     SIZE_T NumberOfBytes
    );

__declspec(dllimport)
PVOID
ExAllocatePoolWithQuota(
     POOL_TYPE PoolType,
     SIZE_T NumberOfBytes
    );

__declspec(dllimport)
PVOID
__stdcall
ExAllocatePoolWithTag(
     POOL_TYPE PoolType,
     SIZE_T NumberOfBytes,
     ULONG Tag
    );




























typedef enum _EX_POOL_PRIORITY {
    LowPoolPriority,
    LowPoolPrioritySpecialPoolOverrun = 8,
    LowPoolPrioritySpecialPoolUnderrun = 9,
    NormalPoolPriority = 16,
    NormalPoolPrioritySpecialPoolOverrun = 24,
    NormalPoolPrioritySpecialPoolUnderrun = 25,
    HighPoolPriority = 32,
    HighPoolPrioritySpecialPoolOverrun = 40,
    HighPoolPrioritySpecialPoolUnderrun = 41

    } EX_POOL_PRIORITY;

__declspec(dllimport)
PVOID
__stdcall
ExAllocatePoolWithTagPriority(
     POOL_TYPE PoolType,
     SIZE_T NumberOfBytes,
     ULONG Tag,
     EX_POOL_PRIORITY Priority
    );







__declspec(dllimport)
PVOID
ExAllocatePoolWithQuotaTag(
     POOL_TYPE PoolType,
     SIZE_T NumberOfBytes,
     ULONG Tag
    );





__declspec(dllimport)
void
__stdcall
ExFreePool(
     PVOID P
    );





typedef struct _FAST_MUTEX {
    LONG Count;
    PKTHREAD Owner;
    ULONG Contention;
    KEVENT Event;
    ULONG OldIrql;
} FAST_MUTEX, *PFAST_MUTEX;
















#line 10307 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
void
_fastcall
ExAcquireFastMutexUnsafe (
     PFAST_MUTEX FastMutex
    );

__declspec(dllimport)
void
_fastcall
ExReleaseFastMutexUnsafe (
     PFAST_MUTEX FastMutex
    );




























#line 10350 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
void
_fastcall
ExAcquireFastMutex (
     PFAST_MUTEX FastMutex
    );

__declspec(dllimport)
void
_fastcall
ExReleaseFastMutex (
     PFAST_MUTEX FastMutex
    );



__declspec(dllimport)
BOOLEAN
_fastcall
ExTryToAcquireFastMutex (
     PFAST_MUTEX FastMutex
    );







#line 10381 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



__declspec(dllimport)
void
_fastcall
ExInterlockedAddLargeStatistic (
     PLARGE_INTEGER Addend,
     ULONG Increment
    );



__declspec(dllimport)
LARGE_INTEGER
ExInterlockedAddLargeInteger (
     PLARGE_INTEGER Addend,
     LARGE_INTEGER Increment,
     PKSPIN_LOCK Lock
    );


__declspec(dllimport)
ULONG
_fastcall
ExfInterlockedAddUlong (
     PULONG Addend,
     ULONG Increment,
     PKSPIN_LOCK Lock
    );







#line 10419 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




#line 10424 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




#line 10429 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
LONGLONG
_fastcall
ExInterlockedCompareExchange64 (
     PLONGLONG Destination,
     PLONGLONG Exchange,
     PLONGLONG Comperand,
     PKSPIN_LOCK Lock
    );

#line 10441 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
PLIST_ENTRY
_fastcall
ExfInterlockedInsertHeadList (
     PLIST_ENTRY ListHead,
     PLIST_ENTRY ListEntry,
     PKSPIN_LOCK Lock
    );

__declspec(dllimport)
PLIST_ENTRY
_fastcall
ExfInterlockedInsertTailList (
     PLIST_ENTRY ListHead,
     PLIST_ENTRY ListEntry,
     PKSPIN_LOCK Lock
    );

__declspec(dllimport)
PLIST_ENTRY
_fastcall
ExfInterlockedRemoveHeadList (
     PLIST_ENTRY ListHead,
     PKSPIN_LOCK Lock
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY
_fastcall
ExfInterlockedPopEntryList (
     PSINGLE_LIST_ENTRY ListHead,
     PKSPIN_LOCK Lock
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY
_fastcall
ExfInterlockedPushEntryList (
     PSINGLE_LIST_ENTRY ListHead,
     PSINGLE_LIST_ENTRY ListEntry,
     PKSPIN_LOCK Lock
    );

































































































#line 10582 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
PSINGLE_LIST_ENTRY
_fastcall
ExInterlockedPopEntrySList (
     PSLIST_HEADER ListHead,
     PKSPIN_LOCK Lock
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY
_fastcall
ExInterlockedPushEntrySList (
     PSLIST_HEADER ListHead,
     PSINGLE_LIST_ENTRY ListEntry,
     PKSPIN_LOCK Lock
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY
_fastcall
ExInterlockedFlushSList (
     PSLIST_HEADER ListHead
    );

#line 10608 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


typedef
PVOID
(*PALLOCATE_FUNCTION) (
     POOL_TYPE PoolType,
     SIZE_T NumberOfBytes,
     ULONG Tag
    );

typedef
void
(*PFREE_FUNCTION) (
     PVOID Buffer
    );

typedef struct _GENERAL_LOOKASIDE {
    SLIST_HEADER ListHead;
    USHORT Depth;
    USHORT MaximumDepth;
    ULONG TotalAllocates;
    union {
        ULONG AllocateMisses;
        ULONG AllocateHits;
    };

    ULONG TotalFrees;
    union {
        ULONG FreeMisses;
        ULONG FreeHits;
    };

    POOL_TYPE Type;
    ULONG Tag;
    ULONG Size;
    PALLOCATE_FUNCTION Allocate;
    PFREE_FUNCTION Free;
    LIST_ENTRY ListEntry;
    ULONG LastTotalAllocates;
    union {
        ULONG LastAllocateMisses;
        ULONG LastAllocateHits;
    };

    ULONG Future[2];
} GENERAL_LOOKASIDE, *PGENERAL_LOOKASIDE;

typedef struct _NPAGED_LOOKASIDE_LIST {
    GENERAL_LOOKASIDE L;
    KSPIN_LOCK Lock;
} NPAGED_LOOKASIDE_LIST, *PNPAGED_LOOKASIDE_LIST;


__declspec(dllimport)
void
ExInitializeNPagedLookasideList (
     PNPAGED_LOOKASIDE_LIST Lookaside,
     PALLOCATE_FUNCTION Allocate,
     PFREE_FUNCTION Free,
     ULONG Flags,
     SIZE_T Size,
     ULONG Tag,
     USHORT Depth
    );

__declspec(dllimport)
void
ExDeleteNPagedLookasideList (
     PNPAGED_LOOKASIDE_LIST Lookaside
    );

__inline
PVOID
ExAllocateFromNPagedLookasideList(
     PNPAGED_LOOKASIDE_LIST Lookaside
    )




















{

    PVOID Entry;

    Lookaside->L.TotalAllocates += 1;
    Entry = ExInterlockedPopEntrySList(&Lookaside->L.ListHead, &Lookaside->Lock);
    if (Entry == ((void *)0)) {
        Lookaside->L.AllocateMisses += 1;
        Entry = (Lookaside->L.Allocate)(Lookaside->L.Type,
                                        Lookaside->L.Size,
                                        Lookaside->L.Tag);
    }

    return Entry;
}

__inline
void
ExFreeToNPagedLookasideList(
     PNPAGED_LOOKASIDE_LIST Lookaside,
     PVOID Entry
    )





















{

    Lookaside->L.TotalFrees += 1;
    if ((USHORT)(&Lookaside->L.ListHead)->Depth >= Lookaside->L.Depth) {
        Lookaside->L.FreeMisses += 1;
        (Lookaside->L.Free)(Entry);

    } else {
        ExInterlockedPushEntrySList(&Lookaside->L.ListHead,
                                    (PSINGLE_LIST_ENTRY)Entry,
                                    &Lookaside->Lock);
    }

    return;
}



typedef struct _PAGED_LOOKASIDE_LIST {
    GENERAL_LOOKASIDE L;
    FAST_MUTEX Lock;
} PAGED_LOOKASIDE_LIST, *PPAGED_LOOKASIDE_LIST;

__declspec(dllimport)
void
ExInitializePagedLookasideList (
     PPAGED_LOOKASIDE_LIST Lookaside,
     PALLOCATE_FUNCTION Allocate,
     PFREE_FUNCTION Free,
     ULONG Flags,
     SIZE_T Size,
     ULONG Tag,
     USHORT Depth
    );

__declspec(dllimport)
void
ExDeletePagedLookasideList (
     PPAGED_LOOKASIDE_LIST Lookaside
    );



__declspec(dllimport)
PVOID
ExAllocateFromPagedLookasideList(
     PPAGED_LOOKASIDE_LIST Lookaside
    );

__declspec(dllimport)
void
ExFreeToPagedLookasideList(
     PPAGED_LOOKASIDE_LIST Lookaside,
     PVOID Entry
    );























































































#line 10890 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


__declspec(dllimport)
void
__stdcall
ProbeForRead(
     const void *Address,
     ULONG Length,
     ULONG Alignment
    );





__declspec(dllimport)
void
__stdcall
ProbeForWrite (
     PVOID Address,
     ULONG Length,
     ULONG Alignment
    );





typedef enum _WORK_QUEUE_TYPE {
    CriticalWorkQueue,
    DelayedWorkQueue,
    HyperCriticalWorkQueue,
    MaximumWorkQueue
} WORK_QUEUE_TYPE;

typedef
void
(*PWORKER_THREAD_ROUTINE)(
     PVOID Parameter
    );

typedef struct _WORK_QUEUE_ITEM {
    LIST_ENTRY List;
    PWORKER_THREAD_ROUTINE WorkerRoutine;
    PVOID Parameter;
} WORK_QUEUE_ITEM, *PWORK_QUEUE_ITEM;







__declspec(dllimport)
void
ExQueueWorkItem(
     PWORK_QUEUE_ITEM WorkItem,
     WORK_QUEUE_TYPE QueueType
    );



__declspec(dllimport)
BOOLEAN
ExIsProcessorFeaturePresent(
    ULONG ProcessorFeature
    );





typedef struct _ZONE_SEGMENT_HEADER {
    SINGLE_LIST_ENTRY SegmentList;
    PVOID Reserved;
} ZONE_SEGMENT_HEADER, *PZONE_SEGMENT_HEADER;

typedef struct _ZONE_HEADER {
    SINGLE_LIST_ENTRY FreeList;
    SINGLE_LIST_ENTRY SegmentList;
    ULONG BlockSize;
    ULONG TotalSegmentSize;
} ZONE_HEADER, *PZONE_HEADER;


__declspec(dllimport)
NTSTATUS
ExInitializeZone(
     PZONE_HEADER Zone,
     ULONG BlockSize,
     PVOID InitialSegment,
     ULONG InitialSegmentSize
    );

__declspec(dllimport)
NTSTATUS
ExExtendZone(
     PZONE_HEADER Zone,
     PVOID Segment,
     ULONG SegmentSize
    );

__declspec(dllimport)
NTSTATUS
ExInterlockedExtendZone(
     PZONE_HEADER Zone,
     PVOID Segment,
     ULONG SegmentSize,
     PKSPIN_LOCK Lock
    );
































































































































































































typedef ULONG_PTR ERESOURCE_THREAD;
typedef ERESOURCE_THREAD *PERESOURCE_THREAD;

typedef struct _OWNER_ENTRY {
    ERESOURCE_THREAD OwnerThread;
    union {
        LONG OwnerCount;
        ULONG TableSize;
    };

} OWNER_ENTRY, *POWNER_ENTRY;

typedef struct _ERESOURCE {
    LIST_ENTRY SystemResourcesList;
    POWNER_ENTRY OwnerTable;
    SHORT ActiveCount;
    USHORT Flag;
    PKSEMAPHORE SharedWaiters;
    PKEVENT ExclusiveWaiters;
    OWNER_ENTRY OwnerThreads[2];
    ULONG ContentionCount;
    USHORT NumberOfSharedWaiters;
    USHORT NumberOfExclusiveWaiters;
    union {
        PVOID Address;
        ULONG_PTR CreatorBackTraceIndex;
    };

    KSPIN_LOCK SpinLock;
} ERESOURCE, *PERESOURCE;











typedef struct _RESOURCE_HASH_ENTRY {
    LIST_ENTRY ListEntry;
    PVOID Address;
    ULONG ContentionCount;
    ULONG Number;
} RESOURCE_HASH_ENTRY, *PRESOURCE_HASH_ENTRY;

typedef struct _RESOURCE_PERFORMANCE_DATA {
    ULONG ActiveResourceCount;
    ULONG TotalResourceCount;
    ULONG ExclusiveAcquire;
    ULONG SharedFirstLevel;
    ULONG SharedSecondLevel;
    ULONG StarveFirstLevel;
    ULONG StarveSecondLevel;
    ULONG WaitForExclusive;
    ULONG OwnerTableExpands;
    ULONG MaximumTableExpand;
    LIST_ENTRY HashTable[64];
} RESOURCE_PERFORMANCE_DATA, *PRESOURCE_PERFORMANCE_DATA;





__declspec(dllimport)
NTSTATUS
ExInitializeResourceLite(
     PERESOURCE Resource
    );

__declspec(dllimport)
NTSTATUS
ExReinitializeResourceLite(
     PERESOURCE Resource
    );

__declspec(dllimport)
BOOLEAN
ExAcquireResourceSharedLite(
     PERESOURCE Resource,
     BOOLEAN Wait
    );

__declspec(dllimport)
BOOLEAN
ExAcquireResourceExclusiveLite(
     PERESOURCE Resource,
     BOOLEAN Wait
    );

__declspec(dllimport)
BOOLEAN
ExAcquireSharedStarveExclusive(
     PERESOURCE Resource,
     BOOLEAN Wait
    );

__declspec(dllimport)
BOOLEAN
ExAcquireSharedWaitForExclusive(
     PERESOURCE Resource,
     BOOLEAN Wait
    );

__declspec(dllimport)
BOOLEAN
ExTryToAcquireResourceExclusiveLite(
     PERESOURCE Resource
    );










__declspec(dllimport)
void
_fastcall
ExReleaseResourceLite(
     PERESOURCE Resource
    );

__declspec(dllimport)
void
ExReleaseResourceForThreadLite(
     PERESOURCE Resource,
     ERESOURCE_THREAD ResourceThreadId
    );

__declspec(dllimport)
void
ExSetResourceOwnerPointer(
     PERESOURCE Resource,
     PVOID OwnerPointer
    );

__declspec(dllimport)
void
ExConvertExclusiveToSharedLite(
     PERESOURCE Resource
    );

__declspec(dllimport)
NTSTATUS
ExDeleteResourceLite (
     PERESOURCE Resource
    );

__declspec(dllimport)
ULONG
ExGetExclusiveWaiterCount (
     PERESOURCE Resource
    );

__declspec(dllimport)
ULONG
ExGetSharedWaiterCount (
     PERESOURCE Resource
    );









__declspec(dllimport)
BOOLEAN
ExIsResourceAcquiredExclusiveLite (
     PERESOURCE Resource
    );

__declspec(dllimport)
ULONG
ExIsResourceAcquiredSharedLite (
     PERESOURCE Resource
    );



















__declspec(dllimport)
KPROCESSOR_MODE
ExGetPreviousMode(
    void
    );




__declspec(dllimport)
void
__stdcall
ExRaiseStatus (
     NTSTATUS Status
    );



__declspec(dllimport)
void
ExRaiseDatatypeMisalignment (
    void
    );

__declspec(dllimport)
void
ExRaiseAccessViolation (
    void
    );





__declspec(dllimport)
ULONG
ExSetTimerResolution (
     ULONG DesiredTime,
     BOOLEAN SetResolution
    );






__declspec(dllimport)
void
ExSystemTimeToLocalTime (
     PLARGE_INTEGER SystemTime,
     PLARGE_INTEGER LocalTime
    );





__declspec(dllimport)
void
ExLocalTimeToSystemTime (
     PLARGE_INTEGER LocalTime,
     PLARGE_INTEGER SystemTime
    );






typedef struct _CALLBACK_OBJECT *PCALLBACK_OBJECT;

typedef void (*PCALLBACK_FUNCTION ) (
     PVOID CallbackContext,
     PVOID Argument1,
     PVOID Argument2
    );


__declspec(dllimport)
NTSTATUS
ExCreateCallback (
     PCALLBACK_OBJECT *CallbackObject,
     POBJECT_ATTRIBUTES ObjectAttributes,
     BOOLEAN Create,
     BOOLEAN AllowMultipleCallbacks
    );

__declspec(dllimport)
PVOID
ExRegisterCallback (
     PCALLBACK_OBJECT CallbackObject,
     PCALLBACK_FUNCTION CallbackFunction,
     PVOID CallbackContext
    );

__declspec(dllimport)
void
ExUnregisterCallback (
     PVOID CallbackRegistration
    );

__declspec(dllimport)
void
ExNotifyCallback (
     PVOID CallbackObject,
     PVOID Argument1,
     PVOID Argument2
    );






typedef GUID UUID;

__declspec(dllimport)
NTSTATUS
ExUuidCreate(
     UUID *Uuid
    );



















































































































extern PBOOLEAN Mm64BitPhysicalAddress;









































































































































































































































































typedef enum _MM_SYSTEM_SIZE {
    MmSmallSystem,
    MmMediumSystem,
    MmLargeSystem
} MM_SYSTEMSIZE;

__declspec(dllimport)
MM_SYSTEMSIZE
MmQuerySystemSize(
    void
    );



__declspec(dllimport)
BOOLEAN
MmIsThisAnNtAsSystem(
    void
    );



typedef enum _LOCK_OPERATION {
    IoReadAccess,
    IoWriteAccess,
    IoModifyAccess
} LOCK_OPERATION;


__declspec(dllimport)
void
MmProbeAndLockProcessPages (
      PMDL MemoryDescriptorList,
     PEPROCESS Process,
     KPROCESSOR_MODE AccessMode,
     LOCK_OPERATION Operation
    );







__declspec(dllimport)
void
MmProbeAndLockPages (
      PMDL MemoryDescriptorList,
     KPROCESSOR_MODE AccessMode,
     LOCK_OPERATION Operation
    );


__declspec(dllimport)
void
MmUnlockPages (
     PMDL MemoryDescriptorList
    );

__declspec(dllimport)
void
MmBuildMdlForNonPagedPool (
      PMDL MemoryDescriptorList
    );

__declspec(dllimport)
PVOID
MmMapLockedPages (
     PMDL MemoryDescriptorList,
     KPROCESSOR_MODE AccessMode
    );

__declspec(dllimport)
PVOID
MmGetSystemRoutineAddress (
     PUNICODE_STRING SystemRoutineName
    );



__declspec(dllimport)
NTSTATUS
MmMapUserAddressesToPage (
     PVOID BaseAddress,
     SIZE_T NumberOfBytes,
     PVOID PageAddress
    );





















typedef enum _MM_PAGE_PRIORITY {
    LowPagePriority,
    NormalPagePriority = 16,
    HighPagePriority = 32
} MM_PAGE_PRIORITY;




__declspec(dllimport)
PVOID
MmMapLockedPagesSpecifyCache (
      PMDL MemoryDescriptorList,
      KPROCESSOR_MODE AccessMode,
      MEMORY_CACHING_TYPE CacheType,
      PVOID BaseAddress,
      ULONG BugCheckOnFailure,
      MM_PAGE_PRIORITY Priority
     );

__declspec(dllimport)
void
MmUnmapLockedPages (
     PVOID BaseAddress,
     PMDL MemoryDescriptorList
    );



typedef struct _PHYSICAL_MEMORY_RANGE {
    PHYSICAL_ADDRESS BaseAddress;
    LARGE_INTEGER NumberOfBytes;
} PHYSICAL_MEMORY_RANGE, *PPHYSICAL_MEMORY_RANGE;

__declspec(dllimport)
NTSTATUS
MmAddPhysicalMemory (
     PPHYSICAL_ADDRESS StartAddress,
      PLARGE_INTEGER NumberOfBytes
    );

__declspec(dllimport)
NTSTATUS
MmRemovePhysicalMemory (
     PPHYSICAL_ADDRESS StartAddress,
      PLARGE_INTEGER NumberOfBytes
    );

__declspec(dllimport)
PPHYSICAL_MEMORY_RANGE
MmGetPhysicalMemoryRanges (
    void
    );

__declspec(dllimport)
PMDL
MmAllocatePagesForMdl (
     PHYSICAL_ADDRESS LowAddress,
     PHYSICAL_ADDRESS HighAddress,
     PHYSICAL_ADDRESS SkipBytes,
     SIZE_T TotalBytes
    );

__declspec(dllimport)
void
MmFreePagesFromMdl (
     PMDL MemoryDescriptorList
    );



__declspec(dllimport)
PVOID
MmMapIoSpace (
     PHYSICAL_ADDRESS PhysicalAddress,
     SIZE_T NumberOfBytes,
     MEMORY_CACHING_TYPE CacheType
    );

__declspec(dllimport)
void
MmUnmapIoSpace (
     PVOID BaseAddress,
     SIZE_T NumberOfBytes
    );


__declspec(dllimport)
PVOID
MmMapVideoDisplay (
     PHYSICAL_ADDRESS PhysicalAddress,
     SIZE_T NumberOfBytes,
     MEMORY_CACHING_TYPE CacheType
     );

__declspec(dllimport)
void
MmUnmapVideoDisplay (
      PVOID BaseAddress,
      SIZE_T NumberOfBytes
     );

__declspec(dllimport)
PHYSICAL_ADDRESS
MmGetPhysicalAddress (
     PVOID BaseAddress
    );

__declspec(dllimport)
PVOID
MmGetVirtualForPhysical (
     PHYSICAL_ADDRESS PhysicalAddress
    );

__declspec(dllimport)
PVOID
MmAllocateContiguousMemory (
     SIZE_T NumberOfBytes,
     PHYSICAL_ADDRESS HighestAcceptableAddress
    );

__declspec(dllimport)
PVOID
MmAllocateContiguousMemorySpecifyCache (
     SIZE_T NumberOfBytes,
     PHYSICAL_ADDRESS LowestAcceptableAddress,
     PHYSICAL_ADDRESS HighestAcceptableAddress,
     PHYSICAL_ADDRESS BoundaryAddressMultiple ,
     MEMORY_CACHING_TYPE CacheType
    );

__declspec(dllimport)
void
MmFreeContiguousMemory (
     PVOID BaseAddress
    );

__declspec(dllimport)
void
MmFreeContiguousMemorySpecifyCache (
     PVOID BaseAddress,
     SIZE_T NumberOfBytes,
     MEMORY_CACHING_TYPE CacheType
    );


__declspec(dllimport)
PVOID
MmAllocateNonCachedMemory (
     SIZE_T NumberOfBytes
    );

__declspec(dllimport)
void
MmFreeNonCachedMemory (
     PVOID BaseAddress,
     SIZE_T NumberOfBytes
    );

__declspec(dllimport)
BOOLEAN
MmIsAddressValid (
     PVOID VirtualAddress
    );

__declspec(dllimport)
BOOLEAN
MmIsNonPagedSystemAddressValid (
     PVOID VirtualAddress
    );



__declspec(dllimport)
SIZE_T
MmSizeOfMdl(
     PVOID Base,
     SIZE_T Length
    );

__declspec(dllimport)
PMDL
MmCreateMdl(
     PMDL MemoryDescriptorList ,
     PVOID Base,
     SIZE_T Length
    );

__declspec(dllimport)
PVOID
MmLockPagableDataSection(
     PVOID AddressWithinSection
    );



__declspec(dllimport)
void
MmLockPagableSectionByHandle (
     PVOID ImageSectionHandle
    );

__declspec(dllimport)
void
MmResetDriverPaging (
     PVOID AddressWithinSection
    );


__declspec(dllimport)
PVOID
MmPageEntireDriver (
     PVOID AddressWithinSection
    );

__declspec(dllimport)
void
MmUnlockPagableImageSection(
     PVOID ImageSectionHandle
    );



__declspec(dllimport)
HANDLE
MmSecureVirtualMemory (
     PVOID Address,
     SIZE_T Size,
     ULONG ProbeMode
    );

__declspec(dllimport)
void
MmUnsecureVirtualMemory (
     HANDLE SecureHandle
    );

__declspec(dllimport)
NTSTATUS
MmMapViewInSystemSpace (
     PVOID Section,
     PVOID *MappedBase,
     PSIZE_T ViewSize
    );

__declspec(dllimport)
NTSTATUS
MmUnmapViewInSystemSpace (
     PVOID MappedBase
    );

__declspec(dllimport)
NTSTATUS
MmMapViewInSessionSpace (
     PVOID Section,
     PVOID *MappedBase,
      PSIZE_T ViewSize
    );

__declspec(dllimport)
NTSTATUS
MmUnmapViewInSessionSpace (
     PVOID MappedBase
    );























































































































































typedef NTSTATUS (*PMM_DLL_INITIALIZE)(
     PUNICODE_STRING RegistryPath
    );

typedef NTSTATUS (*PMM_DLL_UNLOAD)(
    void
    );







struct _DRIVER_OBJECT;

__declspec(dllimport)
LOGICAL
MmIsDriverVerifying (
     struct _DRIVER_OBJECT *DriverObject
    );





typedef enum _SECURITY_OPERATION_CODE {
    SetSecurityDescriptor,
    QuerySecurityDescriptor,
    DeleteSecurityDescriptor,
    AssignSecurityDescriptor
    } SECURITY_OPERATION_CODE, *PSECURITY_OPERATION_CODE;









typedef struct _SECURITY_SUBJECT_CONTEXT {
    PACCESS_TOKEN ClientToken;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    PACCESS_TOKEN PrimaryToken;
    PVOID ProcessAuditId;
    } SECURITY_SUBJECT_CONTEXT, *PSECURITY_SUBJECT_CONTEXT;
















typedef struct _INITIAL_PRIVILEGE_SET {
    ULONG PrivilegeCount;
    ULONG Control;
    LUID_AND_ATTRIBUTES Privilege[3];
    } INITIAL_PRIVILEGE_SET, * PINITIAL_PRIVILEGE_SET;









typedef struct _ACCESS_STATE {
   LUID OperationID;
   BOOLEAN SecurityEvaluated;
   BOOLEAN GenerateAudit;
   BOOLEAN GenerateOnClose;
   BOOLEAN PrivilegesAllocated;
   ULONG Flags;
   ACCESS_MASK RemainingDesiredAccess;
   ACCESS_MASK PreviouslyGrantedAccess;
   ACCESS_MASK OriginalDesiredAccess;
   SECURITY_SUBJECT_CONTEXT SubjectSecurityContext;
   PSECURITY_DESCRIPTOR SecurityDescriptor;
   PVOID AuxData;
   union {
      INITIAL_PRIVILEGE_SET InitialPrivilegeSet;
      PRIVILEGE_SET PrivilegeSet;
      } Privileges;

   BOOLEAN AuditPrivileges;
   UNICODE_STRING ObjectName;
   UNICODE_STRING ObjectTypeName;

   } ACCESS_STATE, *PACCESS_STATE;


__declspec(dllimport)
NTSTATUS
SeAssignSecurity (
     PSECURITY_DESCRIPTOR ParentDescriptor ,
     PSECURITY_DESCRIPTOR ExplicitDescriptor,
     PSECURITY_DESCRIPTOR *NewDescriptor,
     BOOLEAN IsDirectoryObject,
     PSECURITY_SUBJECT_CONTEXT SubjectContext,
     PGENERIC_MAPPING GenericMapping,
     POOL_TYPE PoolType
    );

__declspec(dllimport)
NTSTATUS
SeAssignSecurityEx (
     PSECURITY_DESCRIPTOR ParentDescriptor ,
     PSECURITY_DESCRIPTOR ExplicitDescriptor ,
     PSECURITY_DESCRIPTOR *NewDescriptor,
     GUID *ObjectType ,
     BOOLEAN IsDirectoryObject,
     ULONG AutoInheritFlags,
     PSECURITY_SUBJECT_CONTEXT SubjectContext,
     PGENERIC_MAPPING GenericMapping,
     POOL_TYPE PoolType
    );

__declspec(dllimport)
NTSTATUS
SeDeassignSecurity (
      PSECURITY_DESCRIPTOR *SecurityDescriptor
    );

__declspec(dllimport)
BOOLEAN
SeAccessCheck (
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PSECURITY_SUBJECT_CONTEXT SubjectSecurityContext,
     BOOLEAN SubjectContextLocked,
     ACCESS_MASK DesiredAccess,
     ACCESS_MASK PreviouslyGrantedAccess,
     PPRIVILEGE_SET *Privileges ,
     PGENERIC_MAPPING GenericMapping,
     KPROCESSOR_MODE AccessMode,
     PACCESS_MASK GrantedAccess,
     PNTSTATUS AccessStatus
    );


__declspec(dllimport)
BOOLEAN
SeValidSecurityDescriptor(
     ULONG Length,
     PSECURITY_DESCRIPTOR SecurityDescriptor
    );

__declspec(dllimport)                                                     
BOOLEAN                                                         
SeSinglePrivilegeCheck(                                         
    LUID PrivilegeValue,                                        
    KPROCESSOR_MODE PreviousMode                                
    );                                                          




__declspec(dllimport)
NTSTATUS
PsCreateSystemThread(
     PHANDLE ThreadHandle,
     ULONG DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes ,
     HANDLE ProcessHandle ,
     PCLIENT_ID ClientId ,
     PKSTART_ROUTINE StartRoutine,
     PVOID StartContext
    );

__declspec(dllimport)
NTSTATUS
PsTerminateSystemThread(
     NTSTATUS ExitStatus
    );


typedef
void
(*PCREATE_PROCESS_NOTIFY_ROUTINE)(
     HANDLE ParentId,
     HANDLE ProcessId,
     BOOLEAN Create
    );

NTSTATUS
PsSetCreateProcessNotifyRoutine(
     PCREATE_PROCESS_NOTIFY_ROUTINE NotifyRoutine,
     BOOLEAN Remove
    );

typedef
void
(*PCREATE_THREAD_NOTIFY_ROUTINE)(
     HANDLE ProcessId,
     HANDLE ThreadId,
     BOOLEAN Create
    );

NTSTATUS
PsSetCreateThreadNotifyRoutine(
     PCREATE_THREAD_NOTIFY_ROUTINE NotifyRoutine
    );





typedef struct _IMAGE_INFO {
    union {
        ULONG Properties;
        struct {
            ULONG ImageAddressingMode  : 8;  
            ULONG SystemModeImage      : 1;  
            ULONG ImageMappedToAllPids : 1;  
            ULONG Reserved             : 22;
        };
    };
    PVOID       ImageBase;
    ULONG       ImageSelector;
    SIZE_T      ImageSize;
    ULONG       ImageSectionNumber;
} IMAGE_INFO, *PIMAGE_INFO;



typedef
void
(*PLOAD_IMAGE_NOTIFY_ROUTINE)(
     PUNICODE_STRING FullImageName,
     HANDLE ProcessId,                
     PIMAGE_INFO ImageInfo
    );

NTSTATUS
PsSetLoadImageNotifyRoutine(
     PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine
    );

HANDLE
PsGetCurrentProcessId( void );

HANDLE
PsGetCurrentThreadId( void );

BOOLEAN
PsGetVersion(
    PULONG MajorVersion ,
    PULONG MinorVersion ,
    PULONG BuildNumber ,
    PUNICODE_STRING CSDVersion 
    );





















































































































































































































typedef NTSTATUS (*PIO_QUERY_DEVICE_ROUTINE)(
     PVOID Context,
     PUNICODE_STRING PathName,
     INTERFACE_TYPE BusType,
     ULONG BusNumber,
     PKEY_VALUE_FULL_INFORMATION *BusInformation,
     CONFIGURATION_TYPE ControllerType,
     ULONG ControllerNumber,
     PKEY_VALUE_FULL_INFORMATION *ControllerInformation,
     CONFIGURATION_TYPE PeripheralType,
     ULONG PeripheralNumber,
     PKEY_VALUE_FULL_INFORMATION *PeripheralInformation
    );






typedef enum _IO_QUERY_DEVICE_DATA_FORMAT {
    IoQueryDeviceIdentifier = 0,
    IoQueryDeviceConfigurationData,
    IoQueryDeviceComponentInformation,
    IoQueryDeviceMaxData
} IO_QUERY_DEVICE_DATA_FORMAT, *PIO_QUERY_DEVICE_DATA_FORMAT;






typedef enum _CREATE_FILE_TYPE {
    CreateFileTypeNone,
    CreateFileTypeNamedPipe,
    CreateFileTypeMailslot
} CREATE_FILE_TYPE;










struct _DEVICE_DESCRIPTION;
struct _DEVICE_OBJECT;
struct _DMA_ADAPTER;
struct _DRIVER_OBJECT;
struct _DRIVE_LAYOUT_INFORMATION;
struct _DISK_PARTITION;
struct _FILE_OBJECT;
struct _IRP;
struct _SCSI_REQUEST_BLOCK;





typedef
void
(*PIO_DPC_ROUTINE) (
     PKDPC Dpc,
     struct _DEVICE_OBJECT *DeviceObject,
     struct _IRP *Irp,
     PVOID Context
    );





typedef
void
(*PIO_TIMER_ROUTINE) (
     struct _DEVICE_OBJECT *DeviceObject,
     PVOID Context
    );





typedef
NTSTATUS
(*PDRIVER_INITIALIZE) (
     struct _DRIVER_OBJECT *DriverObject,
     PUNICODE_STRING RegistryPath
    );






typedef
void
(*PDRIVER_REINITIALIZE) (
     struct _DRIVER_OBJECT *DriverObject,
     PVOID Context,
     ULONG Count
    );






typedef
void
(*PDRIVER_CANCEL) (
     struct _DEVICE_OBJECT *DeviceObject,
     struct _IRP *Irp
    );





typedef
NTSTATUS
(*PDRIVER_DISPATCH) (
     struct _DEVICE_OBJECT *DeviceObject,
     struct _IRP *Irp
    );





typedef
void
(*PDRIVER_STARTIO) (
     struct _DEVICE_OBJECT *DeviceObject,
     struct _IRP *Irp
    );





typedef
void
(*PDRIVER_UNLOAD) (
     struct _DRIVER_OBJECT *DriverObject
    );





typedef
NTSTATUS
(*PDRIVER_ADD_DEVICE) (
     struct _DRIVER_OBJECT *DriverObject,
     struct _DEVICE_OBJECT *PhysicalDeviceObject
    );








typedef
BOOLEAN
(*PFAST_IO_CHECK_IF_POSSIBLE) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     ULONG Length,
     BOOLEAN Wait,
     ULONG LockKey,
     BOOLEAN CheckForReadOperation,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_READ) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     ULONG Length,
     BOOLEAN Wait,
     ULONG LockKey,
     PVOID Buffer,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_WRITE) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     ULONG Length,
     BOOLEAN Wait,
     ULONG LockKey,
     PVOID Buffer,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );





typedef
BOOLEAN
(*PFAST_IO_QUERY_BASIC_INFO) (
     struct _FILE_OBJECT *FileObject,
     BOOLEAN Wait,
     PFILE_BASIC_INFORMATION Buffer,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_QUERY_STANDARD_INFO) (
     struct _FILE_OBJECT *FileObject,
     BOOLEAN Wait,
     PFILE_STANDARD_INFORMATION Buffer,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );





typedef
BOOLEAN
(*PFAST_IO_LOCK) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     PLARGE_INTEGER Length,
    PEPROCESS ProcessId,
    ULONG Key,
    BOOLEAN FailImmediately,
    BOOLEAN ExclusiveLock,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_UNLOCK_SINGLE) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     PLARGE_INTEGER Length,
    PEPROCESS ProcessId,
    ULONG Key,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_UNLOCK_ALL) (
     struct _FILE_OBJECT *FileObject,
    PEPROCESS ProcessId,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_UNLOCK_ALL_BY_KEY) (
     struct _FILE_OBJECT *FileObject,
    PVOID ProcessId,
    ULONG Key,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );





typedef
BOOLEAN
(*PFAST_IO_DEVICE_CONTROL) (
     struct _FILE_OBJECT *FileObject,
     BOOLEAN Wait,
     PVOID InputBuffer ,
     ULONG InputBufferLength,
     PVOID OutputBuffer ,
     ULONG OutputBufferLength,
     ULONG IoControlCode,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );







typedef
void
(*PFAST_IO_ACQUIRE_FILE) (
     struct _FILE_OBJECT *FileObject
    );

typedef
void
(*PFAST_IO_RELEASE_FILE) (
     struct _FILE_OBJECT *FileObject
    );







typedef
void
(*PFAST_IO_DETACH_DEVICE) (
     struct _DEVICE_OBJECT *SourceDevice,
     struct _DEVICE_OBJECT *TargetDevice
    );








typedef
BOOLEAN
(*PFAST_IO_QUERY_NETWORK_OPEN_INFO) (
     struct _FILE_OBJECT *FileObject,
     BOOLEAN Wait,
     struct _FILE_NETWORK_OPEN_INFORMATION *Buffer,
     struct _IO_STATUS_BLOCK *IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );





typedef
BOOLEAN
(*PFAST_IO_MDL_READ) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     ULONG Length,
     ULONG LockKey,
     PMDL *MdlChain,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_MDL_READ_COMPLETE) (
     struct _FILE_OBJECT *FileObject,
     PMDL MdlChain,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_PREPARE_MDL_WRITE) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     ULONG Length,
     ULONG LockKey,
     PMDL *MdlChain,
     PIO_STATUS_BLOCK IoStatus,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_MDL_WRITE_COMPLETE) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     PMDL MdlChain,
     struct _DEVICE_OBJECT *DeviceObject
    );






typedef
NTSTATUS
(*PFAST_IO_ACQUIRE_FOR_MOD_WRITE) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER EndingOffset,
     struct _ERESOURCE **ResourceToRelease,
     struct _DEVICE_OBJECT *DeviceObject
             );

typedef
NTSTATUS
(*PFAST_IO_RELEASE_FOR_MOD_WRITE) (
     struct _FILE_OBJECT *FileObject,
     struct _ERESOURCE *ResourceToRelease,
     struct _DEVICE_OBJECT *DeviceObject
             );






typedef
NTSTATUS
(*PFAST_IO_ACQUIRE_FOR_CCFLUSH) (
     struct _FILE_OBJECT *FileObject,
     struct _DEVICE_OBJECT *DeviceObject
             );

typedef
NTSTATUS
(*PFAST_IO_RELEASE_FOR_CCFLUSH) (
     struct _FILE_OBJECT *FileObject,
     struct _DEVICE_OBJECT *DeviceObject
             );

typedef
BOOLEAN
(*PFAST_IO_READ_COMPRESSED) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     ULONG Length,
     ULONG LockKey,
     PVOID Buffer,
     PMDL *MdlChain,
     PIO_STATUS_BLOCK IoStatus,
     struct _COMPRESSED_DATA_INFO *CompressedDataInfo,
     ULONG CompressedDataInfoLength,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_WRITE_COMPRESSED) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     ULONG Length,
     ULONG LockKey,
     PVOID Buffer,
     PMDL *MdlChain,
     PIO_STATUS_BLOCK IoStatus,
     struct _COMPRESSED_DATA_INFO *CompressedDataInfo,
     ULONG CompressedDataInfoLength,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_MDL_READ_COMPLETE_COMPRESSED) (
     struct _FILE_OBJECT *FileObject,
     PMDL MdlChain,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_MDL_WRITE_COMPLETE_COMPRESSED) (
     struct _FILE_OBJECT *FileObject,
     PLARGE_INTEGER FileOffset,
     PMDL MdlChain,
     struct _DEVICE_OBJECT *DeviceObject
    );

typedef
BOOLEAN
(*PFAST_IO_QUERY_OPEN) (
     struct _IRP *Irp,
     PFILE_NETWORK_OPEN_INFORMATION NetworkInformation,
     struct _DEVICE_OBJECT *DeviceObject
    );







typedef struct _FAST_IO_DISPATCH {
    ULONG SizeOfFastIoDispatch;
    PFAST_IO_CHECK_IF_POSSIBLE FastIoCheckIfPossible;
    PFAST_IO_READ FastIoRead;
    PFAST_IO_WRITE FastIoWrite;
    PFAST_IO_QUERY_BASIC_INFO FastIoQueryBasicInfo;
    PFAST_IO_QUERY_STANDARD_INFO FastIoQueryStandardInfo;
    PFAST_IO_LOCK FastIoLock;
    PFAST_IO_UNLOCK_SINGLE FastIoUnlockSingle;
    PFAST_IO_UNLOCK_ALL FastIoUnlockAll;
    PFAST_IO_UNLOCK_ALL_BY_KEY FastIoUnlockAllByKey;
    PFAST_IO_DEVICE_CONTROL FastIoDeviceControl;
    PFAST_IO_ACQUIRE_FILE AcquireFileForNtCreateSection;
    PFAST_IO_RELEASE_FILE ReleaseFileForNtCreateSection;
    PFAST_IO_DETACH_DEVICE FastIoDetachDevice;
    PFAST_IO_QUERY_NETWORK_OPEN_INFO FastIoQueryNetworkOpenInfo;
    PFAST_IO_ACQUIRE_FOR_MOD_WRITE AcquireForModWrite;
    PFAST_IO_MDL_READ MdlRead;
    PFAST_IO_MDL_READ_COMPLETE MdlReadComplete;
    PFAST_IO_PREPARE_MDL_WRITE PrepareMdlWrite;
    PFAST_IO_MDL_WRITE_COMPLETE MdlWriteComplete;
    PFAST_IO_READ_COMPRESSED FastIoReadCompressed;
    PFAST_IO_WRITE_COMPRESSED FastIoWriteCompressed;
    PFAST_IO_MDL_READ_COMPLETE_COMPRESSED MdlReadCompleteCompressed;
    PFAST_IO_MDL_WRITE_COMPLETE_COMPRESSED MdlWriteCompleteCompressed;
    PFAST_IO_QUERY_OPEN FastIoQueryOpen;
    PFAST_IO_RELEASE_FOR_MOD_WRITE ReleaseForModWrite;
    PFAST_IO_ACQUIRE_FOR_CCFLUSH AcquireForCcFlush;
    PFAST_IO_RELEASE_FOR_CCFLUSH ReleaseForCcFlush;
} FAST_IO_DISPATCH, *PFAST_IO_DISPATCH;






typedef enum _IO_ALLOCATION_ACTION {
    KeepObject = 1,
    DeallocateObject,
    DeallocateObjectKeepRegisters
} IO_ALLOCATION_ACTION, *PIO_ALLOCATION_ACTION;





typedef
IO_ALLOCATION_ACTION
(*PDRIVER_CONTROL) (
     struct _DEVICE_OBJECT *DeviceObject,
     struct _IRP *Irp,
     PVOID MapRegisterBase,
     PVOID Context
    );






typedef struct _IO_SECURITY_CONTEXT {
    PSECURITY_QUALITY_OF_SERVICE SecurityQos;
    PACCESS_STATE AccessState;
    ACCESS_MASK DesiredAccess;
    ULONG FullCreateOptions;
} IO_SECURITY_CONTEXT, *PIO_SECURITY_CONTEXT;


















typedef struct _VPB {
    CSHORT Type;
    CSHORT Size;
    USHORT Flags;
    USHORT VolumeLabelLength; 
    struct _DEVICE_OBJECT *DeviceObject;
    struct _DEVICE_OBJECT *RealDevice;
    ULONG SerialNumber;
    ULONG ReferenceCount;
    WCHAR VolumeLabel[(32 * sizeof(WCHAR)) / sizeof(WCHAR)];
} VPB, *PVPB;


















#line 13500 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"












#line 13513 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"





typedef struct _ADAPTER_OBJECT *PADAPTER_OBJECT; 

#line 13521 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"






typedef struct _WAIT_CONTEXT_BLOCK {
    KDEVICE_QUEUE_ENTRY WaitQueueEntry;
    PDRIVER_CONTROL DeviceRoutine;
    PVOID DeviceContext;
    ULONG NumberOfMapRegisters;
    PVOID DeviceObject;
    PVOID CurrentIrp;
    PKDPC BufferChainingDpc;
} WAIT_CONTEXT_BLOCK, *PWAIT_CONTEXT_BLOCK;



typedef struct _CONTROLLER_OBJECT {
    CSHORT Type;
    CSHORT Size;
    PVOID ControllerExtension;
    KDEVICE_QUEUE DeviceWaitQueue;

    ULONG Spare1;
    LARGE_INTEGER Spare2;

} CONTROLLER_OBJECT, *PCONTROLLER_OBJECT;
























typedef struct _DEVICE_OBJECT {
    CSHORT Type;
    USHORT Size;
    LONG ReferenceCount;
    struct _DRIVER_OBJECT *DriverObject;
    struct _DEVICE_OBJECT *NextDevice;
    struct _DEVICE_OBJECT *AttachedDevice;
    struct _IRP *CurrentIrp;
    PIO_TIMER Timer;
    ULONG Flags;                                
    ULONG Characteristics;                      
    PVPB Vpb;
    PVOID DeviceExtension;
    ULONG DeviceType;
    CCHAR StackSize;
    union {
        LIST_ENTRY ListEntry;
        WAIT_CONTEXT_BLOCK Wcb;
    } Queue;
    ULONG AlignmentRequirement;
    KDEVICE_QUEUE DeviceQueue;
    KDPC Dpc;

    
    
    
    

    ULONG ActiveThreadCount;
    PSECURITY_DESCRIPTOR SecurityDescriptor;
    KEVENT DeviceLock;

    USHORT SectorSize;
    USHORT Spare1;

    struct _DEVOBJ_EXTENSION  *DeviceObjectExtension;
    PVOID  Reserved;
} DEVICE_OBJECT;
typedef struct _DEVICE_OBJECT *PDEVICE_OBJECT; 


struct  _DEVICE_OBJECT_POWER_EXTENSION;

typedef struct _DEVOBJ_EXTENSION {

    CSHORT          Type;
    USHORT          Size;

    
    
    

    PDEVICE_OBJECT  DeviceObject;               


} DEVOBJ_EXTENSION, *PDEVOBJ_EXTENSION;















typedef struct _DRIVER_EXTENSION {

    
    
    

    struct _DRIVER_OBJECT *DriverObject;

    
    
    
    
    

    PDRIVER_ADD_DEVICE AddDevice;

    
    
    
    

    ULONG Count;

    
    
    
    

    UNICODE_STRING ServiceKeyName;

    
    
    


} DRIVER_EXTENSION, *PDRIVER_EXTENSION;

typedef struct _DRIVER_OBJECT {
    CSHORT Type;
    CSHORT Size;

    
    
    
    
    

    PDEVICE_OBJECT DeviceObject;
    ULONG Flags;

    
    
    
    
    

    PVOID DriverStart;
    ULONG DriverSize;
    PVOID DriverSection;
    PDRIVER_EXTENSION DriverExtension;

    
    
    
    

    UNICODE_STRING DriverName;

    
    
    
    

    PUNICODE_STRING HardwareDatabase;

    
    
    
    
    
    
    
    

    PFAST_IO_DISPATCH FastIoDispatch;

    
    
    
    
    

    PDRIVER_INITIALIZE DriverInit;
    PDRIVER_STARTIO DriverStartIo;
    PDRIVER_UNLOAD DriverUnload;
    PDRIVER_DISPATCH MajorFunction[0x1b + 1];

} DRIVER_OBJECT;
typedef struct _DRIVER_OBJECT *PDRIVER_OBJECT; 








typedef struct _SECTION_OBJECT_POINTERS {
    PVOID DataSectionObject;
    PVOID SharedCacheMap;
    PVOID ImageSectionObject;
} SECTION_OBJECT_POINTERS;
typedef SECTION_OBJECT_POINTERS *PSECTION_OBJECT_POINTERS;





typedef struct _IO_COMPLETION_CONTEXT {
    PVOID Port;
    PVOID Key;
} IO_COMPLETION_CONTEXT, *PIO_COMPLETION_CONTEXT;






























typedef struct _FILE_OBJECT {
    CSHORT Type;
    CSHORT Size;
    PDEVICE_OBJECT DeviceObject;
    PVPB Vpb;
    PVOID FsContext;
    PVOID FsContext2;
    PSECTION_OBJECT_POINTERS SectionObjectPointer;
    PVOID PrivateCacheMap;
    NTSTATUS FinalStatus;
    struct _FILE_OBJECT *RelatedFileObject;
    BOOLEAN LockOperation;
    BOOLEAN DeletePending;
    BOOLEAN ReadAccess;
    BOOLEAN WriteAccess;
    BOOLEAN DeleteAccess;
    BOOLEAN SharedRead;
    BOOLEAN SharedWrite;
    BOOLEAN SharedDelete;
    ULONG Flags;
    UNICODE_STRING FileName;
    LARGE_INTEGER CurrentByteOffset;
    ULONG Waiters;
    ULONG Busy;
    PVOID LastLock;
    KEVENT Lock;
    KEVENT Event;
    PIO_COMPLETION_CONTEXT CompletionContext;
} FILE_OBJECT;
typedef struct _FILE_OBJECT *PFILE_OBJECT; 







































typedef struct _IRP {
    CSHORT Type;
    USHORT Size;

    
    
    

    
    
    
    

    PMDL MdlAddress;

    
    
    

    ULONG Flags;

    
    
    
    
    
    
    
    
    
    
    
    
    

    union {
        struct _IRP *MasterIrp;
        LONG IrpCount;
        PVOID SystemBuffer;
    } AssociatedIrp;

    
    
    
    

    LIST_ENTRY ThreadListEntry;

    
    
    

    IO_STATUS_BLOCK IoStatus;

    
    
    

    KPROCESSOR_MODE RequestorMode;

    
    
    
    

    BOOLEAN PendingReturned;

    
    
    

    CHAR StackCount;
    CHAR CurrentLocation;

    
    
    

    BOOLEAN Cancel;

    
    
    

    KIRQL CancelIrql;

    
    
    
    

    CCHAR ApcEnvironment;

    
    
    

    UCHAR AllocationFlags;

    
    
    

    PIO_STATUS_BLOCK UserIosb;
    PKEVENT UserEvent;
    union {
        struct {
            PIO_APC_ROUTINE UserApcRoutine;
            PVOID UserApcContext;
        } AsynchronousParameters;
        LARGE_INTEGER AllocationSize;
    } Overlay;

    
    
    
    

    PDRIVER_CANCEL CancelRoutine;

    
    
    
    
    
    
    

    PVOID UserBuffer;

    
    
    
    
    
    
    
    
    

    union {

        struct {

            union {

                
                
                
                

                KDEVICE_QUEUE_ENTRY DeviceQueueEntry;

                struct {

                    
                    
                    
                    
                    

                    PVOID DriverContext[4];

                } ;

            } ;

            
            
            

            PETHREAD Thread;

            
            
            
            
            

            PCHAR AuxiliaryBuffer;

            
            
            
            
            

            struct {

                
                
                
                

                LIST_ENTRY ListEntry;

                union {

                    
                    
                    
                    
                    
                    

                    struct _IO_STACK_LOCATION *CurrentStackLocation;

                    
                    
                    

                    ULONG PacketType;
                };
            };

            
            
            
            
            

            PFILE_OBJECT OriginalFileObject;

        } Overlay;

        
        
        
        
        
        
        

        KAPC Apc;

        
        
        
        

        PVOID CompletionKey;

    } Tail;

} IRP, *PIRP;





typedef
NTSTATUS
(*PIO_COMPLETION_ROUTINE) (
     PDEVICE_OBJECT DeviceObject,
     PIRP Irp,
     PVOID Context
    );














































































typedef enum _DEVICE_RELATION_TYPE {
    BusRelations,
    EjectionRelations,
    PowerRelations,
    RemovalRelations,
    TargetDeviceRelation
} DEVICE_RELATION_TYPE, *PDEVICE_RELATION_TYPE;

typedef struct _DEVICE_RELATIONS {
    ULONG Count;
    PDEVICE_OBJECT Objects[1];  
} DEVICE_RELATIONS, *PDEVICE_RELATIONS;

typedef enum _DEVICE_USAGE_NOTIFICATION_TYPE {
    DeviceUsageTypeUndefined,
    DeviceUsageTypePaging,
    DeviceUsageTypeHibernation,
    DeviceUsageTypeDumpFile
} DEVICE_USAGE_NOTIFICATION_TYPE;



typedef struct _INTERFACE {
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;
    
} INTERFACE, *PINTERFACE;



typedef struct _DEVICE_CAPABILITIES {
    USHORT Size;
    USHORT Version;  
    ULONG DeviceD1:1;
    ULONG DeviceD2:1;
    ULONG LockSupported:1;
    ULONG EjectSupported:1; 
    ULONG Removable:1;
    ULONG DockDevice:1;
    ULONG UniqueID:1;
    ULONG SilentInstall:1;
    ULONG RawDeviceOK:1;
    ULONG SurpriseRemovalOK:1;
    ULONG WakeFromD0:1;
    ULONG WakeFromD1:1;
    ULONG WakeFromD2:1;
    ULONG WakeFromD3:1;
    ULONG HardwareDisabled:1;
    ULONG NonDynamic:1;
    ULONG WarmEjectSupported:1;
    ULONG NoDisplayInUI:1;
    ULONG Reserved:14;

    ULONG Address;
    ULONG UINumber;

    DEVICE_POWER_STATE DeviceState[PowerSystemMaximum];
    SYSTEM_POWER_STATE SystemWake;
    DEVICE_POWER_STATE DeviceWake;
    ULONG D1Latency;
    ULONG D2Latency;
    ULONG D3Latency;
} DEVICE_CAPABILITIES, *PDEVICE_CAPABILITIES;

typedef struct _POWER_SEQUENCE {
    ULONG SequenceD1;
    ULONG SequenceD2;
    ULONG SequenceD3;
} POWER_SEQUENCE, *PPOWER_SEQUENCE;

typedef enum {
    BusQueryDeviceID = 0,       
    BusQueryHardwareIDs = 1,    
    BusQueryCompatibleIDs = 2,  
    BusQueryInstanceID = 3,     
    BusQueryDeviceSerialNumber = 4    
} BUS_QUERY_ID_TYPE, *PBUS_QUERY_ID_TYPE;

typedef ULONG PNP_DEVICE_STATE, *PPNP_DEVICE_STATE;








typedef enum {
    DeviceTextDescription = 0,            
    DeviceTextLocationInformation = 1     
} DEVICE_TEXT_TYPE, *PDEVICE_TEXT_TYPE;






#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"























#pragma warning(disable:4103)

#pragma pack(push,4)


#line 30 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"
#line 34 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack4.h"

#line 14301 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#line 14302 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



#line 14306 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

#line 14308 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

typedef struct _IO_STACK_LOCATION {
    UCHAR MajorFunction;
    UCHAR MinorFunction;
    UCHAR Flags;
    UCHAR Control;

    
    
    
    
    

    union {

        
        
        

        struct {
            PIO_SECURITY_CONTEXT SecurityContext;
            ULONG Options;
            USHORT  FileAttributes;
            USHORT ShareAccess;
            ULONG  EaLength;
        } Create;


        
        
        

        struct {
            ULONG Length;
            ULONG  Key;
            LARGE_INTEGER ByteOffset;
        } Read;

        
        
        

        struct {
            ULONG Length;
            ULONG  Key;
            LARGE_INTEGER ByteOffset;
        } Write;


        
        
        

        struct {
            ULONG Length;
            FILE_INFORMATION_CLASS  FileInformationClass;
        } QueryFile;

        
        
        

        struct {
            ULONG Length;
            FILE_INFORMATION_CLASS  FileInformationClass;
            PFILE_OBJECT FileObject;
            union {
                struct {
                    BOOLEAN ReplaceIfExists;
                    BOOLEAN AdvanceOnly;
                };
                ULONG ClusterCount;
                HANDLE DeleteHandle;
            };
        } SetFile;


        
        
        

        struct {
            ULONG Length;
            FS_INFORMATION_CLASS  FsInformationClass;
        } QueryVolume;


        
        
        
        
        


        
        
        
        
        
        

        struct {
            ULONG OutputBufferLength;
            ULONG  InputBufferLength;
            ULONG  IoControlCode;
            PVOID Type3InputBuffer;
        } DeviceIoControl;


        
        
        

        struct {
            SECURITY_INFORMATION SecurityInformation;
            ULONG  Length;
        } QuerySecurity;

        
        
        

        struct {
            SECURITY_INFORMATION SecurityInformation;
            PSECURITY_DESCRIPTOR SecurityDescriptor;
        } SetSecurity;


        
        
        
        
        

        struct {
            PVPB Vpb;
            PDEVICE_OBJECT DeviceObject;
        } MountVolume;

        
        
        

        struct {
            PVPB Vpb;
            PDEVICE_OBJECT DeviceObject;
        } VerifyVolume;

        
        
        

        struct {
            struct _SCSI_REQUEST_BLOCK *Srb;
        } Scsi;


        
        
        

        struct {
            DEVICE_RELATION_TYPE Type;
        } QueryDeviceRelations;

        
        
        

        struct {
            const GUID *InterfaceType;
            USHORT Size;
            USHORT Version;
            PINTERFACE Interface;
            PVOID InterfaceSpecificData;
        } QueryInterface;



        
        
        

        struct {
            PDEVICE_CAPABILITIES Capabilities;
        } DeviceCapabilities;

        
        
        

        struct {
            PIO_RESOURCE_REQUIREMENTS_LIST IoResourceRequirementList;
        } FilterResourceRequirements;

        
        
        

        struct {
            ULONG WhichSpace;
            PVOID Buffer;
            ULONG Offset;
            ULONG  Length;
        } ReadWriteConfig;

        
        
        

        struct {
            BOOLEAN Lock;
        } SetLock;

        
        
        

        struct {
            BUS_QUERY_ID_TYPE IdType;
        } QueryId;

        
        
        

        struct {
            DEVICE_TEXT_TYPE DeviceTextType;
            LCID  LocaleId;
        } QueryDeviceText;

        
        
        

        struct {
            BOOLEAN InPath;
            BOOLEAN Reserved[3];
            DEVICE_USAGE_NOTIFICATION_TYPE  Type;
        } UsageNotification;

        
        
        

        struct {
            SYSTEM_POWER_STATE PowerState;
        } WaitWake;

        
        
        

        struct {
            PPOWER_SEQUENCE PowerSequence;
        } PowerSequence;

        
        
        

        struct {
            ULONG SystemContext;
            POWER_STATE_TYPE  Type;
            POWER_STATE  State;
            POWER_ACTION  ShutdownType;
        } Power;

        
        
        

        struct {
            PCM_RESOURCE_LIST AllocatedResources;
            PCM_RESOURCE_LIST AllocatedResourcesTranslated;
        } StartDevice;


        
        
        
        
        

        
        
        

        struct {
            ULONG_PTR ProviderId;
            PVOID DataPath;
            ULONG BufferSize;
            PVOID Buffer;
        } WMI;

        
        
        

        struct {
            PVOID Argument1;
            PVOID Argument2;
            PVOID Argument3;
            PVOID Argument4;
        } Others;

    } Parameters;

    
    
    
    

    PDEVICE_OBJECT DeviceObject;

    
    
    

    PFILE_OBJECT FileObject;

    
    
    
    

    PIO_COMPLETION_ROUTINE CompletionRoutine;

    
    
    
    

    PVOID Context;

} IO_STACK_LOCATION, *PIO_STACK_LOCATION;

#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


#line 36 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"
#line 37 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"

#line 14646 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
#line 14647 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"






typedef struct _SHARE_ACCESS {
    ULONG OpenCount;
    ULONG Readers;
    ULONG Writers;
    ULONG Deleters;
    ULONG SharedRead;
    ULONG SharedWrite;
    ULONG SharedDelete;
} SHARE_ACCESS, *PSHARE_ACCESS;











typedef struct _CONFIGURATION_INFORMATION {

    
    
    
    
    
    

    ULONG DiskCount;                
    ULONG FloppyCount;              
    ULONG CdRomCount;               
    ULONG TapeCount;                
    ULONG ScsiPortCount;            
    ULONG SerialCount;              
    ULONG ParallelCount;            

    
    
    
    

    BOOLEAN AtDiskPrimaryAddressClaimed;    
    BOOLEAN AtDiskSecondaryAddressClaimed;  

    
    
    
    

    ULONG Version;

    
    
    
    
    

    ULONG MediumChangerCount;

} CONFIGURATION_INFORMATION, *PCONFIGURATION_INFORMATION;





__declspec(dllimport)
void
IoAcquireCancelSpinLock(
     PKIRQL Irql
    );


__declspec(dllimport)
NTSTATUS
IoAllocateAdapterChannel(
     PADAPTER_OBJECT AdapterObject,
     PDEVICE_OBJECT DeviceObject,
     ULONG NumberOfMapRegisters,
     PDRIVER_CONTROL ExecutionRoutine,
     PVOID Context
    );

__declspec(dllimport)
void
IoAllocateController(
     PCONTROLLER_OBJECT ControllerObject,
     PDEVICE_OBJECT DeviceObject,
     PDRIVER_CONTROL ExecutionRoutine,
     PVOID Context
    );



__declspec(dllimport)
NTSTATUS
IoAllocateDriverObjectExtension(
     PDRIVER_OBJECT DriverObject,
     PVOID ClientIdentificationAddress,
     ULONG DriverObjectExtensionSize,
     PVOID *DriverObjectExtension
    );



__declspec(dllimport)
PVOID
IoAllocateErrorLogEntry(
     PVOID IoObject,
     UCHAR EntrySize
    );

__declspec(dllimport)
PIRP
IoAllocateIrp(
     CCHAR StackSize,
     BOOLEAN ChargeQuota
    );

__declspec(dllimport)
PMDL
IoAllocateMdl(
     PVOID VirtualAddress,
     ULONG Length,
     BOOLEAN SecondaryBuffer,
     BOOLEAN ChargeQuota,
      PIRP Irp 
    );

































__declspec(dllimport)
NTSTATUS
IoAssignResources (
     PUNICODE_STRING RegistryPath,
     PUNICODE_STRING DriverClassName ,
     PDRIVER_OBJECT DriverObject,
     PDEVICE_OBJECT DeviceObject ,
     PIO_RESOURCE_REQUIREMENTS_LIST RequestedResources,
      PCM_RESOURCE_LIST *AllocatedResources
    );


__declspec(dllimport)
NTSTATUS
IoAttachDevice(
     PDEVICE_OBJECT SourceDevice,
     PUNICODE_STRING TargetDevice,
     PDEVICE_OBJECT *AttachedDevice
    );



__declspec(dllimport)
NTSTATUS
IoAttachDeviceByPointer(
     PDEVICE_OBJECT SourceDevice,
     PDEVICE_OBJECT TargetDevice
    );



__declspec(dllimport)
PDEVICE_OBJECT
IoAttachDeviceToDeviceStack(
     PDEVICE_OBJECT SourceDevice,
     PDEVICE_OBJECT TargetDevice
    );

__declspec(dllimport)
PIRP
IoBuildAsynchronousFsdRequest(
     ULONG MajorFunction,
     PDEVICE_OBJECT DeviceObject,
      PVOID Buffer ,
     ULONG Length ,
     PLARGE_INTEGER StartingOffset ,
     PIO_STATUS_BLOCK IoStatusBlock 
    );

__declspec(dllimport)
PIRP
IoBuildDeviceIoControlRequest(
     ULONG IoControlCode,
     PDEVICE_OBJECT DeviceObject,
     PVOID InputBuffer ,
     ULONG InputBufferLength,
     PVOID OutputBuffer ,
     ULONG OutputBufferLength,
     BOOLEAN InternalDeviceIoControl,
     PKEVENT Event,
     PIO_STATUS_BLOCK IoStatusBlock
    );

__declspec(dllimport)
void
IoBuildPartialMdl(
     PMDL SourceMdl,
      PMDL TargetMdl,
     PVOID VirtualAddress,
     ULONG Length
    );

typedef struct _BOOTDISK_INFORMATION {
    LONGLONG BootPartitionOffset;
    LONGLONG SystemPartitionOffset;
    ULONG BootDeviceSignature;
    ULONG SystemDeviceSignature;
} BOOTDISK_INFORMATION, *PBOOTDISK_INFORMATION;

__declspec(dllimport)
NTSTATUS
IoGetBootDiskInformation(
      PBOOTDISK_INFORMATION BootDiskInformation,
     ULONG Size
    );


__declspec(dllimport)
PIRP
IoBuildSynchronousFsdRequest(
     ULONG MajorFunction,
     PDEVICE_OBJECT DeviceObject,
      PVOID Buffer ,
     ULONG Length ,
     PLARGE_INTEGER StartingOffset ,
     PKEVENT Event,
     PIO_STATUS_BLOCK IoStatusBlock
    );

__declspec(dllimport)
NTSTATUS
_fastcall
IofCallDriver(
     PDEVICE_OBJECT DeviceObject,
      PIRP Irp
    );




__declspec(dllimport)
BOOLEAN
IoCancelIrp(
     PIRP Irp
    );


__declspec(dllimport)
NTSTATUS
IoCheckShareAccess(
     ACCESS_MASK DesiredAccess,
     ULONG DesiredShareAccess,
      PFILE_OBJECT FileObject,
      PSHARE_ACCESS ShareAccess,
     BOOLEAN Update
    );

__declspec(dllimport)
void
_fastcall
IofCompleteRequest(
     PIRP Irp,
     CCHAR PriorityBoost
    );






__declspec(dllimport)
NTSTATUS
IoConnectInterrupt(
     PKINTERRUPT *InterruptObject,
     PKSERVICE_ROUTINE ServiceRoutine,
     PVOID ServiceContext,
     PKSPIN_LOCK SpinLock ,
     ULONG Vector,
     KIRQL Irql,
     KIRQL SynchronizeIrql,
     KINTERRUPT_MODE InterruptMode,
     BOOLEAN ShareVector,
     KAFFINITY ProcessorEnableMask,
     BOOLEAN FloatingSave
    );



__declspec(dllimport)
PCONTROLLER_OBJECT
IoCreateController(
     ULONG Size
    );



__declspec(dllimport)
NTSTATUS
IoCreateDevice(
     PDRIVER_OBJECT DriverObject,
     ULONG DeviceExtensionSize,
     PUNICODE_STRING DeviceName ,
     ULONG DeviceType,
     ULONG DeviceCharacteristics,
     BOOLEAN Exclusive,
     PDEVICE_OBJECT *DeviceObject
    );




__declspec(dllimport)
BOOLEAN
IoIsWdmVersionAvailable(
     UCHAR MajorVersion,
     UCHAR MinorVersion
    );



__declspec(dllimport)
NTSTATUS
IoCreateFile(
     PHANDLE FileHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes,
     PIO_STATUS_BLOCK IoStatusBlock,
     PLARGE_INTEGER AllocationSize ,
     ULONG FileAttributes,
     ULONG ShareAccess,
     ULONG Disposition,
     ULONG CreateOptions,
     PVOID EaBuffer ,
     ULONG EaLength,
     CREATE_FILE_TYPE CreateFileType,
     PVOID ExtraCreateParameters ,
     ULONG Options
    );


__declspec(dllimport)
PKEVENT
IoCreateNotificationEvent(
     PUNICODE_STRING EventName,
     PHANDLE EventHandle
    );

__declspec(dllimport)
NTSTATUS
IoCreateSymbolicLink(
     PUNICODE_STRING SymbolicLinkName,
     PUNICODE_STRING DeviceName
    );



__declspec(dllimport)
PKEVENT
IoCreateSynchronizationEvent(
     PUNICODE_STRING EventName,
     PHANDLE EventHandle
    );



__declspec(dllimport)
NTSTATUS
IoCreateUnprotectedSymbolicLink(
     PUNICODE_STRING SymbolicLinkName,
     PUNICODE_STRING DeviceName
    );
































__declspec(dllimport)
void
IoDeleteController(
     PCONTROLLER_OBJECT ControllerObject
    );



__declspec(dllimport)
void
IoDeleteDevice(
     PDEVICE_OBJECT DeviceObject
    );

__declspec(dllimport)
NTSTATUS
IoDeleteSymbolicLink(
     PUNICODE_STRING SymbolicLinkName
    );

__declspec(dllimport)
void
IoDetachDevice(
      PDEVICE_OBJECT TargetDevice
    );



__declspec(dllimport)
void
IoDisconnectInterrupt(
     PKINTERRUPT InterruptObject
    );


__declspec(dllimport)
void
IoFreeController(
     PCONTROLLER_OBJECT ControllerObject
    );



__declspec(dllimport)
void
IoFreeIrp(
     PIRP Irp
    );

__declspec(dllimport)
void
IoFreeMdl(
     PMDL Mdl
    );

__declspec(dllimport)                                 
PDEVICE_OBJECT                              
IoGetAttachedDeviceReference(               
     PDEVICE_OBJECT DeviceObject          
    );                                      
                                            
__declspec(dllimport)                                 
PCONFIGURATION_INFORMATION                  
IoGetConfigurationInformation( void );      




























__declspec(dllimport)
PDEVICE_OBJECT
IoGetDeviceToVerify(
     PETHREAD Thread
    );



__declspec(dllimport)
PVOID
IoGetDriverObjectExtension(
     PDRIVER_OBJECT DriverObject,
     PVOID ClientIdentificationAddress
    );

__declspec(dllimport)
PEPROCESS
IoGetCurrentProcess(
    void
    );



__declspec(dllimport)
NTSTATUS
IoGetDeviceObjectPointer(
     PUNICODE_STRING ObjectName,
     ACCESS_MASK DesiredAccess,
     PFILE_OBJECT *FileObject,
     PDEVICE_OBJECT *DeviceObject
    );

__declspec(dllimport)
struct _DMA_ADAPTER *
IoGetDmaAdapter(
     PDEVICE_OBJECT PhysicalDeviceObject,            
     struct _DEVICE_DESCRIPTION *DeviceDescription,
      PULONG NumberOfMapRegisters
    );



__declspec(dllimport)
PGENERIC_MAPPING
IoGetFileObjectGenericMapping(
    void
    );








































__declspec(dllimport)
PVOID
IoGetInitialStack(
    void
    );

__declspec(dllimport)
void
IoGetStackLimits (
     PULONG_PTR LowLimit,
     PULONG_PTR HighLimit
    );






__inline
ULONG_PTR
IoGetRemainingStackSize (
    void
    )
{
    ULONG_PTR Top;
    ULONG_PTR Bottom;

    IoGetStackLimits( &Bottom, &Top );
    return((ULONG_PTR)(&Top) - Bottom );
}




























__declspec(dllimport)
PDEVICE_OBJECT
IoGetRelatedDeviceObject(
     PFILE_OBJECT FileObject
    );



































__declspec(dllimport)
void
IoInitializeIrp(
      PIRP Irp,
     USHORT PacketSize,
     CCHAR StackSize
    );

__declspec(dllimport)
NTSTATUS
IoInitializeTimer(
     PDEVICE_OBJECT DeviceObject,
     PIO_TIMER_ROUTINE TimerRoutine,
     PVOID Context
    );


__declspec(dllimport)
void
IoReuseIrp(
      PIRP Irp,
     NTSTATUS Iostatus
    );


__declspec(dllimport)
void
IoCancelFileOpen(
     PDEVICE_OBJECT  DeviceObject,
     PFILE_OBJECT    FileObject
    );

































__declspec(dllimport)
PIRP
IoMakeAssociatedIrp(
     PIRP Irp,
     CCHAR StackSize
    );






























__declspec(dllimport)                                             
NTSTATUS                                                
IoQueryDeviceDescription(                               
     PINTERFACE_TYPE BusType ,                
     PULONG BusNumber ,                       
     PCONFIGURATION_TYPE ControllerType ,     
     PULONG ControllerNumber ,                
     PCONFIGURATION_TYPE PeripheralType ,     
     PULONG PeripheralNumber ,                
     PIO_QUERY_DEVICE_ROUTINE CalloutRoutine,         
     PVOID Context                                    
    );                                                  

__declspec(dllimport)
void
IoRaiseHardError(
     PIRP Irp,
     PVPB Vpb ,
     PDEVICE_OBJECT RealDeviceObject
    );

__declspec(dllimport)
BOOLEAN
IoRaiseInformationalHardError(
     NTSTATUS ErrorStatus,
     PUNICODE_STRING String ,
     PKTHREAD Thread 
    );

__declspec(dllimport)
BOOLEAN
IoSetThreadHardErrorMode(
     BOOLEAN EnableHardErrors
    );

__declspec(dllimport)
void
IoRegisterBootDriverReinitialization(
     PDRIVER_OBJECT DriverObject,
     PDRIVER_REINITIALIZE DriverReinitializationRoutine,
     PVOID Context
    );

__declspec(dllimport)
void
IoRegisterDriverReinitialization(
     PDRIVER_OBJECT DriverObject,
     PDRIVER_REINITIALIZE DriverReinitializationRoutine,
     PVOID Context
    );


__declspec(dllimport)
NTSTATUS
IoRegisterShutdownNotification(
     PDEVICE_OBJECT DeviceObject
    );

__declspec(dllimport)
NTSTATUS
IoRegisterLastChanceShutdownNotification(
     PDEVICE_OBJECT DeviceObject
    );



__declspec(dllimport)
void
IoReleaseCancelSpinLock(
     KIRQL Irql
    );


__declspec(dllimport)
void
IoRemoveShareAccess(
     PFILE_OBJECT FileObject,
      PSHARE_ACCESS ShareAccess
    );


__declspec(dllimport)
NTSTATUS
IoReportResourceUsage(
     PUNICODE_STRING DriverClassName ,
     PDRIVER_OBJECT DriverObject,
     PCM_RESOURCE_LIST DriverList ,
     ULONG DriverListSize ,
     PDEVICE_OBJECT DeviceObject,
     PCM_RESOURCE_LIST DeviceList ,
     ULONG DeviceListSize ,
     BOOLEAN OverrideConflict,
     PBOOLEAN ConflictDetected
    );

























































































































__declspec(dllimport)
void
IoSetHardErrorOrVerifyDevice(
     PIRP Irp,
     PDEVICE_OBJECT DeviceObject
    );
































































































__declspec(dllimport)
void
IoSetShareAccess(
     ACCESS_MASK DesiredAccess,
     ULONG DesiredShareAccess,
      PFILE_OBJECT FileObject,
     PSHARE_ACCESS ShareAccess
    );



typedef struct _IO_REMOVE_LOCK_TRACKING_BLOCK * PIO_REMOVE_LOCK_TRACKING_BLOCK;

typedef struct _IO_REMOVE_LOCK_COMMON_BLOCK {
    BOOLEAN     Removed;
    BOOLEAN     Reserved [3];
    LONG        IoCount;
    KEVENT      RemoveEvent;

} IO_REMOVE_LOCK_COMMON_BLOCK;

typedef struct _IO_REMOVE_LOCK_DBG_BLOCK {
    LONG        Signature;
    LONG        HighWatermark;
    LONGLONG    MaxLockedTicks;
    LONG        AllocateTag;
    LIST_ENTRY  LockList;
    KSPIN_LOCK  Spin;
    LONG        LowMemoryCount;
    ULONG       Reserved1[4];
    PVOID       Reserved2;
    PIO_REMOVE_LOCK_TRACKING_BLOCK Blocks;
} IO_REMOVE_LOCK_DBG_BLOCK;

typedef struct _IO_REMOVE_LOCK {
    IO_REMOVE_LOCK_COMMON_BLOCK Common;

    IO_REMOVE_LOCK_DBG_BLOCK Dbg;
#line 15820 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
} IO_REMOVE_LOCK, *PIO_REMOVE_LOCK;




__declspec(dllimport)
void
__stdcall
IoInitializeRemoveLockEx(
      PIO_REMOVE_LOCK Lock,
      ULONG   AllocateTag, 
      ULONG   MaxLockedMinutes, 
      ULONG   HighWatermark, 
      ULONG   RemlockSize 
    );











__declspec(dllimport)
NTSTATUS
__stdcall
IoAcquireRemoveLockEx (
     PIO_REMOVE_LOCK RemoveLock,
      PVOID   Tag, 
     PCSTR            File,
     ULONG            Line,
     ULONG            RemlockSize 
    );







































__declspec(dllimport)
void
__stdcall
IoReleaseRemoveLockEx(
     PIO_REMOVE_LOCK RemoveLock,
     PVOID            Tag, 
     ULONG            RemlockSize 
    );




























__declspec(dllimport)
void
__stdcall
IoReleaseRemoveLockAndWaitEx(
     PIO_REMOVE_LOCK RemoveLock,
     PVOID            Tag,
     ULONG            RemlockSize 
    );
















































__declspec(dllimport)
void
IoStartNextPacket(
     PDEVICE_OBJECT DeviceObject,
     BOOLEAN Cancelable
    );

__declspec(dllimport)
void
IoStartNextPacketByKey(
     PDEVICE_OBJECT DeviceObject,
     BOOLEAN Cancelable,
     ULONG Key
    );

__declspec(dllimport)
void
IoStartPacket(
     PDEVICE_OBJECT DeviceObject,
     PIRP Irp,
     PULONG Key ,
     PDRIVER_CANCEL CancelFunction 
    );



__declspec(dllimport)
void
IoStartTimer(
     PDEVICE_OBJECT DeviceObject
    );

__declspec(dllimport)
void
IoStopTimer(
     PDEVICE_OBJECT DeviceObject
    );


__declspec(dllimport)
void
IoUnregisterShutdownNotification(
     PDEVICE_OBJECT DeviceObject
    );



__declspec(dllimport)
void
IoUpdateShareAccess(
     PFILE_OBJECT FileObject,
      PSHARE_ACCESS ShareAccess
    );

__declspec(dllimport)                                     
void                                            
IoWriteErrorLogEntry(                           
     PVOID ElEntry                            
    );                                          

typedef struct _IO_WORKITEM *PIO_WORKITEM;

typedef
void
(*PIO_WORKITEM_ROUTINE) (
     PDEVICE_OBJECT DeviceObject,
     PVOID Context
    );

PIO_WORKITEM
IoAllocateWorkItem(
    PDEVICE_OBJECT DeviceObject
    );

void
IoFreeWorkItem(
    PIO_WORKITEM IoWorkItem
    );

void
IoQueueWorkItem(
     PIO_WORKITEM IoWorkItem,
     PIO_WORKITEM_ROUTINE WorkerRoutine,
     WORK_QUEUE_TYPE QueueType,
     PVOID Context
    );





__declspec(dllimport)
NTSTATUS
IoWMIRegistrationControl(
     PDEVICE_OBJECT DeviceObject,
     ULONG Action
);


















__declspec(dllimport)
NTSTATUS
IoWMIAllocateInstanceIds(
     GUID *Guid,
     ULONG InstanceCount,
     ULONG *FirstInstanceId
    );

__declspec(dllimport)
NTSTATUS
IoWMISuggestInstanceName(
     PDEVICE_OBJECT PhysicalDeviceObject ,
     PUNICODE_STRING SymbolicLinkName ,
     BOOLEAN CombineNames,
     PUNICODE_STRING SuggestedInstanceName
    );

__declspec(dllimport)
NTSTATUS
IoWMIWriteEvent(
     PVOID WnodeEventItem
    );





#line 16130 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

#line 16132 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"






typedef enum {
    DevicePropertyDeviceDescription,
    DevicePropertyHardwareID,
    DevicePropertyCompatibleIDs,
    DevicePropertyBootConfiguration,
    DevicePropertyBootConfigurationTranslated,
    DevicePropertyClassName,
    DevicePropertyClassGuid,
    DevicePropertyDriverKeyName,
    DevicePropertyManufacturer,
    DevicePropertyFriendlyName,
    DevicePropertyLocationInformation,
    DevicePropertyPhysicalDeviceObjectName,
    DevicePropertyBusTypeGuid,
    DevicePropertyLegacyBusType,
    DevicePropertyBusNumber,
    DevicePropertyEnumeratorName,
    DevicePropertyAddress,
    DevicePropertyUINumber
} DEVICE_REGISTRY_PROPERTY;

typedef BOOLEAN (*PTRANSLATE_BUS_ADDRESS)(
     PVOID Context,
     PHYSICAL_ADDRESS BusAddress,
     ULONG Length,
      PULONG AddressSpace,
     PPHYSICAL_ADDRESS TranslatedAddress
    );

typedef struct _DMA_ADAPTER *(*PGET_DMA_ADAPTER)(
     PVOID Context,
     struct _DEVICE_DESCRIPTION *DeviceDescriptor,
     PULONG NumberOfMapRegisters
    );

typedef ULONG (*PGET_SET_DEVICE_DATA)(
     PVOID Context,
     ULONG DataType,
     PVOID Buffer,
     ULONG Offset,
     ULONG Length
    );






typedef struct _PNP_BUS_INFORMATION {
    GUID BusTypeGuid;
    INTERFACE_TYPE LegacyBusType;
    ULONG BusNumber;
} PNP_BUS_INFORMATION, *PPNP_BUS_INFORMATION;









typedef struct _LEGACY_BUS_INFORMATION {
    GUID BusTypeGuid;
    INTERFACE_TYPE LegacyBusType;
    ULONG BusNumber;
} LEGACY_BUS_INFORMATION, *PLEGACY_BUS_INFORMATION;

typedef struct _BUS_INTERFACE_STANDARD {
    
    
    
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;
    
    
    
    PTRANSLATE_BUS_ADDRESS TranslateBusAddress;
    PGET_DMA_ADAPTER GetDmaAdapter;
    PGET_SET_DEVICE_DATA SetBusData;
    PGET_SET_DEVICE_DATA GetBusData;

} BUS_INTERFACE_STANDARD, *PBUS_INTERFACE_STANDARD;




typedef BOOLEAN (* PGPE_SERVICE_ROUTINE) (
                            PVOID,
                            PVOID);

typedef NTSTATUS (* PGPE_CONNECT_VECTOR) (
                            PDEVICE_OBJECT,
                            ULONG,
                            KINTERRUPT_MODE,
                            BOOLEAN,
                            PGPE_SERVICE_ROUTINE,
                            PVOID,
                            PVOID);

typedef NTSTATUS (* PGPE_DISCONNECT_VECTOR) (
                            PVOID);

typedef NTSTATUS (* PGPE_ENABLE_EVENT) (
                            PDEVICE_OBJECT,
                            PVOID);

typedef NTSTATUS (* PGPE_DISABLE_EVENT) (
                            PDEVICE_OBJECT,
                            PVOID);

typedef NTSTATUS (* PGPE_CLEAR_STATUS) (
                            PDEVICE_OBJECT,
                            PVOID);

typedef void (* PDEVICE_NOTIFY_CALLBACK) (
                            PVOID,
                            ULONG);

typedef NTSTATUS (* PREGISTER_FOR_DEVICE_NOTIFICATIONS) (
                            PDEVICE_OBJECT,
                            PDEVICE_NOTIFY_CALLBACK,
                            PVOID);

typedef void (* PUNREGISTER_FOR_DEVICE_NOTIFICATIONS) (
                            PDEVICE_OBJECT,
                            PDEVICE_NOTIFY_CALLBACK);

typedef struct _ACPI_INTERFACE_STANDARD {
    
    
    
    USHORT                  Size;
    USHORT                  Version;
    PVOID                   Context;
    PINTERFACE_REFERENCE    InterfaceReference;
    PINTERFACE_DEREFERENCE  InterfaceDereference;
    
    
    
    PGPE_CONNECT_VECTOR                     GpeConnectVector;
    PGPE_DISCONNECT_VECTOR                  GpeDisconnectVector;
    PGPE_ENABLE_EVENT                       GpeEnableEvent;
    PGPE_DISABLE_EVENT                      GpeDisableEvent;
    PGPE_CLEAR_STATUS                       GpeClearStatus;
    PREGISTER_FOR_DEVICE_NOTIFICATIONS      RegisterForDeviceNotifications;
    PUNREGISTER_FOR_DEVICE_NOTIFICATIONS    UnregisterForDeviceNotifications;

} ACPI_INTERFACE_STANDARD, *PACPI_INTERFACE_STANDARD;



typedef enum _ACPI_REG_TYPE {
    PM1a_ENABLE,
    PM1b_ENABLE,
    PM1a_STATUS,
    PM1b_STATUS,
    PM1a_CONTROL,
    PM1b_CONTROL,
    GP_STATUS,
    GP_ENABLE,
    SMI_CMD,
    MaxRegType
} ACPI_REG_TYPE, *PACPI_REG_TYPE;

typedef USHORT (*PREAD_ACPI_REGISTER) (
   ACPI_REG_TYPE AcpiReg,
   ULONG         Register);

typedef void (*PWRITE_ACPI_REGISTER) (
   ACPI_REG_TYPE AcpiReg,
   ULONG         Register,
   USHORT        Value
  );

typedef struct ACPI_REGS_INTERFACE_STANDARD {
    
    
    
    USHORT Size;
    USHORT Version;
    PVOID  Context;
    PINTERFACE_REFERENCE   InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;

    
    
    
    PREAD_ACPI_REGISTER  ReadAcpiRegister;
    PWRITE_ACPI_REGISTER WriteAcpiRegister;

} ACPI_REGS_INTERFACE_STANDARD, *PACPI_REGS_INTERFACE_STANDARD;





typedef struct {
    PVOID   LinkNode;
    ULONG   StaticVector;
    UCHAR   Flags;
} ROUTING_TOKEN, *PROUTING_TOKEN;









typedef
NTSTATUS
(*PGET_INTERRUPT_ROUTING)(
      PDEVICE_OBJECT  Pdo,
     ULONG           *Bus,
     ULONG           *PciSlot,
     UCHAR           *InterruptLine,
     UCHAR           *InterruptPin,
     UCHAR           *ClassCode,
     UCHAR           *SubClassCode,
     PDEVICE_OBJECT  *ParentPdo,
     ROUTING_TOKEN   *RoutingToken,
     UCHAR           *Flags
    );

typedef
NTSTATUS
(*PSET_INTERRUPT_ROUTING_TOKEN)(
      PDEVICE_OBJECT  Pdo,
      PROUTING_TOKEN  RoutingToken
    );

typedef
void
(*PUPDATE_INTERRUPT_LINE)(
     PDEVICE_OBJECT Pdo,
     UCHAR LineRegister
    );

typedef struct _INT_ROUTE_INTERFACE_STANDARD {
    
    
    
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;
    
    
    
    PGET_INTERRUPT_ROUTING GetInterruptRouting;
    PSET_INTERRUPT_ROUTING_TOKEN SetInterruptRoutingToken;
    PUPDATE_INTERRUPT_LINE UpdateInterruptLine;

} INT_ROUTE_INTERFACE_STANDARD, *PINT_ROUTE_INTERFACE_STANDARD;






typedef struct _IO_ASSIGNED_RESOURCES {
    ULONG Count;
    PASSIGNED_RESOURCE AssignedResources[1];
} IO_ASSIGNED_RESOURCES, *PIO_ASSIGNED_RESOURCES;

__declspec(dllimport)
NTSTATUS
IoGetAssignedResourcesForSuballocation (
     INTERFACE_TYPE InterfaceType,
     ULONG BusNumber,
     ULONG SlotNumber,
     PIO_RESOURCE_DESCRIPTOR ResourceDescriptor,
     PIO_ASSIGNED_RESOURCES *List
    );

__declspec(dllimport)
NTSTATUS
IoReportDetectedDevice(
     PDRIVER_OBJECT DriverObject,
     INTERFACE_TYPE LegacyBusType,
     ULONG BusNumber,
     ULONG SlotNumber,
     PCM_RESOURCE_LIST ResourceList,
     PIO_RESOURCE_REQUIREMENTS_LIST ResourceRequirements ,
     BOOLEAN ResourceAssigned,
      PDEVICE_OBJECT *DeviceObject
    );



__declspec(dllimport)
void
IoInvalidateDeviceRelations(
     PDEVICE_OBJECT DeviceObject,
     DEVICE_RELATION_TYPE Type
    );

__declspec(dllimport)
void
IoRequestDeviceEject(
     PDEVICE_OBJECT PhysicalDeviceObject
    );

__declspec(dllimport)
NTSTATUS
IoGetDeviceProperty(
     PDEVICE_OBJECT DeviceObject,
     DEVICE_REGISTRY_PROPERTY DeviceProperty,
     ULONG BufferLength,
     PVOID PropertyBuffer,
     PULONG ResultLength
    );









__declspec(dllimport)
NTSTATUS
IoOpenDeviceRegistryKey(
     PDEVICE_OBJECT DeviceObject,
     ULONG DevInstKeyType,
     ACCESS_MASK DesiredAccess,
     PHANDLE DevInstRegKey
    );

__declspec(dllimport)
NTSTATUS
__stdcall
IoRegisterDeviceInterface(
     PDEVICE_OBJECT PhysicalDeviceObject,
     const GUID *InterfaceClassGuid,
     PUNICODE_STRING ReferenceString,     
     PUNICODE_STRING SymbolicLinkName
    );

__declspec(dllimport)
NTSTATUS
IoOpenDeviceInterfaceRegistryKey(
     PUNICODE_STRING SymbolicLinkName,
     ACCESS_MASK DesiredAccess,
     PHANDLE DeviceInterfaceKey
    );



__declspec(dllimport)
NTSTATUS
IoSetDeviceInterfaceState(
     PUNICODE_STRING SymbolicLinkName,
     BOOLEAN Enable
    );



__declspec(dllimport)
NTSTATUS
__stdcall
IoGetDeviceInterfaces(
     const GUID *InterfaceClassGuid,
     PDEVICE_OBJECT PhysicalDeviceObject ,
     ULONG Flags,
     PWSTR *SymbolicLinkList
    );



__declspec(dllimport)
NTSTATUS
__stdcall
IoGetDeviceInterfaceAlias(
     PUNICODE_STRING SymbolicLinkName,
     const GUID *AliasInterfaceClassGuid,
     PUNICODE_STRING AliasSymbolicLinkName
    );





typedef enum _IO_NOTIFICATION_EVENT_CATEGORY {
    EventCategoryReserved,
    EventCategoryHardwareProfileChange,
    EventCategoryDeviceInterfaceChange,
    EventCategoryTargetDeviceChange
} IO_NOTIFICATION_EVENT_CATEGORY;








typedef
NTSTATUS
(*PDRIVER_NOTIFICATION_CALLBACK_ROUTINE) (
     PVOID NotificationStructure,
     PVOID Context
);


__declspec(dllimport)
NTSTATUS
IoRegisterPlugPlayNotification(
     IO_NOTIFICATION_EVENT_CATEGORY EventCategory,
     ULONG EventCategoryFlags,
     PVOID EventCategoryData ,
     PDRIVER_OBJECT DriverObject,
     PDRIVER_NOTIFICATION_CALLBACK_ROUTINE CallbackRoutine,
     PVOID Context,
     PVOID *NotificationEntry
    );

__declspec(dllimport)
NTSTATUS
IoUnregisterPlugPlayNotification(
     PVOID NotificationEntry
    );

__declspec(dllimport)
NTSTATUS
IoReportTargetDeviceChange(
     PDEVICE_OBJECT PhysicalDeviceObject,
     PVOID NotificationStructure  
    );

typedef
void
(*PDEVICE_CHANGE_COMPLETE_CALLBACK)(
     PVOID Context
    );

__declspec(dllimport)
void
IoInvalidateDeviceState(
     PDEVICE_OBJECT PhysicalDeviceObject
    );











__declspec(dllimport)
NTSTATUS
IoReportTargetDeviceChangeAsynchronous(
     PDEVICE_OBJECT PhysicalDeviceObject,
     PVOID NotificationStructure,  
     PDEVICE_CHANGE_COMPLETE_CALLBACK Callback,       
     PVOID Context    
    );






typedef enum _ARBITER_ACTION {
    ArbiterActionTestAllocation,
    ArbiterActionRetestAllocation,
    ArbiterActionCommitAllocation,
    ArbiterActionRollbackAllocation,
    ArbiterActionQueryAllocatedResources,
    ArbiterActionWriteReservedResources,
    ArbiterActionQueryConflict,
    ArbiterActionQueryArbitrate,
    ArbiterActionAddReserved,
    ArbiterActionBootAllocation
} ARBITER_ACTION, *PARBITER_ACTION;

typedef struct _ARBITER_CONFLICT_INFO {
    
    
    
    PDEVICE_OBJECT OwningObject;

    
    
    
    ULONGLONG Start;

    
    
    
    ULONGLONG End;

} ARBITER_CONFLICT_INFO, *PARBITER_CONFLICT_INFO;





typedef struct _ARBITER_PARAMETERS {

    union {

        struct {

            
            
            
              PLIST_ENTRY ArbitrationList;

            
            
            
             ULONG AllocateFromCount;

            
            
            
            
             PCM_PARTIAL_RESOURCE_DESCRIPTOR AllocateFrom;

        } TestAllocation;

        struct {

            
            
            
              PLIST_ENTRY ArbitrationList;

            
            
            
             ULONG AllocateFromCount;

            
            
            
            
             PCM_PARTIAL_RESOURCE_DESCRIPTOR AllocateFrom;

        } RetestAllocation;

        struct {

            
            
            
              PLIST_ENTRY ArbitrationList;

        } BootAllocation;

        struct {

            
            
            
             PCM_PARTIAL_RESOURCE_LIST *AllocatedResources;

        } QueryAllocatedResources;

        struct {

            
            
            
             PDEVICE_OBJECT PhysicalDeviceObject;

            
            
            
             PIO_RESOURCE_DESCRIPTOR ConflictingResource;

            
            
            
             PULONG ConflictCount;

            
            
            
             PARBITER_CONFLICT_INFO *Conflicts;

        } QueryConflict;

        struct {

            
            
            
            
             PLIST_ENTRY ArbitrationList;

        } QueryArbitrate;

        struct {

            
            
            
            PDEVICE_OBJECT ReserveDevice;

        } AddReserved;

    } Parameters;

} ARBITER_PARAMETERS, *PARBITER_PARAMETERS;



typedef enum _ARBITER_REQUEST_SOURCE {

    ArbiterRequestUndefined = -1,
    ArbiterRequestLegacyReported,   
    ArbiterRequestHalReported,      
    ArbiterRequestLegacyAssigned,   
    ArbiterRequestPnpDetected,      
    ArbiterRequestPnpEnumerated     

} ARBITER_REQUEST_SOURCE;


typedef enum _ARBITER_RESULT {

    ArbiterResultUndefined = -1,
    ArbiterResultSuccess,
    ArbiterResultExternalConflict, 
    ArbiterResultNullRequest       

} ARBITER_RESULT;









__declspec(dllimport)
NTSTATUS
IoReportResourceForDetection(
     PDRIVER_OBJECT DriverObject,
     PCM_RESOURCE_LIST DriverList ,
     ULONG DriverListSize ,
     PDEVICE_OBJECT DeviceObject ,
     PCM_RESOURCE_LIST DeviceList ,
     ULONG DeviceListSize ,
     PBOOLEAN ConflictDetected
    );


typedef struct _ARBITER_LIST_ENTRY {

    
    
    
    LIST_ENTRY ListEntry;

    
    
    
    ULONG AlternativeCount;

    
    
    
    PIO_RESOURCE_DESCRIPTOR Alternatives;

    
    
    
    PDEVICE_OBJECT PhysicalDeviceObject;

    
    
    
    ARBITER_REQUEST_SOURCE RequestSource;

    
    
    
    ULONG Flags;

    
    
    
    
    LONG_PTR WorkSpace;

    
    
    
    
    INTERFACE_TYPE InterfaceType;
    ULONG SlotNumber;
    ULONG BusNumber;

    
    
    
    
    
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Assignment;

    
    
    
    
    PIO_RESOURCE_DESCRIPTOR SelectedAlternative;

    
    
    
    
    ARBITER_RESULT Result;

} ARBITER_LIST_ENTRY, *PARBITER_LIST_ENTRY;





typedef
NTSTATUS
(*PARBITER_HANDLER) (
     PVOID Context,
     ARBITER_ACTION Action,
      PARBITER_PARAMETERS Parameters
    );














typedef struct _ARBITER_INTERFACE {

    
    
    
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;

    
    
    
    PARBITER_HANDLER ArbiterHandler;

    
    
    
    ULONG Flags;

} ARBITER_INTERFACE, *PARBITER_INTERFACE;





typedef enum _RESOURCE_TRANSLATION_DIRECTION {
    TranslateChildToParent,
    TranslateParentToChild
} RESOURCE_TRANSLATION_DIRECTION;





typedef
NTSTATUS
(*PTRANSLATE_RESOURCE_HANDLER)(
     PVOID Context,
     PCM_PARTIAL_RESOURCE_DESCRIPTOR Source,
     RESOURCE_TRANSLATION_DIRECTION Direction,
     ULONG AlternativesCount, 
     IO_RESOURCE_DESCRIPTOR Alternatives[], 
     PDEVICE_OBJECT PhysicalDeviceObject,
     PCM_PARTIAL_RESOURCE_DESCRIPTOR Target
);

typedef
NTSTATUS
(*PTRANSLATE_RESOURCE_REQUIREMENTS_HANDLER)(
     PVOID Context,
     PIO_RESOURCE_DESCRIPTOR Source,
     PDEVICE_OBJECT PhysicalDeviceObject,
     PULONG TargetCount,
     PIO_RESOURCE_DESCRIPTOR *Target
);





typedef struct _TRANSLATOR_INTERFACE {
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;
    PTRANSLATE_RESOURCE_HANDLER TranslateResources;
    PTRANSLATE_RESOURCE_REQUIREMENTS_HANDLER TranslateResourceRequirements;
} TRANSLATOR_INTERFACE, *PTRANSLATOR_INTERFACE;







typedef
NTSTATUS
(*PLEGACY_DEVICE_DETECTION_HANDLER)(
     PVOID Context,
     INTERFACE_TYPE LegacyBusType,
     ULONG BusNumber,
     ULONG SlotNumber,
     PDEVICE_OBJECT *PhysicalDeviceObject
);





typedef struct _LEGACY_DEVICE_DETECTION_INTERFACE {
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;
    PLEGACY_DEVICE_DETECTION_HANDLER LegacyDeviceDetection;
} LEGACY_DEVICE_DETECTION_INTERFACE, *PLEGACY_DEVICE_DETECTION_INTERFACE;






typedef struct _PLUGPLAY_NOTIFICATION_HEADER {
    USHORT Version; 
    USHORT Size;    
    GUID Event;
    
    
    
} PLUGPLAY_NOTIFICATION_HEADER, *PPLUGPLAY_NOTIFICATION_HEADER;





typedef struct _HWPROFILE_CHANGE_NOTIFICATION {
    USHORT Version;
    USHORT Size;
    GUID Event;
    
    
    
} HWPROFILE_CHANGE_NOTIFICATION, *PHWPROFILE_CHANGE_NOTIFICATION;






typedef struct _DEVICE_INTERFACE_CHANGE_NOTIFICATION {
    USHORT Version;
    USHORT Size;
    GUID Event;
    
    
    
    GUID InterfaceClassGuid;
    PUNICODE_STRING SymbolicLinkName;
} DEVICE_INTERFACE_CHANGE_NOTIFICATION, *PDEVICE_INTERFACE_CHANGE_NOTIFICATION;










typedef struct _TARGET_DEVICE_REMOVAL_NOTIFICATION {
    USHORT Version;
    USHORT Size;
    GUID Event;
    
    
    
    PFILE_OBJECT FileObject;
} TARGET_DEVICE_REMOVAL_NOTIFICATION, *PTARGET_DEVICE_REMOVAL_NOTIFICATION;











typedef struct _TARGET_DEVICE_CUSTOM_NOTIFICATION {
    USHORT Version;
    USHORT Size;
    GUID Event;
    
    
    
    PFILE_OBJECT FileObject;    
                                
                                
                                
                                
                                
                                
    LONG NameBufferOffset;      
                                
                                
    UCHAR CustomDataBuffer[1];  
                                
                                
                                
                                
} TARGET_DEVICE_CUSTOM_NOTIFICATION, *PTARGET_DEVICE_CUSTOM_NOTIFICATION;





typedef struct _DEVICE_DESCRIPTION {
    ULONG Version;
    BOOLEAN Master;
    BOOLEAN ScatterGather;
    BOOLEAN DemandMode;
    BOOLEAN AutoInitialize;
    BOOLEAN Dma32BitAddresses;
    BOOLEAN IgnoreCount;
    BOOLEAN Reserved1;          
    BOOLEAN Dma64BitAddresses;
    ULONG BusNumber; 
    ULONG DmaChannel;
    INTERFACE_TYPE  InterfaceType;
    DMA_WIDTH DmaWidth;
    DMA_SPEED DmaSpeed;
    ULONG MaximumLength;
    ULONG DmaPort;
} DEVICE_DESCRIPTION, *PDEVICE_DESCRIPTION;














typedef
BOOLEAN
(*PHAL_RESET_DISPLAY_PARAMETERS) (
     ULONG Columns,
     ULONG Rows
    );

__declspec(dllimport)
void
HalAcquireDisplayOwnership (
     PHAL_RESET_DISPLAY_PARAMETERS  ResetDisplayParameters
    );









#line 17146 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
                                                

                                                

#line 17151 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
                                                
__declspec(dllimport)                                        
void                                            
KeFlushWriteBuffer (                            
    void                                        
    );                                          
                                                




__declspec(dllimport)
NTSTATUS
HalAssignSlotResources (
     PUNICODE_STRING RegistryPath,
     PUNICODE_STRING DriverClassName ,
     PDRIVER_OBJECT DriverObject,
     PDEVICE_OBJECT DeviceObject,
     INTERFACE_TYPE BusType,
     ULONG BusNumber,
     ULONG SlotNumber,
      PCM_RESOURCE_LIST *AllocatedResources
    );

__declspec(dllimport)
ULONG
HalGetInterruptVector(
     INTERFACE_TYPE  InterfaceType,
     ULONG BusNumber,
     ULONG BusInterruptLevel,
     ULONG BusInterruptVector,
     PKIRQL Irql,
     PKAFFINITY Affinity
    );

__declspec(dllimport)
ULONG
HalSetBusData(
     BUS_DATA_TYPE BusDataType,
     ULONG BusNumber,
     ULONG SlotNumber,
     PVOID Buffer,
     ULONG Length
    );
#line 17196 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
ULONG
HalSetBusDataByOffset(
     BUS_DATA_TYPE BusDataType,
     ULONG BusNumber,
     ULONG SlotNumber,
     PVOID Buffer,
     ULONG Offset,
     ULONG Length
    );

__declspec(dllimport)
BOOLEAN
HalTranslateBusAddress(
     INTERFACE_TYPE  InterfaceType,
     ULONG BusNumber,
     PHYSICAL_ADDRESS BusAddress,
      PULONG AddressSpace,
     PPHYSICAL_ADDRESS TranslatedAddress
    );

















__declspec(dllimport)
PVOID
HalAllocateCrashDumpRegisters(
     PADAPTER_OBJECT AdapterObject,
      PULONG NumberOfMapRegisters
    );


__declspec(dllimport)
ULONG
HalGetBusData(
     BUS_DATA_TYPE BusDataType,
     ULONG BusNumber,
     ULONG SlotNumber,
     PVOID Buffer,
     ULONG Length
    );
#line 17252 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

__declspec(dllimport)
ULONG
HalGetBusDataByOffset(
     BUS_DATA_TYPE BusDataType,
     ULONG BusNumber,
     ULONG SlotNumber,
     PVOID Buffer,
     ULONG Offset,
     ULONG Length
    );

__declspec(dllimport)
PADAPTER_OBJECT
HalGetAdapter(
     PDEVICE_DESCRIPTION DeviceDescription,
      PULONG NumberOfMapRegisters
    );





__declspec(dllimport)
BOOLEAN
HalMakeBeep(
     ULONG Frequency
    );
#line 17281 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"






































#line 17320 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"
__declspec(dllimport)
NTSTATUS
IoReadPartitionTable(
     PDEVICE_OBJECT DeviceObject,
     ULONG SectorSize,
     BOOLEAN ReturnRecognizedPartitions,
     struct _DRIVE_LAYOUT_INFORMATION **PartitionBuffer
    );

__declspec(dllimport)
NTSTATUS
IoSetPartitionInformation(
     PDEVICE_OBJECT DeviceObject,
     ULONG SectorSize,
     ULONG PartitionNumber,
     ULONG PartitionType
    );

__declspec(dllimport)
NTSTATUS
IoWritePartitionTable(
     PDEVICE_OBJECT DeviceObject,
     ULONG SectorSize,
     ULONG SectorsPerTrack,
     ULONG NumberOfHeads,
     struct _DRIVE_LAYOUT_INFORMATION *PartitionBuffer
    );
#line 17348 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"





__declspec(dllimport)
LARGE_INTEGER
KeQueryPerformanceCounter (
    PLARGE_INTEGER PerformanceFrequency 
   );






__declspec(dllimport)
void
KeStallExecutionProcessor (
     ULONG MicroSeconds
    );


typedef
void
(*PDEVICE_CONTROL_COMPLETION)(
     struct _DEVICE_CONTROL_CONTEXT     *ControlContext
    );

typedef struct _DEVICE_CONTROL_CONTEXT {
    NTSTATUS                Status;
    PDEVICE_HANDLER_OBJECT  DeviceHandler;
    PDEVICE_OBJECT          DeviceObject;
    ULONG                   ControlCode;
    PVOID                   Buffer;
    PULONG                  BufferLength;
    PVOID                   Context;
} DEVICE_CONTROL_CONTEXT, *PDEVICE_CONTROL_CONTEXT;

typedef
PBUS_HANDLER
(_fastcall *pHalHandlerForBus) (
     INTERFACE_TYPE InterfaceType,
     ULONG          BusNumber
    );
typedef
void
(_fastcall *pHalReferenceBusHandler) (
     PBUS_HANDLER   BusHandler
    );





typedef enum _HAL_QUERY_INFORMATION_CLASS {
    HalInstalledBusInformation,
    HalProfileSourceInformation,
    HalInformationClassUnused1,
    HalPowerInformation,
    HalProcessorSpeedInformation,
    HalCallbackInformation,
    HalMapRegisterInformation,
    HalMcaLogInformation,
    HalFrameBufferCachingInformation,
    HalDisplayBiosInformation,
    HalProcessorFeatureInformation
    
} HAL_QUERY_INFORMATION_CLASS, *PHAL_QUERY_INFORMATION_CLASS;


typedef enum _HAL_SET_INFORMATION_CLASS {
    HalProfileSourceInterval,
    HalProfileSourceInterruptHandler,
    HalMcaRegisterDriver
} HAL_SET_INFORMATION_CLASS, *PHAL_SET_INFORMATION_CLASS;


typedef
NTSTATUS
(*pHalQuerySystemInformation)(
     HAL_QUERY_INFORMATION_CLASS  InformationClass,
     ULONG     BufferSize,
      PVOID Buffer,
     PULONG   ReturnedLength
    );

NTSTATUS
HaliQuerySystemInformation(
     HAL_SET_INFORMATION_CLASS    InformationClass,
     ULONG     BufferSize,
      PVOID Buffer,
     PULONG   ReturnedLength
    );

typedef
NTSTATUS
(*pHalSetSystemInformation)(
     HAL_SET_INFORMATION_CLASS    InformationClass,
     ULONG     BufferSize,
     PVOID     Buffer
    );

NTSTATUS
HaliSetSystemInformation(
     HAL_SET_INFORMATION_CLASS    InformationClass,
     ULONG     BufferSize,
     PVOID     Buffer
    );

typedef
void
(_fastcall *pHalExamineMBR)(
     PDEVICE_OBJECT DeviceObject,
     ULONG SectorSize,
     ULONG MBRTypeIdentifier,
     PVOID *Buffer
    );

typedef
void
(_fastcall *pHalIoAssignDriveLetters)(
     struct _LOADER_PARAMETER_BLOCK *LoaderBlock,
     PSTRING NtDeviceName,
     PUCHAR NtSystemPath,
     PSTRING NtSystemPathString
    );

typedef
NTSTATUS
(_fastcall *pHalIoReadPartitionTable)(
     PDEVICE_OBJECT DeviceObject,
     ULONG SectorSize,
     BOOLEAN ReturnRecognizedPartitions,
     struct _DRIVE_LAYOUT_INFORMATION **PartitionBuffer
    );

typedef
NTSTATUS
(_fastcall *pHalIoSetPartitionInformation)(
     PDEVICE_OBJECT DeviceObject,
     ULONG SectorSize,
     ULONG PartitionNumber,
     ULONG PartitionType
    );

typedef
NTSTATUS
(_fastcall *pHalIoWritePartitionTable)(
     PDEVICE_OBJECT DeviceObject,
     ULONG SectorSize,
     ULONG SectorsPerTrack,
     ULONG NumberOfHeads,
     struct _DRIVE_LAYOUT_INFORMATION *PartitionBuffer
    );

typedef
NTSTATUS
(*pHalQueryBusSlots)(
     PBUS_HANDLER         BusHandler,
     ULONG                BufferSize,
     PULONG              SlotNumbers,
     PULONG              ReturnedLength
    );

typedef
NTSTATUS
(*pHalInitPnpDriver)(
    void
    );

NTSTATUS
HaliInitPnpDriver(
    void
    );

typedef struct _PM_DISPATCH_TABLE {
    ULONG   Signature;
    ULONG   Version;
    PVOID   Function[1];
} PM_DISPATCH_TABLE, *PPM_DISPATCH_TABLE;

typedef
NTSTATUS
(*pHalInitPowerManagement)(
     PPM_DISPATCH_TABLE  PmDriverDispatchTable,
     PPM_DISPATCH_TABLE *PmHalDispatchTable
    );

NTSTATUS
HaliInitPowerManagement(
     PPM_DISPATCH_TABLE  PmDriverDispatchTable,
      PPM_DISPATCH_TABLE *PmHalDispatchTable
    );

typedef
struct _DMA_ADAPTER *
(*pHalGetDmaAdapter)(
     PVOID Context,
     struct _DEVICE_DESCRIPTION *DeviceDescriptor,
     PULONG NumberOfMapRegisters
    );

struct _DMA_ADAPTER *
HaliGetDmaAdapter(
     PVOID Context,
     struct _DEVICE_DESCRIPTION *DeviceDescriptor,
     PULONG NumberOfMapRegisters
    );

typedef
NTSTATUS
(*pHalGetInterruptTranslator)(
     INTERFACE_TYPE ParentInterfaceType,
     ULONG ParentBusNumber,
     INTERFACE_TYPE BridgeInterfaceType,
     USHORT Size,
     USHORT Version,
     PTRANSLATOR_INTERFACE Translator,
     PULONG BridgeBusNumber
    );

NTSTATUS
HaliGetInterruptTranslator(
     INTERFACE_TYPE ParentInterfaceType,
     ULONG ParentBusNumber,
     INTERFACE_TYPE BridgeInterfaceType,
     USHORT Size,
     USHORT Version,
     PTRANSLATOR_INTERFACE Translator,
     PULONG BridgeBusNumber
    );

typedef
BOOLEAN
(*pHalTranslateBusAddress)(
     INTERFACE_TYPE  InterfaceType,
     ULONG BusNumber,
     PHYSICAL_ADDRESS BusAddress,
      PULONG AddressSpace,
     PPHYSICAL_ADDRESS TranslatedAddress
    );

typedef
NTSTATUS
(*pHalAssignSlotResources) (
     PUNICODE_STRING RegistryPath,
     PUNICODE_STRING DriverClassName ,
     PDRIVER_OBJECT DriverObject,
     PDEVICE_OBJECT DeviceObject,
     INTERFACE_TYPE BusType,
     ULONG BusNumber,
     ULONG SlotNumber,
      PCM_RESOURCE_LIST *AllocatedResources
    );

typedef
void
(*pHalHaltSystem) (
    void
    );

typedef
void
(*pHalResetDisplay) (
    void
    );

typedef
BOOLEAN
(*pHalFindBusAddressTranslation) (
     PHYSICAL_ADDRESS BusAddress,
      PULONG AddressSpace,
     PPHYSICAL_ADDRESS TranslatedAddress,
      PULONG_PTR Context,
     BOOLEAN NextBus
    );

typedef struct {
    ULONG                           Version;
    pHalQuerySystemInformation      HalQuerySystemInformation;
    pHalSetSystemInformation        HalSetSystemInformation;
    pHalQueryBusSlots               HalQueryBusSlots;
    ULONG                           Spare1;
    pHalExamineMBR                  HalExamineMBR;
    pHalIoAssignDriveLetters        HalIoAssignDriveLetters;
    pHalIoReadPartitionTable        HalIoReadPartitionTable;
    pHalIoSetPartitionInformation   HalIoSetPartitionInformation;
    pHalIoWritePartitionTable       HalIoWritePartitionTable;

    pHalHandlerForBus               HalReferenceHandlerForBus;
    pHalReferenceBusHandler         HalReferenceBusHandler;
    pHalReferenceBusHandler         HalDereferenceBusHandler;

    pHalInitPnpDriver               HalInitPnpDriver;
    pHalInitPowerManagement         HalInitPowerManagement;

    pHalGetDmaAdapter               HalGetDmaAdapter;
    pHalGetInterruptTranslator      HalGetInterruptTranslator;
} HAL_DISPATCH, *PHAL_DISPATCH;



extern  PHAL_DISPATCH   HalDispatchTable;







#line 17660 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




























typedef struct _HAL_BUS_INFORMATION{
    INTERFACE_TYPE  BusType;
    BUS_DATA_TYPE   ConfigurationType;
    ULONG           BusNumber;
    ULONG           Reserved;
} HAL_BUS_INFORMATION, *PHAL_BUS_INFORMATION;


typedef struct _HAL_PROFILE_SOURCE_INFORMATION {
    KPROFILE_SOURCE Source;
    BOOLEAN Supported;
    ULONG Interval;
} HAL_PROFILE_SOURCE_INFORMATION, *PHAL_PROFILE_SOURCE_INFORMATION;


typedef struct _HAL_PROFILE_SOURCE_INTERVAL {
    KPROFILE_SOURCE Source;
    ULONG_PTR Interval;
} HAL_PROFILE_SOURCE_INTERVAL, *PHAL_PROFILE_SOURCE_INTERVAL;


typedef enum _HAL_DISPLAY_BIOS_INFORMATION {
    HalDisplayInt10Bios,
    HalDisplayEmulatedBios,
    HalDisplayNoBios
} HAL_DISPLAY_BIOS_INFORMATION, *PHAL_DISPLAY_BIOS_INFORMATION;


typedef struct _HAL_POWER_INFORMATION {
    ULONG   TBD;
} HAL_POWER_INFORMATION, *PHAL_POWER_INFORMATION;


typedef struct _HAL_PROCESSOR_SPEED_INFO {
    ULONG   TBD;
} HAL_PROCESSOR_SPEED_INFORMATION, *PHAL_PROCESSOR_SPEED_INFORMATION;


typedef struct _HAL_CALLBACKS {
    PCALLBACK_OBJECT  SetSystemInformation;
    PCALLBACK_OBJECT  BusCheck;
} HAL_CALLBACKS, *PHAL_CALLBACKS;


typedef struct _HAL_PROCESSOR_FEATURE {
    ULONG UsableFeatureBits;
} HAL_PROCESSOR_FEATURE;









typedef union _MCI_ADDR{
    struct {
        ULONG Address;
        ULONG Reserved;
    };

    ULONGLONG   QuadPart;
} MCI_ADDR, *PMCI_ADDR;


typedef enum {
    HAL_MCE_RECORD,
    HAL_MCA_RECORD
} MCA_EXCEPTION_TYPE;






typedef struct _MCA_EXCEPTION {

    ULONG               VersionNumber;      
    MCA_EXCEPTION_TYPE  ExceptionType;      
    LARGE_INTEGER       TimeStamp;          
    ULONG               ProcessorNumber;

    union {
        struct {
            UCHAR           BankNumber;
            MCI_STATS       Status;
            MCI_ADDR        Address;
            ULONGLONG       Misc;
        } Mca;

        struct {
            ULONGLONG       Address;        
            ULONGLONG       Type;           
        } Mce;
    } u;

} MCA_EXCEPTION, *PMCA_EXCEPTION;




typedef
void
(*PDRIVER_EXCPTN_CALLBACK) (
     PVOID            Context,
     PMCA_EXCEPTION   BankLog
);




typedef struct _MCA_DRIVER_INFO {
    PDRIVER_EXCPTN_CALLBACK ExceptionCallback;
    PKDEFERRED_ROUTINE      DpcCallback;
    PVOID                   DeviceContext;
} MCA_DRIVER_INFO, *PMCA_DRIVER_INFO;

#line 17807 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



typedef struct _SCATTER_GATHER_ELEMENT {
    PHYSICAL_ADDRESS Address;
    ULONG Length;
    ULONG_PTR Reserved;
} SCATTER_GATHER_ELEMENT, *PSCATTER_GATHER_ELEMENT;

#pragma warning(disable:4200)
typedef struct _SCATTER_GATHER_LIST {
    ULONG NumberOfElements;
    ULONG_PTR Reserved;
    SCATTER_GATHER_ELEMENT Elements[];
} SCATTER_GATHER_LIST, *PSCATTER_GATHER_LIST;
#pragma warning(default:4200)



typedef struct _DMA_OPERATIONS *PDMA_OPERATIONS;

typedef struct _DMA_ADAPTER {
    USHORT Version;
    USHORT Size;
    PDMA_OPERATIONS DmaOperations;
    
} DMA_ADAPTER, *PDMA_ADAPTER;

typedef void (*PPUT_DMA_ADAPTER)(
    PDMA_ADAPTER DmaAdapter
    );

typedef PVOID (*PALLOCATE_COMMON_BUFFER)(
     PDMA_ADAPTER DmaAdapter,
     ULONG Length,
     PPHYSICAL_ADDRESS LogicalAddress,
     BOOLEAN CacheEnabled
    );

typedef void (*PFREE_COMMON_BUFFER)(
     PDMA_ADAPTER DmaAdapter,
     ULONG Length,
     PHYSICAL_ADDRESS LogicalAddress,
     PVOID VirtualAddress,
     BOOLEAN CacheEnabled
    );

typedef NTSTATUS (*PALLOCATE_ADAPTER_CHANNEL)(
     PDMA_ADAPTER DmaAdapter,
     PDEVICE_OBJECT DeviceObject,
     ULONG NumberOfMapRegisters,
     PDRIVER_CONTROL ExecutionRoutine,
     PVOID Context
    );

typedef BOOLEAN (*PFLUSH_ADAPTER_BUFFERS)(
     PDMA_ADAPTER DmaAdapter,
     PMDL Mdl,
     PVOID MapRegisterBase,
     PVOID CurrentVa,
     ULONG Length,
     BOOLEAN WriteToDevice
    );

typedef void (*PFREE_ADAPTER_CHANNEL)(
     PDMA_ADAPTER DmaAdapter
    );

typedef void (*PFREE_MAP_REGISTERS)(
     PDMA_ADAPTER DmaAdapter,
    PVOID MapRegisterBase,
    ULONG NumberOfMapRegisters
    );

typedef PHYSICAL_ADDRESS (*PMAP_TRANSFER)(
     PDMA_ADAPTER DmaAdapter,
     PMDL Mdl,
     PVOID MapRegisterBase,
     PVOID CurrentVa,
      PULONG Length,
     BOOLEAN WriteToDevice
    );

typedef ULONG (*PGET_DMA_ALIGNMENT)(
     PDMA_ADAPTER DmaAdapter
    );

typedef ULONG (*PREAD_DMA_COUNTER)(
     PDMA_ADAPTER DmaAdapter
    );

typedef void
(*PDRIVER_LIST_CONTROL)(
     struct _DEVICE_OBJECT *DeviceObject,
     struct _IRP *Irp,
     PSCATTER_GATHER_LIST ScatterGather,
     PVOID Context
    );

typedef NTSTATUS
(*PGET_SCATTER_GATHER_LIST)(
     PDMA_ADAPTER DmaAdapter,
     PDEVICE_OBJECT DeviceObject,
     PMDL Mdl,
     PVOID CurrentVa,
     ULONG Length,
     PDRIVER_LIST_CONTROL ExecutionRoutine,
     PVOID Context,
     BOOLEAN WriteToDevice
    );

typedef void
(*PPUT_SCATTER_GATHER_LIST)(
     PDMA_ADAPTER DmaAdapter,
     PSCATTER_GATHER_LIST ScatterGather,
     BOOLEAN WriteToDevice
    );

typedef struct _DMA_OPERATIONS {
    ULONG Size;
    PPUT_DMA_ADAPTER PutDmaAdapter;
    PALLOCATE_COMMON_BUFFER AllocateCommonBuffer;
    PFREE_COMMON_BUFFER FreeCommonBuffer;
    PALLOCATE_ADAPTER_CHANNEL AllocateAdapterChannel;
    PFLUSH_ADAPTER_BUFFERS FlushAdapterBuffers;
    PFREE_ADAPTER_CHANNEL FreeAdapterChannel;
    PFREE_MAP_REGISTERS FreeMapRegisters;
    PMAP_TRANSFER MapTransfer;
    PGET_DMA_ALIGNMENT GetDmaAlignment;
    PREAD_DMA_COUNTER ReadDmaCounter;
    PGET_SCATTER_GATHER_LIST GetScatterGatherList;
    PPUT_SCATTER_GATHER_LIST PutScatterGatherList;
} DMA_OPERATIONS;




















#line 17961 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"






































































































































































































#line 18160 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"




__declspec(dllimport)
NTSTATUS
HalAllocateAdapterChannel(
     PADAPTER_OBJECT AdapterObject,
     PWAIT_CONTEXT_BLOCK Wcb,
     ULONG NumberOfMapRegisters,
     PDRIVER_CONTROL ExecutionRoutine
    );

__declspec(dllimport)
PVOID
HalAllocateCommonBuffer(
     PADAPTER_OBJECT AdapterObject,
     ULONG Length,
     PPHYSICAL_ADDRESS LogicalAddress,
     BOOLEAN CacheEnabled
    );

__declspec(dllimport)
void
HalFreeCommonBuffer(
     PADAPTER_OBJECT AdapterObject,
     ULONG Length,
     PHYSICAL_ADDRESS LogicalAddress,
     PVOID VirtualAddress,
     BOOLEAN CacheEnabled
    );

__declspec(dllimport)
ULONG
HalReadDmaCounter(
     PADAPTER_OBJECT AdapterObject
    );

__declspec(dllimport)
BOOLEAN
IoFlushAdapterBuffers(
     PADAPTER_OBJECT AdapterObject,
     PMDL Mdl,
     PVOID MapRegisterBase,
     PVOID CurrentVa,
     ULONG Length,
     BOOLEAN WriteToDevice
    );

__declspec(dllimport)
void
IoFreeAdapterChannel(
     PADAPTER_OBJECT AdapterObject
    );

__declspec(dllimport)
void
IoFreeMapRegisters(
    PADAPTER_OBJECT AdapterObject,
    PVOID MapRegisterBase,
    ULONG NumberOfMapRegisters
   );

__declspec(dllimport)
PHYSICAL_ADDRESS
IoMapTransfer(
     PADAPTER_OBJECT AdapterObject,
     PMDL Mdl,
     PVOID MapRegisterBase,
     PVOID CurrentVa,
      PULONG Length,
     BOOLEAN WriteToDevice
    );
#line 18234 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

NTSTATUS
HalGetScatterGatherList (
     PADAPTER_OBJECT DmaAdapter,
     PDEVICE_OBJECT DeviceObject,
     PMDL Mdl,
     PVOID CurrentVa,
     ULONG Length,
     PDRIVER_LIST_CONTROL ExecutionRoutine,
     PVOID Context,
     BOOLEAN WriteToDevice
    );

void
HalPutScatterGatherList (
     PADAPTER_OBJECT DmaAdapter,
     PSCATTER_GATHER_LIST ScatterGather,
     BOOLEAN WriteToDevice
    );

void
HalPutDmaAdapter(
     PADAPTER_OBJECT DmaAdapter
    );


__declspec(dllimport)
void
PoSetSystemState (
     EXECUTION_STATE Flags
    );

__declspec(dllimport)
PVOID
PoRegisterSystemState (
     PVOID StateHandle,
     EXECUTION_STATE Flags
    );

typedef
void
(*PREQUEST_POWER_COMPLETE) (
     PDEVICE_OBJECT DeviceObject,
     UCHAR MinorFunction,
     POWER_STATE PowerState,
     PVOID Context,
     PIO_STATUS_BLOCK IoStatus
    );

__declspec(dllimport)
NTSTATUS
PoRequestPowerIrp (
     PDEVICE_OBJECT DeviceObject,
     UCHAR MinorFunction,
     POWER_STATE PowerState,
     PREQUEST_POWER_COMPLETE CompletionFunction,
     PVOID Context,
     PIRP *Irp 
    );

__declspec(dllimport)
void
PoUnregisterSystemState (
     PVOID StateHandle
    );


__declspec(dllimport)
POWER_STATE
PoSetPowerState (
     PDEVICE_OBJECT   DeviceObject,
     POWER_STATE_TYPE Type,
     POWER_STATE      State
    );

__declspec(dllimport)
NTSTATUS
PoCallDriver (
     PDEVICE_OBJECT   DeviceObject,
      PIRP         Irp
    );

__declspec(dllimport)
void
PoStartNextPowerIrp(
     PIRP    Irp
    );


__declspec(dllimport)
PULONG
PoRegisterDeviceForIdleDetection (
     PDEVICE_OBJECT     DeviceObject,
     ULONG              ConservationIdleTime,
     ULONG              PerformanceIdleTime,
     DEVICE_POWER_STATE State
    );


















__declspec(dllimport)
BOOLEAN
FsRtlIsTotalDeviceFailure(
     NTSTATUS Status
    );





typedef struct _OBJECT_HANDLE_INFORMATION {
    ULONG HandleAttributes;
    ACCESS_MASK GrantedAccess;
} OBJECT_HANDLE_INFORMATION, *POBJECT_HANDLE_INFORMATION;

__declspec(dllimport)                                                     
NTSTATUS                                                        
ObReferenceObjectByHandle(                                      
     HANDLE Handle,                                           
     ACCESS_MASK DesiredAccess,                               
     POBJECT_TYPE ObjectType ,                        
     KPROCESSOR_MODE AccessMode,                              
     PVOID *Object,                                          
     POBJECT_HANDLE_INFORMATION HandleInformation    
    );                                                          






__declspec(dllimport)
void
_fastcall
ObfReferenceObject(
     PVOID Object
    );


__declspec(dllimport)
NTSTATUS
ObReferenceObjectByPointer(
     PVOID Object,
     ACCESS_MASK DesiredAccess,
     POBJECT_TYPE ObjectType,
     KPROCESSOR_MODE AccessMode
    );

__declspec(dllimport)
void
_fastcall
ObfDereferenceObject(
     PVOID Object
    );

NTSTATUS
ObGetObjectSecurity(
     PVOID Object,
     PSECURITY_DESCRIPTOR *SecurityDescriptor,
     PBOOLEAN MemoryAllocated
    );

void
ObReleaseObjectSecurity(
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     BOOLEAN MemoryAllocated
    );
























typedef struct _PCI_SLOT_NUMBER {
    union {
        struct {
            ULONG   DeviceNumber:5;
            ULONG   FunctionNumber:3;
            ULONG   Reserved:24;
        } bits;
        ULONG   AsULONG;
    } u;
} PCI_SLOT_NUMBER, *PPCI_SLOT_NUMBER;






typedef struct _PCI_COMMON_CONFIG {
    USHORT  VendorID;                   
    USHORT  DeviceID;                   
    USHORT  Command;                    
    USHORT  Status;
    UCHAR   RevisionID;                 
    UCHAR   ProgIf;                     
    UCHAR   SubClass;                   
    UCHAR   BaseClass;                  
    UCHAR   CacheLineSize;              
    UCHAR   LatencyTimer;               
    UCHAR   HeaderType;                 
    UCHAR   BIST;                       

    union {
        struct _PCI_HEADER_TYPE_0 {
            ULONG   BaseAddresses[6];
            ULONG   CIS;
            USHORT  SubVendorID;
            USHORT  SubSystemID;
            ULONG   ROMBaseAddress;
            UCHAR   CapabilitiesPtr;
            UCHAR   Reserved1[3];
            ULONG   Reserved2;
            UCHAR   InterruptLine;      
            UCHAR   InterruptPin;       
            UCHAR   MinimumGrant;       
            UCHAR   MaximumLatency;     
        } type0;



        
        
        

        struct _PCI_HEADER_TYPE_1 {
            ULONG   BaseAddresses[2];
            UCHAR   PrimaryBus;
            UCHAR   SecondaryBus;
            UCHAR   SubordinateBus;
            UCHAR   SecondaryLatency;
            UCHAR   IOBase;
            UCHAR   IOLimit;
            USHORT  SecondaryStatus;
            USHORT  MemoryBase;
            USHORT  MemoryLimit;
            USHORT  PrefetchBase;
            USHORT  PrefetchLimit;
            ULONG   PrefetchBaseUpper32;
            ULONG   PrefetchLimitUpper32;
            USHORT  IOBaseUpper16;
            USHORT  IOLimitUpper16;
            UCHAR   CapabilitiesPtr;
            UCHAR   Reserved1[3];
            ULONG   ROMBaseAddress;
            UCHAR   InterruptLine;
            UCHAR   InterruptPin;
            USHORT  BridgeControl;
        } type1;

        
        
        

        struct _PCI_HEADER_TYPE_2 {
            ULONG   SocketRegistersBaseAddress;
            UCHAR   CapabilitiesPtr;
            UCHAR   Reserved;
            USHORT  SecondaryStatus;
            UCHAR   PrimaryBus;
            UCHAR   SecondaryBus;
            UCHAR   SubordinateBus;
            UCHAR   SecondaryLatency;
            struct  {
                ULONG   Base;
                ULONG   Limit;
            }       Range[5-1];
            UCHAR   InterruptLine;
            UCHAR   InterruptPin;
            USHORT  BridgeControl;
        } type2;



    } u;

    UCHAR   DeviceSpecific[192];

} PCI_COMMON_CONFIG, *PPCI_COMMON_CONFIG;



















































































typedef struct _PCI_CAPABILITIES_HEADER {
    UCHAR   CapabilityID;
    UCHAR   Next;
} PCI_CAPABILITIES_HEADER, *PPCI_CAPABILITIES_HEADER;





typedef struct _PCI_PMC {
    UCHAR       Version:3;
    UCHAR       PMEClock:1;
    UCHAR       Rsvd1:1;
    UCHAR       DeviceSpecificInitialization:1;
    UCHAR       Rsvd2:2;
    struct _PM_SUPPORT {
        UCHAR   Rsvd2:1;
        UCHAR   D1:1;
        UCHAR   D2:1;
        UCHAR   PMED0:1;
        UCHAR   PMED1:1;
        UCHAR   PMED2:1;
        UCHAR   PMED3Hot:1;
        UCHAR   PMED3Cold:1;
    } Support;
} PCI_PMC, *PPCI_PMC;

typedef struct _PCI_PMCSR {
    USHORT      PowerState:2;
    USHORT      Rsvd1:6;
    USHORT      PMEEnable:1;
    USHORT      DataSelect:4;
    USHORT      DataScale:2;
    USHORT      PMEStatus:1;
} PCI_PMCSR, *PPCI_PMCSR;


typedef struct _PCI_PMCSR_BSE {
    UCHAR       Rsvd1:6;
    UCHAR       D3HotSupportsStopClock:1;       
    UCHAR       BusPowerClockControlEnabled:1;  
} PCI_PMCSR_BSE, *PPCI_PMCSR_BSE;


typedef struct _PCI_PM_CAPABILITY {

    PCI_CAPABILITIES_HEADER Header;

    
    
    

    union {
        PCI_PMC         Capabilities;
        USHORT          AsUSHORT;
    } PMC;

    
    
    

    union {
        PCI_PMCSR       ControlStatus;
        USHORT          AsUSHORT;
    } PMCSR;

    
    
    

    union {
        PCI_PMCSR_BSE   BridgeSupport;
        UCHAR           AsUCHAR;
    } PMCSR_BSE;

    
    
    
    

    UCHAR   Data;

} PCI_PM_CAPABILITY, *PPCI_PM_CAPABILITY;





typedef struct _PCI_AGP_CAPABILITY {

    PCI_CAPABILITIES_HEADER Header;

    USHORT  Minor:4;
    USHORT  Major:4;
    USHORT  Rsvd1:8;

    struct  _PCI_AGP_STATUS {
        ULONG   Rate:3;
        ULONG   Rsvd1:1;
        ULONG   FastWrite:1;
        ULONG   FourGB:1;
        ULONG   Rsvd2:3;
        ULONG   SideBandAddressing:1;                   
        ULONG   Rsvd3:14;
        ULONG   RequestQueueDepthMaximum:8;             
    } AGPStatus;

    struct  _PCI_AGP_COMMAND {
        ULONG   Rate:3;
        ULONG   Rsvd1:1;
        ULONG   FastWriteEnable:1;
        ULONG   FourGBEnable:1;
        ULONG   Rsvd2:2;
        ULONG   AGPEnable:1;
        ULONG   SBAEnable:1;
        ULONG   Rsvd3:14;
        ULONG   RequestQueueDepth:8;
    } AGPCommand;

} PCI_AGP_CAPABILITY, *PPCI_AGP_CAPABILITY;









typedef struct _PCI_MSI_CAPABILITY {

      PCI_CAPABILITIES_HEADER Header;

      struct _PCI_MSI_MESSAGE_CONTROL {
         USHORT  MSIEnable:1;
         USHORT  MultipleMessageCapable:3;
         USHORT  MultipleMessageEnable:3;
         USHORT  CapableOf64Bits:1;
         USHORT  Reserved:8;
      } MessageControl;

      union {
            struct _PCI_MSI_MESSAGE_ADDRESS {
               ULONG_PTR Reserved:2;              
               ULONG_PTR Address:30;
            } Register;
            ULONG_PTR Raw;
      } MessageAddress;

      
      
      
      
      
      

      union {

         

         struct _PCI_MSI_64BIT_DATA {
            ULONG MessageUpperAddress;
            USHORT MessageData;
         } Bit64;

         

         struct _PCI_MSI_32BIT_DATA {
            USHORT MessageData;
            ULONG Unused;
         } Bit32;
      } Data;

} PCI_MSI_CAPABILITY, *PPCI_PCI_CAPABILITY;





















































































































































































typedef void
(*PciPin2Line) (
     struct _BUS_HANDLER  *BusHandler,
     struct _BUS_HANDLER  *RootHandler,
     PCI_SLOT_NUMBER      SlotNumber,
     PPCI_COMMON_CONFIG   PciData
    );

typedef void
(*PciLine2Pin) (
     struct _BUS_HANDLER  *BusHandler,
     struct _BUS_HANDLER  *RootHandler,
     PCI_SLOT_NUMBER      SlotNumber,
     PPCI_COMMON_CONFIG   PciNewData,
     PPCI_COMMON_CONFIG   PciOldData
    );

typedef void
(*PciReadWriteConfig) (
     struct _BUS_HANDLER *BusHandler,
     PCI_SLOT_NUMBER Slot,
     PVOID Buffer,
     ULONG Offset,
     ULONG Length
    );




typedef struct _PCIBUSDATA {
    ULONG                   Tag;
    ULONG                   Version;
    PciReadWriteConfig      ReadConfig;
    PciReadWriteConfig      WriteConfig;
    PciPin2Line             Pin2Line;
    PciLine2Pin             Line2Pin;
    PCI_SLOT_NUMBER         ParentSlot;
    PVOID                   Reserved[4];
} PCIBUSDATA, *PPCIBUSDATA;

typedef ULONG (*PCI_READ_WRITE_CONFIG)(
     PVOID Context,
     UCHAR BusOffset,
     ULONG Slot,
     PVOID Buffer,
     ULONG Offset,
     ULONG Length
    );

typedef void (*PCI_PIN_TO_LINE)(
     PVOID Context,
     PPCI_COMMON_CONFIG PciData
    );

typedef void (*PCI_LINE_TO_PIN)(
     PVOID Context,
     PPCI_COMMON_CONFIG PciNewData,
     PPCI_COMMON_CONFIG PciOldData
    );

typedef struct _PCI_BUS_INTERFACE_STANDARD {
    
    
    
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;
    
    
    
    PCI_READ_WRITE_CONFIG ReadConfig;
    PCI_READ_WRITE_CONFIG WriteConfig;
    PCI_PIN_TO_LINE PinToLine;
    PCI_LINE_TO_PIN LineToPin;
} PCI_BUS_INTERFACE_STANDARD, *PPCI_BUS_INTERFACE_STANDARD;





typedef
BOOLEAN
(*PPCI_IS_DEVICE_PRESENT) (
     USHORT VendorID,
     USHORT DeviceID,
     UCHAR RevisionID,
     USHORT SubVendorID,
     USHORT SubSystemID,
     ULONG Flags
);





typedef struct _PCI_DEVICE_PRESENT_INTERFACE {
    
    
    
    USHORT Size;
    USHORT Version;
    PVOID Context;
    PINTERFACE_REFERENCE InterfaceReference;
    PINTERFACE_DEREFERENCE InterfaceDereference;
    
    
    
    PPCI_IS_DEVICE_PRESENT IsDevicePresent;
} PCI_DEVICE_PRESENT_INTERFACE, *PPCI_DEVICE_PRESENT_INTERFACE;







#line 19103 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"

extern POBJECT_TYPE *IoFileObjectType;
extern POBJECT_TYPE *ExEventObjectType;
extern POBJECT_TYPE *ExSemaphoreObjectType;





__declspec(dllimport)
NTSTATUS
__stdcall
ZwCreateFile(
     PHANDLE FileHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes,
     PIO_STATUS_BLOCK IoStatusBlock,
     PLARGE_INTEGER AllocationSize ,
     ULONG FileAttributes,
     ULONG ShareAccess,
     ULONG CreateDisposition,
     ULONG CreateOptions,
     PVOID EaBuffer ,
     ULONG EaLength
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwOpenFile(
     PHANDLE FileHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes,
     PIO_STATUS_BLOCK IoStatusBlock,
     ULONG ShareAccess,
     ULONG OpenOptions
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwQueryInformationFile(
     HANDLE FileHandle,
     PIO_STATUS_BLOCK IoStatusBlock,
     PVOID FileInformation,
     ULONG Length,
     FILE_INFORMATION_CLASS FileInformationClass
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwSetInformationFile(
     HANDLE FileHandle,
     PIO_STATUS_BLOCK IoStatusBlock,
     PVOID FileInformation,
     ULONG Length,
     FILE_INFORMATION_CLASS FileInformationClass
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwReadFile(
     HANDLE FileHandle,
     HANDLE Event ,
     PIO_APC_ROUTINE ApcRoutine ,
     PVOID ApcContext ,
     PIO_STATUS_BLOCK IoStatusBlock,
     PVOID Buffer,
     ULONG Length,
     PLARGE_INTEGER ByteOffset ,
     PULONG Key 
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwWriteFile(
     HANDLE FileHandle,
     HANDLE Event ,
     PIO_APC_ROUTINE ApcRoutine ,
     PVOID ApcContext ,
     PIO_STATUS_BLOCK IoStatusBlock,
     PVOID Buffer,
     ULONG Length,
     PLARGE_INTEGER ByteOffset ,
     PULONG Key 
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwClose(
     HANDLE Handle
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwCreateDirectoryObject(
     PHANDLE DirectoryHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwMakeTemporaryObject(
     HANDLE Handle
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwCreateSection (
     PHANDLE SectionHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes ,
     PLARGE_INTEGER MaximumSize ,
     ULONG SectionPageProtection,
     ULONG AllocationAttributes,
     HANDLE FileHandle 
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwOpenSection(
     PHANDLE SectionHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwMapViewOfSection(
     HANDLE SectionHandle,
     HANDLE ProcessHandle,
      PVOID *BaseAddress,
     ULONG ZeroBits,
     ULONG CommitSize,
      PLARGE_INTEGER SectionOffset ,
      PSIZE_T ViewSize,
     SECTION_INHERIT InheritDisposition,
     ULONG AllocationType,
     ULONG Protect
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwUnmapViewOfSection(
     HANDLE ProcessHandle,
     PVOID BaseAddress
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwSetInformationThread(
     HANDLE ThreadHandle,
     THREADINFOCLASS ThreadInformationClass,
     PVOID ThreadInformation,
     ULONG ThreadInformationLength
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwCreateKey(
     PHANDLE KeyHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes,
     ULONG TitleIndex,
     PUNICODE_STRING Class ,
     ULONG CreateOptions,
     PULONG Disposition 
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwOpenKey(
     PHANDLE KeyHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwDeleteKey(
     HANDLE KeyHandle
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwEnumerateKey(
     HANDLE KeyHandle,
     ULONG Index,
     KEY_INFORMATION_CLASS KeyInformationClass,
     PVOID KeyInformation,
     ULONG Length,
     PULONG ResultLength
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwEnumerateValueKey(
     HANDLE KeyHandle,
     ULONG Index,
     KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
     PVOID KeyValueInformation,
     ULONG Length,
     PULONG ResultLength
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwFlushKey(
     HANDLE KeyHandle
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwQueryKey(
     HANDLE KeyHandle,
     KEY_INFORMATION_CLASS KeyInformationClass,
     PVOID KeyInformation,
     ULONG Length,
     PULONG ResultLength
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwQueryValueKey(
     HANDLE KeyHandle,
     PUNICODE_STRING ValueName,
     KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
     PVOID KeyValueInformation,
     ULONG Length,
     PULONG ResultLength
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwSetValueKey(
     HANDLE KeyHandle,
     PUNICODE_STRING ValueName,
     ULONG TitleIndex ,
     ULONG Type,
     PVOID Data,
     ULONG DataSize
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwOpenSymbolicLinkObject(
     PHANDLE LinkHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes
    );

__declspec(dllimport)
NTSTATUS
__stdcall
ZwQuerySymbolicLinkObject(
     HANDLE LinkHandle,
      PUNICODE_STRING LinkTarget,
     PULONG ReturnedLength 
    );

NTSTATUS
ZwCreateTimer (
     PHANDLE TimerHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes ,
     TIMER_TYPE TimerType
    );

NTSTATUS
ZwOpenTimer (
     PHANDLE TimerHandle,
     ACCESS_MASK DesiredAccess,
     POBJECT_ATTRIBUTES ObjectAttributes
    );

NTSTATUS
ZwCancelTimer (
     HANDLE TimerHandle,
     PBOOLEAN CurrentState 
    );

NTSTATUS
ZwSetTimer (
     HANDLE TimerHandle,
     PLARGE_INTEGER DueTime,
     PTIMER_APC_ROUTINE TimerApcRoutine ,
     PVOID TimerContext ,
     BOOLEAN WakeTimer,
     LONG Period ,
     PBOOLEAN PreviousState 
    );

#line 19418 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"


#line 7 "Usb.c"
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"






























  
  
  
#line 35 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"






typedef void (*WDFFUNC) (void);
extern WDFFUNC WdfFunctions [];








#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdftypes.h"




































typedef UCHAR BYTE;
#line 39 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdftypes.h"





















#line 61 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdftypes.h"






typedef enum _WDF_TRI_STATE {
    WdfFalse = 0,
    WdfTrue = 1,
    WdfUseDefault = 2,
} WDF_TRI_STATE, *PWDF_TRI_STATE;



typedef PVOID WDFCONTEXT;




typedef struct WDFDEVICE_INIT *PWDFDEVICE_INIT;

typedef struct _WDF_OBJECT_ATTRIBUTES *PWDF_OBJECT_ATTRIBUTES;











typedef HANDLE WDFOBJECT, *PWDFOBJECT;




struct WDFDRIVER__ { int unused; }; typedef struct WDFDRIVER__ *WDFDRIVER;
struct WDFDEVICE__ { int unused; }; typedef struct WDFDEVICE__ *WDFDEVICE;

struct WDFWMIPROVIDER__ { int unused; }; typedef struct WDFWMIPROVIDER__ *WDFWMIPROVIDER;
struct WDFWMIINSTANCE__ { int unused; }; typedef struct WDFWMIINSTANCE__ *WDFWMIINSTANCE;

struct WDFQUEUE__ { int unused; }; typedef struct WDFQUEUE__ *WDFQUEUE;
struct WDFREQUEST__ { int unused; }; typedef struct WDFREQUEST__ *WDFREQUEST;
struct WDFFILEOBJECT__ { int unused; }; typedef struct WDFFILEOBJECT__ *WDFFILEOBJECT;
struct WDFDPC__ { int unused; }; typedef struct WDFDPC__ *WDFDPC;
struct WDFTIMER__ { int unused; }; typedef struct WDFTIMER__ *WDFTIMER;
struct WDFWORKITEM__ { int unused; }; typedef struct WDFWORKITEM__ *WDFWORKITEM;
struct WDFINTERRUPT__ { int unused; }; typedef struct WDFINTERRUPT__ *WDFINTERRUPT;




struct WDFWAITLOCK__ { int unused; }; typedef struct WDFWAITLOCK__ *WDFWAITLOCK;
struct WDFSPINLOCK__ { int unused; }; typedef struct WDFSPINLOCK__ *WDFSPINLOCK;

struct WDFMEMORY__ { int unused; }; typedef struct WDFMEMORY__ *WDFMEMORY;
struct WDFLOOKASIDE__ { int unused; }; typedef struct WDFLOOKASIDE__ *WDFLOOKASIDE;




struct WDFIOTARGET__ { int unused; }; typedef struct WDFIOTARGET__ *WDFIOTARGET;
struct WDFUSBDEVICE__ { int unused; }; typedef struct WDFUSBDEVICE__ *WDFUSBDEVICE;
struct WDFUSBINTERFACE__ { int unused; }; typedef struct WDFUSBINTERFACE__ *WDFUSBINTERFACE;
struct WDFUSBPIPE__ { int unused; }; typedef struct WDFUSBPIPE__ *WDFUSBPIPE;


struct WDFDMAENABLER__ { int unused; }; typedef struct WDFDMAENABLER__ *WDFDMAENABLER;
struct WDFDMATRANSACTION__ { int unused; }; typedef struct WDFDMATRANSACTION__ *WDFDMATRANSACTION;
struct WDFCOMMONBUFFER__ { int unused; }; typedef struct WDFCOMMONBUFFER__ *WDFCOMMONBUFFER;




struct WDFKEY__ { int unused; }; typedef struct WDFKEY__ *WDFKEY;
struct WDFSTRING__ { int unused; }; typedef struct WDFSTRING__ *WDFSTRING;
struct WDFCOLLECTION__ { int unused; }; typedef struct WDFCOLLECTION__ *WDFCOLLECTION;
struct WDFCHILDLIST__ { int unused; }; typedef struct WDFCHILDLIST__ *WDFCHILDLIST;

struct WDFIORESREQLIST__ { int unused; }; typedef struct WDFIORESREQLIST__ *WDFIORESREQLIST;
struct WDFIORESLIST__ { int unused; }; typedef struct WDFIORESLIST__ *WDFIORESLIST;
struct WDFCMRESLIST__ { int unused; }; typedef struct WDFCMRESLIST__ *WDFCMRESLIST;



#line 150 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdftypes.h"


#line 153 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdftypes.h"

#line 52 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfglobals.h"
































typedef struct _WDF_DRIVER_GLOBALS {

    
    WDFDRIVER Driver;

    
    ULONG DriverFlags;

    
    
    ULONG DriverTag;

    CHAR DriverName[(32)];

    
    
    
    BOOLEAN DisplaceDriverUnload;

} WDF_DRIVER_GLOBALS, *PWDF_DRIVER_GLOBALS;









#line 63 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfglobals.h"

#line 53 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdffuncenum.h"
















extern PWDF_DRIVER_GLOBALS WdfDriverGlobals;

typedef enum _WDFFUNCENUM {

    WdfChildListCreateTableIndex = 0,
    WdfChildListGetDeviceTableIndex = 1,
    WdfChildListRetrievePdoTableIndex = 2,
    WdfChildListRetrieveAddressDescriptionTableIndex = 3,
    WdfChildListBeginScanTableIndex = 4,
    WdfChildListEndScanTableIndex = 5,
    WdfChildListBeginIterationTableIndex = 6,
    WdfChildListRetrieveNextDeviceTableIndex = 7,
    WdfChildListEndIterationTableIndex = 8,
    WdfChildListAddOrUpdateChildDescriptionAsPresentTableIndex = 9,
    WdfChildListUpdateChildDescriptionAsMissingTableIndex = 10,
    WdfChildListUpdateAllChildDescriptionsAsPresentTableIndex = 11,
    WdfChildListRequestChildEjectTableIndex = 12,
    WdfCollectionCreateTableIndex = 13,
    WdfCollectionGetCountTableIndex = 14,
    WdfCollectionAddTableIndex = 15,
    WdfCollectionRemoveTableIndex = 16,
    WdfCollectionRemoveItemTableIndex = 17,
    WdfCollectionGetItemTableIndex = 18,
    WdfCollectionGetFirstItemTableIndex = 19,
    WdfCollectionGetLastItemTableIndex = 20,
    WdfCommonBufferCreateTableIndex = 21,
    WdfCommonBufferGetAlignedVirtualAddressTableIndex = 22,
    WdfCommonBufferGetAlignedLogicalAddressTableIndex = 23,
    WdfCommonBufferGetLengthTableIndex = 24,
    WdfControlDeviceInitAllocateTableIndex = 25,
    WdfControlDeviceInitSetShutdownNotificationTableIndex = 26,
    WdfControlFinishInitializingTableIndex = 27,
    WdfDeviceGetDeviceStateTableIndex = 28,
    WdfDeviceSetDeviceStateTableIndex = 29,
    WdfWdmDeviceGetWdfDeviceHandleTableIndex = 30,
    WdfDeviceWdmGetDeviceObjectTableIndex = 31,
    WdfDeviceWdmGetAttachedDeviceTableIndex = 32,
    WdfDeviceWdmGetPhysicalDeviceTableIndex = 33,
    WdfDeviceWdmDispatchPreprocessedIrpTableIndex = 34,
    WdfDeviceAddDependentUsageDeviceObjectTableIndex = 35,
    WdfDeviceAddRemovalRelationsPhysicalDeviceTableIndex = 36,
    WdfDeviceRemoveRemovalRelationsPhysicalDeviceTableIndex = 37,
    WdfDeviceClearRemovalRelationsDevicesTableIndex = 38,
    WdfDeviceGetDriverTableIndex = 39,
    WdfDeviceRetrieveDeviceNameTableIndex = 40,
    WdfDeviceAssignMofResourceNameTableIndex = 41,
    WdfDeviceGetIoTargetTableIndex = 42,
    WdfDeviceGetDevicePnpStateTableIndex = 43,
    WdfDeviceGetDevicePowerStateTableIndex = 44,
    WdfDeviceGetDevicePowerPolicyStateTableIndex = 45,
    WdfDeviceAssignS0IdleSettingsTableIndex = 46,
    WdfDeviceAssignSxWakeSettingsTableIndex = 47,
    WdfDeviceOpenRegistryKeyTableIndex = 48,
    WdfDeviceSetSpecialFileSupportTableIndex = 49,
    WdfDeviceSetCharacteristicsTableIndex = 50,
    WdfDeviceGetCharacteristicsTableIndex = 51,
    WdfDeviceGetAlignmentRequirementTableIndex = 52,
    WdfDeviceSetAlignmentRequirementTableIndex = 53,
    WdfDeviceInitFreeTableIndex = 54,
    WdfDeviceInitSetPnpPowerEventCallbacksTableIndex = 55,
    WdfDeviceInitSetPowerPolicyEventCallbacksTableIndex = 56,
    WdfDeviceInitSetPowerPolicyOwnershipTableIndex = 57,
    WdfDeviceInitRegisterPnpStateChangeCallbackTableIndex = 58,
    WdfDeviceInitRegisterPowerStateChangeCallbackTableIndex = 59,
    WdfDeviceInitRegisterPowerPolicyStateChangeCallbackTableIndex = 60,
    WdfDeviceInitSetIoTypeTableIndex = 61,
    WdfDeviceInitSetExclusiveTableIndex = 62,
    WdfDeviceInitSetPowerNotPageableTableIndex = 63,
    WdfDeviceInitSetPowerPageableTableIndex = 64,
    WdfDeviceInitSetPowerInrushTableIndex = 65,
    WdfDeviceInitSetDeviceTypeTableIndex = 66,
    WdfDeviceInitAssignNameTableIndex = 67,
    WdfDeviceInitAssignSDDLStringTableIndex = 68,
    WdfDeviceInitSetDeviceClassTableIndex = 69,
    WdfDeviceInitSetCharacteristicsTableIndex = 70,
    WdfDeviceInitSetFileObjectConfigTableIndex = 71,
    WdfDeviceInitSetRequestAttributesTableIndex = 72,
    WdfDeviceInitAssignWdmIrpPreprocessCallbackTableIndex = 73,
    WdfDeviceInitSetIoInCallerContextCallbackTableIndex = 74,
    WdfDeviceCreateTableIndex = 75,
    WdfDeviceSetStaticStopRemoveTableIndex = 76,
    WdfDeviceCreateDeviceInterfaceTableIndex = 77,
    WdfDeviceSetDeviceInterfaceStateTableIndex = 78,
    WdfDeviceRetrieveDeviceInterfaceStringTableIndex = 79,
    WdfDeviceCreateSymbolicLinkTableIndex = 80,
    WdfDeviceQueryPropertyTableIndex = 81,
    WdfDeviceAllocAndQueryPropertyTableIndex = 82,
    WdfDeviceSetPnpCapabilitiesTableIndex = 83,
    WdfDeviceSetPowerCapabilitiesTableIndex = 84,
    WdfDeviceSetBusInformationForChildrenTableIndex = 85,
    WdfDeviceIndicateWakeStatusTableIndex = 86,
    WdfDeviceSetFailedTableIndex = 87,
    WdfDeviceStopIdleTableIndex = 88,
    WdfDeviceResumeIdleTableIndex = 89,
    WdfDeviceGetFileObjectTableIndex = 90,
    WdfDeviceEnqueueRequestTableIndex = 91,
    WdfDeviceGetDefaultQueueTableIndex = 92,
    WdfDeviceConfigureRequestDispatchingTableIndex = 93,
    WdfDmaEnablerCreateTableIndex = 94,
    WdfDmaEnablerGetMaximumLengthTableIndex = 95,
    WdfDmaEnablerGetMaximumScatterGatherElementsTableIndex = 96,
    WdfDmaEnablerSetMaximumScatterGatherElementsTableIndex = 97,
    WdfDmaTransactionCreateTableIndex = 98,
    WdfDmaTransactionInitializeTableIndex = 99,
    WdfDmaTransactionInitializeUsingRequestTableIndex = 100,
    WdfDmaTransactionExecuteTableIndex = 101,
    WdfDmaTransactionReleaseTableIndex = 102,
    WdfDmaTransactionDmaCompletedTableIndex = 103,
    WdfDmaTransactionDmaCompletedWithLengthTableIndex = 104,
    WdfDmaTransactionDmaCompletedFinalTableIndex = 105,
    WdfDmaTransactionGetBytesTransferredTableIndex = 106,
    WdfDmaTransactionSetMaximumLengthTableIndex = 107,
    WdfDmaTransactionGetRequestTableIndex = 108,
    WdfDmaTransactionGetCurrentDmaTransferLengthTableIndex = 109,
    WdfDmaTransactionGetDeviceTableIndex = 110,
    WdfDpcCreateTableIndex = 111,
    WdfDpcEnqueueTableIndex = 112,
    WdfDpcCancelTableIndex = 113,
    WdfDpcGetParentObjectTableIndex = 114,
    WdfDpcWdmGetDpcTableIndex = 115,
    WdfDriverCreateTableIndex = 116,
    WdfDriverGetRegistryPathTableIndex = 117,
    WdfDriverWdmGetDriverObjectTableIndex = 118,
    WdfDriverOpenParametersRegistryKeyTableIndex = 119,
    WdfWdmDriverGetWdfDriverHandleTableIndex = 120,
    WdfDriverRegisterTraceInfoTableIndex = 121,
    WdfDriverRetrieveVersionStringTableIndex = 122,
    WdfDriverIsVersionAvailableTableIndex = 123,
    WdfFdoInitWdmGetPhysicalDeviceTableIndex = 124,
    WdfFdoInitOpenRegistryKeyTableIndex = 125,
    WdfFdoInitQueryPropertyTableIndex = 126,
    WdfFdoInitAllocAndQueryPropertyTableIndex = 127,
    WdfFdoInitSetEventCallbacksTableIndex = 128,
    WdfFdoInitSetFilterTableIndex = 129,
    WdfFdoInitSetDefaultChildListConfigTableIndex = 130,
    WdfFdoQueryForInterfaceTableIndex = 131,
    WdfFdoGetDefaultChildListTableIndex = 132,
    WdfFdoAddStaticChildTableIndex = 133,
    WdfFdoLockStaticChildListForIterationTableIndex = 134,
    WdfFdoRetrieveNextStaticChildTableIndex = 135,
    WdfFdoUnlockStaticChildListFromIterationTableIndex = 136,
    WdfFileObjectGetFileNameTableIndex = 137,
    WdfFileObjectGetFlagsTableIndex = 138,
    WdfFileObjectGetDeviceTableIndex = 139,
    WdfFileObjectWdmGetFileObjectTableIndex = 140,
    WdfInterruptCreateTableIndex = 141,
    WdfInterruptQueueDpcForIsrTableIndex = 142,
    WdfInterruptSynchronizeTableIndex = 143,
    WdfInterruptAcquireLockTableIndex = 144,
    WdfInterruptReleaseLockTableIndex = 145,
    WdfInterruptEnableTableIndex = 146,
    WdfInterruptDisableTableIndex = 147,
    WdfInterruptWdmGetInterruptTableIndex = 148,
    WdfInterruptGetInfoTableIndex = 149,
    WdfInterruptSetPolicyTableIndex = 150,
    WdfInterruptGetDeviceTableIndex = 151,
    WdfIoQueueCreateTableIndex = 152,
    WdfIoQueueGetStateTableIndex = 153,
    WdfIoQueueStartTableIndex = 154,
    WdfIoQueueStopTableIndex = 155,
    WdfIoQueueStopSynchronouslyTableIndex = 156,
    WdfIoQueueGetDeviceTableIndex = 157,
    WdfIoQueueRetrieveNextRequestTableIndex = 158,
    WdfIoQueueRetrieveRequestByFileObjectTableIndex = 159,
    WdfIoQueueFindRequestTableIndex = 160,
    WdfIoQueueRetrieveFoundRequestTableIndex = 161,
    WdfIoQueueDrainSynchronouslyTableIndex = 162,
    WdfIoQueueDrainTableIndex = 163,
    WdfIoQueuePurgeSynchronouslyTableIndex = 164,
    WdfIoQueuePurgeTableIndex = 165,
    WdfIoQueueReadyNotifyTableIndex = 166,
    WdfIoTargetCreateTableIndex = 167,
    WdfIoTargetOpenTableIndex = 168,
    WdfIoTargetCloseForQueryRemoveTableIndex = 169,
    WdfIoTargetCloseTableIndex = 170,
    WdfIoTargetStartTableIndex = 171,
    WdfIoTargetStopTableIndex = 172,
    WdfIoTargetGetStateTableIndex = 173,
    WdfIoTargetGetDeviceTableIndex = 174,
    WdfIoTargetQueryTargetPropertyTableIndex = 175,
    WdfIoTargetAllocAndQueryTargetPropertyTableIndex = 176,
    WdfIoTargetQueryForInterfaceTableIndex = 177,
    WdfIoTargetWdmGetTargetDeviceObjectTableIndex = 178,
    WdfIoTargetWdmGetTargetPhysicalDeviceTableIndex = 179,
    WdfIoTargetWdmGetTargetFileObjectTableIndex = 180,
    WdfIoTargetWdmGetTargetFileHandleTableIndex = 181,
    WdfIoTargetSendReadSynchronouslyTableIndex = 182,
    WdfIoTargetFormatRequestForReadTableIndex = 183,
    WdfIoTargetSendWriteSynchronouslyTableIndex = 184,
    WdfIoTargetFormatRequestForWriteTableIndex = 185,
    WdfIoTargetSendIoctlSynchronouslyTableIndex = 186,
    WdfIoTargetFormatRequestForIoctlTableIndex = 187,
    WdfIoTargetSendInternalIoctlSynchronouslyTableIndex = 188,
    WdfIoTargetFormatRequestForInternalIoctlTableIndex = 189,
    WdfIoTargetSendInternalIoctlOthersSynchronouslyTableIndex = 190,
    WdfIoTargetFormatRequestForInternalIoctlOthersTableIndex = 191,
    WdfMemoryCreateTableIndex = 192,
    WdfMemoryCreatePreallocatedTableIndex = 193,
    WdfMemoryGetBufferTableIndex = 194,
    WdfMemoryAssignBufferTableIndex = 195,
    WdfMemoryCopyToBufferTableIndex = 196,
    WdfMemoryCopyFromBufferTableIndex = 197,
    WdfLookasideListCreateTableIndex = 198,
    WdfMemoryCreateFromLookasideTableIndex = 199,
    WdfDeviceMiniportCreateTableIndex = 200,
    WdfDriverMiniportUnloadTableIndex = 201,
    WdfObjectGetTypedContextWorkerTableIndex = 202,
    WdfObjectAllocateContextTableIndex = 203,
    WdfObjectContextGetObjectTableIndex = 204,
    WdfObjectReferenceActualTableIndex = 205,
    WdfObjectDereferenceActualTableIndex = 206,
    WdfObjectCreateTableIndex = 207,
    WdfObjectDeleteTableIndex = 208,
    WdfObjectQueryTableIndex = 209,
    WdfPdoInitAllocateTableIndex = 210,
    WdfPdoInitSetEventCallbacksTableIndex = 211,
    WdfPdoInitAssignDeviceIDTableIndex = 212,
    WdfPdoInitAssignInstanceIDTableIndex = 213,
    WdfPdoInitAddHardwareIDTableIndex = 214,
    WdfPdoInitAddCompatibleIDTableIndex = 215,
    WdfPdoInitAddDeviceTextTableIndex = 216,
    WdfPdoInitSetDefaultLocaleTableIndex = 217,
    WdfPdoInitAssignRawDeviceTableIndex = 218,
    WdfPdoMarkMissingTableIndex = 219,
    WdfPdoRequestEjectTableIndex = 220,
    WdfPdoGetParentTableIndex = 221,
    WdfPdoRetrieveIdentificationDescriptionTableIndex = 222,
    WdfPdoRetrieveAddressDescriptionTableIndex = 223,
    WdfPdoUpdateAddressDescriptionTableIndex = 224,
    WdfPdoAddEjectionRelationsPhysicalDeviceTableIndex = 225,
    WdfPdoRemoveEjectionRelationsPhysicalDeviceTableIndex = 226,
    WdfPdoClearEjectionRelationsDevicesTableIndex = 227,
    WdfDeviceAddQueryInterfaceTableIndex = 228,
    WdfRegistryOpenKeyTableIndex = 229,
    WdfRegistryCreateKeyTableIndex = 230,
    WdfRegistryCloseTableIndex = 231,
    WdfRegistryWdmGetHandleTableIndex = 232,
    WdfRegistryRemoveKeyTableIndex = 233,
    WdfRegistryRemoveValueTableIndex = 234,
    WdfRegistryQueryValueTableIndex = 235,
    WdfRegistryQueryMemoryTableIndex = 236,
    WdfRegistryQueryMultiStringTableIndex = 237,
    WdfRegistryQueryUnicodeStringTableIndex = 238,
    WdfRegistryQueryStringTableIndex = 239,
    WdfRegistryQueryULongTableIndex = 240,
    WdfRegistryAssignValueTableIndex = 241,
    WdfRegistryAssignMemoryTableIndex = 242,
    WdfRegistryAssignMultiStringTableIndex = 243,
    WdfRegistryAssignUnicodeStringTableIndex = 244,
    WdfRegistryAssignStringTableIndex = 245,
    WdfRegistryAssignULongTableIndex = 246,
    WdfRequestCreateTableIndex = 247,
    WdfRequestCreateFromIrpTableIndex = 248,
    WdfRequestReuseTableIndex = 249,
    WdfRequestChangeTargetTableIndex = 250,
    WdfRequestFormatRequestUsingCurrentTypeTableIndex = 251,
    WdfRequestWdmFormatUsingStackLocationTableIndex = 252,
    WdfRequestSendTableIndex = 253,
    WdfRequestGetStatusTableIndex = 254,
    WdfRequestMarkCancelableTableIndex = 255,
    WdfRequestUnmarkCancelableTableIndex = 256,
    WdfRequestIsCanceledTableIndex = 257,
    WdfRequestCancelSentRequestTableIndex = 258,
    WdfRequestIsFrom32BitProcessTableIndex = 259,
    WdfRequestSetCompletionRoutineTableIndex = 260,
    WdfRequestGetCompletionParamsTableIndex = 261,
    WdfRequestAllocateTimerTableIndex = 262,
    WdfRequestCompleteTableIndex = 263,
    WdfRequestCompleteWithPriorityBoostTableIndex = 264,
    WdfRequestCompleteWithInformationTableIndex = 265,
    WdfRequestGetParametersTableIndex = 266,
    WdfRequestRetrieveInputMemoryTableIndex = 267,
    WdfRequestRetrieveOutputMemoryTableIndex = 268,
    WdfRequestRetrieveInputBufferTableIndex = 269,
    WdfRequestRetrieveOutputBufferTableIndex = 270,
    WdfRequestRetrieveInputWdmMdlTableIndex = 271,
    WdfRequestRetrieveOutputWdmMdlTableIndex = 272,
    WdfRequestRetrieveUnsafeUserInputBufferTableIndex = 273,
    WdfRequestRetrieveUnsafeUserOutputBufferTableIndex = 274,
    WdfRequestSetInformationTableIndex = 275,
    WdfRequestGetInformationTableIndex = 276,
    WdfRequestGetFileObjectTableIndex = 277,
    WdfRequestProbeAndLockUserBufferForReadTableIndex = 278,
    WdfRequestProbeAndLockUserBufferForWriteTableIndex = 279,
    WdfRequestGetRequestorModeTableIndex = 280,
    WdfRequestForwardToIoQueueTableIndex = 281,
    WdfRequestGetIoQueueTableIndex = 282,
    WdfRequestRequeueTableIndex = 283,
    WdfRequestStopAcknowledgeTableIndex = 284,
    WdfRequestWdmGetIrpTableIndex = 285,
    WdfIoResourceRequirementsListSetSlotNumberTableIndex = 286,
    WdfIoResourceRequirementsListSetInterfaceTypeTableIndex = 287,
    WdfIoResourceRequirementsListAppendIoResListTableIndex = 288,
    WdfIoResourceRequirementsListInsertIoResListTableIndex = 289,
    WdfIoResourceRequirementsListGetCountTableIndex = 290,
    WdfIoResourceRequirementsListGetIoResListTableIndex = 291,
    WdfIoResourceRequirementsListRemoveTableIndex = 292,
    WdfIoResourceRequirementsListRemoveByIoResListTableIndex = 293,
    WdfIoResourceListCreateTableIndex = 294,
    WdfIoResourceListAppendDescriptorTableIndex = 295,
    WdfIoResourceListInsertDescriptorTableIndex = 296,
    WdfIoResourceListUpdateDescriptorTableIndex = 297,
    WdfIoResourceListGetCountTableIndex = 298,
    WdfIoResourceListGetDescriptorTableIndex = 299,
    WdfIoResourceListRemoveTableIndex = 300,
    WdfIoResourceListRemoveByDescriptorTableIndex = 301,
    WdfCmResourceListAppendDescriptorTableIndex = 302,
    WdfCmResourceListInsertDescriptorTableIndex = 303,
    WdfCmResourceListGetCountTableIndex = 304,
    WdfCmResourceListGetDescriptorTableIndex = 305,
    WdfCmResourceListRemoveTableIndex = 306,
    WdfCmResourceListRemoveByDescriptorTableIndex = 307,
    WdfStringCreateTableIndex = 308,
    WdfStringGetUnicodeStringTableIndex = 309,
    WdfObjectAcquireLockTableIndex = 310,
    WdfObjectReleaseLockTableIndex = 311,
    WdfWaitLockCreateTableIndex = 312,
    WdfWaitLockAcquireTableIndex = 313,
    WdfWaitLockReleaseTableIndex = 314,
    WdfSpinLockCreateTableIndex = 315,
    WdfSpinLockAcquireTableIndex = 316,
    WdfSpinLockReleaseTableIndex = 317,
    WdfTimerCreateTableIndex = 318,
    WdfTimerStartTableIndex = 319,
    WdfTimerStopTableIndex = 320,
    WdfTimerGetParentObjectTableIndex = 321,
    WdfUsbTargetDeviceCreateTableIndex = 322,
    WdfUsbTargetDeviceRetrieveInformationTableIndex = 323,
    WdfUsbTargetDeviceGetDeviceDescriptorTableIndex = 324,
    WdfUsbTargetDeviceRetrieveConfigDescriptorTableIndex = 325,
    WdfUsbTargetDeviceQueryStringTableIndex = 326,
    WdfUsbTargetDeviceAllocAndQueryStringTableIndex = 327,
    WdfUsbTargetDeviceFormatRequestForStringTableIndex = 328,
    WdfUsbTargetDeviceGetNumInterfacesTableIndex = 329,
    WdfUsbTargetDeviceSelectConfigTableIndex = 330,
    WdfUsbTargetDeviceWdmGetConfigurationHandleTableIndex = 331,
    WdfUsbTargetDeviceRetrieveCurrentFrameNumberTableIndex = 332,
    WdfUsbTargetDeviceSendControlTransferSynchronouslyTableIndex = 333,
    WdfUsbTargetDeviceFormatRequestForControlTransferTableIndex = 334,
    WdfUsbTargetDeviceIsConnectedSynchronousTableIndex = 335,
    WdfUsbTargetDeviceResetPortSynchronouslyTableIndex = 336,
    WdfUsbTargetDeviceCyclePortSynchronouslyTableIndex = 337,
    WdfUsbTargetDeviceFormatRequestForCyclePortTableIndex = 338,
    WdfUsbTargetDeviceSendUrbSynchronouslyTableIndex = 339,
    WdfUsbTargetDeviceFormatRequestForUrbTableIndex = 340,
    WdfUsbTargetPipeGetInformationTableIndex = 341,
    WdfUsbTargetPipeIsInEndpointTableIndex = 342,
    WdfUsbTargetPipeIsOutEndpointTableIndex = 343,
    WdfUsbTargetPipeGetTypeTableIndex = 344,
    WdfUsbTargetPipeSetNoMaximumPacketSizeCheckTableIndex = 345,
    WdfUsbTargetPipeWriteSynchronouslyTableIndex = 346,
    WdfUsbTargetPipeFormatRequestForWriteTableIndex = 347,
    WdfUsbTargetPipeReadSynchronouslyTableIndex = 348,
    WdfUsbTargetPipeFormatRequestForReadTableIndex = 349,
    WdfUsbTargetPipeConfigContinuousReaderTableIndex = 350,
    WdfUsbTargetPipeAbortSynchronouslyTableIndex = 351,
    WdfUsbTargetPipeFormatRequestForAbortTableIndex = 352,
    WdfUsbTargetPipeResetSynchronouslyTableIndex = 353,
    WdfUsbTargetPipeFormatRequestForResetTableIndex = 354,
    WdfUsbTargetPipeSendUrbSynchronouslyTableIndex = 355,
    WdfUsbTargetPipeFormatRequestForUrbTableIndex = 356,
    WdfUsbInterfaceGetInterfaceNumberTableIndex = 357,
    WdfUsbInterfaceGetNumEndpointsTableIndex = 358,
    WdfUsbInterfaceGetDescriptorTableIndex = 359,
    WdfUsbInterfaceSelectSettingTableIndex = 360,
    WdfUsbInterfaceGetEndpointInformationTableIndex = 361,
    WdfUsbTargetDeviceGetInterfaceTableIndex = 362,
    WdfUsbInterfaceGetConfiguredSettingIndexTableIndex = 363,
    WdfUsbInterfaceGetNumConfiguredPipesTableIndex = 364,
    WdfUsbInterfaceGetConfiguredPipeTableIndex = 365,
    WdfUsbTargetPipeWdmGetPipeHandleTableIndex = 366,
    WdfVerifierDbgBreakPointTableIndex = 367,
    WdfVerifierKeBugCheckTableIndex = 368,
    WdfWmiProviderCreateTableIndex = 369,
    WdfWmiProviderGetDeviceTableIndex = 370,
    WdfWmiProviderIsEnabledTableIndex = 371,
    WdfWmiProviderGetTracingHandleTableIndex = 372,
    WdfWmiInstanceCreateTableIndex = 373,
    WdfWmiInstanceRegisterTableIndex = 374,
    WdfWmiInstanceDeregisterTableIndex = 375,
    WdfWmiInstanceGetDeviceTableIndex = 376,
    WdfWmiInstanceGetProviderTableIndex = 377,
    WdfWmiInstanceFireEventTableIndex = 378,
    WdfWorkItemCreateTableIndex = 379,
    WdfWorkItemEnqueueTableIndex = 380,
    WdfWorkItemGetParentObjectTableIndex = 381,
    WdfWorkItemFlushTableIndex = 382,
    WdfCommonBufferCreateWithConfigTableIndex = 383,
    WdfDmaEnablerGetFragmentLengthTableIndex = 384,
    WdfDmaEnablerWdmGetDmaAdapterTableIndex = 385,
    WdfUsbInterfaceGetNumSettingsTableIndex = 386,
    WdfDeviceRemoveDependentUsageDeviceObjectTableIndex = 387,
    WdfDeviceGetSystemPowerActionTableIndex = 388,
    WdfInterruptSetExtendedPolicyTableIndex = 389,
    WdfIoQueueAssignForwardProgressPolicyTableIndex = 390,
    WdfPdoInitAssignContainerIDTableIndex = 391,
    WdfPdoInitAllowForwardingRequestToParentTableIndex = 392,
    WdfRequestMarkCancelableExTableIndex = 393,
    WdfRequestIsReservedTableIndex = 394,
    WdfRequestForwardToParentDeviceIoQueueTableIndex = 395,
    WdfFunctionTableNumEntries = 396,
} WDFFUNCENUM;

#line 421 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdffuncenum.h"


#line 54 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfstatus.h"





























































































































































































































































#line 255 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfstatus.h"

#line 55 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfassert.h"



































__declspec(dllimport)
void
__stdcall
RtlAssert(
     PVOID FailedAssertion,
     PVOID FileName,
     ULONG LineNumber,
     PSTR Message
    );


































#line 80 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfassert.h"


#line 83 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfassert.h"

#line 56 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfverifier.h"



































typedef

void
(*PFN_WDFVERIFIERDBGBREAKPOINT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals
    );

void
__forceinline
WdfVerifierDbgBreakPoint(
    )
{
    ((PFN_WDFVERIFIERDBGBREAKPOINT) WdfFunctions[WdfVerifierDbgBreakPointTableIndex])(WdfDriverGlobals);
}




typedef

void
(*PFN_WDFVERIFIERKEBUGCHECK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    ULONG BugCheckCode,
    
    ULONG_PTR BugCheckParameter1,
    
    ULONG_PTR BugCheckParameter2,
    
    ULONG_PTR BugCheckParameter3,
    
    ULONG_PTR BugCheckParameter4
    );

void
__forceinline
WdfVerifierKeBugCheck(
    
    ULONG BugCheckCode,
    
    ULONG_PTR BugCheckParameter1,
    
    ULONG_PTR BugCheckParameter2,
    
    ULONG_PTR BugCheckParameter3,
    
    ULONG_PTR BugCheckParameter4
    )
{
    ((PFN_WDFVERIFIERKEBUGCHECK) WdfFunctions[WdfVerifierKeBugCheckTableIndex])(WdfDriverGlobals, BugCheckCode, BugCheckParameter1, BugCheckParameter2, BugCheckParameter3, BugCheckParameter4);
}



#line 94 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfverifier.h"


#line 97 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfverifier.h"

#line 57 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfpool.h"


































#line 36 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfpool.h"


#line 39 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfpool.h"

#line 58 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"


#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfobject.h"






























typedef enum _WDF_EXECUTION_LEVEL {
    WdfExecutionLevelInvalid = 0x00,
    WdfExecutionLevelInheritFromParent,
    WdfExecutionLevelPassive,
    WdfExecutionLevelDispatch,
} WDF_EXECUTION_LEVEL;




typedef enum _WDF_SYNCHRONIZATION_SCOPE {
    WdfSynchronizationScopeInvalid = 0x00,
    WdfSynchronizationScopeInheritFromParent,
    WdfSynchronizationScopeDevice,
    WdfSynchronizationScopeQueue,
    WdfSynchronizationScopeNone,
} WDF_SYNCHRONIZATION_SCOPE;



typedef



void
EVT_WDF_OBJECT_CONTEXT_CLEANUP(
    
    WDFOBJECT Object
    );

typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP *PFN_WDF_OBJECT_CONTEXT_CLEANUP;

typedef



void
EVT_WDF_OBJECT_CONTEXT_DESTROY(
    
    WDFOBJECT Object
    );

typedef EVT_WDF_OBJECT_CONTEXT_DESTROY *PFN_WDF_OBJECT_CONTEXT_DESTROY;


typedef const struct _WDF_OBJECT_CONTEXT_TYPE_INFO *PCWDF_OBJECT_CONTEXT_TYPE_INFO;

typedef struct _WDF_OBJECT_ATTRIBUTES {
    
    
    
    ULONG Size;

    
    
    
    PFN_WDF_OBJECT_CONTEXT_CLEANUP EvtCleanupCallback;

    
    
    
    
    PFN_WDF_OBJECT_CONTEXT_DESTROY EvtDestroyCallback;

    
    
    
    WDF_EXECUTION_LEVEL ExecutionLevel;

    
    
    
    WDF_SYNCHRONIZATION_SCOPE SynchronizationScope;

    
    
    
    WDFOBJECT ParentObject;

    
    
    
    
    size_t ContextSizeOverride;

    
    
    
    PCWDF_OBJECT_CONTEXT_TYPE_INFO ContextTypeInfo;

} WDF_OBJECT_ATTRIBUTES, *PWDF_OBJECT_ATTRIBUTES;

void
__forceinline
WDF_OBJECT_ATTRIBUTES_INIT(
     PWDF_OBJECT_ATTRIBUTES Attributes
    )
{
    memset((Attributes),0,(sizeof(WDF_OBJECT_ATTRIBUTES)));
    Attributes->Size = sizeof(WDF_OBJECT_ATTRIBUTES);
    Attributes->ExecutionLevel = WdfExecutionLevelInheritFromParent;
    Attributes->SynchronizationScope = WdfSynchronizationScopeInheritFromParent;
}


















typedef
PCWDF_OBJECT_CONTEXT_TYPE_INFO
(__cdecl *PFN_GET_UNIQUE_CONTEXT_TYPE)(
    void
    );




typedef struct _WDF_OBJECT_CONTEXT_TYPE_INFO {
    
    
    
    ULONG Size;

    
    
    
    PCHAR ContextName;

    
    
    
    
    
    size_t ContextSize;

    
    
    
    
    
    PCWDF_OBJECT_CONTEXT_TYPE_INFO UniqueType;

    
    
    
    
    
    
    PFN_GET_UNIQUE_CONTEXT_TYPE EvtDriverGetUniqueContextType;

} WDF_OBJECT_CONTEXT_TYPE_INFO, *PWDF_OBJECT_CONTEXT_TYPE_INFO;






























































































#line 290 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfobject.h"

#pragma section(".kmdftypeinit$b", read, write)
#pragma section(".data")






























































































typedef

PVOID
(_fastcall *PFN_WDFOBJECTGETTYPEDCONTEXTWORKER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFOBJECT Handle,
    
    PCWDF_OBJECT_CONTEXT_TYPE_INFO TypeInfo
    );

PVOID
__forceinline
WdfObjectGetTypedContextWorker(
    
    WDFOBJECT Handle,
    
    PCWDF_OBJECT_CONTEXT_TYPE_INFO TypeInfo
    )
{
    return ((PFN_WDFOBJECTGETTYPEDCONTEXTWORKER) WdfFunctions[WdfObjectGetTypedContextWorkerTableIndex])(WdfDriverGlobals, Handle, TypeInfo);
}




typedef

NTSTATUS
(*PFN_WDFOBJECTALLOCATECONTEXT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFOBJECT Handle,
    
    PWDF_OBJECT_ATTRIBUTES ContextAttributes,
    
    PVOID* Context
    );

NTSTATUS
__forceinline
WdfObjectAllocateContext(
    
    WDFOBJECT Handle,
    
    PWDF_OBJECT_ATTRIBUTES ContextAttributes,
    
    PVOID* Context
    )
{
    return ((PFN_WDFOBJECTALLOCATECONTEXT) WdfFunctions[WdfObjectAllocateContextTableIndex])(WdfDriverGlobals, Handle, ContextAttributes, Context);
}




typedef

WDFOBJECT
(_fastcall *PFN_WDFOBJECTCONTEXTGETOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PVOID ContextPointer
    );

WDFOBJECT
__forceinline
WdfObjectContextGetObject(
    
    PVOID ContextPointer
    )
{
    return ((PFN_WDFOBJECTCONTEXTGETOBJECT) WdfFunctions[WdfObjectContextGetObjectTableIndex])(WdfDriverGlobals, ContextPointer);
}




typedef

void
(*PFN_WDFOBJECTREFERENCEACTUAL)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFOBJECT Handle,
    
    PVOID Tag,
    
    LONG Line,
     
    PCHAR File
    );

void
__forceinline
WdfObjectReferenceActual(
    
    WDFOBJECT Handle,
    
    PVOID Tag,
    
    LONG Line,
     
    PCHAR File
    )
{
    ((PFN_WDFOBJECTREFERENCEACTUAL) WdfFunctions[WdfObjectReferenceActualTableIndex])(WdfDriverGlobals, Handle, Tag, Line, File);
}




typedef

void
(*PFN_WDFOBJECTDEREFERENCEACTUAL)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFOBJECT Handle,
    
    PVOID Tag,
    
    LONG Line,
     
    PCHAR File
    );

void
__forceinline
WdfObjectDereferenceActual(
    
    WDFOBJECT Handle,
    
    PVOID Tag,
    
    LONG Line,
     
    PCHAR File
    )
{
    ((PFN_WDFOBJECTDEREFERENCEACTUAL) WdfFunctions[WdfObjectDereferenceActualTableIndex])(WdfDriverGlobals, Handle, Tag, Line, File);
}




typedef



NTSTATUS
(*PFN_WDFOBJECTCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFOBJECT* Object
    );



NTSTATUS
__forceinline
WdfObjectCreate(
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFOBJECT* Object
    )
{
    return ((PFN_WDFOBJECTCREATE) WdfFunctions[WdfObjectCreateTableIndex])(WdfDriverGlobals, Attributes, Object);
}




typedef


void
(*PFN_WDFOBJECTDELETE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFOBJECT Object
    );


void
__forceinline
WdfObjectDelete(
    
    WDFOBJECT Object
    )
{
    ((PFN_WDFOBJECTDELETE) WdfFunctions[WdfObjectDeleteTableIndex])(WdfDriverGlobals, Object);
}




typedef



NTSTATUS
(*PFN_WDFOBJECTQUERY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFOBJECT Object,
    
    const GUID* Guid,
    
    ULONG QueryBufferLength,
    
    PVOID QueryBuffer
    );



NTSTATUS
__forceinline
WdfObjectQuery(
    
    WDFOBJECT Object,
    
    const GUID* Guid,
    
    ULONG QueryBufferLength,
    
    PVOID QueryBuffer
    )
{
    return ((PFN_WDFOBJECTQUERY) WdfFunctions[WdfObjectQueryTableIndex])(WdfDriverGlobals, Object, Guid, QueryBufferLength, QueryBuffer);
}














































#line 676 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfobject.h"


#line 679 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfobject.h"

#line 61 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"


#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfsync.h"




































typedef


void
(*PFN_WDFOBJECTACQUIRELOCK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    
    
    WDFOBJECT Object
    );


void
__forceinline
WdfObjectAcquireLock(
    
    
    
    WDFOBJECT Object
    )
{
    ((PFN_WDFOBJECTACQUIRELOCK) WdfFunctions[WdfObjectAcquireLockTableIndex])(WdfDriverGlobals, Object);
}




typedef


void
(*PFN_WDFOBJECTRELEASELOCK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    
    
    WDFOBJECT Object
    );


void
__forceinline
WdfObjectReleaseLock(
    
    
    
    WDFOBJECT Object
    )
{
    ((PFN_WDFOBJECTRELEASELOCK) WdfFunctions[WdfObjectReleaseLockTableIndex])(WdfDriverGlobals, Object);
}




typedef



NTSTATUS
(*PFN_WDFWAITLOCKCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES LockAttributes,
    
    WDFWAITLOCK* Lock
    );



NTSTATUS
__forceinline
WdfWaitLockCreate(
    
    PWDF_OBJECT_ATTRIBUTES LockAttributes,
    
    WDFWAITLOCK* Lock
    )
{
    return ((PFN_WDFWAITLOCKCREATE) WdfFunctions[WdfWaitLockCreateTableIndex])(WdfDriverGlobals, LockAttributes, Lock);
}




typedef





NTSTATUS
(*PFN_WDFWAITLOCKACQUIRE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWAITLOCK Lock,
    
    PLONGLONG Timeout
    );





NTSTATUS
__forceinline
WdfWaitLockAcquire(
    
    WDFWAITLOCK Lock,
    
    PLONGLONG Timeout
    )
{
    return ((PFN_WDFWAITLOCKACQUIRE) WdfFunctions[WdfWaitLockAcquireTableIndex])(WdfDriverGlobals, Lock, Timeout);
}




typedef


void
(*PFN_WDFWAITLOCKRELEASE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWAITLOCK Lock
    );


void
__forceinline
WdfWaitLockRelease(
    
    WDFWAITLOCK Lock
    )
{
    ((PFN_WDFWAITLOCKRELEASE) WdfFunctions[WdfWaitLockReleaseTableIndex])(WdfDriverGlobals, Lock);
}




typedef



NTSTATUS
(*PFN_WDFSPINLOCKCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES SpinLockAttributes,
    
    WDFSPINLOCK* SpinLock
    );



NTSTATUS
__forceinline
WdfSpinLockCreate(
    
    PWDF_OBJECT_ATTRIBUTES SpinLockAttributes,
    
    WDFSPINLOCK* SpinLock
    )
{
    return ((PFN_WDFSPINLOCKCREATE) WdfFunctions[WdfSpinLockCreateTableIndex])(WdfDriverGlobals, SpinLockAttributes, SpinLock);
}




typedef



void
(*PFN_WDFSPINLOCKACQUIRE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    
    
    
    WDFSPINLOCK SpinLock
    );



void
__forceinline
WdfSpinLockAcquire(
    
    
    
    
    WDFSPINLOCK SpinLock
    )
{
    ((PFN_WDFSPINLOCKACQUIRE) WdfFunctions[WdfSpinLockAcquireTableIndex])(WdfDriverGlobals, SpinLock);
}




typedef



void
(*PFN_WDFSPINLOCKRELEASE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    
    
    
    WDFSPINLOCK SpinLock
    );



void
__forceinline
WdfSpinLockRelease(
    
    
    
    
    WDFSPINLOCK SpinLock
    )
{
    ((PFN_WDFSPINLOCKRELEASE) WdfFunctions[WdfSpinLockReleaseTableIndex])(WdfDriverGlobals, SpinLock);
}



#line 283 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfsync.h"


#line 286 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfsync.h"

#line 64 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"

#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcore.h"







































LONGLONG
__forceinline
WDF_REL_TIMEOUT_IN_SEC(
     ULONGLONG Time
    )
{
    return Time * -1 * ((LONGLONG) 1 * 10 * 1000 * 1000);
}

LONGLONG
__forceinline
WDF_ABS_TIMEOUT_IN_SEC(
     ULONGLONG Time
    )
{
    return Time *  1 * ((LONGLONG) 1 * 10 * 1000 * 1000);
}

LONGLONG
__forceinline
WDF_REL_TIMEOUT_IN_MS(
     ULONGLONG Time
    )
{
    return Time * -1 * ((LONGLONG) 1 * 10 * 1000);
}

LONGLONG
__forceinline
WDF_ABS_TIMEOUT_IN_MS(
     ULONGLONG Time
    )
{
    return Time *  1 * ((LONGLONG) 1 * 10 * 1000);
}

LONGLONG
__forceinline
WDF_REL_TIMEOUT_IN_US(
     ULONGLONG Time
    )
{
    return Time * -1 * ((LONGLONG) 1 * 10);
}

LONGLONG
__forceinline
WDF_ABS_TIMEOUT_IN_US(
     ULONGLONG Time
    )
{
    return Time *  1 * ((LONGLONG) 1 * 10);
}




size_t
__forceinline
WDF_ALIGN_SIZE_DOWN(
     size_t Length,
     size_t AlignTo
    )
{
    return Length & ~(AlignTo - 1);
}

size_t
__forceinline
WDF_ALIGN_SIZE_UP(
     size_t Length,
     size_t AlignTo
    )
{
    return WDF_ALIGN_SIZE_DOWN(Length + AlignTo - 1, AlignTo);
}



















#line 136 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcore.h"







#line 144 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcore.h"



#line 148 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcore.h"


#line 151 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcore.h"

#line 66 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"

#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdriver.h"





























typedef enum _WDF_DRIVER_INIT_FLAGS {
    WdfDriverInitNonPnpDriver = 0x00000001, 
    WdfDriverInitNoDispatchOverride = 0x00000002, 
    WdfVerifyOn = 0x00000004, 
    WdfVerifierOn = 0x00000008, 
} WDF_DRIVER_INIT_FLAGS;









typedef



NTSTATUS
EVT_WDF_DRIVER_DEVICE_ADD(
    
    WDFDRIVER Driver,
    
    PWDFDEVICE_INIT DeviceInit
    );

typedef EVT_WDF_DRIVER_DEVICE_ADD *PFN_WDF_DRIVER_DEVICE_ADD;

typedef



void
EVT_WDF_DRIVER_UNLOAD(
    
    WDFDRIVER Driver
    );

typedef EVT_WDF_DRIVER_UNLOAD *PFN_WDF_DRIVER_UNLOAD;





typedef



NTSTATUS
EVT_WDF_TRACE_CALLBACK(
    
    UCHAR   minorFunction,
    
    PVOID   dataPath,
    
    ULONG   bufferLength,
    
    PVOID   buffer,
    
    PVOID   context,
    
    PULONG  size
    );

typedef EVT_WDF_TRACE_CALLBACK *PFN_WDF_TRACE_CALLBACK;

typedef struct _WDF_DRIVER_CONFIG {
    
    
    
    ULONG Size;

    
    
    
    PFN_WDF_DRIVER_DEVICE_ADD EvtDriverDeviceAdd;

    PFN_WDF_DRIVER_UNLOAD    EvtDriverUnload;

    
    
    
    ULONG DriverInitFlags;

    
    
    
    
    ULONG DriverPoolTag;

} WDF_DRIVER_CONFIG, *PWDF_DRIVER_CONFIG;

void
__forceinline
WDF_DRIVER_CONFIG_INIT(
     PWDF_DRIVER_CONFIG Config,
     PFN_WDF_DRIVER_DEVICE_ADD EvtDriverDeviceAdd
    )
{
    memset((Config),0,(sizeof(WDF_DRIVER_CONFIG)));

    Config->Size = sizeof(WDF_DRIVER_CONFIG);
    Config->EvtDriverDeviceAdd = EvtDriverDeviceAdd;
}

typedef struct _WDF_DRIVER_VERSION_AVAILABLE_PARAMS {
    
    
    
    ULONG Size;

    
    
    
    ULONG MajorVersion;

    
    
    
    ULONG MinorVersion;

} WDF_DRIVER_VERSION_AVAILABLE_PARAMS, *PWDF_DRIVER_VERSION_AVAILABLE_PARAMS;

void
__forceinline
WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT(
     PWDF_DRIVER_VERSION_AVAILABLE_PARAMS Params,
     ULONG MajorVersion,
     ULONG MinorVersion
    )
{
    memset((Params),0,(sizeof(WDF_DRIVER_VERSION_AVAILABLE_PARAMS)));

    Params->Size = sizeof(WDF_DRIVER_VERSION_AVAILABLE_PARAMS);
    Params->MajorVersion = MajorVersion;
    Params->MinorVersion = MinorVersion;
}

WDFDRIVER
__forceinline
WdfGetDriver(
    void
    )
{
    return WdfDriverGlobals->Driver;
}




typedef



NTSTATUS
(*PFN_WDFDRIVERCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PDRIVER_OBJECT DriverObject,
    
    PCUNICODE_STRING RegistryPath,
    
    PWDF_OBJECT_ATTRIBUTES DriverAttributes,
    
    PWDF_DRIVER_CONFIG DriverConfig,
    
    WDFDRIVER* Driver
    );



NTSTATUS
__forceinline
WdfDriverCreate(
    
    PDRIVER_OBJECT DriverObject,
    
    PCUNICODE_STRING RegistryPath,
    
    PWDF_OBJECT_ATTRIBUTES DriverAttributes,
    
    PWDF_DRIVER_CONFIG DriverConfig,
    
    WDFDRIVER* Driver
    )
{
    return ((PFN_WDFDRIVERCREATE) WdfFunctions[WdfDriverCreateTableIndex])(WdfDriverGlobals, DriverObject, RegistryPath, DriverAttributes, DriverConfig, Driver);
}




typedef


PWSTR
(*PFN_WDFDRIVERGETREGISTRYPATH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDRIVER Driver
    );


PWSTR
__forceinline
WdfDriverGetRegistryPath(
    
    WDFDRIVER Driver
    )
{
    return ((PFN_WDFDRIVERGETREGISTRYPATH) WdfFunctions[WdfDriverGetRegistryPathTableIndex])(WdfDriverGlobals, Driver);
}




typedef


PDRIVER_OBJECT
(*PFN_WDFDRIVERWDMGETDRIVEROBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDRIVER Driver
    );


PDRIVER_OBJECT
__forceinline
WdfDriverWdmGetDriverObject(
    
    WDFDRIVER Driver
    )
{
    return ((PFN_WDFDRIVERWDMGETDRIVEROBJECT) WdfFunctions[WdfDriverWdmGetDriverObjectTableIndex])(WdfDriverGlobals, Driver);
}




typedef



NTSTATUS
(*PFN_WDFDRIVEROPENPARAMETERSREGISTRYKEY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDRIVER Driver,
    
    ACCESS_MASK DesiredAccess,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    );



NTSTATUS
__forceinline
WdfDriverOpenParametersRegistryKey(
    
    WDFDRIVER Driver,
    
    ACCESS_MASK DesiredAccess,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    )
{
    return ((PFN_WDFDRIVEROPENPARAMETERSREGISTRYKEY) WdfFunctions[WdfDriverOpenParametersRegistryKeyTableIndex])(WdfDriverGlobals, Driver, DesiredAccess, KeyAttributes, Key);
}




typedef


WDFDRIVER
(*PFN_WDFWDMDRIVERGETWDFDRIVERHANDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PDRIVER_OBJECT DriverObject
    );


WDFDRIVER
__forceinline
WdfWdmDriverGetWdfDriverHandle(
    
    PDRIVER_OBJECT DriverObject
    )
{
    return ((PFN_WDFWDMDRIVERGETWDFDRIVERHANDLE) WdfFunctions[WdfWdmDriverGetWdfDriverHandleTableIndex])(WdfDriverGlobals, DriverObject);
}




typedef



NTSTATUS
(*PFN_WDFDRIVERREGISTERTRACEINFO)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PDRIVER_OBJECT DriverObject,
    
    PFN_WDF_TRACE_CALLBACK EvtTraceCallback,
    
    PVOID ControlBlock
    );



NTSTATUS
__forceinline
WdfDriverRegisterTraceInfo(
    
    PDRIVER_OBJECT DriverObject,
    
    PFN_WDF_TRACE_CALLBACK EvtTraceCallback,
    
    PVOID ControlBlock
    )
{
    return ((PFN_WDFDRIVERREGISTERTRACEINFO) WdfFunctions[WdfDriverRegisterTraceInfoTableIndex])(WdfDriverGlobals, DriverObject, EvtTraceCallback, ControlBlock);
}




typedef



NTSTATUS
(*PFN_WDFDRIVERRETRIEVEVERSIONSTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDRIVER Driver,
    
    WDFSTRING String
    );



NTSTATUS
__forceinline
WdfDriverRetrieveVersionString(
    
    WDFDRIVER Driver,
    
    WDFSTRING String
    )
{
    return ((PFN_WDFDRIVERRETRIEVEVERSIONSTRING) WdfFunctions[WdfDriverRetrieveVersionStringTableIndex])(WdfDriverGlobals, Driver, String);
}




typedef



BOOLEAN
(*PFN_WDFDRIVERISVERSIONAVAILABLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDRIVER Driver,
    
    PWDF_DRIVER_VERSION_AVAILABLE_PARAMS VersionAvailableParams
    );



BOOLEAN
__forceinline
WdfDriverIsVersionAvailable(
    
    WDFDRIVER Driver,
    
    PWDF_DRIVER_VERSION_AVAILABLE_PARAMS VersionAvailableParams
    )
{
    return ((PFN_WDFDRIVERISVERSIONAVAILABLE) WdfFunctions[WdfDriverIsVersionAvailableTableIndex])(WdfDriverGlobals, Driver, VersionAvailableParams);
}



#line 435 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdriver.h"


#line 438 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdriver.h"

#line 68 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"


#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\WdfQueryInterface.h"































typedef



NTSTATUS
EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST(
    
    WDFDEVICE Device,
    
    LPGUID InterfaceType,
    
    PINTERFACE ExposedInterface,
    
    PVOID ExposedInterfaceSpecificData
    );

typedef EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST *PFN_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST;

typedef struct _WDF_QUERY_INTERFACE_CONFIG {
    
    
    
    ULONG Size;

    
    
    
    
    PINTERFACE Interface;

    
    
    
    const GUID * InterfaceType;

    
    
    
    
    BOOLEAN SendQueryToParentStack;

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    PFN_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST EvtDeviceProcessQueryInterfaceRequest;

    
    
    
    
    
    
    
    
    
    BOOLEAN ImportInterface;

} WDF_QUERY_INTERFACE_CONFIG, *PWDF_QUERY_INTERFACE_CONFIG;

void
__forceinline
WDF_QUERY_INTERFACE_CONFIG_INIT(
     PWDF_QUERY_INTERFACE_CONFIG InterfaceConfig,
     PINTERFACE Interface,
     const GUID* InterfaceType,
     PFN_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST EvtDeviceProcessQueryInterfaceRequest
    )
{
    memset((InterfaceConfig),0,(sizeof(WDF_QUERY_INTERFACE_CONFIG)));

    InterfaceConfig->Size = sizeof(WDF_QUERY_INTERFACE_CONFIG);
    InterfaceConfig->Interface = Interface;
    InterfaceConfig->InterfaceType = InterfaceType;
    InterfaceConfig->EvtDeviceProcessQueryInterfaceRequest =
        EvtDeviceProcessQueryInterfaceRequest;
}




typedef



NTSTATUS
(*PFN_WDFDEVICEADDQUERYINTERFACE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_QUERY_INTERFACE_CONFIG InterfaceConfig
    );



NTSTATUS
__forceinline
WdfDeviceAddQueryInterface(
    
    WDFDEVICE Device,
    
    PWDF_QUERY_INTERFACE_CONFIG InterfaceConfig
    )
{
    return ((PFN_WDFDEVICEADDQUERYINTERFACE) WdfFunctions[WdfDeviceAddQueryInterfaceTableIndex])(WdfDriverGlobals, Device, InterfaceConfig);
}














void
__forceinline
WdfDeviceInterfaceReferenceNoOp(
     PVOID Context
    )
{
    (Context);
}

void
__forceinline
WdfDeviceInterfaceDereferenceNoOp(
     PVOID Context
    )
{
    (Context);
}

#line 189 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\WdfQueryInterface.h"


#line 192 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\WdfQueryInterface.h"

#line 71 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfmemory.h"































typedef enum _WDF_MEMORY_DESCRIPTOR_TYPE {
    WdfMemoryDescriptorTypeInvalid = 0,
    WdfMemoryDescriptorTypeBuffer,
    WdfMemoryDescriptorTypeMdl,
    WdfMemoryDescriptorTypeHandle,
} WDF_MEMORY_DESCRIPTOR_TYPE;



typedef struct _WDFMEMORY_OFFSET {
    
    
    
    size_t BufferOffset;

    
    
    
    
    
    size_t BufferLength;

} WDFMEMORY_OFFSET, *PWDFMEMORY_OFFSET;

typedef struct _WDF_MEMORY_DESCRIPTOR {
    WDF_MEMORY_DESCRIPTOR_TYPE Type;

    union {
        struct {
            PVOID Buffer;

            ULONG Length;
        } BufferType;

        struct {
            PMDL Mdl;

            ULONG BufferLength;
        } MdlType;

        struct {
            WDFMEMORY Memory;
            PWDFMEMORY_OFFSET Offsets;
        } HandleType;
    } u;

} WDF_MEMORY_DESCRIPTOR, *PWDF_MEMORY_DESCRIPTOR;

void
__forceinline
WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(
     PWDF_MEMORY_DESCRIPTOR Descriptor,
      PVOID Buffer,
      ULONG BufferLength
    )
{
    memset((Descriptor),0,(sizeof(WDF_MEMORY_DESCRIPTOR)));

    Descriptor->Type = WdfMemoryDescriptorTypeBuffer;
    Descriptor->u.BufferType.Buffer = Buffer;
    Descriptor->u.BufferType.Length = BufferLength;
}

void
__forceinline
WDF_MEMORY_DESCRIPTOR_INIT_MDL(
     PWDF_MEMORY_DESCRIPTOR Descriptor,
     PMDL Mdl,
     ULONG BufferLength
    )
{
    memset((Descriptor),0,(sizeof(WDF_MEMORY_DESCRIPTOR)));

    Descriptor->Type = WdfMemoryDescriptorTypeMdl;
    Descriptor->u.MdlType.Mdl = Mdl;
    Descriptor->u.MdlType.BufferLength = BufferLength;
}

void
__forceinline
WDF_MEMORY_DESCRIPTOR_INIT_HANDLE(
     PWDF_MEMORY_DESCRIPTOR Descriptor,
     WDFMEMORY Memory,
     PWDFMEMORY_OFFSET Offsets
    )
{
    memset((Descriptor),0,(sizeof(WDF_MEMORY_DESCRIPTOR)));

    Descriptor->Type = WdfMemoryDescriptorTypeHandle;
    Descriptor->u.HandleType.Memory = Memory;
    Descriptor->u.HandleType.Offsets = Offsets;
}




typedef




NTSTATUS
(*PFN_WDFMEMORYCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    
    POOL_TYPE PoolType,
    
    ULONG PoolTag,
    
    
    size_t BufferSize,
    
    WDFMEMORY* Memory,
    
    PVOID* Buffer
    );




NTSTATUS
__forceinline
WdfMemoryCreate(
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    
    POOL_TYPE PoolType,
    
    ULONG PoolTag,
    
    
    size_t BufferSize,
    
    WDFMEMORY* Memory,
    
    PVOID* Buffer
    )
{
    return ((PFN_WDFMEMORYCREATE) WdfFunctions[WdfMemoryCreateTableIndex])(WdfDriverGlobals, Attributes, PoolType, PoolTag, BufferSize, Memory, Buffer);
}




typedef



NTSTATUS
(*PFN_WDFMEMORYCREATEPREALLOCATED)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
     
    PVOID Buffer,
    
    
    size_t BufferSize,
    
    WDFMEMORY* Memory
    );



NTSTATUS
__forceinline
WdfMemoryCreatePreallocated(
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
     
    PVOID Buffer,
    
    
    size_t BufferSize,
    
    WDFMEMORY* Memory
    )
{
    return ((PFN_WDFMEMORYCREATEPREALLOCATED) WdfFunctions[WdfMemoryCreatePreallocatedTableIndex])(WdfDriverGlobals, Attributes, Buffer, BufferSize, Memory);
}




typedef


PVOID
(*PFN_WDFMEMORYGETBUFFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFMEMORY Memory,
    
    size_t* BufferSize
    );


PVOID
__forceinline
WdfMemoryGetBuffer(
    
    WDFMEMORY Memory,
    
    size_t* BufferSize
    )
{
    return ((PFN_WDFMEMORYGETBUFFER) WdfFunctions[WdfMemoryGetBufferTableIndex])(WdfDriverGlobals, Memory, BufferSize);
}




typedef



NTSTATUS
(*PFN_WDFMEMORYASSIGNBUFFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFMEMORY Memory,
    
    PVOID Buffer,
    
    
    size_t BufferSize
    );



NTSTATUS
__forceinline
WdfMemoryAssignBuffer(
    
    WDFMEMORY Memory,
    
    PVOID Buffer,
    
    
    size_t BufferSize
    )
{
    return ((PFN_WDFMEMORYASSIGNBUFFER) WdfFunctions[WdfMemoryAssignBufferTableIndex])(WdfDriverGlobals, Memory, Buffer, BufferSize);
}




typedef



NTSTATUS
(*PFN_WDFMEMORYCOPYTOBUFFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFMEMORY SourceMemory,
    
    size_t SourceOffset,
    
    PVOID Buffer,
    
    
    size_t NumBytesToCopyTo
    );



NTSTATUS
__forceinline
WdfMemoryCopyToBuffer(
    
    WDFMEMORY SourceMemory,
    
    size_t SourceOffset,
    
    PVOID Buffer,
    
    
    size_t NumBytesToCopyTo
    )
{
    return ((PFN_WDFMEMORYCOPYTOBUFFER) WdfFunctions[WdfMemoryCopyToBufferTableIndex])(WdfDriverGlobals, SourceMemory, SourceOffset, Buffer, NumBytesToCopyTo);
}




typedef



NTSTATUS
(*PFN_WDFMEMORYCOPYFROMBUFFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFMEMORY DestinationMemory,
    
    size_t DestinationOffset,
    
    PVOID Buffer,
    
    
    size_t NumBytesToCopyFrom
    );



NTSTATUS
__forceinline
WdfMemoryCopyFromBuffer(
    
    WDFMEMORY DestinationMemory,
    
    size_t DestinationOffset,
    
    PVOID Buffer,
    
    
    size_t NumBytesToCopyFrom
    )
{
    return ((PFN_WDFMEMORYCOPYFROMBUFFER) WdfFunctions[WdfMemoryCopyFromBufferTableIndex])(WdfDriverGlobals, DestinationMemory, DestinationOffset, Buffer, NumBytesToCopyFrom);
}




typedef




NTSTATUS
(*PFN_WDFLOOKASIDELISTCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES LookasideAttributes,
    
    
    size_t BufferSize,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES MemoryAttributes,
    
    ULONG PoolTag,
    
    WDFLOOKASIDE* Lookaside
    );




NTSTATUS
__forceinline
WdfLookasideListCreate(
    
    PWDF_OBJECT_ATTRIBUTES LookasideAttributes,
    
    
    size_t BufferSize,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES MemoryAttributes,
    
    ULONG PoolTag,
    
    WDFLOOKASIDE* Lookaside
    )
{
    return ((PFN_WDFLOOKASIDELISTCREATE) WdfFunctions[WdfLookasideListCreateTableIndex])(WdfDriverGlobals, LookasideAttributes, BufferSize, PoolType, MemoryAttributes, PoolTag, Lookaside);
}




typedef



NTSTATUS
(*PFN_WDFMEMORYCREATEFROMLOOKASIDE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFLOOKASIDE Lookaside,
    
    WDFMEMORY* Memory
    );



NTSTATUS
__forceinline
WdfMemoryCreateFromLookaside(
    
    WDFLOOKASIDE Lookaside,
    
    WDFMEMORY* Memory
    )
{
    return ((PFN_WDFMEMORYCREATEFROMLOOKASIDE) WdfFunctions[WdfMemoryCreateFromLookasideTableIndex])(WdfDriverGlobals, Lookaside, Memory);
}



#line 454 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfmemory.h"


#line 457 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfmemory.h"

#line 72 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfchildlist.h"































typedef enum _WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS {
    WdfChildListRetrieveDeviceUndefined = 0,
    WdfChildListRetrieveDeviceSuccess,
    WdfChildListRetrieveDeviceNotYetCreated,
    WdfChildListRetrieveDeviceNoSuchDevice,
} WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS, *PWDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS;

typedef enum _WDF_RETRIEVE_CHILD_FLAGS {
    WdfRetrieveUnspecified = 0x0000,
    WdfRetrievePresentChildren = 0x0001,
    WdfRetrieveMissingChildren = 0x0002,
    WdfRetrievePendingChildren = 0x0004,
    WdfRetrieveAddedChildren = (WdfRetrievePresentChildren | WdfRetrievePendingChildren),
    WdfRetrieveAllChildren = (WdfRetrievePresentChildren | WdfRetrievePendingChildren | WdfRetrieveMissingChildren),
} WDF_RETRIEVE_CHILD_FLAGS;



typedef struct _WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER {
    
    
    
    
    
    
    ULONG IdentificationDescriptionSize;
}   WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER,
  *PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER;

void
__forceinline
WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT(
     PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER Header,
     ULONG IdentificationDescriptionSize
    )
{
    memset((Header),0,(IdentificationDescriptionSize));
    Header->IdentificationDescriptionSize = IdentificationDescriptionSize;
}

typedef struct _WDF_CHILD_ADDRESS_DESCRIPTION_HEADER {
    
    
    
    
    
    
    ULONG AddressDescriptionSize;
}   WDF_CHILD_ADDRESS_DESCRIPTION_HEADER,
  *PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER;

void
__forceinline
WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT(
     PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER Header,
     ULONG AddressDescriptionSize
    )
{
    memset((Header),0,(AddressDescriptionSize));
    Header->AddressDescriptionSize = AddressDescriptionSize;
}

typedef



NTSTATUS
EVT_WDF_CHILD_LIST_CREATE_DEVICE(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription,
    
    PWDFDEVICE_INIT ChildInit
    );

typedef EVT_WDF_CHILD_LIST_CREATE_DEVICE *PFN_WDF_CHILD_LIST_CREATE_DEVICE;

typedef



void
EVT_WDF_CHILD_LIST_SCAN_FOR_CHILDREN(
    
    WDFCHILDLIST ChildList
    );

typedef EVT_WDF_CHILD_LIST_SCAN_FOR_CHILDREN *PFN_WDF_CHILD_LIST_SCAN_FOR_CHILDREN;

typedef



void
EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER SourceIdentificationDescription,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER DestinationIdentificationDescription
    );

typedef EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY *PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY;

typedef



NTSTATUS
EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER SourceIdentificationDescription,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER DestinationIdentificationDescription
    );

typedef EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE *PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE;

typedef



BOOLEAN
EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER FirstIdentificationDescription,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER SecondIdentificationDescription
    );

typedef EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE *PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE;

typedef



void
EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
    );

typedef EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP *PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP;

typedef



void
EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER SourceAddressDescription,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER DestinationAddressDescription
    );

typedef EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY *PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY;

typedef



NTSTATUS
EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER SourceAddressDescription,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER DestinationAddressDescription
    );

typedef EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE *PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE;

typedef



void
EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    );

typedef EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP *PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP;

typedef



BOOLEAN
EVT_WDF_CHILD_LIST_DEVICE_REENUMERATED(
    
    WDFCHILDLIST ChildList,
    
    WDFDEVICE OldDevice,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER OldAddressDescription,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER NewAddressDescription
    );

typedef EVT_WDF_CHILD_LIST_DEVICE_REENUMERATED *PFN_WDF_CHILD_LIST_DEVICE_REENUMERATED;

typedef struct _WDF_CHILD_RETRIEVE_INFO {
    
    
    
    ULONG Size;

    
    
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription;

    
    
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription;

    
    
    
    WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS Status;

    
    
    
    
    PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE EvtChildListIdentificationDescriptionCompare;

} WDF_CHILD_RETRIEVE_INFO, *PWDF_CHILD_RETRIEVE_INFO;

void
__forceinline
WDF_CHILD_RETRIEVE_INFO_INIT(
     PWDF_CHILD_RETRIEVE_INFO Info,
     PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
    )
{
    memset((Info),0,(sizeof(WDF_CHILD_RETRIEVE_INFO)));

    Info->Size = sizeof(WDF_CHILD_RETRIEVE_INFO);
    Info->IdentificationDescription = IdentificationDescription;
}

typedef struct _WDF_CHILD_LIST_CONFIG {
    
    
    
    ULONG Size;

    
    
    
    
    ULONG IdentificationDescriptionSize;

    
    
    
    
    ULONG AddressDescriptionSize;

    
    
    
    
    PFN_WDF_CHILD_LIST_CREATE_DEVICE EvtChildListCreateDevice;

    
    
    
    
    
    PFN_WDF_CHILD_LIST_SCAN_FOR_CHILDREN EvtChildListScanForChildren;

    
    
    
    
    
    
    PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY EvtChildListIdentificationDescriptionCopy;

    
    
    
    
    
    PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE EvtChildListIdentificationDescriptionDuplicate;

    
    
    
    
    
    PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP EvtChildListIdentificationDescriptionCleanup;

    
    
    
    
    
    
    
    PFN_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE EvtChildListIdentificationDescriptionCompare;

    
    
    
    
    
    
    PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY EvtChildListAddressDescriptionCopy;

    
    
    
    
    
    PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE EvtChildListAddressDescriptionDuplicate;

    
    
    
    
    
    PFN_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP EvtChildListAddressDescriptionCleanup;

    
    
    
    
    
    PFN_WDF_CHILD_LIST_DEVICE_REENUMERATED EvtChildListDeviceReenumerated;

} WDF_CHILD_LIST_CONFIG, *PWDF_CHILD_LIST_CONFIG;

void
__forceinline
WDF_CHILD_LIST_CONFIG_INIT(
     PWDF_CHILD_LIST_CONFIG Config,
      ULONG IdentificationDescriptionSize,
      PFN_WDF_CHILD_LIST_CREATE_DEVICE EvtChildListCreateDevice
    )
{
    memset((Config),0,(sizeof(WDF_CHILD_LIST_CONFIG)));

    Config->Size = sizeof(WDF_CHILD_LIST_CONFIG);
    Config->IdentificationDescriptionSize = IdentificationDescriptionSize;
    Config->EvtChildListCreateDevice = EvtChildListCreateDevice;
}

typedef struct _WDF_CHILD_LIST_ITERATOR {
    
    
    
    ULONG Size;

    
    
    
    
    
    ULONG Flags;

    
    
    
    PVOID Reserved[4];

} WDF_CHILD_LIST_ITERATOR, *PWDF_CHILD_LIST_ITERATOR;

void
__forceinline
WDF_CHILD_LIST_ITERATOR_INIT(
     PWDF_CHILD_LIST_ITERATOR Iterator,
     ULONG Flags
    )
{
    memset((Iterator),0,(sizeof(WDF_CHILD_LIST_ITERATOR)));

    Iterator->Size = sizeof(WDF_CHILD_LIST_ITERATOR);
    Iterator->Flags = Flags;
}




typedef



NTSTATUS
(*PFN_WDFCHILDLISTCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_CHILD_LIST_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES ChildListAttributes,
    
    WDFCHILDLIST* ChildList
    );



NTSTATUS
__forceinline
WdfChildListCreate(
    
    WDFDEVICE Device,
    
    PWDF_CHILD_LIST_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES ChildListAttributes,
    
    WDFCHILDLIST* ChildList
    )
{
    return ((PFN_WDFCHILDLISTCREATE) WdfFunctions[WdfChildListCreateTableIndex])(WdfDriverGlobals, Device, Config, ChildListAttributes, ChildList);
}




typedef


WDFDEVICE
(*PFN_WDFCHILDLISTGETDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList
    );


WDFDEVICE
__forceinline
WdfChildListGetDevice(
    
    WDFCHILDLIST ChildList
    )
{
    return ((PFN_WDFCHILDLISTGETDEVICE) WdfFunctions[WdfChildListGetDeviceTableIndex])(WdfDriverGlobals, ChildList);
}




typedef



WDFDEVICE
(*PFN_WDFCHILDLISTRETRIEVEPDO)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_RETRIEVE_INFO RetrieveInfo
    );



WDFDEVICE
__forceinline
WdfChildListRetrievePdo(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_RETRIEVE_INFO RetrieveInfo
    )
{
    return ((PFN_WDFCHILDLISTRETRIEVEPDO) WdfFunctions[WdfChildListRetrievePdoTableIndex])(WdfDriverGlobals, ChildList, RetrieveInfo);
}




typedef



NTSTATUS
(*PFN_WDFCHILDLISTRETRIEVEADDRESSDESCRIPTION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    );



NTSTATUS
__forceinline
WdfChildListRetrieveAddressDescription(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    )
{
    return ((PFN_WDFCHILDLISTRETRIEVEADDRESSDESCRIPTION) WdfFunctions[WdfChildListRetrieveAddressDescriptionTableIndex])(WdfDriverGlobals, ChildList, IdentificationDescription, AddressDescription);
}




typedef


void
(*PFN_WDFCHILDLISTBEGINSCAN)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList
    );


void
__forceinline
WdfChildListBeginScan(
    
    WDFCHILDLIST ChildList
    )
{
    ((PFN_WDFCHILDLISTBEGINSCAN) WdfFunctions[WdfChildListBeginScanTableIndex])(WdfDriverGlobals, ChildList);
}




typedef


void
(*PFN_WDFCHILDLISTENDSCAN)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList
    );


void
__forceinline
WdfChildListEndScan(
    
    WDFCHILDLIST ChildList
    )
{
    ((PFN_WDFCHILDLISTENDSCAN) WdfFunctions[WdfChildListEndScanTableIndex])(WdfDriverGlobals, ChildList);
}




typedef


void
(*PFN_WDFCHILDLISTBEGINITERATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_LIST_ITERATOR Iterator
    );


void
__forceinline
WdfChildListBeginIteration(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_LIST_ITERATOR Iterator
    )
{
    ((PFN_WDFCHILDLISTBEGINITERATION) WdfFunctions[WdfChildListBeginIterationTableIndex])(WdfDriverGlobals, ChildList, Iterator);
}




typedef



NTSTATUS
(*PFN_WDFCHILDLISTRETRIEVENEXTDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_LIST_ITERATOR Iterator,
    
    WDFDEVICE* Device,
    
    PWDF_CHILD_RETRIEVE_INFO Info
    );



NTSTATUS
__forceinline
WdfChildListRetrieveNextDevice(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_LIST_ITERATOR Iterator,
    
    WDFDEVICE* Device,
    
    PWDF_CHILD_RETRIEVE_INFO Info
    )
{
    return ((PFN_WDFCHILDLISTRETRIEVENEXTDEVICE) WdfFunctions[WdfChildListRetrieveNextDeviceTableIndex])(WdfDriverGlobals, ChildList, Iterator, Device, Info);
}




typedef


void
(*PFN_WDFCHILDLISTENDITERATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_LIST_ITERATOR Iterator
    );


void
__forceinline
WdfChildListEndIteration(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_LIST_ITERATOR Iterator
    )
{
    ((PFN_WDFCHILDLISTENDITERATION) WdfFunctions[WdfChildListEndIterationTableIndex])(WdfDriverGlobals, ChildList, Iterator);
}




typedef



NTSTATUS
(*PFN_WDFCHILDLISTADDORUPDATECHILDDESCRIPTIONASPRESENT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    );



NTSTATUS
__forceinline
WdfChildListAddOrUpdateChildDescriptionAsPresent(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    )
{
    return ((PFN_WDFCHILDLISTADDORUPDATECHILDDESCRIPTIONASPRESENT) WdfFunctions[WdfChildListAddOrUpdateChildDescriptionAsPresentTableIndex])(WdfDriverGlobals, ChildList, IdentificationDescription, AddressDescription);
}




typedef



NTSTATUS
(*PFN_WDFCHILDLISTUPDATECHILDDESCRIPTIONASMISSING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
    );



NTSTATUS
__forceinline
WdfChildListUpdateChildDescriptionAsMissing(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
    )
{
    return ((PFN_WDFCHILDLISTUPDATECHILDDESCRIPTIONASMISSING) WdfFunctions[WdfChildListUpdateChildDescriptionAsMissingTableIndex])(WdfDriverGlobals, ChildList, IdentificationDescription);
}




typedef


void
(*PFN_WDFCHILDLISTUPDATEALLCHILDDESCRIPTIONSASPRESENT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList
    );


void
__forceinline
WdfChildListUpdateAllChildDescriptionsAsPresent(
    
    WDFCHILDLIST ChildList
    )
{
    ((PFN_WDFCHILDLISTUPDATEALLCHILDDESCRIPTIONSASPRESENT) WdfFunctions[WdfChildListUpdateAllChildDescriptionsAsPresentTableIndex])(WdfDriverGlobals, ChildList);
}




typedef


BOOLEAN
(*PFN_WDFCHILDLISTREQUESTCHILDEJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
    );


BOOLEAN
__forceinline
WdfChildListRequestChildEject(
    
    WDFCHILDLIST ChildList,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
    )
{
    return ((PFN_WDFCHILDLISTREQUESTCHILDEJECT) WdfFunctions[WdfChildListRequestChildEjectTableIndex])(WdfDriverGlobals, ChildList, IdentificationDescription);
}



#line 831 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfchildlist.h"


#line 834 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfchildlist.h"

#line 73 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdffileobject.h"




































typedef


PUNICODE_STRING
(*PFN_WDFFILEOBJECTGETFILENAME)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFFILEOBJECT FileObject
    );


PUNICODE_STRING
__forceinline
WdfFileObjectGetFileName(
    
    WDFFILEOBJECT FileObject
    )
{
    return ((PFN_WDFFILEOBJECTGETFILENAME) WdfFunctions[WdfFileObjectGetFileNameTableIndex])(WdfDriverGlobals, FileObject);
}




typedef


ULONG
(*PFN_WDFFILEOBJECTGETFLAGS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFFILEOBJECT FileObject
    );


ULONG
__forceinline
WdfFileObjectGetFlags(
    
    WDFFILEOBJECT FileObject
    )
{
    return ((PFN_WDFFILEOBJECTGETFLAGS) WdfFunctions[WdfFileObjectGetFlagsTableIndex])(WdfDriverGlobals, FileObject);
}




typedef


WDFDEVICE
(*PFN_WDFFILEOBJECTGETDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFFILEOBJECT FileObject
    );


WDFDEVICE
__forceinline
WdfFileObjectGetDevice(
    
    WDFFILEOBJECT FileObject
    )
{
    return ((PFN_WDFFILEOBJECTGETDEVICE) WdfFunctions[WdfFileObjectGetDeviceTableIndex])(WdfDriverGlobals, FileObject);
}




typedef


PFILE_OBJECT
(*PFN_WDFFILEOBJECTWDMGETFILEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFFILEOBJECT FileObject
    );


PFILE_OBJECT
__forceinline
WdfFileObjectWdmGetFileObject(
    
    WDFFILEOBJECT FileObject
    )
{
    return ((PFN_WDFFILEOBJECTWDMGETFILEOBJECT) WdfFunctions[WdfFileObjectWdmGetFileObjectTableIndex])(WdfDriverGlobals, FileObject);
}




#line 138 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdffileobject.h"


#line 141 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdffileobject.h"

#line 74 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdevice.h"






























typedef enum _WDF_DEVICE_STATE_FLAGS {
    WdfDevStateNP = 0x8000,
} WDF_DEVICE_STATE_FLAGS;




typedef enum _WDF_DEVICE_PNP_STATE {
    WdfDevStatePnpInvalid = 0x00,
    WdfDevStatePnpObjectCreated = 0x100,
    WdfDevStatePnpCheckForDevicePresence = 0x101,
    WdfDevStatePnpEjectFailed = 0x102,
    WdfDevStatePnpEjectHardware = 0x103,
    WdfDevStatePnpEjectedWaitingForRemove = 0x104,
    WdfDevStatePnpInit = 0x105,
    WdfDevStatePnpInitStarting = 0x106,
    WdfDevStatePnpInitSurpriseRemoved = 0x107,
    WdfDevStatePnpHardwareAvailable = 0x108,
    WdfDevStatePnpEnableInterfaces = 0x109,
    WdfDevStatePnpHardwareAvailablePowerPolicyFailed = 0x10A,
    WdfDevStatePnpQueryRemoveAskDriver = 0x10B,
    WdfDevStatePnpQueryRemovePending = 0x10C,
    WdfDevStatePnpQueryRemoveStaticCheck = 0x10D,
    WdfDevStatePnpQueriedRemoving = 0x10E,
    WdfDevStatePnpQueryStopAskDriver = 0x10F,
    WdfDevStatePnpQueryStopPending = 0x110,
    WdfDevStatePnpQueryStopStaticCheck = 0x111,
    WdfDevStatePnpQueryCanceled = 0x112,
    WdfDevStatePnpRemoved = 0x113,
    WdfDevStatePnpPdoRemoved = 0x114,
    WdfDevStatePnpRemovedPdoWait = 0x115,
    WdfDevStatePnpRemovedPdoSurpriseRemoved = 0x116,
    WdfDevStatePnpRemovingDisableInterfaces = 0x117,
    WdfDevStatePnpRestarting = 0x118,
    WdfDevStatePnpStarted = 0x119,
    WdfDevStatePnpStartedCancelStop = 0x11A,
    WdfDevStatePnpStartedCancelRemove = 0x11B,
    WdfDevStatePnpStartedRemoving = 0x11C,
    WdfDevStatePnpStartingFromStopped = 0x11D,
    WdfDevStatePnpStopped = 0x11E,
    WdfDevStatePnpStoppedWaitForStartCompletion = 0x11F,
    WdfDevStatePnpStartedStopping = 0x120,
    WdfDevStatePnpSurpriseRemove = 0x121,
    WdfDevStatePnpInitQueryRemove = 0x122,
    WdfDevStatePnpInitQueryRemoveCanceled = 0x123,
    WdfDevStatePnpFdoRemoved = 0x124,
    WdfDevStatePnpRemovedWaitForChildren = 0x125,
    WdfDevStatePnpQueriedSurpriseRemove = 0x126,
    WdfDevStatePnpSurpriseRemoveIoStarted = 0x127,
    WdfDevStatePnpFailedPowerDown = 0x128,
    WdfDevStatePnpFailedIoStarting = 0x129,
    WdfDevStatePnpFailedOwnHardware = 0x12A,
    WdfDevStatePnpFailed = 0x12B,
    WdfDevStatePnpFailedSurpriseRemoved = 0x12C,
    WdfDevStatePnpFailedStarted = 0x12D,
    WdfDevStatePnpFailedWaitForRemove = 0x12E,
    WdfDevStatePnpFailedInit = 0x12F,
    WdfDevStatePnpPdoInitFailed = 0x130,
    WdfDevStatePnpRestart = 0x131,
    WdfDevStatePnpRestartReleaseHardware = 0x132,
    WdfDevStatePnpRestartHardwareAvailable = 0x133,
    WdfDevStatePnpPdoRestart = 0x134,
    WdfDevStatePnpFinal = 0x135,
    WdfDevStatePnpRemovedChildrenRemoved = 0x136,
    WdfDevStatePnpQueryRemoveEnsureDeviceAwake = 0x137,
    WdfDevStatePnpQueryStopEnsureDeviceAwake = 0x138,
    WdfDevStatePnpNull = 0x139,
} WDF_DEVICE_PNP_STATE, *PWDF_DEVICE_PNP_STATE;




typedef enum _WDF_DEVICE_POWER_STATE {
    WdfDevStatePowerInvalid = 0x00,
    WdfDevStatePowerObjectCreated = 0x300,
    WdfDevStatePowerCheckDeviceType = 0x301,
    WdfDevStatePowerCheckDeviceTypeNP = 0x302 | WdfDevStateNP,
    WdfDevStatePowerCheckParentState = 0x303,
    WdfDevStatePowerCheckParentStateNP = 0x304 | WdfDevStateNP,
    WdfDevStatePowerEnablingWakeAtBus = 0x305,
    WdfDevStatePowerEnablingWakeAtBusNP = 0x306 | WdfDevStateNP,
    WdfDevStatePowerD0 = 0x307,
    WdfDevStatePowerD0NP = 0x308 | WdfDevStateNP,
    WdfDevStatePowerD0BusWakeOwner = 0x309,
    WdfDevStatePowerD0BusWakeOwnerNP = 0x30A | WdfDevStateNP,
    WdfDevStatePowerD0ArmedForWake = 0x30B,
    WdfDevStatePowerD0ArmedForWakeNP = 0x30C | WdfDevStateNP,
    WdfDevStatePowerD0DisarmingWakeAtBus = 0x30D,
    WdfDevStatePowerD0DisarmingWakeAtBusNP = 0x30E | WdfDevStateNP,
    WdfDevStatePowerD0Starting = 0x30F,
    WdfDevStatePowerD0StartingConnectInterrupt = 0x310,
    WdfDevStatePowerD0StartingDmaEnable = 0x311,
    WdfDevStatePowerD0StartingStartSelfManagedIo = 0x312,
    WdfDevStatePowerDecideD0State = 0x313,
    WdfDevStatePowerGotoD3Stopped = 0x314,
    WdfDevStatePowerStopped = 0x315,
    WdfDevStatePowerStartingCheckDeviceType = 0x316,
    WdfDevStatePowerStartingChild = 0x317,
    WdfDevStatePowerDxDisablingWakeAtBus = 0x318,
    WdfDevStatePowerDxDisablingWakeAtBusNP = 0x319 | WdfDevStateNP,
    WdfDevStatePowerGotoDx = 0x31A,
    WdfDevStatePowerGotoDxNP = 0x31B | WdfDevStateNP,
    WdfDevStatePowerGotoDxIoStopped = 0x31C,
    WdfDevStatePowerGotoDxIoStoppedNP = 0x31D | WdfDevStateNP,
    WdfDevStatePowerGotoDxNPFailed = 0x31E | WdfDevStateNP,
    WdfDevStatePowerDx = 0x31F,
    WdfDevStatePowerDxNP = 0x320 | WdfDevStateNP,
    WdfDevStatePowerGotoDxArmedForWake = 0x321,
    WdfDevStatePowerGotoDxArmedForWakeNP = 0x322 | WdfDevStateNP,
    WdfDevStatePowerGotoDxIoStoppedArmedForWake = 0x323,
    WdfDevStatePowerGotoDxIoStoppedArmedForWakeNP = 0x324 | WdfDevStateNP,
    WdfDevStatePowerDxArmedForWake = 0x325,
    WdfDevStatePowerDxArmedForWakeNP = 0x326 | WdfDevStateNP,
    WdfDevStatePowerCheckParentStateArmedForWake = 0x327,
    WdfDevStatePowerCheckParentStateArmedForWakeNP = 0x328 | WdfDevStateNP,
    WdfDevStatePowerWaitForParentArmedForWake = 0x329,
    WdfDevStatePowerWaitForParentArmedForWakeNP = 0x32A | WdfDevStateNP,
    WdfDevStatePowerStartSelfManagedIo = 0x32B,
    WdfDevStatePowerStartSelfManagedIoNP = 0x32C | WdfDevStateNP,
    WdfDevStatePowerStartSelfManagedIoFailed = 0x32D,
    WdfDevStatePowerStartSelfManagedIoFailedNP = 0x32E | WdfDevStateNP,
    WdfDevStatePowerWaitForParent = 0x32F,
    WdfDevStatePowerWaitForParentNP = 0x330 | WdfDevStateNP,
    WdfDevStatePowerWakePending = 0x331,
    WdfDevStatePowerWakePendingNP = 0x332 | WdfDevStateNP,
    WdfDevStatePowerWaking = 0x333,
    WdfDevStatePowerWakingNP = 0x334 | WdfDevStateNP,
    WdfDevStatePowerWakingConnectInterrupt = 0x335,
    WdfDevStatePowerWakingConnectInterruptNP = 0x336 | WdfDevStateNP,
    WdfDevStatePowerWakingConnectInterruptFailed = 0x337,
    WdfDevStatePowerWakingConnectInterruptFailedNP = 0x338 | WdfDevStateNP,
    WdfDevStatePowerWakingDmaEnable = 0x339,
    WdfDevStatePowerWakingDmaEnableNP = 0x33A | WdfDevStateNP,
    WdfDevStatePowerWakingDmaEnableFailed = 0x33B,
    WdfDevStatePowerWakingDmaEnableFailedNP = 0x33C | WdfDevStateNP,
    WdfDevStatePowerReportPowerUpFailedDerefParent = 0x33D,
    WdfDevStatePowerReportPowerUpFailed = 0x33E,
    WdfDevStatePowerPowerFailedPowerDown = 0x33F,
    WdfDevStatePowerReportPowerDownFailed = 0x340,
    WdfDevStatePowerInitialConnectInterruptFailed = 0x341,
    WdfDevStatePowerInitialDmaEnableFailed = 0x342,
    WdfDevStatePowerInitialSelfManagedIoFailed = 0x343,
    WdfDevStatePowerInitialPowerUpFailedDerefParent = 0x344,
    WdfDevStatePowerInitialPowerUpFailed = 0x345,
    WdfDevStatePowerDxStoppedDisarmWake = 0x346,
    WdfDevStatePowerDxStoppedDisarmWakeNP = 0x347 | WdfDevStateNP,
    WdfDevStatePowerGotoDxStoppedDisableInterruptNP = 0x348 | WdfDevStateNP,
    WdfDevStatePowerGotoDxStopped = 0x349,
    WdfDevStatePowerDxStopped = 0x34A,
    WdfDevStatePowerGotoStopped = 0x34B,
    WdfDevStatePowerStoppedCompleteDx = 0x34C,
    WdfDevStatePowerDxStoppedDecideDxState = 0x34D,
    WdfDevStatePowerDxStoppedArmForWake = 0x34E,
    WdfDevStatePowerDxStoppedArmForWakeNP = 0x34F | WdfDevStateNP,
    WdfDevStatePowerFinalPowerDownFailed = 0x350,
    WdfDevStatePowerFinal = 0x351,
    WdfDevStatePowerNull = 0x352,
} WDF_DEVICE_POWER_STATE, *PWDF_DEVICE_POWER_STATE;





typedef enum _WDF_DEVICE_POWER_POLICY_STATE {
    WdfDevStatePwrPolInvalid =  0x00,
    WdfDevStatePwrPolObjectCreated = 0x500,
    WdfDevStatePwrPolStarting = 0x501,
    WdfDevStatePwrPolStartingSucceeded = 0x502,
    WdfDevStatePwrPolStartingFailed = 0x503,
    WdfDevStatePwrPolStartingDecideS0Wake = 0x504,
    WdfDevStatePwrPolStartedIdleCapable = 0x505,
    WdfDevStatePwrPolTimerExpiredNoWake = 0x506,
    WdfDevStatePwrPolTimerExpiredNoWakeCompletePowerDown = 0x507,
    WdfDevStatePwrPolWaitingUnarmed = 0x508,
    WdfDevStatePwrPolWaitingUnarmedQueryIdle = 0x509,
    WdfDevStatePwrPolS0NoWakePowerUp = 0x50A,
    WdfDevStatePwrPolS0NoWakeCompletePowerUp = 0x50B,
    WdfDevStatePwrPolSystemSleepFromDeviceWaitingUnarmed = 0x50C,
    WdfDevStatePwrPolSystemSleepNeedWake = 0x50D,
    WdfDevStatePwrPolSystemSleepNeedWakeCompletePowerUp = 0x50E,
    WdfDevStatePwrPolSystemSleepPowerRequestFailed = 0x50F,
    WdfDevStatePwrPolCheckPowerPageable = 0x510,
    WdfDevStatePwrPolSleepingWakeWakeArrived = 0x511,
    WdfDevStatePwrPolSleepingWakeRevertArmWake = 0x512,
    WdfDevStatePwrPolSystemAsleepWakeArmed = 0x513,
    WdfDevStatePwrPolSystemWakeDeviceWakeEnabled = 0x514,
    WdfDevStatePwrPolSystemWakeDeviceWakeEnabledWakeCanceled = 0x515,
    WdfDevStatePwrPolSystemWakeDeviceWakeDisarm = 0x516,
    WdfDevStatePwrPolSystemWakeDeviceWakeTriggered = 0x517,
    WdfDevStatePwrPolSystemWakeDeviceWakeTriggeredS0 = 0x518,
    WdfDevStatePwrPolSystemWakeDeviceWokeDisarm = 0x519,
    WdfDevStatePwrPolSleepingWakeWakeArrivedNP =  0x51A | WdfDevStateNP,
    WdfDevStatePwrPolSleepingWakeRevertArmWakeNP =  0x51B | WdfDevStateNP,
    WdfDevStatePwrPolSleepingWakePowerDownFailed = 0x51C,
    WdfDevStatePwrPolSleepingWakePowerDownFailedWakeCanceled = 0x51D,
    WdfDevStatePwrPolSystemAsleepWakeArmedNP =  0x51E | WdfDevStateNP,
    WdfDevStatePwrPolSystemWakeDeviceWakeEnabledNP =  0x51F | WdfDevStateNP,
    WdfDevStatePwrPolSystemWakeDeviceWakeEnabledWakeCanceledNP =  0x520 | WdfDevStateNP,
    WdfDevStatePwrPolSystemWakeDeviceWakeDisarmNP =  0x521 | WdfDevStateNP,
    WdfDevStatePwrPolSystemWakeDeviceWakeTriggeredNP =  0x522 | WdfDevStateNP,
    WdfDevStatePwrPolSystemWakeDeviceWakeTriggeredS0NP =  0x523 | WdfDevStateNP,
    WdfDevStatePwrPolSystemWakeDeviceWokeDisarmNP =  0x524 | WdfDevStateNP,
    WdfDevStatePwrPolSystemWakeDeviceWakeCompletePowerUp = 0x525,
    WdfDevStatePwrPolSleeping = 0x526,
    WdfDevStatePwrPolSleepingNoWakePowerDown = 0x527,
    WdfDevStatePwrPolSleepingNoWakeCompletePowerDown = 0x528,
    WdfDevStatePwrPolSleepingNoWakeDxRequestFailed = 0x529,
    WdfDevStatePwrPolSleepingWakePowerDown = 0x52A,
    WdfDevStatePwrPolSleepingSendWake = 0x52B,
    WdfDevStatePwrPolSystemAsleepNoWake = 0x52C,
    WdfDevStatePwrPolSystemWakeDeviceWakeDisabled = 0x52D,
    WdfDevStatePwrPolSystemWakeDeviceToD0 = 0x52E,
    WdfDevStatePwrPolSystemWakeDeviceToD0CompletePowerUp = 0x52F,
    WdfDevStatePwrPolSystemWakeQueryIdle = 0x530,
    WdfDevStatePwrPolStartedWakeCapable = 0x531,
    WdfDevStatePwrPolTimerExpiredDecideUsbSS = 0x532,
    WdfDevStatePwrPolTimerExpiredWakeCapablePowerDown = 0x533,
    WdfDevStatePwrPolTimerExpiredWakeCapableSendWake = 0x534,
    WdfDevStatePwrPolTimerExpiredWakeCapableUsbSS = 0x535,
    WdfDevStatePwrPolTimerExpiredWakeCapableWakeArrived = 0x536,
    WdfDevStatePwrPolTimerExpiredWakeCapableCancelWake = 0x537,
    WdfDevStatePwrPolTimerExpiredWakeCapableWakeCanceled = 0x538,
    WdfDevStatePwrPolTimerExpiredWakeCapableCleanup = 0x539,
    WdfDevStatePwrPolTimerExpiredWakeCapableDxAllocFailed = 0x53A,
    WdfDevStatePwrPolTimerExpiredWakeCompletedPowerDown = 0x53B,
    WdfDevStatePwrPolTimerExpiredWakeCompletedPowerUp = 0x53C,
    WdfDevStatePwrPolWaitingArmedUsbSS = 0x53D,
    WdfDevStatePwrPolWaitingArmed = 0x53E,
    WdfDevStatePwrPolWaitingArmedQueryIdle = 0x53F,
    WdfDevStatePwrPolIoPresentArmed = 0x540,
    WdfDevStatePwrPolIoPresentArmedWakeCanceled = 0x541,
    WdfDevStatePwrPolS0WakeDisarm = 0x542,
    WdfDevStatePwrPolS0WakeCompletePowerUp = 0x543,
    WdfDevStatePwrPolTimerExpiredWakeSucceeded = 0x544,
    WdfDevStatePwrPolTimerExpiredWakeCompletedDisarm = 0x545,
    WdfDevStatePwrPolTimerExpiredWakeCapableWakeSucceeded = 0x546,
    WdfDevStatePwrPolTimerExpiredWakeCapableWakeFailed = 0x547,
    WdfDevStatePwrPolWakeFailedUsbSS = 0x548,
    WdfDevStatePwrPolTimerExpiredWakeCapablePowerDownFailedCancelWake = 0x549,
    WdfDevStatePwrPolTimerExpiredWakeCapablePowerDownFailedWakeCanceled = 0x54A,
    WdfDevStatePwrPolTimerExpiredWakeCapablePowerDownFailedUsbSS = 0x54B,
    WdfDevStatePwrPolCancelingWakeForSystemSleep = 0x54C,
    WdfDevStatePwrPolCancelingWakeForSystemSleepWakeCanceled = 0x54D,
    WdfDevStatePwrPolDisarmingWakeForSystemSleepCompletePowerUp = 0x54E,
    WdfDevStatePwrPolPowerUpForSystemSleepFailed = 0x54F,
    WdfDevStatePwrPolWokeFromS0UsbSS = 0x550,
    WdfDevStatePwrPolWokeFromS0 = 0x551,
    WdfDevStatePwrPolWokeFromS0NotifyDriver = 0x552,
    WdfDevStatePwrPolStoppingResetDevice = 0x553,
    WdfDevStatePwrPolStoppingResetDeviceCompletePowerUp = 0x554,
    WdfDevStatePwrPolStoppingResetDeviceFailed = 0x555,
    WdfDevStatePwrPolStoppingD0 = 0x556,
    WdfDevStatePwrPolStoppingD0Failed = 0x557,
    WdfDevStatePwrPolStoppingDisarmWake = 0x558,
    WdfDevStatePwrPolStoppingDisarmWakeCancelWake = 0x559,
    WdfDevStatePwrPolStoppingDisarmWakeWakeCanceled = 0x55A,
    WdfDevStatePwrPolStopping = 0x55B,
    WdfDevStatePwrPolStoppingFailed = 0x55C,
    WdfDevStatePwrPolStoppingSendStatus = 0x55D,
    WdfDevStatePwrPolStoppingCancelTimer = 0x55E,
    WdfDevStatePwrPolStoppingWaitForIdleTimeout = 0x55F,
    WdfDevStatePwrPolStoppingCancelUsbSS = 0x560,
    WdfDevStatePwrPolStoppingWaitForUsbSSCompletion = 0x561,
    WdfDevStatePwrPolStoppingCancelWake = 0x562,
    WdfDevStatePwrPolStopped = 0x563,
    WdfDevStatePwrPolCancelUsbSS = 0x564,
    WdfDevStatePwrPolStarted = 0x565,
    WdfDevStatePwrPolStartedCancelTimer = 0x566,
    WdfDevStatePwrPolStartedWaitForIdleTimeout = 0x567,
    WdfDevStatePwrPolStartedWakeCapableCancelTimerForSleep = 0x568,
    WdfDevStatePwrPolStartedWakeCapableWaitForIdleTimeout = 0x569,
    WdfDevStatePwrPolStartedWakeCapableSleepingUsbSS = 0x56A,
    WdfDevStatePwrPolStartedIdleCapableCancelTimerForSleep = 0x56B,
    WdfDevStatePwrPolStartedIdleCapableWaitForIdleTimeout = 0x56C,
    WdfDevStatePwrPolDeviceD0PowerRequestFailed = 0x56D,
    WdfDevStatePwrPolDevicePowerRequestFailed = 0x56E,
    WdfDevStatePwrPolGotoDx = 0x56F,
    WdfDevStatePwrPolGotoDxInDx = 0x570,
    WdfDevStatePwrPolDx = 0x571,
    WdfDevStatePwrPolGotoD0 = 0x572,
    WdfDevStatePwrPolGotoD0InD0 = 0x573,
    WdfDevStatePwrPolFinal = 0x574,
    WdfDevStatePwrPolSleepingPowerDownNotProcessed = 0x575,
    WdfDevStatePwrPolTimerExpiredWakeCapablePowerDownNotProcessed = 0x576,
    WdfDevStatePwrPolTimerExpiredNoWakePowerDownNotProcessed = 0x577,
    WdfDevStatePwrPolTimerExpiredNoWakePoweredDownDisableIdleTimer = 0x578,
    WdfDevStatePwrPolStoppingWaitingForImplicitPowerDown = 0x579,
    WdfDevStatePwrPolStoppingPoweringUp = 0x57A,
    WdfDevStatePwrPolStoppingPoweringDown = 0x57B,
    WdfDevStatePwrPolPowerUpForSystemSleepNotSeen = 0x57C,
    WdfDevStatePwrPolWaitingArmedStoppingCancelUsbSS = 0x57D,
    WdfDevStatePwrPolWaitingArmedWakeFailedCancelUsbSS = 0x57E,
    WdfDevStatePwrPolWaitingArmedIoPresentCancelUsbSS = 0x57F,
    WdfDevStatePwrPolWaitingArmedWakeSucceededCancelUsbSS = 0x580,
    WdfDevStatePwrPolCancelingUsbSSForSystemSleep = 0x581,
    WdfDevStatePwrPolStoppingD0CancelUsbSS = 0x582,
    WdfDevStatePwrPolNull = 0x583,
} WDF_DEVICE_POWER_POLICY_STATE, *PWDF_DEVICE_POWER_POLICY_STATE;



typedef enum _WDF_STATE_NOTIFICATION_TYPE {
    StateNotificationInvalid =       0x0000,
    StateNotificationEnterState =       0x0001,
    StateNotificationPostProcessState = 0x0002,
    StateNotificationLeaveState =       0x0004,
    StateNotificationAllStates =       StateNotificationEnterState | StateNotificationPostProcessState | StateNotificationLeaveState,
} WDF_STATE_NOTIFICATION_TYPE;

typedef enum _WDF_POWER_POLICY_S0_IDLE_CAPABILITIES {
    IdleCapsInvalid = 0,
    IdleCannotWakeFromS0,
    IdleCanWakeFromS0,
    IdleUsbSelectiveSuspend,
} WDF_POWER_POLICY_S0_IDLE_CAPABILITIES;

typedef enum _WDF_POWER_POLICY_S0_IDLE_USER_CONTROL {
    IdleUserControlInvalid = 0,
    IdleDoNotAllowUserControl,
    IdleAllowUserControl,
} WDF_POWER_POLICY_S0_IDLE_USER_CONTROL;

typedef enum _WDF_POWER_POLICY_IDLE_TIMEOUT_CONSTANTS {
    IdleTimeoutDefaultConstant = 0,
} WDF_POWER_POLICY_IDLE_TIMEOUT_CONSTANTS;

typedef enum _WDF_POWER_POLICY_SX_WAKE_USER_CONTROL {
    WakeUserControlInvalid = 0,
    WakeDoNotAllowUserControl,
    WakeAllowUserControl,
} WDF_POWER_POLICY_SX_WAKE_USER_CONTROL;

typedef enum _WDF_POWER_DEVICE_STATE {
    WdfPowerDeviceInvalid = 0,
    WdfPowerDeviceD0,
    WdfPowerDeviceD1,
    WdfPowerDeviceD2,
    WdfPowerDeviceD3,
    WdfPowerDeviceD3Final,
    WdfPowerDevicePrepareForHibernation,
    WdfPowerDeviceMaximum,
} WDF_POWER_DEVICE_STATE, *PWDF_POWER_DEVICE_STATE;

typedef enum _WDF_SPECIAL_FILE_TYPE {
    WdfSpecialFileUndefined = 0,
    WdfSpecialFilePaging = 1,
    WdfSpecialFileHibernation,
    WdfSpecialFileDump,
    WdfSpecialFileMax,
} WDF_SPECIAL_FILE_TYPE, *PWDF_SPECIAL_FILE_TYPE;

typedef enum _WDF_DEVICE_IO_TYPE {
    WdfDeviceIoUndefined = 0,
    WdfDeviceIoNeither,
    WdfDeviceIoBuffered,
    WdfDeviceIoDirect,
} WDF_DEVICE_IO_TYPE, *PWDF_DEVICE_IO_TYPE;

typedef enum _WDF_FILEOBJECT_CLASS {
    WdfFileObjectInvalid = 0,
    WdfFileObjectNotRequired = 1,
    WdfFileObjectWdfCanUseFsContext = 2,
    WdfFileObjectWdfCanUseFsContext2 = 3,
    WdfFileObjectWdfCannotUseFsContexts = 4,
    WdfFileObjectCanBeOptional = 0x80000000,
} WDF_FILEOBJECT_CLASS, *PWDF_FILEOBJECT_CLASS;

typedef enum _WDF_DEVICE_FAILED_ACTION {
    WdfDeviceFailedUndefined = 0,
    WdfDeviceFailedAttemptRestart,
    WdfDeviceFailedNoRestart,
} WDF_DEVICE_FAILED_ACTION;








#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\wdmsec.h"






















#pragma once






























extern const UNICODE_STRING     SDDL_DEVOBJ_KERNEL_ONLY;





























extern const UNICODE_STRING     SDDL_DEVOBJ_SYS_ALL;













extern const UNICODE_STRING     SDDL_DEVOBJ_SYS_ALL_ADM_ALL;




















extern const UNICODE_STRING     SDDL_DEVOBJ_SYS_ALL_ADM_RX;






















extern const UNICODE_STRING     SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_R;



























extern const UNICODE_STRING     SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_R_RES_R;






















extern const UNICODE_STRING     SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_RW_RES_R;



















extern const UNICODE_STRING     SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_RWX_RES_RWX;














































































































































































NTSTATUS
WdmlibIoCreateDeviceSecure(
      PDRIVER_OBJECT      DriverObject,
      ULONG               DeviceExtensionSize,
      PUNICODE_STRING     DeviceName              ,
      ULONG         DeviceType,
      ULONG               DeviceCharacteristics,
      BOOLEAN             Exclusive,
      PCUNICODE_STRING    DefaultSDDLString,
      LPCGUID             DeviceClassGuid         ,
     PDEVICE_OBJECT     *DeviceObject
    );












NTSTATUS
WdmlibRtlInitUnicodeStringEx(
     PUNICODE_STRING DestinationString,
      PCWSTR          SourceString        
    );












NTSTATUS
WdmlibIoValidateDeviceIoControlAccess(
      PIRP    Irp,
      ULONG   RequiredAccess
    );





#line 440 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\wdmsec.h"


#line 412 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdevice.h"
#line 413 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdevice.h"









typedef enum _WDF_REQUEST_TYPE WDF_REQUEST_TYPE;


typedef



void
EVT_WDF_DEVICE_FILE_CREATE(
    
    WDFDEVICE Device,
    
    WDFREQUEST Request,
    
    WDFFILEOBJECT FileObject
    );

typedef EVT_WDF_DEVICE_FILE_CREATE *PFN_WDF_DEVICE_FILE_CREATE;

typedef



void
EVT_WDF_FILE_CLOSE(
    
    WDFFILEOBJECT FileObject
    );

typedef EVT_WDF_FILE_CLOSE *PFN_WDF_FILE_CLOSE;

typedef



void
EVT_WDF_FILE_CLEANUP(
    
    WDFFILEOBJECT FileObject
    );

typedef EVT_WDF_FILE_CLEANUP *PFN_WDF_FILE_CLEANUP;

typedef struct _WDF_FILEOBJECT_CONFIG {
    
    
    
    ULONG Size;

    
    
    
    PFN_WDF_DEVICE_FILE_CREATE  EvtDeviceFileCreate;

    
    
    
    PFN_WDF_FILE_CLOSE   EvtFileClose;

    
    
    
    PFN_WDF_FILE_CLEANUP EvtFileCleanup;

    
    
    
    
    
    
    
    
    
    
    
    WDF_TRI_STATE AutoForwardCleanupClose;

    
    
    
    
    
    WDF_FILEOBJECT_CLASS FileObjectClass;

} WDF_FILEOBJECT_CONFIG, *PWDF_FILEOBJECT_CONFIG;

void
__forceinline
WDF_FILEOBJECT_CONFIG_INIT(
     PWDF_FILEOBJECT_CONFIG FileEventCallbacks,
     PFN_WDF_DEVICE_FILE_CREATE EvtDeviceFileCreate,
     PFN_WDF_FILE_CLOSE EvtFileClose,
     PFN_WDF_FILE_CLEANUP EvtFileCleanup
    )
{
    FileEventCallbacks->Size = sizeof(WDF_FILEOBJECT_CONFIG);

    FileEventCallbacks->EvtDeviceFileCreate  = EvtDeviceFileCreate;
    FileEventCallbacks->EvtFileClose   = EvtFileClose;
    FileEventCallbacks->EvtFileCleanup = EvtFileCleanup;

    FileEventCallbacks->FileObjectClass = WdfFileObjectWdfCannotUseFsContexts;
    FileEventCallbacks->AutoForwardCleanupClose = WdfUseDefault;
}

typedef struct _WDF_DEVICE_PNP_NOTIFICATION_DATA {
    
    
    
    WDF_STATE_NOTIFICATION_TYPE Type;

    union {
        struct {
            
            
            
            WDF_DEVICE_PNP_STATE CurrentState;

            
            
            
            WDF_DEVICE_PNP_STATE NewState;
        } EnterState;

        struct {
            
            
            
            WDF_DEVICE_PNP_STATE CurrentState;
        } PostProcessState;


        struct {
            
            
            
            WDF_DEVICE_PNP_STATE CurrentState;

            
            
            
            WDF_DEVICE_PNP_STATE NewState;
        } LeaveState;
    } Data;
} WDF_DEVICE_PNP_NOTIFICATION_DATA;

typedef const WDF_DEVICE_PNP_NOTIFICATION_DATA* PCWDF_DEVICE_PNP_NOTIFICATION_DATA;

typedef struct _WDF_DEVICE_POWER_NOTIFICATION_DATA {
    
    
    
    WDF_STATE_NOTIFICATION_TYPE Type;

    union {
        struct {
            
            
            
            WDF_DEVICE_POWER_STATE CurrentState;

            
            
            
            WDF_DEVICE_POWER_STATE NewState;
        } EnterState;

        struct {
            
            
            
            WDF_DEVICE_POWER_STATE CurrentState;
        } PostProcessState;


        struct {
            
            
            
            WDF_DEVICE_POWER_STATE CurrentState;

            
            
            
            WDF_DEVICE_POWER_STATE NewState;
        } LeaveState;
    } Data;
} WDF_DEVICE_POWER_NOTIFICATION_DATA;

typedef const WDF_DEVICE_POWER_NOTIFICATION_DATA* PCWDF_DEVICE_POWER_NOTIFICATION_DATA;

typedef struct _WDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA {
    
    
    
    WDF_STATE_NOTIFICATION_TYPE Type;

    union {
        struct {
            
            
            
            WDF_DEVICE_POWER_POLICY_STATE CurrentState;

            
            
            
            WDF_DEVICE_POWER_POLICY_STATE NewState;
        } EnterState;

        struct {
            
            
            
            WDF_DEVICE_POWER_POLICY_STATE CurrentState;
        } PostProcessState;


        struct {
            
            
            
            WDF_DEVICE_POWER_POLICY_STATE CurrentState;

            
            
            
            WDF_DEVICE_POWER_POLICY_STATE NewState;
        } LeaveState;
    } Data;
} WDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA;

typedef const WDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA* PCWDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA;

typedef



void
EVT_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION(
    
    WDFDEVICE Device,
    
    PCWDF_DEVICE_PNP_NOTIFICATION_DATA NotificationData
    );

typedef EVT_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION *PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION;

typedef



void
EVT_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION(
    
    WDFDEVICE Device,
    
    PCWDF_DEVICE_POWER_NOTIFICATION_DATA NotificationData
    );

typedef EVT_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION *PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION;

typedef



void
EVT_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION(
    
    WDFDEVICE Device,
    
    PCWDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA NotificationData
    );

typedef EVT_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION *PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION;



typedef



NTSTATUS
EVT_WDF_DEVICE_D0_ENTRY(
    
    WDFDEVICE Device,
    
    WDF_POWER_DEVICE_STATE PreviousState
    );

typedef EVT_WDF_DEVICE_D0_ENTRY *PFN_WDF_DEVICE_D0_ENTRY;

typedef



NTSTATUS
EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED(
    
    WDFDEVICE Device,
    
    WDF_POWER_DEVICE_STATE PreviousState
    );

typedef EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED *PFN_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED;

typedef



NTSTATUS
EVT_WDF_DEVICE_D0_EXIT(
    
    WDFDEVICE Device,
    
    WDF_POWER_DEVICE_STATE TargetState
    );

typedef EVT_WDF_DEVICE_D0_EXIT *PFN_WDF_DEVICE_D0_EXIT;

typedef



NTSTATUS
EVT_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED(
    
    WDFDEVICE Device,
    
    WDF_POWER_DEVICE_STATE TargetState
    );

typedef EVT_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED *PFN_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED;

typedef



NTSTATUS
EVT_WDF_DEVICE_PREPARE_HARDWARE(
    
    WDFDEVICE Device,
    
    WDFCMRESLIST ResourcesRaw,
    
    WDFCMRESLIST ResourcesTranslated
    );

typedef EVT_WDF_DEVICE_PREPARE_HARDWARE *PFN_WDF_DEVICE_PREPARE_HARDWARE;

typedef



NTSTATUS
EVT_WDF_DEVICE_RELEASE_HARDWARE(
    
    WDFDEVICE Device,
    
    WDFCMRESLIST ResourcesTranslated
    );

typedef EVT_WDF_DEVICE_RELEASE_HARDWARE *PFN_WDF_DEVICE_RELEASE_HARDWARE;

typedef



void
EVT_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP *PFN_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP;

typedef



void
EVT_WDF_DEVICE_SELF_MANAGED_IO_FLUSH(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_SELF_MANAGED_IO_FLUSH *PFN_WDF_DEVICE_SELF_MANAGED_IO_FLUSH;

typedef



NTSTATUS
EVT_WDF_DEVICE_SELF_MANAGED_IO_INIT(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_SELF_MANAGED_IO_INIT *PFN_WDF_DEVICE_SELF_MANAGED_IO_INIT;

typedef



NTSTATUS
EVT_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND *PFN_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND;

typedef



NTSTATUS
EVT_WDF_DEVICE_SELF_MANAGED_IO_RESTART(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_SELF_MANAGED_IO_RESTART *PFN_WDF_DEVICE_SELF_MANAGED_IO_RESTART;

typedef



NTSTATUS
EVT_WDF_DEVICE_QUERY_STOP(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_QUERY_STOP *PFN_WDF_DEVICE_QUERY_STOP;

typedef



NTSTATUS
EVT_WDF_DEVICE_QUERY_REMOVE(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_QUERY_REMOVE *PFN_WDF_DEVICE_QUERY_REMOVE;

typedef



void
EVT_WDF_DEVICE_SURPRISE_REMOVAL(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_SURPRISE_REMOVAL *PFN_WDF_DEVICE_SURPRISE_REMOVAL;

typedef



void
EVT_WDF_DEVICE_USAGE_NOTIFICATION(
    
    WDFDEVICE Device,
    
    WDF_SPECIAL_FILE_TYPE NotificationType,
    
    BOOLEAN IsInNotificationPath
    );

typedef EVT_WDF_DEVICE_USAGE_NOTIFICATION *PFN_WDF_DEVICE_USAGE_NOTIFICATION;

typedef



void
EVT_WDF_DEVICE_RELATIONS_QUERY(
    
    WDFDEVICE Device,
    
    DEVICE_RELATION_TYPE RelationType
    );

typedef EVT_WDF_DEVICE_RELATIONS_QUERY *PFN_WDF_DEVICE_RELATIONS_QUERY;

typedef



NTSTATUS
EVT_WDF_DEVICE_ARM_WAKE_FROM_S0(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_ARM_WAKE_FROM_S0 *PFN_WDF_DEVICE_ARM_WAKE_FROM_S0;

typedef



NTSTATUS
EVT_WDF_DEVICE_ARM_WAKE_FROM_SX(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_ARM_WAKE_FROM_SX *PFN_WDF_DEVICE_ARM_WAKE_FROM_SX;

typedef



NTSTATUS
EVT_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON(
    
    WDFDEVICE Device,
    
    BOOLEAN DeviceWakeEnabled,
    
    BOOLEAN ChildrenArmedForWake
    );

typedef EVT_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON *PFN_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON;

typedef



void
EVT_WDF_DEVICE_DISARM_WAKE_FROM_S0(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_DISARM_WAKE_FROM_S0 *PFN_WDF_DEVICE_DISARM_WAKE_FROM_S0;

typedef



void
EVT_WDF_DEVICE_DISARM_WAKE_FROM_SX(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_DISARM_WAKE_FROM_SX *PFN_WDF_DEVICE_DISARM_WAKE_FROM_SX;

typedef



void
EVT_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED *PFN_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED;

typedef



void
EVT_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED *PFN_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED;

typedef struct _WDF_PNPPOWER_EVENT_CALLBACKS {
    
    
    
    ULONG Size;

    PFN_WDF_DEVICE_D0_ENTRY                 EvtDeviceD0Entry;
    PFN_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED EvtDeviceD0EntryPostInterruptsEnabled;
    PFN_WDF_DEVICE_D0_EXIT                  EvtDeviceD0Exit;
    PFN_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED EvtDeviceD0ExitPreInterruptsDisabled;
    PFN_WDF_DEVICE_PREPARE_HARDWARE         EvtDevicePrepareHardware;
    PFN_WDF_DEVICE_RELEASE_HARDWARE         EvtDeviceReleaseHardware;
    PFN_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP  EvtDeviceSelfManagedIoCleanup;
    PFN_WDF_DEVICE_SELF_MANAGED_IO_FLUSH    EvtDeviceSelfManagedIoFlush;
    PFN_WDF_DEVICE_SELF_MANAGED_IO_INIT     EvtDeviceSelfManagedIoInit;
    PFN_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND  EvtDeviceSelfManagedIoSuspend;
    PFN_WDF_DEVICE_SELF_MANAGED_IO_RESTART  EvtDeviceSelfManagedIoRestart;
    PFN_WDF_DEVICE_SURPRISE_REMOVAL         EvtDeviceSurpriseRemoval;
    PFN_WDF_DEVICE_QUERY_REMOVE             EvtDeviceQueryRemove;
    PFN_WDF_DEVICE_QUERY_STOP               EvtDeviceQueryStop;
    PFN_WDF_DEVICE_USAGE_NOTIFICATION       EvtDeviceUsageNotification;
    PFN_WDF_DEVICE_RELATIONS_QUERY          EvtDeviceRelationsQuery;
} WDF_PNPPOWER_EVENT_CALLBACKS, *PWDF_PNPPOWER_EVENT_CALLBACKS;

typedef struct _WDF_POWER_POLICY_EVENT_CALLBACKS {
    
    
    
    ULONG Size;

    PFN_WDF_DEVICE_ARM_WAKE_FROM_S0         EvtDeviceArmWakeFromS0;
    PFN_WDF_DEVICE_DISARM_WAKE_FROM_S0      EvtDeviceDisarmWakeFromS0;
    PFN_WDF_DEVICE_WAKE_FROM_S0_TRIGGERED   EvtDeviceWakeFromS0Triggered;

    PFN_WDF_DEVICE_ARM_WAKE_FROM_SX         EvtDeviceArmWakeFromSx;
    PFN_WDF_DEVICE_DISARM_WAKE_FROM_SX      EvtDeviceDisarmWakeFromSx;
    PFN_WDF_DEVICE_WAKE_FROM_SX_TRIGGERED   EvtDeviceWakeFromSxTriggered;

    PFN_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON EvtDeviceArmWakeFromSxWithReason;

} WDF_POWER_POLICY_EVENT_CALLBACKS, *PWDF_POWER_POLICY_EVENT_CALLBACKS;

void
__forceinline
WDF_POWER_POLICY_EVENT_CALLBACKS_INIT(
     PWDF_POWER_POLICY_EVENT_CALLBACKS Callbacks
    )
{
    memset((Callbacks),0,(sizeof(WDF_POWER_POLICY_EVENT_CALLBACKS)));

    Callbacks->Size = sizeof(WDF_POWER_POLICY_EVENT_CALLBACKS);
}

void
__forceinline
WDF_PNPPOWER_EVENT_CALLBACKS_INIT(
     PWDF_PNPPOWER_EVENT_CALLBACKS Callbacks
    )
{
    memset((Callbacks),0,(sizeof(WDF_PNPPOWER_EVENT_CALLBACKS)));
    Callbacks->Size = sizeof(WDF_PNPPOWER_EVENT_CALLBACKS);
}


ULONG
__forceinline
WdfDevStateNormalize(
     ULONG State
    )
{
    return State & ~WdfDevStateNP;
}


BOOLEAN
__forceinline
WdfDevStateIsNP(
     ULONG State
    )
{
    return (State & WdfDevStateNP) ? 1 : 0;
}

typedef struct _WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS {
    
    
    
    ULONG Size;

    
    
    
    
    WDF_POWER_POLICY_S0_IDLE_CAPABILITIES IdleCaps;

    
    
    
    
    DEVICE_POWER_STATE DxState;

    
    
    
    
    ULONG IdleTimeout;

    
    
    
    
    WDF_POWER_POLICY_S0_IDLE_USER_CONTROL UserControlOfIdleSettings;

    
    
    
    
    
    
    
    
    
    WDF_TRI_STATE Enabled;

    
    
    
    
    
    
    WDF_TRI_STATE PowerUpIdleDeviceOnSystemWake;

} WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS, *PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS;

void
__forceinline
WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT(
     PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings,
     WDF_POWER_POLICY_S0_IDLE_CAPABILITIES IdleCaps
    )
{
    memset((Settings),0,(sizeof(WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS)));

    Settings->Size = sizeof(WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS);

    Settings->IdleTimeout = ((ULONG) IdleTimeoutDefaultConstant);
    Settings->UserControlOfIdleSettings = IdleAllowUserControl;
    Settings->Enabled = WdfUseDefault;
    Settings->PowerUpIdleDeviceOnSystemWake = WdfUseDefault;

    Settings->IdleCaps = IdleCaps;

    switch (IdleCaps) {
    case IdleUsbSelectiveSuspend:
    case IdleCanWakeFromS0:
        Settings->DxState = PowerDeviceMaximum;
        break;

    case IdleCannotWakeFromS0:
        Settings->DxState = PowerDeviceD3;
        break;
    }
}

typedef struct _WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS {
    
    
    
    ULONG Size;

    
    
    
    
    DEVICE_POWER_STATE DxState;

    
    
    
    
    WDF_POWER_POLICY_SX_WAKE_USER_CONTROL UserControlOfWakeSettings;

    
    
    
    
    
    
    
    
    
    
    
    WDF_TRI_STATE Enabled;

    
    
    
    
    
    
    
    BOOLEAN ArmForWakeIfChildrenAreArmedForWake;

    
    
    
    
    
    
    BOOLEAN IndicateChildWakeOnParentWake;

} WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS, *PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS;

void
__forceinline
WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT(
     PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
    )
{
    memset((Settings),0,(sizeof(WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS)));

    Settings->Size = sizeof(WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS);

    Settings->Enabled = WdfUseDefault;
    Settings->DxState = PowerDeviceMaximum;
    Settings->UserControlOfWakeSettings = WakeAllowUserControl;
}

typedef struct _WDF_DEVICE_STATE {
    
    
    
    ULONG Size;

    
    
    
    WDF_TRI_STATE Disabled;

    
    
    
    
    WDF_TRI_STATE DontDisplayInUI;

    
    
    
    
    
    WDF_TRI_STATE Failed;

    
    
    
    WDF_TRI_STATE NotDisableable;


    
    
    
    WDF_TRI_STATE Removed;

    
    
    
    
    
    WDF_TRI_STATE ResourcesChanged;

} WDF_DEVICE_STATE, *PWDF_DEVICE_STATE;

void
__forceinline
WDF_DEVICE_STATE_INIT(
     PWDF_DEVICE_STATE PnpDeviceState
    )
{
    memset((PnpDeviceState),0,(sizeof(WDF_DEVICE_STATE)));

    PnpDeviceState->Size = sizeof(WDF_DEVICE_STATE);

    
    
    
    PnpDeviceState->Disabled = WdfUseDefault;
    PnpDeviceState->DontDisplayInUI = WdfUseDefault;
    PnpDeviceState->Failed = WdfUseDefault;
    PnpDeviceState->NotDisableable = WdfUseDefault;
    PnpDeviceState->Removed = WdfUseDefault;
    PnpDeviceState->ResourcesChanged = WdfUseDefault;
}

typedef struct _WDF_DEVICE_PNP_CAPABILITIES {
    
    
    
    ULONG Size;

    
    
    

    WDF_TRI_STATE LockSupported;
    WDF_TRI_STATE EjectSupported;
    WDF_TRI_STATE Removable;
    WDF_TRI_STATE DockDevice;
    WDF_TRI_STATE UniqueID;
    WDF_TRI_STATE SilentInstall;
    WDF_TRI_STATE SurpriseRemovalOK;
    WDF_TRI_STATE HardwareDisabled;
    WDF_TRI_STATE NoDisplayInUI;

    
    
    
    ULONG Address;
    ULONG UINumber;

} WDF_DEVICE_PNP_CAPABILITIES, *PWDF_DEVICE_PNP_CAPABILITIES;

void
__forceinline
WDF_DEVICE_PNP_CAPABILITIES_INIT(
     PWDF_DEVICE_PNP_CAPABILITIES Caps
    )
{
    memset((Caps),0,(sizeof(WDF_DEVICE_PNP_CAPABILITIES)));

    Caps->Size = sizeof(WDF_DEVICE_PNP_CAPABILITIES);

    Caps->LockSupported = WdfUseDefault;
    Caps->EjectSupported = WdfUseDefault;
    Caps->Removable = WdfUseDefault;
    Caps->DockDevice = WdfUseDefault;
    Caps->UniqueID = WdfUseDefault;
    Caps->SilentInstall = WdfUseDefault;
    Caps->SurpriseRemovalOK = WdfUseDefault;
    Caps->HardwareDisabled = WdfUseDefault;
    Caps->NoDisplayInUI = WdfUseDefault;

    Caps->Address = (ULONG) -1;
    Caps->UINumber = (ULONG) -1;
}

typedef struct _WDF_DEVICE_POWER_CAPABILITIES {
    
    
    
    ULONG Size;

    WDF_TRI_STATE DeviceD1;
    WDF_TRI_STATE DeviceD2;

    WDF_TRI_STATE WakeFromD0;
    WDF_TRI_STATE WakeFromD1;
    WDF_TRI_STATE WakeFromD2;
    WDF_TRI_STATE WakeFromD3;

    
    
    
    DEVICE_POWER_STATE DeviceState[PowerSystemMaximum];

    
    
    
    
    DEVICE_POWER_STATE DeviceWake;
    SYSTEM_POWER_STATE SystemWake;

    
    
    
    ULONG D1Latency;
    ULONG D2Latency;
    ULONG D3Latency;

    
    
    
    
    
    
    DEVICE_POWER_STATE IdealDxStateForSx;

} WDF_DEVICE_POWER_CAPABILITIES, *PWDF_DEVICE_POWER_CAPABILITIES;

void
__forceinline
WDF_DEVICE_POWER_CAPABILITIES_INIT(
     PWDF_DEVICE_POWER_CAPABILITIES Caps
    )
{
    ULONG i;

    memset((Caps),0,(sizeof(WDF_DEVICE_POWER_CAPABILITIES)));

    Caps->Size = sizeof(WDF_DEVICE_POWER_CAPABILITIES);

    Caps->DeviceD1 = WdfUseDefault;
    Caps->DeviceD2 = WdfUseDefault;

    Caps->WakeFromD0 = WdfUseDefault;
    Caps->WakeFromD1 = WdfUseDefault;
    Caps->WakeFromD2 = WdfUseDefault;
    Caps->WakeFromD3 = WdfUseDefault;

    for (i = 0; i < sizeof(Caps->DeviceState)/sizeof(Caps->DeviceState[1]); i++) {
        Caps->DeviceState[i] = PowerDeviceMaximum;
    }

    Caps->DeviceWake = PowerDeviceMaximum;
    Caps->SystemWake = PowerSystemMaximum;

    Caps->D1Latency = (ULONG) -1;
    Caps->D2Latency = (ULONG) -1;
    Caps->D3Latency = (ULONG) -1;

    Caps->IdealDxStateForSx = PowerDeviceMaximum;
}

typedef



NTSTATUS
EVT_WDFDEVICE_WDM_IRP_PREPROCESS(
    
    WDFDEVICE Device,
    
    PIRP Irp
    );

typedef EVT_WDFDEVICE_WDM_IRP_PREPROCESS *PFN_WDFDEVICE_WDM_IRP_PREPROCESS;




typedef



void
EVT_WDF_IO_IN_CALLER_CONTEXT(
    
    WDFDEVICE Device,
    
    WDFREQUEST Request
    );

typedef EVT_WDF_IO_IN_CALLER_CONTEXT *PFN_WDF_IO_IN_CALLER_CONTEXT;




typedef


void
(*PFN_WDFDEVICEGETDEVICESTATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_STATE DeviceState
    );


void
__forceinline
WdfDeviceGetDeviceState(
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_STATE DeviceState
    )
{
    ((PFN_WDFDEVICEGETDEVICESTATE) WdfFunctions[WdfDeviceGetDeviceStateTableIndex])(WdfDriverGlobals, Device, DeviceState);
}




typedef


void
(*PFN_WDFDEVICESETDEVICESTATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_STATE DeviceState
    );


void
__forceinline
WdfDeviceSetDeviceState(
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_STATE DeviceState
    )
{
    ((PFN_WDFDEVICESETDEVICESTATE) WdfFunctions[WdfDeviceSetDeviceStateTableIndex])(WdfDriverGlobals, Device, DeviceState);
}




typedef


WDFDEVICE
(*PFN_WDFWDMDEVICEGETWDFDEVICEHANDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PDEVICE_OBJECT DeviceObject
    );


WDFDEVICE
__forceinline
WdfWdmDeviceGetWdfDeviceHandle(
    
    PDEVICE_OBJECT DeviceObject
    )
{
    return ((PFN_WDFWDMDEVICEGETWDFDEVICEHANDLE) WdfFunctions[WdfWdmDeviceGetWdfDeviceHandleTableIndex])(WdfDriverGlobals, DeviceObject);
}




typedef


PDEVICE_OBJECT
(*PFN_WDFDEVICEWDMGETDEVICEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


PDEVICE_OBJECT
__forceinline
WdfDeviceWdmGetDeviceObject(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEWDMGETDEVICEOBJECT) WdfFunctions[WdfDeviceWdmGetDeviceObjectTableIndex])(WdfDriverGlobals, Device);
}




typedef


PDEVICE_OBJECT
(*PFN_WDFDEVICEWDMGETATTACHEDDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


PDEVICE_OBJECT
__forceinline
WdfDeviceWdmGetAttachedDevice(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEWDMGETATTACHEDDEVICE) WdfFunctions[WdfDeviceWdmGetAttachedDeviceTableIndex])(WdfDriverGlobals, Device);
}




typedef


PDEVICE_OBJECT
(*PFN_WDFDEVICEWDMGETPHYSICALDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


PDEVICE_OBJECT
__forceinline
WdfDeviceWdmGetPhysicalDevice(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEWDMGETPHYSICALDEVICE) WdfFunctions[WdfDeviceWdmGetPhysicalDeviceTableIndex])(WdfDriverGlobals, Device);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEWDMDISPATCHPREPROCESSEDIRP)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PIRP Irp
    );



NTSTATUS
__forceinline
WdfDeviceWdmDispatchPreprocessedIrp(
    
    WDFDEVICE Device,
    
    PIRP Irp
    )
{
    return ((PFN_WDFDEVICEWDMDISPATCHPREPROCESSEDIRP) WdfFunctions[WdfDeviceWdmDispatchPreprocessedIrpTableIndex])(WdfDriverGlobals, Device, Irp);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEADDDEPENDENTUSAGEDEVICEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT DependentDevice
    );



NTSTATUS
__forceinline
WdfDeviceAddDependentUsageDeviceObject(
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT DependentDevice
    )
{
    return ((PFN_WDFDEVICEADDDEPENDENTUSAGEDEVICEOBJECT) WdfFunctions[WdfDeviceAddDependentUsageDeviceObjectTableIndex])(WdfDriverGlobals, Device, DependentDevice);
}




typedef


void
(*PFN_WDFDEVICEREMOVEDEPENDENTUSAGEDEVICEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT DependentDevice
    );


void
__forceinline
WdfDeviceRemoveDependentUsageDeviceObject(
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT DependentDevice
    )
{
    ((PFN_WDFDEVICEREMOVEDEPENDENTUSAGEDEVICEOBJECT) WdfFunctions[WdfDeviceRemoveDependentUsageDeviceObjectTableIndex])(WdfDriverGlobals, Device, DependentDevice);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEADDREMOVALRELATIONSPHYSICALDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT PhysicalDevice
    );



NTSTATUS
__forceinline
WdfDeviceAddRemovalRelationsPhysicalDevice(
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT PhysicalDevice
    )
{
    return ((PFN_WDFDEVICEADDREMOVALRELATIONSPHYSICALDEVICE) WdfFunctions[WdfDeviceAddRemovalRelationsPhysicalDeviceTableIndex])(WdfDriverGlobals, Device, PhysicalDevice);
}




typedef


void
(*PFN_WDFDEVICEREMOVEREMOVALRELATIONSPHYSICALDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT PhysicalDevice
    );


void
__forceinline
WdfDeviceRemoveRemovalRelationsPhysicalDevice(
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT PhysicalDevice
    )
{
    ((PFN_WDFDEVICEREMOVEREMOVALRELATIONSPHYSICALDEVICE) WdfFunctions[WdfDeviceRemoveRemovalRelationsPhysicalDeviceTableIndex])(WdfDriverGlobals, Device, PhysicalDevice);
}




typedef


void
(*PFN_WDFDEVICECLEARREMOVALRELATIONSDEVICES)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


void
__forceinline
WdfDeviceClearRemovalRelationsDevices(
    
    WDFDEVICE Device
    )
{
    ((PFN_WDFDEVICECLEARREMOVALRELATIONSDEVICES) WdfFunctions[WdfDeviceClearRemovalRelationsDevicesTableIndex])(WdfDriverGlobals, Device);
}




typedef


WDFDRIVER
(*PFN_WDFDEVICEGETDRIVER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


WDFDRIVER
__forceinline
WdfDeviceGetDriver(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETDRIVER) WdfFunctions[WdfDeviceGetDriverTableIndex])(WdfDriverGlobals, Device);
}




typedef



NTSTATUS
(*PFN_WDFDEVICERETRIEVEDEVICENAME)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    WDFSTRING String
    );



NTSTATUS
__forceinline
WdfDeviceRetrieveDeviceName(
    
    WDFDEVICE Device,
    
    WDFSTRING String
    )
{
    return ((PFN_WDFDEVICERETRIEVEDEVICENAME) WdfFunctions[WdfDeviceRetrieveDeviceNameTableIndex])(WdfDriverGlobals, Device, String);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEASSIGNMOFRESOURCENAME)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PCUNICODE_STRING MofResourceName
    );



NTSTATUS
__forceinline
WdfDeviceAssignMofResourceName(
    
    WDFDEVICE Device,
    
    PCUNICODE_STRING MofResourceName
    )
{
    return ((PFN_WDFDEVICEASSIGNMOFRESOURCENAME) WdfFunctions[WdfDeviceAssignMofResourceNameTableIndex])(WdfDriverGlobals, Device, MofResourceName);
}




typedef


WDFIOTARGET
(*PFN_WDFDEVICEGETIOTARGET)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


WDFIOTARGET
__forceinline
WdfDeviceGetIoTarget(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETIOTARGET) WdfFunctions[WdfDeviceGetIoTargetTableIndex])(WdfDriverGlobals, Device);
}




typedef


WDF_DEVICE_PNP_STATE
(*PFN_WDFDEVICEGETDEVICEPNPSTATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


WDF_DEVICE_PNP_STATE
__forceinline
WdfDeviceGetDevicePnpState(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETDEVICEPNPSTATE) WdfFunctions[WdfDeviceGetDevicePnpStateTableIndex])(WdfDriverGlobals, Device);
}




typedef


WDF_DEVICE_POWER_STATE
(*PFN_WDFDEVICEGETDEVICEPOWERSTATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


WDF_DEVICE_POWER_STATE
__forceinline
WdfDeviceGetDevicePowerState(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETDEVICEPOWERSTATE) WdfFunctions[WdfDeviceGetDevicePowerStateTableIndex])(WdfDriverGlobals, Device);
}




typedef


WDF_DEVICE_POWER_POLICY_STATE
(*PFN_WDFDEVICEGETDEVICEPOWERPOLICYSTATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


WDF_DEVICE_POWER_POLICY_STATE
__forceinline
WdfDeviceGetDevicePowerPolicyState(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETDEVICEPOWERPOLICYSTATE) WdfFunctions[WdfDeviceGetDevicePowerPolicyStateTableIndex])(WdfDriverGlobals, Device);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEASSIGNS0IDLESETTINGS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings
    );



NTSTATUS
__forceinline
WdfDeviceAssignS0IdleSettings(
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings
    )
{
    return ((PFN_WDFDEVICEASSIGNS0IDLESETTINGS) WdfFunctions[WdfDeviceAssignS0IdleSettingsTableIndex])(WdfDriverGlobals, Device, Settings);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEASSIGNSXWAKESETTINGS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
    );



NTSTATUS
__forceinline
WdfDeviceAssignSxWakeSettings(
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
    )
{
    return ((PFN_WDFDEVICEASSIGNSXWAKESETTINGS) WdfFunctions[WdfDeviceAssignSxWakeSettingsTableIndex])(WdfDriverGlobals, Device, Settings);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEOPENREGISTRYKEY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    ULONG DeviceInstanceKeyType,
    
    ACCESS_MASK DesiredAccess,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    );



NTSTATUS
__forceinline
WdfDeviceOpenRegistryKey(
    
    WDFDEVICE Device,
    
    ULONG DeviceInstanceKeyType,
    
    ACCESS_MASK DesiredAccess,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    )
{
    return ((PFN_WDFDEVICEOPENREGISTRYKEY) WdfFunctions[WdfDeviceOpenRegistryKeyTableIndex])(WdfDriverGlobals, Device, DeviceInstanceKeyType, DesiredAccess, KeyAttributes, Key);
}




typedef


void
(*PFN_WDFDEVICESETSPECIALFILESUPPORT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    WDF_SPECIAL_FILE_TYPE FileType,
    
    BOOLEAN FileTypeIsSupported
    );


void
__forceinline
WdfDeviceSetSpecialFileSupport(
    
    WDFDEVICE Device,
    
    WDF_SPECIAL_FILE_TYPE FileType,
    
    BOOLEAN FileTypeIsSupported
    )
{
    ((PFN_WDFDEVICESETSPECIALFILESUPPORT) WdfFunctions[WdfDeviceSetSpecialFileSupportTableIndex])(WdfDriverGlobals, Device, FileType, FileTypeIsSupported);
}




typedef


void
(*PFN_WDFDEVICESETCHARACTERISTICS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    ULONG DeviceCharacteristics
    );


void
__forceinline
WdfDeviceSetCharacteristics(
    
    WDFDEVICE Device,
    
    ULONG DeviceCharacteristics
    )
{
    ((PFN_WDFDEVICESETCHARACTERISTICS) WdfFunctions[WdfDeviceSetCharacteristicsTableIndex])(WdfDriverGlobals, Device, DeviceCharacteristics);
}




typedef


ULONG
(*PFN_WDFDEVICEGETCHARACTERISTICS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


ULONG
__forceinline
WdfDeviceGetCharacteristics(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETCHARACTERISTICS) WdfFunctions[WdfDeviceGetCharacteristicsTableIndex])(WdfDriverGlobals, Device);
}




typedef


ULONG
(*PFN_WDFDEVICEGETALIGNMENTREQUIREMENT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


ULONG
__forceinline
WdfDeviceGetAlignmentRequirement(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETALIGNMENTREQUIREMENT) WdfFunctions[WdfDeviceGetAlignmentRequirementTableIndex])(WdfDriverGlobals, Device);
}




typedef


void
(*PFN_WDFDEVICESETALIGNMENTREQUIREMENT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    ULONG AlignmentRequirement
    );


void
__forceinline
WdfDeviceSetAlignmentRequirement(
    
    WDFDEVICE Device,
    
    ULONG AlignmentRequirement
    )
{
    ((PFN_WDFDEVICESETALIGNMENTREQUIREMENT) WdfFunctions[WdfDeviceSetAlignmentRequirementTableIndex])(WdfDriverGlobals, Device, AlignmentRequirement);
}




typedef


void
(*PFN_WDFDEVICEINITFREE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit
    );


void
__forceinline
WdfDeviceInitFree(
    
    PWDFDEVICE_INIT DeviceInit
    )
{
    ((PFN_WDFDEVICEINITFREE) WdfFunctions[WdfDeviceInitFreeTableIndex])(WdfDriverGlobals, DeviceInit);
}




typedef


void
(*PFN_WDFDEVICEINITSETPNPPOWEREVENTCALLBACKS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_PNPPOWER_EVENT_CALLBACKS PnpPowerEventCallbacks
    );


void
__forceinline
WdfDeviceInitSetPnpPowerEventCallbacks(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_PNPPOWER_EVENT_CALLBACKS PnpPowerEventCallbacks
    )
{
    ((PFN_WDFDEVICEINITSETPNPPOWEREVENTCALLBACKS) WdfFunctions[WdfDeviceInitSetPnpPowerEventCallbacksTableIndex])(WdfDriverGlobals, DeviceInit, PnpPowerEventCallbacks);
}




typedef


void
(*PFN_WDFDEVICEINITSETPOWERPOLICYEVENTCALLBACKS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_POWER_POLICY_EVENT_CALLBACKS PowerPolicyEventCallbacks
    );


void
__forceinline
WdfDeviceInitSetPowerPolicyEventCallbacks(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_POWER_POLICY_EVENT_CALLBACKS PowerPolicyEventCallbacks
    )
{
    ((PFN_WDFDEVICEINITSETPOWERPOLICYEVENTCALLBACKS) WdfFunctions[WdfDeviceInitSetPowerPolicyEventCallbacksTableIndex])(WdfDriverGlobals, DeviceInit, PowerPolicyEventCallbacks);
}




typedef


void
(*PFN_WDFDEVICEINITSETPOWERPOLICYOWNERSHIP)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    BOOLEAN IsPowerPolicyOwner
    );


void
__forceinline
WdfDeviceInitSetPowerPolicyOwnership(
    
    PWDFDEVICE_INIT DeviceInit,
    
    BOOLEAN IsPowerPolicyOwner
    )
{
    ((PFN_WDFDEVICEINITSETPOWERPOLICYOWNERSHIP) WdfFunctions[WdfDeviceInitSetPowerPolicyOwnershipTableIndex])(WdfDriverGlobals, DeviceInit, IsPowerPolicyOwner);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEINITREGISTERPNPSTATECHANGECALLBACK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    WDF_DEVICE_PNP_STATE PnpState,
    
    PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION EvtDevicePnpStateChange,
    
    ULONG CallbackTypes
    );



NTSTATUS
__forceinline
WdfDeviceInitRegisterPnpStateChangeCallback(
    
    PWDFDEVICE_INIT DeviceInit,
    
    WDF_DEVICE_PNP_STATE PnpState,
    
    PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION EvtDevicePnpStateChange,
    
    ULONG CallbackTypes
    )
{
    return ((PFN_WDFDEVICEINITREGISTERPNPSTATECHANGECALLBACK) WdfFunctions[WdfDeviceInitRegisterPnpStateChangeCallbackTableIndex])(WdfDriverGlobals, DeviceInit, PnpState, EvtDevicePnpStateChange, CallbackTypes);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEINITREGISTERPOWERSTATECHANGECALLBACK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    WDF_DEVICE_POWER_STATE PowerState,
    
    PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION EvtDevicePowerStateChange,
    
    ULONG CallbackTypes
    );



NTSTATUS
__forceinline
WdfDeviceInitRegisterPowerStateChangeCallback(
    
    PWDFDEVICE_INIT DeviceInit,
    
    WDF_DEVICE_POWER_STATE PowerState,
    
    PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION EvtDevicePowerStateChange,
    
    ULONG CallbackTypes
    )
{
    return ((PFN_WDFDEVICEINITREGISTERPOWERSTATECHANGECALLBACK) WdfFunctions[WdfDeviceInitRegisterPowerStateChangeCallbackTableIndex])(WdfDriverGlobals, DeviceInit, PowerState, EvtDevicePowerStateChange, CallbackTypes);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEINITREGISTERPOWERPOLICYSTATECHANGECALLBACK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    WDF_DEVICE_POWER_POLICY_STATE PowerPolicyState,
    
    PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION EvtDevicePowerPolicyStateChange,
    
    ULONG CallbackTypes
    );



NTSTATUS
__forceinline
WdfDeviceInitRegisterPowerPolicyStateChangeCallback(
    
    PWDFDEVICE_INIT DeviceInit,
    
    WDF_DEVICE_POWER_POLICY_STATE PowerPolicyState,
    
    PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION EvtDevicePowerPolicyStateChange,
    
    ULONG CallbackTypes
    )
{
    return ((PFN_WDFDEVICEINITREGISTERPOWERPOLICYSTATECHANGECALLBACK) WdfFunctions[WdfDeviceInitRegisterPowerPolicyStateChangeCallbackTableIndex])(WdfDriverGlobals, DeviceInit, PowerPolicyState, EvtDevicePowerPolicyStateChange, CallbackTypes);
}




typedef


void
(*PFN_WDFDEVICEINITSETIOTYPE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    WDF_DEVICE_IO_TYPE IoType
    );


void
__forceinline
WdfDeviceInitSetIoType(
    
    PWDFDEVICE_INIT DeviceInit,
    
    WDF_DEVICE_IO_TYPE IoType
    )
{
    ((PFN_WDFDEVICEINITSETIOTYPE) WdfFunctions[WdfDeviceInitSetIoTypeTableIndex])(WdfDriverGlobals, DeviceInit, IoType);
}




typedef


void
(*PFN_WDFDEVICEINITSETEXCLUSIVE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    BOOLEAN IsExclusive
    );


void
__forceinline
WdfDeviceInitSetExclusive(
    
    PWDFDEVICE_INIT DeviceInit,
    
    BOOLEAN IsExclusive
    )
{
    ((PFN_WDFDEVICEINITSETEXCLUSIVE) WdfFunctions[WdfDeviceInitSetExclusiveTableIndex])(WdfDriverGlobals, DeviceInit, IsExclusive);
}




typedef


void
(*PFN_WDFDEVICEINITSETPOWERNOTPAGEABLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit
    );


void
__forceinline
WdfDeviceInitSetPowerNotPageable(
    
    PWDFDEVICE_INIT DeviceInit
    )
{
    ((PFN_WDFDEVICEINITSETPOWERNOTPAGEABLE) WdfFunctions[WdfDeviceInitSetPowerNotPageableTableIndex])(WdfDriverGlobals, DeviceInit);
}




typedef


void
(*PFN_WDFDEVICEINITSETPOWERPAGEABLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit
    );


void
__forceinline
WdfDeviceInitSetPowerPageable(
    
    PWDFDEVICE_INIT DeviceInit
    )
{
    ((PFN_WDFDEVICEINITSETPOWERPAGEABLE) WdfFunctions[WdfDeviceInitSetPowerPageableTableIndex])(WdfDriverGlobals, DeviceInit);
}




typedef


void
(*PFN_WDFDEVICEINITSETPOWERINRUSH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit
    );


void
__forceinline
WdfDeviceInitSetPowerInrush(
    
    PWDFDEVICE_INIT DeviceInit
    )
{
    ((PFN_WDFDEVICEINITSETPOWERINRUSH) WdfFunctions[WdfDeviceInitSetPowerInrushTableIndex])(WdfDriverGlobals, DeviceInit);
}




typedef


void
(*PFN_WDFDEVICEINITSETDEVICETYPE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    ULONG DeviceType
    );


void
__forceinline
WdfDeviceInitSetDeviceType(
    
    PWDFDEVICE_INIT DeviceInit,
    
    ULONG DeviceType
    )
{
    ((PFN_WDFDEVICEINITSETDEVICETYPE) WdfFunctions[WdfDeviceInitSetDeviceTypeTableIndex])(WdfDriverGlobals, DeviceInit, DeviceType);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEINITASSIGNNAME)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING DeviceName
    );



NTSTATUS
__forceinline
WdfDeviceInitAssignName(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING DeviceName
    )
{
    return ((PFN_WDFDEVICEINITASSIGNNAME) WdfFunctions[WdfDeviceInitAssignNameTableIndex])(WdfDriverGlobals, DeviceInit, DeviceName);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEINITASSIGNSDDLSTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING SDDLString
    );



NTSTATUS
__forceinline
WdfDeviceInitAssignSDDLString(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING SDDLString
    )
{
    return ((PFN_WDFDEVICEINITASSIGNSDDLSTRING) WdfFunctions[WdfDeviceInitAssignSDDLStringTableIndex])(WdfDriverGlobals, DeviceInit, SDDLString);
}




typedef


void
(*PFN_WDFDEVICEINITSETDEVICECLASS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    const GUID* DeviceClassGuid
    );


void
__forceinline
WdfDeviceInitSetDeviceClass(
    
    PWDFDEVICE_INIT DeviceInit,
    
    const GUID* DeviceClassGuid
    )
{
    ((PFN_WDFDEVICEINITSETDEVICECLASS) WdfFunctions[WdfDeviceInitSetDeviceClassTableIndex])(WdfDriverGlobals, DeviceInit, DeviceClassGuid);
}




typedef


void
(*PFN_WDFDEVICEINITSETCHARACTERISTICS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    ULONG DeviceCharacteristics,
    
    BOOLEAN OrInValues
    );


void
__forceinline
WdfDeviceInitSetCharacteristics(
    
    PWDFDEVICE_INIT DeviceInit,
    
    ULONG DeviceCharacteristics,
    
    BOOLEAN OrInValues
    )
{
    ((PFN_WDFDEVICEINITSETCHARACTERISTICS) WdfFunctions[WdfDeviceInitSetCharacteristicsTableIndex])(WdfDriverGlobals, DeviceInit, DeviceCharacteristics, OrInValues);
}




typedef


void
(*PFN_WDFDEVICEINITSETFILEOBJECTCONFIG)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_FILEOBJECT_CONFIG FileObjectConfig,
    
    PWDF_OBJECT_ATTRIBUTES FileObjectAttributes
    );


void
__forceinline
WdfDeviceInitSetFileObjectConfig(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_FILEOBJECT_CONFIG FileObjectConfig,
    
    PWDF_OBJECT_ATTRIBUTES FileObjectAttributes
    )
{
    ((PFN_WDFDEVICEINITSETFILEOBJECTCONFIG) WdfFunctions[WdfDeviceInitSetFileObjectConfigTableIndex])(WdfDriverGlobals, DeviceInit, FileObjectConfig, FileObjectAttributes);
}




typedef


void
(*PFN_WDFDEVICEINITSETREQUESTATTRIBUTES)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_OBJECT_ATTRIBUTES RequestAttributes
    );


void
__forceinline
WdfDeviceInitSetRequestAttributes(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_OBJECT_ATTRIBUTES RequestAttributes
    )
{
    ((PFN_WDFDEVICEINITSETREQUESTATTRIBUTES) WdfFunctions[WdfDeviceInitSetRequestAttributesTableIndex])(WdfDriverGlobals, DeviceInit, RequestAttributes);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEINITASSIGNWDMIRPPREPROCESSCALLBACK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PFN_WDFDEVICE_WDM_IRP_PREPROCESS EvtDeviceWdmIrpPreprocess,
    
    UCHAR MajorFunction,
    
    
    PUCHAR MinorFunctions,
    
    ULONG NumMinorFunctions
    );



NTSTATUS
__forceinline
WdfDeviceInitAssignWdmIrpPreprocessCallback(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PFN_WDFDEVICE_WDM_IRP_PREPROCESS EvtDeviceWdmIrpPreprocess,
    
    UCHAR MajorFunction,
    
    
    PUCHAR MinorFunctions,
    
    ULONG NumMinorFunctions
    )
{
    return ((PFN_WDFDEVICEINITASSIGNWDMIRPPREPROCESSCALLBACK) WdfFunctions[WdfDeviceInitAssignWdmIrpPreprocessCallbackTableIndex])(WdfDriverGlobals, DeviceInit, EvtDeviceWdmIrpPreprocess, MajorFunction, MinorFunctions, NumMinorFunctions);
}




typedef


void
(*PFN_WDFDEVICEINITSETIOINCALLERCONTEXTCALLBACK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PFN_WDF_IO_IN_CALLER_CONTEXT EvtIoInCallerContext
    );


void
__forceinline
WdfDeviceInitSetIoInCallerContextCallback(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PFN_WDF_IO_IN_CALLER_CONTEXT EvtIoInCallerContext
    )
{
    ((PFN_WDFDEVICEINITSETIOINCALLERCONTEXTCALLBACK) WdfFunctions[WdfDeviceInitSetIoInCallerContextCallbackTableIndex])(WdfDriverGlobals, DeviceInit, EvtIoInCallerContext);
}




typedef



NTSTATUS
(*PFN_WDFDEVICECREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT* DeviceInit,
    
    PWDF_OBJECT_ATTRIBUTES DeviceAttributes,
    
    WDFDEVICE* Device
    );



NTSTATUS
__forceinline
WdfDeviceCreate(
    
    PWDFDEVICE_INIT* DeviceInit,
    
    PWDF_OBJECT_ATTRIBUTES DeviceAttributes,
    
    WDFDEVICE* Device
    )
{
    return ((PFN_WDFDEVICECREATE) WdfFunctions[WdfDeviceCreateTableIndex])(WdfDriverGlobals, DeviceInit, DeviceAttributes, Device);
}




typedef


void
(*PFN_WDFDEVICESETSTATICSTOPREMOVE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    BOOLEAN Stoppable
    );


void
__forceinline
WdfDeviceSetStaticStopRemove(
    
    WDFDEVICE Device,
    
    BOOLEAN Stoppable
    )
{
    ((PFN_WDFDEVICESETSTATICSTOPREMOVE) WdfFunctions[WdfDeviceSetStaticStopRemoveTableIndex])(WdfDriverGlobals, Device, Stoppable);
}




typedef



NTSTATUS
(*PFN_WDFDEVICECREATEDEVICEINTERFACE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    const GUID* InterfaceClassGUID,
    
    PCUNICODE_STRING ReferenceString
    );



NTSTATUS
__forceinline
WdfDeviceCreateDeviceInterface(
    
    WDFDEVICE Device,
    
    const GUID* InterfaceClassGUID,
    
    PCUNICODE_STRING ReferenceString
    )
{
    return ((PFN_WDFDEVICECREATEDEVICEINTERFACE) WdfFunctions[WdfDeviceCreateDeviceInterfaceTableIndex])(WdfDriverGlobals, Device, InterfaceClassGUID, ReferenceString);
}




typedef


void
(*PFN_WDFDEVICESETDEVICEINTERFACESTATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    const GUID* InterfaceClassGUID,
    
    PCUNICODE_STRING ReferenceString,
    
    BOOLEAN IsInterfaceEnabled
    );


void
__forceinline
WdfDeviceSetDeviceInterfaceState(
    
    WDFDEVICE Device,
    
    const GUID* InterfaceClassGUID,
    
    PCUNICODE_STRING ReferenceString,
    
    BOOLEAN IsInterfaceEnabled
    )
{
    ((PFN_WDFDEVICESETDEVICEINTERFACESTATE) WdfFunctions[WdfDeviceSetDeviceInterfaceStateTableIndex])(WdfDriverGlobals, Device, InterfaceClassGUID, ReferenceString, IsInterfaceEnabled);
}




typedef



NTSTATUS
(*PFN_WDFDEVICERETRIEVEDEVICEINTERFACESTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    const GUID* InterfaceClassGUID,
    
    PCUNICODE_STRING ReferenceString,
    
    WDFSTRING String
    );



NTSTATUS
__forceinline
WdfDeviceRetrieveDeviceInterfaceString(
    
    WDFDEVICE Device,
    
    const GUID* InterfaceClassGUID,
    
    PCUNICODE_STRING ReferenceString,
    
    WDFSTRING String
    )
{
    return ((PFN_WDFDEVICERETRIEVEDEVICEINTERFACESTRING) WdfFunctions[WdfDeviceRetrieveDeviceInterfaceStringTableIndex])(WdfDriverGlobals, Device, InterfaceClassGUID, ReferenceString, String);
}




typedef



NTSTATUS
(*PFN_WDFDEVICECREATESYMBOLICLINK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PCUNICODE_STRING SymbolicLinkName
    );



NTSTATUS
__forceinline
WdfDeviceCreateSymbolicLink(
    
    WDFDEVICE Device,
    
    PCUNICODE_STRING SymbolicLinkName
    )
{
    return ((PFN_WDFDEVICECREATESYMBOLICLINK) WdfFunctions[WdfDeviceCreateSymbolicLinkTableIndex])(WdfDriverGlobals, Device, SymbolicLinkName);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEQUERYPROPERTY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    ULONG BufferLength,
    
    PVOID PropertyBuffer,
    
    PULONG ResultLength
    );



NTSTATUS
__forceinline
WdfDeviceQueryProperty(
    
    WDFDEVICE Device,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    ULONG BufferLength,
    
    PVOID PropertyBuffer,
    
    PULONG ResultLength
    )
{
    return ((PFN_WDFDEVICEQUERYPROPERTY) WdfFunctions[WdfDeviceQueryPropertyTableIndex])(WdfDriverGlobals, Device, DeviceProperty, BufferLength, PropertyBuffer, ResultLength);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEALLOCANDQUERYPROPERTY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    
    WDFMEMORY* PropertyMemory
    );



NTSTATUS
__forceinline
WdfDeviceAllocAndQueryProperty(
    
    WDFDEVICE Device,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    
    WDFMEMORY* PropertyMemory
    )
{
    return ((PFN_WDFDEVICEALLOCANDQUERYPROPERTY) WdfFunctions[WdfDeviceAllocAndQueryPropertyTableIndex])(WdfDriverGlobals, Device, DeviceProperty, PoolType, PropertyMemoryAttributes, PropertyMemory);
}




typedef


void
(*PFN_WDFDEVICESETPNPCAPABILITIES)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_PNP_CAPABILITIES PnpCapabilities
    );


void
__forceinline
WdfDeviceSetPnpCapabilities(
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_PNP_CAPABILITIES PnpCapabilities
    )
{
    ((PFN_WDFDEVICESETPNPCAPABILITIES) WdfFunctions[WdfDeviceSetPnpCapabilitiesTableIndex])(WdfDriverGlobals, Device, PnpCapabilities);
}




typedef


void
(*PFN_WDFDEVICESETPOWERCAPABILITIES)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_POWER_CAPABILITIES PowerCapabilities
    );


void
__forceinline
WdfDeviceSetPowerCapabilities(
    
    WDFDEVICE Device,
    
    PWDF_DEVICE_POWER_CAPABILITIES PowerCapabilities
    )
{
    ((PFN_WDFDEVICESETPOWERCAPABILITIES) WdfFunctions[WdfDeviceSetPowerCapabilitiesTableIndex])(WdfDriverGlobals, Device, PowerCapabilities);
}




typedef


void
(*PFN_WDFDEVICESETBUSINFORMATIONFORCHILDREN)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PPNP_BUS_INFORMATION BusInformation
    );


void
__forceinline
WdfDeviceSetBusInformationForChildren(
    
    WDFDEVICE Device,
    
    PPNP_BUS_INFORMATION BusInformation
    )
{
    ((PFN_WDFDEVICESETBUSINFORMATIONFORCHILDREN) WdfFunctions[WdfDeviceSetBusInformationForChildrenTableIndex])(WdfDriverGlobals, Device, BusInformation);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEINDICATEWAKESTATUS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    NTSTATUS WaitWakeStatus
    );



NTSTATUS
__forceinline
WdfDeviceIndicateWakeStatus(
    
    WDFDEVICE Device,
    
    NTSTATUS WaitWakeStatus
    )
{
    return ((PFN_WDFDEVICEINDICATEWAKESTATUS) WdfFunctions[WdfDeviceIndicateWakeStatusTableIndex])(WdfDriverGlobals, Device, WaitWakeStatus);
}




typedef


void
(*PFN_WDFDEVICESETFAILED)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    WDF_DEVICE_FAILED_ACTION FailedAction
    );


void
__forceinline
WdfDeviceSetFailed(
    
    WDFDEVICE Device,
    
    WDF_DEVICE_FAILED_ACTION FailedAction
    )
{
    ((PFN_WDFDEVICESETFAILED) WdfFunctions[WdfDeviceSetFailedTableIndex])(WdfDriverGlobals, Device, FailedAction);
}




typedef




NTSTATUS
(*PFN_WDFDEVICESTOPIDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    BOOLEAN WaitForD0
    );




NTSTATUS
__forceinline
WdfDeviceStopIdle(
    
    WDFDEVICE Device,
    
    BOOLEAN WaitForD0
    )
{
    return ((PFN_WDFDEVICESTOPIDLE) WdfFunctions[WdfDeviceStopIdleTableIndex])(WdfDriverGlobals, Device, WaitForD0);
}




typedef


void
(*PFN_WDFDEVICERESUMEIDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


void
__forceinline
WdfDeviceResumeIdle(
    
    WDFDEVICE Device
    )
{
    ((PFN_WDFDEVICERESUMEIDLE) WdfFunctions[WdfDeviceResumeIdleTableIndex])(WdfDriverGlobals, Device);
}




typedef


WDFFILEOBJECT
(*PFN_WDFDEVICEGETFILEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PFILE_OBJECT FileObject
    );


WDFFILEOBJECT
__forceinline
WdfDeviceGetFileObject(
    
    WDFDEVICE Device,
    
    PFILE_OBJECT FileObject
    )
{
    return ((PFN_WDFDEVICEGETFILEOBJECT) WdfFunctions[WdfDeviceGetFileObjectTableIndex])(WdfDriverGlobals, Device, FileObject);
}




typedef



NTSTATUS
(*PFN_WDFDEVICEENQUEUEREQUEST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    WDFREQUEST Request
    );



NTSTATUS
__forceinline
WdfDeviceEnqueueRequest(
    
    WDFDEVICE Device,
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFDEVICEENQUEUEREQUEST) WdfFunctions[WdfDeviceEnqueueRequestTableIndex])(WdfDriverGlobals, Device, Request);
}




typedef


WDFQUEUE
(*PFN_WDFDEVICEGETDEFAULTQUEUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


WDFQUEUE
__forceinline
WdfDeviceGetDefaultQueue(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETDEFAULTQUEUE) WdfFunctions[WdfDeviceGetDefaultQueueTableIndex])(WdfDriverGlobals, Device);
}




typedef



NTSTATUS
(*PFN_WDFDEVICECONFIGUREREQUESTDISPATCHING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    WDFQUEUE Queue,
    
    
    WDF_REQUEST_TYPE RequestType
    );



NTSTATUS
__forceinline
WdfDeviceConfigureRequestDispatching(
    
    WDFDEVICE Device,
    
    WDFQUEUE Queue,
    
    
    WDF_REQUEST_TYPE RequestType
    )
{
    return ((PFN_WDFDEVICECONFIGUREREQUESTDISPATCHING) WdfFunctions[WdfDeviceConfigureRequestDispatchingTableIndex])(WdfDriverGlobals, Device, Queue, RequestType);
}




typedef


POWER_ACTION
(*PFN_WDFDEVICEGETSYSTEMPOWERACTION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


POWER_ACTION
__forceinline
WdfDeviceGetSystemPowerAction(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFDEVICEGETSYSTEMPOWERACTION) WdfFunctions[WdfDeviceGetSystemPowerActionTableIndex])(WdfDriverGlobals, Device);
}



#line 3521 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdevice.h"


#line 3524 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdevice.h"


#line 75 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcollection.h"


































typedef



NTSTATUS
(*PFN_WDFCOLLECTIONCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES CollectionAttributes,
    
    WDFCOLLECTION* Collection
    );



NTSTATUS
__forceinline
WdfCollectionCreate(
    
    PWDF_OBJECT_ATTRIBUTES CollectionAttributes,
    
    WDFCOLLECTION* Collection
    )
{
    return ((PFN_WDFCOLLECTIONCREATE) WdfFunctions[WdfCollectionCreateTableIndex])(WdfDriverGlobals, CollectionAttributes, Collection);
}




typedef


ULONG
(*PFN_WDFCOLLECTIONGETCOUNT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOLLECTION Collection
    );


ULONG
__forceinline
WdfCollectionGetCount(
    
    WDFCOLLECTION Collection
    )
{
    return ((PFN_WDFCOLLECTIONGETCOUNT) WdfFunctions[WdfCollectionGetCountTableIndex])(WdfDriverGlobals, Collection);
}




typedef



NTSTATUS
(*PFN_WDFCOLLECTIONADD)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOLLECTION Collection,
    
    WDFOBJECT Object
    );



NTSTATUS
__forceinline
WdfCollectionAdd(
    
    WDFCOLLECTION Collection,
    
    WDFOBJECT Object
    )
{
    return ((PFN_WDFCOLLECTIONADD) WdfFunctions[WdfCollectionAddTableIndex])(WdfDriverGlobals, Collection, Object);
}




typedef


void
(*PFN_WDFCOLLECTIONREMOVE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOLLECTION Collection,
    
    WDFOBJECT Item
    );


void
__forceinline
WdfCollectionRemove(
    
    WDFCOLLECTION Collection,
    
    WDFOBJECT Item
    )
{
    ((PFN_WDFCOLLECTIONREMOVE) WdfFunctions[WdfCollectionRemoveTableIndex])(WdfDriverGlobals, Collection, Item);
}




typedef


void
(*PFN_WDFCOLLECTIONREMOVEITEM)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOLLECTION Collection,
    
    ULONG Index
    );


void
__forceinline
WdfCollectionRemoveItem(
    
    WDFCOLLECTION Collection,
    
    ULONG Index
    )
{
    ((PFN_WDFCOLLECTIONREMOVEITEM) WdfFunctions[WdfCollectionRemoveItemTableIndex])(WdfDriverGlobals, Collection, Index);
}




typedef


WDFOBJECT
(*PFN_WDFCOLLECTIONGETITEM)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOLLECTION Collection,
    
    ULONG Index
    );


WDFOBJECT
__forceinline
WdfCollectionGetItem(
    
    WDFCOLLECTION Collection,
    
    ULONG Index
    )
{
    return ((PFN_WDFCOLLECTIONGETITEM) WdfFunctions[WdfCollectionGetItemTableIndex])(WdfDriverGlobals, Collection, Index);
}




typedef


WDFOBJECT
(*PFN_WDFCOLLECTIONGETFIRSTITEM)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOLLECTION Collection
    );


WDFOBJECT
__forceinline
WdfCollectionGetFirstItem(
    
    WDFCOLLECTION Collection
    )
{
    return ((PFN_WDFCOLLECTIONGETFIRSTITEM) WdfFunctions[WdfCollectionGetFirstItemTableIndex])(WdfDriverGlobals, Collection);
}




typedef


WDFOBJECT
(*PFN_WDFCOLLECTIONGETLASTITEM)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOLLECTION Collection
    );


WDFOBJECT
__forceinline
WdfCollectionGetLastItem(
    
    WDFCOLLECTION Collection
    )
{
    return ((PFN_WDFCOLLECTIONGETLASTITEM) WdfFunctions[WdfCollectionGetLastItemTableIndex])(WdfDriverGlobals, Collection);
}



#line 259 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcollection.h"


#line 262 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcollection.h"

#line 76 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdpc.h"
































typedef



void
EVT_WDF_DPC(
    
    WDFDPC Dpc
    );

typedef EVT_WDF_DPC *PFN_WDF_DPC;

typedef struct _WDF_DPC_CONFIG {
    ULONG       Size;
    PFN_WDF_DPC EvtDpcFunc;

    
    
    
    
    
    
    
    BOOLEAN     AutomaticSerialization;

} WDF_DPC_CONFIG, *PWDF_DPC_CONFIG;

void
__forceinline
WDF_DPC_CONFIG_INIT(
     PWDF_DPC_CONFIG Config,
      PFN_WDF_DPC     EvtDpcFunc
    )
{
    memset((Config),0,(sizeof(WDF_DPC_CONFIG)));
    Config->Size = sizeof(WDF_DPC_CONFIG);
    Config->EvtDpcFunc = EvtDpcFunc;

    Config->AutomaticSerialization = 1;
}




typedef



NTSTATUS
(*PFN_WDFDPCCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_DPC_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFDPC* Dpc
    );



NTSTATUS
__forceinline
WdfDpcCreate(
    
    PWDF_DPC_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFDPC* Dpc
    )
{
    return ((PFN_WDFDPCCREATE) WdfFunctions[WdfDpcCreateTableIndex])(WdfDriverGlobals, Config, Attributes, Dpc);
}




typedef


BOOLEAN
(*PFN_WDFDPCENQUEUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDPC Dpc
    );


BOOLEAN
__forceinline
WdfDpcEnqueue(
    
    WDFDPC Dpc
    )
{
    return ((PFN_WDFDPCENQUEUE) WdfFunctions[WdfDpcEnqueueTableIndex])(WdfDriverGlobals, Dpc);
}




typedef



BOOLEAN
(*PFN_WDFDPCCANCEL)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDPC Dpc,
    
    BOOLEAN Wait
    );



BOOLEAN
__forceinline
WdfDpcCancel(
    
    WDFDPC Dpc,
    
    BOOLEAN Wait
    )
{
    return ((PFN_WDFDPCCANCEL) WdfFunctions[WdfDpcCancelTableIndex])(WdfDriverGlobals, Dpc, Wait);
}




typedef


WDFOBJECT
(*PFN_WDFDPCGETPARENTOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDPC Dpc
    );


WDFOBJECT
__forceinline
WdfDpcGetParentObject(
    
    WDFDPC Dpc
    )
{
    return ((PFN_WDFDPCGETPARENTOBJECT) WdfFunctions[WdfDpcGetParentObjectTableIndex])(WdfDriverGlobals, Dpc);
}




typedef


PKDPC
(*PFN_WDFDPCWDMGETDPC)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDPC Dpc
    );


PKDPC
__forceinline
WdfDpcWdmGetDpc(
    
    WDFDPC Dpc
    )
{
    return ((PFN_WDFDPCWDMGETDPC) WdfFunctions[WdfDpcWdmGetDpcTableIndex])(WdfDriverGlobals, Dpc);
}



#line 218 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdpc.h"


#line 221 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfdpc.h"

#line 77 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdftimer.h"
































typedef



void
EVT_WDF_TIMER(
    
    WDFTIMER Timer
    );

typedef EVT_WDF_TIMER *PFN_WDF_TIMER;

typedef struct _WDF_TIMER_CONFIG {
    ULONG Size;
    PFN_WDF_TIMER EvtTimerFunc;

    ULONG Period;

    
    
    
    
    
    
    
    BOOLEAN AutomaticSerialization;

    
    
    
    ULONG TolerableDelay;

} WDF_TIMER_CONFIG, *PWDF_TIMER_CONFIG;

void
__forceinline
WDF_TIMER_CONFIG_INIT(
     PWDF_TIMER_CONFIG Config,
      PFN_WDF_TIMER     EvtTimerFunc
    )
{
    memset((Config),0,(sizeof(WDF_TIMER_CONFIG)));
    Config->Size = sizeof(WDF_TIMER_CONFIG);
    Config->EvtTimerFunc = EvtTimerFunc;
    Config->Period = 0;
    Config->AutomaticSerialization = 1;
    Config->TolerableDelay = 0;
}

void
__forceinline
WDF_TIMER_CONFIG_INIT_PERIODIC(
     PWDF_TIMER_CONFIG Config,
      PFN_WDF_TIMER     EvtTimerFunc,
      LONG             Period
    )
{
    memset((Config),0,(sizeof(WDF_TIMER_CONFIG)));
    Config->Size = sizeof(WDF_TIMER_CONFIG);
    Config->EvtTimerFunc = EvtTimerFunc;
    Config->Period = Period;
    Config->AutomaticSerialization = 1;
    Config->TolerableDelay = 0;
}





typedef



NTSTATUS
(*PFN_WDFTIMERCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_TIMER_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFTIMER* Timer
    );



NTSTATUS
__forceinline
WdfTimerCreate(
    
    PWDF_TIMER_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFTIMER* Timer
    )
{
    return ((PFN_WDFTIMERCREATE) WdfFunctions[WdfTimerCreateTableIndex])(WdfDriverGlobals, Config, Attributes, Timer);
}




typedef


BOOLEAN
(*PFN_WDFTIMERSTART)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFTIMER Timer,
    
    LONGLONG DueTime
    );


BOOLEAN
__forceinline
WdfTimerStart(
    
    WDFTIMER Timer,
    
    LONGLONG DueTime
    )
{
    return ((PFN_WDFTIMERSTART) WdfFunctions[WdfTimerStartTableIndex])(WdfDriverGlobals, Timer, DueTime);
}




typedef



BOOLEAN
(*PFN_WDFTIMERSTOP)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFTIMER Timer,
    
    BOOLEAN Wait
    );



BOOLEAN
__forceinline
WdfTimerStop(
    
    WDFTIMER Timer,
    
    BOOLEAN Wait
    )
{
    return ((PFN_WDFTIMERSTOP) WdfFunctions[WdfTimerStopTableIndex])(WdfDriverGlobals, Timer, Wait);
}




typedef


WDFOBJECT
(*PFN_WDFTIMERGETPARENTOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFTIMER Timer
    );


WDFOBJECT
__forceinline
WdfTimerGetParentObject(
    
    WDFTIMER Timer
    )
{
    return ((PFN_WDFTIMERGETPARENTOBJECT) WdfFunctions[WdfTimerGetParentObjectTableIndex])(WdfDriverGlobals, Timer);
}



#line 222 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdftimer.h"


#line 225 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdftimer.h"

#line 78 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfworkitem.h"
































typedef



void
EVT_WDF_WORKITEM(
    
    WDFWORKITEM WorkItem
    );

typedef EVT_WDF_WORKITEM *PFN_WDF_WORKITEM;

typedef struct _WDF_WORKITEM_CONFIG {

    ULONG Size;

    PFN_WDF_WORKITEM EvtWorkItemFunc;

    
    
    
    
    
    
    
    BOOLEAN AutomaticSerialization;

} WDF_WORKITEM_CONFIG, *PWDF_WORKITEM_CONFIG;


void
__forceinline
WDF_WORKITEM_CONFIG_INIT(
     PWDF_WORKITEM_CONFIG Config,
     PFN_WDF_WORKITEM     EvtWorkItemFunc
    )
{
    memset((Config),0,(sizeof(WDF_WORKITEM_CONFIG)));
    Config->Size = sizeof(WDF_WORKITEM_CONFIG);
    Config->EvtWorkItemFunc = EvtWorkItemFunc;

    Config->AutomaticSerialization = 1;
}





typedef



NTSTATUS
(*PFN_WDFWORKITEMCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_WORKITEM_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFWORKITEM* WorkItem
    );



NTSTATUS
__forceinline
WdfWorkItemCreate(
    
    PWDF_WORKITEM_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFWORKITEM* WorkItem
    )
{
    return ((PFN_WDFWORKITEMCREATE) WdfFunctions[WdfWorkItemCreateTableIndex])(WdfDriverGlobals, Config, Attributes, WorkItem);
}




typedef


void
(*PFN_WDFWORKITEMENQUEUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWORKITEM WorkItem
    );


void
__forceinline
WdfWorkItemEnqueue(
    
    WDFWORKITEM WorkItem
    )
{
    ((PFN_WDFWORKITEMENQUEUE) WdfFunctions[WdfWorkItemEnqueueTableIndex])(WdfDriverGlobals, WorkItem);
}




typedef


WDFOBJECT
(*PFN_WDFWORKITEMGETPARENTOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWORKITEM WorkItem
    );


WDFOBJECT
__forceinline
WdfWorkItemGetParentObject(
    
    WDFWORKITEM WorkItem
    )
{
    return ((PFN_WDFWORKITEMGETPARENTOBJECT) WdfFunctions[WdfWorkItemGetParentObjectTableIndex])(WdfDriverGlobals, WorkItem);
}




typedef


void
(*PFN_WDFWORKITEMFLUSH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWORKITEM WorkItem
    );


void
__forceinline
WdfWorkItemFlush(
    
    WDFWORKITEM WorkItem
    )
{
    ((PFN_WDFWORKITEMFLUSH) WdfFunctions[WdfWorkItemFlushTableIndex])(WdfDriverGlobals, WorkItem);
}



#line 191 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfworkitem.h"


#line 194 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfworkitem.h"

#line 79 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfinterrupt.h"





























typedef enum _WDF_INTERRUPT_POLARITY {
    WdfInterruptPolarityUnknown = 0,
    WdfInterruptActiveHigh,
    WdfInterruptActiveLow,
} WDF_INTERRUPT_POLARITY, *PWDF_INTERRUPT_POLARITY;

typedef enum _WDF_INTERRUPT_POLICY {
    WdfIrqPolicyMachineDefault = 0,
    WdfIrqPolicyAllCloseProcessors,
    WdfIrqPolicyOneCloseProcessor,
    WdfIrqPolicyAllProcessorsInMachine,
    WdfIrqPolicySpecifiedProcessors,
    WdfIrqPolicySpreadMessagesAcrossAllProcessors,
} WDF_INTERRUPT_POLICY, *PWDF_INTERRUPT_POLICY;

typedef enum _WDF_INTERRUPT_PRIORITY {
    WdfIrqPriorityUndefined = 0,
    WdfIrqPriorityLow,
    WdfIrqPriorityNormal,
    WdfIrqPriorityHigh,
} WDF_INTERRUPT_PRIORITY, *PWDF_INTERRUPT_PRIORITY;







typedef



BOOLEAN
EVT_WDF_INTERRUPT_ISR(
    
    WDFINTERRUPT Interrupt,
    
    ULONG MessageID
    );

typedef EVT_WDF_INTERRUPT_ISR *PFN_WDF_INTERRUPT_ISR;





typedef



BOOLEAN
EVT_WDF_INTERRUPT_SYNCHRONIZE(
    
    WDFINTERRUPT Interrupt,
    
    WDFCONTEXT Context
    );

typedef EVT_WDF_INTERRUPT_SYNCHRONIZE *PFN_WDF_INTERRUPT_SYNCHRONIZE;





typedef



void
EVT_WDF_INTERRUPT_DPC(
    
    WDFINTERRUPT Interrupt,
    
    WDFOBJECT AssociatedObject
    );

typedef EVT_WDF_INTERRUPT_DPC *PFN_WDF_INTERRUPT_DPC;






typedef



NTSTATUS
EVT_WDF_INTERRUPT_ENABLE(
    
    WDFINTERRUPT Interrupt,
    
    WDFDEVICE AssociatedDevice
    );

typedef EVT_WDF_INTERRUPT_ENABLE *PFN_WDF_INTERRUPT_ENABLE;





typedef



NTSTATUS
EVT_WDF_INTERRUPT_DISABLE(
    
    WDFINTERRUPT Interrupt,
    
    WDFDEVICE AssociatedDevice
    );

typedef EVT_WDF_INTERRUPT_DISABLE *PFN_WDF_INTERRUPT_DISABLE;




typedef struct _WDF_INTERRUPT_CONFIG {
    ULONG              Size;

    
    
    
    
    
    WDFSPINLOCK        SpinLock;

    WDF_TRI_STATE      ShareVector;

    BOOLEAN            FloatingSave;

    
    
    
    BOOLEAN            AutomaticSerialization;

    
    PFN_WDF_INTERRUPT_ISR         EvtInterruptIsr;
    PFN_WDF_INTERRUPT_DPC         EvtInterruptDpc;
    PFN_WDF_INTERRUPT_ENABLE      EvtInterruptEnable;
    PFN_WDF_INTERRUPT_DISABLE     EvtInterruptDisable;

} WDF_INTERRUPT_CONFIG, *PWDF_INTERRUPT_CONFIG;


void
__forceinline
WDF_INTERRUPT_CONFIG_INIT(
     PWDF_INTERRUPT_CONFIG Configuration,
     PFN_WDF_INTERRUPT_ISR EvtInterruptIsr,
     PFN_WDF_INTERRUPT_DPC EvtInterruptDpc
    )
{
    memset((Configuration),0,(sizeof(WDF_INTERRUPT_CONFIG)));

    Configuration->Size = sizeof(WDF_INTERRUPT_CONFIG);

    Configuration->ShareVector = WdfUseDefault;

    Configuration->EvtInterruptIsr     = EvtInterruptIsr;
    Configuration->EvtInterruptDpc     = EvtInterruptDpc;
}

typedef struct _WDF_INTERRUPT_INFO {
    
    
    
    ULONG                  Size;
    ULONG64                Reserved1;
    KAFFINITY              TargetProcessorSet;
    ULONG                  Reserved2;
    ULONG                  MessageNumber;
    ULONG                  Vector;
    KIRQL                  Irql;
    KINTERRUPT_MODE        Mode;
    WDF_INTERRUPT_POLARITY Polarity;
    BOOLEAN                MessageSignaled;
    UCHAR                  ShareDisposition; 
    __declspec(align(8)) USHORT Group;

} WDF_INTERRUPT_INFO, *PWDF_INTERRUPT_INFO;

void
__forceinline
WDF_INTERRUPT_INFO_INIT(
     PWDF_INTERRUPT_INFO Info
    )
{
    memset((Info),0,(sizeof(WDF_INTERRUPT_INFO)));
    Info->Size = sizeof(WDF_INTERRUPT_INFO);
}




typedef struct _WDF_INTERRUPT_EXTENDED_POLICY {
    
    
    
    ULONG                   Size;
    WDF_INTERRUPT_POLICY    Policy;
    WDF_INTERRUPT_PRIORITY  Priority;
    GROUP_AFFINITY          TargetProcessorSetAndGroup;
    
} WDF_INTERRUPT_EXTENDED_POLICY, *PWDF_INTERRUPT_EXTENDED_POLICY;

void
__forceinline
WDF_INTERRUPT_EXTENDED_POLICY_INIT(
     PWDF_INTERRUPT_EXTENDED_POLICY ExtendedPolicy
    )
{
    memset((ExtendedPolicy),0,(sizeof(WDF_INTERRUPT_EXTENDED_POLICY)));
    ExtendedPolicy->Size     = sizeof(WDF_INTERRUPT_EXTENDED_POLICY);
    ExtendedPolicy->Policy   = WdfIrqPolicyMachineDefault;
    ExtendedPolicy->Priority = WdfIrqPriorityUndefined;
}




typedef



NTSTATUS
(*PFN_WDFINTERRUPTCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_INTERRUPT_CONFIG Configuration,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFINTERRUPT* Interrupt
    );



NTSTATUS
__forceinline
WdfInterruptCreate(
    
    WDFDEVICE Device,
    
    PWDF_INTERRUPT_CONFIG Configuration,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFINTERRUPT* Interrupt
    )
{
    return ((PFN_WDFINTERRUPTCREATE) WdfFunctions[WdfInterruptCreateTableIndex])(WdfDriverGlobals, Device, Configuration, Attributes, Interrupt);
}




typedef

BOOLEAN
(*PFN_WDFINTERRUPTQUEUEDPCFORISR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt
    );

BOOLEAN
__forceinline
WdfInterruptQueueDpcForIsr(
    
    WDFINTERRUPT Interrupt
    )
{
    return ((PFN_WDFINTERRUPTQUEUEDPCFORISR) WdfFunctions[WdfInterruptQueueDpcForIsrTableIndex])(WdfDriverGlobals, Interrupt);
}




typedef


BOOLEAN
(*PFN_WDFINTERRUPTSYNCHRONIZE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt,
    
    PFN_WDF_INTERRUPT_SYNCHRONIZE Callback,
    
    WDFCONTEXT Context
    );


BOOLEAN
__forceinline
WdfInterruptSynchronize(
    
    WDFINTERRUPT Interrupt,
    
    PFN_WDF_INTERRUPT_SYNCHRONIZE Callback,
    
    WDFCONTEXT Context
    )
{
    return ((PFN_WDFINTERRUPTSYNCHRONIZE) WdfFunctions[WdfInterruptSynchronizeTableIndex])(WdfDriverGlobals, Interrupt, Callback, Context);
}




typedef

__drv_setsIRQL(2 + 1)

void
(*PFN_WDFINTERRUPTACQUIRELOCK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    
    
    
    WDFINTERRUPT Interrupt
    );


__drv_setsIRQL(2 + 1)
void
__forceinline
WdfInterruptAcquireLock(
    
    
    
    
    WDFINTERRUPT Interrupt
    )
{
    ((PFN_WDFINTERRUPTACQUIRELOCK) WdfFunctions[WdfInterruptAcquireLockTableIndex])(WdfDriverGlobals, Interrupt);
}




typedef



void
(*PFN_WDFINTERRUPTRELEASELOCK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    
    
    
    WDFINTERRUPT Interrupt
    );



void
__forceinline
WdfInterruptReleaseLock(
    
    
    
    
    WDFINTERRUPT Interrupt
    )
{
    ((PFN_WDFINTERRUPTRELEASELOCK) WdfFunctions[WdfInterruptReleaseLockTableIndex])(WdfDriverGlobals, Interrupt);
}




typedef


void
(*PFN_WDFINTERRUPTENABLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt
    );


void
__forceinline
WdfInterruptEnable(
    
    WDFINTERRUPT Interrupt
    )
{
    ((PFN_WDFINTERRUPTENABLE) WdfFunctions[WdfInterruptEnableTableIndex])(WdfDriverGlobals, Interrupt);
}




typedef


void
(*PFN_WDFINTERRUPTDISABLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt
    );


void
__forceinline
WdfInterruptDisable(
    
    WDFINTERRUPT Interrupt
    )
{
    ((PFN_WDFINTERRUPTDISABLE) WdfFunctions[WdfInterruptDisableTableIndex])(WdfDriverGlobals, Interrupt);
}




typedef


PKINTERRUPT
(*PFN_WDFINTERRUPTWDMGETINTERRUPT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt
    );


PKINTERRUPT
__forceinline
WdfInterruptWdmGetInterrupt(
    
    WDFINTERRUPT Interrupt
    )
{
    return ((PFN_WDFINTERRUPTWDMGETINTERRUPT) WdfFunctions[WdfInterruptWdmGetInterruptTableIndex])(WdfDriverGlobals, Interrupt);
}




typedef


void
(*PFN_WDFINTERRUPTGETINFO)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt,
    
    PWDF_INTERRUPT_INFO Info
    );


void
__forceinline
WdfInterruptGetInfo(
    
    WDFINTERRUPT Interrupt,
    
    PWDF_INTERRUPT_INFO Info
    )
{
    ((PFN_WDFINTERRUPTGETINFO) WdfFunctions[WdfInterruptGetInfoTableIndex])(WdfDriverGlobals, Interrupt, Info);
}




typedef


void
(*PFN_WDFINTERRUPTSETPOLICY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt,
    
    WDF_INTERRUPT_POLICY Policy,
    
    WDF_INTERRUPT_PRIORITY Priority,
    
    KAFFINITY TargetProcessorSet
    );


void
__forceinline
WdfInterruptSetPolicy(
    
    WDFINTERRUPT Interrupt,
    
    WDF_INTERRUPT_POLICY Policy,
    
    WDF_INTERRUPT_PRIORITY Priority,
    
    KAFFINITY TargetProcessorSet
    )
{
    ((PFN_WDFINTERRUPTSETPOLICY) WdfFunctions[WdfInterruptSetPolicyTableIndex])(WdfDriverGlobals, Interrupt, Policy, Priority, TargetProcessorSet);
}




typedef


void
(*PFN_WDFINTERRUPTSETEXTENDEDPOLICY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt,
    
    PWDF_INTERRUPT_EXTENDED_POLICY PolicyAndGroup
    );


void
__forceinline
WdfInterruptSetExtendedPolicy(
    
    WDFINTERRUPT Interrupt,
    
    PWDF_INTERRUPT_EXTENDED_POLICY PolicyAndGroup
    )
{
    ((PFN_WDFINTERRUPTSETEXTENDEDPOLICY) WdfFunctions[WdfInterruptSetExtendedPolicyTableIndex])(WdfDriverGlobals, Interrupt, PolicyAndGroup);
}




typedef

WDFDEVICE
(*PFN_WDFINTERRUPTGETDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFINTERRUPT Interrupt
    );

WDFDEVICE
__forceinline
WdfInterruptGetDevice(
    
    WDFINTERRUPT Interrupt
    )
{
    return ((PFN_WDFINTERRUPTGETDEVICE) WdfFunctions[WdfInterruptGetDeviceTableIndex])(WdfDriverGlobals, Interrupt);
}



#line 606 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfinterrupt.h"


#line 609 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfinterrupt.h"

#line 80 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfresource.h"




































typedef


void
(*PFN_WDFIORESOURCEREQUIREMENTSLISTSETSLOTNUMBER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList,
    
    ULONG SlotNumber
    );


void
__forceinline
WdfIoResourceRequirementsListSetSlotNumber(
    
    WDFIORESREQLIST RequirementsList,
    
    ULONG SlotNumber
    )
{
    ((PFN_WDFIORESOURCEREQUIREMENTSLISTSETSLOTNUMBER) WdfFunctions[WdfIoResourceRequirementsListSetSlotNumberTableIndex])(WdfDriverGlobals, RequirementsList, SlotNumber);
}




typedef


void
(*PFN_WDFIORESOURCEREQUIREMENTSLISTSETINTERFACETYPE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList,
    
    
    INTERFACE_TYPE InterfaceType
    );


void
__forceinline
WdfIoResourceRequirementsListSetInterfaceType(
    
    WDFIORESREQLIST RequirementsList,
    
    
    INTERFACE_TYPE InterfaceType
    )
{
    ((PFN_WDFIORESOURCEREQUIREMENTSLISTSETINTERFACETYPE) WdfFunctions[WdfIoResourceRequirementsListSetInterfaceTypeTableIndex])(WdfDriverGlobals, RequirementsList, InterfaceType);
}




typedef



NTSTATUS
(*PFN_WDFIORESOURCEREQUIREMENTSLISTAPPENDIORESLIST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList,
    
    WDFIORESLIST IoResList
    );



NTSTATUS
__forceinline
WdfIoResourceRequirementsListAppendIoResList(
    
    WDFIORESREQLIST RequirementsList,
    
    WDFIORESLIST IoResList
    )
{
    return ((PFN_WDFIORESOURCEREQUIREMENTSLISTAPPENDIORESLIST) WdfFunctions[WdfIoResourceRequirementsListAppendIoResListTableIndex])(WdfDriverGlobals, RequirementsList, IoResList);
}




typedef



NTSTATUS
(*PFN_WDFIORESOURCEREQUIREMENTSLISTINSERTIORESLIST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList,
    
    WDFIORESLIST IoResList,
    
    ULONG Index
    );



NTSTATUS
__forceinline
WdfIoResourceRequirementsListInsertIoResList(
    
    WDFIORESREQLIST RequirementsList,
    
    WDFIORESLIST IoResList,
    
    ULONG Index
    )
{
    return ((PFN_WDFIORESOURCEREQUIREMENTSLISTINSERTIORESLIST) WdfFunctions[WdfIoResourceRequirementsListInsertIoResListTableIndex])(WdfDriverGlobals, RequirementsList, IoResList, Index);
}




typedef


ULONG
(*PFN_WDFIORESOURCEREQUIREMENTSLISTGETCOUNT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList
    );


ULONG
__forceinline
WdfIoResourceRequirementsListGetCount(
    
    WDFIORESREQLIST RequirementsList
    )
{
    return ((PFN_WDFIORESOURCEREQUIREMENTSLISTGETCOUNT) WdfFunctions[WdfIoResourceRequirementsListGetCountTableIndex])(WdfDriverGlobals, RequirementsList);
}




typedef


WDFIORESLIST
(*PFN_WDFIORESOURCEREQUIREMENTSLISTGETIORESLIST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList,
    
    ULONG Index
    );


WDFIORESLIST
__forceinline
WdfIoResourceRequirementsListGetIoResList(
    
    WDFIORESREQLIST RequirementsList,
    
    ULONG Index
    )
{
    return ((PFN_WDFIORESOURCEREQUIREMENTSLISTGETIORESLIST) WdfFunctions[WdfIoResourceRequirementsListGetIoResListTableIndex])(WdfDriverGlobals, RequirementsList, Index);
}




typedef


void
(*PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList,
    
    ULONG Index
    );


void
__forceinline
WdfIoResourceRequirementsListRemove(
    
    WDFIORESREQLIST RequirementsList,
    
    ULONG Index
    )
{
    ((PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVE) WdfFunctions[WdfIoResourceRequirementsListRemoveTableIndex])(WdfDriverGlobals, RequirementsList, Index);
}




typedef


void
(*PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVEBYIORESLIST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList,
    
    WDFIORESLIST IoResList
    );


void
__forceinline
WdfIoResourceRequirementsListRemoveByIoResList(
    
    WDFIORESREQLIST RequirementsList,
    
    WDFIORESLIST IoResList
    )
{
    ((PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVEBYIORESLIST) WdfFunctions[WdfIoResourceRequirementsListRemoveByIoResListTableIndex])(WdfDriverGlobals, RequirementsList, IoResList);
}




typedef



NTSTATUS
(*PFN_WDFIORESOURCELISTCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESREQLIST RequirementsList,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFIORESLIST* ResourceList
    );



NTSTATUS
__forceinline
WdfIoResourceListCreate(
    
    WDFIORESREQLIST RequirementsList,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFIORESLIST* ResourceList
    )
{
    return ((PFN_WDFIORESOURCELISTCREATE) WdfFunctions[WdfIoResourceListCreateTableIndex])(WdfDriverGlobals, RequirementsList, Attributes, ResourceList);
}




typedef



NTSTATUS
(*PFN_WDFIORESOURCELISTAPPENDDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESLIST ResourceList,
    
    PIO_RESOURCE_DESCRIPTOR Descriptor
    );



NTSTATUS
__forceinline
WdfIoResourceListAppendDescriptor(
    
    WDFIORESLIST ResourceList,
    
    PIO_RESOURCE_DESCRIPTOR Descriptor
    )
{
    return ((PFN_WDFIORESOURCELISTAPPENDDESCRIPTOR) WdfFunctions[WdfIoResourceListAppendDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Descriptor);
}




typedef



NTSTATUS
(*PFN_WDFIORESOURCELISTINSERTDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESLIST ResourceList,
    
    PIO_RESOURCE_DESCRIPTOR Descriptor,
    
    ULONG Index
    );



NTSTATUS
__forceinline
WdfIoResourceListInsertDescriptor(
    
    WDFIORESLIST ResourceList,
    
    PIO_RESOURCE_DESCRIPTOR Descriptor,
    
    ULONG Index
    )
{
    return ((PFN_WDFIORESOURCELISTINSERTDESCRIPTOR) WdfFunctions[WdfIoResourceListInsertDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Descriptor, Index);
}




typedef


void
(*PFN_WDFIORESOURCELISTUPDATEDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESLIST ResourceList,
    
    PIO_RESOURCE_DESCRIPTOR Descriptor,
    
    ULONG Index
    );


void
__forceinline
WdfIoResourceListUpdateDescriptor(
    
    WDFIORESLIST ResourceList,
    
    PIO_RESOURCE_DESCRIPTOR Descriptor,
    
    ULONG Index
    )
{
    ((PFN_WDFIORESOURCELISTUPDATEDESCRIPTOR) WdfFunctions[WdfIoResourceListUpdateDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Descriptor, Index);
}




typedef


ULONG
(*PFN_WDFIORESOURCELISTGETCOUNT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESLIST ResourceList
    );


ULONG
__forceinline
WdfIoResourceListGetCount(
    
    WDFIORESLIST ResourceList
    )
{
    return ((PFN_WDFIORESOURCELISTGETCOUNT) WdfFunctions[WdfIoResourceListGetCountTableIndex])(WdfDriverGlobals, ResourceList);
}




typedef


PIO_RESOURCE_DESCRIPTOR
(*PFN_WDFIORESOURCELISTGETDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESLIST ResourceList,
    
    ULONG Index
    );


PIO_RESOURCE_DESCRIPTOR
__forceinline
WdfIoResourceListGetDescriptor(
    
    WDFIORESLIST ResourceList,
    
    ULONG Index
    )
{
    return ((PFN_WDFIORESOURCELISTGETDESCRIPTOR) WdfFunctions[WdfIoResourceListGetDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Index);
}




typedef


void
(*PFN_WDFIORESOURCELISTREMOVE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESLIST ResourceList,
    
    ULONG Index
    );


void
__forceinline
WdfIoResourceListRemove(
    
    WDFIORESLIST ResourceList,
    
    ULONG Index
    )
{
    ((PFN_WDFIORESOURCELISTREMOVE) WdfFunctions[WdfIoResourceListRemoveTableIndex])(WdfDriverGlobals, ResourceList, Index);
}




typedef


void
(*PFN_WDFIORESOURCELISTREMOVEBYDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIORESLIST ResourceList,
    
    PIO_RESOURCE_DESCRIPTOR Descriptor
    );


void
__forceinline
WdfIoResourceListRemoveByDescriptor(
    
    WDFIORESLIST ResourceList,
    
    PIO_RESOURCE_DESCRIPTOR Descriptor
    )
{
    ((PFN_WDFIORESOURCELISTREMOVEBYDESCRIPTOR) WdfFunctions[WdfIoResourceListRemoveByDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Descriptor);
}




typedef



NTSTATUS
(*PFN_WDFCMRESOURCELISTAPPENDDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCMRESLIST List,
    
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor
    );



NTSTATUS
__forceinline
WdfCmResourceListAppendDescriptor(
    
    WDFCMRESLIST List,
    
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor
    )
{
    return ((PFN_WDFCMRESOURCELISTAPPENDDESCRIPTOR) WdfFunctions[WdfCmResourceListAppendDescriptorTableIndex])(WdfDriverGlobals, List, Descriptor);
}




typedef



NTSTATUS
(*PFN_WDFCMRESOURCELISTINSERTDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCMRESLIST List,
    
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor,
    
    ULONG Index
    );



NTSTATUS
__forceinline
WdfCmResourceListInsertDescriptor(
    
    WDFCMRESLIST List,
    
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor,
    
    ULONG Index
    )
{
    return ((PFN_WDFCMRESOURCELISTINSERTDESCRIPTOR) WdfFunctions[WdfCmResourceListInsertDescriptorTableIndex])(WdfDriverGlobals, List, Descriptor, Index);
}




typedef


ULONG
(*PFN_WDFCMRESOURCELISTGETCOUNT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCMRESLIST List
    );


ULONG
__forceinline
WdfCmResourceListGetCount(
    
    WDFCMRESLIST List
    )
{
    return ((PFN_WDFCMRESOURCELISTGETCOUNT) WdfFunctions[WdfCmResourceListGetCountTableIndex])(WdfDriverGlobals, List);
}




typedef


PCM_PARTIAL_RESOURCE_DESCRIPTOR
(*PFN_WDFCMRESOURCELISTGETDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCMRESLIST List,
    
    ULONG Index
    );


PCM_PARTIAL_RESOURCE_DESCRIPTOR
__forceinline
WdfCmResourceListGetDescriptor(
    
    WDFCMRESLIST List,
    
    ULONG Index
    )
{
    return ((PFN_WDFCMRESOURCELISTGETDESCRIPTOR) WdfFunctions[WdfCmResourceListGetDescriptorTableIndex])(WdfDriverGlobals, List, Index);
}




typedef


void
(*PFN_WDFCMRESOURCELISTREMOVE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCMRESLIST List,
    
    ULONG Index
    );


void
__forceinline
WdfCmResourceListRemove(
    
    WDFCMRESLIST List,
    
    ULONG Index
    )
{
    ((PFN_WDFCMRESOURCELISTREMOVE) WdfFunctions[WdfCmResourceListRemoveTableIndex])(WdfDriverGlobals, List, Index);
}




typedef


void
(*PFN_WDFCMRESOURCELISTREMOVEBYDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCMRESLIST List,
    
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor
    );


void
__forceinline
WdfCmResourceListRemoveByDescriptor(
    
    WDFCMRESLIST List,
    
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor
    )
{
    ((PFN_WDFCMRESOURCELISTREMOVEBYDESCRIPTOR) WdfFunctions[WdfCmResourceListRemoveByDescriptorTableIndex])(WdfDriverGlobals, List, Descriptor);
}



#line 699 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfresource.h"


#line 702 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfresource.h"

#line 81 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"


#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfrequest.h"



































typedef enum _WDF_REQUEST_TYPE {
    WdfRequestTypeCreate = 0x0,
    WdfRequestTypeCreateNamedPipe = 0x1,
    WdfRequestTypeClose = 0x2,
    WdfRequestTypeRead = 0x3,
    WdfRequestTypeWrite = 0x4,
    WdfRequestTypeQueryInformation = 0x5,
    WdfRequestTypeSetInformation = 0x6,
    WdfRequestTypeQueryEA = 0x7,
    WdfRequestTypeSetEA = 0x8,
    WdfRequestTypeFlushBuffers = 0x9,
    WdfRequestTypeQueryVolumeInformation = 0xa,
    WdfRequestTypeSetVolumeInformation = 0xb,
    WdfRequestTypeDirectoryControl = 0xc,
    WdfRequestTypeFileSystemControl = 0xd,
    WdfRequestTypeDeviceControl = 0xe,
    WdfRequestTypeDeviceControlInternal = 0xf,
    WdfRequestTypeShutdown = 0x10,
    WdfRequestTypeLockControl = 0x11,
    WdfRequestTypeCleanup = 0x12,
    WdfRequestTypeCreateMailSlot = 0x13,
    WdfRequestTypeQuerySecurity = 0x14,
    WdfRequestTypeSetSecurity = 0x15,
    WdfRequestTypePower = 0x16,
    WdfRequestTypeSystemControl = 0x17,
    WdfRequestTypeDeviceChange = 0x18,
    WdfRequestTypeQueryQuota = 0x19,
    WdfRequestTypeSetQuota = 0x1A,
    WdfRequestTypePnp = 0x1B,
    WdfRequestTypeOther =0x1C,
    WdfRequestTypeUsb = 0x40,
    WdfRequestTypeNoFormat = 0xFF,
    WdfRequestTypeMax,
} WDF_REQUEST_TYPE;

typedef enum _WDF_REQUEST_REUSE_FLAGS {
    WDF_REQUEST_REUSE_NO_FLAGS = 0x00000000,
    WDF_REQUEST_REUSE_SET_NEW_IRP = 0x00000001,
} WDF_REQUEST_REUSE_FLAGS;





typedef enum _WDF_REQUEST_STOP_ACTION_FLAGS {
    WdfRequestStopActionInvalid = 0,
    WdfRequestStopActionSuspend = 0x01, 
    WdfRequestStopActionPurge = 0x2, 
    WdfRequestStopRequestCancelable = 0x10000000, 
} WDF_REQUEST_STOP_ACTION_FLAGS;

typedef enum _WDF_REQUEST_SEND_OPTIONS_FLAGS {
    WDF_REQUEST_SEND_OPTION_TIMEOUT = 0x0000001,
    WDF_REQUEST_SEND_OPTION_SYNCHRONOUS = 0x0000002,
    WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE = 0x0000004,
    WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET = 0x0000008,
} WDF_REQUEST_SEND_OPTIONS_FLAGS;




typedef



void
EVT_WDF_REQUEST_CANCEL(
    
    WDFREQUEST Request
    );

typedef EVT_WDF_REQUEST_CANCEL *PFN_WDF_REQUEST_CANCEL;





typedef struct _WDF_REQUEST_PARAMETERS {

    USHORT Size;

    UCHAR MinorFunction;

    WDF_REQUEST_TYPE Type;

    
    
    
    
    
    union {

        
        
        

        struct {
            PIO_SECURITY_CONTEXT SecurityContext;
            ULONG Options;
            USHORT  FileAttributes;
            USHORT ShareAccess;
            ULONG  EaLength;
        } Create;


        
        
        

        struct {
            size_t Length;
            ULONG  Key;
            LONGLONG DeviceOffset;
        } Read;

        
        
        

        struct {
            size_t Length;
            ULONG  Key;
            LONGLONG DeviceOffset;
        } Write;

        
        
        
        
        
        

        struct {
            size_t OutputBufferLength;
            size_t  InputBufferLength;
            ULONG  IoControlCode;
            PVOID Type3InputBuffer;
        } DeviceIoControl;

        struct {
            PVOID Arg1;
            PVOID  Arg2;
            ULONG  IoControlCode;
            PVOID Arg4;
        } Others;

    } Parameters;

} WDF_REQUEST_PARAMETERS, *PWDF_REQUEST_PARAMETERS;

void
__forceinline
WDF_REQUEST_PARAMETERS_INIT(
     PWDF_REQUEST_PARAMETERS Parameters
    )
{
    memset((Parameters),0,(sizeof(WDF_REQUEST_PARAMETERS)));

    Parameters->Size = sizeof(WDF_REQUEST_PARAMETERS);
}

typedef struct _WDF_USB_REQUEST_COMPLETION_PARAMS *PWDF_USB_REQUEST_COMPLETION_PARAMS;

typedef struct _WDF_REQUEST_COMPLETION_PARAMS {
    
    
    
    ULONG Size;

    WDF_REQUEST_TYPE Type;

    IO_STATUS_BLOCK IoStatus;

    union {
        struct {
            WDFMEMORY Buffer;
            size_t Length;
            size_t Offset;
        } Write;

        struct {
            WDFMEMORY Buffer;
            size_t Length;
            size_t Offset;
        } Read;

        struct {
            ULONG IoControlCode;

            struct {
                WDFMEMORY Buffer;
                size_t Offset;
            } Input;

            struct {
                WDFMEMORY Buffer;
                size_t Offset;
                size_t Length;
            } Output;
        } Ioctl;

        struct {
            union {
                PVOID Ptr;
                ULONG_PTR Value;
            } Argument1;
            union {
                PVOID Ptr;
                ULONG_PTR Value;
            } Argument2;
            union {
                PVOID Ptr;
                ULONG_PTR Value;
            } Argument3;
            union {
                PVOID Ptr;
                ULONG_PTR Value;
            } Argument4;
        } Others;

        struct {
            PWDF_USB_REQUEST_COMPLETION_PARAMS Completion;
        } Usb;
    } Parameters;

} WDF_REQUEST_COMPLETION_PARAMS, *PWDF_REQUEST_COMPLETION_PARAMS;

void
__forceinline
WDF_REQUEST_COMPLETION_PARAMS_INIT(
     PWDF_REQUEST_COMPLETION_PARAMS Params
    )
{
    memset((Params),0,(sizeof(WDF_REQUEST_COMPLETION_PARAMS)));
    Params->Size = sizeof(WDF_REQUEST_COMPLETION_PARAMS);
    Params->Type = WdfRequestTypeNoFormat;
}

typedef


void
EVT_WDF_REQUEST_COMPLETION_ROUTINE(
    
    WDFREQUEST Request,
    
    WDFIOTARGET Target,
    
    PWDF_REQUEST_COMPLETION_PARAMS Params,
    
    WDFCONTEXT Context
    );

typedef EVT_WDF_REQUEST_COMPLETION_ROUTINE *PFN_WDF_REQUEST_COMPLETION_ROUTINE;






















typedef struct _WDF_REQUEST_REUSE_PARAMS {
    
    
    
    ULONG Size;

    
    
    
    ULONG Flags;

    
    
    
    NTSTATUS Status;

    
    
    
    
    
    
    PIRP NewIrp;

} WDF_REQUEST_REUSE_PARAMS, *PWDF_REQUEST_REUSE_PARAMS;

void
__forceinline
WDF_REQUEST_REUSE_PARAMS_INIT(
     PWDF_REQUEST_REUSE_PARAMS Params,
     ULONG Flags,
     NTSTATUS Status
    )
{
    memset((Params),0,(sizeof(WDF_REQUEST_REUSE_PARAMS)));

    Params->Size = sizeof(WDF_REQUEST_REUSE_PARAMS);
    Params->Flags = Flags;
    Params->Status = Status;
}

void
__forceinline
WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP(
     PWDF_REQUEST_REUSE_PARAMS Params,
     PIRP NewIrp
    )
{
    Params->Flags |= WDF_REQUEST_REUSE_SET_NEW_IRP;
    Params->NewIrp = NewIrp;
}

typedef struct _WDF_REQUEST_SEND_OPTIONS {
    
    
    
    ULONG Size;

    
    
    
    
    ULONG Flags;

    
    
    
    LONGLONG Timeout;

} WDF_REQUEST_SEND_OPTIONS, *PWDF_REQUEST_SEND_OPTIONS;

void
__forceinline
WDF_REQUEST_SEND_OPTIONS_INIT(
     PWDF_REQUEST_SEND_OPTIONS Options,
     ULONG Flags
    )
{
    memset((Options),0,(sizeof(WDF_REQUEST_SEND_OPTIONS)));
    Options->Size = sizeof(WDF_REQUEST_SEND_OPTIONS);
    Options->Flags = Flags;
}

void
__forceinline
WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(
     PWDF_REQUEST_SEND_OPTIONS Options,
     LONGLONG Timeout
    )
{
    Options->Flags |= WDF_REQUEST_SEND_OPTION_TIMEOUT;
    Options->Timeout = Timeout;
}

typedef enum _WDF_REQUEST_FORWARD_OPTIONS_FLAGS {
    WDF_REQUEST_FORWARD_OPTION_SEND_AND_FORGET = 0x0000001
} WDF_REQUEST_FORWARD_OPTIONS_FLAGS;

typedef struct _WDF_REQUEST_FORWARD_OPTIONS {
    
    
    
    ULONG Size;

    
    
    
    
    ULONG Flags;  
} WDF_REQUEST_FORWARD_OPTIONS, *PWDF_REQUEST_FORWARD_OPTIONS;





void
__forceinline
WDF_REQUEST_FORWARD_OPTIONS_INIT(
     PWDF_REQUEST_FORWARD_OPTIONS  ForwardOptions
    )
{
    memset((ForwardOptions),0,(sizeof(WDF_REQUEST_FORWARD_OPTIONS)));

    ForwardOptions->Size = sizeof(WDF_REQUEST_FORWARD_OPTIONS);
    ForwardOptions->Flags |= WDF_REQUEST_FORWARD_OPTION_SEND_AND_FORGET;
}





typedef



NTSTATUS
(*PFN_WDFREQUESTCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES RequestAttributes,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST* Request
    );



NTSTATUS
__forceinline
WdfRequestCreate(
    
    PWDF_OBJECT_ATTRIBUTES RequestAttributes,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST* Request
    )
{
    return ((PFN_WDFREQUESTCREATE) WdfFunctions[WdfRequestCreateTableIndex])(WdfDriverGlobals, RequestAttributes, IoTarget, Request);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTCREATEFROMIRP)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDF_OBJECT_ATTRIBUTES RequestAttributes,
    
    PIRP Irp,
    
    BOOLEAN RequestFreesIrp,
    
    WDFREQUEST* Request
    );



NTSTATUS
__forceinline
WdfRequestCreateFromIrp(
    
    PWDF_OBJECT_ATTRIBUTES RequestAttributes,
    
    PIRP Irp,
    
    BOOLEAN RequestFreesIrp,
    
    WDFREQUEST* Request
    )
{
    return ((PFN_WDFREQUESTCREATEFROMIRP) WdfFunctions[WdfRequestCreateFromIrpTableIndex])(WdfDriverGlobals, RequestAttributes, Irp, RequestFreesIrp, Request);
}




typedef


NTSTATUS
(*PFN_WDFREQUESTREUSE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_REUSE_PARAMS ReuseParams
    );


NTSTATUS
__forceinline
WdfRequestReuse(
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_REUSE_PARAMS ReuseParams
    )
{
    return ((PFN_WDFREQUESTREUSE) WdfFunctions[WdfRequestReuseTableIndex])(WdfDriverGlobals, Request, ReuseParams);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTCHANGETARGET)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    WDFIOTARGET IoTarget
    );



NTSTATUS
__forceinline
WdfRequestChangeTarget(
    
    WDFREQUEST Request,
    
    WDFIOTARGET IoTarget
    )
{
    return ((PFN_WDFREQUESTCHANGETARGET) WdfFunctions[WdfRequestChangeTargetTableIndex])(WdfDriverGlobals, Request, IoTarget);
}




typedef


void
(*PFN_WDFREQUESTFORMATREQUESTUSINGCURRENTTYPE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );


void
__forceinline
WdfRequestFormatRequestUsingCurrentType(
    
    WDFREQUEST Request
    )
{
    ((PFN_WDFREQUESTFORMATREQUESTUSINGCURRENTTYPE) WdfFunctions[WdfRequestFormatRequestUsingCurrentTypeTableIndex])(WdfDriverGlobals, Request);
}




typedef


void
(*PFN_WDFREQUESTWDMFORMATUSINGSTACKLOCATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PIO_STACK_LOCATION Stack
    );


void
__forceinline
WdfRequestWdmFormatUsingStackLocation(
    
    WDFREQUEST Request,
    
    PIO_STACK_LOCATION Stack
    )
{
    ((PFN_WDFREQUESTWDMFORMATUSINGSTACKLOCATION) WdfFunctions[WdfRequestWdmFormatUsingStackLocationTableIndex])(WdfDriverGlobals, Request, Stack);
}




typedef



BOOLEAN
(*PFN_WDFREQUESTSEND)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    WDFIOTARGET Target,
    
    PWDF_REQUEST_SEND_OPTIONS Options
    );



BOOLEAN
__forceinline
WdfRequestSend(
    
    WDFREQUEST Request,
    
    WDFIOTARGET Target,
    
    PWDF_REQUEST_SEND_OPTIONS Options
    )
{
    return ((PFN_WDFREQUESTSEND) WdfFunctions[WdfRequestSendTableIndex])(WdfDriverGlobals, Request, Target, Options);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTGETSTATUS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );



NTSTATUS
__forceinline
WdfRequestGetStatus(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTGETSTATUS) WdfFunctions[WdfRequestGetStatusTableIndex])(WdfDriverGlobals, Request);
}




typedef


void
(*PFN_WDFREQUESTMARKCANCELABLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PFN_WDF_REQUEST_CANCEL EvtRequestCancel
    );


void
__forceinline
WdfRequestMarkCancelable(
    
    WDFREQUEST Request,
    
    PFN_WDF_REQUEST_CANCEL EvtRequestCancel
    )
{
    ((PFN_WDFREQUESTMARKCANCELABLE) WdfFunctions[WdfRequestMarkCancelableTableIndex])(WdfDriverGlobals, Request, EvtRequestCancel);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTMARKCANCELABLEEX)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PFN_WDF_REQUEST_CANCEL EvtRequestCancel
    );



NTSTATUS
__forceinline
WdfRequestMarkCancelableEx(
    
    WDFREQUEST Request,
    
    PFN_WDF_REQUEST_CANCEL EvtRequestCancel
    )
{
    return ((PFN_WDFREQUESTMARKCANCELABLEEX) WdfFunctions[WdfRequestMarkCancelableExTableIndex])(WdfDriverGlobals, Request, EvtRequestCancel);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTUNMARKCANCELABLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );



NTSTATUS
__forceinline
WdfRequestUnmarkCancelable(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTUNMARKCANCELABLE) WdfFunctions[WdfRequestUnmarkCancelableTableIndex])(WdfDriverGlobals, Request);
}




typedef



BOOLEAN
(*PFN_WDFREQUESTISCANCELED)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );



BOOLEAN
__forceinline
WdfRequestIsCanceled(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTISCANCELED) WdfFunctions[WdfRequestIsCanceledTableIndex])(WdfDriverGlobals, Request);
}




typedef


BOOLEAN
(*PFN_WDFREQUESTCANCELSENTREQUEST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );


BOOLEAN
__forceinline
WdfRequestCancelSentRequest(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTCANCELSENTREQUEST) WdfFunctions[WdfRequestCancelSentRequestTableIndex])(WdfDriverGlobals, Request);
}




typedef



BOOLEAN
(*PFN_WDFREQUESTISFROM32BITPROCESS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );



BOOLEAN
__forceinline
WdfRequestIsFrom32BitProcess(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTISFROM32BITPROCESS) WdfFunctions[WdfRequestIsFrom32BitProcessTableIndex])(WdfDriverGlobals, Request);
}




typedef


void
(*PFN_WDFREQUESTSETCOMPLETIONROUTINE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PFN_WDF_REQUEST_COMPLETION_ROUTINE CompletionRoutine,
     
    WDFCONTEXT CompletionContext
    );


void
__forceinline
WdfRequestSetCompletionRoutine(
    
    WDFREQUEST Request,
    
    PFN_WDF_REQUEST_COMPLETION_ROUTINE CompletionRoutine,
     
    WDFCONTEXT CompletionContext
    )
{
    ((PFN_WDFREQUESTSETCOMPLETIONROUTINE) WdfFunctions[WdfRequestSetCompletionRoutineTableIndex])(WdfDriverGlobals, Request, CompletionRoutine, CompletionContext);
}




typedef


void
(*PFN_WDFREQUESTGETCOMPLETIONPARAMS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_COMPLETION_PARAMS Params
    );


void
__forceinline
WdfRequestGetCompletionParams(
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_COMPLETION_PARAMS Params
    )
{
    ((PFN_WDFREQUESTGETCOMPLETIONPARAMS) WdfFunctions[WdfRequestGetCompletionParamsTableIndex])(WdfDriverGlobals, Request, Params);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTALLOCATETIMER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );



NTSTATUS
__forceinline
WdfRequestAllocateTimer(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTALLOCATETIMER) WdfFunctions[WdfRequestAllocateTimerTableIndex])(WdfDriverGlobals, Request);
}




typedef


void
(*PFN_WDFREQUESTCOMPLETE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    NTSTATUS Status
    );


void
__forceinline
WdfRequestComplete(
    
    WDFREQUEST Request,
    
    NTSTATUS Status
    )
{
    ((PFN_WDFREQUESTCOMPLETE) WdfFunctions[WdfRequestCompleteTableIndex])(WdfDriverGlobals, Request, Status);
}




typedef


void
(*PFN_WDFREQUESTCOMPLETEWITHPRIORITYBOOST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    NTSTATUS Status,
    
    CCHAR PriorityBoost
    );


void
__forceinline
WdfRequestCompleteWithPriorityBoost(
    
    WDFREQUEST Request,
    
    NTSTATUS Status,
    
    CCHAR PriorityBoost
    )
{
    ((PFN_WDFREQUESTCOMPLETEWITHPRIORITYBOOST) WdfFunctions[WdfRequestCompleteWithPriorityBoostTableIndex])(WdfDriverGlobals, Request, Status, PriorityBoost);
}




typedef


void
(*PFN_WDFREQUESTCOMPLETEWITHINFORMATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    NTSTATUS Status,
    
    ULONG_PTR Information
    );


void
__forceinline
WdfRequestCompleteWithInformation(
    
    WDFREQUEST Request,
    
    NTSTATUS Status,
    
    ULONG_PTR Information
    )
{
    ((PFN_WDFREQUESTCOMPLETEWITHINFORMATION) WdfFunctions[WdfRequestCompleteWithInformationTableIndex])(WdfDriverGlobals, Request, Status, Information);
}




typedef


void
(*PFN_WDFREQUESTGETPARAMETERS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_PARAMETERS Parameters
    );


void
__forceinline
WdfRequestGetParameters(
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_PARAMETERS Parameters
    )
{
    ((PFN_WDFREQUESTGETPARAMETERS) WdfFunctions[WdfRequestGetParametersTableIndex])(WdfDriverGlobals, Request, Parameters);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTRETRIEVEINPUTMEMORY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    WDFMEMORY* Memory
    );



NTSTATUS
__forceinline
WdfRequestRetrieveInputMemory(
    
    WDFREQUEST Request,
    
    WDFMEMORY* Memory
    )
{
    return ((PFN_WDFREQUESTRETRIEVEINPUTMEMORY) WdfFunctions[WdfRequestRetrieveInputMemoryTableIndex])(WdfDriverGlobals, Request, Memory);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTRETRIEVEOUTPUTMEMORY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    WDFMEMORY* Memory
    );



NTSTATUS
__forceinline
WdfRequestRetrieveOutputMemory(
    
    WDFREQUEST Request,
    
    WDFMEMORY* Memory
    )
{
    return ((PFN_WDFREQUESTRETRIEVEOUTPUTMEMORY) WdfFunctions[WdfRequestRetrieveOutputMemoryTableIndex])(WdfDriverGlobals, Request, Memory);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTRETRIEVEINPUTBUFFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    size_t MinimumRequiredLength,
    
    PVOID* Buffer,
    
    size_t* Length
    );



NTSTATUS
__forceinline
WdfRequestRetrieveInputBuffer(
    
    WDFREQUEST Request,
    
    size_t MinimumRequiredLength,
    
    PVOID* Buffer,
    
    size_t* Length
    )
{
    return ((PFN_WDFREQUESTRETRIEVEINPUTBUFFER) WdfFunctions[WdfRequestRetrieveInputBufferTableIndex])(WdfDriverGlobals, Request, MinimumRequiredLength, Buffer, Length);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTRETRIEVEOUTPUTBUFFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    size_t MinimumRequiredSize,
    
    PVOID* Buffer,
    
    size_t* Length
    );



NTSTATUS
__forceinline
WdfRequestRetrieveOutputBuffer(
    
    WDFREQUEST Request,
    
    size_t MinimumRequiredSize,
    
    PVOID* Buffer,
    
    size_t* Length
    )
{
    return ((PFN_WDFREQUESTRETRIEVEOUTPUTBUFFER) WdfFunctions[WdfRequestRetrieveOutputBufferTableIndex])(WdfDriverGlobals, Request, MinimumRequiredSize, Buffer, Length);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTRETRIEVEINPUTWDMMDL)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PMDL* Mdl
    );



NTSTATUS
__forceinline
WdfRequestRetrieveInputWdmMdl(
    
    WDFREQUEST Request,
    
    PMDL* Mdl
    )
{
    return ((PFN_WDFREQUESTRETRIEVEINPUTWDMMDL) WdfFunctions[WdfRequestRetrieveInputWdmMdlTableIndex])(WdfDriverGlobals, Request, Mdl);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTRETRIEVEOUTPUTWDMMDL)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PMDL* Mdl
    );



NTSTATUS
__forceinline
WdfRequestRetrieveOutputWdmMdl(
    
    WDFREQUEST Request,
    
    PMDL* Mdl
    )
{
    return ((PFN_WDFREQUESTRETRIEVEOUTPUTWDMMDL) WdfFunctions[WdfRequestRetrieveOutputWdmMdlTableIndex])(WdfDriverGlobals, Request, Mdl);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTRETRIEVEUNSAFEUSERINPUTBUFFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    size_t MinimumRequiredLength,
    
    PVOID* InputBuffer,
    
    size_t* Length
    );



NTSTATUS
__forceinline
WdfRequestRetrieveUnsafeUserInputBuffer(
    
    WDFREQUEST Request,
    
    size_t MinimumRequiredLength,
    
    PVOID* InputBuffer,
    
    size_t* Length
    )
{
    return ((PFN_WDFREQUESTRETRIEVEUNSAFEUSERINPUTBUFFER) WdfFunctions[WdfRequestRetrieveUnsafeUserInputBufferTableIndex])(WdfDriverGlobals, Request, MinimumRequiredLength, InputBuffer, Length);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTRETRIEVEUNSAFEUSEROUTPUTBUFFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    size_t MinimumRequiredLength,
    
    PVOID* OutputBuffer,
    
    size_t* Length
    );



NTSTATUS
__forceinline
WdfRequestRetrieveUnsafeUserOutputBuffer(
    
    WDFREQUEST Request,
    
    size_t MinimumRequiredLength,
    
    PVOID* OutputBuffer,
    
    size_t* Length
    )
{
    return ((PFN_WDFREQUESTRETRIEVEUNSAFEUSEROUTPUTBUFFER) WdfFunctions[WdfRequestRetrieveUnsafeUserOutputBufferTableIndex])(WdfDriverGlobals, Request, MinimumRequiredLength, OutputBuffer, Length);
}




typedef


void
(*PFN_WDFREQUESTSETINFORMATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    ULONG_PTR Information
    );


void
__forceinline
WdfRequestSetInformation(
    
    WDFREQUEST Request,
    
    ULONG_PTR Information
    )
{
    ((PFN_WDFREQUESTSETINFORMATION) WdfFunctions[WdfRequestSetInformationTableIndex])(WdfDriverGlobals, Request, Information);
}




typedef


ULONG_PTR
(*PFN_WDFREQUESTGETINFORMATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );


ULONG_PTR
__forceinline
WdfRequestGetInformation(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTGETINFORMATION) WdfFunctions[WdfRequestGetInformationTableIndex])(WdfDriverGlobals, Request);
}




typedef


WDFFILEOBJECT
(*PFN_WDFREQUESTGETFILEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );


WDFFILEOBJECT
__forceinline
WdfRequestGetFileObject(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTGETFILEOBJECT) WdfFunctions[WdfRequestGetFileObjectTableIndex])(WdfDriverGlobals, Request);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORREAD)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PVOID Buffer,
    
    size_t Length,
    
    WDFMEMORY* MemoryObject
    );



NTSTATUS
__forceinline
WdfRequestProbeAndLockUserBufferForRead(
    
    WDFREQUEST Request,
    
    PVOID Buffer,
    
    size_t Length,
    
    WDFMEMORY* MemoryObject
    )
{
    return ((PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORREAD) WdfFunctions[WdfRequestProbeAndLockUserBufferForReadTableIndex])(WdfDriverGlobals, Request, Buffer, Length, MemoryObject);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORWRITE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    PVOID Buffer,
    
    size_t Length,
    
    WDFMEMORY* MemoryObject
    );



NTSTATUS
__forceinline
WdfRequestProbeAndLockUserBufferForWrite(
    
    WDFREQUEST Request,
    
    PVOID Buffer,
    
    size_t Length,
    
    WDFMEMORY* MemoryObject
    )
{
    return ((PFN_WDFREQUESTPROBEANDLOCKUSERBUFFERFORWRITE) WdfFunctions[WdfRequestProbeAndLockUserBufferForWriteTableIndex])(WdfDriverGlobals, Request, Buffer, Length, MemoryObject);
}




typedef


KPROCESSOR_MODE
(*PFN_WDFREQUESTGETREQUESTORMODE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );


KPROCESSOR_MODE
__forceinline
WdfRequestGetRequestorMode(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTGETREQUESTORMODE) WdfFunctions[WdfRequestGetRequestorModeTableIndex])(WdfDriverGlobals, Request);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTFORWARDTOIOQUEUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    WDFQUEUE DestinationQueue
    );



NTSTATUS
__forceinline
WdfRequestForwardToIoQueue(
    
    WDFREQUEST Request,
    
    WDFQUEUE DestinationQueue
    )
{
    return ((PFN_WDFREQUESTFORWARDTOIOQUEUE) WdfFunctions[WdfRequestForwardToIoQueueTableIndex])(WdfDriverGlobals, Request, DestinationQueue);
}




typedef


WDFQUEUE
(*PFN_WDFREQUESTGETIOQUEUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );


WDFQUEUE
__forceinline
WdfRequestGetIoQueue(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTGETIOQUEUE) WdfFunctions[WdfRequestGetIoQueueTableIndex])(WdfDriverGlobals, Request);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTREQUEUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );



NTSTATUS
__forceinline
WdfRequestRequeue(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTREQUEUE) WdfFunctions[WdfRequestRequeueTableIndex])(WdfDriverGlobals, Request);
}




typedef


void
(*PFN_WDFREQUESTSTOPACKNOWLEDGE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    BOOLEAN Requeue
    );


void
__forceinline
WdfRequestStopAcknowledge(
    
    WDFREQUEST Request,
    
    BOOLEAN Requeue
    )
{
    ((PFN_WDFREQUESTSTOPACKNOWLEDGE) WdfFunctions[WdfRequestStopAcknowledgeTableIndex])(WdfDriverGlobals, Request, Requeue);
}




typedef


PIRP
(*PFN_WDFREQUESTWDMGETIRP)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );


PIRP
__forceinline
WdfRequestWdmGetIrp(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTWDMGETIRP) WdfFunctions[WdfRequestWdmGetIrpTableIndex])(WdfDriverGlobals, Request);
}




typedef


BOOLEAN
(*PFN_WDFREQUESTISRESERVED)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request
    );


BOOLEAN
__forceinline
WdfRequestIsReserved(
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFREQUESTISRESERVED) WdfFunctions[WdfRequestIsReservedTableIndex])(WdfDriverGlobals, Request);
}




typedef



NTSTATUS
(*PFN_WDFREQUESTFORWARDTOPARENTDEVICEIOQUEUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFREQUEST Request,
    
    WDFQUEUE ParentDeviceQueue,
    
    PWDF_REQUEST_FORWARD_OPTIONS ForwardOptions
    );



NTSTATUS
__forceinline
WdfRequestForwardToParentDeviceIoQueue(
    
    WDFREQUEST Request,
    
    WDFQUEUE ParentDeviceQueue,
    
    PWDF_REQUEST_FORWARD_OPTIONS ForwardOptions
    )
{
    return ((PFN_WDFREQUESTFORWARDTOPARENTDEVICEIOQUEUE) WdfFunctions[WdfRequestForwardToParentDeviceIoQueueTableIndex])(WdfDriverGlobals, Request, ParentDeviceQueue, ForwardOptions);
}



#line 1731 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfrequest.h"


#line 1734 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfrequest.h"


#line 84 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfiotarget.h"





























typedef enum _WDF_IO_TARGET_STATE {
    WdfIoTargetStateUndefined = 0,
    WdfIoTargetStarted,
    WdfIoTargetStopped,
    WdfIoTargetClosedForQueryRemove,
    WdfIoTargetClosed,
    WdfIoTargetDeleted,
} WDF_IO_TARGET_STATE, *PWDF_IO_TARGET_STATE;

typedef enum _WDF_IO_TARGET_OPEN_TYPE {
    WdfIoTargetOpenUndefined = 0,
    WdfIoTargetOpenUseExistingDevice = 1,
    WdfIoTargetOpenByName = 2,
    WdfIoTargetOpenReopen = 3,
} WDF_IO_TARGET_OPEN_TYPE;

typedef enum _WDF_IO_TARGET_SENT_IO_ACTION {
    WdfIoTargetSentIoUndefined = 0,
    WdfIoTargetCancelSentIo,
    WdfIoTargetWaitForSentIoToComplete,
    WdfIoTargetLeaveSentIoPending,
} WDF_IO_TARGET_SENT_IO_ACTION;



typedef



NTSTATUS
EVT_WDF_IO_TARGET_QUERY_REMOVE(
    
    WDFIOTARGET IoTarget
    );

typedef EVT_WDF_IO_TARGET_QUERY_REMOVE *PFN_WDF_IO_TARGET_QUERY_REMOVE;

typedef



void
EVT_WDF_IO_TARGET_REMOVE_CANCELED(
    
    WDFIOTARGET IoTarget
    );

typedef EVT_WDF_IO_TARGET_REMOVE_CANCELED *PFN_WDF_IO_TARGET_REMOVE_CANCELED;

typedef



void
EVT_WDF_IO_TARGET_REMOVE_COMPLETE(
    
    WDFIOTARGET IoTarget
    );

typedef EVT_WDF_IO_TARGET_REMOVE_COMPLETE *PFN_WDF_IO_TARGET_REMOVE_COMPLETE;

typedef struct _WDF_IO_TARGET_OPEN_PARAMS {
    
    
    
    ULONG Size;

    
    
    
    
    WDF_IO_TARGET_OPEN_TYPE Type;

    
    
    
    
    
    PFN_WDF_IO_TARGET_QUERY_REMOVE EvtIoTargetQueryRemove;

    
    
    
    
    PFN_WDF_IO_TARGET_REMOVE_CANCELED EvtIoTargetRemoveCanceled;

    
    
    
    
    PFN_WDF_IO_TARGET_REMOVE_COMPLETE EvtIoTargetRemoveComplete;


    
    
    
    
    PDEVICE_OBJECT TargetDeviceObject;

    
    
    
    
    
    PFILE_OBJECT TargetFileObject;
    

    
    
    
    
    UNICODE_STRING TargetDeviceName;

    
    
    
    
    
    
    ACCESS_MASK DesiredAccess;

    
    
    
    
    
    
    ULONG ShareAccess;

    
    
    
    
    ULONG FileAttributes;

    
    
    
    
    ULONG CreateDisposition;

    
    
    
    
    ULONG CreateOptions;

    PVOID EaBuffer;

    ULONG EaBufferLength;

    PLONGLONG AllocationSize;

    

    
    
    
    
    
    ULONG FileInformation;

} WDF_IO_TARGET_OPEN_PARAMS, *PWDF_IO_TARGET_OPEN_PARAMS;

void
__forceinline
WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE(
     PWDF_IO_TARGET_OPEN_PARAMS Params,
     PDEVICE_OBJECT DeviceObject
    )
{
    memset((Params),0,(sizeof(WDF_IO_TARGET_OPEN_PARAMS)));

    Params->Size = sizeof(WDF_IO_TARGET_OPEN_PARAMS);
    Params->Type = WdfIoTargetOpenUseExistingDevice;

    Params->TargetDeviceObject = DeviceObject;
}

void
__forceinline
WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME(
     PWDF_IO_TARGET_OPEN_PARAMS Params,
     PCUNICODE_STRING TargetDeviceName,
     ACCESS_MASK DesiredAccess
    )
{
    memset((Params),0,(sizeof(WDF_IO_TARGET_OPEN_PARAMS)));

    Params->Size = sizeof(WDF_IO_TARGET_OPEN_PARAMS);
    Params->Type = WdfIoTargetOpenByName;

    memcpy((&Params->TargetDeviceName),(TargetDeviceName),(sizeof(UNICODE_STRING)));
#line 225 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfiotarget.h"
    Params->DesiredAccess = DesiredAccess;
    Params->CreateOptions = 0x00000040;
}

void
__forceinline
WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME(
     PWDF_IO_TARGET_OPEN_PARAMS Params,
     PCUNICODE_STRING TargetDeviceName,
     ACCESS_MASK DesiredAccess
    )
{
    WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME(Params,
                                                  TargetDeviceName,
                                                  DesiredAccess);
    Params->CreateDisposition = 0x00000001;
}

void
__forceinline
WDF_IO_TARGET_OPEN_PARAMS_INIT_REOPEN(
     PWDF_IO_TARGET_OPEN_PARAMS Params
    )
{
    memset((Params),0,(sizeof(WDF_IO_TARGET_OPEN_PARAMS)));

    Params->Size = sizeof(WDF_IO_TARGET_OPEN_PARAMS);
    Params->Type = WdfIoTargetOpenReopen;
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_OBJECT_ATTRIBUTES IoTargetAttributes,
    
    WDFIOTARGET* IoTarget
    );



NTSTATUS
__forceinline
WdfIoTargetCreate(
    
    WDFDEVICE Device,
    
    PWDF_OBJECT_ATTRIBUTES IoTargetAttributes,
    
    WDFIOTARGET* IoTarget
    )
{
    return ((PFN_WDFIOTARGETCREATE) WdfFunctions[WdfIoTargetCreateTableIndex])(WdfDriverGlobals, Device, IoTargetAttributes, IoTarget);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETOPEN)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    PWDF_IO_TARGET_OPEN_PARAMS OpenParams
    );



NTSTATUS
__forceinline
WdfIoTargetOpen(
    
    WDFIOTARGET IoTarget,
    
    PWDF_IO_TARGET_OPEN_PARAMS OpenParams
    )
{
    return ((PFN_WDFIOTARGETOPEN) WdfFunctions[WdfIoTargetOpenTableIndex])(WdfDriverGlobals, IoTarget, OpenParams);
}




typedef


void
(*PFN_WDFIOTARGETCLOSEFORQUERYREMOVE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );


void
__forceinline
WdfIoTargetCloseForQueryRemove(
    
    WDFIOTARGET IoTarget
    )
{
    ((PFN_WDFIOTARGETCLOSEFORQUERYREMOVE) WdfFunctions[WdfIoTargetCloseForQueryRemoveTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef


void
(*PFN_WDFIOTARGETCLOSE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );


void
__forceinline
WdfIoTargetClose(
    
    WDFIOTARGET IoTarget
    )
{
    ((PFN_WDFIOTARGETCLOSE) WdfFunctions[WdfIoTargetCloseTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETSTART)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );



NTSTATUS
__forceinline
WdfIoTargetStart(
    
    WDFIOTARGET IoTarget
    )
{
    return ((PFN_WDFIOTARGETSTART) WdfFunctions[WdfIoTargetStartTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef



void
(*PFN_WDFIOTARGETSTOP)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    
    WDF_IO_TARGET_SENT_IO_ACTION Action
    );



void
__forceinline
WdfIoTargetStop(
    
    WDFIOTARGET IoTarget,
    
    
    WDF_IO_TARGET_SENT_IO_ACTION Action
    )
{
    ((PFN_WDFIOTARGETSTOP) WdfFunctions[WdfIoTargetStopTableIndex])(WdfDriverGlobals, IoTarget, Action);
}




typedef


WDF_IO_TARGET_STATE
(*PFN_WDFIOTARGETGETSTATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );


WDF_IO_TARGET_STATE
__forceinline
WdfIoTargetGetState(
    
    WDFIOTARGET IoTarget
    )
{
    return ((PFN_WDFIOTARGETGETSTATE) WdfFunctions[WdfIoTargetGetStateTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef


WDFDEVICE
(*PFN_WDFIOTARGETGETDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );


WDFDEVICE
__forceinline
WdfIoTargetGetDevice(
    
    WDFIOTARGET IoTarget
    )
{
    return ((PFN_WDFIOTARGETGETDEVICE) WdfFunctions[WdfIoTargetGetDeviceTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETQUERYTARGETPROPERTY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    ULONG BufferLength,
    
    
    PVOID PropertyBuffer,
    
    PULONG ResultLength
    );



NTSTATUS
__forceinline
WdfIoTargetQueryTargetProperty(
    
    WDFIOTARGET IoTarget,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    ULONG BufferLength,
    
    
    PVOID PropertyBuffer,
    
    PULONG ResultLength
    )
{
    return ((PFN_WDFIOTARGETQUERYTARGETPROPERTY) WdfFunctions[WdfIoTargetQueryTargetPropertyTableIndex])(WdfDriverGlobals, IoTarget, DeviceProperty, BufferLength, PropertyBuffer, ResultLength);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETALLOCANDQUERYTARGETPROPERTY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    
    WDFMEMORY* PropertyMemory
    );



NTSTATUS
__forceinline
WdfIoTargetAllocAndQueryTargetProperty(
    
    WDFIOTARGET IoTarget,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    
    WDFMEMORY* PropertyMemory
    )
{
    return ((PFN_WDFIOTARGETALLOCANDQUERYTARGETPROPERTY) WdfFunctions[WdfIoTargetAllocAndQueryTargetPropertyTableIndex])(WdfDriverGlobals, IoTarget, DeviceProperty, PoolType, PropertyMemoryAttributes, PropertyMemory);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETQUERYFORINTERFACE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    LPCGUID InterfaceType,
    
    PINTERFACE Interface,
    
    USHORT Size,
    
    USHORT Version,
    
    PVOID InterfaceSpecificData
    );



NTSTATUS
__forceinline
WdfIoTargetQueryForInterface(
    
    WDFIOTARGET IoTarget,
    
    LPCGUID InterfaceType,
    
    PINTERFACE Interface,
    
    USHORT Size,
    
    USHORT Version,
    
    PVOID InterfaceSpecificData
    )
{
    return ((PFN_WDFIOTARGETQUERYFORINTERFACE) WdfFunctions[WdfIoTargetQueryForInterfaceTableIndex])(WdfDriverGlobals, IoTarget, InterfaceType, Interface, Size, Version, InterfaceSpecificData);
}




typedef


PDEVICE_OBJECT
(*PFN_WDFIOTARGETWDMGETTARGETDEVICEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );


PDEVICE_OBJECT
__forceinline
WdfIoTargetWdmGetTargetDeviceObject(
    
    WDFIOTARGET IoTarget
    )
{
    return ((PFN_WDFIOTARGETWDMGETTARGETDEVICEOBJECT) WdfFunctions[WdfIoTargetWdmGetTargetDeviceObjectTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef


PDEVICE_OBJECT
(*PFN_WDFIOTARGETWDMGETTARGETPHYSICALDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );


PDEVICE_OBJECT
__forceinline
WdfIoTargetWdmGetTargetPhysicalDevice(
    
    WDFIOTARGET IoTarget
    )
{
    return ((PFN_WDFIOTARGETWDMGETTARGETPHYSICALDEVICE) WdfFunctions[WdfIoTargetWdmGetTargetPhysicalDeviceTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef


PFILE_OBJECT
(*PFN_WDFIOTARGETWDMGETTARGETFILEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );


PFILE_OBJECT
__forceinline
WdfIoTargetWdmGetTargetFileObject(
    
    WDFIOTARGET IoTarget
    )
{
    return ((PFN_WDFIOTARGETWDMGETTARGETFILEOBJECT) WdfFunctions[WdfIoTargetWdmGetTargetFileObjectTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef


HANDLE
(*PFN_WDFIOTARGETWDMGETTARGETFILEHANDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget
    );


HANDLE
__forceinline
WdfIoTargetWdmGetTargetFileHandle(
    
    WDFIOTARGET IoTarget
    )
{
    return ((PFN_WDFIOTARGETWDMGETTARGETFILEHANDLE) WdfFunctions[WdfIoTargetWdmGetTargetFileHandleTableIndex])(WdfDriverGlobals, IoTarget);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETSENDREADSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    
    PLONGLONG DeviceOffset,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesRead
    );



NTSTATUS
__forceinline
WdfIoTargetSendReadSynchronously(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    
    PLONGLONG DeviceOffset,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesRead
    )
{
    return ((PFN_WDFIOTARGETSENDREADSYNCHRONOUSLY) WdfFunctions[WdfIoTargetSendReadSynchronouslyTableIndex])(WdfDriverGlobals, IoTarget, Request, OutputBuffer, DeviceOffset, RequestOptions, BytesRead);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETFORMATREQUESTFORREAD)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    WDFMEMORY OutputBuffer,
    
    PWDFMEMORY_OFFSET OutputBufferOffset,
    
    PLONGLONG DeviceOffset
    );



NTSTATUS
__forceinline
WdfIoTargetFormatRequestForRead(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    WDFMEMORY OutputBuffer,
    
    PWDFMEMORY_OFFSET OutputBufferOffset,
    
    PLONGLONG DeviceOffset
    )
{
    return ((PFN_WDFIOTARGETFORMATREQUESTFORREAD) WdfFunctions[WdfIoTargetFormatRequestForReadTableIndex])(WdfDriverGlobals, IoTarget, Request, OutputBuffer, OutputBufferOffset, DeviceOffset);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETSENDWRITESYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    PWDF_MEMORY_DESCRIPTOR InputBuffer,
    
    PLONGLONG DeviceOffset,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesWritten
    );



NTSTATUS
__forceinline
WdfIoTargetSendWriteSynchronously(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    PWDF_MEMORY_DESCRIPTOR InputBuffer,
    
    PLONGLONG DeviceOffset,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesWritten
    )
{
    return ((PFN_WDFIOTARGETSENDWRITESYNCHRONOUSLY) WdfFunctions[WdfIoTargetSendWriteSynchronouslyTableIndex])(WdfDriverGlobals, IoTarget, Request, InputBuffer, DeviceOffset, RequestOptions, BytesWritten);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETFORMATREQUESTFORWRITE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    WDFMEMORY InputBuffer,
    
    PWDFMEMORY_OFFSET InputBufferOffset,
    
    PLONGLONG DeviceOffset
    );



NTSTATUS
__forceinline
WdfIoTargetFormatRequestForWrite(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    WDFMEMORY InputBuffer,
    
    PWDFMEMORY_OFFSET InputBufferOffset,
    
    PLONGLONG DeviceOffset
    )
{
    return ((PFN_WDFIOTARGETFORMATREQUESTFORWRITE) WdfFunctions[WdfIoTargetFormatRequestForWriteTableIndex])(WdfDriverGlobals, IoTarget, Request, InputBuffer, InputBufferOffset, DeviceOffset);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETSENDIOCTLSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    ULONG IoctlCode,
    
    PWDF_MEMORY_DESCRIPTOR InputBuffer,
    
    PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesReturned
    );



NTSTATUS
__forceinline
WdfIoTargetSendIoctlSynchronously(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    ULONG IoctlCode,
    
    PWDF_MEMORY_DESCRIPTOR InputBuffer,
    
    PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesReturned
    )
{
    return ((PFN_WDFIOTARGETSENDIOCTLSYNCHRONOUSLY) WdfFunctions[WdfIoTargetSendIoctlSynchronouslyTableIndex])(WdfDriverGlobals, IoTarget, Request, IoctlCode, InputBuffer, OutputBuffer, RequestOptions, BytesReturned);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETFORMATREQUESTFORIOCTL)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    ULONG IoctlCode,
    
    WDFMEMORY InputBuffer,
    
    PWDFMEMORY_OFFSET InputBufferOffset,
    
    WDFMEMORY OutputBuffer,
    
    PWDFMEMORY_OFFSET OutputBufferOffset
    );



NTSTATUS
__forceinline
WdfIoTargetFormatRequestForIoctl(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    ULONG IoctlCode,
    
    WDFMEMORY InputBuffer,
    
    PWDFMEMORY_OFFSET InputBufferOffset,
    
    WDFMEMORY OutputBuffer,
    
    PWDFMEMORY_OFFSET OutputBufferOffset
    )
{
    return ((PFN_WDFIOTARGETFORMATREQUESTFORIOCTL) WdfFunctions[WdfIoTargetFormatRequestForIoctlTableIndex])(WdfDriverGlobals, IoTarget, Request, IoctlCode, InputBuffer, InputBufferOffset, OutputBuffer, OutputBufferOffset);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETSENDINTERNALIOCTLSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    ULONG IoctlCode,
    
    PWDF_MEMORY_DESCRIPTOR InputBuffer,
    
    PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesReturned
    );



NTSTATUS
__forceinline
WdfIoTargetSendInternalIoctlSynchronously(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    
    ULONG IoctlCode,
    
    PWDF_MEMORY_DESCRIPTOR InputBuffer,
    
    PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesReturned
    )
{
    return ((PFN_WDFIOTARGETSENDINTERNALIOCTLSYNCHRONOUSLY) WdfFunctions[WdfIoTargetSendInternalIoctlSynchronouslyTableIndex])(WdfDriverGlobals, IoTarget, Request, IoctlCode, InputBuffer, OutputBuffer, RequestOptions, BytesReturned);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTL)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    ULONG IoctlCode,
    
    WDFMEMORY InputBuffer,
    
    PWDFMEMORY_OFFSET InputBufferOffset,
    
    WDFMEMORY OutputBuffer,
    
    PWDFMEMORY_OFFSET OutputBufferOffset
    );



NTSTATUS
__forceinline
WdfIoTargetFormatRequestForInternalIoctl(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    ULONG IoctlCode,
    
    WDFMEMORY InputBuffer,
    
    PWDFMEMORY_OFFSET InputBufferOffset,
    
    WDFMEMORY OutputBuffer,
    
    PWDFMEMORY_OFFSET OutputBufferOffset
    )
{
    return ((PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTL) WdfFunctions[WdfIoTargetFormatRequestForInternalIoctlTableIndex])(WdfDriverGlobals, IoTarget, Request, IoctlCode, InputBuffer, InputBufferOffset, OutputBuffer, OutputBufferOffset);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETSENDINTERNALIOCTLOTHERSSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    ULONG IoctlCode,
    
    PWDF_MEMORY_DESCRIPTOR OtherArg1,
    
    PWDF_MEMORY_DESCRIPTOR OtherArg2,
    
    PWDF_MEMORY_DESCRIPTOR OtherArg4,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesReturned
    );



NTSTATUS
__forceinline
WdfIoTargetSendInternalIoctlOthersSynchronously(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    ULONG IoctlCode,
    
    PWDF_MEMORY_DESCRIPTOR OtherArg1,
    
    PWDF_MEMORY_DESCRIPTOR OtherArg2,
    
    PWDF_MEMORY_DESCRIPTOR OtherArg4,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PULONG_PTR BytesReturned
    )
{
    return ((PFN_WDFIOTARGETSENDINTERNALIOCTLOTHERSSYNCHRONOUSLY) WdfFunctions[WdfIoTargetSendInternalIoctlOthersSynchronouslyTableIndex])(WdfDriverGlobals, IoTarget, Request, IoctlCode, OtherArg1, OtherArg2, OtherArg4, RequestOptions, BytesReturned);
}




typedef



NTSTATUS
(*PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTLOTHERS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    ULONG IoctlCode,
    
    WDFMEMORY OtherArg1,
    
    PWDFMEMORY_OFFSET OtherArg1Offset,
    
    WDFMEMORY OtherArg2,
    
    PWDFMEMORY_OFFSET OtherArg2Offset,
    
    WDFMEMORY OtherArg4,
    
    PWDFMEMORY_OFFSET OtherArg4Offset
    );



NTSTATUS
__forceinline
WdfIoTargetFormatRequestForInternalIoctlOthers(
    
    WDFIOTARGET IoTarget,
    
    WDFREQUEST Request,
    ULONG IoctlCode,
    
    WDFMEMORY OtherArg1,
    
    PWDFMEMORY_OFFSET OtherArg1Offset,
    
    WDFMEMORY OtherArg2,
    
    PWDFMEMORY_OFFSET OtherArg2Offset,
    
    WDFMEMORY OtherArg4,
    
    PWDFMEMORY_OFFSET OtherArg4Offset
    )
{
    return ((PFN_WDFIOTARGETFORMATREQUESTFORINTERNALIOCTLOTHERS) WdfFunctions[WdfIoTargetFormatRequestForInternalIoctlOthersTableIndex])(WdfDriverGlobals, IoTarget, Request, IoctlCode, OtherArg1, OtherArg1Offset, OtherArg2, OtherArg2Offset, OtherArg4, OtherArg4Offset);
}



#line 1211 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfiotarget.h"


#line 1214 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfiotarget.h"

#line 85 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfio.h"























































typedef enum _WDF_IO_QUEUE_DISPATCH_TYPE {
    WdfIoQueueDispatchInvalid = 0,
    WdfIoQueueDispatchSequential,
    WdfIoQueueDispatchParallel,
    WdfIoQueueDispatchManual,
    WdfIoQueueDispatchMax,
} WDF_IO_QUEUE_DISPATCH_TYPE;









































typedef enum _WDF_IO_QUEUE_STATE {
    WdfIoQueueAcceptRequests = 0x01,
    WdfIoQueueDispatchRequests = 0x02,
    WdfIoQueueNoRequests = 0x04,
    WdfIoQueueDriverNoRequests = 0x08,
    WdfIoQueuePnpHeld = 0x10,
} WDF_IO_QUEUE_STATE;












BOOLEAN
__forceinline
WDF_IO_QUEUE_IDLE(
     WDF_IO_QUEUE_STATE State
    )
{
    return ((State & WdfIoQueueNoRequests) &&
            (State & WdfIoQueueDriverNoRequests)) ? 1: 0;
}





BOOLEAN
__forceinline
WDF_IO_QUEUE_READY(
     WDF_IO_QUEUE_STATE State
    )
{
    return ((State & WdfIoQueueDispatchRequests) &&
        (State & WdfIoQueueAcceptRequests) &&
        ((State & WdfIoQueuePnpHeld)==0)) ? 1: 0;
}






BOOLEAN
__forceinline
WDF_IO_QUEUE_STOPPED(
     WDF_IO_QUEUE_STATE State
    )
{
    return (((State & WdfIoQueueDispatchRequests) == 0) &&
        (State & WdfIoQueueAcceptRequests) &&
        (State & WdfIoQueueDriverNoRequests)) ? 1: 0;

}







BOOLEAN
__forceinline
WDF_IO_QUEUE_DRAINED(
     WDF_IO_QUEUE_STATE State
    )
{
    return ( ((State & WdfIoQueueAcceptRequests)==0) &&
          (State & WdfIoQueueDispatchRequests) &&
          (State & WdfIoQueueNoRequests)  &&
          (State & WdfIoQueueDriverNoRequests) ) ? 1: 0;

}






BOOLEAN
__forceinline
WDF_IO_QUEUE_PURGED(
     WDF_IO_QUEUE_STATE State
    )
{
    return ( ((State & WdfIoQueueAcceptRequests)==0) &&
          (State & WdfIoQueueNoRequests) &&
          (State & WdfIoQueueDriverNoRequests) ) ? 1: 0;

}





typedef



void
EVT_WDF_IO_QUEUE_IO_DEFAULT(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request
    );

typedef EVT_WDF_IO_QUEUE_IO_DEFAULT *PFN_WDF_IO_QUEUE_IO_DEFAULT;


typedef



void
EVT_WDF_IO_QUEUE_IO_STOP(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request,
    
    ULONG ActionFlags
    );

typedef EVT_WDF_IO_QUEUE_IO_STOP *PFN_WDF_IO_QUEUE_IO_STOP;

typedef



void
EVT_WDF_IO_QUEUE_IO_RESUME(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request
    );

typedef EVT_WDF_IO_QUEUE_IO_RESUME *PFN_WDF_IO_QUEUE_IO_RESUME;

typedef



void
EVT_WDF_IO_QUEUE_IO_READ(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request,
    
    size_t Length
    );

typedef EVT_WDF_IO_QUEUE_IO_READ *PFN_WDF_IO_QUEUE_IO_READ;

typedef



void
EVT_WDF_IO_QUEUE_IO_WRITE(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request,
    
    size_t Length
    );

typedef EVT_WDF_IO_QUEUE_IO_WRITE *PFN_WDF_IO_QUEUE_IO_WRITE;

typedef



void
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request,
    
    size_t OutputBufferLength,
    
    size_t InputBufferLength,
    
    ULONG IoControlCode
    );

typedef EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL *PFN_WDF_IO_QUEUE_IO_DEVICE_CONTROL;

typedef



void
EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request,
    
    size_t OutputBufferLength,
    
    size_t InputBufferLength,
    
    ULONG IoControlCode
    );

typedef EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL *PFN_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL;


typedef



void
EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request
    );

typedef EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE *PFN_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE;


typedef



void
EVT_WDF_IO_QUEUE_STATE(
    
    WDFQUEUE Queue,
    
    WDFCONTEXT Context
    );

typedef EVT_WDF_IO_QUEUE_STATE *PFN_WDF_IO_QUEUE_STATE;






typedef struct _WDF_IO_QUEUE_CONFIG {

    ULONG                                       Size;

    WDF_IO_QUEUE_DISPATCH_TYPE                  DispatchType;

    WDF_TRI_STATE                               PowerManaged;

    BOOLEAN                                     AllowZeroLengthRequests;

    BOOLEAN                                     DefaultQueue;

    PFN_WDF_IO_QUEUE_IO_DEFAULT                 EvtIoDefault;

    PFN_WDF_IO_QUEUE_IO_READ                    EvtIoRead;

    PFN_WDF_IO_QUEUE_IO_WRITE                   EvtIoWrite;

    PFN_WDF_IO_QUEUE_IO_DEVICE_CONTROL          EvtIoDeviceControl;

    PFN_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL EvtIoInternalDeviceControl;

    PFN_WDF_IO_QUEUE_IO_STOP                    EvtIoStop;

    PFN_WDF_IO_QUEUE_IO_RESUME                  EvtIoResume;

    PFN_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE       EvtIoCanceledOnQueue;

    union {
        struct {
            ULONG NumberOfPresentedRequests;
        } Parallel;
    } Settings;

} WDF_IO_QUEUE_CONFIG, *PWDF_IO_QUEUE_CONFIG;

void
__forceinline
WDF_IO_QUEUE_CONFIG_INIT(
     PWDF_IO_QUEUE_CONFIG      Config,
     WDF_IO_QUEUE_DISPATCH_TYPE DispatchType
    )
{
    memset((Config),0,(sizeof(WDF_IO_QUEUE_CONFIG)));

    Config->Size = sizeof(WDF_IO_QUEUE_CONFIG);
    Config->PowerManaged = WdfUseDefault;
    Config->DispatchType = DispatchType;
    if (Config->DispatchType == WdfIoQueueDispatchParallel) {
        Config->Settings.Parallel.NumberOfPresentedRequests = (ULONG)-1;    
    }
}

void
__forceinline
WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(
     PWDF_IO_QUEUE_CONFIG      Config,
     WDF_IO_QUEUE_DISPATCH_TYPE DispatchType
    )
{
    memset((Config),0,(sizeof(WDF_IO_QUEUE_CONFIG)));

    Config->Size = sizeof(WDF_IO_QUEUE_CONFIG);
    Config->PowerManaged = WdfUseDefault;
    Config->DefaultQueue = 1;
    Config->DispatchType = DispatchType;
    if (Config->DispatchType == WdfIoQueueDispatchParallel) {
        Config->Settings.Parallel.NumberOfPresentedRequests = (ULONG)-1;    
    }    
}

typedef enum _WDF_IO_FORWARD_PROGRESS_ACTION {
    WdfIoForwardProgressActionInvalid = 0x0,
    WdfIoForwardProgressActionFailRequest,
    WdfIoForwardProgressActionUseReservedRequest
} WDF_IO_FORWARD_PROGRESS_ACTION;

typedef enum _WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY  {
  WdfIoForwardProgressInvalidPolicy =0x0,
  WdfIoForwardProgressReservedPolicyAlwaysUseReservedRequest,
  WdfIoForwardProgressReservedPolicyUseExamine,
  WdfIoForwardProgressReservedPolicyPagingIO
} WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY;

typedef



NTSTATUS
EVT_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request
    );

typedef EVT_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST *PFN_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST;

typedef



NTSTATUS
EVT_WDF_IO_ALLOCATE_REQUEST_RESOURCES(
    
    WDFQUEUE Queue,
    
    WDFREQUEST Request
    );

typedef EVT_WDF_IO_ALLOCATE_REQUEST_RESOURCES *PFN_WDF_IO_ALLOCATE_REQUEST_RESOURCES;

typedef



WDF_IO_FORWARD_PROGRESS_ACTION
EVT_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS(
    
    WDFQUEUE Queue,
    
    PIRP Irp
    );

typedef EVT_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS *PFN_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS;

typedef  struct _WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS {
    union {

        struct {
          PFN_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS     EvtIoWdmIrpForForwardProgress;
        } ExaminePolicy;

    } Policy;
} WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS;

typedef struct _WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY {
    ULONG  Size;

    ULONG TotalForwardProgressRequests;

    
    
    
    WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY ForwardProgressReservedPolicy;
    
    
    
    
    WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS ForwardProgressReservePolicySettings;

    
    
    
    PFN_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST EvtIoAllocateResourcesForReservedRequest;

    
    
    
    PFN_WDF_IO_ALLOCATE_REQUEST_RESOURCES  EvtIoAllocateRequestResources;       

}  WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY, *PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY;

void
__forceinline
WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_DEFAULT_INIT(
     PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY Policy,
     ULONG TotalForwardProgressRequests
    )
{
    memset((Policy),0,(sizeof(WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY)));

    Policy->Size = sizeof(WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY);
    Policy->TotalForwardProgressRequests = TotalForwardProgressRequests;
    Policy->ForwardProgressReservedPolicy = WdfIoForwardProgressReservedPolicyAlwaysUseReservedRequest;
}


void
__forceinline
WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT(
     PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY      Policy,
     ULONG TotalForwardProgressRequests,
     PFN_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS EvtIoWdmIrpForForwardProgress
    )
{
    memset((Policy),0,(sizeof(WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY)));

    Policy->Size = sizeof(WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY);
    Policy->TotalForwardProgressRequests = TotalForwardProgressRequests;
    Policy->ForwardProgressReservedPolicy =  WdfIoForwardProgressReservedPolicyUseExamine;
    Policy->ForwardProgressReservePolicySettings.Policy.ExaminePolicy.EvtIoWdmIrpForForwardProgress =
            EvtIoWdmIrpForForwardProgress;
}

void
__forceinline
WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT(
     PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY      Policy,
     ULONG TotalForwardProgressRequests
    )
{
    memset((Policy),0,(sizeof(WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY)));

    Policy->Size = sizeof(WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY);
    Policy->TotalForwardProgressRequests = TotalForwardProgressRequests;
    Policy->ForwardProgressReservedPolicy = WdfIoForwardProgressReservedPolicyPagingIO;
}





typedef



NTSTATUS
(*PFN_WDFIOQUEUECREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_IO_QUEUE_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES QueueAttributes,
    
    WDFQUEUE* Queue
    );



NTSTATUS
__forceinline
WdfIoQueueCreate(
    
    WDFDEVICE Device,
    
    PWDF_IO_QUEUE_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES QueueAttributes,
    
    WDFQUEUE* Queue
    )
{
    return ((PFN_WDFIOQUEUECREATE) WdfFunctions[WdfIoQueueCreateTableIndex])(WdfDriverGlobals, Device, Config, QueueAttributes, Queue);
}




typedef


WDF_IO_QUEUE_STATE
(*PFN_WDFIOQUEUEGETSTATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    PULONG QueueRequests,
    
    PULONG DriverRequests
    );


WDF_IO_QUEUE_STATE
__forceinline
WdfIoQueueGetState(
    
    WDFQUEUE Queue,
    
    PULONG QueueRequests,
    
    PULONG DriverRequests
    )
{
    return ((PFN_WDFIOQUEUEGETSTATE) WdfFunctions[WdfIoQueueGetStateTableIndex])(WdfDriverGlobals, Queue, QueueRequests, DriverRequests);
}




typedef


void
(*PFN_WDFIOQUEUESTART)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue
    );


void
__forceinline
WdfIoQueueStart(
    
    WDFQUEUE Queue
    )
{
    ((PFN_WDFIOQUEUESTART) WdfFunctions[WdfIoQueueStartTableIndex])(WdfDriverGlobals, Queue);
}




typedef


void
(*PFN_WDFIOQUEUESTOP)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    
    PFN_WDF_IO_QUEUE_STATE StopComplete,
    
    
    WDFCONTEXT Context
    );


void
__forceinline
WdfIoQueueStop(
    
    WDFQUEUE Queue,
    
    
    PFN_WDF_IO_QUEUE_STATE StopComplete,
    
    
    WDFCONTEXT Context
    )
{
    ((PFN_WDFIOQUEUESTOP) WdfFunctions[WdfIoQueueStopTableIndex])(WdfDriverGlobals, Queue, StopComplete, Context);
}




typedef


void
(*PFN_WDFIOQUEUESTOPSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue
    );


void
__forceinline
WdfIoQueueStopSynchronously(
    
    WDFQUEUE Queue
    )
{
    ((PFN_WDFIOQUEUESTOPSYNCHRONOUSLY) WdfFunctions[WdfIoQueueStopSynchronouslyTableIndex])(WdfDriverGlobals, Queue);
}




typedef


WDFDEVICE
(*PFN_WDFIOQUEUEGETDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue
    );


WDFDEVICE
__forceinline
WdfIoQueueGetDevice(
    
    WDFQUEUE Queue
    )
{
    return ((PFN_WDFIOQUEUEGETDEVICE) WdfFunctions[WdfIoQueueGetDeviceTableIndex])(WdfDriverGlobals, Queue);
}




typedef



NTSTATUS
(*PFN_WDFIOQUEUERETRIEVENEXTREQUEST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    WDFREQUEST* OutRequest
    );



NTSTATUS
__forceinline
WdfIoQueueRetrieveNextRequest(
    
    WDFQUEUE Queue,
    
    WDFREQUEST* OutRequest
    )
{
    return ((PFN_WDFIOQUEUERETRIEVENEXTREQUEST) WdfFunctions[WdfIoQueueRetrieveNextRequestTableIndex])(WdfDriverGlobals, Queue, OutRequest);
}




typedef



NTSTATUS
(*PFN_WDFIOQUEUERETRIEVEREQUESTBYFILEOBJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    WDFFILEOBJECT FileObject,
    
    WDFREQUEST* OutRequest
    );



NTSTATUS
__forceinline
WdfIoQueueRetrieveRequestByFileObject(
    
    WDFQUEUE Queue,
    
    WDFFILEOBJECT FileObject,
    
    WDFREQUEST* OutRequest
    )
{
    return ((PFN_WDFIOQUEUERETRIEVEREQUESTBYFILEOBJECT) WdfFunctions[WdfIoQueueRetrieveRequestByFileObjectTableIndex])(WdfDriverGlobals, Queue, FileObject, OutRequest);
}




typedef



NTSTATUS
(*PFN_WDFIOQUEUEFINDREQUEST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    WDFREQUEST FoundRequest,
    
    WDFFILEOBJECT FileObject,
    
    PWDF_REQUEST_PARAMETERS Parameters,
    
    WDFREQUEST* OutRequest
    );



NTSTATUS
__forceinline
WdfIoQueueFindRequest(
    
    WDFQUEUE Queue,
    
    WDFREQUEST FoundRequest,
    
    WDFFILEOBJECT FileObject,
    
    PWDF_REQUEST_PARAMETERS Parameters,
    
    WDFREQUEST* OutRequest
    )
{
    return ((PFN_WDFIOQUEUEFINDREQUEST) WdfFunctions[WdfIoQueueFindRequestTableIndex])(WdfDriverGlobals, Queue, FoundRequest, FileObject, Parameters, OutRequest);
}




typedef



NTSTATUS
(*PFN_WDFIOQUEUERETRIEVEFOUNDREQUEST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    WDFREQUEST FoundRequest,
    
    WDFREQUEST* OutRequest
    );



NTSTATUS
__forceinline
WdfIoQueueRetrieveFoundRequest(
    
    WDFQUEUE Queue,
    
    WDFREQUEST FoundRequest,
    
    WDFREQUEST* OutRequest
    )
{
    return ((PFN_WDFIOQUEUERETRIEVEFOUNDREQUEST) WdfFunctions[WdfIoQueueRetrieveFoundRequestTableIndex])(WdfDriverGlobals, Queue, FoundRequest, OutRequest);
}




typedef


void
(*PFN_WDFIOQUEUEDRAINSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue
    );


void
__forceinline
WdfIoQueueDrainSynchronously(
    
    WDFQUEUE Queue
    )
{
    ((PFN_WDFIOQUEUEDRAINSYNCHRONOUSLY) WdfFunctions[WdfIoQueueDrainSynchronouslyTableIndex])(WdfDriverGlobals, Queue);
}




typedef


void
(*PFN_WDFIOQUEUEDRAIN)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    
    PFN_WDF_IO_QUEUE_STATE DrainComplete,
    
    
    WDFCONTEXT Context
    );


void
__forceinline
WdfIoQueueDrain(
    
    WDFQUEUE Queue,
    
    
    PFN_WDF_IO_QUEUE_STATE DrainComplete,
    
    
    WDFCONTEXT Context
    )
{
    ((PFN_WDFIOQUEUEDRAIN) WdfFunctions[WdfIoQueueDrainTableIndex])(WdfDriverGlobals, Queue, DrainComplete, Context);
}




typedef


void
(*PFN_WDFIOQUEUEPURGESYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue
    );


void
__forceinline
WdfIoQueuePurgeSynchronously(
    
    WDFQUEUE Queue
    )
{
    ((PFN_WDFIOQUEUEPURGESYNCHRONOUSLY) WdfFunctions[WdfIoQueuePurgeSynchronouslyTableIndex])(WdfDriverGlobals, Queue);
}




typedef


void
(*PFN_WDFIOQUEUEPURGE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    
    PFN_WDF_IO_QUEUE_STATE PurgeComplete,
    
    
    WDFCONTEXT Context
    );


void
__forceinline
WdfIoQueuePurge(
    
    WDFQUEUE Queue,
    
    
    PFN_WDF_IO_QUEUE_STATE PurgeComplete,
    
    
    WDFCONTEXT Context
    )
{
    ((PFN_WDFIOQUEUEPURGE) WdfFunctions[WdfIoQueuePurgeTableIndex])(WdfDriverGlobals, Queue, PurgeComplete, Context);
}




typedef



NTSTATUS
(*PFN_WDFIOQUEUEREADYNOTIFY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    PFN_WDF_IO_QUEUE_STATE QueueReady,
    
    WDFCONTEXT Context
    );



NTSTATUS
__forceinline
WdfIoQueueReadyNotify(
    
    WDFQUEUE Queue,
    
    PFN_WDF_IO_QUEUE_STATE QueueReady,
    
    WDFCONTEXT Context
    )
{
    return ((PFN_WDFIOQUEUEREADYNOTIFY) WdfFunctions[WdfIoQueueReadyNotifyTableIndex])(WdfDriverGlobals, Queue, QueueReady, Context);
}




typedef



NTSTATUS
(*PFN_WDFIOQUEUEASSIGNFORWARDPROGRESSPOLICY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFQUEUE Queue,
    
    PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY ForwardProgressPolicy
    );



NTSTATUS
__forceinline
WdfIoQueueAssignForwardProgressPolicy(
    
    WDFQUEUE Queue,
    
    PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY ForwardProgressPolicy
    )
{
    return ((PFN_WDFIOQUEUEASSIGNFORWARDPROGRESSPOLICY) WdfFunctions[WdfIoQueueAssignForwardProgressPolicyTableIndex])(WdfDriverGlobals, Queue, ForwardProgressPolicy);
}



#line 1088 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfio.h"


#line 1091 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfio.h"

#line 86 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"


#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdffdo.h"
































typedef



NTSTATUS
EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS(
    
    WDFDEVICE Device,
    
    WDFIORESREQLIST IoResourceRequirementsList
    );

typedef EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS *PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS;

typedef



NTSTATUS
EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES(
    
    WDFDEVICE Device,
    
    WDFCMRESLIST ResourcesRaw,
    
    WDFCMRESLIST ResourcesTranslated
    );

typedef EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES *PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES;

typedef struct _WDF_FDO_EVENT_CALLBACKS {
    
    
    
    ULONG Size;

    PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtDeviceFilterAddResourceRequirements;

    PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtDeviceFilterRemoveResourceRequirements;

    PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES EvtDeviceRemoveAddedResources;

} WDF_FDO_EVENT_CALLBACKS, *PWDF_FDO_EVENT_CALLBACKS;

void
__forceinline
WDF_FDO_EVENT_CALLBACKS_INIT(
     PWDF_FDO_EVENT_CALLBACKS Callbacks
    )
{
    memset((Callbacks),0,(sizeof(WDF_FDO_EVENT_CALLBACKS)));
    Callbacks->Size = sizeof(WDF_FDO_EVENT_CALLBACKS);
}




typedef


PDEVICE_OBJECT
(*PFN_WDFFDOINITWDMGETPHYSICALDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit
    );


PDEVICE_OBJECT
__forceinline
WdfFdoInitWdmGetPhysicalDevice(
    
    PWDFDEVICE_INIT DeviceInit
    )
{
    return ((PFN_WDFFDOINITWDMGETPHYSICALDEVICE) WdfFunctions[WdfFdoInitWdmGetPhysicalDeviceTableIndex])(WdfDriverGlobals, DeviceInit);
}




typedef



NTSTATUS
(*PFN_WDFFDOINITOPENREGISTRYKEY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    ULONG DeviceInstanceKeyType,
    
    ACCESS_MASK DesiredAccess,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    );



NTSTATUS
__forceinline
WdfFdoInitOpenRegistryKey(
    
    PWDFDEVICE_INIT DeviceInit,
    
    ULONG DeviceInstanceKeyType,
    
    ACCESS_MASK DesiredAccess,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    )
{
    return ((PFN_WDFFDOINITOPENREGISTRYKEY) WdfFunctions[WdfFdoInitOpenRegistryKeyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceInstanceKeyType, DesiredAccess, KeyAttributes, Key);
}




typedef



NTSTATUS
(*PFN_WDFFDOINITQUERYPROPERTY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    ULONG BufferLength,
    
    PVOID PropertyBuffer,
    
    PULONG ResultLength
    );



NTSTATUS
__forceinline
WdfFdoInitQueryProperty(
    
    PWDFDEVICE_INIT DeviceInit,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    ULONG BufferLength,
    
    PVOID PropertyBuffer,
    
    PULONG ResultLength
    )
{
    return ((PFN_WDFFDOINITQUERYPROPERTY) WdfFunctions[WdfFdoInitQueryPropertyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceProperty, BufferLength, PropertyBuffer, ResultLength);
}




typedef



NTSTATUS
(*PFN_WDFFDOINITALLOCANDQUERYPROPERTY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    
    WDFMEMORY* PropertyMemory
    );



NTSTATUS
__forceinline
WdfFdoInitAllocAndQueryProperty(
    
    PWDFDEVICE_INIT DeviceInit,
    
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    
    WDFMEMORY* PropertyMemory
    )
{
    return ((PFN_WDFFDOINITALLOCANDQUERYPROPERTY) WdfFunctions[WdfFdoInitAllocAndQueryPropertyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceProperty, PoolType, PropertyMemoryAttributes, PropertyMemory);
}




typedef


void
(*PFN_WDFFDOINITSETEVENTCALLBACKS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_FDO_EVENT_CALLBACKS FdoEventCallbacks
    );


void
__forceinline
WdfFdoInitSetEventCallbacks(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_FDO_EVENT_CALLBACKS FdoEventCallbacks
    )
{
    ((PFN_WDFFDOINITSETEVENTCALLBACKS) WdfFunctions[WdfFdoInitSetEventCallbacksTableIndex])(WdfDriverGlobals, DeviceInit, FdoEventCallbacks);
}




typedef


void
(*PFN_WDFFDOINITSETFILTER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit
    );


void
__forceinline
WdfFdoInitSetFilter(
    
    PWDFDEVICE_INIT DeviceInit
    )
{
    ((PFN_WDFFDOINITSETFILTER) WdfFunctions[WdfFdoInitSetFilterTableIndex])(WdfDriverGlobals, DeviceInit);
}




typedef


void
(*PFN_WDFFDOINITSETDEFAULTCHILDLISTCONFIG)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_CHILD_LIST_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES DefaultChildListAttributes
    );


void
__forceinline
WdfFdoInitSetDefaultChildListConfig(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_CHILD_LIST_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES DefaultChildListAttributes
    )
{
    ((PFN_WDFFDOINITSETDEFAULTCHILDLISTCONFIG) WdfFunctions[WdfFdoInitSetDefaultChildListConfigTableIndex])(WdfDriverGlobals, DeviceInit, Config, DefaultChildListAttributes);
}




typedef



NTSTATUS
(*PFN_WDFFDOQUERYFORINTERFACE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Fdo,
    
    LPCGUID InterfaceType,
    
    PINTERFACE Interface,
    
    USHORT Size,
    
    USHORT Version,
    
    PVOID InterfaceSpecificData
    );



NTSTATUS
__forceinline
WdfFdoQueryForInterface(
    
    WDFDEVICE Fdo,
    
    LPCGUID InterfaceType,
    
    PINTERFACE Interface,
    
    USHORT Size,
    
    USHORT Version,
    
    PVOID InterfaceSpecificData
    )
{
    return ((PFN_WDFFDOQUERYFORINTERFACE) WdfFunctions[WdfFdoQueryForInterfaceTableIndex])(WdfDriverGlobals, Fdo, InterfaceType, Interface, Size, Version, InterfaceSpecificData);
}




typedef


WDFCHILDLIST
(*PFN_WDFFDOGETDEFAULTCHILDLIST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Fdo
    );


WDFCHILDLIST
__forceinline
WdfFdoGetDefaultChildList(
    
    WDFDEVICE Fdo
    )
{
    return ((PFN_WDFFDOGETDEFAULTCHILDLIST) WdfFunctions[WdfFdoGetDefaultChildListTableIndex])(WdfDriverGlobals, Fdo);
}




typedef



NTSTATUS
(*PFN_WDFFDOADDSTATICCHILD)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Fdo,
    
    WDFDEVICE Child
    );



NTSTATUS
__forceinline
WdfFdoAddStaticChild(
    
    WDFDEVICE Fdo,
    
    WDFDEVICE Child
    )
{
    return ((PFN_WDFFDOADDSTATICCHILD) WdfFunctions[WdfFdoAddStaticChildTableIndex])(WdfDriverGlobals, Fdo, Child);
}




typedef


void
(*PFN_WDFFDOLOCKSTATICCHILDLISTFORITERATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Fdo
    );


void
__forceinline
WdfFdoLockStaticChildListForIteration(
    
    WDFDEVICE Fdo
    )
{
    ((PFN_WDFFDOLOCKSTATICCHILDLISTFORITERATION) WdfFunctions[WdfFdoLockStaticChildListForIterationTableIndex])(WdfDriverGlobals, Fdo);
}




typedef



WDFDEVICE
(*PFN_WDFFDORETRIEVENEXTSTATICCHILD)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Fdo,
    
    WDFDEVICE PreviousChild,
    
    ULONG Flags
    );



WDFDEVICE
__forceinline
WdfFdoRetrieveNextStaticChild(
    
    WDFDEVICE Fdo,
    
    WDFDEVICE PreviousChild,
    
    ULONG Flags
    )
{
    return ((PFN_WDFFDORETRIEVENEXTSTATICCHILD) WdfFunctions[WdfFdoRetrieveNextStaticChildTableIndex])(WdfDriverGlobals, Fdo, PreviousChild, Flags);
}




typedef


void
(*PFN_WDFFDOUNLOCKSTATICCHILDLISTFROMITERATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Fdo
    );


void
__forceinline
WdfFdoUnlockStaticChildListFromIteration(
    
    WDFDEVICE Fdo
    )
{
    ((PFN_WDFFDOUNLOCKSTATICCHILDLISTFROMITERATION) WdfFunctions[WdfFdoUnlockStaticChildListFromIterationTableIndex])(WdfDriverGlobals, Fdo);
}



#line 521 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdffdo.h"


#line 524 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdffdo.h"

#line 89 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfpdo.h"































typedef



NTSTATUS
EVT_WDF_DEVICE_RESOURCES_QUERY(
    
    WDFDEVICE Device,
    
    WDFCMRESLIST Resources
    );

typedef EVT_WDF_DEVICE_RESOURCES_QUERY *PFN_WDF_DEVICE_RESOURCES_QUERY;

typedef



NTSTATUS
EVT_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY(
    
    WDFDEVICE Device,
    
    WDFIORESREQLIST IoResourceRequirementsList
    );

typedef EVT_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY *PFN_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY;

typedef



NTSTATUS
EVT_WDF_DEVICE_EJECT(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_EJECT *PFN_WDF_DEVICE_EJECT;

typedef



NTSTATUS
EVT_WDF_DEVICE_SET_LOCK(
    
    WDFDEVICE Device,
    
    BOOLEAN IsLocked
    );

typedef EVT_WDF_DEVICE_SET_LOCK *PFN_WDF_DEVICE_SET_LOCK;

typedef



NTSTATUS
EVT_WDF_DEVICE_ENABLE_WAKE_AT_BUS(
    
    WDFDEVICE Device,
    
    SYSTEM_POWER_STATE PowerState
    );

typedef EVT_WDF_DEVICE_ENABLE_WAKE_AT_BUS *PFN_WDF_DEVICE_ENABLE_WAKE_AT_BUS;

typedef



void
EVT_WDF_DEVICE_DISABLE_WAKE_AT_BUS(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_DISABLE_WAKE_AT_BUS *PFN_WDF_DEVICE_DISABLE_WAKE_AT_BUS;

typedef struct _WDF_PDO_EVENT_CALLBACKS {
    
    
    
    ULONG Size;

    
    
    
    PFN_WDF_DEVICE_RESOURCES_QUERY EvtDeviceResourcesQuery;

    
    
    
    PFN_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY EvtDeviceResourceRequirementsQuery;

    
    
    
    PFN_WDF_DEVICE_EJECT EvtDeviceEject;

    
    
    
    PFN_WDF_DEVICE_SET_LOCK EvtDeviceSetLock;

    
    
    
    
    PFN_WDF_DEVICE_ENABLE_WAKE_AT_BUS       EvtDeviceEnableWakeAtBus;

    
    
    
    
    PFN_WDF_DEVICE_DISABLE_WAKE_AT_BUS      EvtDeviceDisableWakeAtBus;

} WDF_PDO_EVENT_CALLBACKS, *PWDF_PDO_EVENT_CALLBACKS;

void
__forceinline
WDF_PDO_EVENT_CALLBACKS_INIT(
     PWDF_PDO_EVENT_CALLBACKS Callbacks
    )
{
    memset((Callbacks),0,(sizeof(WDF_PDO_EVENT_CALLBACKS)));
    Callbacks->Size = sizeof(WDF_PDO_EVENT_CALLBACKS);
}




typedef



PWDFDEVICE_INIT
(*PFN_WDFPDOINITALLOCATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE ParentDevice
    );



PWDFDEVICE_INIT
__forceinline
WdfPdoInitAllocate(
    
    WDFDEVICE ParentDevice
    )
{
    return ((PFN_WDFPDOINITALLOCATE) WdfFunctions[WdfPdoInitAllocateTableIndex])(WdfDriverGlobals, ParentDevice);
}




typedef


void
(*PFN_WDFPDOINITSETEVENTCALLBACKS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_PDO_EVENT_CALLBACKS DispatchTable
    );


void
__forceinline
WdfPdoInitSetEventCallbacks(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PWDF_PDO_EVENT_CALLBACKS DispatchTable
    )
{
    ((PFN_WDFPDOINITSETEVENTCALLBACKS) WdfFunctions[WdfPdoInitSetEventCallbacksTableIndex])(WdfDriverGlobals, DeviceInit, DispatchTable);
}




typedef



NTSTATUS
(*PFN_WDFPDOINITASSIGNDEVICEID)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING DeviceID
    );



NTSTATUS
__forceinline
WdfPdoInitAssignDeviceID(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING DeviceID
    )
{
    return ((PFN_WDFPDOINITASSIGNDEVICEID) WdfFunctions[WdfPdoInitAssignDeviceIDTableIndex])(WdfDriverGlobals, DeviceInit, DeviceID);
}




typedef



NTSTATUS
(*PFN_WDFPDOINITASSIGNINSTANCEID)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING InstanceID
    );



NTSTATUS
__forceinline
WdfPdoInitAssignInstanceID(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING InstanceID
    )
{
    return ((PFN_WDFPDOINITASSIGNINSTANCEID) WdfFunctions[WdfPdoInitAssignInstanceIDTableIndex])(WdfDriverGlobals, DeviceInit, InstanceID);
}




typedef



NTSTATUS
(*PFN_WDFPDOINITADDHARDWAREID)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING HardwareID
    );



NTSTATUS
__forceinline
WdfPdoInitAddHardwareID(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING HardwareID
    )
{
    return ((PFN_WDFPDOINITADDHARDWAREID) WdfFunctions[WdfPdoInitAddHardwareIDTableIndex])(WdfDriverGlobals, DeviceInit, HardwareID);
}




typedef



NTSTATUS
(*PFN_WDFPDOINITADDCOMPATIBLEID)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING CompatibleID
    );



NTSTATUS
__forceinline
WdfPdoInitAddCompatibleID(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING CompatibleID
    )
{
    return ((PFN_WDFPDOINITADDCOMPATIBLEID) WdfFunctions[WdfPdoInitAddCompatibleIDTableIndex])(WdfDriverGlobals, DeviceInit, CompatibleID);
}




typedef



NTSTATUS
(*PFN_WDFPDOINITASSIGNCONTAINERID)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING ContainerID
    );



NTSTATUS
__forceinline
WdfPdoInitAssignContainerID(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING ContainerID
    )
{
    return ((PFN_WDFPDOINITASSIGNCONTAINERID) WdfFunctions[WdfPdoInitAssignContainerIDTableIndex])(WdfDriverGlobals, DeviceInit, ContainerID);
}




typedef



NTSTATUS
(*PFN_WDFPDOINITADDDEVICETEXT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING DeviceDescription,
    
    PCUNICODE_STRING DeviceLocation,
    
    LCID LocaleId
    );



NTSTATUS
__forceinline
WdfPdoInitAddDeviceText(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PCUNICODE_STRING DeviceDescription,
    
    PCUNICODE_STRING DeviceLocation,
    
    LCID LocaleId
    )
{
    return ((PFN_WDFPDOINITADDDEVICETEXT) WdfFunctions[WdfPdoInitAddDeviceTextTableIndex])(WdfDriverGlobals, DeviceInit, DeviceDescription, DeviceLocation, LocaleId);
}




typedef


void
(*PFN_WDFPDOINITSETDEFAULTLOCALE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    LCID LocaleId
    );


void
__forceinline
WdfPdoInitSetDefaultLocale(
    
    PWDFDEVICE_INIT DeviceInit,
    
    LCID LocaleId
    )
{
    ((PFN_WDFPDOINITSETDEFAULTLOCALE) WdfFunctions[WdfPdoInitSetDefaultLocaleTableIndex])(WdfDriverGlobals, DeviceInit, LocaleId);
}




typedef



NTSTATUS
(*PFN_WDFPDOINITASSIGNRAWDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    const GUID* DeviceClassGuid
    );



NTSTATUS
__forceinline
WdfPdoInitAssignRawDevice(
    
    PWDFDEVICE_INIT DeviceInit,
    
    const GUID* DeviceClassGuid
    )
{
    return ((PFN_WDFPDOINITASSIGNRAWDEVICE) WdfFunctions[WdfPdoInitAssignRawDeviceTableIndex])(WdfDriverGlobals, DeviceInit, DeviceClassGuid);
}




typedef


void
(*PFN_WDFPDOINITALLOWFORWARDINGREQUESTTOPARENT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit
    );


void
__forceinline
WdfPdoInitAllowForwardingRequestToParent(
    
    PWDFDEVICE_INIT DeviceInit
    )
{
    ((PFN_WDFPDOINITALLOWFORWARDINGREQUESTTOPARENT) WdfFunctions[WdfPdoInitAllowForwardingRequestToParentTableIndex])(WdfDriverGlobals, DeviceInit);
}




typedef



NTSTATUS
(*PFN_WDFPDOMARKMISSING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );



NTSTATUS
__forceinline
WdfPdoMarkMissing(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFPDOMARKMISSING) WdfFunctions[WdfPdoMarkMissingTableIndex])(WdfDriverGlobals, Device);
}




typedef


void
(*PFN_WDFPDOREQUESTEJECT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


void
__forceinline
WdfPdoRequestEject(
    
    WDFDEVICE Device
    )
{
    ((PFN_WDFPDOREQUESTEJECT) WdfFunctions[WdfPdoRequestEjectTableIndex])(WdfDriverGlobals, Device);
}




typedef


WDFDEVICE
(*PFN_WDFPDOGETPARENT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


WDFDEVICE
__forceinline
WdfPdoGetParent(
    
    WDFDEVICE Device
    )
{
    return ((PFN_WDFPDOGETPARENT) WdfFunctions[WdfPdoGetParentTableIndex])(WdfDriverGlobals, Device);
}




typedef



NTSTATUS
(*PFN_WDFPDORETRIEVEIDENTIFICATIONDESCRIPTION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
    );



NTSTATUS
__forceinline
WdfPdoRetrieveIdentificationDescription(
    
    WDFDEVICE Device,
    
    PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription
    )
{
    return ((PFN_WDFPDORETRIEVEIDENTIFICATIONDESCRIPTION) WdfFunctions[WdfPdoRetrieveIdentificationDescriptionTableIndex])(WdfDriverGlobals, Device, IdentificationDescription);
}




typedef



NTSTATUS
(*PFN_WDFPDORETRIEVEADDRESSDESCRIPTION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    );



NTSTATUS
__forceinline
WdfPdoRetrieveAddressDescription(
    
    WDFDEVICE Device,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    )
{
    return ((PFN_WDFPDORETRIEVEADDRESSDESCRIPTION) WdfFunctions[WdfPdoRetrieveAddressDescriptionTableIndex])(WdfDriverGlobals, Device, AddressDescription);
}




typedef



NTSTATUS
(*PFN_WDFPDOUPDATEADDRESSDESCRIPTION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    );



NTSTATUS
__forceinline
WdfPdoUpdateAddressDescription(
    
    WDFDEVICE Device,
    
    PWDF_CHILD_ADDRESS_DESCRIPTION_HEADER AddressDescription
    )
{
    return ((PFN_WDFPDOUPDATEADDRESSDESCRIPTION) WdfFunctions[WdfPdoUpdateAddressDescriptionTableIndex])(WdfDriverGlobals, Device, AddressDescription);
}




typedef



NTSTATUS
(*PFN_WDFPDOADDEJECTIONRELATIONSPHYSICALDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT PhysicalDevice
    );



NTSTATUS
__forceinline
WdfPdoAddEjectionRelationsPhysicalDevice(
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT PhysicalDevice
    )
{
    return ((PFN_WDFPDOADDEJECTIONRELATIONSPHYSICALDEVICE) WdfFunctions[WdfPdoAddEjectionRelationsPhysicalDeviceTableIndex])(WdfDriverGlobals, Device, PhysicalDevice);
}




typedef


void
(*PFN_WDFPDOREMOVEEJECTIONRELATIONSPHYSICALDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT PhysicalDevice
    );


void
__forceinline
WdfPdoRemoveEjectionRelationsPhysicalDevice(
    
    WDFDEVICE Device,
    
    PDEVICE_OBJECT PhysicalDevice
    )
{
    ((PFN_WDFPDOREMOVEEJECTIONRELATIONSPHYSICALDEVICE) WdfFunctions[WdfPdoRemoveEjectionRelationsPhysicalDeviceTableIndex])(WdfDriverGlobals, Device, PhysicalDevice);
}




typedef


void
(*PFN_WDFPDOCLEAREJECTIONRELATIONSDEVICES)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


void
__forceinline
WdfPdoClearEjectionRelationsDevices(
    
    WDFDEVICE Device
    )
{
    ((PFN_WDFPDOCLEAREJECTIONRELATIONSDEVICES) WdfFunctions[WdfPdoClearEjectionRelationsDevicesTableIndex])(WdfDriverGlobals, Device);
}



#line 755 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfpdo.h"


#line 758 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfpdo.h"

#line 90 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcontrol.h"






























typedef



void
EVT_WDF_DEVICE_SHUTDOWN_NOTIFICATION(
    
    WDFDEVICE Device
    );

typedef EVT_WDF_DEVICE_SHUTDOWN_NOTIFICATION *PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION;

typedef enum _WDF_DEVICE_SHUTDOWN_FLAGS {
    WdfDeviceShutdown = 0x01,
    WdfDeviceLastChanceShutdown = 0x02,
} WDF_DEVICE_SHUTDOWN_FLAGS;






typedef



PWDFDEVICE_INIT
(*PFN_WDFCONTROLDEVICEINITALLOCATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDRIVER Driver,
    
    const UNICODE_STRING* SDDLString
    );



PWDFDEVICE_INIT
__forceinline
WdfControlDeviceInitAllocate(
    
    WDFDRIVER Driver,
    
    const UNICODE_STRING* SDDLString
    )
{
    return ((PFN_WDFCONTROLDEVICEINITALLOCATE) WdfFunctions[WdfControlDeviceInitAllocateTableIndex])(WdfDriverGlobals, Driver, SDDLString);
}




typedef


void
(*PFN_WDFCONTROLDEVICEINITSETSHUTDOWNNOTIFICATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PWDFDEVICE_INIT DeviceInit,
    
    PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION Notification,
    
    UCHAR Flags
    );


void
__forceinline
WdfControlDeviceInitSetShutdownNotification(
    
    PWDFDEVICE_INIT DeviceInit,
    
    PFN_WDF_DEVICE_SHUTDOWN_NOTIFICATION Notification,
    
    UCHAR Flags
    )
{
    ((PFN_WDFCONTROLDEVICEINITSETSHUTDOWNNOTIFICATION) WdfFunctions[WdfControlDeviceInitSetShutdownNotificationTableIndex])(WdfDriverGlobals, DeviceInit, Notification, Flags);
}




typedef


void
(*PFN_WDFCONTROLFINISHINITIALIZING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device
    );


void
__forceinline
WdfControlFinishInitializing(
    
    WDFDEVICE Device
    )
{
    ((PFN_WDFCONTROLFINISHINITIALIZING) WdfFunctions[WdfControlFinishInitializingTableIndex])(WdfDriverGlobals, Device);
}



#line 142 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcontrol.h"


#line 145 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfcontrol.h"

#line 91 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"

#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\WdfWMI.h"





























typedef enum _WDF_WMI_PROVIDER_CONTROL {
    WdfWmiControlInvalid = 0,
    WdfWmiEventControl,
    WdfWmiInstanceControl,
} WDF_WMI_PROVIDER_CONTROL;













typedef enum _WDF_WMI_PROVIDER_FLAGS {
    WdfWmiProviderEventOnly = 0x0001,
    WdfWmiProviderExpensive = 0x0002,
    WdfWmiProviderTracing =   0x0004,
    WdfWmiProviderValidFlags = WdfWmiProviderEventOnly | WdfWmiProviderExpensive | WdfWmiProviderTracing,
} WDF_WMI_PROVIDER_FLAGS;



typedef



NTSTATUS
EVT_WDF_WMI_INSTANCE_QUERY_INSTANCE(
    
    WDFWMIINSTANCE WmiInstance,
    
    ULONG OutBufferSize,
    
    PVOID OutBuffer,
    
    PULONG BufferUsed
    );

typedef EVT_WDF_WMI_INSTANCE_QUERY_INSTANCE *PFN_WDF_WMI_INSTANCE_QUERY_INSTANCE;

typedef



NTSTATUS
EVT_WDF_WMI_INSTANCE_SET_INSTANCE(
    
    WDFWMIINSTANCE WmiInstance,
    
    ULONG InBufferSize,
    
    PVOID InBuffer
    );

typedef EVT_WDF_WMI_INSTANCE_SET_INSTANCE *PFN_WDF_WMI_INSTANCE_SET_INSTANCE;

typedef



NTSTATUS
EVT_WDF_WMI_INSTANCE_SET_ITEM(
    
    WDFWMIINSTANCE WmiInstance,
    
    ULONG DataItemId,
    
    ULONG InBufferSize,
    
    PVOID InBuffer
    );

typedef EVT_WDF_WMI_INSTANCE_SET_ITEM *PFN_WDF_WMI_INSTANCE_SET_ITEM;

typedef



NTSTATUS
EVT_WDF_WMI_INSTANCE_EXECUTE_METHOD(
    
    WDFWMIINSTANCE WmiInstance,
    
    ULONG MethodId,
    
    ULONG InBufferSize,
    
    ULONG OutBufferSize,
    
    
    PVOID Buffer,
    
    PULONG BufferUsed
    );

typedef EVT_WDF_WMI_INSTANCE_EXECUTE_METHOD *PFN_WDF_WMI_INSTANCE_EXECUTE_METHOD;

typedef



NTSTATUS
EVT_WDF_WMI_PROVIDER_FUNCTION_CONTROL(
    
    WDFWMIPROVIDER WmiProvider,
    
    WDF_WMI_PROVIDER_CONTROL Control,
    
    BOOLEAN Enable
    );

typedef EVT_WDF_WMI_PROVIDER_FUNCTION_CONTROL *PFN_WDF_WMI_PROVIDER_FUNCTION_CONTROL;

typedef struct _WDF_WMI_PROVIDER_CONFIG {
    
    
    
    ULONG Size;

    
    
    
    GUID Guid;

    
    
    
    ULONG Flags;

    
    
    
    
    ULONG MinInstanceBufferSize;

    
    
    
    
    PFN_WDF_WMI_PROVIDER_FUNCTION_CONTROL EvtWmiProviderFunctionControl;

} WDF_WMI_PROVIDER_CONFIG, *PWDF_WMI_PROVIDER_CONFIG;

void
__forceinline
WDF_WMI_PROVIDER_CONFIG_INIT(
     PWDF_WMI_PROVIDER_CONFIG Config,
     const GUID* Guid
    )
{
    memset((Config),0,(sizeof(WDF_WMI_PROVIDER_CONFIG)));

    Config->Size = sizeof(WDF_WMI_PROVIDER_CONFIG);
    memcpy((&Config->Guid),(Guid),(sizeof(GUID)));
}

typedef struct _WDF_WMI_INSTANCE_CONFIG {
    
    
    
    ULONG Size;

    
    
    
    
    WDFWMIPROVIDER Provider;

    
    
    
    
    
    PWDF_WMI_PROVIDER_CONFIG ProviderConfig;

    
    
    
    
    
    
    BOOLEAN UseContextForQuery;

    
    
    
    BOOLEAN Register;

    
    
    
    PFN_WDF_WMI_INSTANCE_QUERY_INSTANCE EvtWmiInstanceQueryInstance;

    
    
    
    PFN_WDF_WMI_INSTANCE_SET_INSTANCE EvtWmiInstanceSetInstance;

    
    
    
    PFN_WDF_WMI_INSTANCE_SET_ITEM EvtWmiInstanceSetItem;

    
    
    
    PFN_WDF_WMI_INSTANCE_EXECUTE_METHOD EvtWmiInstanceExecuteMethod;

} WDF_WMI_INSTANCE_CONFIG, *PWDF_WMI_INSTANCE_CONFIG;

void
__forceinline
WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER(
     PWDF_WMI_INSTANCE_CONFIG Config,
     WDFWMIPROVIDER Provider
    )
{
    memset((Config),0,(sizeof(WDF_WMI_INSTANCE_CONFIG)));
    Config->Size = sizeof(WDF_WMI_INSTANCE_CONFIG);

    Config->Provider = Provider;
}

void
__forceinline
WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG(
     PWDF_WMI_INSTANCE_CONFIG Config,
     PWDF_WMI_PROVIDER_CONFIG ProviderConfig
    )
{
    memset((Config),0,(sizeof(WDF_WMI_INSTANCE_CONFIG)));
    Config->Size = sizeof(WDF_WMI_INSTANCE_CONFIG);

    Config->ProviderConfig = ProviderConfig;
}

NTSTATUS
__forceinline
WDF_WMI_BUFFER_APPEND_STRING(
     PVOID Buffer,
     ULONG BufferLength,
     PCUNICODE_STRING String,
     PULONG RequiredSize
    )
{
    
    
    
    
    
    *RequiredSize = String->Length + sizeof(USHORT);

    
    
    

    
    
    
    
    if (BufferLength < (String->Length + sizeof(USHORT))) {
        
        
        
        
        return ((NTSTATUS)0xC0000023L);
    }

    
    
    
    *(USHORT *) Buffer = String->Length;

    
    
    
    memcpy((((PVOID) (((PUCHAR) (Buffer)) + (sizeof(USHORT))))),(String->Buffer),(String->Length));
#line 314 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\WdfWMI.h"

    return ((NTSTATUS)0x00000000L);
}




typedef



NTSTATUS
(*PFN_WDFWMIPROVIDERCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_WMI_PROVIDER_CONFIG WmiProviderConfig,
    
    PWDF_OBJECT_ATTRIBUTES ProviderAttributes,
    
    WDFWMIPROVIDER* WmiProvider
    );



NTSTATUS
__forceinline
WdfWmiProviderCreate(
    
    WDFDEVICE Device,
    
    PWDF_WMI_PROVIDER_CONFIG WmiProviderConfig,
    
    PWDF_OBJECT_ATTRIBUTES ProviderAttributes,
    
    WDFWMIPROVIDER* WmiProvider
    )
{
    return ((PFN_WDFWMIPROVIDERCREATE) WdfFunctions[WdfWmiProviderCreateTableIndex])(WdfDriverGlobals, Device, WmiProviderConfig, ProviderAttributes, WmiProvider);
}




typedef


WDFDEVICE
(*PFN_WDFWMIPROVIDERGETDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWMIPROVIDER WmiProvider
    );


WDFDEVICE
__forceinline
WdfWmiProviderGetDevice(
    
    WDFWMIPROVIDER WmiProvider
    )
{
    return ((PFN_WDFWMIPROVIDERGETDEVICE) WdfFunctions[WdfWmiProviderGetDeviceTableIndex])(WdfDriverGlobals, WmiProvider);
}




typedef


BOOLEAN
(*PFN_WDFWMIPROVIDERISENABLED)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWMIPROVIDER WmiProvider,
    
    WDF_WMI_PROVIDER_CONTROL ProviderControl
    );


BOOLEAN
__forceinline
WdfWmiProviderIsEnabled(
    
    WDFWMIPROVIDER WmiProvider,
    
    WDF_WMI_PROVIDER_CONTROL ProviderControl
    )
{
    return ((PFN_WDFWMIPROVIDERISENABLED) WdfFunctions[WdfWmiProviderIsEnabledTableIndex])(WdfDriverGlobals, WmiProvider, ProviderControl);
}




typedef


ULONGLONG
(*PFN_WDFWMIPROVIDERGETTRACINGHANDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWMIPROVIDER WmiProvider
    );


ULONGLONG
__forceinline
WdfWmiProviderGetTracingHandle(
    
    WDFWMIPROVIDER WmiProvider
    )
{
    return ((PFN_WDFWMIPROVIDERGETTRACINGHANDLE) WdfFunctions[WdfWmiProviderGetTracingHandleTableIndex])(WdfDriverGlobals, WmiProvider);
}




typedef



NTSTATUS
(*PFN_WDFWMIINSTANCECREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_WMI_INSTANCE_CONFIG InstanceConfig,
    
    PWDF_OBJECT_ATTRIBUTES InstanceAttributes,
    
    WDFWMIINSTANCE* Instance
    );



NTSTATUS
__forceinline
WdfWmiInstanceCreate(
    
    WDFDEVICE Device,
    
    PWDF_WMI_INSTANCE_CONFIG InstanceConfig,
    
    PWDF_OBJECT_ATTRIBUTES InstanceAttributes,
    
    WDFWMIINSTANCE* Instance
    )
{
    return ((PFN_WDFWMIINSTANCECREATE) WdfFunctions[WdfWmiInstanceCreateTableIndex])(WdfDriverGlobals, Device, InstanceConfig, InstanceAttributes, Instance);
}




typedef



NTSTATUS
(*PFN_WDFWMIINSTANCEREGISTER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWMIINSTANCE WmiInstance
    );



NTSTATUS
__forceinline
WdfWmiInstanceRegister(
    
    WDFWMIINSTANCE WmiInstance
    )
{
    return ((PFN_WDFWMIINSTANCEREGISTER) WdfFunctions[WdfWmiInstanceRegisterTableIndex])(WdfDriverGlobals, WmiInstance);
}




typedef


void
(*PFN_WDFWMIINSTANCEDEREGISTER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWMIINSTANCE WmiInstance
    );


void
__forceinline
WdfWmiInstanceDeregister(
    
    WDFWMIINSTANCE WmiInstance
    )
{
    ((PFN_WDFWMIINSTANCEDEREGISTER) WdfFunctions[WdfWmiInstanceDeregisterTableIndex])(WdfDriverGlobals, WmiInstance);
}




typedef


WDFDEVICE
(*PFN_WDFWMIINSTANCEGETDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWMIINSTANCE WmiInstance
    );


WDFDEVICE
__forceinline
WdfWmiInstanceGetDevice(
    
    WDFWMIINSTANCE WmiInstance
    )
{
    return ((PFN_WDFWMIINSTANCEGETDEVICE) WdfFunctions[WdfWmiInstanceGetDeviceTableIndex])(WdfDriverGlobals, WmiInstance);
}




typedef


WDFWMIPROVIDER
(*PFN_WDFWMIINSTANCEGETPROVIDER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWMIINSTANCE WmiInstance
    );


WDFWMIPROVIDER
__forceinline
WdfWmiInstanceGetProvider(
    
    WDFWMIINSTANCE WmiInstance
    )
{
    return ((PFN_WDFWMIINSTANCEGETPROVIDER) WdfFunctions[WdfWmiInstanceGetProviderTableIndex])(WdfDriverGlobals, WmiInstance);
}




typedef



NTSTATUS
(*PFN_WDFWMIINSTANCEFIREEVENT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFWMIINSTANCE WmiInstance,
    
    ULONG EventDataSize,
    
    PVOID EventData
    );



NTSTATUS
__forceinline
WdfWmiInstanceFireEvent(
    
    WDFWMIINSTANCE WmiInstance,
    
    ULONG EventDataSize,
    
    PVOID EventData
    )
{
    return ((PFN_WDFWMIINSTANCEFIREEVENT) WdfFunctions[WdfWmiInstanceFireEventTableIndex])(WdfDriverGlobals, WmiInstance, EventDataSize, EventData);
}



#line 615 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\WdfWMI.h"


#line 618 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\WdfWMI.h"

#line 93 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"

#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfstring.h"


































typedef



NTSTATUS
(*PFN_WDFSTRINGCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    PCUNICODE_STRING UnicodeString,
    
    PWDF_OBJECT_ATTRIBUTES StringAttributes,
    
    WDFSTRING* String
    );



NTSTATUS
__forceinline
WdfStringCreate(
    
    PCUNICODE_STRING UnicodeString,
    
    PWDF_OBJECT_ATTRIBUTES StringAttributes,
    
    WDFSTRING* String
    )
{
    return ((PFN_WDFSTRINGCREATE) WdfFunctions[WdfStringCreateTableIndex])(WdfDriverGlobals, UnicodeString, StringAttributes, String);
}




typedef


void
(*PFN_WDFSTRINGGETUNICODESTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFSTRING String,
    
    PUNICODE_STRING UnicodeString
    );


void
__forceinline
WdfStringGetUnicodeString(
    
    WDFSTRING String,
    
    PUNICODE_STRING UnicodeString
    )
{
    ((PFN_WDFSTRINGGETUNICODESTRING) WdfFunctions[WdfStringGetUnicodeStringTableIndex])(WdfDriverGlobals, String, UnicodeString);
}



#line 99 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfstring.h"


#line 102 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfstring.h"

#line 95 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfregistry.h"


































typedef



NTSTATUS
(*PFN_WDFREGISTRYOPENKEY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY ParentKey,
    
    PCUNICODE_STRING KeyName,
    
    ACCESS_MASK DesiredAccess,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    );



NTSTATUS
__forceinline
WdfRegistryOpenKey(
    
    WDFKEY ParentKey,
    
    PCUNICODE_STRING KeyName,
    
    ACCESS_MASK DesiredAccess,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    )
{
    return ((PFN_WDFREGISTRYOPENKEY) WdfFunctions[WdfRegistryOpenKeyTableIndex])(WdfDriverGlobals, ParentKey, KeyName, DesiredAccess, KeyAttributes, Key);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYCREATEKEY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY ParentKey,
    
    PCUNICODE_STRING KeyName,
    
    ACCESS_MASK DesiredAccess,
    
    ULONG CreateOptions,
    
    PULONG CreateDisposition,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    );



NTSTATUS
__forceinline
WdfRegistryCreateKey(
    
    WDFKEY ParentKey,
    
    PCUNICODE_STRING KeyName,
    
    ACCESS_MASK DesiredAccess,
    
    ULONG CreateOptions,
    
    PULONG CreateDisposition,
    
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    
    WDFKEY* Key
    )
{
    return ((PFN_WDFREGISTRYCREATEKEY) WdfFunctions[WdfRegistryCreateKeyTableIndex])(WdfDriverGlobals, ParentKey, KeyName, DesiredAccess, CreateOptions, CreateDisposition, KeyAttributes, Key);
}




typedef


void
(*PFN_WDFREGISTRYCLOSE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key
    );


void
__forceinline
WdfRegistryClose(
    
    WDFKEY Key
    )
{
    ((PFN_WDFREGISTRYCLOSE) WdfFunctions[WdfRegistryCloseTableIndex])(WdfDriverGlobals, Key);
}




typedef


HANDLE
(*PFN_WDFREGISTRYWDMGETHANDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key
    );


HANDLE
__forceinline
WdfRegistryWdmGetHandle(
    
    WDFKEY Key
    )
{
    return ((PFN_WDFREGISTRYWDMGETHANDLE) WdfFunctions[WdfRegistryWdmGetHandleTableIndex])(WdfDriverGlobals, Key);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYREMOVEKEY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key
    );



NTSTATUS
__forceinline
WdfRegistryRemoveKey(
    
    WDFKEY Key
    )
{
    return ((PFN_WDFREGISTRYREMOVEKEY) WdfFunctions[WdfRegistryRemoveKeyTableIndex])(WdfDriverGlobals, Key);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYREMOVEVALUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName
    );



NTSTATUS
__forceinline
WdfRegistryRemoveValue(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName
    )
{
    return ((PFN_WDFREGISTRYREMOVEVALUE) WdfFunctions[WdfRegistryRemoveValueTableIndex])(WdfDriverGlobals, Key, ValueName);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYQUERYVALUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    ULONG ValueLength,
    
    PVOID Value,
    
    PULONG ValueLengthQueried,
    
    PULONG ValueType
    );



NTSTATUS
__forceinline
WdfRegistryQueryValue(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    ULONG ValueLength,
    
    PVOID Value,
    
    PULONG ValueLengthQueried,
    
    PULONG ValueType
    )
{
    return ((PFN_WDFREGISTRYQUERYVALUE) WdfFunctions[WdfRegistryQueryValueTableIndex])(WdfDriverGlobals, Key, ValueName, ValueLength, Value, ValueLengthQueried, ValueType);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYQUERYMEMORY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES MemoryAttributes,
    
    WDFMEMORY* Memory,
    
    PULONG ValueType
    );



NTSTATUS
__forceinline
WdfRegistryQueryMemory(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    
    POOL_TYPE PoolType,
    
    PWDF_OBJECT_ATTRIBUTES MemoryAttributes,
    
    WDFMEMORY* Memory,
    
    PULONG ValueType
    )
{
    return ((PFN_WDFREGISTRYQUERYMEMORY) WdfFunctions[WdfRegistryQueryMemoryTableIndex])(WdfDriverGlobals, Key, ValueName, PoolType, MemoryAttributes, Memory, ValueType);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYQUERYMULTISTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    PWDF_OBJECT_ATTRIBUTES StringsAttributes,
    
    WDFCOLLECTION Collection
    );



NTSTATUS
__forceinline
WdfRegistryQueryMultiString(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    PWDF_OBJECT_ATTRIBUTES StringsAttributes,
    
    WDFCOLLECTION Collection
    )
{
    return ((PFN_WDFREGISTRYQUERYMULTISTRING) WdfFunctions[WdfRegistryQueryMultiStringTableIndex])(WdfDriverGlobals, Key, ValueName, StringsAttributes, Collection);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYQUERYUNICODESTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    PUSHORT ValueByteLength,
    
    PUNICODE_STRING Value
    );



NTSTATUS
__forceinline
WdfRegistryQueryUnicodeString(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    PUSHORT ValueByteLength,
    
    PUNICODE_STRING Value
    )
{
    return ((PFN_WDFREGISTRYQUERYUNICODESTRING) WdfFunctions[WdfRegistryQueryUnicodeStringTableIndex])(WdfDriverGlobals, Key, ValueName, ValueByteLength, Value);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYQUERYSTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    WDFSTRING String
    );



NTSTATUS
__forceinline
WdfRegistryQueryString(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    WDFSTRING String
    )
{
    return ((PFN_WDFREGISTRYQUERYSTRING) WdfFunctions[WdfRegistryQueryStringTableIndex])(WdfDriverGlobals, Key, ValueName, String);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYQUERYULONG)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    PULONG Value
    );



NTSTATUS
__forceinline
WdfRegistryQueryULong(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    PULONG Value
    )
{
    return ((PFN_WDFREGISTRYQUERYULONG) WdfFunctions[WdfRegistryQueryULongTableIndex])(WdfDriverGlobals, Key, ValueName, Value);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYASSIGNVALUE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    ULONG ValueType,
    
    ULONG ValueLength,
    
    PVOID Value
    );



NTSTATUS
__forceinline
WdfRegistryAssignValue(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    ULONG ValueType,
    
    ULONG ValueLength,
    
    PVOID Value
    )
{
    return ((PFN_WDFREGISTRYASSIGNVALUE) WdfFunctions[WdfRegistryAssignValueTableIndex])(WdfDriverGlobals, Key, ValueName, ValueType, ValueLength, Value);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYASSIGNMEMORY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    ULONG ValueType,
    
    WDFMEMORY Memory,
    
    PWDFMEMORY_OFFSET MemoryOffsets
    );



NTSTATUS
__forceinline
WdfRegistryAssignMemory(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    ULONG ValueType,
    
    WDFMEMORY Memory,
    
    PWDFMEMORY_OFFSET MemoryOffsets
    )
{
    return ((PFN_WDFREGISTRYASSIGNMEMORY) WdfFunctions[WdfRegistryAssignMemoryTableIndex])(WdfDriverGlobals, Key, ValueName, ValueType, Memory, MemoryOffsets);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYASSIGNMULTISTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    WDFCOLLECTION StringsCollection
    );



NTSTATUS
__forceinline
WdfRegistryAssignMultiString(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    WDFCOLLECTION StringsCollection
    )
{
    return ((PFN_WDFREGISTRYASSIGNMULTISTRING) WdfFunctions[WdfRegistryAssignMultiStringTableIndex])(WdfDriverGlobals, Key, ValueName, StringsCollection);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYASSIGNUNICODESTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    PCUNICODE_STRING Value
    );



NTSTATUS
__forceinline
WdfRegistryAssignUnicodeString(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    PCUNICODE_STRING Value
    )
{
    return ((PFN_WDFREGISTRYASSIGNUNICODESTRING) WdfFunctions[WdfRegistryAssignUnicodeStringTableIndex])(WdfDriverGlobals, Key, ValueName, Value);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYASSIGNSTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    WDFSTRING String
    );



NTSTATUS
__forceinline
WdfRegistryAssignString(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    WDFSTRING String
    )
{
    return ((PFN_WDFREGISTRYASSIGNSTRING) WdfFunctions[WdfRegistryAssignStringTableIndex])(WdfDriverGlobals, Key, ValueName, String);
}




typedef



NTSTATUS
(*PFN_WDFREGISTRYASSIGNULONG)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    ULONG Value
    );



NTSTATUS
__forceinline
WdfRegistryAssignULong(
    
    WDFKEY Key,
    
    PCUNICODE_STRING ValueName,
    
    ULONG Value
    )
{
    return ((PFN_WDFREGISTRYASSIGNULONG) WdfFunctions[WdfRegistryAssignULongTableIndex])(WdfDriverGlobals, Key, ValueName, Value);
}



#line 707 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfregistry.h"


#line 710 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfregistry.h"

#line 96 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"


#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfDmaEnabler.h"































typedef enum _WDF_DMA_PROFILE {
    WdfDmaProfileInvalid = 0,
    WdfDmaProfilePacket,
    WdfDmaProfileScatterGather,
    WdfDmaProfilePacket64,
    WdfDmaProfileScatterGather64,
    WdfDmaProfileScatterGatherDuplex,
    WdfDmaProfileScatterGather64Duplex,
} WDF_DMA_PROFILE;

typedef enum _WDF_DMA_DIRECTION {
    WdfDmaDirectionReadFromDevice = 0,
    WdfDmaDirectionWriteToDevice = 1,
} WDF_DMA_DIRECTION;






typedef



NTSTATUS
EVT_WDF_DMA_ENABLER_FILL(
    
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_FILL *PFN_WDF_DMA_ENABLER_FILL;

typedef



NTSTATUS
EVT_WDF_DMA_ENABLER_FLUSH(
    
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_FLUSH *PFN_WDF_DMA_ENABLER_FLUSH;

typedef



NTSTATUS
EVT_WDF_DMA_ENABLER_ENABLE(
    
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_ENABLE *PFN_WDF_DMA_ENABLER_ENABLE;

typedef



NTSTATUS
EVT_WDF_DMA_ENABLER_DISABLE(
    
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_DISABLE *PFN_WDF_DMA_ENABLER_DISABLE;

typedef



NTSTATUS
EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_START(
    
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_START *PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_START;

typedef



NTSTATUS
EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP(
    
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP *PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP;




typedef struct _WDF_DMA_ENABLER_CONFIG {
    
    
    
    ULONG                Size;

    
    
    
    WDF_DMA_PROFILE      Profile;

    
    
    
    size_t               MaximumLength;

    
    
    
    PFN_WDF_DMA_ENABLER_FILL                  EvtDmaEnablerFill;
    PFN_WDF_DMA_ENABLER_FLUSH                 EvtDmaEnablerFlush;
    PFN_WDF_DMA_ENABLER_DISABLE               EvtDmaEnablerDisable;
    PFN_WDF_DMA_ENABLER_ENABLE                EvtDmaEnablerEnable;
    PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_START  EvtDmaEnablerSelfManagedIoStart;
    PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP   EvtDmaEnablerSelfManagedIoStop;

} WDF_DMA_ENABLER_CONFIG, *PWDF_DMA_ENABLER_CONFIG;

void
__forceinline
WDF_DMA_ENABLER_CONFIG_INIT(
     PWDF_DMA_ENABLER_CONFIG Config,
      WDF_DMA_PROFILE    Profile,
      size_t             MaximumLength
    )
{
    memset((Config),0,(sizeof(WDF_DMA_ENABLER_CONFIG)));

    Config->Size = sizeof(WDF_DMA_ENABLER_CONFIG);
    Config->Profile = Profile;
    Config->MaximumLength = MaximumLength;
}




typedef



NTSTATUS
(*PFN_WDFDMAENABLERCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_DMA_ENABLER_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFDMAENABLER* DmaEnablerHandle
    );



NTSTATUS
__forceinline
WdfDmaEnablerCreate(
    
    WDFDEVICE Device,
    
    PWDF_DMA_ENABLER_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFDMAENABLER* DmaEnablerHandle
    )
{
    return ((PFN_WDFDMAENABLERCREATE) WdfFunctions[WdfDmaEnablerCreateTableIndex])(WdfDriverGlobals, Device, Config, Attributes, DmaEnablerHandle);
}




typedef


size_t
(*PFN_WDFDMAENABLERGETMAXIMUMLENGTH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMAENABLER DmaEnabler
    );


size_t
__forceinline
WdfDmaEnablerGetMaximumLength(
    
    WDFDMAENABLER DmaEnabler
    )
{
    return ((PFN_WDFDMAENABLERGETMAXIMUMLENGTH) WdfFunctions[WdfDmaEnablerGetMaximumLengthTableIndex])(WdfDriverGlobals, DmaEnabler);
}




typedef


size_t
(*PFN_WDFDMAENABLERGETMAXIMUMSCATTERGATHERELEMENTS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMAENABLER DmaEnabler
    );


size_t
__forceinline
WdfDmaEnablerGetMaximumScatterGatherElements(
    
    WDFDMAENABLER DmaEnabler
    )
{
    return ((PFN_WDFDMAENABLERGETMAXIMUMSCATTERGATHERELEMENTS) WdfFunctions[WdfDmaEnablerGetMaximumScatterGatherElementsTableIndex])(WdfDriverGlobals, DmaEnabler);
}




typedef


void
(*PFN_WDFDMAENABLERSETMAXIMUMSCATTERGATHERELEMENTS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMAENABLER DmaEnabler,
    
    
    size_t MaximumFragments
    );


void
__forceinline
WdfDmaEnablerSetMaximumScatterGatherElements(
    
    WDFDMAENABLER DmaEnabler,
    
    
    size_t MaximumFragments
    )
{
    ((PFN_WDFDMAENABLERSETMAXIMUMSCATTERGATHERELEMENTS) WdfFunctions[WdfDmaEnablerSetMaximumScatterGatherElementsTableIndex])(WdfDriverGlobals, DmaEnabler, MaximumFragments);
}




typedef


size_t
(*PFN_WDFDMAENABLERGETFRAGMENTLENGTH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMAENABLER DmaEnabler,
    
    WDF_DMA_DIRECTION DmaDirection
    );


size_t
__forceinline
WdfDmaEnablerGetFragmentLength(
    
    WDFDMAENABLER DmaEnabler,
    
    WDF_DMA_DIRECTION DmaDirection
    )
{
    return ((PFN_WDFDMAENABLERGETFRAGMENTLENGTH) WdfFunctions[WdfDmaEnablerGetFragmentLengthTableIndex])(WdfDriverGlobals, DmaEnabler, DmaDirection);
}




typedef


PDMA_ADAPTER
(*PFN_WDFDMAENABLERWDMGETDMAADAPTER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMAENABLER DmaEnabler,
    
    WDF_DMA_DIRECTION DmaDirection
    );


PDMA_ADAPTER
__forceinline
WdfDmaEnablerWdmGetDmaAdapter(
    
    WDFDMAENABLER DmaEnabler,
    
    WDF_DMA_DIRECTION DmaDirection
    )
{
    return ((PFN_WDFDMAENABLERWDMGETDMAADAPTER) WdfFunctions[WdfDmaEnablerWdmGetDmaAdapterTableIndex])(WdfDriverGlobals, DmaEnabler, DmaDirection);
}



#line 351 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfDmaEnabler.h"


#line 354 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfDmaEnabler.h"

#line 99 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfDmaTransaction.h"

































typedef



BOOLEAN
EVT_WDF_PROGRAM_DMA(
    
    WDFDMATRANSACTION Transaction,
    
    WDFDEVICE Device,
    
    WDFCONTEXT Context,
    
    WDF_DMA_DIRECTION Direction,
    
    PSCATTER_GATHER_LIST SgList
    );

typedef EVT_WDF_PROGRAM_DMA *PFN_WDF_PROGRAM_DMA;




typedef



NTSTATUS
(*PFN_WDFDMATRANSACTIONCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMAENABLER DmaEnabler,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFDMATRANSACTION* DmaTransaction
    );



NTSTATUS
__forceinline
WdfDmaTransactionCreate(
    
    WDFDMAENABLER DmaEnabler,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFDMATRANSACTION* DmaTransaction
    )
{
    return ((PFN_WDFDMATRANSACTIONCREATE) WdfFunctions[WdfDmaTransactionCreateTableIndex])(WdfDriverGlobals, DmaEnabler, Attributes, DmaTransaction);
}




typedef



NTSTATUS
(*PFN_WDFDMATRANSACTIONINITIALIZE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction,
    
    PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
    
    WDF_DMA_DIRECTION DmaDirection,
    
    PMDL Mdl,
    
    PVOID VirtualAddress,
    
    
    size_t Length
    );



NTSTATUS
__forceinline
WdfDmaTransactionInitialize(
    
    WDFDMATRANSACTION DmaTransaction,
    
    PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
    
    WDF_DMA_DIRECTION DmaDirection,
    
    PMDL Mdl,
    
    PVOID VirtualAddress,
    
    
    size_t Length
    )
{
    return ((PFN_WDFDMATRANSACTIONINITIALIZE) WdfFunctions[WdfDmaTransactionInitializeTableIndex])(WdfDriverGlobals, DmaTransaction, EvtProgramDmaFunction, DmaDirection, Mdl, VirtualAddress, Length);
}




typedef



NTSTATUS
(*PFN_WDFDMATRANSACTIONINITIALIZEUSINGREQUEST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction,
    
    WDFREQUEST Request,
    
    PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
    
    WDF_DMA_DIRECTION DmaDirection
    );



NTSTATUS
__forceinline
WdfDmaTransactionInitializeUsingRequest(
    
    WDFDMATRANSACTION DmaTransaction,
    
    WDFREQUEST Request,
    
    PFN_WDF_PROGRAM_DMA EvtProgramDmaFunction,
    
    WDF_DMA_DIRECTION DmaDirection
    )
{
    return ((PFN_WDFDMATRANSACTIONINITIALIZEUSINGREQUEST) WdfFunctions[WdfDmaTransactionInitializeUsingRequestTableIndex])(WdfDriverGlobals, DmaTransaction, Request, EvtProgramDmaFunction, DmaDirection);
}




typedef



NTSTATUS
(*PFN_WDFDMATRANSACTIONEXECUTE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction,
    
    WDFCONTEXT Context
    );



NTSTATUS
__forceinline
WdfDmaTransactionExecute(
    
    WDFDMATRANSACTION DmaTransaction,
    
    WDFCONTEXT Context
    )
{
    return ((PFN_WDFDMATRANSACTIONEXECUTE) WdfFunctions[WdfDmaTransactionExecuteTableIndex])(WdfDriverGlobals, DmaTransaction, Context);
}




typedef



NTSTATUS
(*PFN_WDFDMATRANSACTIONRELEASE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction
    );



NTSTATUS
__forceinline
WdfDmaTransactionRelease(
    
    WDFDMATRANSACTION DmaTransaction
    )
{
    return ((PFN_WDFDMATRANSACTIONRELEASE) WdfFunctions[WdfDmaTransactionReleaseTableIndex])(WdfDriverGlobals, DmaTransaction);
}




typedef


BOOLEAN
(*PFN_WDFDMATRANSACTIONDMACOMPLETED)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction,
    
    NTSTATUS* Status
    );


BOOLEAN
__forceinline
WdfDmaTransactionDmaCompleted(
    
    WDFDMATRANSACTION DmaTransaction,
    
    NTSTATUS* Status
    )
{
    return ((PFN_WDFDMATRANSACTIONDMACOMPLETED) WdfFunctions[WdfDmaTransactionDmaCompletedTableIndex])(WdfDriverGlobals, DmaTransaction, Status);
}




typedef


BOOLEAN
(*PFN_WDFDMATRANSACTIONDMACOMPLETEDWITHLENGTH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction,
    
    size_t TransferredLength,
    
    NTSTATUS* Status
    );


BOOLEAN
__forceinline
WdfDmaTransactionDmaCompletedWithLength(
    
    WDFDMATRANSACTION DmaTransaction,
    
    size_t TransferredLength,
    
    NTSTATUS* Status
    )
{
    return ((PFN_WDFDMATRANSACTIONDMACOMPLETEDWITHLENGTH) WdfFunctions[WdfDmaTransactionDmaCompletedWithLengthTableIndex])(WdfDriverGlobals, DmaTransaction, TransferredLength, Status);
}




typedef


BOOLEAN
(*PFN_WDFDMATRANSACTIONDMACOMPLETEDFINAL)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction,
    
    size_t FinalTransferredLength,
    
    NTSTATUS* Status
    );


BOOLEAN
__forceinline
WdfDmaTransactionDmaCompletedFinal(
    
    WDFDMATRANSACTION DmaTransaction,
    
    size_t FinalTransferredLength,
    
    NTSTATUS* Status
    )
{
    return ((PFN_WDFDMATRANSACTIONDMACOMPLETEDFINAL) WdfFunctions[WdfDmaTransactionDmaCompletedFinalTableIndex])(WdfDriverGlobals, DmaTransaction, FinalTransferredLength, Status);
}




typedef


size_t
(*PFN_WDFDMATRANSACTIONGETBYTESTRANSFERRED)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction
    );


size_t
__forceinline
WdfDmaTransactionGetBytesTransferred(
    
    WDFDMATRANSACTION DmaTransaction
    )
{
    return ((PFN_WDFDMATRANSACTIONGETBYTESTRANSFERRED) WdfFunctions[WdfDmaTransactionGetBytesTransferredTableIndex])(WdfDriverGlobals, DmaTransaction);
}




typedef


void
(*PFN_WDFDMATRANSACTIONSETMAXIMUMLENGTH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction,
    
    size_t MaximumLength
    );


void
__forceinline
WdfDmaTransactionSetMaximumLength(
    
    WDFDMATRANSACTION DmaTransaction,
    
    size_t MaximumLength
    )
{
    ((PFN_WDFDMATRANSACTIONSETMAXIMUMLENGTH) WdfFunctions[WdfDmaTransactionSetMaximumLengthTableIndex])(WdfDriverGlobals, DmaTransaction, MaximumLength);
}




typedef


WDFREQUEST
(*PFN_WDFDMATRANSACTIONGETREQUEST)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction
    );


WDFREQUEST
__forceinline
WdfDmaTransactionGetRequest(
    
    WDFDMATRANSACTION DmaTransaction
    )
{
    return ((PFN_WDFDMATRANSACTIONGETREQUEST) WdfFunctions[WdfDmaTransactionGetRequestTableIndex])(WdfDriverGlobals, DmaTransaction);
}




typedef


size_t
(*PFN_WDFDMATRANSACTIONGETCURRENTDMATRANSFERLENGTH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction
    );


size_t
__forceinline
WdfDmaTransactionGetCurrentDmaTransferLength(
    
    WDFDMATRANSACTION DmaTransaction
    )
{
    return ((PFN_WDFDMATRANSACTIONGETCURRENTDMATRANSFERLENGTH) WdfFunctions[WdfDmaTransactionGetCurrentDmaTransferLengthTableIndex])(WdfDriverGlobals, DmaTransaction);
}




typedef


WDFDEVICE
(*PFN_WDFDMATRANSACTIONGETDEVICE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMATRANSACTION DmaTransaction
    );


WDFDEVICE
__forceinline
WdfDmaTransactionGetDevice(
    
    WDFDMATRANSACTION DmaTransaction
    )
{
    return ((PFN_WDFDMATRANSACTIONGETDEVICE) WdfFunctions[WdfDmaTransactionGetDeviceTableIndex])(WdfDriverGlobals, DmaTransaction);
}



#line 462 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfDmaTransaction.h"


#line 465 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfDmaTransaction.h"

#line 100 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfCommonBuffer.h"

































typedef struct _WDF_COMMON_BUFFER_CONFIG {
    
    
    
    ULONG   Size;

    
    
    
    ULONG   AlignmentRequirement;

} WDF_COMMON_BUFFER_CONFIG, *PWDF_COMMON_BUFFER_CONFIG;

void
__forceinline
WDF_COMMON_BUFFER_CONFIG_INIT(
     PWDF_COMMON_BUFFER_CONFIG Config,
      ULONG  AlignmentRequirement
    )
{
    memset((Config),0,(sizeof(WDF_COMMON_BUFFER_CONFIG)));

    Config->Size = sizeof(WDF_COMMON_BUFFER_CONFIG);
    Config->AlignmentRequirement = AlignmentRequirement;
}




typedef



NTSTATUS
(*PFN_WDFCOMMONBUFFERCREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMAENABLER DmaEnabler,
    
    
    size_t Length,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFCOMMONBUFFER* CommonBuffer
    );



NTSTATUS
__forceinline
WdfCommonBufferCreate(
    
    WDFDMAENABLER DmaEnabler,
    
    
    size_t Length,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFCOMMONBUFFER* CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERCREATE) WdfFunctions[WdfCommonBufferCreateTableIndex])(WdfDriverGlobals, DmaEnabler, Length, Attributes, CommonBuffer);
}




typedef



NTSTATUS
(*PFN_WDFCOMMONBUFFERCREATEWITHCONFIG)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDMAENABLER DmaEnabler,
    
    
    size_t Length,
    
    PWDF_COMMON_BUFFER_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFCOMMONBUFFER* CommonBuffer
    );



NTSTATUS
__forceinline
WdfCommonBufferCreateWithConfig(
    
    WDFDMAENABLER DmaEnabler,
    
    
    size_t Length,
    
    PWDF_COMMON_BUFFER_CONFIG Config,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFCOMMONBUFFER* CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERCREATEWITHCONFIG) WdfFunctions[WdfCommonBufferCreateWithConfigTableIndex])(WdfDriverGlobals, DmaEnabler, Length, Config, Attributes, CommonBuffer);
}




typedef


PVOID
(*PFN_WDFCOMMONBUFFERGETALIGNEDVIRTUALADDRESS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOMMONBUFFER CommonBuffer
    );


PVOID
__forceinline
WdfCommonBufferGetAlignedVirtualAddress(
    
    WDFCOMMONBUFFER CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERGETALIGNEDVIRTUALADDRESS) WdfFunctions[WdfCommonBufferGetAlignedVirtualAddressTableIndex])(WdfDriverGlobals, CommonBuffer);
}




typedef


PHYSICAL_ADDRESS
(*PFN_WDFCOMMONBUFFERGETALIGNEDLOGICALADDRESS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOMMONBUFFER CommonBuffer
    );


PHYSICAL_ADDRESS
__forceinline
WdfCommonBufferGetAlignedLogicalAddress(
    
    WDFCOMMONBUFFER CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERGETALIGNEDLOGICALADDRESS) WdfFunctions[WdfCommonBufferGetAlignedLogicalAddressTableIndex])(WdfDriverGlobals, CommonBuffer);
}




typedef


size_t
(*PFN_WDFCOMMONBUFFERGETLENGTH)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFCOMMONBUFFER CommonBuffer
    );


size_t
__forceinline
WdfCommonBufferGetLength(
    
    WDFCOMMONBUFFER CommonBuffer
    )
{
    return ((PFN_WDFCOMMONBUFFERGETLENGTH) WdfFunctions[WdfCommonBufferGetLengthTableIndex])(WdfDriverGlobals, CommonBuffer);
}



#line 224 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfCommonBuffer.h"


#line 227 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfCommonBuffer.h"

#line 101 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"

#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfbugcodes.h"




































typedef enum _WDF_BUGCHECK_CODES {
    WDF_POWER_ROUTINE_TIMED_OUT = 0x1,
    WDF_RECURSIVE_LOCK = 0x2,
    WDF_VERIFIER_FATAL_ERROR = 0x3,
    WDF_REQUIRED_PARAMETER_IS_NULL = 0x4,
    WDF_INVALID_HANDLE = 0x5,
    WDF_REQUEST_FATAL_ERROR = 0x6,
    WDF_OBJECT_ERROR = 0x7,
    WDF_DMA_FATAL_ERROR = 0x8,
    WDF_INVALID_INTERRUPT = 0x9,
    WDF_QUEUE_FATAL_ERROR = 0xA,
    WDF_INVALID_LOCK_OPERATION = 0xB,
    WDF_PNP_FATAL_ERROR = 0xC,
    WDF_POWER_MULTIPLE_PPO = 0xD,
    WDF_VERIFIER_IRQL_MISMATCH = 0xE,
    WDF_VERIFIER_CRITICAL_REGION_MISMATCH = 0xF,
} WDF_BUGCHECK_CODES;

typedef enum _WDF_REQUEST_FATAL_ERROR_CODES {
    WDF_REQUEST_FATAL_ERROR_NO_MORE_STACK_LOCATIONS = 0x1,
    WDF_REQUEST_FATAL_ERROR_NULL_IRP = 0x2,
    WDF_REQUEST_FATAL_ERROR_REQUEST_ALREADY_SENT = 0x3,
    WDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH = 0x4,
} WDF_REQUEST_FATAL_ERROR_CODES;



typedef struct _WDF_POWER_ROUTINE_TIMED_OUT_DATA {
    
    
    
    WDF_DEVICE_POWER_STATE PowerState;

    
    
    
    WDF_DEVICE_POWER_POLICY_STATE PowerPolicyState;

    
    
    
    PDEVICE_OBJECT DeviceObject;

    
    
    
    WDFDEVICE Device;

    
    
    
    PKTHREAD TimedOutThread;

} WDF_POWER_ROUTINE_TIMED_OUT_DATA;

typedef struct _WDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH_DATA {
    WDFREQUEST Request;

    PIRP Irp;

    ULONG OutputBufferLength;

    ULONG_PTR Information;

    UCHAR MajorFunction;

}   WDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH_DATA,
  *PWDF_REQUEST_FATAL_ERROR_INFORMATION_LENGTH_MISMATCH_DATA;

typedef struct _WDF_QUEUE_FATAL_ERROR_DATA {
    WDFQUEUE Queue;

    WDFREQUEST Request;

    NTSTATUS Status;

} WDF_QUEUE_FATAL_ERROR_DATA, *PWDF_QUEUE_FATAL_ERROR_DATA;



#line 118 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfbugcodes.h"


#line 121 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfbugcodes.h"

#line 103 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfroletypes.h"



typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_DEVICE_CONTEXT_CLEANUP;
typedef EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_DEVICE_CONTEXT_DESTROY;
typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_IO_QUEUE_CONTEXT_CLEANUP_CALLBACK;
typedef EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_IO_QUEUE_CONTEXT_DESTROY_CALLBACK;
typedef EVT_WDF_OBJECT_CONTEXT_CLEANUP EVT_WDF_FILE_CONTEXT_CLEANUP_CALLBACK;
typedef EVT_WDF_OBJECT_CONTEXT_DESTROY EVT_WDF_FILE_CONTEXT_DESTROY_CALLBACK;

#line 12 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfroletypes.h"


#line 104 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"



#line 108 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"

#line 8 "Usb.c"
#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\Usb.h"
#pragma once


#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\ntddk.h"



























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 5 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\Usb.h"
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdf.h"












































































































#line 6 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\Usb.h"

#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"









































#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbioctl.h"


























#line 1 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usb100.h"




#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\PSHPACK1.H"























#pragma warning(disable:4103)

#pragma pack(push,1)


#line 30 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\PSHPACK1.H"


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\PSHPACK1.H"
#line 34 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\PSHPACK1.H"

#line 6 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usb100.h"
















































































































typedef struct _USB_DEVICE_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    USHORT bcdUSB;
    UCHAR bDeviceClass;
    UCHAR bDeviceSubClass;
    UCHAR bDeviceProtocol;
    UCHAR bMaxPacketSize0;
    USHORT idVendor;
    USHORT idProduct;
    USHORT bcdDevice;
    UCHAR iManufacturer;
    UCHAR iProduct;
    UCHAR iSerialNumber;
    UCHAR bNumConfigurations;
} USB_DEVICE_DESCRIPTOR, *PUSB_DEVICE_DESCRIPTOR;

typedef struct _USB_ENDPOINT_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    UCHAR bEndpointAddress;
    UCHAR bmAttributes;
    USHORT wMaxPacketSize;
    UCHAR bInterval;
} USB_ENDPOINT_DESCRIPTOR, *PUSB_ENDPOINT_DESCRIPTOR;

typedef struct _USB_CONFIGURATION_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    USHORT wTotalLength;
    UCHAR bNumInterfaces;
    UCHAR bConfigurationValue;
    UCHAR iConfiguration;
    UCHAR bmAttributes;
    UCHAR MaxPower;
} USB_CONFIGURATION_DESCRIPTOR, *PUSB_CONFIGURATION_DESCRIPTOR;

typedef struct _USB_INTERFACE_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    UCHAR bInterfaceNumber;
    UCHAR bAlternateSetting;
    UCHAR bNumEndpoints;
    UCHAR bInterfaceClass;
    UCHAR bInterfaceSubClass;
    UCHAR bInterfaceProtocol;
    UCHAR iInterface;
} USB_INTERFACE_DESCRIPTOR, *PUSB_INTERFACE_DESCRIPTOR;

typedef struct _USB_STRING_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    WCHAR bString[1];
} USB_STRING_DESCRIPTOR, *PUSB_STRING_DESCRIPTOR;

typedef struct _USB_COMMON_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
} USB_COMMON_DESCRIPTOR, *PUSB_COMMON_DESCRIPTOR;








typedef struct _USB_HUB_DESCRIPTOR {
    UCHAR        bDescriptorLength;      
    UCHAR        bDescriptorType;        
    UCHAR        bNumberOfPorts;         
    USHORT       wHubCharacteristics;    
    UCHAR        bPowerOnToPowerGood;    
    UCHAR        bHubControlCurrent;     
    
    
    UCHAR        bRemoveAndPowerMask[64];       
} USB_HUB_DESCRIPTOR, *PUSB_HUB_DESCRIPTOR;




















typedef struct _USB_CONFIGURATION_POWER_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    UCHAR SelfPowerConsumedD0[3];
    UCHAR bPowerSummaryId;
    UCHAR bBusPowerSavingD1;
    UCHAR bSelfPowerSavingD1;
    UCHAR bBusPowerSavingD2;
    UCHAR bSelfPowerSavingD2; 
    UCHAR bBusPowerSavingD3;
    UCHAR bSelfPowerSavingD3; 
    USHORT TransitionTimeFromD1;
    USHORT TransitionTimeFromD2;
    USHORT TransitionTimeFromD3;
} USB_CONFIGURATION_POWER_DESCRIPTOR, *PUSB_CONFIGURATION_POWER_DESCRIPTOR;


typedef struct _USB_INTERFACE_POWER_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    UCHAR bmCapabilitiesFlags;
    UCHAR bBusPowerSavingD1;
    UCHAR bSelfPowerSavingD1;
    UCHAR bBusPowerSavingD2;
    UCHAR bSelfPowerSavingD2; 
    UCHAR bBusPowerSavingD3;
    UCHAR bSelfPowerSavingD3; 
    USHORT TransitionTimeFromD1;
    USHORT TransitionTimeFromD2;
    USHORT TransitionTimeFromD3;
} USB_INTERFACE_POWER_DESCRIPTOR, *PUSB_INTERFACE_POWER_DESCRIPTOR;


#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\POPPACK.H"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\POPPACK.H"


#line 36 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\POPPACK.H"
#line 37 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\POPPACK.H"

#line 250 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usb100.h"


#line 253 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usb100.h"

#line 28 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbioctl.h"







extern const GUID  GUID_CLASS_USBHUB;



extern const GUID  GUID_CLASS_USB_DEVICE;



extern const GUID  GUID_USB_WMI_STD_DATA;



extern const GUID  GUID_USB_WMI_STD_NOTIFICATION;             


















































































































































































						




					    









                                                


















































#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack1.h"























#pragma warning(disable:4103)

#pragma pack(push,1)


#line 30 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack1.h"


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack1.h"
#line 34 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\pshpack1.h"

#line 293 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbioctl.h"

typedef enum _USB_HUB_NODE {
    UsbHub,
    UsbMIParent
} USB_HUB_NODE;

typedef struct _USB_HUB_INFORMATION {
    


    USB_HUB_DESCRIPTOR HubDescriptor;

    BOOLEAN HubIsBusPowered;

} USB_HUB_INFORMATION, *PUSB_HUB_INFORMATION;

typedef struct _USB_MI_PARENT_INFORMATION {
    ULONG NumberOfInterfaces;
} USB_MI_PARENT_INFORMATION, *PUSB_MI_PARENT_INFORMATION;

typedef struct _USB_NODE_INFORMATION {
    USB_HUB_NODE NodeType;        
    union {
        USB_HUB_INFORMATION HubInformation;
        USB_MI_PARENT_INFORMATION MiParentInformation;
    } u;
} USB_NODE_INFORMATION, *PUSB_NODE_INFORMATION;	

typedef struct _USB_PIPE_INFO {
    USB_ENDPOINT_DESCRIPTOR EndpointDescriptor;
    ULONG ScheduleOffset;
} USB_PIPE_INFO, *PUSB_PIPE_INFO;	


typedef enum _USB_CONNECTION_STATUS {
    NoDeviceConnected,
    DeviceConnected,

    
    DeviceFailedEnumeration,
    DeviceGeneralFailure,
    DeviceCausedOvercurrent,
    DeviceNotEnoughPower,
    
    DeviceNotEnoughBandwidth        
} USB_CONNECTION_STATUS, *PUSB_CONNECTION_STATUS;

typedef struct _USB_NODE_CONNECTION_INFORMATION {
    ULONG ConnectionIndex;
    

    USB_DEVICE_DESCRIPTOR DeviceDescriptor;
    UCHAR CurrentConfigurationValue;
    BOOLEAN LowSpeed;

    BOOLEAN DeviceIsHub;

    USHORT DeviceAddress;

    ULONG NumberOfOpenPipes;

    USB_CONNECTION_STATUS ConnectionStatus;
    USB_PIPE_INFO PipeList[0];
} USB_NODE_CONNECTION_INFORMATION, *PUSB_NODE_CONNECTION_INFORMATION;	

typedef struct _USB_NODE_CONNECTION_DRIVERKEY_NAME {
    ULONG ConnectionIndex;  
    ULONG ActualLength;     
    
    WCHAR DriverKeyName[1];      
} USB_NODE_CONNECTION_DRIVERKEY_NAME, *PUSB_NODE_CONNECTION_DRIVERKEY_NAME;	

typedef struct _USB_NODE_CONNECTION_NAME {
    ULONG ConnectionIndex;  
    ULONG ActualLength;     
    

    WCHAR NodeName[1];      
} USB_NODE_CONNECTION_NAME, *PUSB_NODE_CONNECTION_NAME;	


typedef struct _USB_HUB_NAME {
    ULONG ActualLength;     
    
    WCHAR HubName[1];       
} USB_HUB_NAME, *PUSB_HUB_NAME;

typedef struct _USB_ROOT_HUB_NAME {
    ULONG ActualLength;     
    
    WCHAR RootHubName[1];   
} USB_ROOT_HUB_NAME, *PUSB_ROOT_HUB_NAME;

typedef struct _USB_HCD_DRIVERKEY_NAME {
    ULONG ActualLength;     
    
    WCHAR DriverKeyName[1];   
} USB_HCD_DRIVERKEY_NAME, *PUSB_HCD_DRIVERKEY_NAME;	

typedef struct _USB_DESCRIPTOR_REQUEST {
    ULONG ConnectionIndex;
    struct {
        UCHAR bmRequest;
        UCHAR bRequest;
        USHORT wValue;
        USHORT wIndex;
        USHORT wLength;
    } SetupPacket;
    UCHAR Data[0];
} USB_DESCRIPTOR_REQUEST, *PUSB_DESCRIPTOR_REQUEST;	







typedef struct _HCD_STAT_COUNTERS {
    ULONG BytesTransferred;

    USHORT IsoMissedCount;
    USHORT DataOverrunErrorCount;

    USHORT CrcErrorCount;
    USHORT ScheduleOverrunCount;

    USHORT TimeoutErrorCount;
    USHORT InternalHcErrorCount;

    USHORT BufferOverrunErrorCount;
    USHORT SWErrorCount;

    USHORT StallPidCount;
    USHORT PortDisableCount;

} HCD_STAT_COUNTERS, *PHCD_STAT_COUNTERS;


typedef struct _HCD_ISO_STAT_COUNTERS {

    USHORT  LateUrbs;
    USHORT  DoubleBufferedPackets;

    USHORT  TransfersCF_5ms;
    USHORT  TransfersCF_2ms;

    USHORT  TransfersCF_1ms;
    USHORT  MaxInterruptLatency;
    
    USHORT  BadStartFrame;
    USHORT  StaleUrbs;

    USHORT  IsoPacketNotAccesed;
    USHORT  IsoPacketHWError;

    USHORT  SmallestUrbPacketCount;
    USHORT  LargestUrbPacketCount;

    USHORT IsoCRC_Error;
    USHORT IsoOVERRUN_Error;
    USHORT IsoINTERNAL_Error;
    USHORT IsoUNKNOWN_Error; 

    ULONG  IsoBytesTransferred;

    USHORT LateMissedCount;
    USHORT HWIsoMissedCount;
    
    ULONG  Reserved7[8];
    
} HCD_ISO_STAT_COUNTERS, *PHCD_ISO_STAT_COUNTERS;



typedef struct _HCD_STAT_INFORMATION_1 {
    ULONG Reserved1;
    ULONG Reserved2;
    ULONG ResetCounters;
    LARGE_INTEGER TimeRead;
    


    HCD_STAT_COUNTERS Counters;

} HCD_STAT_INFORMATION_1, *PHCD_STAT_INFORMATION_1;

typedef struct _HCD_STAT_INFORMATION_2 {
    ULONG Reserved1;
    ULONG Reserved2;
    ULONG ResetCounters;
    LARGE_INTEGER TimeRead;

    LONG LockedMemoryUsed;
    


    HCD_STAT_COUNTERS Counters;
    HCD_ISO_STAT_COUNTERS IsoCounters;

} HCD_STAT_INFORMATION_2, *PHCD_STAT_INFORMATION_2;










typedef enum _USB_NOTIFICATION_TYPE {

    

    EnumerationFailure = 0,
    InsufficentBandwidth,
    InsufficentPower,
    OverCurrent,
    ResetOvercurrent,

    

    AcquireBusInfo,

    

    AcquireHubName,
    AcquireControllerName,

    

    HubOvercurrent,
    HubPowerChange,
    
} USB_NOTIFICATION_TYPE;

typedef struct _USB_NOTIFICATION {
    
    USB_NOTIFICATION_TYPE NotificationType;     
    
} USB_NOTIFICATION, *PUSB_NOTIFICATION;



 
typedef struct _USB_CONNECTION_NOTIFICATION {
    
    USB_NOTIFICATION_TYPE NotificationType;     

    





    ULONG ConnectionNumber;

    


    ULONG RequestedBandwidth;     

    


    ULONG EnumerationFailReason;

    


    ULONG PowerRequested;

    


    ULONG HubNameLength;
    
} USB_CONNECTION_NOTIFICATION, *PUSB_CONNECTION_NOTIFICATION;





typedef struct _USB_BUS_NOTIFICATION {
    
    USB_NOTIFICATION_TYPE NotificationType;     

    ULONG TotalBandwidth;
    ULONG ConsumedBandwidth;

    


    ULONG ControllerNameLength; 

} USB_BUS_NOTIFICATION, *PUSB_BUS_NOTIFICATION;





typedef struct _USB_ACQUIRE_INFO {
    
    USB_NOTIFICATION_TYPE NotificationType;     
    
    ULONG TotalSize;                            

    WCHAR Buffer[1];
} USB_ACQUIRE_INFO, *PUSB_ACQUIRE_INFO;


#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"


#line 36 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"
#line 37 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\w2k\\poppack.h"

#line 605 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbioctl.h"


#line 608 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbioctl.h"

#line 43 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"

























                                                    























                                                           















































                    





















typedef LONG USBD_STATUS;

























































































































































typedef PVOID USBD_PIPE_HANDLE;
typedef PVOID USBD_CONFIGURATION_HANDLE;
typedef PVOID USBD_INTERFACE_HANDLE;












typedef struct _USBD_VERSION_INFORMATION {
    ULONG USBDI_Version;          
    ULONG Supported_USB_Version;  
} USBD_VERSION_INFORMATION, *PUSBD_VERSION_INFORMATION;

typedef enum _USBD_PIPE_TYPE {
    UsbdPipeTypeControl,
    UsbdPipeTypeIsochronous,
    UsbdPipeTypeBulk,
    UsbdPipeTypeInterrupt
} USBD_PIPE_TYPE;




typedef struct _USBD_DEVICE_INFORMATION {
    ULONG OffsetNext;
    PVOID UsbdDeviceHandle;
    USB_DEVICE_DESCRIPTOR DeviceDescriptor;
} USBD_DEVICE_INFORMATION, *PUSBD_DEVICE_INFORMATION;











typedef struct _USBD_PIPE_INFORMATION {
    
    
    
    
    USHORT MaximumPacketSize;  
    UCHAR EndpointAddress;     
                               
    UCHAR Interval;            
    
    USBD_PIPE_TYPE PipeType;   
    USBD_PIPE_HANDLE PipeHandle;
    
    
    
    
    
    ULONG MaximumTransferSize; 
                               
    ULONG PipeFlags;
} USBD_PIPE_INFORMATION, *PUSBD_PIPE_INFORMATION;

















typedef struct _USBD_INTERFACE_INFORMATION {
    USHORT Length;       
                         
                         
    
    
    
    
    
    
    UCHAR InterfaceNumber;
    UCHAR AlternateSetting;
    
    
    
    
    
    UCHAR Class;
    UCHAR SubClass;
    UCHAR Protocol;
    UCHAR Reserved;
    
    USBD_INTERFACE_HANDLE InterfaceHandle;
    ULONG NumberOfPipes; 

    
    
    



    USBD_PIPE_INFORMATION Pipes[1];
#line 433 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
} USBD_INTERFACE_INFORMATION, *PUSBD_INTERFACE_INFORMATION;






struct _URB_HCD_AREA {
    PVOID HcdEndpoint;
    PIRP HcdIrp;
    LIST_ENTRY HcdListEntry;
    LIST_ENTRY HcdListEntry2;
    PVOID HcdCurrentIoFlushPointer;
    PVOID HcdExtension;
};

struct _URB_HEADER {
    
    
    
    USHORT Length;
    USHORT Function;
    USBD_STATUS Status;
    
    
    
    PVOID UsbdDeviceHandle; 
                            
    ULONG UsbdFlags;        
};

struct _URB_SELECT_INTERFACE {



    struct _URB_HEADER Hdr;                 
#line 470 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    USBD_CONFIGURATION_HANDLE ConfigurationHandle;

    
    
    
    USBD_INTERFACE_INFORMATION Interface;
};

struct _URB_SELECT_CONFIGURATION {



    struct _URB_HEADER Hdr;                 
#line 484 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    
    
    
    PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor;
    USBD_CONFIGURATION_HANDLE ConfigurationHandle;
    USBD_INTERFACE_INFORMATION Interface;
};





struct _URB_PIPE_REQUEST {



    struct _URB_HEADER Hdr;                 
#line 502 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    USBD_PIPE_HANDLE PipeHandle;
    ULONG Reserved;
};







struct _URB_FRAME_LENGTH_CONTROL {



    struct _URB_HEADER Hdr;                 
#line 518 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
};

struct _URB_GET_FRAME_LENGTH {



    struct _URB_HEADER Hdr;                 
#line 526 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    ULONG FrameLength;
    ULONG FrameNumber;
};

struct _URB_SET_FRAME_LENGTH {



    struct _URB_HEADER Hdr;                 
#line 536 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    LONG FrameLengthDelta;
};

struct _URB_GET_CURRENT_FRAME_NUMBER {



    struct _URB_HEADER Hdr;                 
#line 545 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    ULONG FrameNumber;
};









struct _URB_CONTROL_DESCRIPTOR_REQUEST {



    struct _URB_HEADER Hdr;                 
#line 562 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;             
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;               
    USHORT Reserved1;
    UCHAR Index;
    UCHAR DescriptorType;
    USHORT LanguageId;
    USHORT Reserved2;
};



struct _URB_CONTROL_GET_STATUS_REQUEST {



    struct _URB_HEADER Hdr;                 
#line 585 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;             
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;           
    UCHAR Reserved1[4];
    USHORT Index;                       
    USHORT Reserved2;
};




struct _URB_CONTROL_FEATURE_REQUEST {



    struct _URB_HEADER Hdr;                 
#line 607 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    UCHAR Reserved[20];
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;           
    USHORT Reserved0;
    USHORT FeatureSelector;
    USHORT Index;                       
    USHORT Reserved1;
};



struct _URB_CONTROL_VENDOR_OR_CLASS_REQUEST {



    struct _URB_HEADER Hdr;                 
#line 625 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    PVOID Reserved;
    ULONG TransferFlags;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;             
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;           
    UCHAR RequestTypeReservedBits;
    UCHAR Request;
    USHORT Value;
    USHORT Index;
    USHORT Reserved1;
};


struct _URB_CONTROL_GET_INTERFACE_REQUEST {



    struct _URB_HEADER Hdr;                 
#line 647 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;             
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;           
    UCHAR Reserved1[4];    
    USHORT Interface;
    USHORT Reserved2;
};


struct _URB_CONTROL_GET_CONFIGURATION_REQUEST {



    struct _URB_HEADER Hdr;                 
#line 667 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;             
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;           
    UCHAR Reserved1[8];    
};







struct _URB_CONTROL_TRANSFER {



    struct _URB_HEADER Hdr;                 
#line 690 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    USBD_PIPE_HANDLE PipeHandle;
    ULONG TransferFlags;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;             
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;           
    UCHAR SetupPacket[8];
};


struct _URB_BULK_OR_INTERRUPT_TRANSFER {



    struct _URB_HEADER Hdr;                 
#line 708 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    USBD_PIPE_HANDLE PipeHandle;
    ULONG TransferFlags;                
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;             
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;           
};
























typedef struct _USBD_ISO_PACKET_DESCRIPTOR {
    ULONG Offset;       
                        

    ULONG Length;       
                        
    USBD_STATUS Status; 
} USBD_ISO_PACKET_DESCRIPTOR, *PUSBD_ISO_PACKET_DESCRIPTOR;

struct _URB_ISOCH_TRANSFER {
    
    
    



    struct _URB_HEADER Hdr;                 
#line 759 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
    USBD_PIPE_HANDLE PipeHandle;
    ULONG TransferFlags;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;             
    struct _URB *UrbLink;               
                                        
    struct _URB_HCD_AREA hca;           

    
    
    
    

    
    

    
    
    
    
    
    
    
    
    
    ULONG StartFrame;
    
    ULONG NumberOfPackets;
    
    ULONG ErrorCount;



    USBD_ISO_PACKET_DESCRIPTOR IsoPacket[1]; 
#line 795 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"
};


typedef struct _URB {
    union {
            struct _URB_HEADER                           UrbHeader;
            struct _URB_SELECT_INTERFACE                 UrbSelectInterface;
            struct _URB_SELECT_CONFIGURATION             UrbSelectConfiguration;
            struct _URB_PIPE_REQUEST                     UrbPipeRequest;
            struct _URB_FRAME_LENGTH_CONTROL             UrbFrameLengthControl;
            struct _URB_GET_FRAME_LENGTH                 UrbGetFrameLength;
            struct _URB_SET_FRAME_LENGTH                 UrbSetFrameLength;
            struct _URB_GET_CURRENT_FRAME_NUMBER         UrbGetCurrentFrameNumber;
            struct _URB_CONTROL_TRANSFER                 UrbControlTransfer;
            struct _URB_BULK_OR_INTERRUPT_TRANSFER       UrbBulkOrInterruptTransfer;
            struct _URB_ISOCH_TRANSFER                   UrbIsochronousTransfer;

            
            struct _URB_CONTROL_DESCRIPTOR_REQUEST       UrbControlDescriptorRequest;
            struct _URB_CONTROL_GET_STATUS_REQUEST       UrbControlGetStatusRequest;
            struct _URB_CONTROL_FEATURE_REQUEST          UrbControlFeatureRequest;
            struct _URB_CONTROL_VENDOR_OR_CLASS_REQUEST  UrbControlVendorClassRequest;
            struct _URB_CONTROL_GET_INTERFACE_REQUEST    UrbControlGetInterfaceRequest;
            struct _URB_CONTROL_GET_CONFIGURATION_REQUEST UrbControlGetConfigurationRequest;
    };
} URB, *PURB;


#line 824 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\inc\\ddk\\w2k\\usbdi.h"

#line 8 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\Usb.h"
#line 1 "C:\\WinDDK\\7600.16385.1\\inc\\ddk\\usbdlib.h"





























typedef struct _USBD_INTERFACE_LIST_ENTRY {
    PUSB_INTERFACE_DESCRIPTOR InterfaceDescriptor;
    PUSBD_INTERFACE_INFORMATION Interface;
} USBD_INTERFACE_LIST_ENTRY, *PUSBD_INTERFACE_LIST_ENTRY;






















            





















































































































#line 175 "C:\\WinDDK\\7600.16385.1\\inc\\ddk\\usbdlib.h"




















































 
__declspec(dllimport)
void
USBD_GetUSBDIVersion(
     PUSBD_VERSION_INFORMATION VersionInformation
    );


 
__declspec(dllimport)
PUSB_INTERFACE_DESCRIPTOR
USBD_ParseConfigurationDescriptor(
     PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
     UCHAR InterfaceNumber,
     UCHAR AlternateSetting
    );














 
__declspec(dllimport)
PURB
USBD_CreateConfigurationRequest(
      PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
     PUSHORT Siz
    );




















 
__declspec(dllimport)
PUSB_COMMON_DESCRIPTOR
USBD_ParseDescriptors(
     PVOID DescriptorBuffer,
     ULONG TotalLength,
     PVOID StartPosition,
     LONG DescriptorType
    );
























 
__declspec(dllimport)
PUSB_INTERFACE_DESCRIPTOR
USBD_ParseConfigurationDescriptorEx(
     PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
     PVOID StartPosition,
     LONG InterfaceNumber,
     LONG AlternateSetting,
     LONG InterfaceClass,
     LONG InterfaceSubClass,
     LONG InterfaceProtocol
    );




























 
__declspec(dllimport)
PURB
USBD_CreateConfigurationRequestEx(
     PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
     PUSBD_INTERFACE_LIST_ENTRY InterfaceList
    );






























 
__declspec(dllexport)
ULONG
USBD_GetInterfaceLength(
     PUSB_INTERFACE_DESCRIPTOR InterfaceDescriptor,
     PUCHAR BufferEnd
    );





















 
__declspec(dllexport)
void
USBD_RegisterHcFilter(
     PDEVICE_OBJECT DeviceObject,
     PDEVICE_OBJECT FilterDeviceObject
    );




















 
 
__declspec(dllexport)
NTSTATUS
USBD_GetPdoRegistryParameter(
     PDEVICE_OBJECT PhysicalDeviceObject,
     PVOID Parameter,
     ULONG ParameterLength,
     PWSTR KeyName,
     ULONG KeyNameLength
    );










 
__declspec(dllexport)
NTSTATUS
USBD_QueryBusTime(
     PDEVICE_OBJECT RootHubPdo,
     PULONG CurrentFrame
    );


















 
 
__declspec(dllimport)
ULONG
USBD_CalculateUsbBandwidth(
     ULONG MaxPacketSize,
     UCHAR EndpointType,
     BOOLEAN LowSpeed
    );












#line 517 "C:\\WinDDK\\7600.16385.1\\inc\\ddk\\usbdlib.h"



 
__declspec(dllimport)
USBD_STATUS
#line 523 "C:\\WinDDK\\7600.16385.1\\inc\\ddk\\usbdlib.h"
USBD_ValidateConfigurationDescriptor(
     PUSB_CONFIGURATION_DESCRIPTOR ConfigDesc,
     ULONG BufferLength,
     USHORT Level,
     PUCHAR *Offset,
     ULONG Tag);










































#line 572 "C:\\WinDDK\\7600.16385.1\\inc\\ddk\\usbdlib.h"

#line 574 "C:\\WinDDK\\7600.16385.1\\inc\\ddk\\usbdlib.h"

#line 576 "C:\\WinDDK\\7600.16385.1\\inc\\ddk\\usbdlib.h"

#line 9 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\Usb.h"
#line 1 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"































#line 33 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"



#line 37 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"



#line 41 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"



#line 45 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"



#line 49 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"



#line 53 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"



#line 57 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"



#line 61 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"



#line 65 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"

typedef enum _WDF_USB_REQUEST_TYPE {
    WdfUsbRequestTypeInvalid = 0,
    WdfUsbRequestTypeNoFormat,
    WdfUsbRequestTypeDeviceString,
    WdfUsbRequestTypeDeviceControlTransfer,
    WdfUsbRequestTypeDeviceUrb,
    WdfUsbRequestTypePipeWrite,
    WdfUsbRequestTypePipeRead,
    WdfUsbRequestTypePipeAbort,
    WdfUsbRequestTypePipeReset,
    WdfUsbRequestTypePipeUrb,
} WDF_USB_REQUEST_TYPE, *PWDF_USB_REQUEST_TYPE;

typedef enum _WDF_USB_BMREQUEST_DIRECTION {
    BmRequestHostToDevice = 0,
    BmRequestDeviceToHost = 1,
} WDF_USB_BMREQUEST_DIRECTION;

typedef enum _WDF_USB_BMREQUEST_TYPE {
    BmRequestStandard = 0,
    BmRequestClass = 1,
    BmRequestVendor = 2,
} WDF_USB_BMREQUEST_TYPE;

typedef enum _WDF_USB_BMREQUEST_RECIPIENT {
    BmRequestToDevice = 0,
    BmRequestToInterface = 1,
    BmRequestToEndpoint = 2,
    BmRequestToOther = 3,
} WDF_USB_BMREQUEST_RECIPIENT;

typedef enum _WDF_USB_PIPE_TYPE {
    WdfUsbPipeTypeInvalid = 0,
    WdfUsbPipeTypeControl,
    WdfUsbPipeTypeIsochronous,
    WdfUsbPipeTypeBulk,
    WdfUsbPipeTypeInterrupt,
} WDF_USB_PIPE_TYPE;

typedef enum _WdfUsbTargetDeviceSelectConfigType {
    WdfUsbTargetDeviceSelectConfigTypeInvalid = 0,
    WdfUsbTargetDeviceSelectConfigTypeDeconfig = 1,
    WdfUsbTargetDeviceSelectConfigTypeSingleInterface = 2,
    WdfUsbTargetDeviceSelectConfigTypeMultiInterface = 3,
    WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs = 4,
    WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor = 5,
    WdfUsbTargetDeviceSelectConfigTypeUrb = 6,
} WdfUsbTargetDeviceSelectConfigType;

typedef enum _WdfUsbTargetDeviceSelectSettingType {
    WdfUsbInterfaceSelectSettingTypeDescriptor = 0x10,
    WdfUsbInterfaceSelectSettingTypeSetting = 0x11,
    WdfUsbInterfaceSelectSettingTypeUrb = 0x12,
} WdfUsbTargetDeviceSelectSettingType;

typedef enum _WDF_USB_DEVICE_TRAITS {
    WDF_USB_DEVICE_TRAIT_SELF_POWERED =        0x00000001,
    WDF_USB_DEVICE_TRAIT_REMOTE_WAKE_CAPABLE = 0x00000002,
    WDF_USB_DEVICE_TRAIT_AT_HIGH_SPEED =       0x00000004,
} WDF_USB_DEVICE_TRAITS;



typedef union _WDF_USB_CONTROL_SETUP_PACKET {
    struct {
        union {
            #pragma warning(disable:4214) 
            struct {
                
                
                
                
                BYTE Recipient:2;

                BYTE Reserved:3;

                
                
                
                
                BYTE Type:2;

                
                
                
                
                BYTE Dir:1;
            } Request;
            #pragma warning(default:4214) 
            BYTE Byte;
        } bm;

        BYTE bRequest;

        union {
            struct {
                BYTE LowByte;
                BYTE HiByte;
            } Bytes;
            USHORT Value;
        } wValue;

        union {
            struct {
                BYTE LowByte;
                BYTE HiByte;
            } Bytes;
            USHORT Value;
        } wIndex;

        USHORT wLength;
    } Packet;

    struct {
        BYTE Bytes[8];
    } Generic;
} WDF_USB_CONTROL_SETUP_PACKET, *PWDF_USB_CONTROL_SETUP_PACKET;

void
__forceinline
WDF_USB_CONTROL_SETUP_PACKET_INIT(
     PWDF_USB_CONTROL_SETUP_PACKET Packet,
     WDF_USB_BMREQUEST_DIRECTION Direction,
     WDF_USB_BMREQUEST_RECIPIENT Recipient,
     BYTE Request,
     USHORT Value,
     USHORT Index
    )
{
    memset((Packet),0,(sizeof(WDF_USB_CONTROL_SETUP_PACKET)));

    Packet->Packet.bm.Request.Dir = (BYTE) Direction;
    Packet->Packet.bm.Request.Type = (BYTE) BmRequestStandard;
    Packet->Packet.bm.Request.Recipient = (BYTE) Recipient;

    Packet->Packet.bRequest = Request;
    Packet->Packet.wValue.Value = Value;
    Packet->Packet.wIndex.Value = Index;

    
}

void
__forceinline
WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS(
     PWDF_USB_CONTROL_SETUP_PACKET Packet,
     WDF_USB_BMREQUEST_DIRECTION Direction,
     WDF_USB_BMREQUEST_RECIPIENT Recipient,
     BYTE Request,
     USHORT Value,
     USHORT Index
    )
{
    memset((Packet),0,(sizeof(WDF_USB_CONTROL_SETUP_PACKET)));

    Packet->Packet.bm.Request.Dir = (BYTE) Direction;
    Packet->Packet.bm.Request.Type = (BYTE) BmRequestClass;
    Packet->Packet.bm.Request.Recipient = (BYTE) Recipient;

    Packet->Packet.bRequest = Request;
    Packet->Packet.wValue.Value = Value;
    Packet->Packet.wIndex.Value = Index;

    
}

void
__forceinline
WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR(
     PWDF_USB_CONTROL_SETUP_PACKET Packet,
     WDF_USB_BMREQUEST_DIRECTION Direction,
     WDF_USB_BMREQUEST_RECIPIENT Recipient,
     BYTE Request,
     USHORT Value,
     USHORT Index
    )
{
    memset((Packet),0,(sizeof(WDF_USB_CONTROL_SETUP_PACKET)));

    Packet->Packet.bm.Request.Dir = (BYTE) Direction;
    Packet->Packet.bm.Request.Type = (BYTE) BmRequestVendor;
    Packet->Packet.bm.Request.Recipient = (BYTE) Recipient;

    Packet->Packet.bRequest = Request;
    Packet->Packet.wValue.Value = Value;
    Packet->Packet.wIndex.Value = Index;

    
}

void
__forceinline
WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE(
     PWDF_USB_CONTROL_SETUP_PACKET Packet,
     WDF_USB_BMREQUEST_RECIPIENT BmRequestRecipient,
     USHORT FeatureSelector,
     USHORT Index,
     BOOLEAN SetFeature
    )
{
    memset((Packet),0,(sizeof(WDF_USB_CONTROL_SETUP_PACKET)));

    Packet->Packet.bm.Request.Dir = (BYTE) BmRequestHostToDevice;
    Packet->Packet.bm.Request.Type = (BYTE) BmRequestStandard;
    Packet->Packet.bm.Request.Recipient = (BYTE) BmRequestRecipient;

    if (SetFeature) {
        Packet->Packet.bRequest = 0x03;
    }
    else {
        Packet->Packet.bRequest = 0x01;
    }

    Packet->Packet.wValue.Value = FeatureSelector;
    Packet->Packet.wIndex.Value = Index;

    
}

void
__forceinline
WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS(
     PWDF_USB_CONTROL_SETUP_PACKET Packet,
     WDF_USB_BMREQUEST_RECIPIENT BmRequestRecipient,
     USHORT Index
    )
{
    memset((Packet),0,(sizeof(WDF_USB_CONTROL_SETUP_PACKET)));

    Packet->Packet.bm.Request.Dir = (BYTE) BmRequestDeviceToHost;
    Packet->Packet.bm.Request.Type = (BYTE) BmRequestStandard;
    Packet->Packet.bm.Request.Recipient = (BYTE) BmRequestRecipient;

    Packet->Packet.bRequest = 0x00;
    Packet->Packet.wIndex.Value = Index;
    Packet->Packet.wValue.Value = 0;

    
}

typedef struct _WDF_USB_REQUEST_COMPLETION_PARAMS {
    USBD_STATUS UsbdStatus;

    WDF_USB_REQUEST_TYPE Type;

    union {
        struct {
            WDFMEMORY Buffer;
            USHORT LangID;
            UCHAR StringIndex;

            
            
            
            
            UCHAR RequiredSize;
        } DeviceString;

        struct {
            WDFMEMORY Buffer;
            WDF_USB_CONTROL_SETUP_PACKET SetupPacket;
            ULONG Length;
        } DeviceControlTransfer;

        struct {
            WDFMEMORY Buffer;
        } DeviceUrb;

        struct {
            WDFMEMORY Buffer;
            size_t Length;
            size_t Offset;
        } PipeWrite;

        struct {
            WDFMEMORY Buffer;
            size_t Length;
            size_t Offset;
        } PipeRead;

        struct {
            WDFMEMORY Buffer;
        } PipeUrb;
    } Parameters;

} WDF_USB_REQUEST_COMPLETION_PARAMS, *PWDF_USB_REQUEST_COMPLETION_PARAMS;

typedef



void
EVT_WDF_USB_READER_COMPLETION_ROUTINE(
    
    WDFUSBPIPE Pipe,
    
    WDFMEMORY Buffer,
    
    size_t NumBytesTransferred,
    
    WDFCONTEXT Context
    );

typedef EVT_WDF_USB_READER_COMPLETION_ROUTINE *PFN_WDF_USB_READER_COMPLETION_ROUTINE;

typedef



BOOLEAN
EVT_WDF_USB_READERS_FAILED(
    
    WDFUSBPIPE Pipe,
    
    NTSTATUS Status,
    
    USBD_STATUS UsbdStatus
    );

typedef EVT_WDF_USB_READERS_FAILED *PFN_WDF_USB_READERS_FAILED;

typedef struct _WDF_USB_CONTINUOUS_READER_CONFIG {
    
    
    
    ULONG Size;

    
    
    
    size_t TransferLength;

    
    
    
    size_t HeaderLength;

    
    
    
    size_t TrailerLength;

    
    
    
    
    UCHAR NumPendingReads;

    
    
    
    PWDF_OBJECT_ATTRIBUTES BufferAttributes;

    
    
    
    PFN_WDF_USB_READER_COMPLETION_ROUTINE EvtUsbTargetPipeReadComplete;

    
    
    
    WDFCONTEXT EvtUsbTargetPipeReadCompleteContext;

    
    
    
    
    PFN_WDF_USB_READERS_FAILED EvtUsbTargetPipeReadersFailed;

} WDF_USB_CONTINUOUS_READER_CONFIG, *PWDF_USB_CONTINUOUS_READER_CONFIG;


void
__forceinline
WDF_USB_CONTINUOUS_READER_CONFIG_INIT(
     PWDF_USB_CONTINUOUS_READER_CONFIG Config,
     PFN_WDF_USB_READER_COMPLETION_ROUTINE EvtUsbTargetPipeReadComplete,
     WDFCONTEXT EvtUsbTargetPipeReadCompleteContext,
     size_t TransferLength
    )

{
    memset((Config),0,(sizeof(WDF_USB_CONTINUOUS_READER_CONFIG)));
    Config->Size = sizeof(WDF_USB_CONTINUOUS_READER_CONFIG);

    Config->EvtUsbTargetPipeReadComplete = EvtUsbTargetPipeReadComplete;
    Config->EvtUsbTargetPipeReadCompleteContext = EvtUsbTargetPipeReadCompleteContext;
    Config->TransferLength = TransferLength;
}

WDFIOTARGET
__forceinline
WdfUsbTargetDeviceGetIoTarget(
     WDFUSBDEVICE UsbDevice
    )
{
    return (WDFIOTARGET) UsbDevice;
}

typedef struct _WDF_USB_DEVICE_INFORMATION {
    
    
    
    ULONG Size;

    
    
    
    USBD_VERSION_INFORMATION UsbdVersionInformation;

    
    
    
    ULONG HcdPortCapabilities;

    
    
    
    ULONG Traits;

} WDF_USB_DEVICE_INFORMATION, *PWDF_USB_DEVICE_INFORMATION;

void
__forceinline
WDF_USB_DEVICE_INFORMATION_INIT(
     PWDF_USB_DEVICE_INFORMATION Udi
    )
{
    memset((Udi),0,(sizeof(WDF_USB_DEVICE_INFORMATION)));
    Udi->Size = sizeof(WDF_USB_DEVICE_INFORMATION);
}

typedef struct _WDF_USB_INTERFACE_SETTING_PAIR {
    
    
    
    WDFUSBINTERFACE UsbInterface;

    
    
    
    UCHAR SettingIndex;

} WDF_USB_INTERFACE_SETTING_PAIR, *PWDF_USB_INTERFACE_SETTING_PAIR;

typedef struct _WDF_USB_DEVICE_SELECT_CONFIG_PARAMS {
    
    
    
    ULONG Size;

    
    
    
    WdfUsbTargetDeviceSelectConfigType Type;


    union {
        struct {
            
            
            
            PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor;

            
            
            
            PUSB_INTERFACE_DESCRIPTOR * InterfaceDescriptors;

            
            
            
            ULONG NumInterfaceDescriptors;

        } Descriptor;

        struct {
            
            
            
            
            
            PURB Urb;

        } Urb;

        struct {
            
            
            
            
            UCHAR   NumberConfiguredPipes;

            
            
            
            
            WDFUSBINTERFACE ConfiguredUsbInterface;

        } SingleInterface;

        struct {
            
            
            
            UCHAR NumberInterfaces;

            
            
            
            PWDF_USB_INTERFACE_SETTING_PAIR Pairs;

            
            
            
            UCHAR NumberOfConfiguredInterfaces;

        } MultiInterface;

    } Types;

} WDF_USB_DEVICE_SELECT_CONFIG_PARAMS, *PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS;


void
__forceinline
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE(
     PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params
    )
{
    memset((Params),0,(sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS)));

    Params->Size = sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS);
    Params->Type = WdfUsbTargetDeviceSelectConfigTypeSingleInterface;
}

void
__forceinline
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES(
      PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params,
     UCHAR NumberInterfaces,
     PWDF_USB_INTERFACE_SETTING_PAIR SettingPairs
    )
{
    memset((Params),0,(sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS)));

    Params->Size = sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS);

    if (SettingPairs != ((void *)0) && NumberInterfaces != 0) {
        Params->Type = WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs;

        Params->Types.MultiInterface.NumberInterfaces = NumberInterfaces;
        Params->Types.MultiInterface.Pairs = SettingPairs;
    }
    else {
        Params->Type = WdfUsbTargetDeviceSelectConfigTypeMultiInterface;
    }
}

void
__forceinline
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS(
     PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params,
      PUSB_CONFIGURATION_DESCRIPTOR ConfigDescriptor,
      PUSB_INTERFACE_DESCRIPTOR* InterfaceDescriptors,
      ULONG NumInterfaceDescriptors
    )
{
    memset((Params),0,(sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS)));

    Params->Size = sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS);
    Params->Type = WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor;
    Params->Types.Descriptor.ConfigurationDescriptor = ConfigDescriptor;
    Params->Types.Descriptor.InterfaceDescriptors = InterfaceDescriptors;
    Params->Types.Descriptor.NumInterfaceDescriptors = NumInterfaceDescriptors;
}

void
__forceinline
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_URB(
     PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params,
      PURB Urb
    )
{
    memset((Params),0,(sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS)));

    Params->Size = sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS);
    Params->Type = WdfUsbTargetDeviceSelectConfigTypeUrb;
    Params->Types.Urb.Urb = Urb;
}


void
__forceinline
WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_DECONFIG(
     PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params
    )
{
    memset((Params),0,(sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS)));

    Params->Size = sizeof(WDF_USB_DEVICE_SELECT_CONFIG_PARAMS);
    Params->Type = WdfUsbTargetDeviceSelectConfigTypeDeconfig;
}

typedef struct _WDF_USB_INTERFACE_SELECT_SETTING_PARAMS {
    
    
    
    ULONG Size;

    
    
    
    
    WdfUsbTargetDeviceSelectSettingType Type;

    union {

        struct {
            
            
            
            PUSB_INTERFACE_DESCRIPTOR InterfaceDescriptor;

        } Descriptor;

        struct {
            
            
            
            UCHAR SettingIndex;

        } Interface;

        struct {
            
            
            
            
            PURB Urb;

        } Urb;

    } Types;

} WDF_USB_INTERFACE_SELECT_SETTING_PARAMS, *PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS;

void
__forceinline
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_DESCRIPTOR(
     PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS Params,
      PUSB_INTERFACE_DESCRIPTOR Interface
    )
{
    memset((Params),0,(sizeof(WDF_USB_INTERFACE_SELECT_SETTING_PARAMS)));

    Params->Size = sizeof(WDF_USB_INTERFACE_SELECT_SETTING_PARAMS);
    Params->Type = WdfUsbInterfaceSelectSettingTypeDescriptor;
    Params->Types.Descriptor.InterfaceDescriptor = Interface;
}

void
__forceinline
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_URB(
     PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS Params,
      PURB Urb
    )
{
    memset((Params),0,(sizeof(WDF_USB_INTERFACE_SELECT_SETTING_PARAMS)));

    Params->Size = sizeof(WDF_USB_INTERFACE_SELECT_SETTING_PARAMS);
    Params->Type = WdfUsbInterfaceSelectSettingTypeUrb;
    Params->Types.Urb.Urb = Urb;
}

void
__forceinline
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING(
     PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS Params,
      UCHAR SettingIndex
    )
{
    memset((Params),0,(sizeof(WDF_USB_INTERFACE_SELECT_SETTING_PARAMS)));

    Params->Size = sizeof(WDF_USB_INTERFACE_SELECT_SETTING_PARAMS);
    Params->Type = WdfUsbInterfaceSelectSettingTypeSetting;
    Params->Types.Interface.SettingIndex = SettingIndex;
}

WDFIOTARGET
__forceinline
WdfUsbTargetPipeGetIoTarget(
     WDFUSBPIPE Pipe
    )
{
    return (WDFIOTARGET) Pipe;
}


typedef struct _WDF_USB_PIPE_INFORMATION {
    
    
    
    ULONG Size;

    
    
    
    ULONG MaximumPacketSize;

    
    
    
    UCHAR EndpointAddress;

    
    
    
    UCHAR Interval;

    
    
    
    UCHAR SettingIndex;

    
    
    WDF_USB_PIPE_TYPE PipeType;

    
    
    
    ULONG  MaximumTransferSize;

} WDF_USB_PIPE_INFORMATION, *PWDF_USB_PIPE_INFORMATION;

void
__forceinline
WDF_USB_PIPE_INFORMATION_INIT(
     PWDF_USB_PIPE_INFORMATION Info
    )
{
    memset((Info),0,(sizeof(WDF_USB_PIPE_INFORMATION)));

    Info->Size = sizeof(WDF_USB_PIPE_INFORMATION);
}

BOOLEAN
__forceinline
WDF_USB_PIPE_DIRECTION_IN(
     UCHAR EndpointAddress
    )
{
    
    
    
    return (EndpointAddress & 0x80) ? 1 : 0;
}

BOOLEAN
__forceinline
WDF_USB_PIPE_DIRECTION_OUT(
     UCHAR EndpointAddress
    )
{
    
    
    
    return (EndpointAddress & 0x80) == 0x00 ? 1 : 0;
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICECREATE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFDEVICE Device,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFUSBDEVICE* UsbDevice
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceCreate(
    
    WDFDEVICE Device,
    
    PWDF_OBJECT_ATTRIBUTES Attributes,
    
    WDFUSBDEVICE* UsbDevice
    )
{
    return ((PFN_WDFUSBTARGETDEVICECREATE) WdfFunctions[WdfUsbTargetDeviceCreateTableIndex])(WdfDriverGlobals, Device, Attributes, UsbDevice);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICERETRIEVEINFORMATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    PWDF_USB_DEVICE_INFORMATION Information
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceRetrieveInformation(
    
    WDFUSBDEVICE UsbDevice,
    
    PWDF_USB_DEVICE_INFORMATION Information
    )
{
    return ((PFN_WDFUSBTARGETDEVICERETRIEVEINFORMATION) WdfFunctions[WdfUsbTargetDeviceRetrieveInformationTableIndex])(WdfDriverGlobals, UsbDevice, Information);
}




typedef


void
(*PFN_WDFUSBTARGETDEVICEGETDEVICEDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    PUSB_DEVICE_DESCRIPTOR UsbDeviceDescriptor
    );


void
__forceinline
WdfUsbTargetDeviceGetDeviceDescriptor(
    
    WDFUSBDEVICE UsbDevice,
    
    PUSB_DEVICE_DESCRIPTOR UsbDeviceDescriptor
    )
{
    ((PFN_WDFUSBTARGETDEVICEGETDEVICEDESCRIPTOR) WdfFunctions[WdfUsbTargetDeviceGetDeviceDescriptorTableIndex])(WdfDriverGlobals, UsbDevice, UsbDeviceDescriptor);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICERETRIEVECONFIGDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    PVOID ConfigDescriptor,
    
    PUSHORT ConfigDescriptorLength
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceRetrieveConfigDescriptor(
    
    WDFUSBDEVICE UsbDevice,
    
    PVOID ConfigDescriptor,
    
    PUSHORT ConfigDescriptorLength
    )
{
    return ((PFN_WDFUSBTARGETDEVICERETRIEVECONFIGDESCRIPTOR) WdfFunctions[WdfUsbTargetDeviceRetrieveConfigDescriptorTableIndex])(WdfDriverGlobals, UsbDevice, ConfigDescriptor, ConfigDescriptorLength);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICEQUERYSTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PUSHORT String,
    
    PUSHORT NumCharacters,
    
    UCHAR StringIndex,
    
    USHORT LangID
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceQueryString(
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PUSHORT String,
    
    PUSHORT NumCharacters,
    
    UCHAR StringIndex,
    
    USHORT LangID
    )
{
    return ((PFN_WDFUSBTARGETDEVICEQUERYSTRING) WdfFunctions[WdfUsbTargetDeviceQueryStringTableIndex])(WdfDriverGlobals, UsbDevice, Request, RequestOptions, String, NumCharacters, StringIndex, LangID);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICEALLOCANDQUERYSTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    PWDF_OBJECT_ATTRIBUTES StringMemoryAttributes,
    
    WDFMEMORY* StringMemory,
    
    PUSHORT NumCharacters,
    
    UCHAR StringIndex,
    
    USHORT LangID
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceAllocAndQueryString(
    
    WDFUSBDEVICE UsbDevice,
    
    PWDF_OBJECT_ATTRIBUTES StringMemoryAttributes,
    
    WDFMEMORY* StringMemory,
    
    PUSHORT NumCharacters,
    
    UCHAR StringIndex,
    
    USHORT LangID
    )
{
    return ((PFN_WDFUSBTARGETDEVICEALLOCANDQUERYSTRING) WdfFunctions[WdfUsbTargetDeviceAllocAndQueryStringTableIndex])(WdfDriverGlobals, UsbDevice, StringMemoryAttributes, StringMemory, NumCharacters, StringIndex, LangID);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORSTRING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    WDFMEMORY Memory,
    
    PWDFMEMORY_OFFSET Offset,
    
    UCHAR StringIndex,
    
    USHORT LangID
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceFormatRequestForString(
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    WDFMEMORY Memory,
    
    PWDFMEMORY_OFFSET Offset,
    
    UCHAR StringIndex,
    
    USHORT LangID
    )
{
    return ((PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORSTRING) WdfFunctions[WdfUsbTargetDeviceFormatRequestForStringTableIndex])(WdfDriverGlobals, UsbDevice, Request, Memory, Offset, StringIndex, LangID);
}




typedef


UCHAR
(*PFN_WDFUSBTARGETDEVICEGETNUMINTERFACES)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice
    );


UCHAR
__forceinline
WdfUsbTargetDeviceGetNumInterfaces(
    
    WDFUSBDEVICE UsbDevice
    )
{
    return ((PFN_WDFUSBTARGETDEVICEGETNUMINTERFACES) WdfFunctions[WdfUsbTargetDeviceGetNumInterfacesTableIndex])(WdfDriverGlobals, UsbDevice);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICESELECTCONFIG)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    PWDF_OBJECT_ATTRIBUTES PipeAttributes,
    
    PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceSelectConfig(
    
    WDFUSBDEVICE UsbDevice,
    
    PWDF_OBJECT_ATTRIBUTES PipeAttributes,
    
    PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params
    )
{
    return ((PFN_WDFUSBTARGETDEVICESELECTCONFIG) WdfFunctions[WdfUsbTargetDeviceSelectConfigTableIndex])(WdfDriverGlobals, UsbDevice, PipeAttributes, Params);
}




typedef


USBD_CONFIGURATION_HANDLE
(*PFN_WDFUSBTARGETDEVICEWDMGETCONFIGURATIONHANDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice
    );


USBD_CONFIGURATION_HANDLE
__forceinline
WdfUsbTargetDeviceWdmGetConfigurationHandle(
    
    WDFUSBDEVICE UsbDevice
    )
{
    return ((PFN_WDFUSBTARGETDEVICEWDMGETCONFIGURATIONHANDLE) WdfFunctions[WdfUsbTargetDeviceWdmGetConfigurationHandleTableIndex])(WdfDriverGlobals, UsbDevice);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICERETRIEVECURRENTFRAMENUMBER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    PULONG CurrentFrameNumber
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceRetrieveCurrentFrameNumber(
    
    WDFUSBDEVICE UsbDevice,
    
    PULONG CurrentFrameNumber
    )
{
    return ((PFN_WDFUSBTARGETDEVICERETRIEVECURRENTFRAMENUMBER) WdfFunctions[WdfUsbTargetDeviceRetrieveCurrentFrameNumberTableIndex])(WdfDriverGlobals, UsbDevice, CurrentFrameNumber);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICESENDCONTROLTRANSFERSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PWDF_USB_CONTROL_SETUP_PACKET SetupPacket,
    
    PWDF_MEMORY_DESCRIPTOR MemoryDescriptor,
    
    PULONG BytesTransferred
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceSendControlTransferSynchronously(
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PWDF_USB_CONTROL_SETUP_PACKET SetupPacket,
    
    PWDF_MEMORY_DESCRIPTOR MemoryDescriptor,
    
    PULONG BytesTransferred
    )
{
    return ((PFN_WDFUSBTARGETDEVICESENDCONTROLTRANSFERSYNCHRONOUSLY) WdfFunctions[WdfUsbTargetDeviceSendControlTransferSynchronouslyTableIndex])(WdfDriverGlobals, UsbDevice, Request, RequestOptions, SetupPacket, MemoryDescriptor, BytesTransferred);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCONTROLTRANSFER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    PWDF_USB_CONTROL_SETUP_PACKET SetupPacket,
    
    WDFMEMORY TransferMemory,
    
    PWDFMEMORY_OFFSET TransferOffset
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceFormatRequestForControlTransfer(
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    PWDF_USB_CONTROL_SETUP_PACKET SetupPacket,
    
    WDFMEMORY TransferMemory,
    
    PWDFMEMORY_OFFSET TransferOffset
    )
{
    return ((PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCONTROLTRANSFER) WdfFunctions[WdfUsbTargetDeviceFormatRequestForControlTransferTableIndex])(WdfDriverGlobals, UsbDevice, Request, SetupPacket, TransferMemory, TransferOffset);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICEISCONNECTEDSYNCHRONOUS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceIsConnectedSynchronous(
    
    WDFUSBDEVICE UsbDevice
    )
{
    return ((PFN_WDFUSBTARGETDEVICEISCONNECTEDSYNCHRONOUS) WdfFunctions[WdfUsbTargetDeviceIsConnectedSynchronousTableIndex])(WdfDriverGlobals, UsbDevice);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICERESETPORTSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceResetPortSynchronously(
    
    WDFUSBDEVICE UsbDevice
    )
{
    return ((PFN_WDFUSBTARGETDEVICERESETPORTSYNCHRONOUSLY) WdfFunctions[WdfUsbTargetDeviceResetPortSynchronouslyTableIndex])(WdfDriverGlobals, UsbDevice);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICECYCLEPORTSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceCyclePortSynchronously(
    
    WDFUSBDEVICE UsbDevice
    )
{
    return ((PFN_WDFUSBTARGETDEVICECYCLEPORTSYNCHRONOUSLY) WdfFunctions[WdfUsbTargetDeviceCyclePortSynchronouslyTableIndex])(WdfDriverGlobals, UsbDevice);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCYCLEPORT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceFormatRequestForCyclePort(
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORCYCLEPORT) WdfFunctions[WdfUsbTargetDeviceFormatRequestForCyclePortTableIndex])(WdfDriverGlobals, UsbDevice, Request);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICESENDURBSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PURB Urb
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceSendUrbSynchronously(
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PURB Urb
    )
{
    return ((PFN_WDFUSBTARGETDEVICESENDURBSYNCHRONOUSLY) WdfFunctions[WdfUsbTargetDeviceSendUrbSynchronouslyTableIndex])(WdfDriverGlobals, UsbDevice, Request, RequestOptions, Urb);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORURB)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    WDFMEMORY UrbMemory,
    
    PWDFMEMORY_OFFSET UrbMemoryOffset
    );



NTSTATUS
__forceinline
WdfUsbTargetDeviceFormatRequestForUrb(
    
    WDFUSBDEVICE UsbDevice,
    
    WDFREQUEST Request,
    
    WDFMEMORY UrbMemory,
    
    PWDFMEMORY_OFFSET UrbMemoryOffset
    )
{
    return ((PFN_WDFUSBTARGETDEVICEFORMATREQUESTFORURB) WdfFunctions[WdfUsbTargetDeviceFormatRequestForUrbTableIndex])(WdfDriverGlobals, UsbDevice, Request, UrbMemory, UrbMemoryOffset);
}




typedef


void
(*PFN_WDFUSBTARGETPIPEGETINFORMATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    PWDF_USB_PIPE_INFORMATION PipeInformation
    );


void
__forceinline
WdfUsbTargetPipeGetInformation(
    
    WDFUSBPIPE Pipe,
    
    PWDF_USB_PIPE_INFORMATION PipeInformation
    )
{
    ((PFN_WDFUSBTARGETPIPEGETINFORMATION) WdfFunctions[WdfUsbTargetPipeGetInformationTableIndex])(WdfDriverGlobals, Pipe, PipeInformation);
}




typedef


BOOLEAN
(*PFN_WDFUSBTARGETPIPEISINENDPOINT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe
    );


BOOLEAN
__forceinline
WdfUsbTargetPipeIsInEndpoint(
    
    WDFUSBPIPE Pipe
    )
{
    return ((PFN_WDFUSBTARGETPIPEISINENDPOINT) WdfFunctions[WdfUsbTargetPipeIsInEndpointTableIndex])(WdfDriverGlobals, Pipe);
}




typedef


BOOLEAN
(*PFN_WDFUSBTARGETPIPEISOUTENDPOINT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe
    );


BOOLEAN
__forceinline
WdfUsbTargetPipeIsOutEndpoint(
    
    WDFUSBPIPE Pipe
    )
{
    return ((PFN_WDFUSBTARGETPIPEISOUTENDPOINT) WdfFunctions[WdfUsbTargetPipeIsOutEndpointTableIndex])(WdfDriverGlobals, Pipe);
}




typedef


WDF_USB_PIPE_TYPE
(*PFN_WDFUSBTARGETPIPEGETTYPE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe
    );


WDF_USB_PIPE_TYPE
__forceinline
WdfUsbTargetPipeGetType(
    
    WDFUSBPIPE Pipe
    )
{
    return ((PFN_WDFUSBTARGETPIPEGETTYPE) WdfFunctions[WdfUsbTargetPipeGetTypeTableIndex])(WdfDriverGlobals, Pipe);
}




typedef


void
(*PFN_WDFUSBTARGETPIPESETNOMAXIMUMPACKETSIZECHECK)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe
    );


void
__forceinline
WdfUsbTargetPipeSetNoMaximumPacketSizeCheck(
    
    WDFUSBPIPE Pipe
    )
{
    ((PFN_WDFUSBTARGETPIPESETNOMAXIMUMPACKETSIZECHECK) WdfFunctions[WdfUsbTargetPipeSetNoMaximumPacketSizeCheckTableIndex])(WdfDriverGlobals, Pipe);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPEWRITESYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PWDF_MEMORY_DESCRIPTOR MemoryDescriptor,
    
    PULONG BytesWritten
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeWriteSynchronously(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PWDF_MEMORY_DESCRIPTOR MemoryDescriptor,
    
    PULONG BytesWritten
    )
{
    return ((PFN_WDFUSBTARGETPIPEWRITESYNCHRONOUSLY) WdfFunctions[WdfUsbTargetPipeWriteSynchronouslyTableIndex])(WdfDriverGlobals, Pipe, Request, RequestOptions, MemoryDescriptor, BytesWritten);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPEFORMATREQUESTFORWRITE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    WDFMEMORY WriteMemory,
    
    PWDFMEMORY_OFFSET WriteOffset
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeFormatRequestForWrite(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    WDFMEMORY WriteMemory,
    
    PWDFMEMORY_OFFSET WriteOffset
    )
{
    return ((PFN_WDFUSBTARGETPIPEFORMATREQUESTFORWRITE) WdfFunctions[WdfUsbTargetPipeFormatRequestForWriteTableIndex])(WdfDriverGlobals, Pipe, Request, WriteMemory, WriteOffset);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPEREADSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PWDF_MEMORY_DESCRIPTOR MemoryDescriptor,
    
    PULONG BytesRead
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeReadSynchronously(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PWDF_MEMORY_DESCRIPTOR MemoryDescriptor,
    
    PULONG BytesRead
    )
{
    return ((PFN_WDFUSBTARGETPIPEREADSYNCHRONOUSLY) WdfFunctions[WdfUsbTargetPipeReadSynchronouslyTableIndex])(WdfDriverGlobals, Pipe, Request, RequestOptions, MemoryDescriptor, BytesRead);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPEFORMATREQUESTFORREAD)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    WDFMEMORY ReadMemory,
    
    PWDFMEMORY_OFFSET ReadOffset
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeFormatRequestForRead(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    WDFMEMORY ReadMemory,
    
    PWDFMEMORY_OFFSET ReadOffset
    )
{
    return ((PFN_WDFUSBTARGETPIPEFORMATREQUESTFORREAD) WdfFunctions[WdfUsbTargetPipeFormatRequestForReadTableIndex])(WdfDriverGlobals, Pipe, Request, ReadMemory, ReadOffset);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPECONFIGCONTINUOUSREADER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    PWDF_USB_CONTINUOUS_READER_CONFIG Config
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeConfigContinuousReader(
    
    WDFUSBPIPE Pipe,
    
    PWDF_USB_CONTINUOUS_READER_CONFIG Config
    )
{
    return ((PFN_WDFUSBTARGETPIPECONFIGCONTINUOUSREADER) WdfFunctions[WdfUsbTargetPipeConfigContinuousReaderTableIndex])(WdfDriverGlobals, Pipe, Config);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPEABORTSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeAbortSynchronously(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions
    )
{
    return ((PFN_WDFUSBTARGETPIPEABORTSYNCHRONOUSLY) WdfFunctions[WdfUsbTargetPipeAbortSynchronouslyTableIndex])(WdfDriverGlobals, Pipe, Request, RequestOptions);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPEFORMATREQUESTFORABORT)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeFormatRequestForAbort(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFUSBTARGETPIPEFORMATREQUESTFORABORT) WdfFunctions[WdfUsbTargetPipeFormatRequestForAbortTableIndex])(WdfDriverGlobals, Pipe, Request);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPERESETSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeResetSynchronously(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions
    )
{
    return ((PFN_WDFUSBTARGETPIPERESETSYNCHRONOUSLY) WdfFunctions[WdfUsbTargetPipeResetSynchronouslyTableIndex])(WdfDriverGlobals, Pipe, Request, RequestOptions);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPEFORMATREQUESTFORRESET)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeFormatRequestForReset(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request
    )
{
    return ((PFN_WDFUSBTARGETPIPEFORMATREQUESTFORRESET) WdfFunctions[WdfUsbTargetPipeFormatRequestForResetTableIndex])(WdfDriverGlobals, Pipe, Request);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPESENDURBSYNCHRONOUSLY)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PURB Urb
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeSendUrbSynchronously(
    
    WDFUSBPIPE Pipe,
    
    WDFREQUEST Request,
    
    PWDF_REQUEST_SEND_OPTIONS RequestOptions,
    
    PURB Urb
    )
{
    return ((PFN_WDFUSBTARGETPIPESENDURBSYNCHRONOUSLY) WdfFunctions[WdfUsbTargetPipeSendUrbSynchronouslyTableIndex])(WdfDriverGlobals, Pipe, Request, RequestOptions, Urb);
}




typedef



NTSTATUS
(*PFN_WDFUSBTARGETPIPEFORMATREQUESTFORURB)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE PIPE,
    
    WDFREQUEST Request,
    
    WDFMEMORY UrbMemory,
    
    PWDFMEMORY_OFFSET UrbMemoryOffset
    );



NTSTATUS
__forceinline
WdfUsbTargetPipeFormatRequestForUrb(
    
    WDFUSBPIPE PIPE,
    
    WDFREQUEST Request,
    
    WDFMEMORY UrbMemory,
    
    PWDFMEMORY_OFFSET UrbMemoryOffset
    )
{
    return ((PFN_WDFUSBTARGETPIPEFORMATREQUESTFORURB) WdfFunctions[WdfUsbTargetPipeFormatRequestForUrbTableIndex])(WdfDriverGlobals, PIPE, Request, UrbMemory, UrbMemoryOffset);
}




typedef


BYTE
(*PFN_WDFUSBINTERFACEGETINTERFACENUMBER)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE UsbInterface
    );


BYTE
__forceinline
WdfUsbInterfaceGetInterfaceNumber(
    
    WDFUSBINTERFACE UsbInterface
    )
{
    return ((PFN_WDFUSBINTERFACEGETINTERFACENUMBER) WdfFunctions[WdfUsbInterfaceGetInterfaceNumberTableIndex])(WdfDriverGlobals, UsbInterface);
}




typedef


BYTE
(*PFN_WDFUSBINTERFACEGETNUMENDPOINTS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE UsbInterface,
    
    UCHAR SettingIndex
    );


BYTE
__forceinline
WdfUsbInterfaceGetNumEndpoints(
    
    WDFUSBINTERFACE UsbInterface,
    
    UCHAR SettingIndex
    )
{
    return ((PFN_WDFUSBINTERFACEGETNUMENDPOINTS) WdfFunctions[WdfUsbInterfaceGetNumEndpointsTableIndex])(WdfDriverGlobals, UsbInterface, SettingIndex);
}




typedef


void
(*PFN_WDFUSBINTERFACEGETDESCRIPTOR)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE UsbInterface,
    
    UCHAR SettingIndex,
    
    PUSB_INTERFACE_DESCRIPTOR InterfaceDescriptor
    );


void
__forceinline
WdfUsbInterfaceGetDescriptor(
    
    WDFUSBINTERFACE UsbInterface,
    
    UCHAR SettingIndex,
    
    PUSB_INTERFACE_DESCRIPTOR InterfaceDescriptor
    )
{
    ((PFN_WDFUSBINTERFACEGETDESCRIPTOR) WdfFunctions[WdfUsbInterfaceGetDescriptorTableIndex])(WdfDriverGlobals, UsbInterface, SettingIndex, InterfaceDescriptor);
}




typedef


BYTE
(*PFN_WDFUSBINTERFACEGETNUMSETTINGS)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE UsbInterface
    );


BYTE
__forceinline
WdfUsbInterfaceGetNumSettings(
    
    WDFUSBINTERFACE UsbInterface
    )
{
    return ((PFN_WDFUSBINTERFACEGETNUMSETTINGS) WdfFunctions[WdfUsbInterfaceGetNumSettingsTableIndex])(WdfDriverGlobals, UsbInterface);
}




typedef



NTSTATUS
(*PFN_WDFUSBINTERFACESELECTSETTING)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE UsbInterface,
    
    PWDF_OBJECT_ATTRIBUTES PipesAttributes,
    
    PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS Params
    );



NTSTATUS
__forceinline
WdfUsbInterfaceSelectSetting(
    
    WDFUSBINTERFACE UsbInterface,
    
    PWDF_OBJECT_ATTRIBUTES PipesAttributes,
    
    PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS Params
    )
{
    return ((PFN_WDFUSBINTERFACESELECTSETTING) WdfFunctions[WdfUsbInterfaceSelectSettingTableIndex])(WdfDriverGlobals, UsbInterface, PipesAttributes, Params);
}




typedef


void
(*PFN_WDFUSBINTERFACEGETENDPOINTINFORMATION)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE UsbInterface,
    
    UCHAR SettingIndex,
    
    UCHAR EndpointIndex,
    
    PWDF_USB_PIPE_INFORMATION EndpointInfo
    );


void
__forceinline
WdfUsbInterfaceGetEndpointInformation(
    
    WDFUSBINTERFACE UsbInterface,
    
    UCHAR SettingIndex,
    
    UCHAR EndpointIndex,
    
    PWDF_USB_PIPE_INFORMATION EndpointInfo
    )
{
    ((PFN_WDFUSBINTERFACEGETENDPOINTINFORMATION) WdfFunctions[WdfUsbInterfaceGetEndpointInformationTableIndex])(WdfDriverGlobals, UsbInterface, SettingIndex, EndpointIndex, EndpointInfo);
}




typedef


WDFUSBINTERFACE
(*PFN_WDFUSBTARGETDEVICEGETINTERFACE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBDEVICE UsbDevice,
    
    UCHAR InterfaceIndex
    );


WDFUSBINTERFACE
__forceinline
WdfUsbTargetDeviceGetInterface(
    
    WDFUSBDEVICE UsbDevice,
    
    UCHAR InterfaceIndex
    )
{
    return ((PFN_WDFUSBTARGETDEVICEGETINTERFACE) WdfFunctions[WdfUsbTargetDeviceGetInterfaceTableIndex])(WdfDriverGlobals, UsbDevice, InterfaceIndex);
}




typedef


BYTE
(*PFN_WDFUSBINTERFACEGETCONFIGUREDSETTINGINDEX)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE Interface
    );


BYTE
__forceinline
WdfUsbInterfaceGetConfiguredSettingIndex(
    
    WDFUSBINTERFACE Interface
    )
{
    return ((PFN_WDFUSBINTERFACEGETCONFIGUREDSETTINGINDEX) WdfFunctions[WdfUsbInterfaceGetConfiguredSettingIndexTableIndex])(WdfDriverGlobals, Interface);
}




typedef


BYTE
(*PFN_WDFUSBINTERFACEGETNUMCONFIGUREDPIPES)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE UsbInterface
    );


BYTE
__forceinline
WdfUsbInterfaceGetNumConfiguredPipes(
    
    WDFUSBINTERFACE UsbInterface
    )
{
    return ((PFN_WDFUSBINTERFACEGETNUMCONFIGUREDPIPES) WdfFunctions[WdfUsbInterfaceGetNumConfiguredPipesTableIndex])(WdfDriverGlobals, UsbInterface);
}




typedef


WDFUSBPIPE
(*PFN_WDFUSBINTERFACEGETCONFIGUREDPIPE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBINTERFACE UsbInterface,
    
    UCHAR PipeIndex,
    
    PWDF_USB_PIPE_INFORMATION PipeInfo
    );


WDFUSBPIPE
__forceinline
WdfUsbInterfaceGetConfiguredPipe(
    
    WDFUSBINTERFACE UsbInterface,
    
    UCHAR PipeIndex,
    
    PWDF_USB_PIPE_INFORMATION PipeInfo
    )
{
    return ((PFN_WDFUSBINTERFACEGETCONFIGUREDPIPE) WdfFunctions[WdfUsbInterfaceGetConfiguredPipeTableIndex])(WdfDriverGlobals, UsbInterface, PipeIndex, PipeInfo);
}




typedef


USBD_PIPE_HANDLE
(*PFN_WDFUSBTARGETPIPEWDMGETPIPEHANDLE)(
    
    PWDF_DRIVER_GLOBALS DriverGlobals,
    
    WDFUSBPIPE UsbPipe
    );


USBD_PIPE_HANDLE
__forceinline
WdfUsbTargetPipeWdmGetPipeHandle(
    
    WDFUSBPIPE UsbPipe
    )
{
    return ((PFN_WDFUSBTARGETPIPEWDMGETPIPEHANDLE) WdfFunctions[WdfUsbTargetPipeWdmGetPipeHandleTableIndex])(WdfDriverGlobals, UsbPipe);
}



#line 2366 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"


#line 2369 "c:\\Users\\win2000\\Downloads\\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\7600.16385.1\\inc\\wdf\\kmdf\\1.9\\wdfusb.h"


#line 10 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\Usb.h"


typedef struct _MTP_USB_CONFIG {
    ULONG ReadBufferSize;      
    ULONG NumReaders;          
    ULONG TransferTimeoutMs;   
    ULONG RetryCount;          
} MTP_USB_CONFIG, *PMTP_USB_CONFIG;



typedef struct _DEVICE_CONTEXT {
    WDFUSBDEVICE UsbDevice;
    WDFUSBINTERFACE UsbInterface;
    WDFUSBPIPE BulkInPipe;
    WDFUSBPIPE BulkOutPipe;
    ULONG MaxPacketSize;
    MTP_USB_CONFIG UsbConfig;
    
    ULONG SessionId;
    
    BOOLEAN UsbPresent;
} DEVICE_CONTEXT, *PDEVICE_CONTEXT;
#line 34 "c:\\users\\win2000\\downloads\\winddk-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\\3790.1830\\src\\mtp_kmdf_w2k\\Usb.h"

typedef DEVICE_CONTEXT* WDF_POINTER_TYPE_DEVICE_CONTEXT;  __declspec(allocate( ".data" )) __declspec(selectany) extern const WDF_OBJECT_CONTEXT_TYPE_INFO _WDF_DEVICE_CONTEXT_TYPE_INFO = { sizeof(WDF_OBJECT_CONTEXT_TYPE_INFO), "DEVICE_CONTEXT", sizeof(DEVICE_CONTEXT), (&_WDF_DEVICE_CONTEXT_TYPE_INFO), ((void *)0), };   WDF_POINTER_TYPE_DEVICE_CONTEXT __forceinline DeviceGetContext(  WDFOBJECT Handle ) { return (WDF_POINTER_TYPE_DEVICE_CONTEXT) WdfObjectGetTypedContextWorker( Handle, (&_WDF_DEVICE_CONTEXT_TYPE_INFO)->UniqueType ); }


NTSTATUS MtpUsb_Create( WDFDEVICE Device,   PMTP_USB_CONFIG Config);
NTSTATUS MtpUsb_StartReaders( WDFDEVICE Device);
NTSTATUS MtpUsb_StopReaders( WDFDEVICE Device);
NTSTATUS MtpUsb_WriteBulk( WDFDEVICE Device,  WDFUSBPIPE Pipe,  PVOID Buffer,  size_t Length);


void MtpEvtUsbReadComplete( WDFUSBPIPE Pipe,  WDFMEMORY Buffer,  size_t NumBytesTransferred,  WDFCONTEXT Context);


WDFUSBPIPE MtpUsb_GetBulkInPipe( WDFDEVICE Device);
WDFUSBPIPE MtpUsb_GetBulkOutPipe( WDFDEVICE Device);


void MtpUsb_OnDataReceived( WDFDEVICE Device,  PVOID Data,  size_t Length);

#line 9 "Usb.c"


NTSTATUS
MtpUsb_Create(WDFDEVICE Device, PMTP_USB_CONFIG Config)
{
    NTSTATUS status;
    WDFUSBDEVICE usbDevice;

    
    
    status = WdfUsbTargetDeviceCreate(Device, (((void *)0)), &usbDevice);
    if (!((NTSTATUS)(status) >= 0)) {
        DbgPrint ("MTP: WdfUsbTargetDeviceCreate failed 0x%08x\n", status);
        return status;
    }

    
    PDEVICE_CONTEXT ctx = DeviceGetContext(Device);
    ctx->UsbDevice = usbDevice;
    
    ctx->UsbPresent = 1;

    
    UCHAR numInterfaces = WdfUsbTargetDeviceGetNumInterfaces(usbDevice);
    if (numInterfaces == 0) {
        DbgPrint ("MTP: No USB interfaces found\n");
        return ((NTSTATUS)0xC0000182L);
    }

    WDFUSBINTERFACE usbInterface = WdfUsbTargetDeviceGetInterface(usbDevice, 0);
    if (usbInterface == ((void *)0)) {
        DbgPrint ("MTP: GetInterface failed\n");
        return ((NTSTATUS)0xC0000182L);
    }

    ctx->UsbInterface = usbInterface;

    
    if (Config) {
        ctx->UsbConfig = *Config;
    } else {
        ctx->UsbConfig.ReadBufferSize = 4096;
        ctx->UsbConfig.NumReaders = 2;
        ctx->UsbConfig.TransferTimeoutMs = 5000;
        ctx->UsbConfig.RetryCount = 3;
    }

    
    UCHAR i;
    for (i = 0; i < WdfUsbInterfaceGetNumEndpoints(usbInterface, 0); i++) {
        WDF_USB_PIPE_INFORMATION pi;
        WDF_USB_PIPE_INFORMATION_INIT(&pi);
        WDFUSBPIPE pipe = WdfUsbInterfaceGetConfiguredPipe(usbInterface, i, &pi);
        WdfUsbTargetPipeGetInformation(pipe, &pi);

        if (pi.PipeType == WdfUsbPipeTypeBulk) {
            if (WdfUsbTargetPipeIsInEndpoint(pipe)) {
                
                ctx->BulkInPipe = pipe;
                ctx->MaxPacketSize = pi.MaximumPacketSize;

                
                WDF_USB_CONTINUOUS_READER_CONFIG contReaderConfig;
                WDF_USB_CONTINUOUS_READER_CONFIG_INIT(&contReaderConfig, MtpEvtUsbReadComplete, Device, ctx->UsbConfig.ReadBufferSize);
                contReaderConfig.NumPendingReads = (UCHAR)ctx->UsbConfig.NumReaders;

                status = WdfUsbTargetPipeConfigContinuousReader(ctx->BulkInPipe, &contReaderConfig);
                if (!((NTSTATUS)(status) >= 0)) {
                    DbgPrint ("MTP: Failed to configure continuous reader 0x%08x\n", status);
                }

            } else {
                ctx->BulkOutPipe = pipe;
            }
        }
    }

    DbgPrint ("MTP: USB device created and pipes located\n");
    return ((NTSTATUS)0x00000000L);
}



NTSTATUS
MtpUsb_WriteBulk(
    WDFDEVICE Device,
    WDFUSBPIPE Pipe,
    PVOID Buffer,
    size_t Length
    )
{
    if (!Buffer || Length == 0 || !Device || !Pipe) {
        return ((NTSTATUS)0xC000000DL);
    }

    PDEVICE_CONTEXT ctx = DeviceGetContext(Device);
    
    
    if (!ctx || !ctx->UsbPresent) {
        DbgPrint ("MTP: USB device not present, aborting write\n");
        return ((NTSTATUS)0xC0000184L);
    }

    WDF_MEMORY_DESCRIPTOR memDesc;
    WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&memDesc, Buffer, (ULONG)Length);

    ULONG retries = ctx->UsbConfig.RetryCount;
    NTSTATUS status = ((NTSTATUS)0xC0000001L);

    for (ULONG attempt = 0; attempt <= retries; ++attempt) {
        
        if (!ctx->UsbPresent) {
            return ((NTSTATUS)0xC0000184L);
        }

        WDFREQUEST request = ((void *)0);
        status = WdfRequestCreate((((void *)0)), WdfUsbTargetPipeGetIoTarget(Pipe), &request);
        if (!((NTSTATUS)(status) >= 0)) {
            if (attempt == retries) {
                DbgPrint ("MTP: WdfRequestCreate failed 0x%08x on final attempt\n", status);
                return status;
            }
            continue;
        }

        status = WdfUsbTargetPipeFormatRequestForWrite(Pipe, request, &memDesc, ((void *)0));
        if (!((NTSTATUS)(status) >= 0)) {
            WdfObjectDelete(request);
            if (attempt == retries) {
                DbgPrint ("MTP: WdfUsbTargetPipeFormatRequestForWrite failed 0x%08x\n", status);
                return status;
            }
            continue;
        }

        if (!WdfRequestSend(request, WdfUsbTargetPipeGetIoTarget(Pipe), ((void *)0))) {
            status = WdfRequestGetStatus(request);
            WdfObjectDelete(request);
            
            
            if (status == ((NTSTATUS)0xC0000120L) || status == ((NTSTATUS)0xC000009DL) ||
                status == ((NTSTATUS)0xC000000EL) || status == ((NTSTATUS)0xC0000185L)) {
                ctx->UsbPresent = 0;
                DbgPrint ("MTP: Device disconnected or I/O error 0x%08x\n", status);
                return ((NTSTATUS)0xC0000184L);
            }
            
            
            if (status == ((NTSTATUS)0xC00000B5L)) {
                DbgPrint ("MTP: I/O timeout (possible disconnection): 0x%08x\n", status);
                
                return status;
            }
            
            if (attempt == retries) {
                DbgPrint ("MTP: WdfRequestSend failed 0x%08x on final attempt\n", status);
                return status;
            }
            continue;
        }

        WdfObjectDelete(request);

        if (((NTSTATUS)(status) >= 0)) {
            return status;  
        }
        
        
    }

    DbgPrint ("MTP: WriteBulk exhausted all retries, last status 0x%08x\n", status);
    return status;
}



void
MtpEvtUsbReadComplete(
    WDFUSBPIPE  Pipe,
    WDFMEMORY   Buffer,
    size_t      NumBytesTransferred,
    WDFCONTEXT  Context
    )
{
    (Pipe);
    WDFDEVICE device = (WDFDEVICE)Context;

    if (NumBytesTransferred == 0) return;

    PVOID data = WdfMemoryGetBuffer(Buffer, ((void *)0));

    
    MtpUsb_OnDataReceived(device, data, NumBytesTransferred);

}


NTSTATUS
MtpUsb_StartReaders(WDFDEVICE Device)
{
    PDEVICE_CONTEXT ctx = DeviceGetContext(Device);
    if (!ctx || !ctx->BulkInPipe) return ((NTSTATUS)0xC0000184L);
    return WdfIoTargetStart(WdfUsbTargetPipeGetIoTarget(ctx->BulkInPipe));
}

NTSTATUS
MtpUsb_StopReaders(WDFDEVICE Device)
{
    PDEVICE_CONTEXT ctx = DeviceGetContext(Device);
    if (!ctx || !ctx->BulkInPipe) return ((NTSTATUS)0xC0000184L);
    WdfIoTargetStop(WdfUsbTargetPipeGetIoTarget(ctx->BulkInPipe), 0);
    return ((NTSTATUS)0x00000000L);
}

WDFUSBPIPE MtpUsb_GetBulkInPipe(WDFDEVICE Device) { return DeviceGetContext(Device)->BulkInPipe; }
WDFUSBPIPE MtpUsb_GetBulkOutPipe(WDFDEVICE Device) { return DeviceGetContext(Device)->BulkOutPipe; }
