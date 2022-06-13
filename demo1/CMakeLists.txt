cmake_minimum_required(VERSION 3.17)
project(demo1)

set(CMAKE_CXX_STANDARD 17)
set(SRC_LIST main.cpp include/memory.h lib/memory.cpp include/cssdk.h lib/cssdk.cpp include/offsets.h include/renderer.h lib/renderer.cpp)
set(INCLUDE_ include/)
set(LIB_ lib/ )
set(dwmapi_dir D:\\C++Test\\csTool\\demo1\\lib\\dwmapi.lib
        D:\\C++Test\\csTool\\demo1\\lib\\d3d9.lib
        D:\\C++Test\\csTool\\demo1\\lib\\d3dx9.lib)
# 指定头文件的搜索路径
INCLUDE_DIRECTORIES(include ${INCLUDE_})
LINK_DIRECTORIES(${dwmapi_dir})
# 指定源文件的路径,保存到DIR_SRCS中
AUX_SOURCE_DIRECTORY(lib DIR_SRCS)

add_executable(demo1 ${SRC_LIST} ${DIR_SRCS})
target_link_libraries(demo1 dwmapi.lib)
target_link_libraries(demo1 d3d9.lib)
target_link_libraries(demo1 d3dx9.lib)