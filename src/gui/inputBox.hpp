#include <windows.h>
#include <unordered_map>
#include <functional>
#include <iostream>

class InputBox {
public:
  InputBox(HWND parent);
  void addCallback(UINT msg, std::function<void(WPARAM, LPARAM)> func);
  bool callCallback(UINT msg, WPARAM wParam, LPARAM lParam);

private:
  static LRESULT CALLBACK inputProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

  static std::unordered_map<HWND, InputBox*> inputBoxes;
  static std::unordered_map<HWND, WNDPROC> inputProcedures;

  HWND handle;
  std::unordered_map<UINT, std::function<void(WPARAM, LPARAM)>> callbacks;
};