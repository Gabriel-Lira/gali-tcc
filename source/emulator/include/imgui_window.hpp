#pragma once

#include <functional>
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
    ImVec4 background_color;
    std::function<void()> app_window_function;
};

class ImguiWindow
{
private:
    const ImguiWindowParams &params;

    ImGuiIO *io;

    ID3D11Device *pd3dDevice = nullptr;
    ID3D11DeviceContext *pd3dDeviceContext = nullptr;
    IDXGISwapChain *pSwapChain = nullptr;
    ID3D11RenderTargetView *mainRenderTargetView = nullptr;
    UINT ResizeWidth = 0, ResizeHeight = 0;

    WNDCLASSEXW wc;
    HWND hwnd;

    // Forward declarations of helper functions
    bool CreateDeviceD3D();
    void CleanupDeviceD3D();
    void CreateRenderTarget();
    void CleanupRenderTarget();
    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
    ImguiWindow(const ImguiWindowParams &_params);
    void run();
    ~ImguiWindow();
};

} // namespace gali