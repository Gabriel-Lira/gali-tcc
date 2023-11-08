#pragma once

#include <string>

#include <d3d11.h>
#include <tchar.h>

#include "imgui.h"

namespace gali
{

class ImguiWindowParams
{
public:
    std::wstring window_name;
    int x;
    int y;
    int nWidth;
    int nHeight;
};

class ImguiWindow
{
private:
    ImGuiIO *io;

    ID3D11Device *pd3dDevice = nullptr;
    ID3D11DeviceContext *pd3dDeviceContext = nullptr;
    IDXGISwapChain *pSwapChain = nullptr;
    UINT ResizeWidth = 0, ResizeHeight = 0;
    ID3D11RenderTargetView *mainRenderTargetView = nullptr;

    WNDCLASSEXW wc;
    HWND hwnd;

    // Forward declarations of helper functions
    bool CreateDeviceD3D();
    void CleanupDeviceD3D();
    void CreateRenderTarget();
    void CleanupRenderTarget();
    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
    ImguiWindow(const ImguiWindowParams &params);
    void run(void (&app_function)());
    ~ImguiWindow();
};

} // namespace gali