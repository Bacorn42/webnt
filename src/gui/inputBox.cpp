#include "inputBox.hpp"

InputBox::InputBox(HWND parent) {
  handle = CreateWindowW(
    L"EDIT",
    L"https://www.google.com/",
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT,
    0, 0, 800, 20,
    parent, NULL, GetModuleHandleW(NULL), NULL
  );
}