#pragma once

#include <string>

#include <d3d11.h>
#include <dxgi1_4.h>
#include <tchar.h>

#include "ImGuiInternal/imgui.h"
#include "ImGuiInternal/imgui_impl_win32.h"
#include "ImGuiInternal/imgui_impl_dx11.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

static const int APP_NUM_FRAMES_IN_FLIGHT = 2;
static const int APP_NUM_BACK_BUFFERS = 2;
static const int APP_SRV_HEAP_SIZE = 64;

enum class LOOPACTION
{
	BREAK,
	CONTINUE
};

class Gui
{
private:
	std::wstring className;
	std::wstring windowName;
	bool showWindow{ true };
	bool running{ false };
	WNDPROC wndProcess;
	WNDCLASSEXW wc{ 0 };
	HWND hwnd{ nullptr };
	ImVec4 clearColor{ 0.45f, 0.55f, 0.60f, 1.00f };

	ID3D11Device* g_pd3dDevice{ nullptr };
	ID3D11DeviceContext* g_pd3dDeviceContext{ nullptr };
	IDXGISwapChain* g_pSwapChain{ nullptr };
	bool g_SwapChainOccluded{ false };
	UINT g_ResizeWidth{ 0 };
	UINT g_ResizeHeight{ 0 };
	ID3D11RenderTargetView* g_mainRenderTargetView{ nullptr };

	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();
public:
	Gui() = default;
	Gui(const Gui& other) = default;
	Gui(Gui&& rvalue) = delete;
	~Gui();

	int initialize(std::wstring wndName, std::wstring className);
	int initialize();
	bool isRunning();
	LOOPACTION startRender();
	void endRender();

	LRESULT CALLBACK AppHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void setWindowName(std::wstring name);
	void setWindowClassName(std::wstring name);
	void setWindowProcess(WNDPROC proc);
	void setWindowState(bool state);
};

