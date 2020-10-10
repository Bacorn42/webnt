#include "webnt.hpp"

Webnt::Webnt() :
window(Window()),
inputBox(InputBox(window.getHandle())) {
  inputBox.addCallback(WM_KEYDOWN, [](WPARAM wParam, LPARAM lParam){
    if(wParam == VK_RETURN) {
      MessageBoxW(NULL, L"Pressed enter on input box!", L"Yay!", MB_OK);
    }
  });
  window.run();
}