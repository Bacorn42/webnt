#include "window.hpp"

static LPCWSTR className = L"Main_Window";

Window::Window() {
  registerClass();
  createWindow();
}

void Window::run() {
  ShowWindow(handle, SW_SHOWNORMAL);
  UpdateWindow(handle);

  messageLoop();
}

void Window::registerClass() {
  WNDCLASSW wc;

  wc.style = 0;
  wc.lpfnWndProc = Window::windowProcedure;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = GetModuleHandleW(NULL);
  wc.hIcon = NULL;
  wc.hCursor = 0;
  wc.hbrBackground = 0;
  wc.lpszMenuName = NULL;
  wc.lpszClassName = className;

  RegisterClassW(&wc);
}

void Window::createWindow() {
  handle = CreateWindowW(
    className,
    L"Webn't",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
    NULL, NULL, GetModuleHandleW(NULL), NULL
  );
}

void Window::messageLoop() {
  MSG Msg;

  while(GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }
}

LRESULT CALLBACK Window::windowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  switch (msg) {
    case WM_CLOSE:
      DestroyWindow(hwnd);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProcW(hwnd, msg, wParam, lParam);
  }
  return 0;
}