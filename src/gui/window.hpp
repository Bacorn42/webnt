#include <windows.h>
#include <tchar.h>

class Window {
public:
  Window();

private:
  void registerClass();
  void createWindow();
  void messageLoop();
  static LRESULT CALLBACK windowProcessor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

  HWND handle;
};