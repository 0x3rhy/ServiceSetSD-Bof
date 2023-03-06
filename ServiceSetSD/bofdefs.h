#pragma once
/* some code and/or ideas are from trustedsec SA Github repo -- thankyou trustedsec! */
#include <windows.h>





#ifdef BOF

#ifdef __cplusplus
extern "C" {
#endif

#include "beacon.h"

#define NtCurrentProcess()        ((HANDLE)(LONG_PTR)-1)

	void go(char* buff, int len);

	/* COM */
	DECLSPEC_IMPORT HRESULT  WINAPI   OLE32$CLSIDFromString(LPCWSTR, LPCLSID);
	DECLSPEC_IMPORT HRESULT  WINAPI   OLE32$CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID* ppv);
	DECLSPEC_IMPORT HRESULT  WINAPI   OLE32$CoInitializeEx(LPVOID, DWORD);
	DECLSPEC_IMPORT VOID     WINAPI   OLE32$CoUninitialize();
	DECLSPEC_IMPORT HRESULT  WINAPI   OLE32$IIDFromString(LPWSTR lpsz, LPIID lpiid);
	DECLSPEC_IMPORT HRESULT	 WINAPI	  OLE32$CoInitialize(LPVOID pvReserved);
	DECLSPEC_IMPORT HRESULT	 WINAPI   OLE32$CoCreateInstanceEx(REFCLSID, IUnknown*, DWORD, COSERVERINFO*, DWORD, MULTI_QI*);
	DECLSPEC_IMPORT BSTR	 WINAPI	  OleAut32$SysAllocString(const OLECHAR*);
	DECLSPEC_IMPORT LPVOID	 WINAPI	  OLEAUT32$VariantInit(VARIANTARG* pvarg);
	DECLSPEC_IMPORT HRESULT	 WINAPI	  OLE32$CoInitializeSecurity(PSECURITY_DESCRIPTOR pSecDesc, LONG cAuthSvc, SOLE_AUTHENTICATION_SERVICE* asAuthSvc, void* pReserved1, DWORD dwAuthnLevel, DWORD dwImpLevel, void* pAuthList, DWORD dwCapabilities, void* pReserved3);

	/* Registry */
	DECLSPEC_IMPORT LSTATUS APIENTRY ADVAPI32$RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
	DECLSPEC_IMPORT LSTATUS APIENTRY ADVAPI32$RegDeleteTreeA(HKEY hKey, LPCSTR lpSubKey);
	DECLSPEC_IMPORT LSTATUS APIENTRY ADVAPI32$RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired,
		CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
	DECLSPEC_IMPORT LSTATUS APIENTRY ADVAPI32$RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType,
		CONST BYTE* lpData, DWORD cbData);


	/* FileSystem */
	DECLSPEC_IMPORT HANDLE WINAPI KERNEL32$CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
	DECLSPEC_IMPORT DWORD WINAPI KERNEL32$SetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
	DECLSPEC_IMPORT BOOL WINAPI KERNEL32$SetFilePointerEx(HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpDistanceToMoveHigh, DWORD dwMoveMethod);
	DECLSPEC_IMPORT BOOL WINAPI KERNEL32$WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
	DECLSPEC_IMPORT BOOL WINAPI KERNEL32$GetFileSizeEx(HANDLE hFile, PLARGE_INTEGER lpFileSize);
	DECLSPEC_IMPORT DWORD WINAPI VERSION$GetFileVersionInfoSizeW(LPCWSTR lptstrFilenamea, LPDWORD lpdwHandle);
	DECLSPEC_IMPORT BOOL WINAPI VERSION$GetFileVersionInfoW(LPCWSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData);
	DECLSPEC_IMPORT BOOL WINAPI VERSION$VerQueryValueW(LPCVOID pBlock, LPCWSTR lpSubBlock, LPVOID* lplpBuffer, PUINT puLen);


	/* Memory */
	DECLSPEC_IMPORT LPVOID	WINAPI KERNEL32$HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
	DECLSPEC_IMPORT BOOL	WINAPI KERNEL32$HeapFree(HANDLE, DWORD, PVOID);
	DECLSPEC_IMPORT LPVOID	WINAPI KERNEL32$HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
	DECLSPEC_IMPORT void* __cdecl  MSVCRT$memcpy(LPVOID, LPVOID, size_t);
	DECLSPEC_IMPORT void __cdecl   MSVCRT$memset(void*, int, size_t);
	DECLSPEC_IMPORT HMODULE WINAPI KERNEL32$GetModuleHandleA(LPCSTR lpModuleName);
	DECLSPEC_IMPORT HMODULE WINAPI KERNEL32$GetModuleHandleW(LPCWSTR lpModuleName);
	DECLSPEC_IMPORT FARPROC WINAPI KERNEL32$GetProcAddress(HANDLE, LPCSTR);
	DECLSPEC_IMPORT HANDLE WINAPI KERNEL32$LoadLibraryA(LPCSTR lpLibFileName);
	DECLSPEC_IMPORT HANDLE WINAPI KERNEL32$LoadLibraryW(LPCWSTR lpLibFileName);
	DECLSPEC_IMPORT BOOL WINAPI KERNEL32$CloseHandle(HANDLE hObject);
	DECLSPEC_IMPORT HLOCAL WINAPI KERNEL32$LocalFree(HLOCAL hMem);
	DECLSPEC_IMPORT HLOCAL WINAPI KERNEL32$LocalAlloc(UINT, SIZE_T);


	/* Process */
	DECLSPEC_IMPORT HANDLE	WINAPI KERNEL32$OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$OpenProcessToken(HANDLE, DWORD, PHANDLE);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$AdjustTokenPrivileges(HANDLE, BOOL, PTOKEN_PRIVILEGES, DWORD, PTOKEN_PRIVILEGES, PDWORD);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$SetTokenInformation(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD);
	DECLSPEC_IMPORT BOOL	WINAPI ADVAPI32$CreateProcessWithLogonW(LPCWSTR lpUsername, LPCWSTR lpDomain, LPCWSTR lpPassword, DWORD dwLogonFlags, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
	DECLSPEC_IMPORT HANDLE	WINAPI KERNEL32$GetProcessHeap();
	DECLSPEC_IMPORT SIZE_T WINAPI  KERNEL32$VirtualQueryEx(HANDLE hProcess, LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
	DECLSPEC_IMPORT DWORD WINAPI   KERNEL32$GetProcessId(HANDLE Process);
	DECLSPEC_IMPORT BOOL WINAPI    KERNEL32$ReadProcessMemory(HANDLE  hProcess, LPCVOID lpBaseAddress, LPVOID  lpBuffer, SIZE_T  nSize, SIZE_T* lpNumberOfBytesRead);
	DECLSPEC_IMPORT VOID WINAPI    KERNEL32$Sleep(DWORD dwMilliseconds);
	DECLSPEC_IMPORT HANDLE WINAPI  KERNEL32$GetCurrentProcess(VOID);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$LookupPrivilegeValueA(LPCSTR, LPCSTR, PLUID);
	DECLSPEC_IMPORT BOOL WINAPI	   ADVAPI32$LookupPrivilegeValueW(LPCWSTR lpSystemName, LPCWSTR lpName, PLUID lpLuid);
	DECLSPEC_IMPORT DWORD WINAPI   PSAPI$GetModuleFileNameExW(HANDLE hProcess, HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
	DECLSPEC_IMPORT BOOL WINAPI    KERNEL32$ReadProcessMemory(HANDLE  hProcess, LPCVOID lpBaseAddress, LPVOID  lpBuffer, SIZE_T  nSize, SIZE_T* lpNumberOfBytesRead);
	DECLSPEC_IMPORT BOOL WINAPI    KERNEL32$WriteProcessMemory(HANDLE  hProcess, LPCVOID lpBaseAddress, LPCVOID  lpBuffer, SIZE_T  nSize, SIZE_T* lpNumberOfBytesWrite);
	DECLSPEC_IMPORT HANDLE WINAPI KERNEL32$CreateToolhelp32Snapshot(DWORD, DWORD);

	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$GetTokenInformation(HANDLE TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, LPVOID TokenInformation, DWORD TokenInformationLength, PDWORD ReturnLength);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$AllocateAndInitializeSid(
		PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
		BYTE nSubAuthorityCount,
		DWORD nSubAuthority0,
		DWORD nSubAuthority1,
		DWORD nSubAuthority2,
		DWORD nSubAuthority3,
		DWORD nSubAuthority4,
		DWORD nSubAuthority5,
		DWORD nSubAuthority6,
		DWORD nSubAuthority7,
		PSID* pSid
	);

	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$AllocateLocallyUniqueId(PLUID Luid);
	DECLSPEC_IMPORT PVOID WINAPI ADVAPI32$FreeSid(PSID pSid);
	DECLSPEC_IMPORT  BOOL   WINAPI ADVAPI32$DuplicateTokenEx(HANDLE, DWORD, LPSECURITY_ATTRIBUTES, SECURITY_IMPERSONATION_LEVEL, TOKEN_TYPE, PHANDLE);
	DECLSPEC_IMPORT  BOOL   WINAPI ADVAPI32$ImpersonateLoggedOnUser(HANDLE hToken);
	DECLSPEC_IMPORT  SC_HANDLE  WINAPI ADVAPI32$OpenSCManagerA(LPCSTR      lpMachineName, LPCSTR    lpDatabaseName, DWORD  dwDesiredAccess);
	DECLSPEC_IMPORT SC_HANDLE WINAPI ADVAPI32$OpenServiceA(SC_HANDLE   hSCManager, LPCSTR  lpServiceName, DWORD    dwDesiredAccess);
	DECLSPEC_IMPORT  BOOL   WINAPI ADVAPI32$CloseServiceHandle(SC_HANDLE   hSCObject);
	DECLSPEC_IMPORT  BOOL   WINAPI ADVAPI32$ControlService(SC_HANDLE  hService, DWORD    dwControl, LPSERVICE_STATUS    lpServiceStatus);




	/* GetLast Error */
	DECLSPEC_IMPORT DWORD	WINAPI KERNEL32$GetLastError(VOID);


	/* Directories */
	DECLSPEC_IMPORT BOOL WINAPI KERNEL32$RemoveDirectoryA(LPCSTR);
	DECLSPEC_IMPORT BOOL WINAPI KERNEL32$CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
	DECLSPEC_IMPORT BOOL WINAPI KERNEL32$MoveFileA(LPCSTR lpExistingFileName, LPCSTR lpNewFileName);
	DECLSPEC_IMPORT BOOL WINAPI SHLWAPI$PathIsDirectoryA(LPCSTR);
	DECLSPEC_IMPORT BOOL WINAPI SHLWAPI$PathFileExistsA(LPCSTR pszPath);


	/* strings */
	DECLSPEC_IMPORT PSTR WINAPI SHLWAPI$StrChrA(PCSTR pszStart, WORD wMatch);
	DECLSPEC_IMPORT LPSTR	__cdecl	MSVCRT$strchr(LPSTR, int);
	DECLSPEC_IMPORT errno_t __cdecl MSVCRT$strcat_s(LPSTR, size_t, LPCSTR);
	DECLSPEC_IMPORT errno_t __cdecl MSVCRT$strcpy_s(LPSTR, size_t, LPCSTR);
	DECLSPEC_IMPORT errno_t __cdecl MSVCRT$strncpy_s(LPSTR, size_t, LPCSTR, size_t);
	DECLSPEC_IMPORT int		__cdecl	MSVCRT$_snprintf(LPSTR, size_t, LPCSTR, ...);
	DECLSPEC_IMPORT void WINAPI		MSVCRT$sprintf(char*, char[], ...);
	DECLSPEC_IMPORT int		__cdecl MSVCRT$_vsnprintf(LPSTR, size_t, LPCSTR, va_list);
	DECLSPEC_IMPORT	size_t	__cdecl MSVCRT$wcslen(LPCWSTR);
	DECLSPEC_IMPORT int __cdecl		MSVCRT$strcmp(const char* _Str1, const char* _Str2);
	DECLSPEC_IMPORT LPSTR WINAPI	Kernel32$lstrcpyA(LPSTR lpString1, LPCSTR lpString2);
	DECLSPEC_IMPORT LPSTR WINAPI	Kernel32$lstrcatA(LPSTR lpString1, LPCSTR lpString2);
	DECLSPEC_IMPORT LPSTR WINAPI	Kernel32$lstrcpynA(LPSTR lpString1, LPCSTR lpString2, int iMaxLength);
	DECLSPEC_IMPORT int WINAPI		KERNEL32$lstrlenW(LPCWSTR lpString);
	DECLSPEC_IMPORT LPWSTR WINAPI	KERNEL32$lstrcpyW(LPWSTR lpString1, LPCWSTR lpString2);
	DECLSPEC_IMPORT int WINAPI MSVCRT$_stricmp(const char*, const char*);
	DECLSPEC_IMPORT int WINAPI MSVCRT$_wcsicmp(wchar_t const*, wchar_t const*);
	DECLSPEC_IMPORT int WINAPI MSVCRT$memcmp(void*, void*, size_t);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$ConvertStringSidToSidA(LPCSTR   StringSid, PSID* Sid);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$GetUserNameA(
		LPSTR lpBuffer,
		LPDWORD pcbBuffer
	);



	/* RPC */
	DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY Rpcrt4$RpcStringFreeA(RPC_CSTR* String);
	DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY Rpcrt4$UuidCreate(UUID* Uuid);
	DECLSPEC_IMPORT RPC_STATUS RPC_ENTRY Rpcrt4$UuidToStringA(const UUID* Uuid, RPC_CSTR* StringUuid);



	/* Random */
	DECLSPEC_IMPORT void WINAPI MSVCRT$srand(int initial);
	DECLSPEC_IMPORT int WINAPI MSVCRT$rand();


	/* DateTime */
	DECLSPEC_IMPORT time_t WINAPI MSVCRT$time(time_t* time);


	/* SystemInfo */
	DECLSPEC_IMPORT void WINAPI KERNEL32$GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
	DECLSPEC_IMPORT BOOL WINAPI KERNEL32$IsProcessorFeaturePresent(DWORD ProcessorFeature);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$GetUserNameW(LPWSTR lpBuffer, LPDWORD pcbBuffer);

	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$SetServiceObjectSecurity(
			        SC_HANDLE               hService,
			        SECURITY_INFORMATION    dwSecurityInformation,
			        PSECURITY_DESCRIPTOR    lpSecurityDescriptor
		);
	DECLSPEC_IMPORT BOOL WINAPI ADVAPI32$ConvertStringSecurityDescriptorToSecurityDescriptorA(LPCSTR StringSecurityDescriptor, DWORD StringSDRevision,
                     PSECURITY_DESCRIPTOR* SecurityDescriptor, PULONG  SecurityDescriptorSize
	);






#ifdef __cplusplus
}
#endif


/* helper macros */

#define malloc(size) KERNEL32$HeapAlloc(KERNEL32$GetProcessHeap(), HEAP_ZERO_MEMORY, size)	/* trustedsec */
#define free(addr) KERNEL32$HeapFree(KERNEL32$GetProcessHeap(), 0, (LPVOID)addr)	/* trustedsec */
#define ZeroMemory(address, size) memset(address, 0, size);


/* ----------------------------------- DEFINITIONS ------------------------------------------*/

/* COM */
#define	CLSIDFromString			OLE32$CLSIDFromString
#define	CoCreateInstance		OLE32$CoCreateInstance
#define CoInitializeEx			OLE32$CoInitializeEx
#define CoUninitialize			OLE32$CoUninitialize
#define IIDFromString			OLE32$IIDFromString
#define CoInitialize			OLE32$CoInitialize
#define CoCreateInstanceEx		OLE32$CoCreateInstanceEx
#define SysAllocString			OleAut32$SysAllocString
#define	VariantInit				OLEAUT32$VariantInit
#define CoInitialize			OLE32$CoInitialize
#define CoInitializeSecurity	OLE32$CoInitializeSecurity

/* memory */
#define HeapFree				KERNEL32$HeapFree
#define HeapAlloc				KERNEL32$HeapAlloc
#define HeapReAlloc				KERNEL32$HeapReAlloc
#define memcpy					MSVCRT$memcpy
#define memset					MSVCRT$memset
#define GetModuleHandleA     KERNEL32$GetModuleHandleA
#define GetModuleHandleW     KERNEL32$GetModuleHandleW
#define GetProcAddress     KERNEL32$GetProcAddress
#define LoadLibraryA     KERNEL32$LoadLibraryA
#define LoadLibraryW     KERNEL32$LoadLibraryW
#define CloseHandle KERNEL32$CloseHandle
#define LocalFree KERNEL32$LocalFree
#define LocalAlloc KERNEL32$LocalAlloc





/* process */
#define GetProcessHeap			KERNEL32$GetProcessHeap
#define CreateProcessWithLogonW ADVAPI32$CreateProcessWithLogonW
#define OpenProcess				KERNEL32$OpenProcess
#define OpenProcessToken ADVAPI32$OpenProcessToken
#define AdjustTokenPrivileges ADVAPI32$AdjustTokenPrivileges
#define SetTokenInformation ADVAPI32$SetTokenInformation
#define VirtualQueryEx			KERNEL32$VirtualQueryEx
#define GetProcessId			KERNEL32$GetProcessId
#define	ReadProcessMemory		KERNEL32$ReadProcessMemory
#define GetCurrentProcess		KERNEL32$GetCurrentProcess
#define Sleep					KERNEL32$Sleep
#define LookupPrivilegeValueA ADVAPI32$LookupPrivilegeValueA
#define LookupPrivilegeValueW	ADVAPI32$LookupPrivilegeValueW
#define	GetModuleFileNameExW	PSAPI$GetModuleFileNameExW
#define ReadProcessMemory KERNEL32$ReadProcessMemory
#define WriteProcessMemory KERNEL32$WriteProcessMemory
#define NtQueryInformationProcess NTDLL$NtQueryInformationProcess
#define CreateToolhelp32Snapshot KERNEL32$CreateToolhelp32Snapshot
#define Process32First KERNEL32$Process32First
#define Process32Next KERNEL32$Process32Next
#define GetTokenInformation ADVAPI32$GetTokenInformation
#define AllocateAndInitializeSid ADVAPI32$AllocateAndInitializeSid
#define AllocateLocallyUniqueId ADVAPI32$AllocateLocallyUniqueId
#define FreeSid ADVAPI32$FreeSid
#define DuplicateTokenEx ADVAPI32$DuplicateTokenEx
#define ImpersonateLoggedOnUser ADVAPI32$ImpersonateLoggedOnUser
#define OpenSCManagerA ADVAPI32$OpenSCManagerA
#define OpenServiceA ADVAPI32$OpenServiceA
#define CloseServiceHandle ADVAPI32$CloseServiceHandle
#define ControlService ADVAPI32$ControlService






/* debug */
#define EnumerateLoadedModulesW64 DBGHELP$EnumerateLoadedModulesW64
#define SymInitializeW			DBGHELP$SymInitializeW
#define SymCleanup				DBGHELP$SymCleanup


/* filesystem */
#define CreateFileA				KERNEL32$CreateFileA
#define SetFilePointer			KERNEL32$SetFilePointer
#define SetFilePointerEx		KERNEL32$SetFilePointerEx
#define WriteFile				KERNEL32$WriteFile
#define GetFileSizeEx			KERNEL32$GetFileSizeEx
#define GetFileVersionInfoSizeW	VERSION$GetFileVersionInfoSizeW
#define GetFileVersionInfoW		VERSION$GetFileVersionInfoW
#define	VerQueryValueW			VERSION$VerQueryValueW

/* error */
#define GetLastError			KERNEL32$GetLastError 


/* registry */
#define RegOpenKeyExA			ADVAPI32$RegOpenKeyExA
#define RegDeleteTreeA			ADVAPI32$RegDeleteTreeA
#define RegCreateKeyExA			ADVAPI32$RegCreateKeyExA
#define RegSetValueExA			ADVAPI32$RegSetValueExA


/* directory */
#define RemoveDirectoryA		KERNEL32$RemoveDirectoryA
#define CreateDirectoryA		KERNEL32$CreateDirectoryA
#define MoveFileA				KERNEL32$MoveFileA
#define PathIsDirectoryA		SHLWAPI$PathIsDirectoryA
#define PathFileExistsA			SHLWAPI$PathFileExistsA


/* strings */
#define strchr					MSVCRT$strchr
#define strcat_s				MSVCRT$strcat_s
#define strcpy_s				MSVCRT$strcpy_s
#define strncpy_s				MSVCRT$strncpy_s
#define snprintf				MSVCRT$_snprintf	/*beacon can't find snprintf without the preceeding '_' */
#define wcslen					MSVCRT$wcslen
#define vsnprintf				MSVCRT$vsnprintf
#define lstrlenW				KERNEL32$lstrlenW
#define lstrcpyW				KERNEL32$lstrcpyW
#define strcmp					MSVCRT$strcmp
#define lstrcpyA				Kernel32$lstrcpyA
#define	lstrcatA				Kernel32$lstrcatA
#define	lstrcpynA				Kernel32$lstrcpynA
#define lstrlenW				KERNEL32$lstrlenW
#define lstrcpyW				KERNEL32$lstrcpyW
#define sprintf					MSVCRT$sprintf
#define _stricmp MSVCRT$_stricmp
#define _wcsicmp MSVCRT$_wcsicmp
#define memcmp MSVCRT$memcmp
#define ConvertStringSidToSidA ADVAPI32$ConvertStringSidToSidA
#define GetUserNameA ADVAPI32$GetUserNameA
#define RtlEqualMemory(Destination,Source,Length) (!memcmp((Destination),(Source),(Length)))



/* RPC */
#define RpcStringFreeA			Rpcrt4$RpcStringFreeA 
#define UuidCreate				Rpcrt4$UuidCreate
#define UuidToStringA			Rpcrt4$UuidToStringA


/* Random */
#define srand					MSVCRT$srand
#define rand					MSVCRT$rand


/* DateTime */
#define time					MSVCRT$time


/* SystemInfo */
#define GetSystemInfo			KERNEL32$GetSystemInfo
#define GetUserNameW			ADVAPI32$GetUserNameW
#define IsProcessorFeaturePresent	KERNEL32$IsProcessorFeaturePresent
#define ConvertStringSecurityDescriptorToSecurityDescriptorA ADVAPI32$ConvertStringSecurityDescriptorToSecurityDescriptorA
#define SetServiceObjectSecurity ADVAPI32$SetServiceObjectSecurity
#else

#endif
