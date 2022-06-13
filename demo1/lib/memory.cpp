
#include "memory.h"

void memory_tool::memory_manager::bind_process(std::string_view name) {
    HANDLE _handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pro;
    pro.dwSize = sizeof(PROCESSENTRY32);
    for (Process32First(_handle, &pro); Process32Next(_handle, &pro);) {
        if (name.compare(pro.szExeFile) == 0) {
            pid = pro.th32ProcessID;
            mem_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
            break;
        }
    }
}

void memory_tool::memory_manager::bind_modules(std::string_view name) {
    HANDLE _handle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    MODULEENTRY32 mod;
    mod.dwSize = sizeof(MODULEENTRY32);
    for (Module32First(_handle, &mod); Module32Next(_handle, &mod);) {
        if (name.compare(mod.szModule) == 0) {
            client_dll = (uintptr_t)mod.modBaseAddr;
            break;
        }
    }
}
