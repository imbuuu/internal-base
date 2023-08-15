#include "pch.h"
#include "Utility.h"
#include "Mem.h"
#include "Global.h"

DWORD WINAPI HackThread(LPVOID hModule)
{
    printf("[ Internal Base | Buuu. ]");
   
        

    return 0;
}
    


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Util::CreateConsole();
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HackThread, nullptr, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
