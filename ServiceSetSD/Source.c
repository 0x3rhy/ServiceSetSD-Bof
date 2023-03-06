#include <windows.h>
#include <stdio.h>
#include "bofdefs.h"

#define SDDL_REVISION_1     1

void SetSSDL(LPCSTR service, LPCSTR ssdl)
{

	SC_HANDLE scmHandle = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (NULL == scmHandle)
	{
		BeaconPrintf(CALLBACK_ERROR, "OpenSCManager failed (%u)\n", GetLastError());
		return;
	}
	BeaconPrintf(CALLBACK_OUTPUT, "[+] OpenSCManager success!\n");

	SC_HANDLE serviceHandle = OpenServiceA(scmHandle, service, READ_CONTROL | WRITE_DAC);
	if (NULL == serviceHandle) {
		BeaconPrintf(CALLBACK_ERROR, "OpenService %s failed (%u)\n", service, GetLastError());
		CloseServiceHandle(scmHandle);
		return;
	}
	BeaconPrintf(CALLBACK_OUTPUT, "[+] OpenService %s success!\n", service);

	PSECURITY_DESCRIPTOR sd = NULL;
	if (!ConvertStringSecurityDescriptorToSecurityDescriptorA(ssdl, SDDL_REVISION_1, &sd,  NULL)) {
		BeaconPrintf(CALLBACK_ERROR, "Convert Security Descriptor To SecurityDescriptor (%u)\n", GetLastError());
		CloseServiceHandle(serviceHandle);
		CloseServiceHandle(scmHandle);
		return;
	}
	BeaconPrintf(CALLBACK_OUTPUT, "[+] Convert Security Descriptor To SecurityDescriptor success!\n");


	BeaconPrintf(CALLBACK_OUTPUT, "[+] %s setsd '%s'\n", service, ssdl);
	if (!SetServiceObjectSecurity(serviceHandle, DACL_SECURITY_INFORMATION, sd)) {
		BeaconPrintf(CALLBACK_ERROR, "Set ServiceObjectSecurity failed (%u)\n", GetLastError());
		LocalFree(sd);
		CloseServiceHandle(serviceHandle);
		CloseServiceHandle(scmHandle);
		return;
	}
	BeaconPrintf(CALLBACK_OUTPUT, "[+] Set ServiceObjectSecurity successful.\n");

	LocalFree(sd);
	CloseServiceHandle(serviceHandle);
	CloseServiceHandle(scmHandle);
}

#ifdef BOF
void go(char* args, int len) {

	if (!BeaconIsAdmin())
	{
		BeaconPrintf(CALLBACK_ERROR, "Requires administrator privileges\n");
		return;
	}

	LPSTR service_name, sddl;
	datap parser;
	BeaconDataParse(&parser, args, len);
	service_name = BeaconDataExtract(&parser, 0);
	sddl = BeaconDataExtract(&parser, 0);

	//LPCSTR h_sddl = "D:(D;;DCLCWPDTSD;;;IU)(D;;DCLCWPDTSD;;;SU)(D;;DCLCWPDTSD;;;BA)(A;;CCLCSWLOCRRC;;;IU)(A;;CCLCSWLOCRRC;;;SU)(A;;CCLCSWRPWPDTLOCRRC;;;SY)(A;;CCDCLCSWRPWPDTLOCRSDRCWDWO;;;BA)S:(AU;FA;CCDCLCSWRPWPDTLOCRSDRCWDWO;;;WD)";
	//LPCSTR s_sddl = "D:(A;;CCLCSWRPWPDTLOCRRC;;;SY)(A;;CCDCLCSWRPWPDTLOCRSDRCWDWO;;;BA)(A;;CCLCSWLOCRRC;;;IU)(A;;CCLCSWLOCRRC;;;SU)S:(AU;FA;CCDCLCSWRPWPDTLOCRSDRCWDWO;;;WD)";

	SetSSDL(service_name, sddl);

}


#else

void main(int argc, char* argv[]) {


}

#endif