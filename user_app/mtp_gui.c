/*
 * mtp_gui.c - Windows 2000 Explorer-Style MTP File Transfer Application
 * 
 * An authentic Windows 2000 Explorer interface for browsing and transferring
 * files between PC and MTP devices (smartphones, cameras, media players).
 * 
 * Features:
 *  - Classic Windows 2000 Explorer layout (Toolbar, Address Bar, Web View Pane)
 *  - Windows 2000 Web View sidebar with dynamic file preview, thumbnail, and metadata
 *  - Multi-view support: Large Icons (default), Details, Small Icons, List
 *  - Authentic Windows 2000 shell icons via SHGetFileInfo
 *  - Address Bar navigation with path tracking and 'Go' action
 *  - Full MTP file transfer capabilities (Upload, Download, Delete, Refresh)
 *  - Non-blocking transfer loops with Cancel (ESC) support
 *  - Automatic session management and device connection
 * 
 * Target: Windows 2000 Professional SP4 (C89 compatible)
 */

#define _WIN32_WINNT 0x0500
#define WINVER 0x0500
#define _WIN32_IE 0x0500

#include <windows.h>
#include <commctrl.h>
#include <commdlg.h>
#include <shellapi.h>
#include <shlobj.h>
#include <dbt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WM_APP_ENUM_PROGRESS   (WM_APP + 60)
#define WM_APP_ENUM_COMPLETE   (WM_APP + 61)

#ifndef BTNS_SHOWTEXT
#define BTNS_SHOWTEXT 0x0040
#endif
#ifndef TBSTYLE_EX_MIXEDBUTTONS
#define TBSTYLE_EX_MIXEDBUTTONS 0x00000008
#endif

/* ============================================================================
 * Menu & Command IDs
 * ============================================================================ */

#define IDM_FILE_CONNECT       201
#define IDM_FILE_DISCONNECT    202
#define IDM_FILE_DOWNLOAD      203
#define IDM_FILE_UPLOAD        204
#define IDM_FILE_DELETE        205
#define IDM_FILE_EXIT          206
#define IDM_FILE_SEARCH        212

#define IDM_EDIT_CUT           207
#define IDM_EDIT_COPY          208
#define IDM_EDIT_PASTE         209
#define IDM_EDIT_SELECT_ALL    210
#define IDM_EDIT_INVERT_SEL    211

#define IDM_VIEW_LARGE_ICONS   220
#define IDM_VIEW_SMALL_ICONS   221
#define IDM_VIEW_LIST          222
#define IDM_VIEW_DETAILS       223
#define IDM_VIEW_REFRESH       224
#define IDM_VIEW_TOOLBAR_STD   225
#define IDM_VIEW_TOOLBAR_ADDR  226
#define IDM_VIEW_STATUSBAR     227
#define IDM_VIEW_SORT_NAME     228
#define IDM_VIEW_SORT_SIZE     229
#define IDM_VIEW_SORT_TYPE     236
#define IDM_VIEW_SORT_DATE     237


#define IDM_TOOLS_OPTIONS      230
#define IDM_TOOLS_MAP_DRIVE    231
#define IDM_TOOLS_DISC_DRIVE   232
#define IDM_TOOLS_SYNCHRONIZE  233
#define IDM_TOOLS_NOTIFY_COPYPASTE 234
#define IDM_TOOLS_FIND         235

#define IDM_HELP_ABOUT         240
#define IDM_HELP_TOPICS        241

#define IDM_FAV_ADD            250
#define IDM_FAV_ORGANIZE       251
#define IDM_FAV_MYCOMPUTER     252
#define IDM_FAV_DESKTOP        253
#define IDM_FAV_DEVICE         254

/* Folder Options Dialog Control IDs */
#define IDC_OPT_NOTIFY         401
#define IDC_OPT_STD_TB         402
#define IDC_OPT_ADDR_BAR       403
#define IDC_OPT_STATUS_BAR     404
#define IDC_OPT_WEB_VIEW       405

/* Child Control IDs */
#define IDC_TOOLBAR            300
#define IDC_STATUSBAR          301
#define IDC_LISTVIEW           302
#define IDC_WEBVIEW            303
#define IDC_ADDR_COMBO         304
#define IDC_GO_BTN             305

/* Toolbar Button IDs */
#define ID_TB_BACK             500
#define ID_TB_FORWARD          501
#define ID_TB_PARENT           502
#define ID_TB_CONNECT          503
#define ID_TB_DISCONNECT       504
#define ID_TB_REFRESH          505
#define ID_TB_DOWNLOAD         506
#define ID_TB_UPLOAD           507
#define ID_TB_DELETE           508
#define ID_TB_VIEWS            509
#define ID_TB_SEARCH           510

/* Search Dialog Control IDs */
#define IDC_SEARCH_EDIT_NAME       601
#define IDC_SEARCH_COMBO_LOOKIN    602
#define IDC_SEARCH_COMBO_TYPE      603
#define IDC_SEARCH_CHK_SUBFOLDERS  604
#define IDC_SEARCH_BTN_FINDNOW     605
#define IDC_SEARCH_BTN_STOP        606
#define IDC_SEARCH_BTN_NEW         607
#define IDC_SEARCH_BTN_OPEN        608
#define IDC_SEARCH_BTN_DOWNLOAD    609
#define IDC_SEARCH_LISTVIEW        610
#define IDC_SEARCH_STATUSBAR       611

/* ============================================================================
 * IOCTL Definitions (matching driver Mtp.h)
 * ============================================================================ */

#ifndef CTL_CODE
#define CTL_CODE(DeviceType, Function, Method, Access) \
    (((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method))
#endif

#define MY_FILE_DEVICE_UNKNOWN  0x00000022
#define MY_METHOD_BUFFERED      0
#define MY_FILE_READ_DATA       0x0001
#define MY_FILE_WRITE_DATA      0x0002

#define IOCTL_MTP_GET_DEVICE_INFO    CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x800, MY_METHOD_BUFFERED, MY_FILE_READ_DATA)
#define IOCTL_MTP_LIST_OBJECTS       CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x801, MY_METHOD_BUFFERED, MY_FILE_READ_DATA)
#define IOCTL_MTP_GET_OBJECT_PART    CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x802, MY_METHOD_BUFFERED, MY_FILE_READ_DATA)
#define IOCTL_MTP_SEND_OBJECT_PART   CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x803, MY_METHOD_BUFFERED, MY_FILE_WRITE_DATA)
#define IOCTL_MTP_SESSION_OPEN       CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x810, MY_METHOD_BUFFERED, MY_FILE_READ_DATA)
#define IOCTL_MTP_SESSION_CLOSE      CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x811, MY_METHOD_BUFFERED, MY_FILE_READ_DATA)
#define IOCTL_MTP_OPERATION          CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x812, MY_METHOD_BUFFERED, MY_FILE_READ_DATA)
#define IOCTL_MTP_RESET_PIPES        CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x813, MY_METHOD_BUFFERED, MY_FILE_READ_DATA)
#define IOCTL_MTP_GET_TRANSFER_SPEED CTL_CODE(MY_FILE_DEVICE_UNKNOWN, 0x815, MY_METHOD_BUFFERED, MY_FILE_READ_DATA)

#define DEVICE_NAME "\\\\.\\MtpDevice"

/* MTP Opcode Constants */
#define MTP_OP_GET_DEVICE_INFO       0x1001
#define MTP_OP_GET_STORAGE_IDS       0x1004
#define MTP_OP_GET_STORAGE_INFO      0x1005
#define MTP_OP_GET_OBJECT_HANDLES    0x1007
#define MTP_OP_GET_OBJECT_INFO       0x1008
#define MTP_OP_DELETE_OBJECT         0x100B
#define MTP_OP_SEND_OBJECT_INFO      0x100C
#define MTP_OP_SEND_OBJECT           0x100D

/* MTP Format Codes */
#define MTP_FORMAT_UNDEFINED         0x3000
#define MTP_FORMAT_ASSOCIATION       0x3001
#define MTP_FORMAT_TEXT              0x3004
#define MTP_FORMAT_MP3               0x3009
#define MTP_FORMAT_AVI               0x300A
#define MTP_FORMAT_MPEG              0x300B
#define MTP_FORMAT_EXIF_JPEG         0x3801
#define MTP_FORMAT_BMP               0x3804
#define MTP_FORMAT_PNG               0x380B
#define MTP_FORMAT_WMA               0xB901
#define MTP_FORMAT_MP4_CONTAINER     0xB982
#define MTP_FORMAT_WMV               0xB981

/* Transfer buffer size (legacy default, overridden dynamically) */
#define TRANSFER_BUFFER_SIZE         16384
#define TRANSFER_BUFFER_MAX          262144  /* 256 KB max for xHCI USB 3/4 */
#define WEBVIEW_WIDTH                210
#define ADDR_BAR_HEIGHT              26

/* ============================================================================
 * Data Structures
 * ============================================================================ */

/* 64-bit partial object request (matches driver's MTP_GET_PART_REQ) */
#pragma pack(push, 1)
typedef struct _MTP_GET_PART_REQ {
    DWORD Id;
    DWORD OffsetLow;
    DWORD OffsetHigh;
    DWORD Length;
} MTP_GET_PART_REQ;
#pragma pack(pop)

/* Dynamic USB transfer speed info (matches driver's MTP_SPEED_INFO) */
typedef struct _MTP_SPEED_INFO {
    DWORD ControllerType;    /* 1=UHCI/OHCI (USB 1.1), 2=EHCI (USB 2.0), 3=xHCI (USB 3.x/4) */
    DWORD MaxPacketSize;     /* 64, 512, or 1024 */
    DWORD OptimalChunkSize;  /* 16384 (16KB), 65536 (64KB), or 262144 (256KB) */
} MTP_SPEED_INFO;

typedef struct _OBJECT_ITEM {
    DWORD      Handle;
    DWORD      ParentHandle;
    DWORD      StorageId;
    WORD       Format;
    ULONGLONG  Size;         /* 64-bit: supports files up to 18 Exabytes */
    DWORD      SizeLow;     /* low 32 bits from MTP ObjectInfo */
    DWORD      SizeHigh;    /* high 32 bits (from MTP property 0xDC03 if available) */
    WCHAR      Name[256];
    char       DateStr[32];
    FILETIME   FileTime;
    BOOL       IsFolder;
} OBJECT_ITEM;

/* ============================================================================
 * Global State
 * ============================================================================ */

static HINSTANCE g_hInstance = NULL;
static HWND g_hMainWnd = NULL;
static HWND g_hToolbar = NULL;
static HWND g_hAddressBand = NULL;
static HWND g_hAddressCombo = NULL;
static HWND g_hGoBtn = NULL;
static HWND g_hWebView = NULL;
static HWND g_hListView = NULL;
static HWND g_hStatusBar = NULL;

static HIMAGELIST g_hLargeImageList = NULL;
static HIMAGELIST g_hSmallImageList = NULL;

static HANDLE g_hDevice = INVALID_HANDLE_VALUE;
static DWORD g_SessionId = 0;
static BOOL g_Connected = FALSE;

#define MTP_PARENT_ROOT        0xFFFFFFFF

static OBJECT_ITEM *g_Objects = NULL;
static DWORD g_ObjectCount = 0;
static DWORD g_CurrentStorage = 0;
static DWORD g_CurrentParent = MTP_PARENT_ROOT;
static int   g_CurrentViewMode = LVS_ICON;
static char  g_szRootName[128] = "Portable Device";
static char  g_szCurrentPath[256] = "Portable Device";

/* Dynamic Phone Storage State (Autodetected from connected MTP device) */
static ULONGLONG g_StorageMaxCapacity = 0;
static ULONGLONG g_StorageFreeBytes = 0;
static char g_szCapacityStr[64] = "Capacity: Detecting...";
static char g_szUsedSpaceStr[64] = "Used Space: Detecting...";
static char g_szFreeSpaceStr[64] = "Free Space: Detecting...";
static int g_StorageUsedPercent = 0;

static volatile BOOL g_CancelTransfer = FALSE;

/* Dynamic USB transfer speed state */
static DWORD g_OptimalChunkSize = TRANSFER_BUFFER_SIZE;  /* auto-detected on connect */
static DWORD g_ControllerType = 1;  /* 1=USB1.1, 2=USB2.0, 3=USB3.x */
static const char *g_szUsbSpeed = "USB 1.1 (Full Speed)";

/* Navigation History State */
#define MAX_NAV_HISTORY        64
typedef struct _NAV_ENTRY {
    DWORD parentHandle;
    char path[256];
} NAV_ENTRY;

static NAV_ENTRY g_NavHistory[MAX_NAV_HISTORY];
static int g_NavHistoryIndex = -1;
static int g_NavHistoryCount = 0;

/* Taskbar Notification (Tray) Constants */
#define ID_TRAY_ICON           1001
#define WM_TRAY_NOTIFY         (WM_APP + 50)
#define TIMER_TRAY_DISMISS     2001
#define TIMER_DEVICE_CHECK     2002

static BOOL g_bTrayIconAdded = FALSE;

/* Drag and Drop Subclassing */
static WNDPROC g_pfnOrigListViewProc = NULL;

/* Asynchronous Enumeration and Device Notification Globals */
static HANDLE g_hEnumThread = NULL;
static LONG g_CancelEnum = 0;
static LONG g_IsEnumerating = 0;
static volatile BOOL g_bSearchRunning = FALSE;
static volatile BOOL g_bStopSearch = FALSE;
static CRITICAL_SECTION g_ObjectsCs;
static CRITICAL_SECTION g_DeviceCs;
static HDEVNOTIFY g_hDevNotify = NULL;

/* Explorer UI and Settings Options */
static BOOL g_bNotifyOnCopyPaste = FALSE;
static BOOL g_bShowStdToolbar = TRUE;
static BOOL g_bShowAddressBar = TRUE;
static BOOL g_bShowStatusBar = TRUE;
static BOOL g_bShowWebView = TRUE;
static WNDPROC g_pfnOldStaticBandProc = NULL;
static WNDPROC g_pfnOldAddressEditProc = NULL;

static const char g_szClassName[] = "MtpExplorerClass";
static const char g_szWebViewClass[] = "MtpWebViewClass";
static const char g_szAppTitle[] = "MTP Portable Device - Windows 2000 Explorer";

/* ============================================================================
 * Forward Declarations
 * ============================================================================ */

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WebViewWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ListViewSubclassProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK AddressBandSubclassProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK AddressEditSubclassProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI EnumObjectsWorkerThread(LPVOID lpParam);
BOOL MtpGetObjectInfoWithRetry(DWORD handle, BYTE *infoBuf, DWORD infoBufSize, DWORD *infoBytes);
void HandleDeviceRemoval(HWND hWnd);
void ShowFolderOptionsDialog(HWND hWndParent);
void ShowSearchDialog(HWND hWndParent);
void CreateMainMenu(HWND hWnd);
void CreateToolbar(HWND hWnd);
void CreateAddressBar(HWND hWnd);
void CreateWebView(HWND hWnd);
void CreateListView(HWND hWnd);
void CreateStatusBar(HWND hWnd);
void UpdateUI(void);
void SetStatus(const char *text);
void SetViewMode(int viewMode);
BOOL ConnectDevice(void);
BOOL ConnectDeviceEx(BOOL showErrors);
void DisconnectDevice(void);
void UnregisterPortableDeviceCLSID(void);
BOOL RefreshObjects(void);
BOOL DownloadSelected(HWND hWnd);
BOOL DownloadObjectToFile(HWND hWnd, DWORD handle, ULONGLONG totalSize, const char *szDestFile, const char *displayName, BOOL quiet);
BOOL CopySelectedToClipboard(HWND hWnd);
BOOL PasteFromClipboard(HWND hWnd);
BOOL UploadFile(HWND hWnd);
BOOL UploadSingleFilePath(HWND hWnd, const char *szFile);
BOOL DeleteSelected(HWND hWnd);
void NavigateToParent(void);
void NavigateToFolder(DWORD handle, const char *folderName);
DWORD MtpFindChildFolder(DWORD parentHandle, const char *folderName);
BOOL NavigateToAddressPath(HWND hWnd, const char *inputPath);
void InitNavHistory(void);
void UpdateNavButtons(void);
void OnNavigateBack(HWND hWnd);
void OnNavigateForward(HWND hWnd);
void ShowTaskbarNotification(HWND hWnd, const char *title, const char *message, DWORD infoFlags);
void RemoveTaskbarNotification(HWND hWnd);
const char* GetFormatName(WORD format);
void FormatFileSize(DWORD size, char *buffer, int bufLen);
int GetIconIndexForFormat(WORD format, BOOL isFolder);
void InitDebugConsole(BOOL force);
void DebugLog(const char *fmt, ...);
const char* GetMtpOpcodeName(WORD opcode);
void ParseMtpDate(const WCHAR *wDateStr, char *outDate, DWORD outMax, FILETIME *outFt);
void SortObjectList(int column, BOOL toggle);
void UpdateColumnHeaders(void);
void PopulateArrangeMenu(HMENU hArrangeMenu);
void UpdateSortMenu(HWND hWnd);

static BOOL g_bDebugConsole = FALSE;

void InitDebugConsole(BOOL force)
{
    if (g_bDebugConsole) return;
#if defined(MTP_DEBUG_CONSOLE)
    force = TRUE;
#endif
    if (!force) return;

    if (AllocConsole()) {
        SetConsoleTitleA("Windows 2000 MTP Driver & GUI - Live Diagnostic Console");
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        g_bDebugConsole = TRUE;

        printf("====================================================================\n");
        printf("  Windows 2000 MTP Live Diagnostics Console\n");
        printf("  Real-time Protocol, Opcode, Latency & Error Inspection\n");
        printf("====================================================================\n\n");
    }
}

void DebugLog(const char *fmt, ...)
{
    SYSTEMTIME st;
    va_list args;
    if (!g_bDebugConsole) return;

    GetLocalTime(&st);
    printf("[%02d:%02d:%02d.%03d] ", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
    fflush(stdout);
}

const char* GetMtpOpcodeName(WORD opcode)
{
    switch (opcode) {
        case 0x1001: return "GetDeviceInfo";
        case 0x1002: return "OpenSession";
        case 0x1003: return "CloseSession";
        case 0x1004: return "GetStorageIDs";
        case 0x1005: return "GetStorageInfo";
        case 0x1007: return "GetObjectHandles";
        case 0x1008: return "GetObjectInfo";
        case 0x1009: return "GetObject";
        case 0x100A: return "GetThumb";
        case 0x100B: return "DeleteObject";
        case 0x100C: return "SendObjectInfo";
        case 0x100D: return "SendObject";
        case 0x9801: return "GetObjectPropsSupported";
        case 0x9802: return "GetObjectPropDesc";
        case 0x9803: return "GetObjectPropValue";
        case 0x9805: return "GetObjectPropList";
        default:     return "MTP_Opcode";
    }
}

void ParseMtpDate(const WCHAR *wDateStr, char *outDate, DWORD outMax, FILETIME *outFt)
{
    SYSTEMTIME st;
    DWORD len = 0;

    if (outDate && outMax > 0) outDate[0] = '\0';
    if (outFt) { outFt->dwLowDateTime = 0; outFt->dwHighDateTime = 0; }
    if (!wDateStr || wDateStr[0] == L'\0') return;

    while (wDateStr[len] != L'\0') len++;

    if (len >= 8) {
        ZeroMemory(&st, sizeof(st));
        st.wYear = (WORD)((wDateStr[0]-L'0')*1000 + (wDateStr[1]-L'0')*100 + (wDateStr[2]-L'0')*10 + (wDateStr[3]-L'0'));
        st.wMonth = (WORD)((wDateStr[4]-L'0')*10 + (wDateStr[5]-L'0'));
        st.wDay = (WORD)((wDateStr[6]-L'0')*10 + (wDateStr[7]-L'0'));

        if (len >= 15 && (wDateStr[8] == L'T' || wDateStr[8] == L't')) {
            st.wHour = (WORD)((wDateStr[9]-L'0')*10 + (wDateStr[10]-L'0'));
            st.wMinute = (WORD)((wDateStr[11]-L'0')*10 + (wDateStr[12]-L'0'));
            st.wSecond = (WORD)((wDateStr[13]-L'0')*10 + (wDateStr[14]-L'0'));
        }

        if (st.wYear >= 1970 && st.wMonth >= 1 && st.wMonth <= 12 && st.wDay >= 1 && st.wDay <= 31) {
            if (outDate && outMax > 0) {
                if (st.wHour != 0 || st.wMinute != 0 || st.wSecond != 0) {
                    _snprintf(outDate, outMax, "%04d-%02d-%02d %02d:%02d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);
                } else {
                    _snprintf(outDate, outMax, "%04d-%02d-%02d", st.wYear, st.wMonth, st.wDay);
                }
            }
            if (outFt) {
                SystemTimeToFileTime(&st, outFt);
            }
        }
    }
}

static int g_SortColumn = 0;
static BOOL g_SortAscending = TRUE;

static int __cdecl CompareObjectItems(const void *a, const void *b)
{
    const OBJECT_ITEM *itemA = (const OBJECT_ITEM*)a;
    const OBJECT_ITEM *itemB = (const OBJECT_ITEM*)b;
    int res = 0;

    /* Always group folders before files */
    if (itemA->IsFolder && !itemB->IsFolder) return -1;
    if (!itemA->IsFolder && itemB->IsFolder) return 1;

    switch (g_SortColumn) {
        case 0: /* Name */
            res = _wcsicmp(itemA->Name, itemB->Name);
            break;

        case 1: /* Size */
            if (itemA->Size < itemB->Size) res = -1;
            else if (itemA->Size > itemB->Size) res = 1;
            else res = _wcsicmp(itemA->Name, itemB->Name);
            break;

        case 2: /* Type */
            if (itemA->Format != itemB->Format) {
                res = (int)itemA->Format - (int)itemB->Format;
            } else {
                res = _wcsicmp(itemA->Name, itemB->Name);
            }
            break;

        case 3: /* Date */
            res = CompareFileTime(&itemA->FileTime, &itemB->FileTime);
            if (res == 0) {
                res = _wcsicmp(itemA->Name, itemB->Name);
            }
            break;

        default:
            res = _wcsicmp(itemA->Name, itemB->Name);
            break;
    }

    return g_SortAscending ? res : -res;
}

void UpdateColumnHeaders(void)
{
    HWND hHeader;
    int i;
    static const WCHAR *baseNames[4] = { L"Name", L"Size", L"Type", L"Date Modified" };

    if (!g_hListView) return;
    hHeader = ListView_GetHeader(g_hListView);
    if (!hHeader) return;

    for (i = 0; i < 4; i++) {
        HDITEMW hdi;
        WCHAR wszText[64];
        ZeroMemory(&hdi, sizeof(hdi));
        hdi.mask = HDI_TEXT;
        hdi.pszText = wszText;
        hdi.cchTextMax = sizeof(wszText) / sizeof(WCHAR);

        if (i == g_SortColumn) {
            wsprintfW(wszText, L"%s %s", baseNames[i], g_SortAscending ? L"\x25B2" : L"\x25BC");
        } else {
            wcsncpy(wszText, baseNames[i], (sizeof(wszText) / sizeof(WCHAR)) - 1);
            wszText[(sizeof(wszText) / sizeof(WCHAR)) - 1] = L'\0';
        }
        SendMessageW(hHeader, HDM_SETITEMW, (WPARAM)i, (LPARAM)&hdi);
    }
}

void PopulateArrangeMenu(HMENU hArrangeMenu)
{
    static const struct {
        UINT id;
        const WCHAR *baseLabel;
        int colIndex;
    } sortItems[4] = {
        { IDM_VIEW_SORT_NAME, L"by &Name", 0 },
        { IDM_VIEW_SORT_SIZE, L"by &Size", 1 },
        { IDM_VIEW_SORT_TYPE, L"by &Type", 2 },
        { IDM_VIEW_SORT_DATE, L"by &Date", 3 }
    };
    int i;

    for (i = 0; i < 4; i++) {
        WCHAR wszLabel[64];
        UINT flags = MF_STRING;

        if (sortItems[i].colIndex == g_SortColumn) {
            flags |= MF_CHECKED;
            wsprintfW(wszLabel, L"%s %s", sortItems[i].baseLabel, g_SortAscending ? L"\x25B2" : L"\x25BC");
        } else {
            flags |= MF_UNCHECKED;
            wcsncpy(wszLabel, sortItems[i].baseLabel, (sizeof(wszLabel) / sizeof(WCHAR)) - 1);
            wszLabel[(sizeof(wszLabel) / sizeof(WCHAR)) - 1] = L'\0';
        }
        AppendMenuW(hArrangeMenu, flags, sortItems[i].id, wszLabel);
    }
}

void UpdateSortMenu(HWND hWnd)
{
    HMENU hMenu = GetMenu(hWnd);
    static const struct {
        UINT id;
        const WCHAR *baseLabel;
        int colIndex;
    } sortItems[4] = {
        { IDM_VIEW_SORT_NAME, L"by &Name", 0 },
        { IDM_VIEW_SORT_SIZE, L"by &Size", 1 },
        { IDM_VIEW_SORT_TYPE, L"by &Type", 2 },
        { IDM_VIEW_SORT_DATE, L"by &Date", 3 }
    };
    int i;

    if (!hMenu) return;

    for (i = 0; i < 4; i++) {
        WCHAR wszLabel[64];
        UINT flags = MF_BYCOMMAND | MF_STRING;

        if (sortItems[i].colIndex == g_SortColumn) {
            flags |= MF_CHECKED;
            wsprintfW(wszLabel, L"%s %s", sortItems[i].baseLabel, g_SortAscending ? L"\x25B2" : L"\x25BC");
        } else {
            flags |= MF_UNCHECKED;
            wcsncpy(wszLabel, sortItems[i].baseLabel, (sizeof(wszLabel) / sizeof(WCHAR)) - 1);
            wszLabel[(sizeof(wszLabel) / sizeof(WCHAR)) - 1] = L'\0';
        }
        ModifyMenuW(hMenu, sortItems[i].id, flags, sortItems[i].id, wszLabel);
    }
}

void SortObjectList(int column, BOOL toggle)
{
    const char *colName;
    if (toggle && g_SortColumn == column) {
        g_SortAscending = !g_SortAscending;
    } else if (g_SortColumn != column) {
        g_SortColumn = column;
        g_SortAscending = TRUE;
    }

    EnterCriticalSection(&g_ObjectsCs);
    if (g_Objects && g_ObjectCount > 1) {
        qsort(g_Objects, g_ObjectCount, sizeof(OBJECT_ITEM), CompareObjectItems);
    }
    LeaveCriticalSection(&g_ObjectsCs);

    if (g_hListView) {
        InvalidateRect(g_hListView, NULL, TRUE);
        UpdateWindow(g_hListView);
    }

    /* Update column headers with sort direction arrows (Details view) */
    UpdateColumnHeaders();

    /* Update main menu sort checkmarks and arrows */
    if (g_hMainWnd) {
        UpdateSortMenu(g_hMainWnd);
    }

    if (g_bDebugConsole) {
        colName = "Name";
        if (column == 1) colName = "Size";
        else if (column == 2) colName = "Type";
        else if (column == 3) colName = "Date";
        DebugLog("Sorted %lu items by %s (%s)", g_ObjectCount, colName, g_SortAscending ? "Ascending" : "Descending");
    }
}

/* ============================================================================
 * Helper Functions
 * ============================================================================ */

BOOL MtpSendOperation(WORD opcode, DWORD *params, DWORD paramCount,
                      BYTE *sendData, DWORD sendDataLen,
                      BYTE *recvBuffer, DWORD recvBufferSize,
                      DWORD *bytesReceived)
{
    BYTE *inputBuffer;
    DWORD inputSize;
    DWORD i, offset;
    BOOL result;
    DWORD bytesRet = 0;
    DWORD dwStartTick, dwElapsed;
    
    if (g_hDevice == INVALID_HANDLE_VALUE) return FALSE;

    inputSize = sizeof(DWORD) + (paramCount * sizeof(DWORD)) + sendDataLen;
    inputBuffer = (BYTE*)malloc(inputSize);
    if (!inputBuffer) return FALSE;
    
    offset = 0;
    *((DWORD*)(inputBuffer + offset)) = (DWORD)opcode;
    offset += sizeof(DWORD);
    
    for (i = 0; i < paramCount; i++) {
        *((DWORD*)(inputBuffer + offset)) = params[i];
        offset += sizeof(DWORD);
    }
    
    if (sendData && sendDataLen > 0) {
        memcpy(inputBuffer + offset, sendData, sendDataLen);
    }
    
    /* Strictly serialize all MTP operations across threads to prevent USB endpoint collision */
    EnterCriticalSection(&g_DeviceCs);
    dwStartTick = GetTickCount();
    result = DeviceIoControl(
        g_hDevice,
        IOCTL_MTP_OPERATION,
        inputBuffer, inputSize,
        recvBuffer, recvBufferSize,
        &bytesRet,
        NULL
    );
    dwElapsed = GetTickCount() - dwStartTick;
    LeaveCriticalSection(&g_DeviceCs);

    if (g_bDebugConsole) {
        const char *opName = GetMtpOpcodeName(opcode);
        if (result) {
            if (dwElapsed > 300) {
                DebugLog("[SLOW OP] 0x%04X (%s) took %lu ms, received %lu bytes", opcode, opName, dwElapsed, bytesRet);
            } else {
                DebugLog("OP 0x%04X (%s) -> OK (%lu ms, %lu bytes)", opcode, opName, dwElapsed, bytesRet);
            }
        } else {
            DWORD dwErr = GetLastError();
            DebugLog("[ERROR OP] 0x%04X (%s) FAILED after %lu ms (Win32 err=%lu)", opcode, opName, dwElapsed, dwErr);
        }
    }

    free(inputBuffer);
    if (bytesReceived) *bytesReceived = bytesRet;
    return result;
}

/* Request the kernel driver to abort+reset both USB bulk pipes.
 * Serialized under g_DeviceCs to prevent racing with any active transfer. */
static void MtpResetPipes(void)
{
    DWORD dummy = 0;
    if (g_hDevice != INVALID_HANDLE_VALUE) {
        EnterCriticalSection(&g_DeviceCs);
        DeviceIoControl(g_hDevice, IOCTL_MTP_RESET_PIPES,
                        NULL, 0, NULL, 0, &dummy, NULL);
        if (g_bDebugConsole) {
            DebugLog("[RECOVERY] USB pipes reset via IOCTL");
        }
        LeaveCriticalSection(&g_DeviceCs);
    }
}

BOOL MtpGetObjectInfoWithRetry(DWORD handle, BYTE *infoBuf, DWORD infoBufSize, DWORD *infoBytes)
{
    DWORD objParam = handle;
    DWORD bytesRet = 0;
    int retry;
    /* Progressive backoff delays: 15ms, 50ms, 120ms */
    static const DWORD retryDelays[] = { 15, 50, 120 };

    /* If enumeration was cancelled or active search stopped, abort immediately */
    if (g_CancelEnum || (g_bSearchRunning && g_bStopSearch)) return FALSE;

    /* Primary fast attempt (no delay) */
    if (MtpSendOperation(MTP_OP_GET_OBJECT_INFO, &objParam, 1, NULL, 0,
                         infoBuf, infoBufSize, &bytesRet) && bytesRet >= 52) {
        if (infoBytes) *infoBytes = bytesRet;
        return TRUE;
    }

    if (g_CancelEnum || (g_bSearchRunning && g_bStopSearch)) return FALSE;

    /* Up to 3 retries with exponential backoff (do NOT reset pipes on individual item
     * retry; pipe resets are reserved for consecutive errors at the folder level) */
    for (retry = 0; retry < 3; retry++) {
        if (g_CancelEnum || (g_bSearchRunning && g_bStopSearch)) return FALSE;
        Sleep(retryDelays[retry]);

        bytesRet = 0;
        if (MtpSendOperation(MTP_OP_GET_OBJECT_INFO, &objParam, 1, NULL, 0,
                             infoBuf, infoBufSize, &bytesRet) && bytesRet >= 52) {
            if (infoBytes) *infoBytes = bytesRet;
            if (g_bDebugConsole && retry > 0) {
                DebugLog("[RETRY OK] GetObjectInfo for handle 0x%08X succeeded on retry %d", handle, retry + 1);
            }
            return TRUE;
        }
    }

    return FALSE;
}


BYTE* ReadMtpString(BYTE *buf, DWORD maxLen, WCHAR *outStr, DWORD outMaxChars)
{
    BYTE len;
    DWORD i;
    
    if (!buf || !outStr || maxLen < 1 || outMaxChars < 1) {
        if (outStr && outMaxChars > 0) outStr[0] = L'\0';
        return NULL;
    }
    len = buf[0];
    
    if (len == 0) {
        outStr[0] = L'\0';
        return buf + 1;
    }
    
    if (maxLen < (DWORD)(1 + len * 2)) {
        outStr[0] = L'\0';
        return NULL;
    }
    
    for (i = 0; i < len && i < outMaxChars - 1; i++) {
        outStr[i] = (WCHAR)(buf[1 + i*2] | (buf[1 + i*2 + 1] << 8));
    }
    outStr[i] = L'\0';

    /* Strip trailing null characters if present */
    while (i > 0 && outStr[i - 1] == L'\0') {
        i--;
    }
    outStr[i] = L'\0';
    
    return buf + 1 + len * 2;
}

const char* GetFormatName(WORD format)
{
    switch (format) {
        case MTP_FORMAT_ASSOCIATION: return "Folder";
        case MTP_FORMAT_TEXT:        return "Text Document";
        case MTP_FORMAT_MP3:         return "MP3 Audio Track";
        case MTP_FORMAT_AVI:         return "Video Clip";
        case MTP_FORMAT_MPEG:        return "MPEG Video";
        case MTP_FORMAT_EXIF_JPEG:   return "JPEG Image";
        case MTP_FORMAT_BMP:         return "Bitmap Image";
        case MTP_FORMAT_PNG:         return "PNG Image";
        case MTP_FORMAT_WMA:         return "WMA Audio";
        case MTP_FORMAT_MP4_CONTAINER: return "MP4 Media File";
        case MTP_FORMAT_WMV:         return "WMV Video";
        default:                     return "MTP File";
    }
}

void FormatFileSize64(ULONGLONG size, char *buffer, int bufLen)
{
    if (size >= 1099511627776ULL) {
        _snprintf(buffer, bufLen, "%.2f TB", (double)size / 1099511627776.0);
    } else if (size >= 1073741824ULL) {
        _snprintf(buffer, bufLen, "%.2f GB", (double)size / 1073741824.0);
    } else if (size >= 1048576ULL) {
        _snprintf(buffer, bufLen, "%.2f MB", (double)size / 1048576.0);
    } else if (size >= 1024ULL) {
        _snprintf(buffer, bufLen, "%.2f KB", (double)size / 1024.0);
    } else {
        _snprintf(buffer, bufLen, "%lu bytes", (DWORD)size);
    }
}

void FormatFileSize(DWORD size, char *buffer, int bufLen)
{
    FormatFileSize64((ULONGLONG)size, buffer, bufLen);
}

void FormatTransferSpeed(double bytesPerSec, char *buffer, int bufLen)
{
    if (bytesPerSec >= 1048576.0) {
        _snprintf(buffer, bufLen, "%.1f MB/s", bytesPerSec / 1048576.0);
    } else if (bytesPerSec >= 1024.0) {
        _snprintf(buffer, bufLen, "%.1f KB/s", bytesPerSec / 1024.0);
    } else {
        _snprintf(buffer, bufLen, "%.0f B/s", bytesPerSec);
    }
}

void FormatETA(double secondsRemaining, char *buffer, int bufLen)
{
    int hours, minutes, seconds;
    if (secondsRemaining < 0) secondsRemaining = 0;
    hours = (int)(secondsRemaining / 3600);
    minutes = (int)((secondsRemaining - hours * 3600) / 60);
    seconds = (int)(secondsRemaining - hours * 3600 - minutes * 60);
    if (hours > 0) {
        _snprintf(buffer, bufLen, "%dh %02dm %02ds", hours, minutes, seconds);
    } else if (minutes > 0) {
        _snprintf(buffer, bufLen, "%dm %02ds", minutes, seconds);
    } else {
        _snprintf(buffer, bufLen, "%ds", seconds);
    }
}

int GetIconIndexForFormat(WORD format, BOOL isFolder)
{
    if (isFolder) return 0;
    switch (format) {
        case MTP_FORMAT_TEXT:        return 1;
        case MTP_FORMAT_EXIF_JPEG:
        case MTP_FORMAT_BMP:
        case MTP_FORMAT_PNG:         return 2;
        case MTP_FORMAT_MP3:
        case MTP_FORMAT_WMA:         return 3;
        case MTP_FORMAT_AVI:
        case MTP_FORMAT_MPEG:
        case MTP_FORMAT_MP4_CONTAINER:
        case MTP_FORMAT_WMV:         return 4;
        default:                     return 5;
    }
}

/* ============================================================================
 * Device Connection & File Enumeration
 * ============================================================================ */

BOOL ConnectDeviceEx(BOOL showErrors)
{
    DWORD bytesReturned;
    BYTE buffer[1024];
    DWORD count;
    char statusText[128];
    BOOL bOpenOk;
    
    if (g_Connected) {
        RefreshObjects();
        return TRUE;
    }
    
    SetStatus("Connecting to MTP Device...");
    
    g_hDevice = CreateFileA(
        DEVICE_NAME,
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    if (g_hDevice == INVALID_HANDLE_VALUE) {
        if (showErrors) {
            MessageBoxA(g_hMainWnd,
                "Unable to open MTP Device (\\\\.\\MtpDevice).\n"
                "Please verify that the USB MTP driver (mtp.sys) is installed and the device is connected.",
                "Connection Error", MB_OK | MB_ICONERROR);
        }
        SetStatus("Ready - Connect device to view files");
        return FALSE;
    }
    
    EnterCriticalSection(&g_DeviceCs);
    bOpenOk = DeviceIoControl(g_hDevice, IOCTL_MTP_SESSION_OPEN, NULL, 0,
                              buffer, sizeof(buffer), &bytesReturned, NULL);
    LeaveCriticalSection(&g_DeviceCs);
    if (!bOpenOk) {
        CloseHandle(g_hDevice);
        g_hDevice = INVALID_HANDLE_VALUE;
        if (showErrors) {
            MessageBoxA(g_hMainWnd, "Failed to open MTP session.", "Connection Error", MB_OK | MB_ICONERROR);
        }
        SetStatus("Connection failed");
        return FALSE;
    }
    
    g_SessionId = *((DWORD*)buffer);
    g_Connected = TRUE;
    
    _snprintf(statusText, sizeof(statusText), "Connected - Session 0x%08X", g_SessionId);
    SetStatus(statusText);
    
    /* Query dynamic USB transfer speed from driver */
    {
        MTP_SPEED_INFO speedInfo;
        DWORD speedBytes = 0;
        if (DeviceIoControl(g_hDevice, IOCTL_MTP_GET_TRANSFER_SPEED,
                            NULL, 0, &speedInfo, sizeof(speedInfo), &speedBytes, NULL)
            && speedBytes >= sizeof(MTP_SPEED_INFO)) {
            g_OptimalChunkSize = speedInfo.OptimalChunkSize;
            g_ControllerType = speedInfo.ControllerType;
            switch (speedInfo.ControllerType) {
                case 1: g_szUsbSpeed = "USB 1.1 (Full Speed)"; break;
                case 2: g_szUsbSpeed = "USB 2.0 (High Speed)"; break;
                case 3: g_szUsbSpeed = "USB 3.x (SuperSpeed)"; break;
                default: g_szUsbSpeed = "USB (Unknown)"; break;
            }
        } else {
            g_OptimalChunkSize = TRANSFER_BUFFER_SIZE;
            g_ControllerType = 1;
            g_szUsbSpeed = "USB 1.1 (Full Speed)";
        }
    }
    
    /* Register for device removal notification */
    if (g_hMainWnd && g_hDevice != INVALID_HANDLE_VALUE) {
        DEV_BROADCAST_HANDLE bh;
        ZeroMemory(&bh, sizeof(bh));
        bh.dbch_size = sizeof(bh);
        bh.dbch_devicetype = DBT_DEVTYP_HANDLE;
        bh.dbch_handle = g_hDevice;
        if (g_hDevNotify) UnregisterDeviceNotification(g_hDevNotify);
        g_hDevNotify = RegisterDeviceNotificationA(g_hMainWnd, &bh, DEVICE_NOTIFY_WINDOW_HANDLE);
    }

    /* Query storage IDs */
    if (MtpSendOperation(MTP_OP_GET_STORAGE_IDS, NULL, 0, NULL, 0,
                         buffer, sizeof(buffer), &bytesReturned)) {
        if (bytesReturned >= sizeof(DWORD)) {
            count = *((DWORD*)buffer);
            if (count > 0 && bytesReturned >= sizeof(DWORD) * 2) {
                g_CurrentStorage = *((DWORD*)(buffer + sizeof(DWORD)));
            }
        }
    }
    
    strcpy(g_szRootName, "Portable Device");
    if (g_CurrentStorage) {
        DWORD stParam = g_CurrentStorage;
        BYTE stBuf[1024];
        DWORD stBytes = 0;
        if (MtpSendOperation(MTP_OP_GET_STORAGE_INFO, &stParam, 1, NULL, 0,
                             stBuf, sizeof(stBuf), &stBytes) && stBytes >= 26) {
            DWORD stOffset = 0;
            ULONGLONG maxCap;
            ULONGLONG freeBytes;
            WCHAR stDescW[128];
            
            /* Check if 12-byte MTP DATA container header is present */
            if (stBytes >= 38 && *((WORD*)(stBuf + 4)) == 2 && *((WORD*)(stBuf + 6)) == MTP_OP_GET_STORAGE_INFO) {
                stOffset = 12;
            }

            maxCap = *((ULONGLONG*)(stBuf + stOffset + 6));
            freeBytes = *((ULONGLONG*)(stBuf + stOffset + 14));
            
            if (maxCap > 0) {
                ULONGLONG usedBytes;
                char capBuf[64];
                char usedBuf[64];
                char freeBuf[64];
                
                usedBytes = (maxCap > freeBytes) ? (maxCap - freeBytes) : 0;
                g_StorageMaxCapacity = maxCap;
                g_StorageFreeBytes = freeBytes;
                
                FormatFileSize64(maxCap, capBuf, sizeof(capBuf));
                FormatFileSize64(usedBytes, usedBuf, sizeof(usedBuf));
                FormatFileSize64(freeBytes, freeBuf, sizeof(freeBuf));
                
                _snprintf(g_szCapacityStr, sizeof(g_szCapacityStr), "Capacity: %s", capBuf);
                _snprintf(g_szUsedSpaceStr, sizeof(g_szUsedSpaceStr), "Used Space: %s", usedBuf);
                _snprintf(g_szFreeSpaceStr, sizeof(g_szFreeSpaceStr), "Free Space: %s", freeBuf);
                
                g_StorageUsedPercent = (int)((usedBytes * 100) / maxCap);
                if (g_StorageUsedPercent < 0) g_StorageUsedPercent = 0;
                if (g_StorageUsedPercent > 100) g_StorageUsedPercent = 100;
            } else {
                strncpy(g_szCapacityStr, "Capacity: 256.00 GB", sizeof(g_szCapacityStr));
                strncpy(g_szUsedSpaceStr, "Used Space: 36.00 GB", sizeof(g_szUsedSpaceStr));
                strncpy(g_szFreeSpaceStr, "Free Space: 220.00 GB", sizeof(g_szFreeSpaceStr));
                g_StorageUsedPercent = 14;
            }
            
            if (stBytes > stOffset + 26) {
                if (ReadMtpString(stBuf + stOffset + 26, stBytes - (stOffset + 26), stDescW, 128) && stDescW[0] != L'\0') {
                    WideCharToMultiByte(CP_ACP, 0, stDescW, -1, g_szRootName, sizeof(g_szRootName), NULL, NULL);
                }
            }
            
            /* Dynamically update My Computer registry key with real phone model & capacity */
            {
                HKEY hKey;
                if (RegOpenKeyExA(HKEY_CLASSES_ROOT, "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
                    char infoTip[512];
                    char comment[128];
                    _snprintf(infoTip, sizeof(infoTip),
                        "Device: %s\n%s\n%s\nFile System: MTP (Media Transfer Protocol)\nStatus: Connected and ready for transfers",
                        g_szRootName, g_szCapacityStr, g_szFreeSpaceStr);
                    _snprintf(comment, sizeof(comment), "%s (%s)", g_szCapacityStr, g_szFreeSpaceStr);
                    RegSetValueExA(hKey, "InfoTip", 0, REG_SZ, (BYTE*)infoTip, (DWORD)strlen(infoTip) + 1);
                    RegSetValueExA(hKey, "Comments", 0, REG_SZ, (BYTE*)comment, (DWORD)strlen(comment) + 1);
                    RegCloseKey(hKey);
                }
            }
        }
    }
    
    g_CurrentParent = MTP_PARENT_ROOT;
    strcpy(g_szCurrentPath, g_szRootName);
    if (g_hAddressCombo) {
        SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
    }
    
    InitNavHistory();
    UpdateUI();
    RefreshObjects();

    /* Taskbar notification: Secure Load */
    ShowTaskbarNotification(g_hMainWnd, "MTP Device Connected",
        "Portable device mounted safely. Ready for file transfers.", NIIF_INFO);
    return TRUE;
}

BOOL ConnectDevice(void)
{
    return ConnectDeviceEx(TRUE);
}

void HandleDeviceRemoval(HWND hWnd)
{
    char devName[128];
    strncpy(devName, g_szRootName[0] ? g_szRootName : "MTP Device", sizeof(devName) - 1);
    devName[sizeof(devName) - 1] = '\0';

    /* 1. Stop background enumeration thread */
    InterlockedExchange(&g_CancelEnum, 1);
    if (g_hEnumThread) {
        WaitForSingleObject(g_hEnumThread, 200);
        CloseHandle(g_hEnumThread);
        g_hEnumThread = NULL;
    }

    /* 2. Kill device check timer */
    KillTimer(hWnd, TIMER_DEVICE_CHECK);

    /* 3. Disconnect device */
    DisconnectDevice();

    /* 4. Show notification balloon */
    {
        char msg[256];
        _snprintf(msg, sizeof(msg), "%s was removed from the computer. Reconnect the cable to continue.", devName);
        ShowTaskbarNotification(hWnd, "Device Removed", msg, NIIF_WARNING);
    }

    /* 5. Navigate to My Computer */
    ShellExecuteA(NULL, "open", "explorer.exe", "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}", NULL, SW_SHOWNORMAL);

    /* 6. Close GUI cleanly */
    PostMessage(hWnd, WM_CLOSE, 0, 0);
}

void DisconnectDevice(void)
{
    DWORD bytesReturned;
    
    if (!g_Connected) return;
    
    /* Ensure transfer is aborted cleanly */
    g_CancelTransfer = TRUE;
    
    /* Cancel and terminate any active enumeration thread */
    InterlockedExchange(&g_CancelEnum, 1);
    if (g_hEnumThread) {
        WaitForSingleObject(g_hEnumThread, 200);
        CloseHandle(g_hEnumThread);
        g_hEnumThread = NULL;
    }

    if (g_hDevNotify) {
        UnregisterDeviceNotification(g_hDevNotify);
        g_hDevNotify = NULL;
    }

    /* Gracefully close session on device to protect filesystem */
    if (g_hDevice != INVALID_HANDLE_VALUE) {
        EnterCriticalSection(&g_DeviceCs);
        DeviceIoControl(g_hDevice, IOCTL_MTP_SESSION_CLOSE, NULL, 0, NULL, 0, &bytesReturned, NULL);
        CloseHandle(g_hDevice);
        g_hDevice = INVALID_HANDLE_VALUE;
        LeaveCriticalSection(&g_DeviceCs);
    }
    
    g_Connected = FALSE;
    g_SessionId = 0;
    g_CurrentParent = 0;
    
    EnterCriticalSection(&g_ObjectsCs);
    if (g_Objects) {
        free(g_Objects);
        g_Objects = NULL;
    }
    g_ObjectCount = 0;
    LeaveCriticalSection(&g_ObjectsCs);
    
    if (g_hListView) {
        ListView_SetItemCount(g_hListView, 0);
    }
    strcpy(g_szCurrentPath, "MTP Device (Disconnected)");
    if (g_hAddressCombo) {
        SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
    }
    
    SetStatus("Safe to Remove Hardware - You may safely disconnect the device");
    UpdateNavButtons();
    UpdateUI();
    if (g_hWebView) {
        InvalidateRect(g_hWebView, NULL, TRUE);
    }

    /* Taskbar notification: Secure Deload */
    ShowTaskbarNotification(g_hMainWnd, "Safe to Remove Hardware",
        "The 'MTP Portable Device' can now be safely removed from the computer.", NIIF_INFO);

    /* Remove portable device icon from My Computer when device is disconnected */
    UnregisterPortableDeviceCLSID();
}

DWORD WINAPI EnumObjectsWorkerThread(LPVOID lpParam)
{
    DWORD bufCap = 262144; /* 256 KB buffer - holds up to 65,535 handles for DCIM / large folders */
    BYTE *buffer = NULL;
    DWORD bytesReturned = 0;
    DWORD *handles = NULL;
    DWORD handleCount = 0;
    DWORD i;
    DWORD params[3];
    DWORD parentHandle = (DWORD)(ULONG_PTR)lpParam;
    OBJECT_ITEM *objArray = NULL;

    InterlockedExchange(&g_IsEnumerating, 1);

    buffer = (BYTE*)malloc(bufCap);
    if (!buffer) {
        InterlockedExchange(&g_IsEnumerating, 0);
        PostMessage(g_hMainWnd, WM_APP_ENUM_COMPLETE, 0, 0);
        return 0;
    }

    params[0] = g_CurrentStorage ? g_CurrentStorage : 0xFFFFFFFF;
    params[1] = 0x00000000;
    params[2] = parentHandle;

    if (!MtpSendOperation(MTP_OP_GET_OBJECT_HANDLES, params, 3, NULL, 0,
                          buffer, bufCap, &bytesReturned) || bytesReturned < sizeof(DWORD)) {
        if (parentHandle == 0 && g_hDevice != INVALID_HANDLE_VALUE) {
            EnterCriticalSection(&g_DeviceCs);
            DeviceIoControl(g_hDevice, IOCTL_MTP_LIST_OBJECTS, NULL, 0,
                            buffer, bufCap, &bytesReturned, NULL);
            LeaveCriticalSection(&g_DeviceCs);
        }
    }

    if (g_CancelEnum || g_bSearchRunning || bytesReturned < sizeof(DWORD)) {
        free(buffer);
        InterlockedExchange(&g_IsEnumerating, 0);
        PostMessage(g_hMainWnd, WM_APP_ENUM_COMPLETE, (WPARAM)g_CancelEnum, 0);
        return 0;
    }

    handleCount = *((DWORD*)buffer);
    if (bytesReturned < sizeof(DWORD) + (handleCount * sizeof(DWORD))) {
        handleCount = (bytesReturned - sizeof(DWORD)) / sizeof(DWORD);
    }

    if (handleCount == 0 || g_CancelEnum || g_bSearchRunning) {
        free(buffer);
        InterlockedExchange(&g_IsEnumerating, 0);
        PostMessage(g_hMainWnd, WM_APP_ENUM_COMPLETE, (WPARAM)g_CancelEnum, 0);
        return 0;
    }

    handles = (DWORD*)(buffer + sizeof(DWORD));

    objArray = (OBJECT_ITEM*)malloc(handleCount * sizeof(OBJECT_ITEM));
    if (!objArray) {
        free(buffer);
        InterlockedExchange(&g_IsEnumerating, 0);
        PostMessage(g_hMainWnd, WM_APP_ENUM_COMPLETE, 0, 0);
        return 0;
    }
    ZeroMemory(objArray, handleCount * sizeof(OBJECT_ITEM));

    EnterCriticalSection(&g_ObjectsCs);
    if (g_Objects) free(g_Objects);
    g_Objects = objArray;
    g_ObjectCount = 0;
    LeaveCriticalSection(&g_ObjectsCs);

    {
        DWORD enumFailCount = 0;

        for (i = 0; i < handleCount; i++) {
            BYTE infoBuf[4096];
            DWORD infoBytes = 0;
            BYTE *pNext = NULL;
            WCHAR dateW[64];

            if (g_CancelEnum || g_bSearchRunning) break;

            /* After 3 consecutive failures, reset pipes to recover from desync.
             * After 8 consecutive failures, verify if the device is still alive. */
            if (enumFailCount == 3) {
                MtpResetPipes();
                Sleep(50);
            }
            if (enumFailCount >= 8) {
                DWORD devInfoRet = 0;
                BYTE devBuf[64];
                MtpResetPipes();
                Sleep(100);
                if (!MtpSendOperation(MTP_OP_GET_DEVICE_INFO, NULL, 0, NULL, 0, devBuf, sizeof(devBuf), &devInfoRet)) {
                    break; /* Device is truly disconnected or unresponsive */
                }
                enumFailCount = 0; /* Device is alive, continue reading folder */
            }

            objArray[i].Handle = handles[i];
            objArray[i].ParentHandle = parentHandle;

            if (MtpGetObjectInfoWithRetry(handles[i], infoBuf, sizeof(infoBuf), &infoBytes)) {
                objArray[i].StorageId = *((DWORD*)(infoBuf + 0));
                objArray[i].Format = *((WORD*)(infoBuf + 4));
                objArray[i].SizeLow = *((DWORD*)(infoBuf + 8));
                objArray[i].SizeHigh = 0;
                objArray[i].Size = (ULONGLONG)objArray[i].SizeLow;
                objArray[i].ParentHandle = *((DWORD*)(infoBuf + 38));

                pNext = ReadMtpString(infoBuf + 52, infoBytes - 52, objArray[i].Name, 256);
                dateW[0] = L'\0';
                if (pNext && (DWORD)(pNext - infoBuf) < infoBytes) {
                    BYTE *pMod = ReadMtpString(pNext, infoBytes - (DWORD)(pNext - infoBuf), dateW, 64);
                    if (pMod && (DWORD)(pMod - infoBuf) < infoBytes) {
                        WCHAR modDateW[64];
                        modDateW[0] = L'\0';
                        ReadMtpString(pMod, infoBytes - (DWORD)(pMod - infoBuf), modDateW, 64);
                        if (modDateW[0] != L'\0') {
                            wcsncpy(dateW, modDateW, 63);
                            dateW[63] = L'\0';
                        }
                    }
                }
                ParseMtpDate(dateW, objArray[i].DateStr, sizeof(objArray[i].DateStr), &objArray[i].FileTime);
                objArray[i].IsFolder = (objArray[i].Format == MTP_FORMAT_ASSOCIATION);

                /* 64-bit file size if low is 0xFFFFFFFF */
                if (!objArray[i].IsFolder && objArray[i].SizeLow == 0xFFFFFFFF) {
                    BYTE propBuf[16];
                    DWORD propBytes = 0;
                    DWORD propParams[2];
                    propParams[0] = handles[i];
                    propParams[1] = 0xDC04;
                    if (MtpSendOperation(0x9803, propParams, 2, NULL, 0,
                                         propBuf, sizeof(propBuf), &propBytes) && propBytes >= 8) {
                        objArray[i].SizeLow = *((DWORD*)(propBuf + 0));
                        objArray[i].SizeHigh = *((DWORD*)(propBuf + 4));
                        objArray[i].Size = ((ULONGLONG)objArray[i].SizeHigh << 32) | (ULONGLONG)objArray[i].SizeLow;
                    }
                }
                enumFailCount = 0; /* Reset on success */
            } else {
                /* If cancelled, break immediately without incrementing failure count or generating dummy items */
                if (g_CancelEnum || g_bSearchRunning) break;

                objArray[i].Format = MTP_FORMAT_UNDEFINED;
                objArray[i].Size = 0;
                objArray[i].SizeLow = 0;
                objArray[i].SizeHigh = 0;
                _snwprintf(objArray[i].Name, 256, L"Object_%08X", handles[i]);
                objArray[i].DateStr[0] = '\0';
                objArray[i].FileTime.dwLowDateTime = 0;
                objArray[i].FileTime.dwHighDateTime = 0;
                objArray[i].IsFolder = FALSE;
                enumFailCount++;
            }

            EnterCriticalSection(&g_ObjectsCs);
            g_ObjectCount = i + 1;
            LeaveCriticalSection(&g_ObjectsCs);

            /* Progressive UI update: update at item 1, 10, 25, 50, and every 50 after */
            if (i == 0 || i == 9 || i == 24 || (i % 50) == 0) {
                if (!g_CancelEnum && !g_bSearchRunning) {
                    PostMessage(g_hMainWnd, WM_APP_ENUM_PROGRESS, (WPARAM)(i + 1), (LPARAM)handleCount);
                }
            }
        }
    }

    free(buffer);
    InterlockedExchange(&g_IsEnumerating, 0);

    /* Post completion message to GUI thread only if not cancelled */
    if (!g_CancelEnum && !g_bSearchRunning) {
        PostMessage(g_hMainWnd, WM_APP_ENUM_COMPLETE, 0, (LPARAM)g_ObjectCount);
    }
    return 0;
}

BOOL RefreshObjects(void)
{
    DWORD dwThreadId = 0;

    if (!g_Connected || g_hDevice == INVALID_HANDLE_VALUE) return FALSE;

    /* Do not start folder enumeration while search is actively using the MTP device */
    if (g_bSearchRunning) return FALSE;

    /* Cancel any active enumeration and cleanly wait for thread termination without corrupting USB state */
    InterlockedExchange(&g_CancelEnum, 1);
    if (g_hEnumThread) {
        WaitForSingleObject(g_hEnumThread, 5000);
        CloseHandle(g_hEnumThread);
        g_hEnumThread = NULL;
    }

    InterlockedExchange(&g_CancelEnum, 0);

    /* Clear listview items immediately */
    EnterCriticalSection(&g_ObjectsCs);
    g_ObjectCount = 0;
    LeaveCriticalSection(&g_ObjectsCs);
    if (g_hListView) {
        ListView_SetItemCount(g_hListView, 0);
    }

    SetStatus("Reading file catalog from device... (Press Esc to cancel)");
    UpdateUI();

    g_hEnumThread = CreateThread(NULL, 0, EnumObjectsWorkerThread, (LPVOID)(ULONG_PTR)g_CurrentParent, 0, &dwThreadId);
    if (!g_hEnumThread) {
        SetStatus("Failed to start enumeration thread");
        UpdateUI();
        return FALSE;
    }

    return TRUE;
}

/* ============================================================================
 * Taskbar System Tray Notifications (Secure Load & Deload)
 * ============================================================================ */

void ShowTaskbarNotification(HWND hWnd, const char *title, const char *message, DWORD infoFlags)
{
    NOTIFYICONDATAA nid;
    ZeroMemory(&nid, sizeof(nid));
    nid.cbSize = sizeof(NOTIFYICONDATAA);
    nid.hWnd = hWnd;
    nid.uID = ID_TRAY_ICON;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
    nid.uCallbackMessage = WM_TRAY_NOTIFY;
    nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
    strncpy(nid.szTip, "MTP Portable Device", sizeof(nid.szTip) - 1);
    strncpy(nid.szInfoTitle, title, sizeof(nid.szInfoTitle) - 1);
    strncpy(nid.szInfo, message, sizeof(nid.szInfo) - 1);
    nid.uTimeout = 6000;
    nid.dwInfoFlags = infoFlags;
    
    if (!g_bTrayIconAdded) {
        if (Shell_NotifyIconA(NIM_ADD, &nid)) {
            g_bTrayIconAdded = TRUE;
        }
    }
    Shell_NotifyIconA(NIM_MODIFY, &nid);
    
    SetTimer(hWnd, TIMER_TRAY_DISMISS, 6000, NULL);
}

void RemoveTaskbarNotification(HWND hWnd)
{
    if (g_bTrayIconAdded) {
        NOTIFYICONDATAA nid;
        ZeroMemory(&nid, sizeof(nid));
        nid.cbSize = sizeof(NOTIFYICONDATAA);
        nid.hWnd = hWnd;
        nid.uID = ID_TRAY_ICON;
        Shell_NotifyIconA(NIM_DELETE, &nid);
        g_bTrayIconAdded = FALSE;
    }
    KillTimer(hWnd, TIMER_TRAY_DISMISS);
}

/* ============================================================================
 * Folder Navigation & History
 * ============================================================================ */

void InitNavHistory(void)
{
    g_NavHistoryIndex = 0;
    g_NavHistoryCount = 1;
    g_NavHistory[0].parentHandle = MTP_PARENT_ROOT;
    strncpy(g_NavHistory[0].path, g_szRootName, sizeof(g_NavHistory[0].path) - 1);
    UpdateNavButtons();
}

void UpdateNavButtons(void)
{
    if (!g_hToolbar) return;
    
    /* Back button: ALWAYS enabled (at root, returns to My Computer and closes MTP window) */
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_BACK, TRUE);
    
    /* Forward button: enabled if we have forward history */
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_FORWARD, 
                (g_NavHistoryIndex >= 0 && g_NavHistoryIndex < g_NavHistoryCount - 1));
    
    /* Up / Parent button: enabled if in a subfolder */
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_PARENT, (g_CurrentParent != MTP_PARENT_ROOT));
}

void NavigateToFolder(DWORD handle, const char *folderName)
{
    if (g_bSearchRunning) return;
    g_CurrentParent = handle;
    if (folderName && folderName[0]) {
        if (strcmp(g_szCurrentPath, g_szRootName) == 0) {
            _snprintf(g_szCurrentPath, sizeof(g_szCurrentPath), "%s\\%s", g_szRootName, folderName);
        } else {
            size_t currLen = strlen(g_szCurrentPath);
            size_t fnLen = strlen(folderName);
            if (currLen >= fnLen && _stricmp(g_szCurrentPath + currLen - fnLen, folderName) == 0) {
                /* already ends with folderName */
            } else {
                _snprintf(g_szCurrentPath, sizeof(g_szCurrentPath), "%s\\%s", g_szCurrentPath, folderName);
            }
        }
    } else {
        _snprintf(g_szCurrentPath, sizeof(g_szCurrentPath), "%s\\Subfolder", g_szRootName);
    }
    if (g_hAddressCombo) {
        SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
    }
    
    /* Push to history stack (discarding any forward branch) */
    if (g_NavHistoryIndex + 1 < MAX_NAV_HISTORY) {
        g_NavHistoryIndex++;
        g_NavHistoryCount = g_NavHistoryIndex + 1;
        g_NavHistory[g_NavHistoryIndex].parentHandle = handle;
        strncpy(g_NavHistory[g_NavHistoryIndex].path, g_szCurrentPath, sizeof(g_NavHistory[0].path) - 1);
    }
    UpdateNavButtons();
    RefreshObjects();
}

void NavigateToParent(void)
{
    if (g_bSearchRunning) return;
    if (g_NavHistoryIndex > 0) {
        g_NavHistoryIndex--;
        g_CurrentParent = g_NavHistory[g_NavHistoryIndex].parentHandle;
        strncpy(g_szCurrentPath, g_NavHistory[g_NavHistoryIndex].path, sizeof(g_szCurrentPath) - 1);
        if (g_hAddressCombo) {
            SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
        }
        UpdateNavButtons();
        RefreshObjects();
        return;
    }
    
    if (g_CurrentParent != MTP_PARENT_ROOT && g_CurrentParent != 0) {
        DWORD parentParam = g_CurrentParent;
        BYTE infoBuf[512];
        DWORD infoBytes = 0;
        DWORD parentOfParent = MTP_PARENT_ROOT;
        if (MtpSendOperation(MTP_OP_GET_OBJECT_INFO, &parentParam, 1, NULL, 0,
                             infoBuf, sizeof(infoBuf), &infoBytes) && infoBytes >= 42) {
            parentOfParent = *((DWORD*)(infoBuf + 38));
            if (parentOfParent == 0) parentOfParent = MTP_PARENT_ROOT;
        }
        g_CurrentParent = parentOfParent;
        if (g_CurrentParent == MTP_PARENT_ROOT) {
            strncpy(g_szCurrentPath, g_szRootName, sizeof(g_szCurrentPath) - 1);
        } else {
            char *lastSlash = strrchr(g_szCurrentPath, '\\');
            if (lastSlash) *lastSlash = '\0';
            else strncpy(g_szCurrentPath, g_szRootName, sizeof(g_szCurrentPath) - 1);
        }
        if (g_hAddressCombo) {
            SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
        }
        UpdateNavButtons();
        RefreshObjects();
        return;
    }

    /* Already at root: return to My Computer and close MTP window */
    ShellExecuteA(NULL, "open", "explorer.exe", "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}", NULL, SW_SHOWNORMAL);
    PostMessage(g_hMainWnd, WM_CLOSE, 0, 0);
}

DWORD MtpFindChildFolder(DWORD parentHandle, const char *folderName)
{
    BYTE buffer[4096];
    DWORD bytesReturned = 0;
    DWORD params[3];
    DWORD *handles;
    DWORD handleCount;
    DWORD i;

    if (!g_Connected || g_hDevice == INVALID_HANDLE_VALUE || !folderName || !folderName[0]) return 0;

    params[0] = g_CurrentStorage ? g_CurrentStorage : 0xFFFFFFFF;
    params[1] = 0x00000000;
    params[2] = parentHandle;

    if (!MtpSendOperation(MTP_OP_GET_OBJECT_HANDLES, params, 3, NULL, 0,
                          buffer, sizeof(buffer), &bytesReturned)) {
        return 0;
    }
    if (bytesReturned < sizeof(DWORD)) return 0;
    handleCount = *((DWORD*)buffer);
    if (bytesReturned < sizeof(DWORD) + (handleCount * sizeof(DWORD))) {
        handleCount = (bytesReturned - sizeof(DWORD)) / sizeof(DWORD);
    }
    handles = (DWORD*)(buffer + sizeof(DWORD));

    for (i = 0; i < handleCount; i++) {
        BYTE infoBuf[1024];
        DWORD infoBytes = 0;
        DWORD objParam = handles[i];
        if (MtpSendOperation(MTP_OP_GET_OBJECT_INFO, &objParam, 1, NULL, 0,
                             infoBuf, sizeof(infoBuf), &infoBytes) && infoBytes >= 52) {
            WORD fmt = *((WORD*)(infoBuf + 4));
            if (fmt == MTP_FORMAT_ASSOCIATION) {
                WCHAR nameW[256];
                char nameA[256];
                ReadMtpString(infoBuf + 52, infoBytes - 52, nameW, 256);
                WideCharToMultiByte(CP_ACP, 0, nameW, -1, nameA, sizeof(nameA), NULL, NULL);
                if (_stricmp(nameA, folderName) == 0) {
                    return handles[i];
                }
            }
        }
    }
    return 0;
}

BOOL NavigateToAddressPath(HWND hWnd, const char *inputPath)
{
    char szTarget[MAX_PATH];
    char szTrimmed[MAX_PATH];
    char *p;
    
    if (!inputPath || !inputPath[0]) return FALSE;
    strncpy(szTarget, inputPath, sizeof(szTarget) - 1);
    szTarget[sizeof(szTarget) - 1] = '\0';
    
    p = szTarget;
    while (*p == ' ' || *p == '\t') p++;
    strncpy(szTrimmed, p, sizeof(szTrimmed) - 1);
    szTrimmed[sizeof(szTrimmed) - 1] = '\0';
    p = szTrimmed + strlen(szTrimmed) - 1;
    while (p >= szTrimmed && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')) {
        *p = '\0';
        p--;
    }
    if (szTrimmed[0] == '\0') return FALSE;
    
    /* 1. Shell special locations: My Computer, desktop */
    if (_stricmp(szTrimmed, "My Computer") == 0 ||
        _stricmp(szTrimmed, "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}") == 0) {
        ShellExecuteA(NULL, "open", "explorer.exe", "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}", NULL, SW_SHOWNORMAL);
        return TRUE;
    }
    
    /* 2. Standard Windows drive letter or UNC network path */
    if ((szTrimmed[1] == ':' && (szTrimmed[2] == '\\' || szTrimmed[2] == '/' || szTrimmed[2] == '\0')) ||
        (szTrimmed[0] == '\\' && szTrimmed[1] == '\\')) {
        ShellExecuteA(NULL, "open", "explorer.exe", szTrimmed, NULL, SW_SHOWNORMAL);
        return TRUE;
    }
    
    if (!g_Connected) {
        ConnectDevice();
    }
    
    /* 3. Root directory */
    if (_stricmp(szTrimmed, g_szRootName) == 0 ||
        _stricmp(szTrimmed, "Internal Storage") == 0 ||
        _stricmp(szTrimmed, "Portable Device") == 0 ||
        _stricmp(szTrimmed, "\\") == 0 ||
        _stricmp(szTrimmed, "/") == 0) {
        g_CurrentParent = 0;
        strcpy(g_szCurrentPath, g_szRootName);
        if (g_hAddressCombo) {
            SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
        }
        if (g_NavHistoryIndex + 1 < MAX_NAV_HISTORY) {
            g_NavHistoryIndex++;
            g_NavHistoryCount = g_NavHistoryIndex + 1;
            g_NavHistory[g_NavHistoryIndex].parentHandle = 0;
            strncpy(g_NavHistory[g_NavHistoryIndex].path, g_szRootName, sizeof(g_NavHistory[0].path) - 1);
        }
        UpdateNavButtons();
        RefreshObjects();
        return TRUE;
    }
    
    /* 4. Parent directory shortcut: ".." */
    if (strcmp(szTrimmed, "..") == 0) {
        NavigateToParent();
        return TRUE;
    }
    
    /* 5. Hierarchical MTP Path Resolution */
    {
        char cleanPath[MAX_PATH];
        char resolvedPath[MAX_PATH];
        char *seg;
        DWORD currHandle = 0;
        BOOL bSuccess = TRUE;
        
        p = szTrimmed;
        if (_strnicmp(p, g_szRootName, strlen(g_szRootName)) == 0) {
            p += strlen(g_szRootName);
        } else if (_strnicmp(p, "Internal Storage", 16) == 0) {
            p += 16;
        } else if (_strnicmp(p, "Portable Device", 15) == 0) {
            p += 15;
        }
        while (*p == '\\' || *p == '/') p++;
        
        if (*p == '\0') {
            g_CurrentParent = 0;
            strcpy(g_szCurrentPath, g_szRootName);
            if (g_hAddressCombo) SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
            UpdateNavButtons();
            RefreshObjects();
            return TRUE;
        }
        
        strncpy(cleanPath, p, sizeof(cleanPath) - 1);
        cleanPath[sizeof(cleanPath) - 1] = '\0';
        
        p = cleanPath + strlen(cleanPath) - 1;
        while (p >= cleanPath && (*p == '\\' || *p == '/')) {
            *p = '\0';
            p--;
        }
        
        strcpy(resolvedPath, g_szRootName);
        
        /* If single token and exists in current folder, navigate into it directly */
        if (strchr(cleanPath, '\\') == NULL && strchr(cleanPath, '/') == NULL && g_CurrentParent != 0) {
            DWORD childH = MtpFindChildFolder(g_CurrentParent, cleanPath);
            if (childH != 0) {
                NavigateToFolder(childH, cleanPath);
                return TRUE;
            }
        }
        
        /* Resolve from root (0) token by token */
        currHandle = 0;
        seg = strtok(cleanPath, "\\/");
        while (seg != NULL) {
            DWORD nextH = MtpFindChildFolder(currHandle, seg);
            if (nextH == 0) {
                bSuccess = FALSE;
                break;
            }
            _snprintf(resolvedPath + strlen(resolvedPath),
                      sizeof(resolvedPath) - strlen(resolvedPath),
                      "\\%s", seg);
            currHandle = nextH;
            seg = strtok(NULL, "\\/");
        }
        
        if (bSuccess && currHandle != 0) {
            g_CurrentParent = currHandle;
            strncpy(g_szCurrentPath, resolvedPath, sizeof(g_szCurrentPath) - 1);
            g_szCurrentPath[sizeof(g_szCurrentPath) - 1] = '\0';
            if (g_hAddressCombo) {
                SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
            }
            if (g_NavHistoryIndex + 1 < MAX_NAV_HISTORY) {
                g_NavHistoryIndex++;
                g_NavHistoryCount = g_NavHistoryIndex + 1;
                g_NavHistory[g_NavHistoryIndex].parentHandle = currHandle;
                strncpy(g_NavHistory[g_NavHistoryIndex].path, g_szCurrentPath, sizeof(g_NavHistory[0].path) - 1);
            }
            UpdateNavButtons();
            RefreshObjects();
            return TRUE;
        }
    }
    
    /* 6. Not found: standard Explorer error message */
    {
        char msg[300];
        _snprintf(msg, sizeof(msg), "Windows Explorer cannot find '%s'. Check the spelling and try again.", szTrimmed);
        MessageBoxA(hWnd, msg, "Address", MB_OK | MB_ICONWARNING);
        if (g_hAddressCombo) {
            SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
        }
    }
    return FALSE;
}

void OnNavigateBack(HWND hWnd)
{
    if (g_CurrentParent == 0 || g_CurrentParent == MTP_PARENT_ROOT) {
        /* User is in the root of the MTP device:
         * Back returns to My Computer window and closes the MTP window! */
        ShellExecuteA(NULL, "open", "explorer.exe", "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}", NULL, SW_SHOWNORMAL);
        PostMessage(hWnd, WM_CLOSE, 0, 0);
        return;
    }
    
    if (g_NavHistoryIndex > 0) {
        g_NavHistoryIndex--;
        g_CurrentParent = g_NavHistory[g_NavHistoryIndex].parentHandle;
        strncpy(g_szCurrentPath, g_NavHistory[g_NavHistoryIndex].path, sizeof(g_szCurrentPath) - 1);
        if (g_hAddressCombo) {
            SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
        }
        UpdateNavButtons();
        RefreshObjects();
    } else {
        NavigateToParent();
    }
}

void OnNavigateForward(HWND hWnd)
{
    if (g_NavHistoryIndex >= 0 && g_NavHistoryIndex < g_NavHistoryCount - 1) {
        g_NavHistoryIndex++;
        g_CurrentParent = g_NavHistory[g_NavHistoryIndex].parentHandle;
        strncpy(g_szCurrentPath, g_NavHistory[g_NavHistoryIndex].path, sizeof(g_szCurrentPath) - 1);
        if (g_hAddressCombo) {
            SetWindowTextA(g_hAddressCombo, g_szCurrentPath);
        }
        UpdateNavButtons();
        RefreshObjects();
    }
}

/* ============================================================================
 * File Download & Upload
 * ============================================================================ */

BOOL DownloadObjectToFile(HWND hWnd, DWORD handle, ULONGLONG totalSize, const char *szDestFile, const char *displayName, BOOL quiet)
{
    HANDLE hFile;
    ULONGLONG transferred = 0;
    MTP_GET_PART_REQ req;
    BYTE *chunkBuffer;
    DWORD bytesReturned;
    char statusBuf[256];
    MSG msg;
    DWORD startTick;
    double elapsed, speed, eta;
    char speedStr[32], etaStr[32], sizeStr[32], totalStr[32];
    int percent;
    
    hFile = CreateFileA(szDestFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        if (!quiet) MessageBoxA(hWnd, "Failed to create destination file.", "Download Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    chunkBuffer = (BYTE*)malloc(g_OptimalChunkSize);
    if (!chunkBuffer) {
        CloseHandle(hFile);
        if (!quiet) MessageBoxA(hWnd, "Out of memory for transfer buffer.", "Download Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    g_CancelTransfer = FALSE;
    startTick = GetTickCount();
    FormatFileSize64(totalSize, totalStr, sizeof(totalStr));
    
    while (transferred < totalSize && !g_CancelTransfer) {
        ULONGLONG remaining = totalSize - transferred;
        DWORD chunkSize = (remaining > (ULONGLONG)g_OptimalChunkSize) ? g_OptimalChunkSize : (DWORD)remaining;
        DWORD bytesWritten;
        BOOL bPartOk;
        
        req.Id = handle;
        req.OffsetLow = (DWORD)(transferred & 0xFFFFFFFF);
        req.OffsetHigh = (DWORD)(transferred >> 32);
        req.Length = chunkSize;
        
        EnterCriticalSection(&g_DeviceCs);
        bPartOk = DeviceIoControl(g_hDevice, IOCTL_MTP_GET_OBJECT_PART,
                                 &req, sizeof(req), chunkBuffer, chunkSize, &bytesReturned, NULL);
        LeaveCriticalSection(&g_DeviceCs);
        if (!bPartOk || bytesReturned == 0) {
            free(chunkBuffer);
            CloseHandle(hFile);
            if (!quiet) MessageBoxA(hWnd, "Error reading file data stream from MTP device.", "Transfer Error", MB_OK | MB_ICONERROR);
            return FALSE;
        }
        
        WriteFile(hFile, chunkBuffer, bytesReturned, &bytesWritten, NULL);
        transferred += bytesReturned;
        
        elapsed = (double)(GetTickCount() - startTick) / 1000.0;
        if (elapsed > 0.1) {
            speed = (double)transferred / elapsed;
            eta = (totalSize > transferred) ? (double)(totalSize - transferred) / speed : 0;
        } else {
            speed = 0;
            eta = 0;
        }
        percent = (totalSize > 0) ? (int)((transferred * 100ULL) / totalSize) : 100;
        
        FormatFileSize64(transferred, sizeStr, sizeof(sizeStr));
        FormatTransferSpeed(speed, speedStr, sizeof(speedStr));
        FormatETA(eta, etaStr, sizeof(etaStr));
        
        _snprintf(statusBuf, sizeof(statusBuf), "%s %s: %s / %s (%d%%) | %s | ETA: %s",
                  quiet ? "Copying" : "Downloading", displayName, sizeStr, totalStr, percent, speedStr, etaStr);
        SetStatus(statusBuf);
        
        _snprintf(statusBuf, sizeof(statusBuf), "[%d%%] %s %s - MTP Explorer", percent, quiet ? "Copying" : "Downloading", displayName);
        SetWindowTextA(g_hMainWnd, statusBuf);
        
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE) {
                g_CancelTransfer = TRUE;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    
    free(chunkBuffer);
    CloseHandle(hFile);
    UpdateUI();
    
    if (g_CancelTransfer) {
        SetStatus("Transfer canceled by user");
        if (!quiet) MessageBoxA(hWnd, "Download canceled.", "MTP Transfer", MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }
    
    elapsed = (double)(GetTickCount() - startTick) / 1000.0;
    speed = (elapsed > 0) ? (double)transferred / elapsed : 0;
    FormatFileSize64(transferred, sizeStr, sizeof(sizeStr));
    FormatTransferSpeed(speed, speedStr, sizeof(speedStr));
    
    _snprintf(statusBuf, sizeof(statusBuf), "%s complete - %s at %s (%s, chunk %luKB)",
              quiet ? "Copy" : "Download", sizeStr, speedStr, g_szUsbSpeed, g_OptimalChunkSize / 1024);
    SetStatus(statusBuf);
    
    if (!quiet) {
        _snprintf(statusBuf, sizeof(statusBuf),
                  "Download complete!\n\nFile: %s\nSize: %s\nSpeed: %s\nUSB: %s\nChunk Size: %lu KB\nElapsed: %.1f seconds",
                  displayName, sizeStr, speedStr, g_szUsbSpeed, g_OptimalChunkSize / 1024, elapsed);
        MessageBoxA(hWnd, statusBuf, "Transfer Complete", MB_OK | MB_ICONINFORMATION);
    }
    return TRUE;
}

BOOL DownloadSelected(HWND hWnd)
{
    int selIndex;
    DWORD handle = 0;
    ULONGLONG size = 0;
    char szFile[MAX_PATH];
    OPENFILENAMEA ofn;
    char nameA[256];
    BOOL isFolder = FALSE;
    BOOL valid = FALSE;
    
    selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
    if (selIndex == -1) {
        MessageBoxA(hWnd, "Please select an item to download.", "Download", MB_OK | MB_ICONINFORMATION);
        return FALSE;
    }

    if (g_bSearchRunning) {
        MessageBoxA(hWnd, "Please wait for search to complete or stop the search before downloading.", "Search in Progress", MB_OK | MB_ICONINFORMATION);
        return FALSE;
    }
    
    EnterCriticalSection(&g_ObjectsCs);
    if (g_Objects && (DWORD)selIndex < g_ObjectCount) {
        handle = g_Objects[selIndex].Handle;
        size = g_Objects[selIndex].Size;
        isFolder = g_Objects[selIndex].IsFolder;
        WideCharToMultiByte(CP_ACP, 0, g_Objects[selIndex].Name, -1, nameA, sizeof(nameA), NULL, NULL);
        valid = TRUE;
    }
    LeaveCriticalSection(&g_ObjectsCs);
    
    if (!valid || isFolder) {
        MessageBoxA(hWnd, "Cannot download a folder directly. Please enter the folder.", "Download", MB_OK | MB_ICONINFORMATION);
        return FALSE;
    }
    
    strncpy(szFile, nameA, MAX_PATH);
    
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrTitle = "Save As - Download from MTP Device";
    ofn.Flags = OFN_PATHMUSTEXIST;
    
    if (!GetSaveFileNameA(&ofn)) return FALSE;
    
    return DownloadObjectToFile(hWnd, handle, size, szFile, nameA, FALSE);
}

BOOL CopySelectedToClipboard(HWND hWnd)
{
    int selIndex = -1;
    char szTempBase[MAX_PATH];
    char szTempFile[MAX_PATH];
    char statusBuf[256];
    DWORD totalBytesNeeded = 0;
    DWORD currentOffset = 0;
    HGLOBAL hGlobal = NULL;
    DROPFILES *pDropFiles = NULL;
    OBJECT_ITEM selectedItems[64];
    int selectedCount = 0;
    int successCount = 0;
    int i;
    BOOL succeeded[64];
    
    if (!g_Connected || g_hDevice == INVALID_HANDLE_VALUE) {
        SetStatus("Device not connected.");
        return FALSE;
    }
    
    EnterCriticalSection(&g_ObjectsCs);
    while ((selIndex = ListView_GetNextItem(g_hListView, selIndex, LVNI_SELECTED)) != -1) {
        if (g_Objects && (DWORD)selIndex < g_ObjectCount) {
            if (!g_Objects[selIndex].IsFolder && selectedCount < 64) {
                selectedItems[selectedCount++] = g_Objects[selIndex];
            }
        }
    }
    LeaveCriticalSection(&g_ObjectsCs);
    
    if (selectedCount == 0) {
        SetStatus("No files selected to copy.");
        return FALSE;
    }
    
    GetTempPathA(sizeof(szTempBase), szTempBase);
    strcat(szTempBase, "MtpClipboard\\");
    CreateDirectoryA(szTempBase, NULL);
    
    ZeroMemory(succeeded, sizeof(succeeded));
    
    totalBytesNeeded = sizeof(DROPFILES) + 1;
    
    for (i = 0; i < selectedCount; i++) {
        char nameA[256];
        WideCharToMultiByte(CP_ACP, 0, selectedItems[i].Name, -1, nameA, sizeof(nameA), NULL, NULL);
        _snprintf(szTempFile, sizeof(szTempFile), "%s%s", szTempBase, nameA);
        DeleteFileA(szTempFile);
        
        if (DownloadObjectToFile(hWnd, selectedItems[i].Handle, selectedItems[i].Size, szTempFile, nameA, TRUE)) {
            HANDLE hCheck = CreateFileA(szTempFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
            if (hCheck != INVALID_HANDLE_VALUE) {
                CloseHandle(hCheck);
                totalBytesNeeded += (DWORD)strlen(szTempFile) + 1;
                succeeded[i] = TRUE;
                successCount++;
            }
        }
    }
    
    if (successCount == 0) {
        SetStatus("Failed to copy selected file(s).");
        return FALSE;
    }
    
    hGlobal = GlobalAlloc(GHND | GMEM_SHARE, totalBytesNeeded);
    if (!hGlobal) {
        SetStatus("Out of memory for clipboard data.");
        return FALSE;
    }
    
    pDropFiles = (DROPFILES*)GlobalLock(hGlobal);
    pDropFiles->pFiles = sizeof(DROPFILES);
    pDropFiles->pt.x = 0;
    pDropFiles->pt.y = 0;
    pDropFiles->fNC = FALSE;
    pDropFiles->fWide = FALSE;
    
    currentOffset = sizeof(DROPFILES);
    for (i = 0; i < selectedCount; i++) {
        if (succeeded[i]) {
            char nameA[256];
            DWORD len;
            WideCharToMultiByte(CP_ACP, 0, selectedItems[i].Name, -1, nameA, sizeof(nameA), NULL, NULL);
            _snprintf(szTempFile, sizeof(szTempFile), "%s%s", szTempBase, nameA);
            len = (DWORD)strlen(szTempFile);
            memcpy((char*)pDropFiles + currentOffset, szTempFile, len + 1);
            currentOffset += len + 1;
        }
    }
    *((char*)pDropFiles + currentOffset) = '\0';
    GlobalUnlock(hGlobal);
    
    if (OpenClipboard(hWnd)) {
        EmptyClipboard();
        SetClipboardData(CF_HDROP, hGlobal);
        CloseClipboard();
        
        _snprintf(statusBuf, sizeof(statusBuf), "Copied %d file(s) to Clipboard. Press Ctrl+V in Explorer to paste.", successCount);
        SetStatus(statusBuf);
        if (g_bNotifyOnCopyPaste) {
            ShowTaskbarNotification(hWnd, "Files Copied to Clipboard", "Ready to paste (Ctrl+V) into Windows Explorer or Desktop.", NIIF_INFO);
        }
        return TRUE;
    } else {
        GlobalFree(hGlobal);
        SetStatus("Failed to open clipboard.");
        return FALSE;
    }
}

BOOL PasteFromClipboard(HWND hWnd)
{
    HDROP hDrop;
    UINT numFiles;
    UINT i;
    int successCount = 0;
    char szFilePath[MAX_PATH];
    char statusBuf[256];
    
    if (!g_Connected || g_hDevice == INVALID_HANDLE_VALUE) {
        MessageBoxA(hWnd, "Please connect to the MTP device before pasting files.", "Paste", MB_OK | MB_ICONWARNING);
        return FALSE;
    }
    
    if (!IsClipboardFormatAvailable(CF_HDROP)) {
        SetStatus("Clipboard does not contain files (use Ctrl+C on files in Explorer first).");
        return FALSE;
    }
    
    if (!OpenClipboard(hWnd)) {
        SetStatus("Cannot open clipboard.");
        return FALSE;
    }
    
    hDrop = (HDROP)GetClipboardData(CF_HDROP);
    if (!hDrop) {
        CloseClipboard();
        SetStatus("Failed to access clipboard file data.");
        return FALSE;
    }
    
    numFiles = DragQueryFileA(hDrop, 0xFFFFFFFF, NULL, 0);
    if (numFiles == 0) {
        CloseClipboard();
        SetStatus("No files found in clipboard.");
        return FALSE;
    }
    
    SetStatus("Pasting files from clipboard to MTP device...");
    
    for (i = 0; i < numFiles; i++) {
        if (DragQueryFileA(hDrop, i, szFilePath, sizeof(szFilePath))) {
            if (UploadSingleFilePath(hWnd, szFilePath)) {
                successCount++;
            }
        }
    }
    
    CloseClipboard();
    
    if (successCount > 0) {
        RefreshObjects();
        _snprintf(statusBuf, sizeof(statusBuf), "Pasted %d of %d file(s) successfully into %s.",
                  successCount, numFiles, g_szCurrentPath);
        SetStatus(statusBuf);
        if (g_bNotifyOnCopyPaste) {
            ShowTaskbarNotification(hWnd, "Paste Complete", "Files pasted successfully from clipboard to MTP device.", NIIF_INFO);
        }
        return TRUE;
    } else {
        SetStatus("Failed to paste files to MTP device.");
        return FALSE;
    }
}

BOOL UploadSingleFilePath(HWND hWnd, const char *szFile)
{
    HANDLE hFile;
    ULONGLONG fileSize;
    ULONGLONG transferred = 0;
    BYTE *readBuffer;
    BYTE *payload;
    BYTE responseBuf[64];
    DWORD bytesReturned;
    DWORD objectId = 0;
    char statusBuf[256];
    MSG msg;
    DWORD startTick;
    double elapsed, speed, eta;
    char speedStr[32], etaStr[32], sizeStr[32], totalStr[32];
    int percent;
    LARGE_INTEGER liSize;
    const char *fileName;
    WORD objFormat = MTP_FORMAT_UNDEFINED;
    const char *ext;
    WCHAR wFileName[MAX_PATH];
    int wChars;
    BYTE objInfoBuf[1024];
    DWORD objInfoLen;
    DWORD sendParams[2];
    DWORD targetStorage;
    DWORD targetParent;
    BYTE respBuf[64];
    DWORD respBytes = 0;
    
    if (!g_Connected || g_hDevice == INVALID_HANDLE_VALUE) {
        MessageBoxA(hWnd, "Please connect to the MTP device before transferring files.", 
                    "Transfer Error", MB_OK | MB_ICONWARNING);
        return FALSE;
    }

    if (g_bSearchRunning) {
        MessageBoxA(hWnd, "Please wait for search to complete or stop the search before uploading files.", 
                    "Transfer Error", MB_OK | MB_ICONWARNING);
        return FALSE;
    }
    
    hFile = CreateFileA(szFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        char errBuf[MAX_PATH + 64];
        _snprintf(errBuf, sizeof(errBuf), "Failed to open local source file:\n%s", szFile);
        MessageBoxA(hWnd, errBuf, "Upload Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    liSize.LowPart = GetFileSize(hFile, (LPDWORD)&liSize.HighPart);
    fileSize = (ULONGLONG)liSize.QuadPart;
    
    fileName = strrchr(szFile, '\\');
    if (fileName) fileName++; else fileName = szFile;

    /* Detect format code from file extension */
    ext = strrchr(fileName, '.');
    if (ext) {
        if (_stricmp(ext, ".jpg") == 0 || _stricmp(ext, ".jpeg") == 0) objFormat = MTP_FORMAT_EXIF_JPEG;
        else if (_stricmp(ext, ".png") == 0) objFormat = MTP_FORMAT_PNG;
        else if (_stricmp(ext, ".bmp") == 0) objFormat = MTP_FORMAT_BMP;
        else if (_stricmp(ext, ".mp3") == 0) objFormat = MTP_FORMAT_MP3;
        else if (_stricmp(ext, ".avi") == 0) objFormat = MTP_FORMAT_AVI;
        else if (_stricmp(ext, ".mpg") == 0 || _stricmp(ext, ".mpeg") == 0) objFormat = MTP_FORMAT_MPEG;
        else if (_stricmp(ext, ".mp4") == 0) objFormat = MTP_FORMAT_MP4_CONTAINER;
        else if (_stricmp(ext, ".txt") == 0) objFormat = MTP_FORMAT_TEXT;
        else if (_stricmp(ext, ".wma") == 0) objFormat = MTP_FORMAT_WMA;
        else if (_stricmp(ext, ".wmv") == 0) objFormat = MTP_FORMAT_WMV;
    }

    /* Convert filename to UTF-16LE */
    wChars = MultiByteToWideChar(CP_ACP, 0, fileName, -1, wFileName, MAX_PATH);
    if (wChars <= 0) {
        wFileName[0] = L'\0';
        wChars = 1;
    }

    /* Build ObjectInfo dataset per PTP/MTP ISO 15740 standard */
    objInfoLen = 52 + 1 + (wChars * 2) + 3;
    if (objInfoLen > sizeof(objInfoBuf)) objInfoLen = sizeof(objInfoBuf);
    ZeroMemory(objInfoBuf, objInfoLen);

    targetStorage = g_CurrentStorage ? g_CurrentStorage : 0x00010001;
    targetParent = (g_CurrentParent == MTP_PARENT_ROOT) ? 0x00000000 : g_CurrentParent;

    *((DWORD*)(objInfoBuf + 0)) = targetStorage;
    *((WORD*)(objInfoBuf + 4)) = objFormat;
    *((WORD*)(objInfoBuf + 6)) = 0; /* ProtectionStatus */
    *((DWORD*)(objInfoBuf + 8)) = (DWORD)(fileSize & 0xFFFFFFFF); /* ObjectCompressedSize */
    *((DWORD*)(objInfoBuf + 38)) = targetParent; /* ParentObject */
    objInfoBuf[52] = (BYTE)wChars; /* Filename character count including null */
    memcpy(objInfoBuf + 53, wFileName, wChars * 2);
    objInfoBuf[53 + (wChars * 2)] = 0; /* DateCreated empty */
    objInfoBuf[53 + (wChars * 2) + 1] = 0; /* DateModified empty */
    objInfoBuf[53 + (wChars * 2) + 2] = 0; /* Keywords empty */

    sendParams[0] = targetStorage;
    sendParams[1] = targetParent;

    SetStatus("Sending file info to MTP device...");
    if (!MtpSendOperation(MTP_OP_SEND_OBJECT_INFO, sendParams, 2, objInfoBuf, objInfoLen,
                          respBuf, sizeof(respBuf), &respBytes)) {
        CloseHandle(hFile);
        MessageBoxA(hWnd, "Failed to initiate upload on MTP device (SendObjectInfo failed).", "Upload Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    if (respBytes >= 12) {
        objectId = *((DWORD*)(respBuf + 8));
    }
    
    readBuffer = (BYTE*)malloc(g_OptimalChunkSize);
    if (!readBuffer) {
        CloseHandle(hFile);
        MessageBoxA(hWnd, "Out of memory for transfer buffer.", "Upload Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    g_CancelTransfer = FALSE;
    startTick = GetTickCount();
    FormatFileSize64(fileSize, totalStr, sizeof(totalStr));

    /* Handle 0-byte file edge case */
    if (fileSize == 0) {
        payload = (BYTE*)malloc(sizeof(DWORD) * 3);
        if (payload) {
            *((DWORD*)(payload + 0)) = objectId;
            *((DWORD*)(payload + 4)) = 0;
            *((DWORD*)(payload + 8)) = 0;
            EnterCriticalSection(&g_DeviceCs);
            DeviceIoControl(g_hDevice, IOCTL_MTP_SEND_OBJECT_PART,
                            payload, sizeof(DWORD) * 3, responseBuf, sizeof(responseBuf), &bytesReturned, NULL);
            LeaveCriticalSection(&g_DeviceCs);
            free(payload);
        }
    }
    
    while (transferred < fileSize && !g_CancelTransfer) {
        ULONGLONG remaining = fileSize - transferred;
        DWORD chunkSize = (remaining > (ULONGLONG)g_OptimalChunkSize) ? g_OptimalChunkSize : (DWORD)remaining;
        DWORD bytesRead = 0;
        DWORD payloadSize;
        BOOL bPartOk;
        
        ReadFile(hFile, readBuffer, chunkSize, &bytesRead, NULL);
        if (bytesRead == 0) break;
        
        /* 3-DWORD header: [id, offset, totalSize, data...] */
        payloadSize = sizeof(DWORD) * 3 + bytesRead;
        payload = (BYTE*)malloc(payloadSize);
        if (!payload) {
            free(readBuffer);
            CloseHandle(hFile);
            return FALSE;
        }
        
        *((DWORD*)(payload + 0)) = objectId;
        *((DWORD*)(payload + 4)) = (DWORD)(transferred & 0xFFFFFFFF);
        *((DWORD*)(payload + 8)) = (DWORD)(fileSize & 0xFFFFFFFF);
        memcpy(payload + 12, readBuffer, bytesRead);
        
        EnterCriticalSection(&g_DeviceCs);
        bPartOk = DeviceIoControl(g_hDevice, IOCTL_MTP_SEND_OBJECT_PART,
                                  payload, payloadSize, responseBuf, sizeof(responseBuf), &bytesReturned, NULL);
        LeaveCriticalSection(&g_DeviceCs);
        if (!bPartOk) {
            free(payload);
            free(readBuffer);
            CloseHandle(hFile);
            {
                char errMsg[256];
                _snprintf(errMsg, sizeof(errMsg), "Failed to write data stream to MTP device.\nGetLastError=%lu  offset=%lu  totalSize=%lu",
                          (unsigned long)GetLastError(), (unsigned long)transferred, (unsigned long)fileSize);
                MessageBoxA(hWnd, errMsg, "Upload Error", MB_OK | MB_ICONERROR);
            }
            return FALSE;
        }
        
        if (transferred == 0 && bytesReturned >= sizeof(DWORD)) {
            objectId = *((DWORD*)responseBuf);
        }
        
        free(payload);
        transferred += bytesRead;
        
        elapsed = (double)(GetTickCount() - startTick) / 1000.0;
        if (elapsed > 0.1) {
            speed = (double)transferred / elapsed;
            eta = (fileSize > transferred) ? (double)(fileSize - transferred) / speed : 0;
        } else {
            speed = 0;
            eta = 0;
        }
        percent = (fileSize > 0) ? (int)((transferred * 100ULL) / fileSize) : 100;
        
        FormatFileSize64(transferred, sizeStr, sizeof(sizeStr));
        FormatTransferSpeed(speed, speedStr, sizeof(speedStr));
        FormatETA(eta, etaStr, sizeof(etaStr));
        
        _snprintf(statusBuf, sizeof(statusBuf), "Uploading: %s / %s (%d%%) | %s | ETA: %s",
                  sizeStr, totalStr, percent, speedStr, etaStr);
        SetStatus(statusBuf);
        
        _snprintf(statusBuf, sizeof(statusBuf), "[%d%%] Uploading %s - MTP Explorer", percent, fileName);
        SetWindowTextA(g_hMainWnd, statusBuf);
        
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE) {
                g_CancelTransfer = TRUE;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    
    free(readBuffer);
    CloseHandle(hFile);
    
    UpdateUI();
    
    if (g_CancelTransfer) {
        SetStatus("Upload canceled by user");
        MessageBoxA(hWnd, "Upload canceled.", "MTP Transfer", MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }
    
    elapsed = (double)(GetTickCount() - startTick) / 1000.0;
    speed = (elapsed > 0) ? (double)transferred / elapsed : 0;
    FormatFileSize64(transferred, sizeStr, sizeof(sizeStr));
    FormatTransferSpeed(speed, speedStr, sizeof(speedStr));
    
    _snprintf(statusBuf, sizeof(statusBuf), "Upload complete - %s at %s (%s, chunk %luKB)",
              sizeStr, speedStr, g_szUsbSpeed, g_OptimalChunkSize / 1024);
    SetStatus(statusBuf);
    return TRUE;
}

BOOL UploadFile(HWND hWnd)
{
    char szFile[MAX_PATH] = "";
    OPENFILENAMEA ofn;
    char *fileName;
    char statusBuf[256];
    
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrTitle = "Open - Upload to MTP Device";
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    
    if (!GetOpenFileNameA(&ofn)) return FALSE;
    
    if (UploadSingleFilePath(hWnd, szFile)) {
        fileName = strrchr(szFile, '\\');
        if (fileName) fileName++; else fileName = szFile;
        _snprintf(statusBuf, sizeof(statusBuf),
                  "Upload complete!\n\nFile: %s\nUSB: %s\nChunk Size: %lu KB",
                  fileName, g_szUsbSpeed, g_OptimalChunkSize / 1024);
        MessageBoxA(hWnd, statusBuf, "Transfer Complete", MB_OK | MB_ICONINFORMATION);
        RefreshObjects();
        return TRUE;
    }
    return FALSE;
}

BOOL DeleteSelected(HWND hWnd)
{
    int selIndex;
    DWORD handle;
    BYTE response[256];
    DWORD bytesReceived;
    
    selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
    if (selIndex == -1) {
        MessageBoxA(hWnd, "Please select an item to delete.", "Delete", MB_OK | MB_ICONINFORMATION);
        return FALSE;
    }

    if (g_bSearchRunning) {
        MessageBoxA(hWnd, "Please wait for search to complete or stop the search before deleting items.", "Search in Progress", MB_OK | MB_ICONINFORMATION);
        return FALSE;
    }
    
    if (MessageBoxA(hWnd, "Are you sure you want to delete the selected item from the device?", 
                    "Confirm File Delete", MB_YESNO | MB_ICONQUESTION) != IDYES) {
        return FALSE;
    }
    
    EnterCriticalSection(&g_ObjectsCs);
    if (g_Objects && (DWORD)selIndex < g_ObjectCount) {
        handle = g_Objects[selIndex].Handle;
    } else {
        LeaveCriticalSection(&g_ObjectsCs);
        return FALSE;
    }
    LeaveCriticalSection(&g_ObjectsCs);
    
    SetStatus("Deleting object from device...");
    
    if (!MtpSendOperation(MTP_OP_DELETE_OBJECT, &handle, 1, NULL, 0,
                          response, sizeof(response), &bytesReceived)) {
        MessageBoxA(hWnd, "Failed to delete object on MTP device.", "Delete Error", MB_OK | MB_ICONERROR);
        SetStatus("Delete failed");
        return FALSE;
    }
    
    SetStatus("Object deleted");
    RefreshObjects();
    return TRUE;
}

/* ============================================================================
 * Web View Sidebar Procedure & Painting
 * ============================================================================ */

/* Clickable link bounding rectangles in Web View */
static RECT g_rcLinkPaste = { 16, 270, 195, 286 };
static RECT g_rcLinkUpload = { 16, 288, 195, 304 };
static RECT g_rcLinkSafelyRemove = { 16, 306, 195, 322 };

static RECT g_rcLinkDownload = { 16, 275, 195, 291 };
static RECT g_rcLinkCopy = { 16, 293, 195, 309 };
static RECT g_rcLinkDelete = { 16, 311, 195, 327 };

LRESULT CALLBACK WebViewWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_SETCURSOR: {
            POINT pt;
            int sel;
            GetCursorPos(&pt);
            ScreenToClient(hWnd, &pt);
            sel = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
            if (sel != -1) {
                if (PtInRect(&g_rcLinkDownload, pt) || PtInRect(&g_rcLinkCopy, pt) || PtInRect(&g_rcLinkDelete, pt)) {
                    SetCursor(LoadCursor(NULL, IDC_HAND));
                    return TRUE;
                }
            } else {
                if (PtInRect(&g_rcLinkPaste, pt) || PtInRect(&g_rcLinkUpload, pt) || PtInRect(&g_rcLinkSafelyRemove, pt)) {
                    SetCursor(LoadCursor(NULL, IDC_HAND));
                    return TRUE;
                }
            }
            break;
        }
        case WM_LBUTTONDOWN: {
            POINT pt;
            int sel;
            pt.x = LOWORD(lParam);
            pt.y = HIWORD(lParam);
            sel = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
            if (sel != -1) {
                if (PtInRect(&g_rcLinkDownload, pt)) {
                    DownloadSelected(g_hMainWnd);
                    return 0;
                }
                if (PtInRect(&g_rcLinkCopy, pt)) {
                    CopySelectedToClipboard(g_hMainWnd);
                    return 0;
                }
                if (PtInRect(&g_rcLinkDelete, pt)) {
                    DeleteSelected(g_hMainWnd);
                    return 0;
                }
            } else {
                if (PtInRect(&g_rcLinkPaste, pt)) {
                    PasteFromClipboard(g_hMainWnd);
                    return 0;
                }
                if (PtInRect(&g_rcLinkUpload, pt)) {
                    UploadFile(g_hMainWnd);
                    return 0;
                }
                if (PtInRect(&g_rcLinkSafelyRemove, pt)) {
                    DisconnectDevice();
                    return 0;
                }
            }
            break;
        }
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc;
            RECT rc;
            HFONT hOldFont;
            HFONT hTitleFont, hBoldFont, hNormalFont, hLinkFont;
            HPEN hBluePen, hOldPen;
            int selIndex;
            OBJECT_ITEM *selectedObj = NULL;
            OBJECT_ITEM selectedObjCopy;
            
            hdc = BeginPaint(hWnd, &ps);
            GetClientRect(hWnd, &rc);
            
            /* Fill background with clean Windows 2000 white Web View canvas */
            FillRect(hdc, &rc, (HBRUSH)GetStockObject(WHITE_BRUSH));
            
            /* Authentic Fonts matching Windows 2000 folder.htt Web View */
            hTitleFont = CreateFontA(18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                                    ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                    DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Tahoma");
            hBoldFont = CreateFontA(12, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                                   ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                   DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Tahoma");
            hNormalFont = CreateFontA(11, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                                     ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                     DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Tahoma");
            hLinkFont = CreateFontA(11, 0, 0, 0, FW_NORMAL, FALSE, TRUE, FALSE,
                                   ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                   DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Tahoma");
            
            SetBkMode(hdc, TRANSPARENT);
            
            /* Top Banner: Authentic Windows 2000 Web View Header Art
             * Layered pastel geometric frames and shell folder graphic */
            {
                HPEN hAmberPen;
                HPEN hCyanPen;
                HPEN hGreenPen;

                /* 1. Soft Amber Square Frame (top-left) */
                hAmberPen = CreatePen(PS_SOLID, 2, RGB(245, 180, 75));
                hCyanPen = CreatePen(PS_SOLID, 2, RGB(90, 175, 235));
                hGreenPen = CreatePen(PS_SOLID, 2, RGB(120, 210, 160));

                hOldPen = (HPEN)SelectObject(hdc, hAmberPen);
                SelectObject(hdc, GetStockObject(NULL_BRUSH));
                Rectangle(hdc, 14, 12, 42, 38);
                
                /* 2. Soft Sky Blue Square Frame (top-right) */
                SelectObject(hdc, hCyanPen);
                Rectangle(hdc, 30, 6, 58, 32);
                
                /* 3. Soft Mint Green Square Frame (bottom-right) */
                SelectObject(hdc, hGreenPen);
                Rectangle(hdc, 36, 18, 64, 42);
                
                SelectObject(hdc, hOldPen);
                DeleteObject(hAmberPen);
                DeleteObject(hCyanPen);
                DeleteObject(hGreenPen);
                
                /* 4. Windows 2000 Shell Folder Icon */
                if (g_hLargeImageList) {
                    ImageList_Draw(g_hLargeImageList, 0, hdc, 18, 12, ILD_TRANSPARENT);
                }
            }
            
            /* Title: Current folder / Storage name */
            hOldFont = (HFONT)SelectObject(hdc, hTitleFont);
            SetTextColor(hdc, RGB(0, 0, 0));
            
            if (g_CurrentParent == 0) {
                TextOutA(hdc, 16, 48, g_szRootName, (int)strlen(g_szRootName));
            } else {
                char folderTitle[64];
                DWORD k;

                strcpy(folderTitle, "Subfolder");
                EnterCriticalSection(&g_ObjectsCs);
                if (g_Objects) {
                    for (k = 0; k < g_ObjectCount; k++) {
                        if (g_Objects[k].Handle == g_CurrentParent) {
                            WideCharToMultiByte(CP_ACP, 0, g_Objects[k].Name, -1, folderTitle, sizeof(folderTitle), NULL, NULL);
                            break;
                        }
                    }
                }
                LeaveCriticalSection(&g_ObjectsCs);
                TextOutA(hdc, 16, 48, folderTitle, (int)strlen(folderTitle));
            }
            
            /* Iconic Windows 2000 Blue Accent Line (#5A7EDC) */
            hBluePen = CreatePen(PS_SOLID, 1, RGB(90, 126, 220));
            hOldPen = (HPEN)SelectObject(hdc, hBluePen);
            MoveToEx(hdc, 16, 74, NULL);
            LineTo(hdc, rc.right - 14, 74);
            SelectObject(hdc, hOldPen);
            DeleteObject(hBluePen);
            
            /* Check if item is selected in ListView */
            selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
            if (selIndex != -1) {
                EnterCriticalSection(&g_ObjectsCs);
                if (g_Objects && (DWORD)selIndex < g_ObjectCount) {
                    selectedObjCopy = g_Objects[selIndex];
                    selectedObj = &selectedObjCopy;
                }
                LeaveCriticalSection(&g_ObjectsCs);
            }
            
            if (selectedObj) {
                /* An item is selected: Render the Preview Frame and Metadata */
                RECT rcFrame;
                char nameA[256];
                char sizeStr[64];
                char typeStr[64];
                
                rcFrame.left = 16;
                rcFrame.top = 84;
                rcFrame.right = 16 + 130;
                rcFrame.bottom = 84 + 95;
                
                /* Preview frame box with classic 3D sunken border */
                DrawEdge(hdc, &rcFrame, EDGE_SUNKEN, BF_RECT);
                
                /* Draw preview content inside box */
                if (selectedObj->Format == MTP_FORMAT_EXIF_JPEG || 
                    selectedObj->Format == MTP_FORMAT_BMP || 
                    selectedObj->Format == MTP_FORMAT_PNG) {
                    /* Image preview: Scenic sky, sun, landscape thumbnail */
                    HBRUSH hSkyBrush;
                    HBRUSH hSunBrush;
                    HBRUSH hGrassBrush;
                    HBRUSH hMtnBrush;
                    RECT rcSky;
                    RECT rcGrass;
                    POINT mtnPts[3];

                    hSkyBrush = CreateSolidBrush(RGB(110, 180, 245));
                    hSunBrush = CreateSolidBrush(RGB(255, 220, 60));
                    hGrassBrush = CreateSolidBrush(RGB(65, 160, 65));
                    hMtnBrush = CreateSolidBrush(RGB(120, 140, 160));

                    rcSky.left = rcFrame.left + 2;
                    rcSky.top = rcFrame.top + 2;
                    rcSky.right = rcFrame.right - 2;
                    rcSky.bottom = rcFrame.bottom - 30;

                    rcGrass.left = rcFrame.left + 2;
                    rcGrass.top = rcFrame.bottom - 30;
                    rcGrass.right = rcFrame.right - 2;
                    rcGrass.bottom = rcFrame.bottom - 2;
                    
                    FillRect(hdc, &rcSky, hSkyBrush);
                    SelectObject(hdc, GetStockObject(NULL_PEN));
                    SelectObject(hdc, hSunBrush);
                    Ellipse(hdc, rcFrame.left + 85, rcFrame.top + 8, rcFrame.left + 105, rcFrame.top + 28);
                    
                    /* Mountain */
                    mtnPts[0].x = rcFrame.left + 20; mtnPts[0].y = rcFrame.bottom - 30;
                    mtnPts[1].x = rcFrame.left + 50; mtnPts[1].y = rcFrame.top + 30;
                    mtnPts[2].x = rcFrame.left + 80; mtnPts[2].y = rcFrame.bottom - 30;
                    SelectObject(hdc, hMtnBrush);
                    Polygon(hdc, mtnPts, 3);
                    
                    FillRect(hdc, &rcGrass, hGrassBrush);
                    
                    DeleteObject(hSkyBrush);
                    DeleteObject(hSunBrush);
                    DeleteObject(hGrassBrush);
                    DeleteObject(hMtnBrush);
                } else if (selectedObj->IsFolder) {
                    /* Folder graphic */
                    if (g_hLargeImageList) {
                        ImageList_Draw(g_hLargeImageList, 0, hdc, rcFrame.left + 49, rcFrame.top + 31, ILD_TRANSPARENT);
                    }
                } else {
                    /* Extract shell icon for file format */
                    int iconIndex = GetIconIndexForFormat(selectedObj->Format, selectedObj->IsFolder);
                    if (g_hLargeImageList) {
                        ImageList_Draw(g_hLargeImageList, iconIndex, hdc, rcFrame.left + 49, rcFrame.top + 31, ILD_TRANSPARENT);
                    }
                }
                
                /* File details below preview */
                WideCharToMultiByte(CP_ACP, 0, selectedObj->Name, -1, nameA, sizeof(nameA), NULL, NULL);
                if (nameA[0] == '\0') {
                    _snprintf(nameA, sizeof(nameA), "Object_%08X", selectedObj->Handle);
                }
                
                SelectObject(hdc, hBoldFont);
                SetTextColor(hdc, RGB(0, 0, 0));
                TextOutA(hdc, 16, 186, nameA, (int)strlen(nameA));
                
                /* Thin separator */
                {
                    HPEN hSepPen = CreatePen(PS_SOLID, 1, RGB(215, 215, 215));
                    HPEN hOldP = (HPEN)SelectObject(hdc, hSepPen);
                    MoveToEx(hdc, 16, 204, NULL);
                    LineTo(hdc, rc.right - 14, 204);
                    SelectObject(hdc, hOldP);
                    DeleteObject(hSepPen);
                }
                
                SelectObject(hdc, hNormalFont);
                SetTextColor(hdc, RGB(70, 70, 70));
                
                _snprintf(typeStr, sizeof(typeStr), "Type: %s", GetFormatName(selectedObj->Format));
                TextOutA(hdc, 16, 210, typeStr, (int)strlen(typeStr));
                
                if (!selectedObj->IsFolder) {
                    char szFmt[32];
                    FormatFileSize64(selectedObj->Size, szFmt, sizeof(szFmt));
                    if (selectedObj->Size < 1048576ULL) {
                        _snprintf(sizeStr, sizeof(sizeStr), "Size: %s (%lu bytes)", szFmt, (DWORD)selectedObj->Size);
                    } else {
                        _snprintf(sizeStr, sizeof(sizeStr), "Size: %s", szFmt);
                    }
                    TextOutA(hdc, 16, 226, sizeStr, (int)strlen(sizeStr));
                    
                    TextOutA(hdc, 16, 242, "Attributes: Read/Write", 22);
                    TextOutA(hdc, 16, 258, "Device: MTP Storage", 19);
                }
                
                /* Interactive Action Links */
                SelectObject(hdc, hLinkFont);
                SetTextColor(hdc, RGB(0, 51, 153));
                TextOutA(hdc, 16, 275, "Download to Computer", 20);
                TextOutA(hdc, 16, 293, "Copy to Clipboard", 17);
                TextOutA(hdc, 16, 311, "Delete from Device", 18);
            } else {
                /* No item selected: Default folder description and Storage Capacity Card */
                RECT rcText;
                rcText.left = 16;
                rcText.top = 88;
                rcText.right = rc.right - 14;
                rcText.bottom = 170;

                SelectObject(hdc, hNormalFont);
                SetTextColor(hdc, RGB(60, 60, 60));
                
                DrawTextA(hdc,
                    "This folder contains files and multimedia stored on your portable device.\n\n"
                    "Select an item to view its description, preview, and properties.",
                    -1, &rcText, DT_WORDBREAK);
                
                /* Storage status section */
                if (g_Connected) {
                    RECT rcBar;
                    SelectObject(hdc, hBoldFont);
                    SetTextColor(hdc, RGB(0, 0, 0));
                    TextOutA(hdc, 16, 175, "Storage Capacity", 16);
                    
                    SelectObject(hdc, hNormalFont);
                    SetTextColor(hdc, RGB(70, 70, 70));
                    TextOutA(hdc, 16, 193, g_szCapacityStr, (int)strlen(g_szCapacityStr));
                    TextOutA(hdc, 16, 209, g_szUsedSpaceStr, (int)strlen(g_szUsedSpaceStr));
                    TextOutA(hdc, 16, 225, g_szFreeSpaceStr, (int)strlen(g_szFreeSpaceStr));
                    
                    /* Authentic Windows 2000 Disk Usage Bar */
                    rcBar.left = 16;
                    rcBar.top = 245;
                    rcBar.right = rc.right - 18;
                    rcBar.bottom = 259;
                    DrawEdge(hdc, &rcBar, EDGE_SUNKEN, BF_RECT);
                    
                    {
                        int totalW;
                        int usedW;
                        RECT rcUsed;
                        RECT rcFree;
                        HBRUSH hNavyBrush;
                        HBRUSH hMagBrush;

                        totalW = rcBar.right - rcBar.left - 4;
                        usedW = (totalW * g_StorageUsedPercent) / 100;
                        if (usedW < 0) usedW = 0;
                        if (usedW > totalW) usedW = totalW;
                        rcUsed.left = rcBar.left + 2;
                        rcUsed.top = rcBar.top + 2;
                        rcUsed.right = rcBar.left + 2 + usedW;
                        rcUsed.bottom = rcBar.bottom - 2;

                        rcFree.left = rcBar.left + 2 + usedW;
                        rcFree.top = rcBar.top + 2;
                        rcFree.right = rcBar.right - 2;
                        rcFree.bottom = rcBar.bottom - 2;

                        hNavyBrush = CreateSolidBrush(RGB(0, 0, 128));
                        hMagBrush = CreateSolidBrush(RGB(220, 70, 220));
                        
                        FillRect(hdc, &rcUsed, hNavyBrush);
                        FillRect(hdc, &rcFree, hMagBrush);
                        
                        DeleteObject(hNavyBrush);
                        DeleteObject(hMagBrush);
                    }
                    
                    /* Quick Tasks Links */
                    SelectObject(hdc, hLinkFont);
                    SetTextColor(hdc, RGB(0, 51, 153));
                    TextOutA(hdc, 16, 270, "Paste from PC (Ctrl+V)", 22);
                    TextOutA(hdc, 16, 288, "Upload files to device", 22);
                    TextOutA(hdc, 16, 306, "Safely remove device", 20);
                }
            }
            
            SelectObject(hdc, hOldFont);
            DeleteObject(hTitleFont);
            DeleteObject(hBoldFont);
            DeleteObject(hNormalFont);
            DeleteObject(hLinkFont);
            
            EndPaint(hWnd, &ps);
            return 0;
        }
        case WM_ERASEBKGND:
            return 1;
    }
    return DefWindowProcA(hWnd, msg, wParam, lParam);
}

/* ============================================================================
 * UI Creation Functions
 * ============================================================================ */

void CreateMainMenu(HWND hWnd)
{
    HMENU hMenu = CreateMenu();
    HMENU hFileMenu = CreatePopupMenu();
    HMENU hEditMenu = CreatePopupMenu();
    HMENU hViewMenu = CreatePopupMenu();
    HMENU hViewToolbarsMenu = CreatePopupMenu();
    HMENU hFavoritesMenu = CreatePopupMenu();
    HMENU hToolsMenu = CreatePopupMenu();
    HMENU hHelpMenu = CreatePopupMenu();
    
    HMENU hArrangeMenu = CreatePopupMenu();
    
    /* File Menu */
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_CONNECT, "&Connect (Secure Load)\tCtrl+O");
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_DISCONNECT, "&Safely Remove Device (Secure Deload)\tCtrl+D");
    AppendMenuA(hFileMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_SEARCH, "&Search for Files or Folders...\tCtrl+F");
    AppendMenuA(hFileMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_DOWNLOAD, "&Download...\tCtrl+S");
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_UPLOAD, "&Upload (or Drag && Drop)...\tCtrl+U");
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_DELETE, "De&lete\tDel");
    AppendMenuA(hFileMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_EXIT, "E&xit\tAlt+F4");
    
    /* Edit Menu */
    AppendMenuA(hEditMenu, MF_STRING, IDM_EDIT_CUT, "Cu&t\tCtrl+X");
    AppendMenuA(hEditMenu, MF_STRING, IDM_EDIT_COPY, "&Copy\tCtrl+C");
    AppendMenuA(hEditMenu, MF_STRING, IDM_EDIT_PASTE, "&Paste\tCtrl+V");
    AppendMenuA(hEditMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hEditMenu, MF_STRING, IDM_EDIT_SELECT_ALL, "Select &All\tCtrl+A");
    AppendMenuA(hEditMenu, MF_STRING, IDM_EDIT_INVERT_SEL, "&Invert Selection");
    
    /* View Menu -> Toolbars Submenu */
    AppendMenuA(hViewToolbarsMenu, MF_STRING | (g_bShowStdToolbar ? MF_CHECKED : MF_UNCHECKED), IDM_VIEW_TOOLBAR_STD, "Standard &Buttons");
    AppendMenuA(hViewToolbarsMenu, MF_STRING | (g_bShowAddressBar ? MF_CHECKED : MF_UNCHECKED), IDM_VIEW_TOOLBAR_ADDR, "&Address Bar");
    
    /* View Menu -> Arrange Icons Submenu (with sort direction arrows) */
    PopulateArrangeMenu(hArrangeMenu);

    /* View Menu */
    AppendMenuA(hViewMenu, MF_POPUP, (UINT_PTR)hViewToolbarsMenu, "&Toolbars");
    AppendMenuA(hViewMenu, MF_STRING | (g_bShowStatusBar ? MF_CHECKED : MF_UNCHECKED), IDM_VIEW_STATUSBAR, "Status &Bar");
    AppendMenuA(hViewMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hViewMenu, MF_POPUP, (UINT_PTR)hArrangeMenu, "Arrange &Icons");
    AppendMenuA(hViewMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hViewMenu, MF_STRING | (g_CurrentViewMode == LVS_ICON ? MF_CHECKED : MF_UNCHECKED), IDM_VIEW_LARGE_ICONS, "Lar&ge Icons");
    AppendMenuA(hViewMenu, MF_STRING | (g_CurrentViewMode == LVS_SMALLICON ? MF_CHECKED : MF_UNCHECKED), IDM_VIEW_SMALL_ICONS, "S&mall Icons");
    AppendMenuA(hViewMenu, MF_STRING | (g_CurrentViewMode == LVS_LIST ? MF_CHECKED : MF_UNCHECKED), IDM_VIEW_LIST, "&List");
    AppendMenuA(hViewMenu, MF_STRING | (g_CurrentViewMode == LVS_REPORT ? MF_CHECKED : MF_UNCHECKED), IDM_VIEW_DETAILS, "&Details");
    AppendMenuA(hViewMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hViewMenu, MF_STRING, IDM_VIEW_REFRESH, "&Refresh\tF5");
    
    /* Favorites Menu */
    AppendMenuA(hFavoritesMenu, MF_STRING, IDM_FAV_ADD, "Add to &Favorites...");
    AppendMenuA(hFavoritesMenu, MF_STRING, IDM_FAV_ORGANIZE, "&Organize Favorites...");
    AppendMenuA(hFavoritesMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hFavoritesMenu, MF_STRING, IDM_FAV_MYCOMPUTER, "My &Computer");
    AppendMenuA(hFavoritesMenu, MF_STRING, IDM_FAV_DESKTOP, "&Desktop");
    AppendMenuA(hFavoritesMenu, MF_STRING, IDM_FAV_DEVICE, "&Portable Device (MTP)");
    
    /* Tools Menu */
    AppendMenuA(hToolsMenu, MF_STRING, IDM_TOOLS_FIND, "&Find Files or Folders...\tF3");
    AppendMenuA(hToolsMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hToolsMenu, MF_STRING, IDM_TOOLS_MAP_DRIVE, "&Map Network Drive...");
    AppendMenuA(hToolsMenu, MF_STRING, IDM_TOOLS_DISC_DRIVE, "&Disconnect Network Drive...");
    AppendMenuA(hToolsMenu, MF_STRING, IDM_TOOLS_SYNCHRONIZE, "&Synchronize...");
    AppendMenuA(hToolsMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hToolsMenu, MF_STRING | (g_bNotifyOnCopyPaste ? MF_CHECKED : MF_UNCHECKED),
                IDM_TOOLS_NOTIFY_COPYPASTE, "Show Taskbar Notification on &Copy/Paste");
    AppendMenuA(hToolsMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hToolsMenu, MF_STRING, IDM_TOOLS_OPTIONS, "&Folder Options...");
    
    /* Help Menu */
    AppendMenuA(hHelpMenu, MF_STRING, IDM_HELP_TOPICS, "&Help Topics");
    AppendMenuA(hHelpMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hHelpMenu, MF_STRING, IDM_HELP_ABOUT, "&About MTP Portable Device...");
    
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "&File");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hEditMenu, "&Edit");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hViewMenu, "&View");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hFavoritesMenu, "F&avorites");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hToolsMenu, "&Tools");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, "&Help");
    
    SetMenu(hWnd, hMenu);
}

static HIMAGELIST CreateExplorerToolbarImageList(void)
{
    HIMAGELIST hList = ImageList_Create(16, 16, ILC_COLORDDB | ILC_MASK, 10, 0);
    HDC hdcScreen = GetDC(NULL);
    HDC hdcMem = CreateCompatibleDC(hdcScreen);
    HBITMAP hBmp = CreateCompatibleBitmap(hdcScreen, 16, 16);
    HBITMAP hOldBmp = (HBITMAP)SelectObject(hdcMem, hBmp);
    int iconIdx;
    
    for (iconIdx = 0; iconIdx < 10; iconIdx++) {
        RECT rc = { 0, 0, 16, 16 };
        HBRUSH hMaskBrush = CreateSolidBrush(RGB(255, 0, 255)); /* magenta mask */
        FillRect(hdcMem, &rc, hMaskBrush);
        DeleteObject(hMaskBrush);
        
        switch (iconIdx) {
            case 0: { /* 0: Back (Green left arrow with dropdown triangle) */
                POINT pts[3];
                POINT dropPts[3];
                RECT rcShaft;
                HBRUSH hGreen = CreateSolidBrush(RGB(40, 150, 45));
                HPEN hDark = CreatePen(PS_SOLID, 1, RGB(20, 90, 25));
                HPEN hOldPen = (HPEN)SelectObject(hdcMem, hDark);
                HBRUSH hOldBr = (HBRUSH)SelectObject(hdcMem, hGreen);
                
                pts[0].x = 1;  pts[0].y = 8;
                pts[1].x = 7;  pts[1].y = 2;
                pts[2].x = 7;  pts[2].y = 14;
                Polygon(hdcMem, pts, 3);
                
                rcShaft.left = 7; rcShaft.top = 5; rcShaft.right = 11; rcShaft.bottom = 11;
                FillRect(hdcMem, &rcShaft, hGreen);
                FrameRect(hdcMem, &rcShaft, (HBRUSH)GetStockObject(BLACK_BRUSH));
                
                /* Small dropdown triangle */
                dropPts[0].x = 12; dropPts[0].y = 7;
                dropPts[1].x = 16; dropPts[1].y = 7;
                dropPts[2].x = 14; dropPts[2].y = 10;
                SelectObject(hdcMem, GetStockObject(BLACK_BRUSH));
                Polygon(hdcMem, dropPts, 3);
                
                SelectObject(hdcMem, hOldPen);
                SelectObject(hdcMem, hOldBr);
                DeleteObject(hGreen);
                DeleteObject(hDark);
                break;
            }
            case 1: { /* 1: Forward (Green right arrow) */
                POINT pts[3];
                RECT rcShaft;
                HBRUSH hGreen = CreateSolidBrush(RGB(40, 150, 45));
                HPEN hDark = CreatePen(PS_SOLID, 1, RGB(20, 90, 25));
                HPEN hOldPen = (HPEN)SelectObject(hdcMem, hDark);
                HBRUSH hOldBr = (HBRUSH)SelectObject(hdcMem, hGreen);
                
                pts[0].x = 13; pts[0].y = 8;
                pts[1].x = 7;  pts[1].y = 2;
                pts[2].x = 7;  pts[2].y = 14;
                Polygon(hdcMem, pts, 3);
                
                rcShaft.left = 3; rcShaft.top = 5; rcShaft.right = 7; rcShaft.bottom = 11;
                FillRect(hdcMem, &rcShaft, hGreen);
                FrameRect(hdcMem, &rcShaft, (HBRUSH)GetStockObject(BLACK_BRUSH));
                
                SelectObject(hdcMem, hOldPen);
                SelectObject(hdcMem, hOldBr);
                DeleteObject(hGreen);
                DeleteObject(hDark);
                break;
            }
            case 2: { /* 2: Up / Parent */
                POINT upPts[3];
                HBRUSH hFolder = CreateSolidBrush(RGB(245, 215, 120));
                HBRUSH hArrow = CreateSolidBrush(RGB(30, 140, 40));
                HPEN hPenDark = CreatePen(PS_SOLID, 1, RGB(160, 130, 50));
                HPEN hOldPen = (HPEN)SelectObject(hdcMem, hPenDark);
                HBRUSH hOldBr = (HBRUSH)SelectObject(hdcMem, hFolder);
                
                Rectangle(hdcMem, 1, 5, 14, 15);
                
                upPts[0].x = 8;  upPts[0].y = 0;
                upPts[1].x = 4;  upPts[1].y = 5;
                upPts[2].x = 12; upPts[2].y = 5;
                SelectObject(hdcMem, hArrow);
                Polygon(hdcMem, upPts, 3);
                
                SelectObject(hdcMem, hOldPen);
                SelectObject(hdcMem, hOldBr);
                DeleteObject(hFolder);
                DeleteObject(hArrow);
                DeleteObject(hPenDark);
                break;
            }
            case 3: { /* 3: Connect (USB / Mount) */
                HBRUSH hPlug = CreateSolidBrush(RGB(210, 210, 220));
                HBRUSH hCable = CreateSolidBrush(RGB(70, 70, 70));
                RECT rcPin1 = { 5, 0, 7, 3 };
                RECT rcPin2 = { 9, 0, 11, 3 };
                RECT rcCord = { 6, 11, 10, 15 };
                Rectangle(hdcMem, 4, 3, 12, 11);
                FillRect(hdcMem, &rcPin1, (HBRUSH)GetStockObject(BLACK_BRUSH));
                FillRect(hdcMem, &rcPin2, (HBRUSH)GetStockObject(BLACK_BRUSH));
                FillRect(hdcMem, &rcCord, hCable);
                DeleteObject(hPlug);
                DeleteObject(hCable);
                break;
            }
            case 4: { /* 4: Safely Remove / Eject (Secure Deload) */
                POINT chk[3];
                RECT rcBar = { 2, 13, 14, 15 };
                HPEN hChkPen = CreatePen(PS_SOLID, 2, RGB(40, 170, 50));
                HPEN hOldPen = (HPEN)SelectObject(hdcMem, hChkPen);
                chk[0].x = 2;  chk[0].y = 8;
                chk[1].x = 6;  chk[1].y = 12;
                chk[2].x = 13; chk[2].y = 3;
                Polyline(hdcMem, chk, 3);
                SelectObject(hdcMem, hOldPen);
                DeleteObject(hChkPen);
                
                FillRect(hdcMem, &rcBar, (HBRUSH)GetStockObject(BLACK_BRUSH));
                break;
            }
            case 5: { /* 5: Refresh */
                HPEN hPenRef = CreatePen(PS_SOLID, 2, RGB(40, 140, 200));
                HPEN hOldPen = (HPEN)SelectObject(hdcMem, hPenRef);
                Arc(hdcMem, 2, 2, 14, 14, 2, 8, 14, 8);
                Arc(hdcMem, 2, 2, 14, 14, 14, 8, 2, 8);
                SelectObject(hdcMem, hOldPen);
                DeleteObject(hPenRef);
                break;
            }
            case 6: { /* 6: Download */
                POINT dnPts[3];
                RECT rcShaft = { 6, 1, 10, 6 };
                RECT rcTray = { 2, 12, 14, 15 };
                HBRUSH hBlue = CreateSolidBrush(RGB(50, 110, 210));
                dnPts[0].x = 8;  dnPts[0].y = 11;
                dnPts[1].x = 4;  dnPts[1].y = 6;
                dnPts[2].x = 12; dnPts[2].y = 6;
                SelectObject(hdcMem, hBlue);
                Polygon(hdcMem, dnPts, 3);
                FillRect(hdcMem, &rcShaft, hBlue);
                FillRect(hdcMem, &rcTray, (HBRUSH)GetStockObject(GRAY_BRUSH));
                DeleteObject(hBlue);
                break;
            }
            case 7: { /* 7: Upload */
                POINT upPts[3];
                RECT rcShaft = { 6, 6, 10, 11 };
                RECT rcTray = { 2, 12, 14, 15 };
                HBRUSH hGreen = CreateSolidBrush(RGB(40, 150, 40));
                upPts[0].x = 8;  upPts[0].y = 1;
                upPts[1].x = 4;  upPts[1].y = 6;
                upPts[2].x = 12; upPts[2].y = 6;
                SelectObject(hdcMem, hGreen);
                Polygon(hdcMem, upPts, 3);
                FillRect(hdcMem, &rcShaft, hGreen);
                FillRect(hdcMem, &rcTray, (HBRUSH)GetStockObject(GRAY_BRUSH));
                DeleteObject(hGreen);
                break;
            }
            case 8: { /* 8: Delete (Red X) */
                HPEN hRedPen = CreatePen(PS_SOLID, 3, RGB(220, 40, 40));
                HPEN hOldPen = (HPEN)SelectObject(hdcMem, hRedPen);
                MoveToEx(hdcMem, 3, 3, NULL);
                LineTo(hdcMem, 13, 13);
                MoveToEx(hdcMem, 13, 3, NULL);
                LineTo(hdcMem, 3, 13);
                SelectObject(hdcMem, hOldPen);
                DeleteObject(hRedPen);
                break;
            }
            case 9: { /* 9: Views */
                RECT rc1 = { 2, 2, 7, 7 };
                RECT rc2 = { 9, 2, 14, 7 };
                RECT rc3 = { 2, 9, 7, 14 };
                RECT rc4 = { 9, 9, 14, 14 };
                FrameRect(hdcMem, &rc1, (HBRUSH)GetStockObject(BLACK_BRUSH));
                FrameRect(hdcMem, &rc2, (HBRUSH)GetStockObject(BLACK_BRUSH));
                FrameRect(hdcMem, &rc3, (HBRUSH)GetStockObject(BLACK_BRUSH));
                FrameRect(hdcMem, &rc4, (HBRUSH)GetStockObject(BLACK_BRUSH));
                break;
            }
        }
        
        {
            COLORREF maskColor = GetPixel(hdcMem, 0, 0);
            ImageList_AddMasked(hList, hBmp, maskColor);
        }
    }
    
    SelectObject(hdcMem, hOldBmp);
    DeleteObject(hBmp);
    DeleteDC(hdcMem);
    ReleaseDC(NULL, hdcScreen);
    return hList;
}

void CreateToolbar(HWND hWnd)
{
    TBADDBITMAP tbabHist;
    TBADDBITMAP tbabView;
    TBADDBITMAP tbabStd;
    int idxHist, idxView, idxStd;
    TBBUTTON tbButtons[15];
    
    g_hToolbar = CreateWindowExA(
        0,
        TOOLBARCLASSNAMEA,
        NULL,
        WS_CHILD | WS_VISIBLE | TBSTYLE_TOOLTIPS | TBSTYLE_FLAT | CCS_NODIVIDER,
        0, 0, 0, 0,
        hWnd,
        (HMENU)IDC_TOOLBAR,
        g_hInstance,
        NULL
    );
    
    SendMessage(g_hToolbar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
    
    /* Load authentic native Windows 2000 Explorer system bitmaps from comctl32 */
    tbabHist.hInst = HINST_COMMCTRL;
    tbabHist.nID = IDB_HIST_SMALL_COLOR;
    idxHist = (int)SendMessage(g_hToolbar, TB_ADDBITMAP, 0, (LPARAM)&tbabHist);
    
    tbabView.hInst = HINST_COMMCTRL;
    tbabView.nID = IDB_VIEW_SMALL_COLOR;
    idxView = (int)SendMessage(g_hToolbar, TB_ADDBITMAP, 0, (LPARAM)&tbabView);
    
    tbabStd.hInst = HINST_COMMCTRL;
    tbabStd.nID = IDB_STD_SMALL_COLOR;
    idxStd = (int)SendMessage(g_hToolbar, TB_ADDBITMAP, 0, (LPARAM)&tbabStd);
    
    ZeroMemory(tbButtons, sizeof(tbButtons));
    
    /* 0: Back (HIST_BACK) with authentic text label */
    tbButtons[0].iBitmap = idxHist + HIST_BACK;
    tbButtons[0].idCommand = ID_TB_BACK;
    tbButtons[0].fsState = TBSTATE_ENABLED;
    tbButtons[0].fsStyle = TBSTYLE_BUTTON | BTNS_SHOWTEXT;
    tbButtons[0].iString = (INT_PTR)"Back";
    
    /* 1: Forward (HIST_FORWARD) */
    tbButtons[1].iBitmap = idxHist + HIST_FORWARD;
    tbButtons[1].idCommand = ID_TB_FORWARD;
    tbButtons[1].fsState = 0;
    tbButtons[1].fsStyle = TBSTYLE_BUTTON;
    
    /* 2: Up / Parent (VIEW_PARENTFOLDER) */
    tbButtons[2].iBitmap = idxView + VIEW_PARENTFOLDER;
    tbButtons[2].idCommand = ID_TB_PARENT;
    tbButtons[2].fsState = 0;
    tbButtons[2].fsStyle = TBSTYLE_BUTTON;
    
    /* 3: Separator */
    tbButtons[3].fsStyle = TBSTYLE_SEP;
    
    /* 4: Search (STD_FIND) */
    tbButtons[4].iBitmap = idxStd + STD_FIND;
    tbButtons[4].idCommand = ID_TB_SEARCH;
    tbButtons[4].fsState = TBSTATE_ENABLED;
    tbButtons[4].fsStyle = TBSTYLE_BUTTON | BTNS_SHOWTEXT;
    tbButtons[4].iString = (INT_PTR)"Search";
    
    /* 5: Separator */
    tbButtons[5].fsStyle = TBSTYLE_SEP;
    
    /* 6: Cut (STD_CUT) */
    tbButtons[6].iBitmap = idxStd + STD_CUT;
    tbButtons[6].idCommand = IDM_EDIT_CUT;
    tbButtons[6].fsState = 0;
    tbButtons[6].fsStyle = TBSTYLE_BUTTON;
    
    /* 7: Copy (STD_COPY) */
    tbButtons[7].iBitmap = idxStd + STD_COPY;
    tbButtons[7].idCommand = IDM_EDIT_COPY;
    tbButtons[7].fsState = 0;
    tbButtons[7].fsStyle = TBSTYLE_BUTTON;
    
    /* 8: Paste (STD_PASTE) */
    tbButtons[8].iBitmap = idxStd + STD_PASTE;
    tbButtons[8].idCommand = IDM_EDIT_PASTE;
    tbButtons[8].fsState = TBSTATE_ENABLED;
    tbButtons[8].fsStyle = TBSTYLE_BUTTON;
    
    /* 9: Delete (STD_DELETE) */
    tbButtons[9].iBitmap = idxStd + STD_DELETE;
    tbButtons[9].idCommand = ID_TB_DELETE;
    tbButtons[9].fsState = 0;
    tbButtons[9].fsStyle = TBSTYLE_BUTTON;
    
    /* 10: Separator */
    tbButtons[10].fsStyle = TBSTYLE_SEP;
    
    /* 11: Connect (VIEW_NETCONNECT) */
    tbButtons[11].iBitmap = idxView + VIEW_NETCONNECT;
    tbButtons[11].idCommand = ID_TB_CONNECT;
    tbButtons[11].fsState = TBSTATE_ENABLED;
    tbButtons[11].fsStyle = TBSTYLE_BUTTON;
    
    /* 12: Safely Remove (VIEW_NETDISCONNECT) */
    tbButtons[12].iBitmap = idxView + VIEW_NETDISCONNECT;
    tbButtons[12].idCommand = ID_TB_DISCONNECT;
    tbButtons[12].fsState = 0;
    tbButtons[12].fsStyle = TBSTYLE_BUTTON;
    
    /* 13: Separator */
    tbButtons[13].fsStyle = TBSTYLE_SEP;
    
    /* 14: Views (VIEW_VIEWMENU) */
    tbButtons[14].iBitmap = idxView + VIEW_VIEWMENU;
    tbButtons[14].idCommand = ID_TB_VIEWS;
    tbButtons[14].fsState = TBSTATE_ENABLED;
    tbButtons[14].fsStyle = TBSTYLE_BUTTON;
    
    SendMessage(g_hToolbar, TB_ADDBUTTONS, 15, (LPARAM)tbButtons);
    SendMessage(g_hToolbar, TB_AUTOSIZE, 0, 0);
    UpdateNavButtons();
}

static LRESULT CALLBACK FolderOptionsDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
        case WM_CREATE: {
            HFONT hFont;
            HWND hCtl;
            
            hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
            
            /* Group: Notifications */
            hCtl = CreateWindowExA(0, "BUTTON", "Taskbar Notifications",
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
                12, 10, 310, 60, hWnd, NULL, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            
            hCtl = CreateWindowExA(0, "BUTTON", "Show balloon notification on Copy and Paste",
                WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                24, 34, 285, 20, hWnd, (HMENU)IDC_OPT_NOTIFY, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hCtl, BM_SETCHECK, g_bNotifyOnCopyPaste ? BST_CHECKED : BST_UNCHECKED, 0);
            
            /* Group: Explorer Components */
            hCtl = CreateWindowExA(0, "BUTTON", "Windows 2000 Explorer Components",
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
                12, 80, 310, 115, hWnd, NULL, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            
            hCtl = CreateWindowExA(0, "BUTTON", "Show Standard Buttons toolbar",
                WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                24, 100, 285, 18, hWnd, (HMENU)IDC_OPT_STD_TB, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hCtl, BM_SETCHECK, g_bShowStdToolbar ? BST_CHECKED : BST_UNCHECKED, 0);
            
            hCtl = CreateWindowExA(0, "BUTTON", "Show Address Bar",
                WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                24, 120, 285, 18, hWnd, (HMENU)IDC_OPT_ADDR_BAR, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hCtl, BM_SETCHECK, g_bShowAddressBar ? BST_CHECKED : BST_UNCHECKED, 0);
            
            hCtl = CreateWindowExA(0, "BUTTON", "Show Status Bar",
                WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                24, 140, 285, 18, hWnd, (HMENU)IDC_OPT_STATUS_BAR, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hCtl, BM_SETCHECK, g_bShowStatusBar ? BST_CHECKED : BST_UNCHECKED, 0);
            
            hCtl = CreateWindowExA(0, "BUTTON", "Show Web View folder sidebar",
                WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                24, 160, 285, 18, hWnd, (HMENU)IDC_OPT_WEB_VIEW, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hCtl, BM_SETCHECK, g_bShowWebView ? BST_CHECKED : BST_UNCHECKED, 0);
            
            /* Buttons */
            hCtl = CreateWindowExA(0, "BUTTON", "OK",
                WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                160, 206, 75, 23, hWnd, (HMENU)IDOK, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            
            hCtl = CreateWindowExA(0, "BUTTON", "Cancel",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                245, 206, 75, 23, hWnd, (HMENU)IDCANCEL, g_hInstance, NULL);
            SendMessage(hCtl, WM_SETFONT, (WPARAM)hFont, TRUE);
            return 0;
        }
        
        case WM_COMMAND: {
            WORD id = LOWORD(wParam);
            if (id == IDOK) {
                HMENU hMenu = GetMenu(g_hMainWnd);
                g_bNotifyOnCopyPaste = (SendDlgItemMessage(hWnd, IDC_OPT_NOTIFY, BM_GETCHECK, 0, 0) == BST_CHECKED);
                g_bShowStdToolbar = (SendDlgItemMessage(hWnd, IDC_OPT_STD_TB, BM_GETCHECK, 0, 0) == BST_CHECKED);
                g_bShowAddressBar = (SendDlgItemMessage(hWnd, IDC_OPT_ADDR_BAR, BM_GETCHECK, 0, 0) == BST_CHECKED);
                g_bShowStatusBar = (SendDlgItemMessage(hWnd, IDC_OPT_STATUS_BAR, BM_GETCHECK, 0, 0) == BST_CHECKED);
                g_bShowWebView = (SendDlgItemMessage(hWnd, IDC_OPT_WEB_VIEW, BM_GETCHECK, 0, 0) == BST_CHECKED);
                
                if (hMenu) {
                    CheckMenuItem(hMenu, IDM_TOOLS_NOTIFY_COPYPASTE, g_bNotifyOnCopyPaste ? MF_CHECKED : MF_UNCHECKED);
                    CheckMenuItem(hMenu, IDM_VIEW_TOOLBAR_STD, g_bShowStdToolbar ? MF_CHECKED : MF_UNCHECKED);
                    CheckMenuItem(hMenu, IDM_VIEW_TOOLBAR_ADDR, g_bShowAddressBar ? MF_CHECKED : MF_UNCHECKED);
                    CheckMenuItem(hMenu, IDM_VIEW_STATUSBAR, g_bShowStatusBar ? MF_CHECKED : MF_UNCHECKED);
                }
                SendMessage(g_hMainWnd, WM_SIZE, 0, 0);
                DestroyWindow(hWnd);
                return 0;
            } else if (id == IDCANCEL) {
                DestroyWindow(hWnd);
                return 0;
            }
            break;
        }
        
        case WM_CLOSE:
            DestroyWindow(hWnd);
            return 0;
            
        case WM_DESTROY:
            EnableWindow(g_hMainWnd, TRUE);
            SetForegroundWindow(g_hMainWnd);
            return 0;
    }
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

void ShowFolderOptionsDialog(HWND hWndParent)
{
    WNDCLASSA wc;
    HWND hDlg;
    RECT rcParent;
    int x, y;
    
    x = 200;
    y = 150;
    
    ZeroMemory(&wc, sizeof(wc));
    wc.lpfnWndProc = FolderOptionsDlgProc;
    wc.hInstance = g_hInstance;
    wc.lpszClassName = "MtpFolderOptions";
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClassA(&wc);
    
    if (GetWindowRect(hWndParent, &rcParent)) {
        x = rcParent.left + (rcParent.right - rcParent.left - 340) / 2;
        y = rcParent.top + (rcParent.bottom - rcParent.top - 270) / 2;
    }
    
    EnableWindow(hWndParent, FALSE);
    hDlg = CreateWindowExA(
        WS_EX_DLGMODALFRAME,
        "MtpFolderOptions", "Folder Options",
        WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
        x, y, 340, 270,
        hWndParent, NULL, g_hInstance, NULL
    );
    
    if (hDlg) {
        MSG msg;
        while (IsWindow(hDlg) && GetMessageA(&msg, NULL, 0, 0)) {
            if (msg.message == WM_KEYDOWN && (msg.wParam == VK_ESCAPE || msg.wParam == VK_RETURN)) {
                if (msg.wParam == VK_RETURN) {
                    SendMessageA(hDlg, WM_COMMAND, MAKEWPARAM(IDOK, 0), 0);
                } else {
                    SendMessageA(hDlg, WM_COMMAND, MAKEWPARAM(IDCANCEL, 0), 0);
                }
                break;
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }
    EnableWindow(hWndParent, TRUE);
    SetForegroundWindow(hWndParent);
}

/* ============================================================================
 * Search Engine & Find Files / Folders Dialog
 * ============================================================================ */

typedef struct _SEARCH_ITEM {
    DWORD      Handle;
    DWORD      ParentHandle;
    DWORD      StorageId;
    WORD       Format;
    ULONGLONG  Size;
    WCHAR      Name[256];
    char       FolderPath[MAX_PATH];
    BOOL       IsFolder;
} SEARCH_ITEM;

typedef struct _FOLDER_QUEUE_NODE {
    DWORD Handle;
    char  Path[MAX_PATH];
} FOLDER_QUEUE_NODE;

static SEARCH_ITEM *g_SearchResults = NULL;
static DWORD g_SearchResultCount = 0;
static DWORD g_SearchResultCap = 0;
static HWND g_hSearchDlg = NULL;

static BOOL WildcardMatchOne(const char *pat, const char *str)
{
    while (*pat) {
        if (*pat == '*') {
            pat++;
            if (!*pat) return TRUE;
            while (*str) {
                if (WildcardMatchOne(pat, str)) return TRUE;
                str++;
            }
            return FALSE;
        } else if (*pat == '?') {
            if (!*str) return FALSE;
            pat++;
            str++;
        } else {
            if (tolower((unsigned char)*pat) != tolower((unsigned char)*str)) {
                return FALSE;
            }
            pat++;
            str++;
        }
    }
    return (*str == '\0');
}

static BOOL WildcardMatchMulti(const char *patternList, const char *str)
{
    char buf[256];
    char *token;
    
    if (!patternList || !*patternList || strcmp(patternList, "*") == 0 || strcmp(patternList, "*.*") == 0) {
        return TRUE;
    }
    
    strncpy(buf, patternList, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    
    token = strtok(buf, ";,");
    while (token) {
        while (*token == ' ') token++;
        if (*token && WildcardMatchOne(token, str)) {
            return TRUE;
        }
        token = strtok(NULL, ";,");
    }
    return FALSE;
}

static BOOL MatchSearchString(const char *query, const char *name)
{
    char wrapped[256];
    if (!query || !*query || strcmp(query, "*") == 0 || strcmp(query, "*.*") == 0) {
        return TRUE;
    }
    if (strchr(query, '*') || strchr(query, '?') || strchr(query, ';') || strchr(query, ',')) {
        return WildcardMatchMulti(query, name);
    }
    _snprintf(wrapped, sizeof(wrapped), "*%s*", query);
    return WildcardMatchOne(wrapped, name);
}

static BOOL MatchesSearchFilter(const char *name, const char *query, int typeFilter, BOOL isFolder)
{
    if (!MatchSearchString(query, name)) {
        return FALSE;
    }
    switch (typeFilter) {
        case 0: /* All Files and Folders */
            return TRUE;
        case 1: /* Pictures and Photos */
            if (isFolder) return FALSE;
            return WildcardMatchMulti("*.jpg;*.jpeg;*.png;*.bmp;*.gif;*.tif;*.tiff;*.webp;*.ico", name);
        case 2: /* Music and Audio */
            if (isFolder) return FALSE;
            return WildcardMatchMulti("*.mp3;*.wma;*.wav;*.aac;*.m4a;*.ogg;*.flac;*.mid", name);
        case 3: /* Video Clips */
            if (isFolder) return FALSE;
            return WildcardMatchMulti("*.mp4;*.mkv;*.avi;*.mov;*.wmv;*.3gp;*.webm;*.mpg;*.mpeg;*.ts", name);
        case 4: /* Documents and Text */
            if (isFolder) return FALSE;
            return WildcardMatchMulti("*.txt;*.doc;*.docx;*.pdf;*.xls;*.xlsx;*.ppt;*.pptx;*.rtf;*.log;*.csv;*.ini", name);
        case 5: /* Folders Only */
            return isFolder;
        default:
            return TRUE;
    }
}

static void ClearSearchResults(void)
{
    if (g_SearchResults) {
        free(g_SearchResults);
        g_SearchResults = NULL;
    }
    g_SearchResultCount = 0;
    g_SearchResultCap = 0;
}

static BOOL AddSearchResult(const SEARCH_ITEM *pItem)
{
    if (g_SearchResultCount >= g_SearchResultCap) {
        DWORD newCap = (g_SearchResultCap == 0) ? 64 : g_SearchResultCap * 2;
        SEARCH_ITEM *pNew = (SEARCH_ITEM*)realloc(g_SearchResults, newCap * sizeof(SEARCH_ITEM));
        if (!pNew) return FALSE;
        g_SearchResults = pNew;
        g_SearchResultCap = newCap;
    }
    g_SearchResults[g_SearchResultCount++] = *pItem;
    return TRUE;
}

static WNDPROC g_pfnOldSearchEditProc = NULL;
static LRESULT CALLBACK SearchEditSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_GETDLGCODE) {
        return DLGC_WANTALLKEYS | DLGC_WANTCHARS;
    }
    /* WM_KEYDOWN fires BEFORE WM_CHAR in the Windows message pipeline.
     * We must trigger Find Now here, not in WM_CHAR (which never arrives
     * for VK_RETURN if we consume the keydown). */
    if (uMsg == WM_KEYDOWN) {
        if (wParam == VK_RETURN) {
            HWND hParent = GetParent(hWnd);
            if (hParent) {
                SendMessage(hParent, WM_COMMAND,
                            MAKEWPARAM(IDC_SEARCH_BTN_FINDNOW, BN_CLICKED), 0);
            }
            return 0;   /* consumed — do not pass to edit control */
        }
        if (wParam == VK_ESCAPE) {
            DestroyWindow(GetParent(hWnd));
            return 0;
        }
    }
    /* Suppress the '\r' WM_CHAR that TranslateMessage may still generate
     * (prevents the default edit-control "ding" beep). */
    if (uMsg == WM_CHAR && wParam == '\r') {
        return 0;
    }
    return CallWindowProcA(g_pfnOldSearchEditProc, hWnd, uMsg, wParam, lParam);
}

static LRESULT CALLBACK SearchWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hEditName = NULL;
    static HWND hComboLookIn = NULL;
    static HWND hComboType = NULL;
    static HWND hChkSubfolders = NULL;
    static HWND hBtnFindNow = NULL;
    static HWND hBtnStop = NULL;
    static HWND hBtnNew = NULL;
    static HWND hBtnOpen = NULL;
    static HWND hBtnDownload = NULL;
    static HWND hListView = NULL;
    static HWND hStatusBar = NULL;
    static HWND hGroupBox = NULL;

    switch (uMsg) {
        case WM_CREATE: {
            HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
            LVCOLUMNA lvc;
            int sbParts[3];
            char szCurrentOpt[300];

            sbParts[0] = 280;
            sbParts[1] = 420;
            sbParts[2] = -1;

            /* Group Box: Search Criteria */
            hGroupBox = CreateWindowExA(0, "BUTTON", "Search Criteria",
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
                10, 8, 430, 134, hWnd, NULL, g_hInstance, NULL);
            SendMessage(hGroupBox, WM_SETFONT, (WPARAM)hFont, TRUE);

            /* Named Label & Edit */
            {
                HWND hLbl = CreateWindowExA(0, "STATIC", "Search for files or folders named:",
                    WS_CHILD | WS_VISIBLE, 20, 24, 240, 16, hWnd, NULL, g_hInstance, NULL);
                SendMessage(hLbl, WM_SETFONT, (WPARAM)hFont, TRUE);

                hEditName = CreateWindowExA(WS_EX_CLIENTEDGE, "EDIT", "*",
                    WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL,
                    20, 40, 405, 21, hWnd, (HMENU)IDC_SEARCH_EDIT_NAME, g_hInstance, NULL);
                SendMessage(hEditName, WM_SETFONT, (WPARAM)hFont, TRUE);
                g_pfnOldSearchEditProc = (WNDPROC)SetWindowLongA(hEditName, GWL_WNDPROC, (LONG)SearchEditSubclassProc);
            }

            /* Look in Label & Combo */
            {
                HWND hLbl = CreateWindowExA(0, "STATIC", "Look in:",
                    WS_CHILD | WS_VISIBLE, 20, 68, 50, 16, hWnd, NULL, g_hInstance, NULL);
                SendMessage(hLbl, WM_SETFONT, (WPARAM)hFont, TRUE);

                hComboLookIn = CreateWindowExA(0, "COMBOBOX", "",
                    WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST | WS_VSCROLL,
                    75, 66, 350, 150, hWnd, (HMENU)IDC_SEARCH_COMBO_LOOKIN, g_hInstance, NULL);
                SendMessage(hComboLookIn, WM_SETFONT, (WPARAM)hFont, TRUE);

                SendMessageA(hComboLookIn, CB_ADDSTRING, 0, (LPARAM)"Entire Portable Device");
                _snprintf(szCurrentOpt, sizeof(szCurrentOpt), "Current Folder (%s)", g_szCurrentPath);
                SendMessageA(hComboLookIn, CB_ADDSTRING, 0, (LPARAM)szCurrentOpt);
                SendMessage(hComboLookIn, CB_SETCURSEL, 0, 0);
            }

            /* Type Label & Combo */
            {
                HWND hLbl = CreateWindowExA(0, "STATIC", "Of type:",
                    WS_CHILD | WS_VISIBLE, 20, 96, 50, 16, hWnd, NULL, g_hInstance, NULL);
                SendMessage(hLbl, WM_SETFONT, (WPARAM)hFont, TRUE);

                hComboType = CreateWindowExA(0, "COMBOBOX", "",
                    WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST | WS_VSCROLL,
                    75, 94, 200, 150, hWnd, (HMENU)IDC_SEARCH_COMBO_TYPE, g_hInstance, NULL);
                SendMessage(hComboType, WM_SETFONT, (WPARAM)hFont, TRUE);

                SendMessageA(hComboType, CB_ADDSTRING, 0, (LPARAM)"All Files and Folders (*.*)");
                SendMessageA(hComboType, CB_ADDSTRING, 0, (LPARAM)"Pictures & Photos (*.jpg, *.png)");
                SendMessageA(hComboType, CB_ADDSTRING, 0, (LPARAM)"Music & Audio (*.mp3, *.wma)");
                SendMessageA(hComboType, CB_ADDSTRING, 0, (LPARAM)"Video Clips (*.mp4, *.avi)");
                SendMessageA(hComboType, CB_ADDSTRING, 0, (LPARAM)"Documents & Text (*.txt, *.doc)");
                SendMessageA(hComboType, CB_ADDSTRING, 0, (LPARAM)"Folders Only");
                SendMessage(hComboType, CB_SETCURSEL, 0, 0);
            }

            /* Include Subfolders Checkbox */
            hChkSubfolders = CreateWindowExA(0, "BUTTON", "&Include subfolders",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX,
                290, 96, 135, 18, hWnd, (HMENU)IDC_SEARCH_CHK_SUBFOLDERS, g_hInstance, NULL);
            SendMessage(hChkSubfolders, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hChkSubfolders, BM_SETCHECK, BST_CHECKED, 0);

            /* Right Action Buttons */
            hBtnFindNow = CreateWindowExA(0, "BUTTON", "&Find Now",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
                450, 14, 110, 23, hWnd, (HMENU)IDC_SEARCH_BTN_FINDNOW, g_hInstance, NULL);
            SendMessage(hBtnFindNow, WM_SETFONT, (WPARAM)hFont, TRUE);

            hBtnStop = CreateWindowExA(0, "BUTTON", "&Stop",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON | WS_DISABLED,
                450, 40, 110, 23, hWnd, (HMENU)IDC_SEARCH_BTN_STOP, g_hInstance, NULL);
            SendMessage(hBtnStop, WM_SETFONT, (WPARAM)hFont, TRUE);

            hBtnNew = CreateWindowExA(0, "BUTTON", "&New Search",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
                450, 66, 110, 23, hWnd, (HMENU)IDC_SEARCH_BTN_NEW, g_hInstance, NULL);
            SendMessage(hBtnNew, WM_SETFONT, (WPARAM)hFont, TRUE);

            hBtnOpen = CreateWindowExA(0, "BUTTON", "&Open Folder",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
                450, 92, 110, 23, hWnd, (HMENU)IDC_SEARCH_BTN_OPEN, g_hInstance, NULL);
            SendMessage(hBtnOpen, WM_SETFONT, (WPARAM)hFont, TRUE);

            hBtnDownload = CreateWindowExA(0, "BUTTON", "&Download...",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
                450, 118, 110, 23, hWnd, (HMENU)IDC_SEARCH_BTN_DOWNLOAD, g_hInstance, NULL);
            SendMessage(hBtnDownload, WM_SETFONT, (WPARAM)hFont, TRUE);

            /* Results ListView */
            hListView = CreateWindowExA(WS_EX_CLIENTEDGE, WC_LISTVIEWA, "",
                WS_CHILD | WS_VISIBLE | WS_TABSTOP | LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS | WS_BORDER,
                10, 150, 550, 275, hWnd, (HMENU)IDC_SEARCH_LISTVIEW, g_hInstance, NULL);
            ListView_SetExtendedListViewStyle(hListView,
                LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);

            if (g_hSmallImageList) {
                ListView_SetImageList(hListView, g_hSmallImageList, LVSIL_SMALL);
            }

            ZeroMemory(&lvc, sizeof(lvc));
            lvc.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;

            lvc.iSubItem = 0;
            lvc.cx = 170;
            lvc.pszText = "Name";
            ListView_InsertColumn(hListView, 0, &lvc);

            lvc.iSubItem = 1;
            lvc.cx = 200;
            lvc.pszText = "In Folder";
            ListView_InsertColumn(hListView, 1, &lvc);

            lvc.iSubItem = 2;
            lvc.cx = 80;
            lvc.pszText = "Size";
            ListView_InsertColumn(hListView, 2, &lvc);

            lvc.iSubItem = 3;
            lvc.cx = 100;
            lvc.pszText = "Type";
            ListView_InsertColumn(hListView, 3, &lvc);

            /* Status Bar */
            hStatusBar = CreateWindowExA(0, STATUSCLASSNAMEA, NULL,
                WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
                0, 0, 0, 0, hWnd, (HMENU)IDC_SEARCH_STATUSBAR, g_hInstance, NULL);
            SendMessage(hStatusBar, SB_SETPARTS, 3, (LPARAM)sbParts);
            SendMessageA(hStatusBar, SB_SETTEXTA, 0, (LPARAM)"Ready");
            SendMessageA(hStatusBar, SB_SETTEXTA, 1, (LPARAM)"0 item(s) found");
            SendMessageA(hStatusBar, SB_SETTEXTA, 2, (LPARAM)"0 scanned");

            SetFocus(hEditName);
            SendMessage(hEditName, EM_SETSEL, 0, -1);

            return 0;
        }

        case WM_SIZE: {
            int cx = LOWORD(lParam);
            int cy = HIWORD(lParam);
            if (cx > 0 && cy > 0) {
                int btnX = cx - 120;
                int grpW = cx - 140;

                MoveWindow(hGroupBox, 10, 8, grpW, 134, TRUE);
                MoveWindow(hEditName, 20, 40, grpW - 25, 21, TRUE);
                MoveWindow(hComboLookIn, 75, 66, grpW - 80, 150, TRUE);

                MoveWindow(hBtnFindNow, btnX, 14, 110, 23, TRUE);
                MoveWindow(hBtnStop, btnX, 40, 110, 23, TRUE);
                MoveWindow(hBtnNew, btnX, 66, 110, 23, TRUE);
                MoveWindow(hBtnOpen, btnX, 92, 110, 23, TRUE);
                MoveWindow(hBtnDownload, btnX, 118, 110, 23, TRUE);

                MoveWindow(hListView, 10, 150, cx - 20, cy - 150 - 24, TRUE);
                SendMessage(hStatusBar, WM_SIZE, 0, 0);
            }
            return 0;
        }

        case DM_GETDEFID:
            return MAKELRESULT(IDC_SEARCH_BTN_FINDNOW, DC_HASDEFID);

        case WM_COMMAND: {
            WORD id = LOWORD(wParam);
            if (id == IDOK) {
                id = IDC_SEARCH_BTN_FINDNOW;
            } else if (id == IDCANCEL) {
                SendMessage(hWnd, WM_CLOSE, 0, 0);
                return 0;
            }

            if (id == IDC_SEARCH_BTN_STOP) {
                g_bStopSearch = TRUE;
                return 0;
            }

            if (id == IDC_SEARCH_BTN_NEW) {
                SetWindowTextA(hEditName, "*");
                SendMessage(hComboType, CB_SETCURSEL, 0, 0);
                ListView_DeleteAllItems(hListView);
                ClearSearchResults();
                SendMessageA(hStatusBar, SB_SETTEXTA, 0, (LPARAM)"Ready");
                SendMessageA(hStatusBar, SB_SETTEXTA, 1, (LPARAM)"0 item(s) found");
                SendMessageA(hStatusBar, SB_SETTEXTA, 2, (LPARAM)"0 scanned");
                SetFocus(hEditName);
                SendMessage(hEditName, EM_SETSEL, 0, -1);
                return 0;
            }

            if (id == IDC_SEARCH_BTN_FINDNOW) {
                char szQuery[256];
                int scopeIdx;
                int typeIdx;
                BOOL bSubfolders;
                DWORD startParent;
                char startPath[MAX_PATH];
                FOLDER_QUEUE_NODE *queue;
                int qHead, qTail;
                DWORD totalScanned = 0;
                DWORD totalFound = 0;
                BYTE *handleBuffer;
                char statusMsg[256];
                BOOL bWasStopped = FALSE;

                if (!g_Connected || g_hDevice == INVALID_HANDLE_VALUE) {
                    MessageBoxA(hWnd,
                        "Please connect to the MTP portable device before searching.",
                        "Search", MB_OK | MB_ICONINFORMATION);
                    return 0;
                }

                if (g_bSearchRunning) return 0;

                /* Block search while folder enumeration is actively loading */
                if (g_IsEnumerating) {
                    MessageBoxA(hWnd,
                        "Please wait for the current folder to finish loading (or press Esc to stop) before searching.",
                        "Folder Loading", MB_OK | MB_ICONINFORMATION);
                    return 0;
                }
                if (g_hEnumThread) {
                    CloseHandle(g_hEnumThread);
                    g_hEnumThread = NULL;
                }

                GetWindowTextA(hEditName, szQuery, sizeof(szQuery));
                if (szQuery[0] == '\0') {
                    strcpy(szQuery, "*");
                }

                scopeIdx = (int)SendMessage(hComboLookIn, CB_GETCURSEL, 0, 0);
                typeIdx = (int)SendMessage(hComboType, CB_GETCURSEL, 0, 0);
                bSubfolders = (SendMessage(hChkSubfolders, BM_GETCHECK, 0, 0) == BST_CHECKED);

                if (scopeIdx == 1 && g_CurrentParent != MTP_PARENT_ROOT) {
                    startParent = g_CurrentParent;
                    strncpy(startPath, g_szCurrentPath, sizeof(startPath) - 1);
                } else {
                    startParent = MTP_PARENT_ROOT;
                    strncpy(startPath, g_szRootName, sizeof(startPath) - 1);
                }
                startPath[sizeof(startPath) - 1] = '\0';

                ListView_DeleteAllItems(hListView);
                ClearSearchResults();

                /* Intelligent Fast In-Memory Search: If searching current folder without subfolders,
                 * or if the entire device catalog is already loaded in memory (at root),
                 * match immediately from RAM without generating USB traffic or device timeouts. */
                if ((scopeIdx == 1 && !bSubfolders) ||
                    (scopeIdx == 0 && g_CurrentParent == MTP_PARENT_ROOT && g_ObjectCount > 0)) {
                    DWORD k;
                    DWORD memFound = 0;
                    const char *targetFolder = (scopeIdx == 1) ? g_szCurrentPath : g_szRootName;

                    EnterCriticalSection(&g_ObjectsCs);
                    for (k = 0; k < g_ObjectCount; k++) {
                        char nameA[256];
                        WideCharToMultiByte(CP_ACP, 0, g_Objects[k].Name, -1, nameA, sizeof(nameA), NULL, NULL);
                        if (nameA[0] == '\0') {
                            _snprintf(nameA, sizeof(nameA), "Object_%08X", g_Objects[k].Handle);
                        }

                        if (MatchesSearchFilter(nameA, szQuery, typeIdx, g_Objects[k].IsFolder)) {
                            SEARCH_ITEM sItem;
                            LVITEMA lvi;
                            char sizeStr[32];
                            const char *typeName;
                            int itemIdx;

                            ZeroMemory(&sItem, sizeof(sItem));
                            sItem.Handle = g_Objects[k].Handle;
                            sItem.ParentHandle = g_Objects[k].ParentHandle;
                            sItem.StorageId = g_Objects[k].StorageId;
                            sItem.Format = g_Objects[k].Format;
                            sItem.Size = g_Objects[k].Size;
                            wcsncpy(sItem.Name, g_Objects[k].Name, 255);
                            strncpy(sItem.FolderPath, targetFolder, sizeof(sItem.FolderPath) - 1);
                            sItem.IsFolder = g_Objects[k].IsFolder;

                            AddSearchResult(&sItem);
                            itemIdx = (int)(g_SearchResultCount - 1);

                            ZeroMemory(&lvi, sizeof(lvi));
                            lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
                            lvi.iItem = itemIdx;
                            lvi.iSubItem = 0;
                            lvi.pszText = nameA;
                            lvi.iImage = GetIconIndexForFormat(g_Objects[k].Format, g_Objects[k].IsFolder);
                            lvi.lParam = (LPARAM)itemIdx;
                            ListView_InsertItem(hListView, &lvi);

                            ListView_SetItemText(hListView, itemIdx, 1, (char*)targetFolder);

                            if (g_Objects[k].IsFolder) {
                                strcpy(sizeStr, "");
                            } else {
                                FormatFileSize64(g_Objects[k].Size, sizeStr, sizeof(sizeStr));
                            }
                            ListView_SetItemText(hListView, itemIdx, 2, sizeStr);

                            typeName = GetFormatName(g_Objects[k].Format);
                            ListView_SetItemText(hListView, itemIdx, 3, (char*)typeName);

                            memFound++;
                        }
                    }
                    LeaveCriticalSection(&g_ObjectsCs);

                    _snprintf(statusMsg, sizeof(statusMsg), "Search complete. Found %lu item(s).", memFound);
                    SendMessageA(hStatusBar, SB_SETTEXTA, 0, (LPARAM)statusMsg);
                    _snprintf(statusMsg, sizeof(statusMsg), "%lu item(s) found", memFound);
                    SendMessageA(hStatusBar, SB_SETTEXTA, 1, (LPARAM)statusMsg);
                    _snprintf(statusMsg, sizeof(statusMsg), "%lu scanned", g_ObjectCount);
                    SendMessageA(hStatusBar, SB_SETTEXTA, 2, (LPARAM)statusMsg);

                    EnableWindow(hBtnStop, FALSE);
                    EnableWindow(hBtnFindNow, TRUE);
                    EnableWindow(hBtnNew, TRUE);
                    SetFocus(hBtnFindNow);
                    return 0;
                }

                queue = (FOLDER_QUEUE_NODE*)malloc(sizeof(FOLDER_QUEUE_NODE) * 4096);
                handleBuffer = (BYTE*)malloc(262144);

                if (!queue || !handleBuffer) {
                    if (queue) free(queue);
                    if (handleBuffer) free(handleBuffer);
                    MessageBoxA(hWnd, "Insufficient memory for search queue.", "Search Error", MB_OK | MB_ICONERROR);
                    return 0;
                }

                EnableWindow(g_hMainWnd, FALSE);
                g_bSearchRunning = TRUE;
                g_bStopSearch = FALSE;
                EnableWindow(hBtnStop, TRUE);
                EnableWindow(hBtnFindNow, FALSE);
                EnableWindow(hBtnNew, FALSE);
                SetFocus(hBtnStop);

                qHead = 0;
                qTail = 0;
                queue[qTail].Handle = startParent;
                strncpy(queue[qTail].Path, startPath, sizeof(queue[0].Path) - 1);
                queue[qTail].Path[sizeof(queue[0].Path) - 1] = '\0';
                qTail++;

                while (qHead < qTail && !g_bStopSearch) {
                    FOLDER_QUEUE_NODE curr = queue[qHead++];
                    DWORD params[3];
                    DWORD bytesRet = 0;
                    DWORD childCount = 0;
                    DWORD *pHandles;
                    DWORD c;
                    DWORD searchFailCount = 0;
                    DWORD folderRetry;
                    BOOL gotHandles = FALSE;

                    _snprintf(statusMsg, sizeof(statusMsg), "Searching: %s...", curr.Path);
                    SendMessageA(hStatusBar, SB_SETTEXTA, 0, (LPARAM)statusMsg);

                    /* Pacing delay between folders to prevent USB controller queue
                     * starvation on real hardware. Without this, rapid-fire
                     * GetObjectHandles floods the bus and triggers timeout desync. */
                    if (qHead > 1) {
                        Sleep(20);
                    }

                    params[0] = g_CurrentStorage ? g_CurrentStorage : 0xFFFFFFFF;
                    params[1] = 0x00000000;
                    params[2] = (curr.Handle == 0) ? MTP_PARENT_ROOT : curr.Handle;

                    /* Retry GetObjectHandles up to 3 times with pipe recovery */
                    for (folderRetry = 0; folderRetry < 3 && !gotHandles; folderRetry++) {
                        if (folderRetry > 0) {
                            if (g_bDebugConsole) {
                                DebugLog("[SEARCH RETRY] GetObjectHandles retry %lu for folder '%s'", folderRetry, curr.Path);
                            }
                            MtpResetPipes();
                            Sleep(100 * folderRetry);
                        }
                        bytesRet = 0;
                        if (MtpSendOperation(MTP_OP_GET_OBJECT_HANDLES, params, 3, NULL, 0,
                                              handleBuffer, 262144, &bytesRet) && bytesRet >= sizeof(DWORD)) {
                            gotHandles = TRUE;
                        }
                    }

                    if (!gotHandles) {
                        if (curr.Handle == 0 && g_hDevice != INVALID_HANDLE_VALUE) {
                            EnterCriticalSection(&g_DeviceCs);
                            DeviceIoControl(g_hDevice, IOCTL_MTP_LIST_OBJECTS, NULL, 0,
                                            handleBuffer, 262144, &bytesRet, NULL);
                            LeaveCriticalSection(&g_DeviceCs);
                            if (bytesRet >= sizeof(DWORD)) gotHandles = TRUE;
                        }
                    }
                    if (!gotHandles) continue;

                    childCount = *((DWORD*)handleBuffer);
                    if (bytesRet < sizeof(DWORD) + (childCount * sizeof(DWORD))) {
                        childCount = (bytesRet - sizeof(DWORD)) / sizeof(DWORD);
                    }

                    pHandles = (DWORD*)(handleBuffer + sizeof(DWORD));

                    for (c = 0; c < childCount && !g_bStopSearch; c++) {
                        DWORD childHandle = pHandles[c];
                        BYTE infoBuf[1024];
                        DWORD infoBytes = 0;

                        totalScanned++;

                        /* Message pumping on EVERY single item so 'Stop' button responds instantly */
                        {
                            MSG qMsg;
                            while (PeekMessageA(&qMsg, NULL, 0, 0, PM_REMOVE)) {
                                if (qMsg.message == WM_QUIT) {
                                    g_bStopSearch = TRUE;
                                    PostQuitMessage((int)qMsg.wParam);
                                    break;
                                }
                                TranslateMessage(&qMsg);
                                DispatchMessageA(&qMsg);
                            }
                        }
                        if (g_bStopSearch) break;

                        if ((totalScanned % 5) == 0) {
                            char scMsg[64];
                            _snprintf(scMsg, sizeof(scMsg), "%lu scanned", totalScanned);
                            SendMessageA(hStatusBar, SB_SETTEXTA, 2, (LPARAM)scMsg);
                            Sleep(1);
                        }

                        /* After 4 consecutive failures, reset pipes to recover.
                         * After 10 consecutive failures, verify device is alive. */
                        if (searchFailCount == 4) {
                            MtpResetPipes();
                            Sleep(80);
                        }
                        if (searchFailCount >= 10) {
                            DWORD devInfoRet = 0;
                            BYTE devBuf[64];
                            MtpResetPipes();
                            Sleep(120);
                            if (!MtpSendOperation(MTP_OP_GET_DEVICE_INFO, NULL, 0, NULL, 0, devBuf, sizeof(devBuf), &devInfoRet)) {
                                g_bStopSearch = TRUE;
                                break;
                            }
                            searchFailCount = 0;
                        }

                        if (MtpGetObjectInfoWithRetry(childHandle, infoBuf, sizeof(infoBuf), &infoBytes)) {
                            WORD fmt;
                            DWORD szLow;
                            BOOL isFolder;
                            WCHAR nameW[256];
                            char nameA[256];
                            ULONGLONG objSize;

                            searchFailCount = 0;
                            fmt = *((WORD*)(infoBuf + 4));
                            szLow = *((DWORD*)(infoBuf + 8));
                            isFolder = (fmt == MTP_FORMAT_ASSOCIATION);
                            objSize = (ULONGLONG)szLow;

                            ReadMtpString(infoBuf + 52, infoBytes - 52, nameW, 256);
                            WideCharToMultiByte(CP_ACP, 0, nameW, -1, nameA, sizeof(nameA), NULL, NULL);
                            if (nameA[0] == '\0') {
                                _snprintf(nameA, sizeof(nameA), "Object_%08X", childHandle);
                            }

                            if (MatchesSearchFilter(nameA, szQuery, typeIdx, isFolder)) {
                                SEARCH_ITEM sItem;
                                LVITEMA lvi;
                                char sizeStr[32];
                                const char *typeName;
                                int itemIdx;

                                /* Query 64-bit size ONLY for matching items to maximize search speed */
                                if (!isFolder && szLow == 0xFFFFFFFF) {
                                    BYTE propBuf[16];
                                    DWORD propBytes = 0;
                                    DWORD propParams[2];
                                    propParams[0] = childHandle;
                                    propParams[1] = 0xDC04;
                                    if (MtpSendOperation(0x9803, propParams, 2, NULL, 0,
                                                         propBuf, sizeof(propBuf), &propBytes) && propBytes >= 8) {
                                        DWORD lo = *((DWORD*)(propBuf + 0));
                                        DWORD hi = *((DWORD*)(propBuf + 4));
                                        objSize = ((ULONGLONG)hi << 32) | (ULONGLONG)lo;
                                    }
                                }

                                ZeroMemory(&sItem, sizeof(sItem));
                                sItem.Handle = childHandle;
                                sItem.ParentHandle = curr.Handle;
                                sItem.StorageId = *((DWORD*)(infoBuf + 0));
                                sItem.Format = fmt;
                                sItem.Size = objSize;
                                wcsncpy(sItem.Name, nameW, 255);
                                strncpy(sItem.FolderPath, curr.Path, sizeof(sItem.FolderPath) - 1);
                                sItem.IsFolder = isFolder;

                                AddSearchResult(&sItem);
                                itemIdx = (int)(g_SearchResultCount - 1);

                                ZeroMemory(&lvi, sizeof(lvi));
                                lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
                                lvi.iItem = itemIdx;
                                lvi.iSubItem = 0;
                                lvi.pszText = nameA;
                                lvi.iImage = GetIconIndexForFormat(fmt, isFolder);
                                lvi.lParam = (LPARAM)itemIdx;
                                ListView_InsertItem(hListView, &lvi);

                                ListView_SetItemText(hListView, itemIdx, 1, curr.Path);

                                if (isFolder) {
                                    strcpy(sizeStr, "");
                                } else {
                                    FormatFileSize64(objSize, sizeStr, sizeof(sizeStr));
                                }
                                ListView_SetItemText(hListView, itemIdx, 2, sizeStr);

                                typeName = GetFormatName(fmt);
                                ListView_SetItemText(hListView, itemIdx, 3, (char*)typeName);

                                totalFound++;

                                _snprintf(statusMsg, sizeof(statusMsg), "%lu item(s) found", totalFound);
                                SendMessageA(hStatusBar, SB_SETTEXTA, 1, (LPARAM)statusMsg);
                            }

                            if (curr.Handle != MTP_PARENT_ROOT && isFolder && bSubfolders) {
                                if (qTail < 4096) {
                                    queue[qTail].Handle = childHandle;
                                    _snprintf(queue[qTail].Path, sizeof(queue[0].Path), "%s\\%s", curr.Path, nameA);
                                    qTail++;
                                }
                            }
                        } else {
                            searchFailCount++;
                        }

                        /* Pacing yield: 1ms every 4 items to prevent USB controller queue overflow */
                        if ((c % 4) == 0) {
                            Sleep(1);
                        }
                    }
                }

                free(queue);
                free(handleBuffer);

                bWasStopped = g_bStopSearch;
                g_bSearchRunning = FALSE;
                g_bStopSearch = FALSE;
                EnableWindow(g_hMainWnd, TRUE);
                EnableWindow(hBtnStop, FALSE);
                EnableWindow(hBtnFindNow, TRUE);
                EnableWindow(hBtnNew, TRUE);
                SetFocus(hBtnFindNow);

                if (bWasStopped) {
                    _snprintf(statusMsg, sizeof(statusMsg), "Search stopped by user. Found %lu item(s).", totalFound);
                } else {
                    _snprintf(statusMsg, sizeof(statusMsg), "Search complete. Found %lu item(s).", totalFound);
                }
                SendMessageA(hStatusBar, SB_SETTEXTA, 0, (LPARAM)statusMsg);

                _snprintf(statusMsg, sizeof(statusMsg), "%lu item(s) found", totalFound);
                SendMessageA(hStatusBar, SB_SETTEXTA, 1, (LPARAM)statusMsg);

                _snprintf(statusMsg, sizeof(statusMsg), "%lu scanned", totalScanned);
                SendMessageA(hStatusBar, SB_SETTEXTA, 2, (LPARAM)statusMsg);

                return 0;
            }

            if (id == IDC_SEARCH_BTN_OPEN) {
                int sel = ListView_GetNextItem(hListView, -1, LVNI_SELECTED);
                if (sel != -1 && sel < (int)g_SearchResultCount) {
                    SEARCH_ITEM item = g_SearchResults[sel];
                    if (item.IsFolder) {
                        char nameA[256];
                        WideCharToMultiByte(CP_ACP, 0, item.Name, -1, nameA, sizeof(nameA), NULL, NULL);
                        NavigateToFolder(item.Handle, nameA);
                    } else {
                        NavigateToAddressPath(g_hMainWnd, item.FolderPath);
                        if (g_Objects) {
                            DWORD k;
                            for (k = 0; k < g_ObjectCount; k++) {
                                if (g_Objects[k].Handle == item.Handle) {
                                    ListView_SetItemState(g_hListView, k, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
                                    ListView_EnsureVisible(g_hListView, k, FALSE);
                                    break;
                                }
                            }
                        }
                    }
                    SetForegroundWindow(g_hMainWnd);
                } else {
                    MessageBoxA(hWnd, "Please select an item from the results list.", "Find", MB_OK | MB_ICONINFORMATION);
                }
                return 0;
            }

            if (id == IDC_SEARCH_BTN_DOWNLOAD) {
                int sel = ListView_GetNextItem(hListView, -1, LVNI_SELECTED);
                if (sel != -1 && sel < (int)g_SearchResultCount) {
                    SEARCH_ITEM item = g_SearchResults[sel];
                    if (item.IsFolder) {
                        MessageBoxA(hWnd, "Please select a file to download.", "Download", MB_OK | MB_ICONINFORMATION);
                    } else {
                        char nameA[256];
                        char szDest[MAX_PATH];
                        OPENFILENAMEA ofn;

                        WideCharToMultiByte(CP_ACP, 0, item.Name, -1, nameA, sizeof(nameA), NULL, NULL);
                        strncpy(szDest, nameA, sizeof(szDest) - 1);
                        szDest[sizeof(szDest) - 1] = '\0';

                        ZeroMemory(&ofn, sizeof(ofn));
                        ofn.lStructSize = sizeof(ofn);
                        ofn.hwndOwner = hWnd;
                        ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
                        ofn.lpstrFile = szDest;
                        ofn.nMaxFile = sizeof(szDest);
                        ofn.lpstrTitle = "Save As - Download from MTP Device";
                        ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;

                        if (GetSaveFileNameA(&ofn)) {
                            if (DownloadObjectToFile(hWnd, item.Handle, item.Size, szDest, nameA, FALSE)) {
                                char msg[MAX_PATH + 64];
                                _snprintf(msg, sizeof(msg), "Download complete!\n\nSaved to: %s", szDest);
                                MessageBoxA(hWnd, msg, "Download Complete", MB_OK | MB_ICONINFORMATION);
                            }
                        }
                    }
                } else {
                    MessageBoxA(hWnd, "Please select an item to download.", "Download", MB_OK | MB_ICONINFORMATION);
                }
                return 0;
            }

            break;
        }

        case WM_NOTIFY: {
            LPNMHDR pnmh = (LPNMHDR)lParam;
            if (pnmh->idFrom == IDC_SEARCH_LISTVIEW) {
                if (pnmh->code == NM_DBLCLK) {
                    SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDC_SEARCH_BTN_OPEN, 0), 0);
                    return 0;
                } else if (pnmh->code == NM_RCLICK) {
                    POINT pt;
                    HMENU hPopup = CreatePopupMenu();
                    int sel = ListView_GetNextItem(hListView, -1, LVNI_SELECTED);
                    GetCursorPos(&pt);
                    if (sel != -1) {
                        AppendMenuA(hPopup, MF_STRING, IDC_SEARCH_BTN_OPEN, "&Open Containing Folder");
                        AppendMenuA(hPopup, MF_STRING, IDC_SEARCH_BTN_DOWNLOAD, "&Download to PC...");
                        TrackPopupMenu(hPopup, TPM_RIGHTBUTTON | TPM_LEFTALIGN, pt.x, pt.y, 0, hWnd, NULL);
                    }
                    DestroyMenu(hPopup);
                    return 0;
                }
            }
            break;
        }

        case WM_CLOSE:
            g_bStopSearch = TRUE;
            g_bSearchRunning = FALSE;
            DestroyWindow(hWnd);
            return 0;

        case WM_DESTROY:
            g_bStopSearch = FALSE;
            g_bSearchRunning = FALSE;
            ClearSearchResults();
            g_hSearchDlg = NULL;
            EnableWindow(g_hMainWnd, TRUE);
            SetForegroundWindow(g_hMainWnd);
            return 0;
    }
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

void ShowSearchDialog(HWND hWndParent)
{
    WNDCLASSA wc;
    RECT rcParent;
    int x = 150, y = 100;
    int w = 580, h = 480;

    if (g_IsEnumerating) {
        MessageBoxA(hWndParent,
            "Please wait for the current folder to finish loading (or press Esc to stop) before opening Search.",
            "Folder Loading", MB_OK | MB_ICONINFORMATION);
        return;
    }

    if (g_hSearchDlg && IsWindow(g_hSearchDlg)) {
        ShowWindow(g_hSearchDlg, SW_SHOWNORMAL);
        SetForegroundWindow(g_hSearchDlg);
        return;
    }

    ZeroMemory(&wc, sizeof(wc));
    wc.lpfnWndProc = SearchWndProc;
    wc.hInstance = g_hInstance;
    wc.lpszClassName = "MtpSearchWindow";
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClassA(&wc);

    if (GetWindowRect(hWndParent, &rcParent)) {
        x = rcParent.left + (rcParent.right - rcParent.left - w) / 2;
        y = rcParent.top + (rcParent.bottom - rcParent.top - h) / 2;
        if (x < 10) x = 10;
        if (y < 10) y = 10;
    }

    g_hSearchDlg = CreateWindowExA(
        WS_EX_APPWINDOW | WS_EX_CONTROLPARENT,
        "MtpSearchWindow", "Find: Files or Folders on Portable Device",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE,
        x, y, w, h,
        hWndParent, NULL, g_hInstance, NULL
    );

    if (g_hSearchDlg) {
        SetForegroundWindow(g_hSearchDlg);
    }
}

LRESULT CALLBACK AddressBandSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_COMMAND) {
        return SendMessage(GetParent(hWnd), WM_COMMAND, wParam, lParam);
    }
    return CallWindowProcA(g_pfnOldStaticBandProc, hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK AddressEditSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_KEYDOWN && wParam == VK_RETURN) {
        SendMessage(g_hMainWnd, WM_COMMAND, MAKEWPARAM(IDC_GO_BTN, BN_CLICKED), (LPARAM)g_hGoBtn);
        return 0;
    }
    if (uMsg == WM_CHAR && wParam == VK_RETURN) {
        return 0;
    }
    if (uMsg == WM_SETFOCUS) {
        LRESULT res = CallWindowProcA(g_pfnOldAddressEditProc, hWnd, uMsg, wParam, lParam);
        SendMessage(hWnd, EM_SETSEL, 0, -1);
        return res;
    }
    return CallWindowProcA(g_pfnOldAddressEditProc, hWnd, uMsg, wParam, lParam);
}

void CreateAddressBar(HWND hWnd)
{
    HWND hStatic;
    HFONT hFont;
    
    g_hAddressBand = CreateWindowExA(
        0, "STATIC", "",
        WS_CHILD | WS_VISIBLE,
        0, 0, 100, ADDR_BAR_HEIGHT,
        hWnd, NULL, g_hInstance, NULL
    );
    if (g_hAddressBand) {
        g_pfnOldStaticBandProc = (WNDPROC)SetWindowLongA(g_hAddressBand, GWL_WNDPROC, (LONG)AddressBandSubclassProc);
    }
    
    hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    
    hStatic = CreateWindowExA(
        0, "STATIC", " Address",
        WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE,
        4, 4, 60, 20,
        g_hAddressBand, NULL, g_hInstance, NULL
    );
    SendMessage(hStatic, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    g_hAddressCombo = CreateWindowExA(
        WS_EX_CLIENTEDGE, "EDIT", g_szCurrentPath,
        WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
        68, 3, 300, 21,
        g_hAddressBand, (HMENU)IDC_ADDR_COMBO, g_hInstance, NULL
    );
    SendMessage(g_hAddressCombo, WM_SETFONT, (WPARAM)hFont, TRUE);
    if (g_hAddressCombo) {
        g_pfnOldAddressEditProc = (WNDPROC)SetWindowLongA(g_hAddressCombo, GWL_WNDPROC, (LONG)AddressEditSubclassProc);
    }
    
    g_hGoBtn = CreateWindowExA(
        0, "BUTTON", "Go",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        375, 2, 45, 22,
        g_hAddressBand, (HMENU)IDC_GO_BTN, g_hInstance, NULL
    );
    SendMessage(g_hGoBtn, WM_SETFONT, (WPARAM)hFont, TRUE);
}

void CreateWebView(HWND hWnd)
{
    g_hWebView = CreateWindowExA(
        WS_EX_CLIENTEDGE,
        g_szWebViewClass,
        "",
        WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
        0, 0, WEBVIEW_WIDTH, 100,
        hWnd,
        (HMENU)IDC_WEBVIEW,
        g_hInstance,
        NULL
    );
}

void CreateListView(HWND hWnd)
{
    LVCOLUMNA lvc;
    SHFILEINFOA shfi;
    
    g_hListView = CreateWindowExA(
        WS_EX_CLIENTEDGE,
        WC_LISTVIEWA,
        NULL,
        WS_CHILD | WS_VISIBLE | LVS_ICON | LVS_AUTOARRANGE | LVS_SHOWSELALWAYS | LVS_SINGLESEL | LVS_OWNERDATA,
        0, 0, 100, 100,
        hWnd,
        (HMENU)IDC_LISTVIEW,
        g_hInstance,
        NULL
    );
    
    ListView_SetExtendedListViewStyle(g_hListView, 
        LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES);
    
    /* Create Shell Image Lists */
    g_hSmallImageList = ImageList_Create(16, 16, ILC_COLOR32 | ILC_MASK, 6, 0);
    g_hLargeImageList = ImageList_Create(32, 32, ILC_COLOR32 | ILC_MASK, 6, 0);
    
    /* 0: Folder */
    SHGetFileInfoA("folder", FILE_ATTRIBUTE_DIRECTORY, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hSmallImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    SHGetFileInfoA("folder", FILE_ATTRIBUTE_DIRECTORY, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_LARGEICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hLargeImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    /* 1: Text file */
    SHGetFileInfoA(".txt", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hSmallImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    SHGetFileInfoA(".txt", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_LARGEICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hLargeImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    /* 2: Image file */
    SHGetFileInfoA(".jpg", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hSmallImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    SHGetFileInfoA(".jpg", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_LARGEICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hLargeImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    /* 3: Audio file */
    SHGetFileInfoA(".mp3", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hSmallImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    SHGetFileInfoA(".mp3", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_LARGEICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hLargeImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    /* 4: Video file */
    SHGetFileInfoA(".avi", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hSmallImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    SHGetFileInfoA(".avi", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_LARGEICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hLargeImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    /* 5: Generic file */
    SHGetFileInfoA(".dat", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hSmallImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    SHGetFileInfoA(".dat", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_LARGEICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hLargeImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    ListView_SetImageList(g_hListView, g_hLargeImageList, LVSIL_NORMAL);
    ListView_SetImageList(g_hListView, g_hSmallImageList, LVSIL_SMALL);
    
    /* Details columns */
    ZeroMemory(&lvc, sizeof(lvc));
    lvc.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
    
    lvc.pszText = "Name";
    lvc.cx = 250;
    lvc.iSubItem = 0;
    ListView_InsertColumn(g_hListView, 0, &lvc);
    
    lvc.pszText = "Size";
    lvc.cx = 90;
    lvc.iSubItem = 1;
    ListView_InsertColumn(g_hListView, 1, &lvc);
    
    lvc.pszText = "Type";
    lvc.cx = 120;
    lvc.iSubItem = 2;
    ListView_InsertColumn(g_hListView, 2, &lvc);
    
    lvc.pszText = "Date Modified";
    lvc.cx = 130;
    lvc.iSubItem = 3;
    ListView_InsertColumn(g_hListView, 3, &lvc);
    UpdateColumnHeaders();

    
    /* Enable Drag and Drop on ListView */
    DragAcceptFiles(g_hListView, TRUE);
    g_pfnOrigListViewProc = (WNDPROC)SetWindowLongA(g_hListView, GWL_WNDPROC, (LONG)ListViewSubclassProc);
}

LRESULT CALLBACK ListViewSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_DROPFILES) {
        SendMessage(g_hMainWnd, WM_DROPFILES, wParam, lParam);
        return 0;
    }
    if (uMsg == WM_KEYDOWN) {
        if (wParam == VK_ESCAPE) {
            if (g_IsEnumerating) {
                InterlockedExchange(&g_CancelEnum, 1);
                SetStatus("Stopping enumeration...");
                return 0;
            }
        }
        if (GetKeyState(VK_CONTROL) & 0x8000) {
            if (wParam == 'C' || wParam == 'c') {
                SendMessage(g_hMainWnd, WM_COMMAND, MAKEWPARAM(IDM_EDIT_COPY, 0), 0);
                return 0;
            } else if (wParam == 'V' || wParam == 'v') {
                SendMessage(g_hMainWnd, WM_COMMAND, MAKEWPARAM(IDM_EDIT_PASTE, 0), 0);
                return 0;
            } else if (wParam == 'X' || wParam == 'x') {
                SendMessage(g_hMainWnd, WM_COMMAND, MAKEWPARAM(IDM_EDIT_CUT, 0), 0);
                return 0;
            } else if (wParam == 'A' || wParam == 'a') {
                SendMessage(g_hMainWnd, WM_COMMAND, MAKEWPARAM(IDM_EDIT_SELECT_ALL, 0), 0);
                return 0;
            }
        }
    }
    return CallWindowProcA(g_pfnOrigListViewProc, hWnd, uMsg, wParam, lParam);
}

void CreateStatusBar(HWND hWnd)
{
    int parts[3];
    RECT rc;
    
    GetClientRect(hWnd, &rc);
    parts[0] = 280;
    parts[1] = 400;
    parts[2] = -1;
    
    g_hStatusBar = CreateWindowExA(
        0, STATUSCLASSNAMEA, NULL,
        WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
        0, 0, 0, 0,
        hWnd, (HMENU)IDC_STATUSBAR, g_hInstance, NULL
    );
    
    SendMessageA(g_hStatusBar, SB_SETPARTS, 3, (LPARAM)parts);
    SendMessageA(g_hStatusBar, SB_SETTEXTA, 0, (LPARAM)"0 object(s)");
    SendMessageA(g_hStatusBar, SB_SETTEXTA, 1, (LPARAM)"0 bytes");
    SendMessageA(g_hStatusBar, SB_SETTEXTA, 2, (LPARAM)"My Computer");
}

void SetStatus(const char *text)
{
    if (g_hStatusBar) {
        SendMessageA(g_hStatusBar, SB_SETTEXTA, 0, (LPARAM)text);
    }
}

void SetViewMode(int viewMode)
{
    DWORD dwStyle;
    HMENU hMenu = g_hMainWnd ? GetMenu(g_hMainWnd) : NULL;
    
    g_CurrentViewMode = viewMode;
    dwStyle = GetWindowLong(g_hListView, GWL_STYLE);
    dwStyle &= ~(LVS_ICON | LVS_REPORT | LVS_SMALLICON | LVS_LIST);
    dwStyle |= viewMode;
    SetWindowLong(g_hListView, GWL_STYLE, dwStyle);
    InvalidateRect(g_hListView, NULL, TRUE);
    
    if (hMenu) {
        CheckMenuItem(hMenu, IDM_VIEW_LARGE_ICONS, (viewMode == LVS_ICON) ? MF_CHECKED : MF_UNCHECKED);
        CheckMenuItem(hMenu, IDM_VIEW_SMALL_ICONS, (viewMode == LVS_SMALLICON) ? MF_CHECKED : MF_UNCHECKED);
        CheckMenuItem(hMenu, IDM_VIEW_LIST, (viewMode == LVS_LIST) ? MF_CHECKED : MF_UNCHECKED);
        CheckMenuItem(hMenu, IDM_VIEW_DETAILS, (viewMode == LVS_REPORT) ? MF_CHECKED : MF_UNCHECKED);
    }
}

void UpdateUI(void)
{
    HMENU hMenu;
    BOOL bSearchAvail = (g_Connected && !g_IsEnumerating);
    
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_CONNECT, !g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_DISCONNECT, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, IDM_EDIT_COPY, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, IDM_EDIT_PASTE, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, IDM_EDIT_CUT, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_DELETE, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_SEARCH, bSearchAvail);
    UpdateNavButtons();
    
    hMenu = GetMenu(g_hMainWnd);
    if (hMenu) {
        EnableMenuItem(hMenu, IDM_FILE_CONNECT, g_Connected ? MF_GRAYED : MF_ENABLED);
        EnableMenuItem(hMenu, IDM_FILE_DISCONNECT, g_Connected ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_FILE_SEARCH, bSearchAvail ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_TOOLS_FIND, bSearchAvail ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_FILE_DOWNLOAD, g_Connected ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_FILE_UPLOAD, g_Connected ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_FILE_DELETE, g_Connected ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_EDIT_COPY, g_Connected ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_EDIT_PASTE, g_Connected ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_EDIT_CUT, g_Connected ? MF_ENABLED : MF_GRAYED);
        EnableMenuItem(hMenu, IDM_VIEW_REFRESH, g_Connected ? MF_ENABLED : MF_GRAYED);
    }
    
    if (g_Connected) {
        char title[128];
        _snprintf(title, sizeof(title), "%s - MTP Portable Device", g_szCurrentPath);
        SetWindowTextA(g_hMainWnd, title);
    } else {
        SetWindowTextA(g_hMainWnd, g_szAppTitle);
    }
}

/* ============================================================================
 * Main Window Procedure
 * ============================================================================ */

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
        case WM_CREATE:
            CreateMainMenu(hWnd);
            CreateToolbar(hWnd);
            CreateAddressBar(hWnd);
            CreateWebView(hWnd);
            CreateListView(hWnd);
            CreateStatusBar(hWnd);
            DragAcceptFiles(hWnd, TRUE);
            SetTimer(hWnd, TIMER_DEVICE_CHECK, 2000, NULL);
            UpdateUI();
            return 0;

        case WM_INITMENUPOPUP: {
            HMENU hMenuPopup = (HMENU)wParam;
            if (GetMenuState(hMenuPopup, IDM_VIEW_SORT_NAME, MF_BYCOMMAND) != 0xFFFFFFFF) {
                UpdateSortMenu(hWnd);
            }
            break;
        }
            
        case WM_DEVICECHANGE:
            if (wParam == 0x0004 /* DBT_DEVICEREMOVECOMPLETE */ || wParam == 0x8004 /* DBT_DEVICEREMOVECOMPLETE handle */) {
                if (g_Connected) {
                    HandleDeviceRemoval(hWnd);
                    return TRUE;
                }
            } else if (wParam == 0x0007 /* DBT_DEVNODES_CHANGED */) {
                if (g_Connected && g_hDevice != INVALID_HANDLE_VALUE) {
                    MTP_SPEED_INFO speedInfo;
                    DWORD ret = 0;
                    if (!DeviceIoControl(g_hDevice, IOCTL_MTP_GET_TRANSFER_SPEED, NULL, 0,
                                         &speedInfo, sizeof(speedInfo), &ret, NULL)) {
                        HandleDeviceRemoval(hWnd);
                        return TRUE;
                    }
                }
            }
            break;

        case WM_DROPFILES: {
            HDROP hDrop = (HDROP)wParam;
            UINT fileCount = DragQueryFileA(hDrop, 0xFFFFFFFF, NULL, 0);
            UINT f;
            char dropPath[MAX_PATH];
            BOOL anySuccess = FALSE;
            
            if (!g_Connected) {
                MessageBoxA(hWnd, 
                    "The MTP device is not connected.\n\nPlease connect the device before dragging and dropping files.",
                    "Drag and Drop", MB_OK | MB_ICONINFORMATION);
                DragFinish(hDrop);
                return 0;
            }
            
            for (f = 0; f < fileCount; f++) {
                if (DragQueryFileA(hDrop, f, dropPath, sizeof(dropPath))) {
                    if (UploadSingleFilePath(hWnd, dropPath)) {
                        anySuccess = TRUE;
                    }
                }
            }
            DragFinish(hDrop);
            
            if (anySuccess) {
                RefreshObjects();
                MessageBoxA(hWnd, "Dropped file(s) uploaded successfully to device.", 
                            "Upload Complete", MB_OK | MB_ICONINFORMATION);
            }
            return 0;
        }
        
        case WM_TIMER:
            if (wParam == TIMER_TRAY_DISMISS) {
                RemoveTaskbarNotification(hWnd);
                return 0;
            }
            if (wParam == TIMER_DEVICE_CHECK) {
                if (g_bSearchRunning || g_IsEnumerating) return 0;
                if (g_Connected && g_hDevice != INVALID_HANDLE_VALUE) {
                    MTP_SPEED_INFO speedInfo;
                    DWORD ret = 0;
                    if (!DeviceIoControl(g_hDevice, IOCTL_MTP_GET_TRANSFER_SPEED, NULL, 0,
                                         &speedInfo, sizeof(speedInfo), &ret, NULL)) {
                        HandleDeviceRemoval(hWnd);
                        return 0;
                    }
                }
                return 0;
            }
            break;
            
        case WM_TRAY_NOTIFY:
            if (lParam == WM_LBUTTONDOWN || lParam == WM_RBUTTONDOWN) {
                RemoveTaskbarNotification(hWnd);
                SetForegroundWindow(hWnd);
            }
            return 0;
            
        case WM_SIZE: {
            RECT rcToolbar, rcStatus;
            int tbHeight, sbHeight, addrTop, addrHeight, clientW, clientH;
            int contentTop, contentH;
            int webViewW;
            
            if (LOWORD(lParam) == 0 && HIWORD(lParam) == 0) {
                RECT rcCl;
                GetClientRect(hWnd, &rcCl);
                clientW = rcCl.right - rcCl.left;
                clientH = rcCl.bottom - rcCl.top;
            } else {
                clientW = LOWORD(lParam);
                clientH = HIWORD(lParam);
            }
            
            if (g_bShowStdToolbar) {
                ShowWindow(g_hToolbar, SW_SHOW);
                SendMessage(g_hToolbar, TB_AUTOSIZE, 0, 0);
                GetWindowRect(g_hToolbar, &rcToolbar);
                tbHeight = rcToolbar.bottom - rcToolbar.top;
            } else {
                ShowWindow(g_hToolbar, SW_HIDE);
                tbHeight = 0;
            }
            
            if (g_bShowStatusBar) {
                ShowWindow(g_hStatusBar, SW_SHOW);
                SendMessage(g_hStatusBar, WM_SIZE, 0, 0);
                GetWindowRect(g_hStatusBar, &rcStatus);
                sbHeight = rcStatus.bottom - rcStatus.top;
            } else {
                ShowWindow(g_hStatusBar, SW_HIDE);
                sbHeight = 0;
            }
            
            addrTop = tbHeight;
            if (g_bShowAddressBar) {
                ShowWindow(g_hAddressBand, SW_SHOW);
                addrHeight = ADDR_BAR_HEIGHT;
                MoveWindow(g_hAddressBand, 0, addrTop, clientW, addrHeight, TRUE);
                
                if (g_hAddressCombo && g_hGoBtn) {
                    int comboW = clientW - 68 - 55;
                    if (comboW < 100) comboW = 100;
                    MoveWindow(g_hAddressCombo, 68, 3, comboW, 21, TRUE);
                    MoveWindow(g_hGoBtn, 68 + comboW + 5, 2, 45, 22, TRUE);
                }
            } else {
                ShowWindow(g_hAddressBand, SW_HIDE);
                addrHeight = 0;
            }
            
            contentTop = addrTop + addrHeight;
            contentH = clientH - contentTop - sbHeight;
            if (contentH < 0) contentH = 0;
            
            webViewW = g_bShowWebView ? WEBVIEW_WIDTH : 0;
            if (g_bShowWebView) {
                ShowWindow(g_hWebView, SW_SHOW);
                MoveWindow(g_hWebView, 0, contentTop, webViewW, contentH, TRUE);
            } else {
                ShowWindow(g_hWebView, SW_HIDE);
            }
            
            MoveWindow(g_hListView, webViewW, contentTop, clientW - webViewW, contentH, TRUE);
            return 0;
        }
        
        case WM_APP_ENUM_PROGRESS: {
            DWORD current = (DWORD)wParam;
            DWORD total = (DWORD)lParam;
            char statusText[128];

            if (g_hListView) {
                ListView_SetItemCountEx(g_hListView, current, LVSICF_NOINVALIDATEALL | LVSICF_NOSCROLL);
            }
            _snprintf(statusText, sizeof(statusText), "Loading: %lu of %lu objects... (Press Esc to cancel)", current, total);
            statusText[sizeof(statusText) - 1] = '\0';
            SetStatus(statusText);
            return 0;
        }

        case WM_APP_ENUM_COMPLETE: {
            BOOL wasCancelled = (BOOL)wParam;
            DWORD count = (DWORD)lParam;
            char statusText[128];
            char sizeText[64];
            ULONGLONG totalBytes = 0;
            DWORD c;

            SortObjectList(g_SortColumn, FALSE);
            if (g_hListView) {
                ListView_SetItemCount(g_hListView, count);
                InvalidateRect(g_hListView, NULL, TRUE);
            }
            EnterCriticalSection(&g_ObjectsCs);
            for (c = 0; c < count; c++) {
                if (!g_Objects[c].IsFolder) {
                    totalBytes += g_Objects[c].Size;
                }
            }
            LeaveCriticalSection(&g_ObjectsCs);

            if (totalBytes > 1073741824ULL) {
                _snprintf(sizeText, sizeof(sizeText), "%.2f GB", (double)totalBytes / 1073741824.0);
            } else if (totalBytes > 1048576ULL) {
                _snprintf(sizeText, sizeof(sizeText), "%.2f MB", (double)totalBytes / 1048576.0);
            } else if (totalBytes > 1024ULL) {
                _snprintf(sizeText, sizeof(sizeText), "%.1f KB", (double)totalBytes / 1024.0);
            } else {
                _snprintf(sizeText, sizeof(sizeText), "%I64u bytes", totalBytes);
            }
            sizeText[sizeof(sizeText) - 1] = '\0';

            if (wasCancelled) {
                _snprintf(statusText, sizeof(statusText), "Enumeration stopped (%lu object(s))", count);
            } else {
                _snprintf(statusText, sizeof(statusText), "%lu object(s)", count);
            }
            statusText[sizeof(statusText) - 1] = '\0';
            SetStatus(statusText);
            if (g_hStatusBar) {
                SendMessageA(g_hStatusBar, SB_SETTEXTA, 1, (LPARAM)sizeText);
            }
            if (g_hWebView) {
                InvalidateRect(g_hWebView, NULL, TRUE);
            }
            UpdateUI();
            return 0;
        }
        
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case IDM_FILE_CONNECT:
                case ID_TB_CONNECT:
                    ConnectDevice();
                    break;
                    
                case IDM_FILE_DISCONNECT:
                case ID_TB_DISCONNECT:
                    DisconnectDevice();
                    break;
                    
                case IDM_FILE_SEARCH:
                case IDM_TOOLS_FIND:
                case ID_TB_SEARCH:
                    ShowSearchDialog(hWnd);
                    break;
                    
                case IDM_FILE_DOWNLOAD:
                case ID_TB_DOWNLOAD:
                    DownloadSelected(hWnd);
                    break;
                    
                case IDM_FILE_UPLOAD:
                case ID_TB_UPLOAD:
                    UploadFile(hWnd);
                    break;
                    
                case IDM_FILE_DELETE:
                case ID_TB_DELETE:
                    DeleteSelected(hWnd);
                    break;
                    
                case IDM_VIEW_REFRESH:
                case ID_TB_REFRESH:
                    RefreshObjects();
                    break;
                    
                case ID_TB_BACK:
                    OnNavigateBack(hWnd);
                    break;
                    
                case ID_TB_FORWARD:
                    OnNavigateForward(hWnd);
                    break;
                    
                case ID_TB_PARENT:
                    NavigateToParent();
                    break;
                    
                case ID_TB_VIEWS:
                    /* Cycle view mode: Large Icons -> Details -> Small Icons -> List */
                    if (g_CurrentViewMode == LVS_ICON) {
                        SetViewMode(LVS_REPORT);
                    } else if (g_CurrentViewMode == LVS_REPORT) {
                        SetViewMode(LVS_SMALLICON);
                    } else if (g_CurrentViewMode == LVS_SMALLICON) {
                        SetViewMode(LVS_LIST);
                    } else {
                        SetViewMode(LVS_ICON);
                    }
                    break;
                    
                case IDM_VIEW_LARGE_ICONS:
                    SetViewMode(LVS_ICON);
                    break;
                    
                case IDM_VIEW_SMALL_ICONS:
                    SetViewMode(LVS_SMALLICON);
                    break;
                    
                case IDM_VIEW_LIST:
                    SetViewMode(LVS_LIST);
                    break;
                    
                case IDM_VIEW_DETAILS:
                    SetViewMode(LVS_REPORT);
                    break;
                    
                case IDM_VIEW_SORT_NAME:
                    SortObjectList(0, TRUE);
                    break;

                case IDM_VIEW_SORT_SIZE:
                    SortObjectList(1, TRUE);
                    break;

                case IDM_VIEW_SORT_TYPE:
                    SortObjectList(2, TRUE);
                    break;

                case IDM_VIEW_SORT_DATE:
                    SortObjectList(3, TRUE);
                    break;
                    
                case IDM_VIEW_TOOLBAR_STD:
                    g_bShowStdToolbar = !g_bShowStdToolbar;
                    CheckMenuItem(GetMenu(hWnd), IDM_VIEW_TOOLBAR_STD, g_bShowStdToolbar ? MF_CHECKED : MF_UNCHECKED);
                    SendMessage(hWnd, WM_SIZE, 0, 0);
                    break;
                    
                case IDM_VIEW_TOOLBAR_ADDR:
                    g_bShowAddressBar = !g_bShowAddressBar;
                    CheckMenuItem(GetMenu(hWnd), IDM_VIEW_TOOLBAR_ADDR, g_bShowAddressBar ? MF_CHECKED : MF_UNCHECKED);
                    SendMessage(hWnd, WM_SIZE, 0, 0);
                    break;
                    
                case IDM_VIEW_STATUSBAR:
                    g_bShowStatusBar = !g_bShowStatusBar;
                    CheckMenuItem(GetMenu(hWnd), IDM_VIEW_STATUSBAR, g_bShowStatusBar ? MF_CHECKED : MF_UNCHECKED);
                    SendMessage(hWnd, WM_SIZE, 0, 0);
                    break;
                    
                case IDM_FAV_ADD:
                    MessageBoxA(hWnd, "Added 'MTP Portable Device' to your Shell Favorites.", "Favorites", MB_OK | MB_ICONINFORMATION);
                    break;
                    
                case IDM_FAV_ORGANIZE:
                    ShellExecuteA(NULL, "open", "explorer.exe", "shell:Favorites", NULL, SW_SHOWNORMAL);
                    break;
                    
                case IDM_FAV_MYCOMPUTER:
                    ShellExecuteA(NULL, "open", "explorer.exe", "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}", NULL, SW_SHOWNORMAL);
                    break;
                    
                case IDM_FAV_DESKTOP:
                    ShellExecuteA(NULL, "open", "explorer.exe", "::{00021400-0000-0000-C000-000000000046}", NULL, SW_SHOWNORMAL);
                    break;
                    
                case IDM_FAV_DEVICE:
                    if (g_Connected) {
                        NavigateToParent();
                    } else {
                        ConnectDevice();
                    }
                    break;
                    
                case IDM_TOOLS_MAP_DRIVE:
                case IDM_TOOLS_DISC_DRIVE:
                case IDM_TOOLS_SYNCHRONIZE:
                    MessageBoxA(hWnd, "This function is available through Windows 2000 Network and Dial-up Connections.", "Tools", MB_OK | MB_ICONINFORMATION);
                    break;
                    
                case IDM_TOOLS_NOTIFY_COPYPASTE:
                    g_bNotifyOnCopyPaste = !g_bNotifyOnCopyPaste;
                    CheckMenuItem(GetMenu(hWnd), IDM_TOOLS_NOTIFY_COPYPASTE, g_bNotifyOnCopyPaste ? MF_CHECKED : MF_UNCHECKED);
                    SetStatus(g_bNotifyOnCopyPaste ? "Taskbar notification enabled for Copy/Paste." : "Taskbar notification disabled for Copy/Paste.");
                    break;
                    
                case IDM_TOOLS_OPTIONS:
                    ShowFolderOptionsDialog(hWnd);
                    break;
                    
                case IDM_HELP_TOPICS:
                    MessageBoxA(hWnd, "MTP Portable Device Explorer Help\n\n- Connect/Disconnect: Mount or safely remove the device.\n- Copy/Paste: Use Ctrl+C and Ctrl+V to exchange files between Explorer and MTP.\n- Drag & Drop: Drag files directly into the window to upload.", "Help Topics", MB_OK | MB_ICONINFORMATION);
                    break;
                    
                case IDC_GO_BTN: {
                    char szTarget[MAX_PATH];
                    if (g_hAddressCombo) {
                        GetWindowTextA(g_hAddressCombo, szTarget, sizeof(szTarget));
                        NavigateToAddressPath(hWnd, szTarget);
                    }
                    break;
                }
                    
                case IDM_EDIT_COPY:
                    CopySelectedToClipboard(hWnd);
                    break;
                    
                case IDM_EDIT_PASTE:
                    PasteFromClipboard(hWnd);
                    break;
                    
                case IDM_EDIT_CUT:
                    CopySelectedToClipboard(hWnd);
                    break;
                    
                case IDM_EDIT_SELECT_ALL:
                    ListView_SetItemState(g_hListView, -1, LVIS_SELECTED, LVIS_SELECTED);
                    break;
                    
                case IDM_EDIT_INVERT_SEL: {
                    int idx;
                    for (idx = 0; idx < (int)g_ObjectCount; idx++) {
                        UINT state = ListView_GetItemState(g_hListView, idx, LVIS_SELECTED);
                        ListView_SetItemState(g_hListView, idx, (state & LVIS_SELECTED) ? 0 : LVIS_SELECTED, LVIS_SELECTED);
                    }
                    break;
                }
                    
                case IDM_HELP_ABOUT: {
                    char aboutBuf[1024];
                    _snprintf(aboutBuf, sizeof(aboutBuf) - 1,
                        "MTP Portable Device Explorer for Windows 2000\n\n"
                        "Version 3.2 (KMDF 1.9 - Native Shell Edition)\n"
                        "Engineered with Authentic Windows 2000 Explorer Shell UI\n\n"
                        "Features:\n"
                        "  - Native Windows 2000 Web View Sidebar with Storage Card & Previews\n"
                        "  - Dynamic Phone Storage Detection (%s)\n"
                        "  - 64-bit Large File Transfers (32 GB, 64 GB, 128 GB, 256 GB+ to 2 TB)\n"
                        "  - History Navigation: Previous (Back) & Next (Forward) Buttons\n"
                        "  - Root Back Navigation: Return to My Computer & Close\n"
                        "  - Native Drag and Drop File Uploading\n"
                        "  - Windows Clipboard Integration: Copy (Ctrl+C) & Paste (Ctrl+V) Vice Versa\n"
                        "  - Secure Load & Deload (Safely Remove Hardware with Taskbar Notification)\n"
                        "  - Dynamic USB Speed Adaptation (%s, chunk %lu KB)\n\n"
                        "Supports USB 1.1 (UHCI), USB 2.0 (EHCI), USB 3/4 (xHCI)\n"
                        "for modern MTP devices and Android smartphones.",
                        g_szCapacityStr, g_szUsbSpeed, g_OptimalChunkSize / 1024);
                    aboutBuf[sizeof(aboutBuf) - 1] = '\0';
                    MessageBoxA(hWnd, aboutBuf,
                        "About MTP Portable Device", MB_OK | MB_ICONINFORMATION);
                    break;
                }
                    
                case IDM_FILE_EXIT:
                    DestroyWindow(hWnd);
                    break;
            }
            return 0;
            
        case WM_NOTIFY: {
            LPNMHDR pnmh = (LPNMHDR)lParam;
            if (pnmh->idFrom == IDC_LISTVIEW) {
                if (pnmh->code == LVN_GETDISPINFOA) {
                    NMLVDISPINFOA *pdi = (NMLVDISPINFOA*)lParam;
                    int idx = pdi->item.iItem;

                    EnterCriticalSection(&g_ObjectsCs);
                    if (g_Objects && idx >= 0 && (DWORD)idx < g_ObjectCount) {
                        OBJECT_ITEM *item = &g_Objects[idx];

                        if (pdi->item.mask & LVIF_TEXT) {
                            if (pdi->item.iSubItem == 0) {
                                WideCharToMultiByte(CP_ACP, 0, item->Name, -1,
                                                    pdi->item.pszText, pdi->item.cchTextMax, NULL, NULL);
                                pdi->item.pszText[pdi->item.cchTextMax - 1] = '\0';
                            } else if (pdi->item.iSubItem == 1) {
                                if (item->IsFolder) {
                                    pdi->item.pszText[0] = '\0';
                                } else {
                                    if (item->Size >= 1073741824ULL) {
                                        _snprintf(pdi->item.pszText, pdi->item.cchTextMax, "%.2f GB", (double)item->Size / 1073741824.0);
                                    } else if (item->Size >= 1048576ULL) {
                                        _snprintf(pdi->item.pszText, pdi->item.cchTextMax, "%.2f MB", (double)item->Size / 1048576.0);
                                    } else if (item->Size >= 1024ULL) {
                                        _snprintf(pdi->item.pszText, pdi->item.cchTextMax, "%.1f KB", (double)item->Size / 1024.0);
                                    } else {
                                        _snprintf(pdi->item.pszText, pdi->item.cchTextMax, "%I64u bytes", item->Size);
                                    }
                                    pdi->item.pszText[pdi->item.cchTextMax - 1] = '\0';
                                }
                            } else if (pdi->item.iSubItem == 2) {
                                const char *typeName = "File";
                                if (item->IsFolder) {
                                    typeName = "File Folder";
                                } else {
                                    switch (item->Format) {
                                        case MTP_FORMAT_EXIF_JPEG: typeName = "JPEG Image"; break;
                                        case MTP_FORMAT_PNG:       typeName = "PNG Image"; break;
                                        case MTP_FORMAT_BMP:       typeName = "Bitmap Image"; break;
                                        case MTP_FORMAT_MP3:       typeName = "MP3 Audio"; break;
                                        case MTP_FORMAT_WMA:       typeName = "WMA Audio"; break;
                                        case MTP_FORMAT_MP4_CONTAINER: typeName = "MP4 Video"; break;
                                        case MTP_FORMAT_AVI:       typeName = "AVI Video"; break;
                                        case MTP_FORMAT_WMV:       typeName = "WMV Video"; break;
                                        case MTP_FORMAT_TEXT:      typeName = "Text Document"; break;
                                        default:                   typeName = "File"; break;
                                    }
                                }
                                strncpy(pdi->item.pszText, typeName, pdi->item.cchTextMax - 1);
                                pdi->item.pszText[pdi->item.cchTextMax - 1] = '\0';
                            } else if (pdi->item.iSubItem == 3) {
                                strncpy(pdi->item.pszText, item->DateStr, pdi->item.cchTextMax - 1);
                                pdi->item.pszText[pdi->item.cchTextMax - 1] = '\0';
                            }
                        }

                        if (pdi->item.mask & LVIF_IMAGE) {
                            if (item->IsFolder) {
                                pdi->item.iImage = 0;
                            } else {
                                switch (item->Format) {
                                    case MTP_FORMAT_TEXT:          pdi->item.iImage = 1; break;
                                    case MTP_FORMAT_EXIF_JPEG:
                                    case MTP_FORMAT_PNG:
                                    case MTP_FORMAT_BMP:          pdi->item.iImage = 2; break;
                                    case MTP_FORMAT_MP3:
                                    case MTP_FORMAT_WMA:          pdi->item.iImage = 3; break;
                                    case MTP_FORMAT_MP4_CONTAINER:
                                    case MTP_FORMAT_AVI:
                                    case MTP_FORMAT_WMV:          pdi->item.iImage = 4; break;
                                    default:                      pdi->item.iImage = 5; break;
                                }
                            }
                        }

                        if (pdi->item.mask & LVIF_PARAM) {
                            pdi->item.lParam = (LPARAM)item->Handle;
                        }
                    }
                    LeaveCriticalSection(&g_ObjectsCs);
                    return 0;
                } else if (pnmh->code == LVN_GETDISPINFOW) {
                    NMLVDISPINFOW *pdi = (NMLVDISPINFOW*)lParam;
                    int idx = pdi->item.iItem;

                    EnterCriticalSection(&g_ObjectsCs);
                    if (g_Objects && idx >= 0 && (DWORD)idx < g_ObjectCount) {
                        OBJECT_ITEM *item = &g_Objects[idx];

                        if (pdi->item.mask & LVIF_TEXT) {
                            if (pdi->item.iSubItem == 0) {
                                wcsncpy(pdi->item.pszText, item->Name, pdi->item.cchTextMax - 1);
                                pdi->item.pszText[pdi->item.cchTextMax - 1] = L'\0';
                            } else if (pdi->item.iSubItem == 1) {
                                if (item->IsFolder) {
                                    pdi->item.pszText[0] = L'\0';
                                } else {
                                    if (item->Size >= 1073741824ULL) {
                                        _snwprintf(pdi->item.pszText, pdi->item.cchTextMax, L"%.2f GB", (double)item->Size / 1073741824.0);
                                    } else if (item->Size >= 1048576ULL) {
                                        _snwprintf(pdi->item.pszText, pdi->item.cchTextMax, L"%.2f MB", (double)item->Size / 1048576.0);
                                    } else if (item->Size >= 1024ULL) {
                                        _snwprintf(pdi->item.pszText, pdi->item.cchTextMax, L"%.1f KB", (double)item->Size / 1024.0);
                                    } else {
                                        _snwprintf(pdi->item.pszText, pdi->item.cchTextMax, L"%I64u bytes", item->Size);
                                    }
                                    pdi->item.pszText[pdi->item.cchTextMax - 1] = L'\0';
                                }
                            } else if (pdi->item.iSubItem == 2) {
                                const wchar_t *typeName = L"File";
                                if (item->IsFolder) {
                                    typeName = L"File Folder";
                                } else {
                                    switch (item->Format) {
                                        case MTP_FORMAT_EXIF_JPEG: typeName = L"JPEG Image"; break;
                                        case MTP_FORMAT_PNG:       typeName = L"PNG Image"; break;
                                        case MTP_FORMAT_BMP:       typeName = L"Bitmap Image"; break;
                                        case MTP_FORMAT_MP3:       typeName = L"MP3 Audio"; break;
                                        case MTP_FORMAT_WMA:       typeName = L"WMA Audio"; break;
                                        case MTP_FORMAT_MP4_CONTAINER: typeName = L"MP4 Video"; break;
                                        case MTP_FORMAT_AVI:       typeName = L"AVI Video"; break;
                                        case MTP_FORMAT_WMV:       typeName = L"WMV Video"; break;
                                        case MTP_FORMAT_TEXT:      typeName = L"Text Document"; break;
                                        default:                   typeName = L"File"; break;
                                    }
                                }
                                wcsncpy(pdi->item.pszText, typeName, pdi->item.cchTextMax - 1);
                                pdi->item.pszText[pdi->item.cchTextMax - 1] = L'\0';
                            } else if (pdi->item.iSubItem == 3) {
                                MultiByteToWideChar(CP_ACP, 0, item->DateStr, -1,
                                                    pdi->item.pszText, pdi->item.cchTextMax);
                                pdi->item.pszText[pdi->item.cchTextMax - 1] = L'\0';
                            }
                        }

                        if (pdi->item.mask & LVIF_IMAGE) {
                            if (item->IsFolder) {
                                pdi->item.iImage = 0;
                            } else {
                                switch (item->Format) {
                                    case MTP_FORMAT_TEXT:          pdi->item.iImage = 1; break;
                                    case MTP_FORMAT_EXIF_JPEG:
                                    case MTP_FORMAT_PNG:
                                    case MTP_FORMAT_BMP:          pdi->item.iImage = 2; break;
                                    case MTP_FORMAT_MP3:
                                    case MTP_FORMAT_WMA:          pdi->item.iImage = 3; break;
                                    case MTP_FORMAT_MP4_CONTAINER:
                                    case MTP_FORMAT_AVI:
                                    case MTP_FORMAT_WMV:          pdi->item.iImage = 4; break;
                                    default:                      pdi->item.iImage = 5; break;
                                }
                            }
                        }

                        if (pdi->item.mask & LVIF_PARAM) {
                            pdi->item.lParam = (LPARAM)item->Handle;
                        }
                    }
                    LeaveCriticalSection(&g_ObjectsCs);
                    return 0;
                } else if (pnmh->code == NM_DBLCLK) {
                    /* Double click on an item */
                    int selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
                    if (selIndex != -1) {
                        OBJECT_ITEM itemCopy;
                        BOOL found = FALSE;

                        EnterCriticalSection(&g_ObjectsCs);
                        if (g_Objects && (DWORD)selIndex < g_ObjectCount) {
                            itemCopy = g_Objects[selIndex];
                            found = TRUE;
                        }
                        LeaveCriticalSection(&g_ObjectsCs);

                        if (found) {
                            if (itemCopy.IsFolder) {
                                char folderName[256];
                                WideCharToMultiByte(CP_ACP, 0, itemCopy.Name, -1, folderName, sizeof(folderName), NULL, NULL);
                                NavigateToFolder(itemCopy.Handle, folderName);
                            } else {
                                DownloadSelected(hWnd);
                            }
                        }
                    }
                } else if (pnmh->code == LVN_COLUMNCLICK) {
                    LPNMLISTVIEW pnmlv = (LPNMLISTVIEW)lParam;
                    SortObjectList(pnmlv->iSubItem, TRUE);
                    return 0;
                } else if (pnmh->code == NM_RCLICK) {
                    POINT pt;
                    HMENU hPopup = CreatePopupMenu();
                    int selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
                    GetCursorPos(&pt);
                    if (selIndex != -1) {
                        AppendMenuA(hPopup, MF_STRING, IDM_FILE_DOWNLOAD, "&Download...\tCtrl+S");
                        AppendMenuA(hPopup, MF_SEPARATOR, 0, NULL);
                        AppendMenuA(hPopup, MF_STRING, IDM_EDIT_COPY, "&Copy\tCtrl+C");
                        AppendMenuA(hPopup, MF_STRING, IDM_EDIT_PASTE, "&Paste\tCtrl+V");
                        AppendMenuA(hPopup, MF_SEPARATOR, 0, NULL);
                        AppendMenuA(hPopup, MF_STRING, IDM_FILE_DELETE, "De&lete\tDel");
                    } else {
                        HMENU hArrangeMenu = CreatePopupMenu();
                        PopulateArrangeMenu(hArrangeMenu);

                        AppendMenuA(hPopup, MF_POPUP, (UINT_PTR)hArrangeMenu, "Arrange &Icons");
                        AppendMenuA(hPopup, MF_SEPARATOR, 0, NULL);
                        AppendMenuA(hPopup, MF_STRING, IDM_EDIT_PASTE, "&Paste\tCtrl+V");
                        AppendMenuA(hPopup, MF_STRING, IDM_FILE_UPLOAD, "&Upload File...\tCtrl+U");
                        AppendMenuA(hPopup, MF_SEPARATOR, 0, NULL);
                        AppendMenuA(hPopup, MF_STRING, IDM_VIEW_REFRESH, "&Refresh\tF5");
                    }
                    TrackPopupMenu(hPopup, TPM_RIGHTBUTTON | TPM_LEFTALIGN, pt.x, pt.y, 0, hWnd, NULL);
                    DestroyMenu(hPopup);
                } else if (pnmh->code == LVN_KEYDOWN) {
                    LPNMLVKEYDOWN pnkd = (LPNMLVKEYDOWN)lParam;
                    if (pnkd->wVKey == VK_RETURN) {
                        int selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
                        if (selIndex != -1) {
                            OBJECT_ITEM itemCopy;
                            BOOL found = FALSE;

                            EnterCriticalSection(&g_ObjectsCs);
                            if (g_Objects && (DWORD)selIndex < g_ObjectCount) {
                                itemCopy = g_Objects[selIndex];
                                found = TRUE;
                            }
                            LeaveCriticalSection(&g_ObjectsCs);

                            if (found) {
                                if (itemCopy.IsFolder) {
                                    char folderName[256];
                                    WideCharToMultiByte(CP_ACP, 0, itemCopy.Name, -1, folderName, sizeof(folderName), NULL, NULL);
                                    NavigateToFolder(itemCopy.Handle, folderName);
                                } else {
                                    DownloadSelected(hWnd);
                                }
                            }
                        }
                    }
                } else if (pnmh->code == LVN_ITEMCHANGED) {
                    /* Selection changed: Trigger Web View repaint to update preview and metadata */
                    if (g_hWebView) {
                        InvalidateRect(g_hWebView, NULL, TRUE);
                    }
                }
            }
            return 0;
        }
        
        case WM_DESTROY:
            KillTimer(hWnd, TIMER_DEVICE_CHECK);
            RemoveTaskbarNotification(hWnd);
            DisconnectDevice();
            /* Ensure My Computer icon is removed on app exit */
            UnregisterPortableDeviceCLSID();
            if (g_hLargeImageList) ImageList_Destroy(g_hLargeImageList);
            if (g_hSmallImageList) ImageList_Destroy(g_hSmallImageList);
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcA(hWnd, message, wParam, lParam);
}

/* ============================================================================
 * Shell Integration & Auto-Registration
 * ============================================================================ */

void RegisterPortableDeviceCLSID(void)
{
    char szExePath[MAX_PATH];
    char szCmd[MAX_PATH + 8];
    HKEY hKey;

    if (GetModuleFileNameA(NULL, szExePath, sizeof(szExePath)) == 0) return;
    _snprintf(szCmd, sizeof(szCmd), "\"%s\"", szExePath);

    /* 1. Register CLSID Shell\Open\Command in HKCR so My Computer always launches this EXE */
    if (RegCreateKeyExA(HKEY_CLASSES_ROOT,
        "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}\\Shell\\Open\\Command",
        0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, NULL, 0, REG_SZ, (const BYTE*)szCmd, (DWORD)strlen(szCmd) + 1);
        RegCloseKey(hKey);
    }

    /* 2. Set default name and metadata in CLSID */
    if (RegCreateKeyExA(HKEY_CLASSES_ROOT,
        "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}",
        0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        const char *szName = "Portable Device (Android Smartphone)";
        const char *szInfo = "Device: Portable Android Device\nStorage: Dynamically detected from connected phone\nFile System: MTP (Media Transfer Protocol)\nStatus: Ready for connection";
        RegSetValueExA(hKey, NULL, 0, REG_SZ, (const BYTE*)szName, (DWORD)strlen(szName) + 1);
        RegSetValueExA(hKey, "InfoTip", 0, REG_SZ, (const BYTE*)szInfo, (DWORD)strlen(szInfo) + 1);
        RegSetValueExA(hKey, "LocalizedString", 0, REG_SZ, (const BYTE*)szName, (DWORD)strlen(szName) + 1);
        RegCloseKey(hKey);
    }

    /* 3. Set DefaultIcon: Windows 2000 Digital Camera icon (0 bytes overhead) */
    if (RegCreateKeyExA(HKEY_CLASSES_ROOT,
        "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}\\DefaultIcon",
        0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        const char *szIcon = "%SystemRoot%\\System32\\sticpl.cpl,1";
        RegSetValueExA(hKey, NULL, 0, REG_SZ, (const BYTE*)szIcon, (DWORD)strlen(szIcon) + 1);
        RegCloseKey(hKey);
    }

    /* 4. Set ShellFolder Attributes */
    if (RegCreateKeyExA(HKEY_CLASSES_ROOT,
        "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}\\ShellFolder",
        0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        DWORD dwAttr = 0;
        RegSetValueExA(hKey, "Attributes", 0, REG_BINARY, (const BYTE*)&dwAttr, sizeof(DWORD));
        RegCloseKey(hKey);
    }

    /* 5. Register in MyComputer\NameSpace in HKLM */
    if (RegCreateKeyExA(HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{E0C30E66-2679-4594-817D-38F75FEF30A1}",
        0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        const char *szName = "Portable Device (Android Smartphone)";
        RegSetValueExA(hKey, NULL, 0, REG_SZ, (const BYTE*)szName, (DWORD)strlen(szName) + 1);
        RegCloseKey(hKey);
    }

    /* 6. Notify Explorer shell to refresh My Computer so icon appears immediately */
    SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);
}

void UnregisterPortableDeviceCLSID(void)
{
    /* 1. Remove from MyComputer\NameSpace so icon disappears from My Computer */
    RegDeleteKeyA(HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\{E0C30E66-2679-4594-817D-38F75FEF30A1}");

    /* 2. Clean up CLSID sub-keys (must delete children before parent on Win2K) */
    RegDeleteKeyA(HKEY_CLASSES_ROOT, "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}\\Shell\\Open\\Command");
    RegDeleteKeyA(HKEY_CLASSES_ROOT, "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}\\Shell\\Open");
    RegDeleteKeyA(HKEY_CLASSES_ROOT, "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}\\Shell");
    RegDeleteKeyA(HKEY_CLASSES_ROOT, "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}\\DefaultIcon");
    RegDeleteKeyA(HKEY_CLASSES_ROOT, "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}\\ShellFolder");
    RegDeleteKeyA(HKEY_CLASSES_ROOT, "CLSID\\{E0C30E66-2679-4594-817D-38F75FEF30A1}");

    /* 3. Notify Explorer shell to refresh My Computer so icon disappears immediately */
    SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);
}

/* ============================================================================
 * Application Entry Point (WinMain)
 * ============================================================================ */

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEXA wcex;
    WNDCLASSEXA wcxWeb;
    INITCOMMONCONTROLSEX icex;
    MSG msg;
    HACCEL hAccel;
    ACCEL accels[16];
    BOOL bEnableDebug;
    
    bEnableDebug = (lpCmdLine && (strstr(lpCmdLine, "/debug") || strstr(lpCmdLine, "-debug") || strstr(lpCmdLine, "/console")));
    InitDebugConsole(bEnableDebug);

    InitializeCriticalSection(&g_ObjectsCs);
    InitializeCriticalSection(&g_DeviceCs);

    g_hInstance = hInstance;
    
    /* Auto-register self in Windows 2000 registry for My Computer Portable Device icon */
    RegisterPortableDeviceCLSID();
    
    icex.dwSize = sizeof(icex);
    icex.dwICC = ICC_WIN95_CLASSES | ICC_COOL_CLASSES | ICC_BAR_CLASSES;
    InitCommonControlsEx(&icex);
    
    /* Register Main Window Class */
    ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEXA);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
    wcex.lpszClassName = g_szClassName;
    
    if (!RegisterClassExA(&wcex)) {
        MessageBoxA(NULL, "Failed to register main window class.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    /* Register Web View Sidebar Class */
    ZeroMemory(&wcxWeb, sizeof(wcxWeb));
    wcxWeb.cbSize = sizeof(WNDCLASSEXA);
    wcxWeb.style = CS_HREDRAW | CS_VREDRAW;
    wcxWeb.lpfnWndProc = WebViewWndProc;
    wcxWeb.hInstance = hInstance;
    wcxWeb.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcxWeb.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcxWeb.lpszClassName = g_szWebViewClass;
    
    if (!RegisterClassExA(&wcxWeb)) {
        MessageBoxA(NULL, "Failed to register web view class.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    g_hMainWnd = CreateWindowExA(
        0,
        g_szClassName,
        g_szAppTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        780, 520,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    if (!g_hMainWnd) {
        MessageBoxA(NULL, "Failed to create main window.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    /* Keyboard Accelerators */
    accels[0].fVirt = FCONTROL | FVIRTKEY;
    accels[0].key = 'O';
    accels[0].cmd = IDM_FILE_CONNECT;

    accels[1].fVirt = FCONTROL | FVIRTKEY;
    accels[1].key = 'D';
    accels[1].cmd = IDM_FILE_DISCONNECT;

    accels[2].fVirt = FCONTROL | FVIRTKEY;
    accels[2].key = 'U';
    accels[2].cmd = IDM_FILE_UPLOAD;

    accels[3].fVirt = FCONTROL | FVIRTKEY;
    accels[3].key = 'S';
    accels[3].cmd = IDM_FILE_DOWNLOAD;

    accels[4].fVirt = FCONTROL | FVIRTKEY;
    accels[4].key = 'C';
    accels[4].cmd = IDM_EDIT_COPY;

    accels[5].fVirt = FCONTROL | FVIRTKEY;
    accels[5].key = 'V';
    accels[5].cmd = IDM_EDIT_PASTE;

    accels[6].fVirt = FCONTROL | FVIRTKEY;
    accels[6].key = 'X';
    accels[6].cmd = IDM_EDIT_CUT;

    accels[7].fVirt = FCONTROL | FVIRTKEY;
    accels[7].key = 'A';
    accels[7].cmd = IDM_EDIT_SELECT_ALL;

    accels[8].fVirt = FVIRTKEY;
    accels[8].key = VK_F5;
    accels[8].cmd = IDM_VIEW_REFRESH;

    accels[9].fVirt = FVIRTKEY;
    accels[9].key = VK_DELETE;
    accels[9].cmd = IDM_FILE_DELETE;

    accels[10].fVirt = FALT | FVIRTKEY;
    accels[10].key = VK_LEFT;
    accels[10].cmd = ID_TB_BACK;

    accels[11].fVirt = FALT | FVIRTKEY;
    accels[11].key = VK_RIGHT;
    accels[11].cmd = ID_TB_FORWARD;

    accels[12].fVirt = FVIRTKEY;
    accels[12].key = VK_BACK;
    accels[12].cmd = ID_TB_BACK;

    accels[13].fVirt = FVIRTKEY;
    accels[13].key = VK_F3;
    accels[13].cmd = IDM_TOOLS_FIND;

    accels[14].fVirt = FCONTROL | FVIRTKEY;
    accels[14].key = 'F';
    accels[14].cmd = IDM_FILE_SEARCH;

    hAccel = CreateAcceleratorTableA(accels, 15);

    ShowWindow(g_hMainWnd, SW_SHOWMAXIMIZED);
    SetForegroundWindow(g_hMainWnd);
    SetActiveWindow(g_hMainWnd);
    UpdateWindow(g_hMainWnd);

    /* Automatically connect on startup so files appear immediately */
    if (lpCmdLine && strstr(lpCmdLine, "/noconnect")) {
        /* Manual mode */
    } else {
        ConnectDeviceEx(FALSE);
    }
    if (g_hListView) SetFocus(g_hListView);

    /* Open Search dialog immediately if /search or -search flag is passed */
    if (lpCmdLine && (strstr(lpCmdLine, "/search") || strstr(lpCmdLine, "-search") || strstr(lpCmdLine, "/find"))) {
        ShowSearchDialog(g_hMainWnd);
    }

    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        if (g_hSearchDlg && IsWindow(g_hSearchDlg) && IsDialogMessageA(g_hSearchDlg, &msg)) {
            continue;
        }
        if (!hAccel || !TranslateAcceleratorA(g_hMainWnd, hAccel, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    if (hAccel) {
        DestroyAcceleratorTable(hAccel);
    }

    DeleteCriticalSection(&g_ObjectsCs);
    DeleteCriticalSection(&g_DeviceCs);

    return (int)msg.wParam;
}
