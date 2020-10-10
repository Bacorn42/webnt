#include <windows.h>

class Window {
public:
  Window();
  void run();
  HWND getHandle() { return handle; }

private:
  void registerClass();
  void createWindow();
  void messageLoop();
  static LRESULT CALLBACK windowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

  HWND handle;
};