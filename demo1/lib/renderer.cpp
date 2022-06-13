#include <tchar.h>
#include "renderer.h"

static HWND target_hwnd;
static HWND overlay_hwnd;

render::overlay::overlay(std::string_view window_name, std::string_view class_name) {
    create_overlay(window_name, class_name);
}

render::overlay::~overlay() {

}

void render::overlay::create_overlay(std::string_view window_name, std::string_view class_name) {
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = m_win_proc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = NULL;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = HBRUSH(RGB(0, 0, 0));
    wc.lpszMenuName = "";
    wc.lpszClassName = "overlay";
    wc.hIconSm = NULL;
    if (!RegisterClassEx(&wc)) {
        MessageBoxA(NULL, "Error 1", " H", MB_OK);
    }
    target_hwnd = FindWindow(class_name.data(), window_name.data());
    //target_hwnd = getHandle(window_name.data());
    GetWindowRect(target_hwnd, &target_rect);
    overlay_rect = target_rect;

    overlay_hwnd = CreateWindowExA(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT, "overlay", "",
                                   WS_VISIBLE | WS_POPUP, target_rect.left, target_rect.top, target_rect.width(),
                                   target_rect.height(), NULL, NULL, NULL, NULL);

    // 设置窗口透明
    MARGINS m = {target_rect.left, target_rect.top, target_rect.width(), target_rect.height()};
    DwmExtendFrameIntoClientArea(overlay_hwnd, &m);
    SetLayeredWindowAttributes(overlay_hwnd, RGB(0, 0, 0), 100, LWA_ALPHA);
    ShowWindowAsync(overlay_hwnd, SW_SHOW);

    // 开始绘制
    init_dx9();
}

LRESULT render::overlay::m_win_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_DESTROY:
            exit(0);
            break;
        default:
            break;
    }
    return DefWindowProc(hwnd, msg, wparam, lparam);
}

HWND render::overlay::getHandle(std::string_view window_name) {
    // 获得首个handle.
    HWND h = FindWindow(0, 0);
    HWND handle = nullptr;
    // 循环查找直到找到为给定进程ID的窗口句柄
    while (h != NULL) {
        //检查窗口句柄是否为顶级窗口
        if (::GetParent(h) == NULL) {
            char text[255];
            ::GetWindowTextA(h, text, 255);
            //有的有窗口 但无标题
            if (strlen(text) > 1 && window_name.compare(text) == 0) {
                handle = h;
            }
        }
        // 取下一个窗口的句柄
        h = GetWindow(h, GW_HWNDNEXT);
    }
    return handle;
}

void render::overlay::init_dx9() {
    m_d3d = Direct3DCreate9(D3D_SDK_VERSION);
    D3DPRESENT_PARAMETERS pp;
    ZeroMemory(&pp,sizeof(D3DPRESENT_PARAMETERS));
    pp.Windowed = true;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    D3DDISPLAYMODE d3ddm;
    if(FAILED(m_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
    {
        MessageBoxA(NULL, "GetAdapterDisplayMode", " H", MB_OK);
    }
    pp.BackBufferFormat = D3DFMT_A8B8G8R8;
    pp.BackBufferFormat = d3ddm.Format;
    pp.BackBufferWidth = target_rect.width();
    pp.BackBufferHeight = target_rect.height();
    pp.hDeviceWindow = overlay_hwnd;
    pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    if(FAILED(m_d3d->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,overlay_hwnd,D3DCREATE_HARDWARE_VERTEXPROCESSING,&pp,&m_device)))
    {
        MessageBoxA(NULL, "CreateDevice", " H", MB_OK);
    }
    m_initialized = true;
}

render::dx_renderer::dx_renderer(IDirect3DDevice9 *mdevice) {

    if(NULL == mdevice){
        MessageBoxA(NULL, "mdevice == NULL", " H", MB_OK);
    }
    d3d_device = mdevice;
    if(FAILED(D3DXCreateLine(d3d_device, &m_line)))
    {
        MessageBoxA(NULL, "D3DXCreateLine", " H", MB_OK);
    }

    if(FAILED(D3DXCreateFontA(d3d_device, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, "YouYuan", &m_font)))
    {
        MessageBoxA(NULL, "D3DXCreateFontA", " H", MB_OK);
    }

}

render::dx_renderer::~dx_renderer() {
    if(m_line){
        m_line->Release();
    }
    if(m_font){
        m_font->Release();
    }
}

void render::dx_renderer::begain_renderer() {
    d3d_device->Clear(NULL,NULL,D3DCLEAR_TARGET,D3DCOLOR_RGBA(0,0,0,0),1.0f,0);
    d3d_device->BeginScene();
}

void render::dx_renderer::end_renderer() {
    d3d_device->EndScene();
    d3d_device->Present(NULL,NULL,NULL,NULL);
}

void render::dx_renderer::draw_rect(int x0, int y0, int width, int height, unsigned long color) {
    draw_line(x0,y0,x0,y0 + height,color);
    draw_line(x0,y0,x0 + width,y0,color);
    draw_line(x0 + width,y0,x0 + width,y0 + height,color);
    draw_line(x0,y0 + height,x0 + width,y0 + height,color);
}

void render::dx_renderer::draw_text(std::string_view text, int x, int y, unsigned long color) {
    RECT r = {x,y,x,y};
    m_font->DrawTextA(NULL,text.data(), text.size(), &r,DT_NOCLIP, color);
}

void render::dx_renderer::draw_line(int x0, int y0, int x1, int y1, unsigned long color) {
    D3DXVECTOR2 line[2] = {D3DXVECTOR2 (x0,y0),D3DXVECTOR2 (x1,y1)};
    m_line->Begin();
    m_line->Draw(line,2,color);
    m_line->End();
}
