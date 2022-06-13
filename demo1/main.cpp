#include "memory.h"
#include "cssdk.h"
#include "renderer.h"
#include "vector"

using namespace memory_tool;

// 获取所有人物的结构体列表
vector<player_Struct> player_Struct_list(32);
// 保存需要绘制的人物结构体
vector<esp_struct> esp_Struct_list(32);
memory_tool::memory_manager *mem_ptr;

void read_thread() {

    vector<uint32_t> my_info_vec = {offsets::local_player_address};
    uint32_t my_info_address;
    while (true) {
        mem_ptr->read_list(mem_ptr->client_dll + offsets::entity_list_offset, player_Struct_list.data(),
                           player_Struct_list.size());
        // 读取人物内存结构
        mem_ptr->read_chain(mem_ptr->client_dll, my_info_vec, my_info_address);
        // 初始化我的人物数据结构体
        player_info my_player_info(mem_ptr, my_info_address);

        // 遍历人物结构体
        for (int i = 1; i < player_Struct_list.size(); i++) {
            esp_Struct_list[i].valid = false;
            uintptr_t entity_address = player_Struct_list[i].player_ptr;
            player_info player_info(mem_ptr, entity_address);
            // 判断人物是否休眠
            if (my_player_info.dormant == 1) {
                continue;
            }
            // 判断人物是否die
            if (my_player_info.health <= 0.01) {
                continue;
            }
            // 判断人物是否同队
            if (my_player_info.team == player_info.team) {
                continue;
            }
            // 定义需要绘制的结构体
            esp_struct esp;
            esp.health = player_info.health;
            // 脚底坐标
            esp.pos = player_info.pos;

            esp.valid = true;
            esp_Struct_list[i] = esp;
        }
    }
}

float X = 0.0f;
float Y = 0.0f;

int main() {

    // 绑定进程  窗口初始化
    render::overlay over("Counter-Strike: Global Offensive - Direct3D 9", "Valve001");
    // 进程绑定及模块初始化
    memory_tool::memory_manager mem("csgo.exe", "client.dll");
    mem_ptr = &mem;
    // d3d设备初始化
    render::dx_renderer dx(over.m_device);
    Y = over.overlay_rect.height();
    X = over.overlay_rect.width();
    //尝试绘制
/*    while (true) {
        dx.begain_renderer();
        dx.draw_rect(133, 155, 100, 100, D3DCOLOR_RGBA(65, 78, 160, 255));
        dx.draw_text("HELLO", 128, 155, D3DCOLOR_RGBA(42, 98, 154, 255));
        dx.end_renderer();
    }*/
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) read_thread, NULL, 0, NULL);
    while (true) {
        dx.begain_renderer();
        for (esp_struct esp : esp_Struct_list) {
            if (!esp.valid) {
                continue;
            }
            if (esp.health <= 0.1f || esp.health > 100.0f) {
                continue;
            }
            // 读取矩阵
            vec_view view = mem.read<vec_view>(mem.client_dll + offsets::view_matrix_offset);
            vec3 v1;
            if(!world2screen(esp.pos, v1, view, X, Y)){
                continue;
            }
            int box_height = v1.z - v1.y;
            int box_weight = box_height / 2;
            dx.draw_rect(v1.x - box_weight / 2, v1.y, box_weight, box_height, D3DCOLOR_RGBA(255, 0, 0, 255));
            dx.draw_text(to_string(esp.health) + "HP", v1.x - box_weight / 2, v1.y, D3DCOLOR_RGBA(0, 255, 0, 255));
        }
        dx.end_renderer();
    }

    return 0;
}
