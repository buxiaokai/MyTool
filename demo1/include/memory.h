#pragma once

#include <iostream>
#include "windows.h"
#include "string"
#include "TlHelp32.h"
#include "vector"

using namespace std;

namespace memory_tool {
    class memory_manager {
    public:
        HANDLE mem_handle = nullptr;
        int pid;
        std::uintptr_t client_dll = 0x0;

        memory_manager(std::string_view gameName, std::string_view moduleName) {
            bind_process(gameName);
            bind_modules(moduleName);
        }

        // 获取进程PID和模块地址
        void bind_process(std::string_view name);
        void bind_modules(std::string_view name);

        template<typename T>
        T read(uintptr_t address) {
            T t;
            ReadProcessMemory(mem_handle, (LPVOID) address, &t, sizeof(T), nullptr);
            return t;
        }

        template<typename T>
        void read_list(uintptr_t address, T *t, SIZE_T count) {
            ReadProcessMemory(mem_handle, (LPVOID) address, t, count * (sizeof(T)), nullptr);
        }

        template<typename T>
        void read_chain(uintptr_t address, vector<uint32_t> vec, T &out) {
            for (int i = 0; i < vec.size(); i++) {
                if (i + 1 == vec.size()) {
                    out = read<T>(address + vec[i]);
                } else {
                    address = read<int>(address + vec[i]);
                }
            }
        }
    };

}

