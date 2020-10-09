#include <windows.h>

class InputBox {
public:
  InputBox(HWND parent);

private:
  HWND handle;
};