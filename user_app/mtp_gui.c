/*
 * mtp_gui.c - MTP File Transfer GUI Application for Windows 2000
 * 
 * A classic Win32 GUI application for browsing and transferring files
 * between the PC and MTP devices (phones, cameras, etc.)
 * 
 * Written for C89 compatibility with Windows 2000 DDK compiler
 */

#define _WIN32_WINNT 0x0500
#define WINVER 0x0500
#define _WIN32_IE 0x0500

#include <windows.h>
#include <commctrl.h>
#include <commdlg.h>
#include <shellapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================================
 * Resource IDs
 * ============================================================================ */

#define IDM_FILE_CONNECT    201
#define IDM_FILE_DISCONNECT 202
#define IDM_FILE_EXIT       203
#define IDM_TRANSFER_DOWNLOAD 210
#define IDM_TRANSFER_UPLOAD 211
#define IDM_TRANSFER_DELETE 212
#define IDM_TRANSFER_REFRESH 213
#define IDM_VIEW_DETAILS    220
#define IDM_VIEW_ICONS      221
#define IDM_HELP_ABOUT      230

#define IDC_TOOLBAR         300
#define IDC_STATUSBAR       301
#define IDC_LISTVIEW        302

/* Toolbar button IDs */
#define ID_TB_CONNECT       500
#define ID_TB_DISCONNECT    501
#define ID_TB_REFRESH       502
#define ID_TB_DOWNLOAD      503
#define ID_TB_UPLOAD        504
#define ID_TB_DELETE        505
#define ID_TB_PARENT        506

/* ============================================================================
 * IOCTL Definitions (must match driver's Mtp.h)
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

#define DEVICE_NAME "\\\\.\\MtpDevice"

/* MTP Operation Codes */
#define MTP_OP_GET_DEVICE_INFO       0x1001
#define MTP_OP_GET_STORAGE_IDS       0x1004
#define MTP_OP_GET_OBJECT_HANDLES    0x1007
#define MTP_OP_GET_OBJECT_INFO       0x1008
#define MTP_OP_DELETE_OBJECT         0x100B

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

/* ============================================================================
 * Structures
 * ============================================================================ */

#pragma pack(push, 1)
typedef struct _MTP_GET_PART_REQ {
    DWORD Id;
    DWORD Offset;
    DWORD Length;
} MTP_GET_PART_REQ;
#pragma pack(pop)

typedef struct _OBJECT_ITEM {
    DWORD   Handle;
    DWORD   ParentHandle;
    DWORD   StorageId;
    WORD    Format;
    DWORD   Size;
    WCHAR   Name[256];
    BOOL    IsFolder;
} OBJECT_ITEM;

/* ============================================================================
 * Global Variables
 * ============================================================================ */

static HINSTANCE g_hInstance = NULL;
static HWND g_hMainWnd = NULL;
static HWND g_hToolbar = NULL;
static HWND g_hStatusBar = NULL;
static HWND g_hListView = NULL;
static HIMAGELIST g_hSmallImageList = NULL;

static HANDLE g_hDevice = INVALID_HANDLE_VALUE;
static DWORD g_SessionId = 0;
static BOOL g_Connected = FALSE;

static OBJECT_ITEM *g_Objects = NULL;
static DWORD g_ObjectCount = 0;
static DWORD g_CurrentStorage = 0;
static DWORD g_CurrentParent = 0;

/* Transfer buffer size - 16KB max for Win2000 USB stack stability */
/* Larger buffers can cause IRP fragmentation on UHCI controllers */
#define TRANSFER_BUFFER_SIZE  16384

/* Cancel flag for transfer operations */
static volatile BOOL g_CancelTransfer = FALSE;

static const char g_szClassName[] = "MtpTransferClass";
static const char g_szAppTitle[] = "MTP File Transfer - Windows 2000";

/* ============================================================================
 * Forward Declarations
 * ============================================================================ */

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CreateMainMenu(HWND hWnd);
void CreateToolbar(HWND hWnd);
void CreateStatusBar(HWND hWnd);
void CreateListView(HWND hWnd);
void UpdateUI(void);
void SetStatus(const char *text);
BOOL ConnectDevice(void);
void DisconnectDevice(void);
BOOL RefreshObjects(void);
BOOL DownloadSelected(HWND hWnd);
BOOL UploadFile(HWND hWnd);
BOOL DeleteSelected(HWND hWnd);
void NavigateToParent(void);
void NavigateToFolder(DWORD handle);

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
    
    result = DeviceIoControl(
        g_hDevice,
        IOCTL_MTP_OPERATION,
        inputBuffer, inputSize,
        recvBuffer, recvBufferSize,
        &bytesRet,
        NULL
    );
    
    free(inputBuffer);
    if (bytesReceived) *bytesReceived = bytesRet;
    return result;
}

BYTE* ReadMtpString(BYTE *buf, DWORD maxLen, WCHAR *outStr, DWORD outMaxChars)
{
    BYTE len;
    DWORD i;
    
    if (maxLen < 1) return NULL;
    len = buf[0];
    
    if (len == 0) {
        outStr[0] = L'\0';
        return buf + 1;
    }
    
    if (maxLen < (DWORD)(1 + len * 2)) return NULL;
    
    for (i = 0; i < len && i < outMaxChars - 1; i++) {
        outStr[i] = (WCHAR)(buf[1 + i*2] | (buf[1 + i*2 + 1] << 8));
    }
    outStr[i] = L'\0';
    
    return buf + 1 + len * 2;
}

const char* GetFormatName(WORD format)
{
    switch (format) {
        case MTP_FORMAT_ASSOCIATION: return "Folder";
        case MTP_FORMAT_TEXT:        return "Text";
        case MTP_FORMAT_MP3:         return "MP3";
        case MTP_FORMAT_AVI:         return "AVI";
        case MTP_FORMAT_MPEG:        return "MPEG";
        case MTP_FORMAT_EXIF_JPEG:   return "JPEG";
        case MTP_FORMAT_BMP:         return "BMP";
        case MTP_FORMAT_PNG:         return "PNG";
        case MTP_FORMAT_WMA:         return "WMA";
        case MTP_FORMAT_MP4_CONTAINER: return "MP4";
        case MTP_FORMAT_WMV:         return "WMV";
        default:                     return "File";
    }
}

void FormatFileSize(DWORD size, char *buffer, int bufLen)
{
    if (size >= 1073741824) {
        _snprintf(buffer, bufLen, "%.2f GB", (double)size / 1073741824.0);
    } else if (size >= 1048576) {
        _snprintf(buffer, bufLen, "%.2f MB", (double)size / 1048576.0);
    } else if (size >= 1024) {
        _snprintf(buffer, bufLen, "%.2f KB", (double)size / 1024.0);
    } else {
        _snprintf(buffer, bufLen, "%lu bytes", size);
    }
}

/* ============================================================================
 * Device Operations
 * ============================================================================ */

BOOL ConnectDevice(void)
{
    DWORD bytesReturned;
    BYTE buffer[1024];
    DWORD count;
    char statusText[128];
    
    if (g_Connected) {
        MessageBoxA(g_hMainWnd, "Already connected to device.", "MTP Transfer", MB_OK | MB_ICONINFORMATION);
        return TRUE;
    }
    
    SetStatus("Connecting to device...");
    
    g_hDevice = CreateFileA(
        DEVICE_NAME,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    if (g_hDevice == INVALID_HANDLE_VALUE) {
        MessageBoxA(g_hMainWnd, 
            "Failed to open MTP device.\n\n"
            "Please ensure:\n"
            "- MTP driver is installed\n"
            "- Device is connected via USB\n"
            "- Device is in MTP mode",
            "Connection Error", MB_OK | MB_ICONERROR);
        SetStatus("Connection failed");
        return FALSE;
    }
    
    if (!DeviceIoControl(g_hDevice, IOCTL_MTP_SESSION_OPEN,
                         NULL, 0, &g_SessionId, sizeof(g_SessionId),
                         &bytesReturned, NULL)) {
        CloseHandle(g_hDevice);
        g_hDevice = INVALID_HANDLE_VALUE;
        MessageBoxA(g_hMainWnd, "Failed to open MTP session.", "Connection Error", MB_OK | MB_ICONERROR);
        SetStatus("Session open failed");
        return FALSE;
    }
    
    g_Connected = TRUE;
    SetStatus("Connected - Loading files...");
    UpdateUI();
    
    if (MtpSendOperation(MTP_OP_GET_STORAGE_IDS, NULL, 0, NULL, 0, buffer, sizeof(buffer), &count)) {
        if (count >= sizeof(DWORD)) {
            DWORD numStorages = *((DWORD*)buffer);
            if (numStorages > 0 && count >= sizeof(DWORD) * 2) {
                g_CurrentStorage = *((DWORD*)(buffer + sizeof(DWORD)));
            }
        }
    }
    
    RefreshObjects();
    
    _snprintf(statusText, sizeof(statusText), "Connected - Session 0x%08lX", g_SessionId);
    SetStatus(statusText);
    
    return TRUE;
}

void DisconnectDevice(void)
{
    DWORD bytesReturned;
    
    if (!g_Connected) return;
    
    SetStatus("Disconnecting...");
    
    DeviceIoControl(g_hDevice, IOCTL_MTP_SESSION_CLOSE,
                    NULL, 0, NULL, 0, &bytesReturned, NULL);
    
    CloseHandle(g_hDevice);
    g_hDevice = INVALID_HANDLE_VALUE;
    g_SessionId = 0;
    g_Connected = FALSE;
    
    if (g_Objects) {
        free(g_Objects);
        g_Objects = NULL;
    }
    g_ObjectCount = 0;
    
    ListView_DeleteAllItems(g_hListView);
    UpdateUI();
    SetStatus("Disconnected");
}

BOOL RefreshObjects(void)
{
    BYTE buffer[TRANSFER_BUFFER_SIZE];
    DWORD bytesReceived;
    DWORD params[3];
    DWORD numHandles;
    DWORD *handles;
    DWORD i;
    char statusText[128];
    
    if (!g_Connected) return FALSE;
    
    SetStatus("Loading objects...");
    
    ListView_DeleteAllItems(g_hListView);
    if (g_Objects) {
        free(g_Objects);
        g_Objects = NULL;
    }
    g_ObjectCount = 0;
    
    params[0] = g_CurrentStorage ? g_CurrentStorage : 0xFFFFFFFF;
    params[1] = 0;
    params[2] = g_CurrentParent;
    
    if (!MtpSendOperation(MTP_OP_GET_OBJECT_HANDLES, params, 3, NULL, 0,
                          buffer, sizeof(buffer), &bytesReceived)) {
        SetStatus("Failed to get object list");
        return FALSE;
    }
    
    if (bytesReceived < sizeof(DWORD)) {
        SetStatus("No objects found");
        return TRUE;
    }
    
    numHandles = *((DWORD*)buffer);
    if (numHandles == 0) {
        SetStatus("Folder is empty");
        return TRUE;
    }
    
    handles = (DWORD*)(buffer + sizeof(DWORD));
    
    g_Objects = (OBJECT_ITEM*)malloc(numHandles * sizeof(OBJECT_ITEM));
    if (!g_Objects) {
        SetStatus("Memory allocation failed");
        return FALSE;
    }
    
    for (i = 0; i < numHandles; i++) {
        BYTE infoBuffer[4096];
        DWORD infoSize;
        DWORD param = handles[i];
        
        ZeroMemory(&g_Objects[i], sizeof(OBJECT_ITEM));
        g_Objects[i].Handle = handles[i];
        
        if (MtpSendOperation(MTP_OP_GET_OBJECT_INFO, &param, 1, NULL, 0,
                             infoBuffer, sizeof(infoBuffer), &infoSize)) {
            if (infoSize >= 52) {
                BYTE *p = infoBuffer;
                
                g_Objects[i].StorageId = *((DWORD*)p); p += 4;
                g_Objects[i].Format = *((WORD*)p); p += 2;
                p += 2;
                g_Objects[i].Size = *((DWORD*)p); p += 4;
                p += 28;
                g_Objects[i].ParentHandle = *((DWORD*)p); p += 4;
                p += 10;
                
                if ((DWORD)(p - infoBuffer) < infoSize) {
                    ReadMtpString(p, infoSize - (DWORD)(p - infoBuffer), 
                                  g_Objects[i].Name, 256);
                }
                
                g_Objects[i].IsFolder = (g_Objects[i].Format == MTP_FORMAT_ASSOCIATION);
            }
        }
        
        if (g_Objects[i].Name[0] == L'\0') {
            wsprintfW(g_Objects[i].Name, L"Object_%08lX", handles[i]);
        }
        
        g_ObjectCount++;
    }
    
    for (i = 0; i < g_ObjectCount; i++) {
        LVITEMW lvi;
        char sizeStr[32];
        char typeStr[32];
        int itemIndex;
        
        ZeroMemory(&lvi, sizeof(lvi));
        lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
        lvi.iItem = i;
        lvi.iSubItem = 0;
        lvi.pszText = g_Objects[i].Name;
        lvi.iImage = g_Objects[i].IsFolder ? 0 : 1;
        lvi.lParam = (LPARAM)g_Objects[i].Handle;
        
        itemIndex = (int)SendMessageW(g_hListView, LVM_INSERTITEMW, 0, (LPARAM)&lvi);
        
        if (!g_Objects[i].IsFolder) {
            FormatFileSize(g_Objects[i].Size, sizeStr, sizeof(sizeStr));
        } else {
            strcpy(sizeStr, "");
        }
        ListView_SetItemText(g_hListView, itemIndex, 1, sizeStr);
        
        strcpy(typeStr, GetFormatName(g_Objects[i].Format));
        ListView_SetItemText(g_hListView, itemIndex, 2, typeStr);
    }
    
    _snprintf(statusText, sizeof(statusText), "%lu object(s)", g_ObjectCount);
    SetStatus(statusText);
    
    return TRUE;
}

void NavigateToParent(void)
{
    DWORD i;
    
    if (!g_Connected) return;
    
    if (g_CurrentParent == 0) {
        return;
    }
    
    for (i = 0; i < g_ObjectCount; i++) {
        if (g_Objects[i].Handle == g_CurrentParent) {
            g_CurrentParent = g_Objects[i].ParentHandle;
            RefreshObjects();
            return;
        }
    }
    
    g_CurrentParent = 0;
    RefreshObjects();
}

void NavigateToFolder(DWORD handle)
{
    if (!g_Connected) return;
    
    g_CurrentParent = handle;
    RefreshObjects();
}

BOOL DownloadSelected(HWND hWnd)
{
    int selIndex;
    DWORD handle;
    char filename[MAX_PATH];
    char saveFilename[MAX_PATH];
    OPENFILENAMEA ofn;
    FILE *fp;
    BYTE buffer[TRANSFER_BUFFER_SIZE];
    MTP_GET_PART_REQ req;
    DWORD bytesReturned;
    DWORD totalBytes = 0;
    BOOL result;
    DWORD i;
    LVITEMA lvi;
    char statusText[128];
    MSG msg;
    
    /* Reset cancel flag at start of transfer */
    g_CancelTransfer = FALSE;
    
    selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
    if (selIndex == -1) {
        MessageBoxA(hWnd, "Please select a file to download.", "Download", MB_OK | MB_ICONINFORMATION);
        return FALSE;
    }
    
    ZeroMemory(&lvi, sizeof(lvi));
    lvi.mask = LVIF_PARAM;
    lvi.iItem = selIndex;
    ListView_GetItem(g_hListView, &lvi);
    handle = (DWORD)lvi.lParam;
    
    filename[0] = '\0';
    for (i = 0; i < g_ObjectCount; i++) {
        if (g_Objects[i].Handle == handle) {
            if (g_Objects[i].IsFolder) {
                NavigateToFolder(handle);
                return TRUE;
            }
            WideCharToMultiByte(CP_ACP, 0, g_Objects[i].Name, -1, 
                               filename, sizeof(filename), NULL, NULL);
            break;
        }
    }
    
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWnd;
    strcpy(saveFilename, filename);
    ofn.lpstrFile = saveFilename;
    ofn.nMaxFile = sizeof(saveFilename);
    ofn.lpstrFilter = "All Files\0*.*\0";
    ofn.lpstrTitle = "Save File As";
    ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    
    if (!GetSaveFileNameA(&ofn)) {
        return FALSE;
    }
    
    fp = fopen(saveFilename, "wb");
    if (!fp) {
        MessageBoxA(hWnd, "Cannot create local file.", "Download Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    SetStatus("Downloading... (Press ESC to cancel)");
    
    req.Id = handle;
    req.Offset = 0;
    req.Length = sizeof(buffer);
    
    while (1) {
        /* Check for cancel request */
        if (g_CancelTransfer) {
            fclose(fp);
            SetStatus("Download cancelled");
            MessageBoxA(hWnd, "Download cancelled by user.", "Cancelled", MB_OK | MB_ICONINFORMATION);
            return FALSE;
        }
        
        result = DeviceIoControl(
            g_hDevice,
            IOCTL_MTP_GET_OBJECT_PART,
            &req, sizeof(req),
            buffer, sizeof(buffer),
            &bytesReturned,
            NULL
        );
        
        if (!result || bytesReturned == 0) break;
        
        fwrite(buffer, 1, bytesReturned, fp);
        totalBytes += bytesReturned;
        req.Offset += bytesReturned;
        
        _snprintf(statusText, sizeof(statusText), "Downloaded %lu bytes... (ESC to cancel)", totalBytes);
        SetStatus(statusText);
        
        /* Process messages to keep UI responsive and check for ESC */
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE) {
                g_CancelTransfer = TRUE;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
        if (bytesReturned < sizeof(buffer)) break;
    }
    
    fclose(fp);
    
    _snprintf(statusText, sizeof(statusText), "Download complete - %lu bytes", totalBytes);
    SetStatus(statusText);
    MessageBoxA(hWnd, "Download complete!", "Success", MB_OK | MB_ICONINFORMATION);
    
    return TRUE;
}

BOOL UploadFile(HWND hWnd)
{
    char filename[MAX_PATH];
    OPENFILENAMEA ofn;
    FILE *fp;
    BYTE *buffer;
    DWORD bufferSize;
    DWORD bytesRead;
    DWORD totalBytes = 0;
    DWORD offset = 0;
    DWORD objectId = 0;  /* Reset per upload to avoid handle reuse issues */
    DWORD bytesReturned;
    BOOL result;
    char statusText[128];
    MSG msg;
    
    /* Reset cancel flag at start of transfer */
    g_CancelTransfer = FALSE;
    
    if (!g_Connected) {
        MessageBoxA(hWnd, "Please connect to a device first.", "Upload", MB_OK | MB_ICONINFORMATION);
        return FALSE;
    }
    
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWnd;
    filename[0] = '\0';
    ofn.lpstrFile = filename;
    ofn.nMaxFile = sizeof(filename);
    ofn.lpstrFilter = "All Files\0*.*\0";
    ofn.lpstrTitle = "Select File to Upload";
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    
    if (!GetOpenFileNameA(&ofn)) {
        return FALSE;
    }
    
    fp = fopen(filename, "rb");
    if (!fp) {
        MessageBoxA(hWnd, "Cannot open file.", "Upload Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    /* Use 16KB buffer for Win2000 USB stack stability */
    bufferSize = 8 + TRANSFER_BUFFER_SIZE;
    buffer = (BYTE*)malloc(bufferSize);
    if (!buffer) {
        fclose(fp);
        MessageBoxA(hWnd, "Memory allocation failed.", "Upload Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    SetStatus("Uploading... (Press ESC to cancel)");
    
    /* Explicitly reset objectId for this upload session */
    objectId = 0;
    
    while ((bytesRead = (DWORD)fread(buffer + 8, 1, TRANSFER_BUFFER_SIZE, fp)) > 0) {
        /* Check for cancel request */
        if (g_CancelTransfer) {
            free(buffer);
            fclose(fp);
            SetStatus("Upload cancelled");
            MessageBoxA(hWnd, "Upload cancelled by user.", "Cancelled", MB_OK | MB_ICONINFORMATION);
            return FALSE;
        }
        
        *((DWORD*)(buffer + 0)) = objectId;
        *((DWORD*)(buffer + 4)) = offset;
        
        result = DeviceIoControl(
            g_hDevice,
            IOCTL_MTP_SEND_OBJECT_PART,
            buffer, 8 + bytesRead,
            &objectId, sizeof(objectId),
            &bytesReturned,
            NULL
        );
        
        if (!result) {
            free(buffer);
            fclose(fp);
            MessageBoxA(hWnd, "Upload failed.", "Upload Error", MB_OK | MB_ICONERROR);
            SetStatus("Upload failed");
            return FALSE;
        }
        
        totalBytes += bytesRead;
        offset += bytesRead;
        
        _snprintf(statusText, sizeof(statusText), "Uploaded %lu bytes... (ESC to cancel)", totalBytes);
        SetStatus(statusText);
        
        /* Process messages to keep UI responsive and check for ESC */
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE) {
                g_CancelTransfer = TRUE;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    
    free(buffer);
    fclose(fp);
    
    _snprintf(statusText, sizeof(statusText), "Upload complete - %lu bytes", totalBytes);
    SetStatus(statusText);
    MessageBoxA(hWnd, "Upload complete!", "Success", MB_OK | MB_ICONINFORMATION);
    
    RefreshObjects();
    return TRUE;
}

BOOL DeleteSelected(HWND hWnd)
{
    int selIndex;
    DWORD handle;
    BYTE response[32];
    DWORD bytesReceived;
    LVITEMA lvi;
    
    selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
    if (selIndex == -1) {
        MessageBoxA(hWnd, "Please select an object to delete.", "Delete", MB_OK | MB_ICONINFORMATION);
        return FALSE;
    }
    
    if (MessageBoxA(hWnd, "Are you sure you want to delete this object?", 
                   "Confirm Delete", MB_YESNO | MB_ICONQUESTION) != IDYES) {
        return FALSE;
    }
    
    ZeroMemory(&lvi, sizeof(lvi));
    lvi.mask = LVIF_PARAM;
    lvi.iItem = selIndex;
    ListView_GetItem(g_hListView, &lvi);
    handle = (DWORD)lvi.lParam;
    
    SetStatus("Deleting...");
    
    if (!MtpSendOperation(MTP_OP_DELETE_OBJECT, &handle, 1, NULL, 0,
                          response, sizeof(response), &bytesReceived)) {
        MessageBoxA(hWnd, "Failed to delete object.", "Delete Error", MB_OK | MB_ICONERROR);
        SetStatus("Delete failed");
        return FALSE;
    }
    
    SetStatus("Object deleted");
    RefreshObjects();
    return TRUE;
}

/* ============================================================================
 * UI Creation Functions
 * ============================================================================ */

void CreateMainMenu(HWND hWnd)
{
    HMENU hMenu = CreateMenu();
    HMENU hFileMenu = CreatePopupMenu();
    HMENU hTransferMenu = CreatePopupMenu();
    HMENU hViewMenu = CreatePopupMenu();
    HMENU hHelpMenu = CreatePopupMenu();
    
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_CONNECT, "&Connect\tCtrl+O");
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_DISCONNECT, "&Disconnect\tCtrl+D");
    AppendMenuA(hFileMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hFileMenu, MF_STRING, IDM_FILE_EXIT, "E&xit\tAlt+F4");
    
    AppendMenuA(hTransferMenu, MF_STRING, IDM_TRANSFER_DOWNLOAD, "&Download...\tCtrl+S");
    AppendMenuA(hTransferMenu, MF_STRING, IDM_TRANSFER_UPLOAD, "&Upload...\tCtrl+U");
    AppendMenuA(hTransferMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hTransferMenu, MF_STRING, IDM_TRANSFER_DELETE, "De&lete\tDel");
    AppendMenuA(hTransferMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hTransferMenu, MF_STRING, IDM_TRANSFER_REFRESH, "&Refresh\tF5");
    
    AppendMenuA(hViewMenu, MF_STRING, IDM_VIEW_DETAILS, "&Details");
    AppendMenuA(hViewMenu, MF_STRING, IDM_VIEW_ICONS, "&Large Icons");
    
    AppendMenuA(hHelpMenu, MF_STRING, IDM_HELP_ABOUT, "&About...");
    
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "&File");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hTransferMenu, "&Transfer");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hViewMenu, "&View");
    AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, "&Help");
    
    SetMenu(hWnd, hMenu);
}

void CreateToolbar(HWND hWnd)
{
    TBBUTTON tbButtons[9];
    HIMAGELIST hToolbarImageList;
    SHFILEINFOA shfi;
    HICON hIcon;
    
    ZeroMemory(tbButtons, sizeof(tbButtons));
    
    tbButtons[0].iBitmap = 0;
    tbButtons[0].idCommand = ID_TB_CONNECT;
    tbButtons[0].fsState = TBSTATE_ENABLED;
    tbButtons[0].fsStyle = TBSTYLE_BUTTON;
    
    tbButtons[1].iBitmap = 1;
    tbButtons[1].idCommand = ID_TB_DISCONNECT;
    tbButtons[1].fsState = 0;
    tbButtons[1].fsStyle = TBSTYLE_BUTTON;
    
    tbButtons[2].fsStyle = TBSTYLE_SEP;
    
    tbButtons[3].iBitmap = 2;
    tbButtons[3].idCommand = ID_TB_REFRESH;
    tbButtons[3].fsState = 0;
    tbButtons[3].fsStyle = TBSTYLE_BUTTON;
    
    tbButtons[4].iBitmap = 3;
    tbButtons[4].idCommand = ID_TB_PARENT;
    tbButtons[4].fsState = 0;
    tbButtons[4].fsStyle = TBSTYLE_BUTTON;
    
    tbButtons[5].fsStyle = TBSTYLE_SEP;
    
    tbButtons[6].iBitmap = 4;
    tbButtons[6].idCommand = ID_TB_DOWNLOAD;
    tbButtons[6].fsState = 0;
    tbButtons[6].fsStyle = TBSTYLE_BUTTON;
    
    tbButtons[7].iBitmap = 5;
    tbButtons[7].idCommand = ID_TB_UPLOAD;
    tbButtons[7].fsState = 0;
    tbButtons[7].fsStyle = TBSTYLE_BUTTON;
    
    tbButtons[8].iBitmap = 6;
    tbButtons[8].idCommand = ID_TB_DELETE;
    tbButtons[8].fsState = 0;
    tbButtons[8].fsStyle = TBSTYLE_BUTTON;
    
    g_hToolbar = CreateToolbarEx(
        hWnd,
        WS_CHILD | WS_VISIBLE | TBSTYLE_TOOLTIPS | TBSTYLE_FLAT,
        IDC_TOOLBAR,
        7,
        g_hInstance,
        0,
        tbButtons,
        9,
        16, 16,
        16, 16,
        sizeof(TBBUTTON)
    );
    
    hToolbarImageList = ImageList_Create(16, 16, ILC_COLOR24 | ILC_MASK, 7, 0);
    
    SHGetFileInfoA("C:\\", 0, &shfi, sizeof(shfi), SHGFI_ICON | SHGFI_SMALLICON);
    ImageList_AddIcon(hToolbarImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    hIcon = LoadIcon(NULL, IDI_WARNING);
    ImageList_AddIcon(hToolbarImageList, hIcon);
    
    hIcon = LoadIcon(NULL, IDI_APPLICATION);
    ImageList_AddIcon(hToolbarImageList, hIcon);
    
    SHGetFileInfoA("C:\\", FILE_ATTRIBUTE_DIRECTORY, &shfi, sizeof(shfi), 
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(hToolbarImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    hIcon = LoadIcon(NULL, IDI_INFORMATION);
    ImageList_AddIcon(hToolbarImageList, hIcon);
    
    hIcon = LoadIcon(NULL, IDI_QUESTION);
    ImageList_AddIcon(hToolbarImageList, hIcon);
    
    hIcon = LoadIcon(NULL, IDI_ERROR);
    ImageList_AddIcon(hToolbarImageList, hIcon);
    
    SendMessage(g_hToolbar, TB_SETIMAGELIST, 0, (LPARAM)hToolbarImageList);
    SendMessage(g_hToolbar, TB_AUTOSIZE, 0, 0);
}

void CreateStatusBar(HWND hWnd)
{
    g_hStatusBar = CreateWindowExA(
        0,
        STATUSCLASSNAMEA,
        NULL,
        WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
        0, 0, 0, 0,
        hWnd,
        (HMENU)IDC_STATUSBAR,
        g_hInstance,
        NULL
    );
    
    SetStatus("Ready - Click Connect to connect to an MTP device");
}

void CreateListView(HWND hWnd)
{
    RECT rcClient;
    LVCOLUMNA lvc;
    SHFILEINFOA shfi;
    
    GetClientRect(hWnd, &rcClient);
    
    g_hListView = CreateWindowExA(
        WS_EX_CLIENTEDGE,
        WC_LISTVIEWA,
        NULL,
        WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL,
        0, 0, rcClient.right, rcClient.bottom,
        hWnd,
        (HMENU)IDC_LISTVIEW,
        g_hInstance,
        NULL
    );
    
    ListView_SetExtendedListViewStyle(g_hListView, 
        LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES);
    
    g_hSmallImageList = ImageList_Create(16, 16, ILC_COLOR24 | ILC_MASK, 2, 0);
    
    SHGetFileInfoA("folder", FILE_ATTRIBUTE_DIRECTORY, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hSmallImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    SHGetFileInfoA("file", FILE_ATTRIBUTE_NORMAL, &shfi, sizeof(shfi),
                   SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
    ImageList_AddIcon(g_hSmallImageList, shfi.hIcon);
    DestroyIcon(shfi.hIcon);
    
    ListView_SetImageList(g_hListView, g_hSmallImageList, LVSIL_SMALL);
    
    ZeroMemory(&lvc, sizeof(lvc));
    lvc.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
    
    lvc.pszText = "Name";
    lvc.cx = 300;
    lvc.iSubItem = 0;
    ListView_InsertColumn(g_hListView, 0, &lvc);
    
    lvc.pszText = "Size";
    lvc.cx = 100;
    lvc.iSubItem = 1;
    ListView_InsertColumn(g_hListView, 1, &lvc);
    
    lvc.pszText = "Type";
    lvc.cx = 100;
    lvc.iSubItem = 2;
    ListView_InsertColumn(g_hListView, 2, &lvc);
}

void SetStatus(const char *text)
{
    if (g_hStatusBar) {
        SendMessageA(g_hStatusBar, SB_SETTEXTA, 0, (LPARAM)text);
    }
}

void UpdateUI(void)
{
    HMENU hMenu;
    
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_CONNECT, !g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_DISCONNECT, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_REFRESH, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_PARENT, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_DOWNLOAD, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_UPLOAD, g_Connected);
    SendMessage(g_hToolbar, TB_ENABLEBUTTON, ID_TB_DELETE, g_Connected);
    
    hMenu = GetMenu(g_hMainWnd);
    EnableMenuItem(hMenu, IDM_FILE_CONNECT, g_Connected ? MF_GRAYED : MF_ENABLED);
    EnableMenuItem(hMenu, IDM_FILE_DISCONNECT, g_Connected ? MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hMenu, IDM_TRANSFER_DOWNLOAD, g_Connected ? MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hMenu, IDM_TRANSFER_UPLOAD, g_Connected ? MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hMenu, IDM_TRANSFER_DELETE, g_Connected ? MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hMenu, IDM_TRANSFER_REFRESH, g_Connected ? MF_ENABLED : MF_GRAYED);
    
    if (g_Connected) {
        SetWindowTextA(g_hMainWnd, "MTP File Transfer - Connected");
    } else {
        SetWindowTextA(g_hMainWnd, g_szAppTitle);
    }
}

/* ============================================================================
 * Window Procedure
 * ============================================================================ */

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
        case WM_CREATE:
            CreateMainMenu(hWnd);
            CreateToolbar(hWnd);
            CreateStatusBar(hWnd);
            CreateListView(hWnd);
            UpdateUI();
            return 0;
        
        case WM_SIZE: {
            RECT rcToolbar, rcStatus;
            int tbHeight, sbHeight;
            
            SendMessage(g_hToolbar, TB_AUTOSIZE, 0, 0);
            SendMessage(g_hStatusBar, WM_SIZE, 0, 0);
            
            GetWindowRect(g_hToolbar, &rcToolbar);
            tbHeight = rcToolbar.bottom - rcToolbar.top;
            
            GetWindowRect(g_hStatusBar, &rcStatus);
            sbHeight = rcStatus.bottom - rcStatus.top;
            
            MoveWindow(g_hListView, 0, tbHeight, 
                      LOWORD(lParam), HIWORD(lParam) - tbHeight - sbHeight, TRUE);
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
                
                case IDM_FILE_EXIT:
                    DestroyWindow(hWnd);
                    break;
                
                case IDM_TRANSFER_DOWNLOAD:
                case ID_TB_DOWNLOAD:
                    DownloadSelected(hWnd);
                    break;
                
                case IDM_TRANSFER_UPLOAD:
                case ID_TB_UPLOAD:
                    UploadFile(hWnd);
                    break;
                
                case IDM_TRANSFER_DELETE:
                case ID_TB_DELETE:
                    DeleteSelected(hWnd);
                    break;
                
                case IDM_TRANSFER_REFRESH:
                case ID_TB_REFRESH:
                    RefreshObjects();
                    break;
                
                case ID_TB_PARENT:
                    NavigateToParent();
                    break;
                
                case IDM_VIEW_DETAILS:
                    SetWindowLongA(g_hListView, GWL_STYLE, 
                        (GetWindowLongA(g_hListView, GWL_STYLE) & ~LVS_TYPEMASK) | LVS_REPORT);
                    break;
                
                case IDM_VIEW_ICONS:
                    SetWindowLongA(g_hListView, GWL_STYLE, 
                        (GetWindowLongA(g_hListView, GWL_STYLE) & ~LVS_TYPEMASK) | LVS_ICON);
                    break;
                
                case IDM_HELP_ABOUT:
                    MessageBoxA(hWnd, 
                        "MTP File Transfer for Windows 2000\n\n"
                        "Version 1.0\n\n"
                        "A user-friendly application for transferring\n"
                        "files between your PC and MTP devices\n"
                        "(smartphones, digital cameras, etc.)\n\n"
                        "Requires the MTP KMDF driver to be installed.",
                        "About MTP Transfer",
                        MB_OK | MB_ICONINFORMATION);
                    break;
            }
            return 0;
        
        case WM_NOTIFY: {
            NMHDR *pnmh = (NMHDR*)lParam;
            
            if (pnmh->hwndFrom == g_hListView && pnmh->code == NM_DBLCLK) {
                int selIndex = ListView_GetNextItem(g_hListView, -1, LVNI_SELECTED);
                if (selIndex != -1) {
                    LVITEMA lvi;
                    DWORD handle;
                    DWORD i;
                    
                    ZeroMemory(&lvi, sizeof(lvi));
                    lvi.mask = LVIF_PARAM;
                    lvi.iItem = selIndex;
                    ListView_GetItem(g_hListView, &lvi);
                    handle = (DWORD)lvi.lParam;
                    
                    for (i = 0; i < g_ObjectCount; i++) {
                        if (g_Objects[i].Handle == handle) {
                            if (g_Objects[i].IsFolder) {
                                NavigateToFolder(handle);
                            } else {
                                DownloadSelected(hWnd);
                            }
                            break;
                        }
                    }
                }
            }
            else if (pnmh->code == TTN_GETDISPINFOA) {
                NMTTDISPINFOA *pttdi = (NMTTDISPINFOA*)lParam;
                switch (pttdi->hdr.idFrom) {
                    case ID_TB_CONNECT:    pttdi->lpszText = "Connect to device"; break;
                    case ID_TB_DISCONNECT: pttdi->lpszText = "Disconnect"; break;
                    case ID_TB_REFRESH:    pttdi->lpszText = "Refresh file list"; break;
                    case ID_TB_PARENT:     pttdi->lpszText = "Go to parent folder"; break;
                    case ID_TB_DOWNLOAD:   pttdi->lpszText = "Download selected file"; break;
                    case ID_TB_UPLOAD:     pttdi->lpszText = "Upload a file"; break;
                    case ID_TB_DELETE:     pttdi->lpszText = "Delete selected item"; break;
                }
            }
            return 0;
        }
        
        case WM_DESTROY:
            if (g_Connected) {
                DisconnectDevice();
            }
            if (g_Objects) {
                free(g_Objects);
            }
            if (g_hSmallImageList) {
                ImageList_Destroy(g_hSmallImageList);
            }
            PostQuitMessage(0);
            return 0;
    }
    
    return DefWindowProcA(hWnd, message, wParam, lParam);
}

/* ============================================================================
 * WinMain
 * ============================================================================ */

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEXA wc;
    MSG msg;
    INITCOMMONCONTROLSEX icex;
    
    (void)hPrevInstance;
    (void)lpCmdLine;
    
    g_hInstance = hInstance;
    
    icex.dwSize = sizeof(icex);
    icex.dwICC = ICC_LISTVIEW_CLASSES | ICC_BAR_CLASSES;
    InitCommonControlsEx(&icex);
    
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(WNDCLASSEXA);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    
    if (!RegisterClassExA(&wc)) {
        MessageBoxA(NULL, "Failed to register window class.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    g_hMainWnd = CreateWindowExA(
        WS_EX_APPWINDOW,
        g_szClassName,
        g_szAppTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        700, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    if (!g_hMainWnd) {
        MessageBoxA(NULL, "Failed to create main window.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    ShowWindow(g_hMainWnd, nCmdShow);
    UpdateWindow(g_hMainWnd);
    
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}
