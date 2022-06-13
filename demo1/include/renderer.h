#pragma once
#include "windows.h"
#include "string"
#include "dwmapi.h"
#include "d3d9.h"
#include "d3dx9.h"
#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
namespace render{
    class overlay{
        struct wnd_rec : public RECT{
            int width(){
                return right - left;
            }
            int height(){
                return bottom - top;
            }
        };
    public:

        IDirect3DDevice9* m_device = NULL;

        overlay(std::string_view window_name, std::string_view class_name);

        ~overlay();

        void create_overlay(std::string_view window_name, std::string_view class_name);

        // 遍历获取窗口句柄
        HWND getHandle(std::string_view);
        wnd_rec overlay_rect;
    private:
        static LRESULT CALLBACK m_win_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
        wnd_rec target_rect;

        void init_dx9();
        IDirect3D9 * m_d3d = NULL;
        bool m_initialized = false;
    };

    class dx_renderer{
    public:
        dx_renderer(IDirect3DDevice9 *mdevice);
        ~dx_renderer();

        void begain_renderer();
        void end_renderer();

        void draw_line(int x0, int y0, int x1, int y1, unsigned long color);
        void draw_rect(int x0, int y0, int width, int height, unsigned long color);
        void draw_text(std::string_view text, int x, int y, unsigned long color);

    private:
        IDirect3DDevice9 *d3d_device;
        ID3DXFont* m_font = NULL;
        ID3DXLine* m_line = NULL;
    };
}