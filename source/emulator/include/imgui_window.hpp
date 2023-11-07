#pragma once

#include <d3d11.h>
#include <tchar.h>

namespace gali
{

class ImguiWindow
{
private:
    // Data
    ID3D11Device *pd3dDevice = nullptr;
    ID3D11DeviceContext *pd3dDeviceContext = nullptr;
    IDXGISwapChain *pSwapChain = nullptr;
    UINT ResizeWidth = 0, ResizeHeight = 0;
    ID3D11RenderTargetView *mainRenderTargetView = nullptr;

    // Forward declarations of helper functions
    bool CreateDeviceD3D(HWND hWnd);
    void CleanupDeviceD3D();
    void CreateRenderTarget();
    void CleanupRenderTarget();
    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
    ImguiWindow(void (&app_function)());
    ~ImguiWindow();
};

} // namespace gali