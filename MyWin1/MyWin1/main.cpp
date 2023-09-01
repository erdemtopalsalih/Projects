#define WIN32_LEAN_AND_MEAN
#include <windows.h>
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nShowCmd)
{
	WNDCLASSEX windowClass;
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));

	windowClass.cbSize=sizeof(WNDCLASSEX);
	windowClass.style=CS_HREDRAW|CS_VREDRAW;
	windowClass.lpfnWndProc=WindowProc;
	windowClass.hInstance=hInstance;
	windowClass.hCursor=LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground=(HBRUSH)COLOR_WINDOW;
	windowClass.lpszClassName="WindowClassName";

	RegisterClassEx(&windowClass);

	HWND windowHandle=CreateWindowEx(NULL, "WindowClassName", "My Win32 Window", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);

	ShowWindow(windowHandle, nShowCmd);
	UpdateWindow(windowHandle);

	MSG msg;

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
}